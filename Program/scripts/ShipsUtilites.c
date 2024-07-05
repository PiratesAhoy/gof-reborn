
#define REAL_SHIPS_QUANTITY 900

object	RealShips[REAL_SHIPS_QUANTITY];

ref GetRealShip(int iType) 
{ 
	if(iType >= REAL_SHIPS_QUANTITY)
	{
		trace ("--- Wrong Ship Index. iType is " + iType);
		Log_TestInfo("--- Wrong Ship Index. iType is " + iType);
		return &ShipsTypes[SHIP_TYPES_QUANTITY + 1]; // для отлова
	}
	return &RealShips[iType]; 
}

// isLock - рудимент, можно выкидывать (26.05.06 boal)
// новая жизнь isLock (04.07.06) теперь это признак ворованности (те цены на верфи)
// если 1 - ворованный, цена копеешная, 0 - честно купленный - можно перепродать.
int GenerateShip(int iBaseType, bool isLock)
{
	int iShip = CreateBaseShip(iBaseType);

	if (iShip == -1)
	{
		return SHIP_NOTUSED;
	}
	
	ref rRealShip = GetRealShip(iShip);
	ref rBaseShip = GetShipByType(sti(rRealShip.BaseType));
    // boal 26/05/06 изменим
    rRealShip.ship.upgrades.hull  = 1 + rand(2);  //признак корабля теперь
	rRealShip.ship.upgrades.sails = 1 + rand(2);  // только визуальная разница
	
	if (!CheckAttribute(rRealShip, "isFort"))
	{
	    int iCaliber = sti(rRealShip.MaxCaliber);
	    if (sti(rRealShip.Class) != 7)
	    {  // чтоб не было баркаса с 16ф
		    switch(iCaliber)
		    {
				case 12:
					iCaliber = 0;
				break;
				case 16:
					iCaliber = 1;
				break;
				case 24:
					iCaliber = 2;
				break;
				case 32:
					iCaliber = 3;
				break;
				case 42:
					iCaliber = 4;
				break;
		    }
		    iCaliber = iCaliber + rand(2) - 1;
		    if (iCaliber < 0) iCaliber = 0;
		    if (rRealShip.BaseName == "Manowar")
		    {
		    	if (iCaliber > 4) iCaliber = 4;
		    }
		    else
		    {
		    	if (iCaliber > 3) iCaliber = 3;
		    }
		    switch(iCaliber)
		    {
				case 0:
					iCaliber = 12;
				break;
				case 1:
					iCaliber = 16;
				break;
				case 2:
					iCaliber = 24;
				break;
				case 3:
					iCaliber = 32;
				break;
				case 4:
					iCaliber = 42;
				break;
		    }
		    rRealShip.MaxCaliber = iCaliber;
	    }
	    rRealShip.SpeedRate	       = stf(rRealShip.SpeedRate) + frandSmall(stf(rRealShip.SpeedRate) / 5.0) - stf(rRealShip.SpeedRate) / 10.0;
	    rRealShip.TurnRate         = stf(rRealShip.TurnRate) + frandSmall(stf(rRealShip.TurnRate) / 5.0) - stf(rRealShip.TurnRate) / 10.0;
	    //rRealShip.Price            = sti(rRealShip.Price) + rand(makeint(sti(rRealShip.Price)/2)) - makeint(sti(rRealShip.Price)/4);
	    rRealShip.HP               = sti(rRealShip.HP) + rand(makeint(sti(rRealShip.HP)/5)) - makeint(sti(rRealShip.HP)/10);
	    rRealShip.WindAgainstSpeed = stf(rRealShip.WindAgainstSpeed) + frandSmall(stf(rRealShip.WindAgainstSpeed)/5.0) - stf(rRealShip.WindAgainstSpeed)/10.0;
	}
    rRealShip.Capacity        = sti(rRealShip.Capacity) + rand(makeint(sti(rRealShip.Capacity)/4)) - makeint(sti(rRealShip.Capacity)/8);
    rRealShip.OptCrew         = makeint(sti(rRealShip.OptCrew) + rand(makeint(sti(rRealShip.OptCrew)/3)) - makeint(sti(rRealShip.OptCrew)/6));
    rRealShip.MaxCrew         = makeint(sti(rRealShip.OptCrew) * 1.25 + 0.5);  // 25% перегруза
    rRealShip.MinCrew         = makeint(sti(rRealShip.MinCrew) + rand(makeint(sti(rRealShip.MinCrew)/3)) - makeint(sti(rRealShip.MinCrew)/6));

	rRealShip.Weight		  = sti(rRealShip.Weight) + rand(sti(rRealShip.Weight)/20) - rand(sti(rRealShip.Weight)/20);
	
	// to_do del -->
	rRealShip.BoardingCrew    = 0;
	rRealShip.GunnerCrew      = 0;
	rRealShip.CannonerCrew    = 0;
	rRealShip.SailorCrew      = sti(rRealShip.OptCrew);
    // to_do del <--
    
	int iDiffWeight			= sti(rRealShip.Weight) - sti(rBaseShip.Weight);
	int iDiffCapacity		= sti(rRealShip.Capacity) - sti(rBaseShip.Capacity);
	int iDiffMaxCrew		= sti(rRealShip.MaxCrew) - sti(rBaseShip.MaxCrew);
	int iDiffMinCrew		= sti(rRealShip.MinCrew) - sti(rBaseShip.MinCrew);
	float fDiffSpeedRate	= stf(rRealShip.SpeedRate) - stf(rBaseShip.SpeedRate);
	int iDiffTurnRate		= sti(rRealShip.TurnRate) - sti(rBaseShip.TurnRate);
	int iDiffHP	    		= sti(rRealShip.HP) - sti(rBaseShip.HP);

	rRealShip.Price	= (iDiffWeight + iDiffCapacity + iDiffMaxCrew*2 + iDiffMinCrew + fDiffSpeedRate*2 + iDiffTurnRate*2 + iDiffHP)*5 + sti(rRealShip.Price);

	if (sti(rRealShip.Price) <= 0) rRealShip.Price = 100;
	
	rRealShip.Stolen = isLock;  // ворованность

	return iShip;
}

int CreateBaseShip(int iBaseType)
{
	int iShip = FindFirstEmptyShip();

	if(iShip == -1)
	{
        trace("Can not find empty ship slot");
		return SHIP_NOTUSED;
	}

	ref rBaseShip = GetShipByType(iBaseType);
	ref rRealShip = GetRealShip(iShip);
	DeleteAttribute(rRealShip, "");
	CopyAttributes(rRealShip, rBaseShip);
    rRealShip.index = iShip;
    rRealShip.BaseType = iBaseType;
    if (!CheckAttribute(rRealShip, "ship.upgrades.hull")) // если задано в базе, то квестовый тип, не перебивать
    {
    	rRealShip.ship.upgrades.hull = 1;  //признак корабля теперь
    }
	rRealShip.ship.upgrades.sails = 1;
	
    rRealShip.BaseName = rRealShip.name; // запоминалка для нужд, тк далее идет 'странное'
	if (rRealShip.name != "Fort" && rRealShip.name != "Boat") // не знаю зачем :(
	{
		rRealShip.name = rRealShip.name + "1"; // без этого вылет, но почему!!!!!!!!!!!!!!
		// выяснил - папка с моделью имеет на конце 1, вот и ответ
	}
    rRealShip.Stolen = 0;  // ворованность - честный
    
	if (iArcadeSails == 0) // момент инерции ниже для тактики
	{
	    rRealShip.InertiaAccelerationY = stf(rRealShip.InertiaAccelerationY) / 2.0;
	}
    
	return iShip;
}
// Генерация корабля для верфи
int GenerateStoreShip(int iBaseType)
{
	int iShip = GenerateShip(iBaseType, 0); // честный 

	if (iShip == -1)
	{
		return SHIP_NOTUSED;
	}
	
	ref rRealShip = GetRealShip(iShip);
    rRealShip.StoreShip = true;  // кораль на верфи, трется отдельным методом
    
	return iShip;	
}
// переработка метода 26.05.06 boal
// идея: трем все корабли, где нет НПС-владельца, все галки пофиг
void EmptyAllFantomShips()
{
	int  i;
	ref  chr;
	// оптимальный код - два прохода, а не вложенный цикл. В начале всем сносим флаг удаляемости, потом проставляем, где есть НПС
	for (i = 0; i < REAL_SHIPS_QUANTITY; i++)
	{
        DeleteAttribute(&RealShips[i], "lock");
	}
	// лодку ставим, тк он имеет индекс НПС за пределами MAX_CHARACTERS
	RealShips[sti(Characters[BOAT_CHARACTER].ship.type)].lock = true;
	// теперь НПС-кэпы
	for (i = 0; i < MAX_CHARACTERS; i++)
	{
        chr = &Characters[i];
        if (CheckAttribute(chr, "ship.type") && chr.ship.type != SHIP_NOTUSED)
        {
            RealShips[sti(chr.ship.type)].lock = true;
        }
        // очистка для верфи
		if (CheckAttribute(chr, "shipyard"))
		{
		    FreeShipFromShipyard(chr);
		}
	}
	for (i = FANTOM_CHARACTERS; i < TOTAL_CHARACTERS; i++) // фантомы в море
	{
        chr = &Characters[i];
        if (CheckAttribute(chr, "ship.type") && chr.ship.type != SHIP_NOTUSED)
        {
            RealShips[sti(chr.ship.type)].lock = true;
        }
	}
	// теперь сборка мусора
	for (i = 0; i < REAL_SHIPS_QUANTITY; i++)
	{
        if (!CheckAttribute(&RealShips[i], "lock") && !CheckAttribute(&RealShips[i], "StoreShip"))  // на верфи корабли не трем
        {
			DeleteAttribute(&RealShips[i], "");
		}
	}
}

int GetRealShipsCount()
{ // метод для отладки
	int result = 0;

	for (int i= 0; i< REAL_SHIPS_QUANTITY; i++)
	{
		if (checkAttribute(&RealShips[i], "name"))
		{
			result++;
		}
	}

	return result;
}

// поиск пустого слота
int FindFirstEmptyShip()
{
	for(int i = 0; i < REAL_SHIPS_QUANTITY; i++)
	{
		if(!checkAttribute(&RealShips[i], "name"))
		{
			return i;
		}
	}

	return -1;
}


/*
float SpeedByHullUpgrade(aref refCharacter)
{
	int iHull = sti(refCharacter.ship.upgrades.hull) - 1;

	float fResult = 1.0 - (0.05 * iHull);

	return fResult;
}


float SpeedBySailsUpgrade(aref refCharacter)
{
	int iSails = sti(refCharacter.ship.upgrades.sails) - 1;
	iSails = iSails * 5;
	float fResult = 1.0 + (0.01 * iSails);

	return fResult;
}
*/

float FindShipSpeed(aref refCharacter)
{
	if(!CheckAttribute(refCharacter, "Ship.type"))
	{
		trace("Character " + refCharacter.id + " have no ship!");
		return 0.0;
	}
	int nShipType = sti(refCharacter.ship.type);
	if(nShipType == SHIP_NOTUSED)
	{
		trace("Character " + refCharacter.id + " have invalid ship!");
		return 1.0;
	}
	ref rShip = GetRealShip(nShipType);
	
	float	fMaxSpeedZ = stf(rShip.SpeedRate);  // базовая скорость
	float fShipHp = stf(refCharacter.ship.hp);
	float fShipMaxHp = stf(rShip.HP);
	float fSpeedFromHp = fShipHp/fShipMaxHp;
	fSpeedFromHp = 0.8 + fSpeedFromHp*0.3;

	if(fSpeedFromHp > 1.0) // некий запас перед снижением скорости
	{
		fSpeedFromHp = 1.0;
	}

	float fSailsDamage = stf(refCharacter.ship.sp);

	float	fTRFromSailDamage = Bring2Range(0.1, 1.0, 0.1, 100.0, fSailsDamage); //0.3

	float fTRFromShipState = fSpeedFromHp * fTRFromSailDamage;
	
	float	fLoad = Clampf(stf(refCharacter.Ship.Cargo.Load) / stf(rShip.Capacity));
	float	fTRFromWeight = Clampf(1.03 - stf(rShip.SpeedDependWeight) * fLoad);
	float   fTRFromSkill = SpeedBySkill(refCharacter);
	// от команды
	float fCrewMax = stf(rShip.MaxCrew);
	float fCrewOpt = stf(rShip.OptCrew);
	float fCrewCur = stf(refCharacter.Ship.Crew.Quantity);
	if (fCrewCur > fCrewMax)
	{
		fCrewCur = fCrewMax;
	}
	float  fTRFromPeople;
	fTRFromPeople = 0.85 + ((GetCrewExp(refCharacter, "Sailors") * fCrewCur) / (fCrewOpt * GetCrewExpRate())) * 0.15;
	if (fTRFromPeople > 1) fTRFromPeople = 1;
	 
	fMaxSpeedZ = fMaxSpeedZ * fTRFromWeight * fTRFromSkill * fTRFromShipState * fTRFromPeople;

	return fMaxSpeedZ;
}

float SpeedBySkill(aref refCharacter)
{
	float fSkill = GetSummonSkillFromNameToOld(refCharacter, SKILL_SAILING);

	float fTRFromSkill = 0.7 + (0.03 *  fSkill);

	//float fSpeedByHullUpgrade = SpeedByHullUpgrade(refCharacter);
	//float fSpeedBySailsUpgrade = SpeedBySailsUpgrade(refCharacter);

	//fTRFromSKill = fTRFromSKill * fSpeedByHullUpgrade * fSpeedBySailsUpgrade;
    float fSpeedPerk = AIShip_isPerksUse(CheckOfficersPerk(refCharacter, "ShipSpeedUp"), 1.0, 1.15);   //slib
    fSpeedPerk = AIShip_isPerksUse(CheckOfficersPerk(refCharacter, "SailingProfessional"), fSpeedPerk, 1.20);
    
	return fTRFromSKill*fSpeedPerk;
}

float FindShipTurnRate(aref refCharacter)
{
	if(!CheckAttribute(refCharacter, "Ship.type"))
	{
		trace("Character " + refCharacter.id + " have no ship!");
		return 0.0;
	}
	int nShipType = sti(refCharacter.ship.type);
	if(nShipType == SHIP_NOTUSED)
	{
		trace("Character " + refCharacter.id + " have invalid ship!");
		return 1.0;
	}
	ref rShip = GetRealShip(nShipType);

	float fShipHp = stf(refCharacter.ship.hp);
	float fShipMaxHp = stf(rShip.HP);
	float fSpeedFromHp = fShipHp/fShipMaxHp;
	fSpeedFromHp = 0.7 + fSpeedFromHp * 0.3;

	float fLoad = Clampf(stf(refCharacter.Ship.Cargo.Load) / stf(rShip.Capacity));
	float fTRFromWeight;
	if (iArcadeSails == 1)
	{
		fTRFromWeight = Clampf(1.03 - stf(rShip.TurnDependWeight) * fLoad);
	}
	else
	{
		fTRFromWeight = Clampf(1.03 - 2.0*stf(rShip.TurnDependWeight) * fLoad); // влияние веса больше
	}
	// не реализовано, всегда 1 float fTRFromSpeed = 1.0 - stf(rShip.TurnDependSpeed);
	// от команды
	//float fCrewMin = stf(rShip.MinCrew);
	float fCrewMax = stf(rShip.MaxCrew);
	float fCrewOpt = stf(rShip.OptCrew);
	float fCrewCur = stf(refCharacter.Ship.Crew.Quantity);
	if (fCrewCur > fCrewMax)
	{
		fCrewCur = fCrewMax;
	}
	float  fTRFromPeople;
	if (iArcadeSails == 1)
	{
		fTRFromPeople = 0.3 + ((GetCrewExp(refCharacter, "Sailors") * fCrewCur) / (fCrewOpt * GetCrewExpRate())) * 0.7;
	}
	else
	{
		fTRFromPeople = 0.05 + ((GetCrewExp(refCharacter, "Sailors") * fCrewCur) / (fCrewOpt * GetCrewExpRate())) * 0.95;
	}
	if (fTRFromPeople > 1) fTRFromPeople = 1;
	
	float fTRFromSKill = TurnBySkill(refCharacter);

	float fTRFromSailDamage = Bring2Range(0.05, 1.0, 0.1, 100.0, stf(refCharacter.ship.sp));

	float fTurn = fTRFromWeight * fTRFromSkill * fTRFromPeople * fTRFromSailDamage * fSpeedFromHp;

	//Log_info(refCharacter.id + "  " + fTurn);
	return fTurn;	
}

float TurnBySkill(aref refCharacter)
{
	float fSkill = GetSummonSkillFromNameToOld(refCharacter, SKILL_SAILING);
	float fTRFromSKill;

    if (iArcadeSails == 1)
	{
		fTRFromSKill = 0.5 + (0.05 * fSkill);
	}
	else
	{
		fTRFromSKill = 0.3 + (0.07 * fSkill);
	}
	
    float fSpeedPerk = AIShip_isPerksUse(CheckOfficersPerk(refCharacter, "ShipTurnRateUp"), 1.0, 1.15);   //slib
    fSpeedPerk = AIShip_isPerksUse(CheckOfficersPerk(refCharacter, "SailingProfessional"), fSpeedPerk, 1.20);
    float fFastTurn180 = AIShip_isPerksUse(CheckOfficersPerk(refCharacter, "Turn180"), 1.0, 8.0);
    
	return fTRFromSKill*fSpeedPerk*fFastTurn180;
}

int GetCannonsNum(aref chr)
{
	int nShipType = sti(chr.ship.type);
    ref refBaseShip = GetRealShip(nShipType);

	int iCannons = GetBortIntactCannonsNum(chr, "cannonf", sti(refBaseShip.fcannon)) + GetBortIntactCannonsNum(chr, "cannonb", sti(refBaseShip.bcannon)) + GetBortIntactCannonsNum(chr, "cannonl", sti(refBaseShip.lcannon)) + GetBortIntactCannonsNum(chr, "cannonr", sti(refBaseShip.rcannon));

	return iCannons;
}

// boal
int GetBortCannonsQty(aref chr, string  sType)
{
	int nShipType = sti(chr.ship.type);
    ref refBaseShip = GetRealShip(nShipType);

	int iCannons = GetBortIntactCannonsNum(chr, sType, sti(refBaseShip.(sType)));

	return iCannons;
}

int GetBortCannonsMaxQty(aref chr, string  sType)
{
	int nShipType = sti(chr.ship.type);
    ref refBaseShip = GetRealShip(nShipType);

	int iCannons = sti(refBaseShip.(sType));

	return iCannons;
}
void SetShipyardStore(ref NPChar)
{
    int    iTest_ship, i;
	string attrName;

	if (CheckAttribute(NPChar, "shipyard")) return;

	SaveCurrentNpcQuestDateParam(npchar, "shipyardDate");

    if (bBettaTestMode)
    {
        for (i = 1; i <=SHIP_TYPES_QUANTITY; i++)
        {
            attrName = "ship" + i;
            FillShipParamShipyard(NPChar, GenerateStoreShip(i-1), attrName);
        }

        return;
    }
    FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_TARTANE), "ship1");

	iTest_ship = rand(5);
	switch(iTest_ship) {
	case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_WAR_TARTANE), "ship2"); break;
	case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GUNBOAT), "ship2"); break;
	case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BERMSLOOP), "ship2"); break;
	case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HANNAH), "ship2"); break;
    case 5:  FillShipParamShipyard(NPChar,GenerateStoreShip(SHIP_LYON), "ship2"); break;
    }
	iTest_ship = rand(6);
	switch(iTest_ship) {
	case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BERMSLOOP), "ship3"); break;
	case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HANNAH), "ship3"); break;
	case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_KETCH), "ship3"); break;
	case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BOUNTY), "ship3"); break;
    case 5:  FillShipParamShipyard(NPChar,GenerateStoreShip(SHIP_LYON), "ship3"); break;
    case 6:  FillShipParamShipyard(NPChar,GenerateStoreShip(SHIP_CASTELF), "ship3"); break;
    }
	if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
	{
		iTest_ship = rand(12);
		switch(iTest_ship) {
		case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_KETCH), "ship4"); break;
		case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BOUNTY), "ship4"); break;
		case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_EDINBURG), "ship4"); break;
		case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CUTTER), "ship4"); break;
		case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGERVML), "ship4"); break;
		case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGER), "ship4"); break;
		case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LYON), "ship4"); break;
		case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINK), "ship4"); break;
		case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGER_H), "ship4"); break;
		case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEOTH_H), "ship4"); break;
		case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CARAVELR), "ship4"); break;
        case 12:  FillShipParamShipyard(NPChar,GenerateStoreShip(SHIP_CASTELF), "ship4"); break;
        }
	}
	else // = If Realistic SHIP PURCHASE IS enabled
	{
		iTest_ship = rand(6);
		switch(iTest_ship) {
		case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_KETCH), "ship4"); break;
		case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BOUNTY), "ship4"); break;
		case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CUTTER), "ship4"); break;
		case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_EDINBURG), "ship4"); break;
        case 5:  FillShipParamShipyard(NPChar,GenerateStoreShip(SHIP_LYON), "ship4"); break;
        case 6:  FillShipParamShipyard(NPChar,GenerateStoreShip(SHIP_CASTELF), "ship4"); break;
        }
	}
	if (sti(PChar.rank) > 1)
	{
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(28); //50% chance to get a ship here
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGER), "ship5"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LYON), "ship5"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINK), "ship5"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGER_H), "ship5"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEOTH_H), "ship5"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SLOOP), "ship5"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_YACHT), "ship5"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SPEEDY), "ship5"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARQUE), "ship5"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship5"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SHNYAVA), "ship5"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SCHOONER), "ship5"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBEC), "ship5"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIGANTINE), "ship5"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship5"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CARAVELR), "ship5"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(10); //50%
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CUTTER), "ship5"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_EDINBURG), "ship5"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGER), "ship5"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LYON), "ship5"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGERVML), "ship5"); break;
            case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship5"); break;
			}
		}
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(46); //50%
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARQUE), "ship6"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HEBEK), "ship6"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SHNYAVA), "ship6"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SCHOONER), "ship6"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBEC), "ship6"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIGANTINE), "ship6"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship6"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG), "ship6"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARKENTINE), "ship6"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_INTERCEPTOR), "ship6"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FLEUT), "ship6"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship6"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG_20_GUN1_18), "ship6"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINNACE), "ship6"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SOPHIE), "ship6"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEON_L), "ship6"); break;
			case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HOOKER1), "ship6"); break;
			case 18:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG_N1), "ship6"); break;
			case 19:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_USS_ENTERPRISE), "ship6"); break;
			case 20:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HANNAH_P), "ship6"); break;
			case 21:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBECLIGHT), "ship6"); break;
			case 22:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARQUE_L), "ship6"); break;
			case 23:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SCHOONER_L), "ship6"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(10); //50%
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGER), "ship6"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LYON), "ship6"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGERVML), "ship6"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGER_H), "ship6"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINK), "ship6"); break;
            case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship6"); break;
            case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship6"); break;
			}
		}
	}
	if (sti(PChar.rank) > 3)
	{
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(60); //33% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG_20_GUN1_18), "ship8"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINNACE), "ship8"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SOPHIE), "ship8"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEON_L), "ship8"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HOOKER1), "ship8"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG_N1), "ship8"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_USS_ENTERPRISE), "ship8"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HANNAH_P), "ship8"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBECLIGHT), "ship8"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARQUE_L), "ship8"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SCHOONER_L), "ship8"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship8"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBEC_FRANCE), "ship8"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FLEUT4_50), "ship8"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PO_FLEUT50), "ship8"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG3), "ship8"); break;
			case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PACKET_BRIG), "ship8"); break;
			case 18:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_ENTERPRISE), "ship8"); break;
			case 19:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship8"); break;
			case 20:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_COLONIALSCHOONER), "ship8"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(12); //33% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LUGGER_H), "ship8"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINK), "ship8"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEOTH_H), "ship8"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SLOOP), "ship8"); break;
            case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LYON), "ship8"); break;
            case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship8"); break;
			}
		}
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(48); //33% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship9"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBEC_FRANCE), "ship9"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FLEUT4_50), "ship9"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PO_FLEUT50), "ship9"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG3), "ship9"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PACKET_BRIG), "ship9"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_ENTERPRISE), "ship9"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SLOOPOFWAR), "ship9"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINNACE3_50), "ship9"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CARAVEL), "ship9"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CARAVEL2), "ship9"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBECAS), "ship9"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINNACE11), "ship9"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship9"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLECORVETTE), "ship9"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_COLONIALSCHOONER), "ship9"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(12); //33% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEOTH_H), "ship9"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SLOOP), "ship9"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_YACHT), "ship9"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SPEEDY), "ship9"); break;
            case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship9"); break;
            case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship9"); break;
			}
		}
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(48); //33% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_ENTERPRISE), "ship10"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SLOOPOFWAR), "ship10"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINNACE3_50), "ship10"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CARAVEL), "ship10"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CARAVEL2), "ship10"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship10"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINNACE11), "ship10"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BLACKANGEL), "ship10"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLECORVETTE), "ship10"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATAVIA2), "ship10"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CRIMSONBLOOD), "ship10"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATAVIA), "ship10"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CORVFRIG2_50), "ship10"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GREYHOUND), "ship10"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FRIGATE_L), "ship10"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FELIPE), "ship10"); break;
            case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship10"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(12); //33% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_YACHT), "ship10"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SPEEDY), "ship10"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARQUE), "ship10"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBECLIGHT), "ship10"); break;
            case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship10"); break;
			}
		}
	}
	if (sti(PChar.rank) > 5)
	{
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(88); //20% chance of a ship here
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLECORVETTE), "ship11"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATAVIA2), "ship11"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CRIMSONBLOOD), "ship11"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATAVIA), "ship11"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CORVFRIG2_50), "ship11"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GREYHOUND), "ship11"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FRIGATE_L), "ship11"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FELIPE), "ship11"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLEFRIGATE), "ship11"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CORVETTE5), "ship11"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FLEUT2), "ship11"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINNACE2), "ship11"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_THEBLACKPEARL), "ship11"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_QueenAnnesRevenge), "ship11"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BLACKPEARL), "ship11"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_Revenge), "ship11"); break;
			case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_30GunFrigate), "ship11"); break;
			case 18:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SURPRISE), "ship11"); break;
			case 19:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_28GUNFRIGATE), "ship11"); break;
			case 20:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CORVETTE), "ship11"); break;
			case 21:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_RaaFrigate), "ship11"); break;
			case 22:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_32GunFrigate), "ship11"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(20); //20%
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship11"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBECLIGHT), "ship11"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SHNYAVA), "ship11"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SCHOONER), "ship11"); break;
            case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship11"); break;
			}
		}
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP purchase is NOT enabled
		{
			iTest_ship = rand(100);  //20%
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLEFRIGATE), "ship12"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CORVETTE5), "ship12"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FLEUT2), "ship12"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINNACE2), "ship12"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_THEBLACKPEARL), "ship12"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_QueenAnnesRevenge), "ship11"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BLACKPEARL), "ship12"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_Revenge), "ship12"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_30GunFrigate), "ship12"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SURPRISE), "ship12"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_28GUNFRIGATE), "ship12"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CORVETTE), "ship12"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LYDIA), "ship12"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_JAMAICASHIP), "ship12"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NIGHTMARE), "ship12"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_COLONIALFRIGATE), "ship12"); break;
			case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BOUSSOLE), "ship12"); break;
			case 18:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LIGHTFRIGATE), "ship12"); break;
			case 19:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEON_H), "ship12"); break;
			case 20:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_RaaFrigate), "ship12"); break;
			case 21:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_32GunFrigate), "ship12"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(20); //20%
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SHNYAVA), "ship12"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SCHOONER), "ship12"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBEC), "ship12"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIGANTINE), "ship12"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship12"); break;
			}
		}
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(95); //20% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LYDIA), "ship13"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_JAMAICASHIP), "ship13"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_Revenge), "ship13"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_COLONIALFRIGATE), "ship13"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BOUSSOLE), "ship13"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LIGHTFRIGATE), "ship13"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINEFRIGATE), "ship13"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEON_H), "ship13"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FASTGALLEON1), "ship13"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MERMAIDGRIEF), "ship13"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FEARLESS), "ship13"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FRIGATE_SAT), "ship13"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FRIGATE), "ship13"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SALAMANDER), "ship13"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FLEUTOFWAR34G), "ship13"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEON1), "ship13"); break;
			case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_INDIAMAN), "ship13"); break;
			case 18:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SIRIUS1), "ship13"); break;
			case 19:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_UNICORN), "ship13"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(20); //20%
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBEC), "ship13"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIGANTINE), "ship13"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship13"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG), "ship13"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARKENTINE), "ship13"); break;
            case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship13"); break;
			}
		}
	}
	if (sti(PChar.rank) > 8)
	{
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(525); //4% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHLINESHIP), "ship14"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHLINESHIP2), "ship14"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FRIGATE_SAT), "ship14"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FRIGATE), "ship14"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_Revenge), "ship14"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FLEUTOFWAR34G), "ship14"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEON1), "ship14"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_INDIAMAN), "ship14"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SIRIUS1), "ship14"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEON), "ship14"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_AMSTERDAM), "ship14"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MORDAUNT), "ship14"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_WAR_PINNACE), "ship14"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHPINNACE), "ship14"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_TWODECKER1_47), "ship14"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNE), "ship14"); break;
			case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LA_LICORNE), "ship14"); break;
			case 18:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINESHIP5), "ship14"); break;
			case 19:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_UNICORN), "ship14"); break;
			case 20:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINEFRIGATE), "ship14"); break;
			case 21:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINESHIP47), "ship14"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(100); //4% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG), "ship14"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARKENTINE), "ship14"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship14"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLEXEBEC), "ship14"); break;
            case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship14"); break;
			}
		}
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(700); // 2.8% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SIRIUS1), "ship15"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_GALEON), "ship15"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_AMSTERDAM), "ship15"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MORDAUNT), "ship15"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_WAR_PINNACE), "ship15"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHPINNACE), "ship15"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_TWODECKER1_47), "ship15"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNE), "ship15"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LA_LICORNE), "ship15"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINESHIP47), "ship15"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINESHIP5), "ship15"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINESHIP), "ship15"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_WARGALLEON2), "ship15"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHLINESHIP2), "ship15"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_RN_BATTLEFRIGATE), "ship15"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHLINESHIP), "ship15"); break;
			case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINESHIPHEAVY), "ship15"); break;
			case 18:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_WARSHIP), "ship15"); break;
			case 19:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_COURONNE), "ship15"); break;
			case 20:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHSHIP), "ship15"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(140); //2.8% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_INTERCEPTOR), "ship15"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLEXEBEC), "ship15"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG_20_GUN1_18), "ship15"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SOPHIE), "ship15"); break;
            case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship15"); break;
			}
		}
	}
	if (sti(PChar.rank) > 12)
	{
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(425); //4% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINESHIP5), "ship141"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINESHIP), "ship141"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_WARGALLEON2), "ship141"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHLINESHIP2), "ship141"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_RN_BATTLEFRIGATE), "ship141"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHLINESHIP), "ship141"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINEFRIGATE), "ship141"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_WARSHIP), "ship141"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_COURONNE), "ship141"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHSHIP), "ship141"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_ENDEAVOUR), "ship141"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SEVENPROVINCIEN), "ship141"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HEAVYWARSHIP), "ship141"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLESHIP), "ship141"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BELLONA), "ship141"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_POSEIDON), "ship141"); break;
			case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MORDAUNT), "ship141"); break;
            case 18:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_Revenge), "ship141"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(175); //4% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG_20_GUN1_18), "ship141"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SOPHIE), "ship141"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HOOKER1), "ship141"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG_N1), "ship141"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARQUE_L), "ship141"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SCHOONER_L), "ship141"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship141"); break;
            case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship141"); break;
			}
        }
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(595); //2.8% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINEFRIGATE), "ship151"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_WARSHIP), "ship151"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_COURONNE), "ship151"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHSHIP), "ship151"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_ENDEAVOUR), "ship151"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHLINESHIP), "ship151"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HEAVYWARSHIP), "ship151"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLESHIP), "ship151"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BELLONA), "ship151"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_POSEIDON), "ship151"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_DUTCHLINESHIP2), "ship151"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MORDAUNT), "ship151"); break;
			case 13:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_INTREPIDE), "ship151"); break;
			case 14:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FR_SUPERIORWARSHIP1), "ship151"); break;
			case 15:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLESHIP1), "ship151"); break;
			case 16:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SUPERBE), "ship151"); break;
			case 17:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINK), "ship151"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(280); //2.8% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship151"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG_N1), "ship151"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_USS_ENTERPRISE), "ship151"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HANNAH_P), "ship151"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BARQUE_L), "ship151"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SCHOONER_L), "ship151"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_CASTELF), "ship151"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_COLONIALSCHOONER), "ship151"); break;
			}
		}
	}
	if (sti(PChar.rank) > 18)
	{
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(480); //2.5% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BELLONA), "ship16"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_POSEIDON), "ship16"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PINNACE), "ship16"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MORDAUNT), "ship16"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_INTREPIDE), "ship16"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_FR_SUPERIORWARSHIP1), "ship16"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLESHIP1), "ship16"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SUPERBE), "ship16"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_LINK), "ship16"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MANOWAR_FAST), "ship16"); break;
			case 11:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MANOWAR), "ship16"); break;
			case 12:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLEMANOWAR), "ship16"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(280); //2.5% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_USS_ENTERPRISE), "ship16"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_HANNAH_P), "ship16"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBEC_FRANCE), "ship16"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG3), "ship16"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_PACKET_BRIG), "ship16"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_ENTERPRISE), "ship16"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship16"); break;
			}
		}
		if(!REALISTIC_SHIP_PURCHASE) // = If Realistic SHIP PURCHASE is NOT enabled
		{
			iTest_ship = rand(400); //2.5% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLESHIP1), "ship17"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SUPERBE), "ship17"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MANOWAR_FAST), "ship17"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MANOWAR), "ship17"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BATTLEMANOWAR), "ship17"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_MANOW50_GUB), "ship17"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_VICTORY), "ship17"); break;
			case 8:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SOLEILROYAL), "ship17"); break;
			case 9:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_ARABELLA), "ship17"); break;
			case 10:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SanFelipe), "ship17"); break;
			}
		}
		else // = If Realistic SHIP PURCHASE IS enabled
		{
			iTest_ship = rand(280); //2.5% chance
			switch(iTest_ship) {
			case 1:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBEC_FRANCE), "ship17"); break;
			case 2:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_BRIG3), "ship17"); break;
			case 3:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_NEPTUNUS), "ship17"); break;
			case 4:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_ENTERPRISE), "ship17"); break;
			case 5:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_SLOOPOFWAR), "ship17"); break;
			case 6:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_XEBECAS), "ship17"); break;
			case 7:  FillShipParamShipyard(NPChar, GenerateStoreShip(SHIP_ARABELLA), "ship17"); break;
			}
		}
	}
}

void FreeShipFromShipyard(ref NPChar)
{
	if (GetNpcQuestPastDayParam(NPChar, "shipyardDate") > (3 + rand(6)))
	{
        aref   arDest, arImt;
		string sAttr;
		int    iNum, i, iShip;
		makearef(arDest, NPChar.shipyard);
		iNum = GetAttributesNum(arDest);
		for (i = 0; i < iNum; i++)
		{
	    	arImt = GetAttributeN(arDest, i);
	    	iShip = sti(arImt.Type); //GetAttributeValue(arImt));
	    	DeleteAttribute(&RealShips[iShip], "StoreShip"); // можно тереть
	    }
        DeleteAttribute(NPChar, "shipyard");
	}
}

void FillShipParamShipyard(ref NPChar, int _iType, string _sShipNum)
{
    aref    arTo, arFrom;
    
	DeleteAttribute(NPChar, "ship");
    NPChar.Ship.Type = _iType;
    
	SetRandomNameToShip(NPChar);

    SetBaseShipData(NPChar);
    SetCrewQuantity(NPChar, 0);
    if (sti(NPChar.Ship.Cannons.Type) != CANNON_TYPE_NONECANNON)
    {
    	NPChar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS12; // to_do переделать на продажу без орудий вообще
    }
    DeleteAttribute(NPChar, "Ship.Cargo");  //пустой трюм
    SetGoodsInitNull(NPChar);
    RecalculateCargoLoad(NPChar);
    
    FillShipyardShipBack(NPChar, _sShipNum);
}

void FillShipyardShip(ref NPChar, string _sShipNum)
{
    aref    arTo, arFrom;

	DeleteAttribute(NPChar, "ship");

    makearef(arFrom,   NPChar.shipyard.(_sShipNum));
    NPChar.Ship = "";
	makearef(arTo, NPChar.Ship);
	CopyAttributes(arTo, arFrom);
}

void FillShipyardShipBack(ref NPChar, string _sShipNum)
{
    aref    arTo, arFrom;

  	DeleteAttribute(NPChar, "shipyard." + _sShipNum);
    NPChar.shipyard.(_sShipNum) = "";
    makearef(arTo,   NPChar.shipyard.(_sShipNum));
	makearef(arFrom, NPChar.Ship);
	CopyAttributes(arTo, arFrom);
}

// палуба от типа корабля
string GetShip_deck(ref chr, bool map2sea)
{
	string ret, add;
	int    iType = sti(chr.Ship.Type);
	if (map2sea)
	{
	    ret = "Ship_deck_";
	}
	else
	{
	    ret = "Deck_Near_Ship_";
	}
	add = "Low"; // если нет типа
	if (iType != SHIP_NOTUSED)
	{
        ref rRealShip = GetRealShip(iType);
        
		add = rRealShip.DeckType;
	}
	
	return ret + add;
}

void MakeCloneShipDeck(ref chr, bool map2sea)
{
	ref rOrg, rClone;
	int iOrg, iClone;
    string locId, toLocId;
    
    locId = GetShip_deck(chr, map2sea);
    if (map2sea)
	{
	    toLocId = "Ship_deck";
	}
	else
	{
	    toLocId = "Deck_Near_Ship";
	}
	
	iOrg = FindLocation(locId);
	iClone = FindLocation(toLocId);

	makeref(rOrg, Locations[iOrg]);
	makeref(rClone, Locations[iClone]);

	DeleteAttribute(rClone, "");
	CopyAttributes(rClone, rOrg);
	rClone.id = toLocId;
	rClone.index = iClone;
}

void MakeCloneFortBoarding(string fromLocId)
{
	ref rOrg, rClone;
	int iOrg, iClone;
    string toLocId;
    
    toLocId = "BOARDING_FORT";

	iOrg = FindLocation(fromLocId);
	iClone = FindLocation(toLocId);

	makeref(rOrg, Locations[iOrg]);
	makeref(rClone, Locations[iClone]);

	DeleteAttribute(rClone, "");
	CopyAttributes(rClone, rOrg);
	rClone.id = toLocId;
	rClone.index = iClone;
	
    rClone.type = "fort_attack";
	LAi_LocationFantomsGen(rClone, false);
	DeleteAttribute(rClone, "reload");
	//это подкручивание другого файла локаторов. там нет goto, soldiers и пр. есть rld и дополн.сундуки
	if (rClone.models.always.locators == "fortV_locators") 
	{
		rClone.models.always.locators = "fortV_lAttack";
		rClone.models.always.fortV = "fortV_attack";	
	}
	else
	{
		rClone.models.always.locators = "fortVRight_lAttack";
		rClone.models.always.fortV = "fortVRight_attack";
	}
	rClone.boarding.locatorNum = 15;
	rClone.boarding = "false";
	rClone.boarding.nextdeck = "";
	rClone.image = "loading\Fort_512.tga";
}