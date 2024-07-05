/////////////////////////
// GOF 1.2
/////////////////////////
// SOURCE 01.001.00
/*
01.000.001
- Fixed SHIP_MANOW50_GUB cannons.
- Fixed SHIP_BATTLEMANOWAR cannons.
01.001.000
- Added ships in as per Luke and Craiggo "Work 2.2".
*/
///// Luke159 Ship max calibures changed for a little more historical accuracy
///// Luke159 Added switch to ship hp values
///// Luke159 ships crew sizes updated

void InitShips()
{
  ref refShip;

	for (int idx=0;idx<SHIP_TYPES_QUANTITY_WITH_FORT;idx++)
	{
		makeref(refShip,ShipsTypes[idx]);

		//#20170912-02
        DeleteAttribute(refShip, "EmblemedSails");
        DeleteAttribute(refShip, "GeraldSails");

		refship.index = idx;

		refship.InertiaAccelerationX = 0.2;		refship.InertiaBrakingX = 0.7;
		refship.InertiaAccelerationY = 0.4;		refship.InertiaBrakingY = 0.4;
		refship.InertiaAccelerationZ = 1.0;		refship.InertiaBrakingZ = 1.0;

		refship.Rocking.y = 0.5;
		refship.Rocking.az = 0.05;

		refship.NetGeraldSails = "";
		refship.Soundtype = "";

		refship.WaterLine = 0.0;
		refship.SpeedDependWeight = 0.0;
		refship.SubSeaDependWeight = 0.0;
		refship.TurnDependWeight = 0.0;
		refship.TurnDependSpeed = 0.0;

		refShip.Height.Bombs.Y		= 3.0;		refShip.Height.Bombs.DY		= 1.0;
		refShip.Height.Grapes.Y		= 4.0;		refShip.Height.Grapes.DY	= 1.0;
		refShip.Height.Knippels.Y	= 25.0;		refShip.Height.Knippels.DY	= 15.0;
		refShip.Height.Balls.Y		= 3.0;		refShip.Height.Balls.DY		= 1.0;

        refship.WindAgainstSpeed   = 1.0;//boal
		refship.CabinType          = "Cabin_Small";
        refShip.AbordageLocation			= "BOARDING_SMALL_DECK";
        refship.DeckType          = "Low";

		refShip.MaxCaliber	= 8;
		refShip.Cannon		= CANNON_TYPE_CANNON_LBS4;

		aref cannonl, cannonr, cannonb, cannonf;

		refship.CanEncounter = true;
		refship.Type.Merchant = true;
		refship.Type.War = true;
		refship.Track.Enable = false;
		refShip.FireHeight = 3.0;

		refShip.Massa = 1500000.0;
		refShip.Volume = 900.0;
		refShip.lowpolycrew = 5;
		refShip.buildtime = 10;

		refShip.rcannon = 0;
		refShip.lcannon = 0;
		refShip.fcannon = 0;
		refShip.bcannon = 0;

		makearef(cannonl,ShipsTypes[idx].Cannons.Borts.cannonl);
		makearef(cannonr,ShipsTypes[idx].Cannons.Borts.cannonr);
		makearef(cannonf,ShipsTypes[idx].Cannons.Borts.cannonf);
		makearef(cannonb,ShipsTypes[idx].Cannons.Borts.cannonb);

		cannonf.FireZone	= Degree2Radian(30.0);
		cannonf.FireDir		= Degree2Radian(0.0);
		cannonf.FireAngMin	= -0.35;
		cannonf.FireAngMax	= 0.60;

		cannonr.FireZone	= Degree2Radian(80.0);
		cannonr.FireDir		= Degree2Radian(90.0);
		cannonr.FireAngMin	= -0.35;
		cannonr.FireAngMax	= 0.60;

		cannonb.FireZone	= Degree2Radian(30.0);
		cannonb.FireDir		= Degree2Radian(180.0);
		cannonb.FireAngMin	= -0.35;
		cannonb.FireAngMax	= 0.60;

		cannonl.FireZone	= Degree2Radian(80.0);
		cannonl.FireDir		= Degree2Radian(270.0);
		cannonl.FireAngMin	= -0.35;
		cannonl.FireAngMax	= 0.60;
	}

	///////////////////////////////////////////////////////////////////////////
	//// Boat
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BOAT]);
	refShip.Name				= "Boat";
	refship.Soundtype				= "lugger";
	refShip.Class				= 7;
	refShip.Cannon				= CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber				= 4;
	refShip.Weight				= Tonnes2CWT(10);
	refShip.Capacity				= 50;
	refShip.CannonsQuantity			= 0;
	refShip.rcannon 							= 0;
	refShip.lcannon 							= 0;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew				= 10; //sailing crew
	refShip.MinCrew				= 2;
	refShip.BoardingCrew						= 0;
	refShip.GunnerCrew							= 0;
	refShip.CannonerCrew						= 0;
	refShip.SailorCrew							= 4;
	refShip.SpeedRate							= 4;
	refShip.TurnRate							= 40;
	refShip.Price				= 300;
	refShip.HP					= 100;
	refShip.SP					= 200;
	refship.CanEncounter					= false;
	refship.Type.Merchant					= false;
	refship.Type.War						= false;
	refShip.lowpolycrew = 0;

	refship.WaterLine							= -0.3;

	refShip.Massa = 10000.0;
	refShip.Volume = 100.0;

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 0.4;	refship.InertiaBrakingY		= 0.2;
	refship.InertiaAccelerationZ	= 0.15;	refship.InertiaBrakingZ		= 0.05;

	///////////////////////////////////////////////////////////////////////////
	//// Tartane
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_TARTANE]);
	refShip.Name				= "Tartane";
	refship.Soundtype				= "lugger";
	refShip.Class				= 7;
	refShip.Cannon				= CANNON_TYPE_NONECANNON;
	refShip.MaxCaliber				= 4;
	refShip.Weight				= Tonnes2CWT(10);
	refShip.Capacity				= 50;
	refShip.CannonsQuantity			= 0;
	refShip.rcannon 							= 0;
	refShip.lcannon 							= 0;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew				= 12;
	refShip.MinCrew				= 2;
	refShip.BoardingCrew						= 8;
	refShip.GunnerCrew							= 0;
	refShip.CannonerCrew						= 0;
	refShip.SailorCrew							= 4;
	refShip.SpeedRate							= 7.0;
	refShip.TurnRate							= 50;
	refShip.Price				= 500;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP					= 200;
}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 100;
}
	refShip.SP					= 200;
	refship.CanEncounter					= false;
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 10.0;
	refShip.sea_enchantment					= 4.0;
	refShip.lowpolycrew = 3;
	refShip.buildtime = 10;

	refShip.Massa = 10000.0;
	refShip.Volume = 20.0;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "1.0, 2.0";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "1.2, 2.0";
	refship.Track2.Speed	= "0.15, 0.25";

	 //Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	//// War Tartane
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_WAR_TARTANE]);
	refShip.Name			= "WarTartane";
	refship.Soundtype			= "lugger";
	refShip.Class			= 7;
	refShip.Cannon			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber			= 4;
	refShip.Weight			= Tonnes2CWT(10);
	refShip.Capacity			= 210;
	refShip.CannonsQuantity		= 8;
	refShip.rcannon 							= 4;
	refShip.lcannon 							= 4;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew			= 20;
	refShip.MinCrew			= 3;
	refShip.BoardingCrew						= 3;
	refShip.GunnerCrew							= 8;
	refShip.CannonerCrew						= 8;
	refShip.SailorCrew							= 8;
	refShip.SpeedRate							= 11.0;
	refShip.TurnRate							= 70;
	refShip.Price			= 2500;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP				= 350;
}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 250;
}
	refShip.SP				= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.CanEncounter					= true;
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 10.5;
	refShip.sea_enchantment					= 3.0;
	refShip.lowpolycrew						= 3;
	refShip.buildtime = 10;

	refShip.Massa = 50000.0;
	refShip.Volume = 100.0;

	refship.WaterLine					= -0.1;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.2;
    	refship.WindAgainstSpeed   = 7.0;//boal

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "1.0, 2.0";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "1.2, 2.0";
	refship.Track2.Speed	= "0.15, 0.25";

	 //Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Gunboat
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GUNBOAT]);
	refShip.Name			= "Gunboat";
	refship.Soundtype			= "lugger";
	refShip.Class			= 7;
	refShip.Cannon			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber			= 4;
	refShip.Weight			= Tonnes2CWT(15);
	refShip.Capacity			= 300;
	refShip.CannonsQuantity		= 7;
	refShip.rcannon 							= 3;
	refShip.lcannon 							= 3;
	refShip.fcannon 							= 1;
	refShip.bcannon 							= 0;
	refShip.MaxCrew			= 25;
	refShip.MinCrew			= 3;
	refShip.BoardingCrew						= 13;
	refShip.GunnerCrew							= 7;
	refShip.CannonerCrew						= 14;
	refShip.SailorCrew							= 12;
	refShip.SpeedRate							= 12.0;
	refShip.TurnRate							= 68;
	refShip.Price			= 3500;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP				= 420;
}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 320;
}
	refShip.SP				= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 11.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew						= 4;
	refShip.buildtime = 10;

	refShip.Massa = 50000.0;
	refShip.Volume = 100.0;

	refship.WaterLine					= -0.4;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.2;
    	refship.WindAgainstSpeed   = 7.0;//boal

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;
	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "1.0, 2.0";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "1.2, 2.0";
	refship.Track2.Speed	= "0.15, 0.25";

	 //Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// bermsloop
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BERMSLOOP]);
	refShip.Name            			= "Bermsloop";
	refship.Soundtype			= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity        			= 540;
	refShip.CannonsQuantity		= 8;
	refShip.rcannon 							= 3;
	refShip.lcannon 							= 3;
	refShip.fcannon 							= 1;
	refShip.bcannon 							= 1;
	refShip.MaxCrew         		= 50;
	refShip.MinCrew         			= 4;
	refShip.BoardingCrew				= 22;
	refShip.GunnerCrew					= 8;
	refShip.CannonerCrew				= 16;
	refShip.SailorCrew					= 48;
	refShip.SpeedRate       			= 14.2;
	refShip.TurnRate        			= 68.0;
	refShip.Price           			= 7000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 2500;
}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 1500;
}
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 8.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= -0.0;
	refship.SpeedDependWeight			= 0.4;
	refship.SubSeaDependWeight			= 0.5;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	 //Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	/////////////////////////////////////////////////////////////////////////
	//// Schooner - Hannah
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_HANNAH]);
	refShip.Name            				= "Hannah";
	refship.Soundtype				= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      	= 8;
	refShip.Weight							= Tonnes2CWT(150);
	refShip.Capacity        			= 750;
	refShip.CannonsQuantity					= 4;
	refShip.rcannon 									= 2;
	refShip.lcannon 									= 2;
	refShip.fcannon 									= 0;
	refShip.bcannon 									= 0;
	refShip.MaxCrew         			= 50;
	refShip.MinCrew         				= 6;
	refShip.BoardingCrew				= 32;
	refShip.GunnerCrew						= 4;
	refShip.CannonerCrew					= 8;
	refShip.SailorCrew				= 42;
	refShip.SpeedRate					= 13.8;
	refShip.TurnRate        			= 52.0;
	refShip.Price           		= 15000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 2800;
}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 1800;
}
	refShip.SP              	= 200;
	refShip.AbordageLocation				= "Boarding Deck_02";
	refship.Type.Merchant						= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed	= 8.0;
	refShip.sea_enchantment		= 2.0;
	refShip.lowpolycrew 					= 10;
	refShip.buildtime 					= 40;

	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.03;

	refship.WaterLine		= 0.2;

	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 0.2;
	refship.TurnDependWeight	= 0.3;
	refship.WindAgainstSpeed   	= 7.5;//boal

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 1.0;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 8;
	refship.Track1.Width		= "1.2, 2.2";
	refship.Track1.Speed		= "7.2, 8.2";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 6;
	refship.Track2.Width		= "2.2, 3.2";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Ketch - Nonsuch
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_KETCH]);
	refShip.Name            				= "Ketch";
	refship.Soundtype				= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      	= 8;
	refShip.Weight							= Tonnes2CWT(150);
	refShip.Capacity        			= 650;
	refShip.CannonsQuantity					= 8;
	refShip.rcannon 									= 4;
	refShip.lcannon 									= 4;
	refShip.fcannon 									= 0;
	refShip.bcannon 									= 0;
	refShip.MaxCrew         		= 50;
	refShip.MinCrew         				= 5;
	refShip.BoardingCrew			= 21;
	refShip.GunnerCrew					= 8;
	refShip.CannonerCrew			= 16;
	refShip.SailorCrew					= 50;
	refShip.SpeedRate       			= 13.7;
	refShip.TurnRate        				= 62.0;
	refShip.Price           		= 8000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 2950;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 1950;
}
	refShip.SP              	= 200;
	refShip.AbordageLocation	= "Boarding Deck_02";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed	= 7.0;
	refShip.sea_enchantment		= 2.0;
	refShip.lowpolycrew 		= 8;
	refShip.buildtime 		= 20;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.035;

	refship.WaterLine		= 0.0;
	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 0.6;
	refship.TurnDependWeight	= 0.2;
	refship.WindAgainstSpeed   	= 10.0;//boal

	refship.InertiaAccelerationX	= 10.0;	refship.InertiaBrakingX		= 10.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 10.0;	refship.InertiaBrakingZ		= 10.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 9;
	refship.Track1.Width		= "2.0, 3.0";
	refship.Track1.Speed		= "8.0, 10.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7;
	refship.Track2.Width		= "3.0, 4.5";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Bounty
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BOUNTY]);
	refShip.Name            			= "Bounty";
	refship.Soundtype			= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 1250;
	refShip.CannonsQuantity		= 4;
	refShip.rcannon 							= 2;
	refShip.lcannon 							= 2;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 77;
	refShip.MinCrew         			= 8;
	refShip.BoardingCrew						= 20;
	refShip.GunnerCrew							= 4;
	refShip.CannonerCrew				= 8;
	refShip.SailorCrew					= 76;
	refShip.SpeedRate       			= 11.5;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 22000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3400;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2400;
}
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 2;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.01;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Lugger
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LUGGER]);
	refShip.Name            			= "Lugger";
	refship.Soundtype			= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity        			= 600;
	refShip.CannonsQuantity				= 8;
	refShip.rcannon 				= 4;
	refShip.lcannon 				= 4;
	refShip.fcannon 				= 0;
	refShip.bcannon 				= 0;
	refShip.MaxCrew         		= 50;
	refShip.MinCrew         			= 5;
	refShip.BoardingCrew				= 21;
	refShip.GunnerCrew					= 8;
	refShip.CannonerCrew				= 16;
	refShip.SailorCrew					= 40;
	refShip.SpeedRate       			= 14.5;
	refShip.TurnRate        			= 60.0;
	refShip.Price           			= 12000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 2600;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 1600;
}
	refShip.SP              			= 200;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.7;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine		= -0.5;
	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 0.6;
	refship.TurnDependWeight	= 0.2;
	refship.WindAgainstSpeed   	= 10.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 9;
	refship.Track1.Width		= "2.0, 3.0";
	refship.Track1.Speed		= "8.0, 10.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7;
	refship.Track2.Width		= "3.0, 4.5";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Lyon Hoy
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LYON]);
	refShip.Name            			= "Lyon";
	refship.Soundtype					= "lugger";
	refShip.Class					= 7;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 8;
	refShip.Weight						= Tonnes2CWT(170);
	refShip.Capacity        			= 800;
	refShip.CannonsQuantity				= 8;
	refShip.rcannon 					= 4;
	refShip.lcannon 					= 4;
	refShip.fcannon 					= 0;
	refShip.bcannon 					= 0;
	refShip.MaxCrew         			= 55;
	refShip.MinCrew         			= 5;
	refShip.BoardingCrew				= 26;
	refShip.GunnerCrew					= 8;
	refShip.CannonerCrew				= 16;
	refShip.SailorCrew					= 50;
	refShip.SpeedRate					= 14.8;
	refShip.TurnRate        			= 39.0;
	refShip.Price           			= 20000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3200;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2200;
}
	refShip.SP              			= 200;
	//refShip.AbordageLocation			= "Boarding Deck_02";
	refship.CanEncounter					= true;
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 8.5;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.45;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= -0.0;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 8.0;	refship.InertiaBrakingZ		= 8.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 2.5";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.05;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Caravel Redonda
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CARAVELR]);
	refShip.Name            	= "CaravelR";
	refship.Soundtype		= "lugger";
	refShip.Class			= 7;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      	= 16;
	refShip.Weight			= Tonnes2CWT(500);
	refShip.Capacity        	= 3000;
	refShip.CannonsQuantity		= 10;
	refShip.rcannon 		= 4;
	refShip.lcannon 		= 4;
	refShip.fcannon 		= 0;
	refShip.bcannon 		= 2;
	refShip.MaxCrew         	= 295;
	refShip.MinCrew         	= 15;
	refShip.BoardingCrew		= 250;
	refShip.GunnerCrew		= 10;
	refShip.CannonerCrew		= 20;
	refShip.SailorCrew		= 290;
	refShip.SpeedRate		= 10.0;
	refShip.TurnRate        	= 29;
	refShip.Price           	= 42000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 7300;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6300;
}
	refShip.SP              	= 200;
	//refShip.AbordageLocation	= "Boarding Deck_02";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed	= 2;
	refShip.sea_enchantment		= 1.5;
	refShip.lowpolycrew 		= 16;
	refShip.buildtime 		= 40;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.035;
	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           	= "Medium";

	refship.WaterLine		= 0.0;
	refship.SpeedDependWeight	= 0.15;
	refship.SubSeaDependWeight	= 0.6;
	refship.TurnDependWeight	= 0.2;
	refship.WindAgainstSpeed   	= 4.0;//boal

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 10;
	refship.Track1.Width		= "4.0, 5.0";
	refship.Track1.Speed		= "7.2, 9.2";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "5.0, 7.0";
	refship.Track2.Speed		= "0.15, 0.25";

//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Edinburg - Edinburgh Trader
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_EDINBURG]);
	refShip.Name            			= "Edinburg";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity       			= 1200;
	refShip.CannonsQuantity		= 14;
	refShip.rcannon 							= 7;
	refShip.lcannon 							= 7;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         		= 76;
	refShip.MinCrew         		= 8;
	refShip.BoardingCrew				= 26;
	refShip.GunnerCrew				= 14;
	refShip.CannonerCrew				= 28;
	refShip.SailorCrew				= 70;
	refShip.SpeedRate				= 11.7;
	refShip.TurnRate        			= 52.0;
	refShip.Price           			= 24000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3600;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2600;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant				= true;
	refship.Type.War				= false;
	refShip.fWindAgainstSpeed			= 4.0;
	refShip.sea_enchantment				= 1.8;
	refShip.lowpolycrew 				= 10;
	refShip.buildtime 				= 40;

	refship.Rocking.y 				= 0.4;
	refship.Rocking.az 				= 0.025;

	refship.WaterLine				= 0.04;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   			= 3.6;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.20;
	refship.Track1.LifeTime 			= 7.5;
	refship.Track1.Width				= "6.0, 7.0";
	refship.Track1.Speed				= "7.2, 9.2";

	refship.Track2.ZStart				= -0.15;
	refship.Track2.LifeTime 			= 5.0;
	refship.Track2.Width				= "6.0, 8.0";
	refship.Track2.Speed				= "0.15, 0.25";

	 //Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Cutter
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CUTTER]);
	refShip.Name            			= "Cutter";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity        			= 650;
	refShip.CannonsQuantity				= 12;
	refShip.rcannon 							= 4;
	refShip.lcannon 							= 4;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 60;
	refShip.MinCrew         			= 5;
	refShip.BoardingCrew				= 19;
	refShip.GunnerCrew					= 12;
	refShip.CannonerCrew				= 24;
	refShip.SailorCrew					= 50;
	refShip.SpeedRate       			= 13.1;
	refShip.TurnRate        			= 58.5;
	refShip.Price           			= 8000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 2900;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 1900;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= -0.0;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 0.5;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	 //Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// LuggerVML - Merchant Lugger
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LUGGERVML]);
	refShip.Name            			= "LuggerVML";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 950;
	refShip.CannonsQuantity				= 12;
	refShip.rcannon 							= 4;
	refShip.lcannon 							= 4;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 62;
	refShip.MinCrew         			= 6;
	refShip.BoardingCrew				= 20;
	refShip.GunnerCrew					= 12;
	refShip.CannonerCrew				= 24;
	refShip.SailorCrew					= 64;
	refShip.SpeedRate       			= 15.4;
	refShip.TurnRate        			= 53.5;
	refShip.Price           			= 17500;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3450;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2450;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 10;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;
	refship.WaterLine							= 0.3;
	refship.SpeedDependWeight			= 0.4;
	refship.SubSeaDependWeight			= 0.43;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 10.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Pink - Light Cutter
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PINK]);
	refShip.Name            			= "Pink";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity        			= 640;
	refShip.CannonsQuantity		= 12;
	refShip.rcannon 							= 4;
	refShip.lcannon 							= 4;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 60;
	refShip.MinCrew         			= 6;
	refShip.BoardingCrew				= 18;
	refShip.GunnerCrew					= 12;
	refShip.CannonerCrew				= 24;
	refShip.SailorCrew					= 50;
	refShip.SpeedRate       			= 13.6;
	refShip.TurnRate        			= 59.5;
	refShip.Price           			= 9000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 2850;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 1850;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 7.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.1;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 0.5;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Lugger_h
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LUGGER_H]);
	refShip.Name            			= "Lugger_h";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 790;
	refShip.CannonsQuantity		= 12;
	refShip.rcannon 							= 4;
	refShip.lcannon 							= 4;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 67;
	refShip.MinCrew         			= 7;
	refShip.BoardingCrew				= 24;
	refShip.GunnerCrew					= 12;
	refShip.CannonerCrew				= 24;
	refShip.SailorCrew					= 54;
	refShip.SpeedRate       			= 13.1;
	refShip.TurnRate        			= 47.5;
	refShip.Price           			= 9100;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3250;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2250;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 7.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 10;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;
	refship.WaterLine							= 0.50;
	refship.SpeedDependWeight			= 0.4;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 10.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

        ///////////////////////////////////////////////////////////////////////////
	//// Galeoth_h
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GALEOTH_H]);
	refShip.Name            			= "Galeoth_h";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity        			= 650;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 70;
	refShip.MinCrew         			= 8;
	refShip.BoardingCrew				= 14;
	refShip.GunnerCrew					= 16;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 70;
	refShip.SpeedRate       			= 13.8;
	refShip.TurnRate        			= 47.5;
	refShip.Price           			= 11000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3930;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2930;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= -0.0;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 9;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Sloop
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SLOOP]);
	refShip.Name            			= "Sloop";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(170);
	refShip.Capacity        			= 850;
	refShip.CannonsQuantity				= 14;
	refShip.rcannon 				= 6;
	refShip.lcannon 				= 6;
	refShip.fcannon 				= 0;
	refShip.bcannon 				= 2;
	refShip.MaxCrew         			= 75;
	refShip.MinCrew         			= 7;
	refShip.BoardingCrew				= 26;
	refShip.GunnerCrew					= 14;
	refShip.CannonerCrew				= 28;
	refShip.SailorCrew					= 65;
	refShip.SpeedRate					= 13.8;
	refShip.TurnRate        			= 59.0;
	refShip.Price           			= 18000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3100;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2100;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 7;
	refShip.sea_enchantment					= 3.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y 		= 0.45;
	refship.Rocking.az 		= 0.02;

	refship.WaterLine		= 0.0;

	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 0.3;
	refship.TurnDependWeight	= 0.3;
	refship.WindAgainstSpeed   	= 8.0;//boal

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 8.0;	refship.InertiaBrakingZ		= 8.0;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 9;
	refship.Track1.Width		= "2.0, 2.5";
	refship.Track1.Speed		= "5.2, 6.2";

	refship.Track2.ZStart		= -0.05;
	refship.Track2.LifeTime 	= 7;
	refship.Track2.Width		= "3.0, 4.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Yacht
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_YACHT]);
	refShip.Name            			= "Yacht";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 780;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 78;
	refShip.MinCrew         			= 7;
	refShip.BoardingCrew				= 23;
	refShip.GunnerCrew					= 16;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 64;
	refShip.SpeedRate       			= 12.6;
	refShip.TurnRate        			= 48.9;
	refShip.Price           			= 17000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3500;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2500;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 8.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 10;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= -0.3;
	refship.SpeedDependWeight			= 0.4;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Brig - Merchant Brig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SPEEDY]);
	refShip.Name            				= "Speedy";
	refship.Soundtype			= "lugger";
	refShip.Class						= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      		= 12;
	refShip.Weight						= Tonnes2CWT(250);
	refShip.Capacity        			= 2000;
	refShip.CannonsQuantity							= 14;
	refShip.rcannon 							= 7;
	refShip.lcannon 							= 7;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 83;
	refShip.MinCrew         			= 8;
	refShip.BoardingCrew				= 33;
	refShip.GunnerCrew					= 14;
	refShip.CannonerCrew				= 28;
	refShip.SailorCrew					= 70;
	refShip.SpeedRate       			= 15.5;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 27000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3900;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2900;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation				= "Boarding Deck_02";
	refship.Type.Merchant		= true;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 4.0;
	refShip.sea_enchantment		= 1.8;
	refShip.lowpolycrew 		= 16;
	refShip.buildtime 		= 60;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.04;

	refship.WaterLine		= 0.1;
	refship.SpeedDependWeight	= 0.27;
	refship.SubSeaDependWeight	= 0.6;
	refship.TurnDependWeight	= 0.3;
	refship.WindAgainstSpeed   	= 3.3;//boal
	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 12;
	refship.Track1.Width		= "2.0, 3.0";
	refship.Track1.Speed		= "6.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "4.0, 6.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// HMS SOPHIE
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SOPHIE]);
	refShip.Name 			= "Sophie";
	refship.Soundtype 			= "lugger";
	refShip.Class 			= 6;
	refShip.Cannon 			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber 			= 12;
	refShip.Weight 			= Tonnes2CWT(400);
	refShip.Capacity 			= 2200;
	refShip.CannonsQuantity 		= 18;
	refShip.rcannon 							= 9;
	refShip.lcannon 							= 9;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew 				= 90;
	refShip.MinCrew 				= 10;
	refShip.BoardingCrew 					= 46;
	refShip.GunnerCrew 							= 18;
	refShip.CannonerCrew 				= 36;
	refShip.SailorCrew 					= 76;
	refShip.SpeedRate 					= 13.5;
	refShip.TurnRate 				= 45.0;
	refShip.Price 					= 33000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP 					= 4200;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3200;
}
	refShip.SP 					= 250;
	refShip.AbordageLocation 				= "Boarding Deck_02";
	refship.Type.Merchant 					= false;
	refship.Type.War 					= true;
	refShip.fWindAgainstSpeed = 4.0;
	refShip.sea_enchantment = 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine = 0.05;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.3;
	refship.WindAgainstSpeed = 3.3;//boal
	refship.CabinType = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX = 0.2; refship.InertiaBrakingX = 2.0;
	refship.InertiaAccelerationY = 12; refship.InertiaBrakingY = 9;
	refship.InertiaAccelerationZ = 6.0; refship.InertiaBrakingZ = 4.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 1.0;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 15.0; refShip.Height.Knippels.DY = 10.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 1.0;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b2.vscale = 0.8;
	refShip.GeraldSails.rey_b3.vscale = 0.8;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width = "2.0, 3.0";
	refship.Track1.Speed = "6.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width = "4.0, 6.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Royal Brig - Heavy Brig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIG_N1]);
	refShip.Name            			= "Brig_n1";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(400);
	refShip.Capacity        			= 1500;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 87;
	refShip.MinCrew         			= 10;
	refShip.BoardingCrew						= 29;
	refShip.GunnerCrew							= 16;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 70;
	refShip.SpeedRate       			= 13.7;
	refShip.TurnRate        			= 42.0;
	refShip.Price           			= 22000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3800;
	}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2800;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.3;
	refShip.sea_enchantment					= 1.9;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.57;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.87;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// USS Enterprise - Schooner
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_USS_ENTERPRISE]);
	refShip.Name            			= "USS_Enterprise";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 1700;
	refShip.CannonsQuantity		= 14;
	refShip.rcannon 							= 7;
	refShip.lcannon 							= 7;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 88;
	refShip.MinCrew         			= 12;
	refShip.BoardingCrew				= 34;
	refShip.GunnerCrew					= 14;
	refShip.CannonerCrew				= 28;
	refShip.SailorCrew					= 78;
	refShip.SpeedRate				= 13.0;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 27000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3250;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2250;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 5.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew 				= 12;
	refShip.buildtime 				= 40;

	refship.Rocking.y 			= 0.4;
	refship.Rocking.az 			= 0.03;

	refship.WaterLine					= -0.2;

	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 0.2;
	refship.TurnDependWeight	= 0.3;
	refship.WindAgainstSpeed   	= 7.5;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 1.0;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 8;
	refship.Track1.Width		= "1.2, 2.2";
	refship.Track1.Speed		= "7.2, 8.2";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 6;
	refship.Track2.Width		= "2.2, 3.2";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Schooner - Hannah (Pirate Version)
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_HANNAH_P]);
	refShip.Name            			= "Hannah_p";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          				= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      	= 8;
	refShip.Weight					= Tonnes2CWT(150);
	refShip.Capacity        		= 1200;
	refShip.CannonsQuantity				= 12;
	refShip.rcannon 						= 4;
	refShip.lcannon 						= 4;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 2;
	refShip.MaxCrew         	= 75;
	refShip.MinCrew         	= 6;
	refShip.BoardingCrew				= 29;
	refShip.GunnerCrew		= 12;
	refShip.CannonerCrew		= 24;
	refShip.SailorCrew			= 70;
	refShip.SpeedRate			= 14.3;
	refShip.TurnRate        	= 51.0;
	refShip.Price           		= 19000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 3050;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2050;
}
	refShip.SP              	= 250;
	refShip.AbordageLocation	= "Boarding Deck_02";
	refship.Type.Merchant		= false;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 8.0;
	refShip.sea_enchantment		= 2.0;
	refShip.lowpolycrew 		= 10;
	refShip.buildtime 		= 40;

	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.03;

	refship.WaterLine		= 0.2;

	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 0.2;
	refship.TurnDependWeight	= 0.3;
	refship.WindAgainstSpeed   	= 7.5;//boal

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 15.0;	refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 1.0;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 8;
	refship.Track1.Width		= "1.2, 2.2";
	refship.Track1.Speed		= "7.2, 8.2";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 6;
	refship.Track2.Width		= "2.2, 3.2";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Hebek
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_HEBEK]);
	refShip.Name            			= "Hebek";
	refship.Soundtype					= "lugger";
	refShip.Class						= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight						= Tonnes2CWT(170);
	refShip.Capacity        			= 650;
	refShip.CannonsQuantity				= 12;
	refShip.rcannon 					= 4;
	refShip.lcannon 					= 4;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 79;
	refShip.MinCrew         			= 6;
	refShip.BoardingCrew				= 37;
	refShip.GunnerCrew					= 12;
	refShip.CannonerCrew				= 24;
	refShip.SailorCrew					= 60;
	refShip.SpeedRate       			= 15.0;
	refShip.TurnRate        			= 65.0;
	refShip.Price           			= 18000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3700;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2700;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 12;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 10;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.45;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= -0.5;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 12.0;//boal

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 8.0;	refship.InertiaBrakingZ		= 8.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 2.5";
	refship.Track1.Speed	= "5.2, 6.2";

	refship.Track2.ZStart	= -0.05;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Barque
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BARQUE]);
	refShip.Name            			= "Barque";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity       			= 1700;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 95;
	refShip.MinCrew         			= 8;
	refShip.BoardingCrew						= 39;
	refShip.GunnerCrew							= 16;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 70;
	refShip.SpeedRate					= 9.0;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 26000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2800;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.8;
	refShip.lowpolycrew = 10;
	refShip.buildtime = 40;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.025;

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 3.6;//boal

	refship.InertiaAccelerationX	= 1.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 7.5;
	refship.Track1.Width	= "6.0, 7.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 5.0;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Schooner
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SCHOONER]);
	refShip.Name            			= "Schooner";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 1300;
	refShip.CannonsQuantity		= 20;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         		= 112;
	refShip.MinCrew         			= 7;
	refShip.BoardingCrew				= 45;
	refShip.GunnerCrew					= 20;
	refShip.CannonerCrew				= 40;
	refShip.SailorCrew					= 70;
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 57.0;
	refShip.Price           			= 26000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3250;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2250;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 8.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 40;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.03;

	refship.WaterLine					= 0.2;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 7.5;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 8;
	refship.Track1.Width	= "1.2, 2.2";
	refship.Track1.Speed	= "7.2, 8.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6;
	refship.Track2.Width	= "2.2, 3.2";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// Xebec
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_XEBEC]);
	refShip.Name            			= "Xebec";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 600;
	refShip.CannonsQuantity			= 20;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 81;
	refShip.MinCrew         		= 9;
	refShip.BoardingCrew				= 12;
	refShip.GunnerCrew					= 20;
	refShip.CannonerCrew				= 40;
	refShip.SailorCrew					= 76;
	refShip.SpeedRate					= 15.2;
	refShip.TurnRate        			= 72.0;
	refShip.Price           			= 19600;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 2250;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 1250;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 9.0;
	refShip.sea_enchantment				= 2.0;
	refShip.lowpolycrew				= 8;
	refShip.buildtime 				= 20;

	refship.Rocking.y 				= 0.5;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine 							= 0.13;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.33;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 7.6;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Brigantine
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIGANTINE]);
	refShip.Name            			= "Brigantine";
	refship.Soundtype			= "corvette";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity        			= 1400;
	refShip.CannonsQuantity				= 16;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 101;
	refShip.MinCrew         			= 12;
	refShip.BoardingCrew						= 41;
	refShip.GunnerCrew							= 16;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 90;
	refShip.SpeedRate       			= 15.5;
	refShip.TurnRate        			= 50.0;
	refShip.Price           			= 27000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4700;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3700;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.16;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 9.1;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Brig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIG]);
	refShip.Name            			= "Brig";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(400);
	refShip.Capacity        			= 1800;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 94;
	refShip.MinCrew         			= 10;
	refShip.BoardingCrew						= 36;
	refShip.GunnerCrew							= 16;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 80;
	refShip.SpeedRate       			= 14.5;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 32000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2950;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.57;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.87;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Barkentine
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BARKENTINE]);
	refShip.Name            			= "Barkentine";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(350);
	refShip.Capacity       			= 2200;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 105;
	refShip.MinCrew         			= 12;
	refShip.BoardingCrew						= 45;
	refShip.GunnerCrew							= 16;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 90;
	refShip.SpeedRate       			= 10.4;
	refShip.TurnRate        			= 40.0;
	refShip.Price           			= 38000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4550;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3550;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.4;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 1.4;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 8.5;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Interceptor
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_INTERCEPTOR]);
	refShip.Name 			= "Interceptor";
	refship.Soundtype 			= "lugger";
	refShip.Class 			= 6;
	refShip.Cannon 			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber 			= 12;
	refShip.Weight 			= Tonnes2CWT(400);
	refShip.Capacity 			= 1900;
	refShip.CannonsQuantity 		= 18;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew 				= 110;
	refShip.MinCrew 				= 12;
	refShip.BoardingCrew 					= 44;
	refShip.GunnerCrew 							= 18;
	refShip.CannonerCrew 				= 36;
	refShip.SailorCrew 					= 100;
	refShip.SpeedRate 					= 14.5;
	refShip.TurnRate 				= 45.0;
	refShip.Price 					= 32000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP 					= 4900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3900;
}
	refShip.SP 					= 250;
	refShip.AbordageLocation 					= "Boarding Deck_02";
	refship.Type.Merchant 					= false;
	refship.Type.War					 = true;
	refShip.fWindAgainstSpeed = 4.0;
	refShip.sea_enchantment = 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.3;
	refship.WindAgainstSpeed = 3.3;//boal
	refship.CabinType = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 1.0;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 15.0; refShip.Height.Knippels.DY = 10.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 1.0;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b2.vscale = 0.8;
	refShip.GeraldSails.rey_b3.vscale = 0.8;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width = "2.0, 3.0";
	refship.Track1.Speed = "6.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width = "4.0, 6.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Fleut
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FLEUT]);
	refShip.Name            			= "Fleut";
	refship.Soundtype			= "corvette";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity		= 18;
	refShip.rcannon 							= 7;
	refShip.lcannon 							= 7;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 270;
	refShip.MinCrew         			= 13;
	refShip.BoardingCrew						= 203;
	refShip.GunnerCrew							= 18;
	refShip.CannonerCrew				= 36;
	refShip.SailorCrew					= 270;
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 50000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 9300;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 8300;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.5;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.3;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   = 4.0;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// 20 Gun Brig - Light Brig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIG_20_GUN1_18]);
	refShip.Name            			= "Brig_20_Gun1_18";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1650;
	refShip.CannonsQuantity		= 20;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 115;
	refShip.MinCrew         			= 12;
	refShip.BoardingCrew				= 43;
	refShip.GunnerCrew					= 20;
	refShip.CannonerCrew				= 40;
	refShip.SailorCrew					= 90;
	refShip.SpeedRate       			= 15.8;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 31000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4100;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3100;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.57;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.87;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Pinnace
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PINNACE]);
	refShip.Name            			= "Pinnace";
	refship.Soundtype			= "frigate";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity		= 18;
	refShip.rcannon 							= 6;
	refShip.lcannon 							= 6;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew				= 289;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew				= 218;
	refShip.GunnerCrew							= 18;
	refShip.CannonerCrew				= 36;
	refShip.SailorCrew					= 280;
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 75000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 10950;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 9950;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.3;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.62;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.82;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   = 6.0;//boal
    	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
    	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.85;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.7, 7.9";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "10.0, 12.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Galeon LIGHT
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GALEON_L]);
	refShip.Name            			= "Galeon_l";
	refship.Soundtype					= "corvette";
	refShip.Class					= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity        			= 3400;
	refShip.CannonsQuantity		= 20;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 290;
	refShip.MinCrew         			= 19;
	refShip.BoardingCrew						= 211;
	refShip.GunnerCrew							= 20;
	refShip.CannonerCrew				= 40;
	refShip.SailorCrew					= 290;
	refShip.SpeedRate					= 11.0;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 60000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 9700;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 8700;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.5;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.45;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.6;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 3.2;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// XebecLight - Light Xebec
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_XEBECLIGHT]);
	refShip.Name            			= "XebecLight";
	refship.Soundtype			= "lugger";
	refShip.Class			= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 600;
	refShip.CannonsQuantity			= 22;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 81;
	refShip.MinCrew         		= 8;
	refShip.BoardingCrew				= 13;
	refShip.GunnerCrew					= 20;
	refShip.CannonerCrew				= 40;
	refShip.SailorCrew					= 76;
	refShip.SpeedRate					= 15.2;
	refShip.TurnRate        			= 52.0;
	refShip.Price           			= 23600;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3150;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2150;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 9.0;
	refShip.sea_enchantment				= 2.0;
	refShip.lowpolycrew				= 8;
	refShip.buildtime 				= 20;

	refship.Rocking.y 				= 0.5;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine 							= 0.13;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.33;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// barque_L - Heavy Barque
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BARQUE_L]);
	refShip.Name            			= "Barque_l";
	refship.Soundtype					= "lugger";
	refShip.Class						= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight						= Tonnes2CWT(350);
	refShip.Capacity       				= 2050;
	refShip.CannonsQuantity				= 16;
	refShip.rcannon 					= 6;
	refShip.lcannon 					= 6;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 89;
	refShip.MinCrew         			= 12;
	refShip.BoardingCrew				= 29;
	refShip.GunnerCrew					= 16;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 80;
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 29000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3800;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.8;
	refShip.lowpolycrew = 10;
	refShip.buildtime = 40;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.025;

	refship.WaterLine							= -0.1;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.8;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 4.5;//boal

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4.0;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 7.5;
	refship.Track1.Width	= "6.0, 7.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 5.0;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	//// schooner_L - Gaff Schooner
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SCHOONER_L]);
	refShip.Name            			= "Schooner_l";
	refship.Soundtype					= "lugger";
	refShip.Class						= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight						= Tonnes2CWT(300);
	refShip.Capacity        			= 1100;
	refShip.CannonsQuantity				= 20;
	refShip.rcannon 					= 8;
	refShip.lcannon 					= 8;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 95;
	refShip.MinCrew         			= 12;
	refShip.BoardingCrew				= 23;
	refShip.GunnerCrew					= 20;
	refShip.CannonerCrew				= 40;
	refShip.SailorCrew					= 90;
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 55.5;
	refShip.Price           			= 24000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2900;
}
	refShip.SP              			= 250;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 9.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 40;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.03;

	refship.WaterLine					= -0.5;

	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.2;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 8.0;//boal

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;		refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 8;
	refship.Track1.Width	= "1.2, 2.2";
	refship.Track1.Speed	= "7.2, 8.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6;
	refship.Track2.Width	= "2.2, 3.2";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Castel Friedrichsburg - Brigantine Heavy
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CASTELF]);
	refShip.Name            			= "Castelf";
	refship.Soundtype					= "corvette";
	refShip.Class						= 6;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 12;
	refShip.Weight								= Tonnes2CWT(650);
	refShip.Capacity        			= 2500;
	refShip.CannonsQuantity				= 16;
	refShip.rcannon 							= 7;
	refShip.lcannon 							= 7;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 92;
	refShip.MinCrew         			= 14;
	refShip.BoardingCrew						= 30;
	refShip.GunnerCrew							= 16;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 90;
	refShip.SpeedRate       			= 15.5;
	refShip.TurnRate        			= 50.0;
	refShip.Price           			= 112000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 5400;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 4400;
}
	refShip.SP              			= 250;
	//refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.0;
	refShip.sea_enchantment					= 1.8;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 6.1;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX		= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Fleut - Derfflinger
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_DERFFLINGER]);
	refShip.Name            	= "Derfflinger";
	refship.Soundtype		= "corvette";
	refShip.Class			= 6;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      	= 16;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity        	= 3700;
	refShip.CannonsQuantity		= 16;
	refShip.rcannon 		= 8;
	refShip.lcannon 		= 8;
	refShip.fcannon 		= 0;
	refShip.bcannon 		= 0;
	refShip.MaxCrew         	= 280;
	refShip.MinCrew         	= 12;
	refShip.BoardingCrew		= 220;
	refShip.GunnerCrew		= 16;
	refShip.CannonerCrew		= 32;
	refShip.SailorCrew		= 280;
	refShip.SpeedRate		= 12.0;
	refShip.TurnRate        	= 35.0;
	refShip.Price           	= 58000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 10200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 9200;
}
	refShip.SP              	= 250;
	//refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed	= 2;
	refShip.sea_enchantment		= 1.5;
	refShip.lowpolycrew 		= 16;
	refShip.buildtime 		= 60;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.035;

	refship.WaterLine		= -0.5;
	refship.SpeedDependWeight	= 0.15;
	refship.SubSeaDependWeight	= 0.8;
	refship.TurnDependWeight	= 0.25;
	refship.WindAgainstSpeed   	= 4.0;//boal
	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           	= "Medium";

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 12;
	refship.Track1.Width		= "2.0, 3.0";
	refship.Track1.Speed		= "8.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "6.0, 8.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Dutch - Pinnace
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_DUTCHPINNACE]);
	refShip.Name            	= "DutchPinnace";
	refship.Soundtype		= "frigate";
	refShip.Class			= 6;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      	= 16;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity        	= 5200;
	refShip.CannonsQuantity		= 20;
	refShip.rcannon 		= 8;
	refShip.lcannon 		= 8;
	refShip.fcannon 		= 2;
	refShip.bcannon 		= 2;
	refShip.MaxCrew			= 318;
	refShip.MinCrew         	= 20;
	refShip.BoardingCrew		= 238;
	refShip.GunnerCrew		= 20;
	refShip.CannonerCrew		= 40;
	refShip.SailorCrew		= 200;
	refShip.SpeedRate		= 12.6;
	refShip.TurnRate        	= 31.0;
	refShip.Price           	= 95000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 11650;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 10650;
}
	refShip.SP              	= 250;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed	= 2.3;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 20;
	refShip.buildtime 		= 80;

	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.035;

	refship.WaterLine		= -0.4;
	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 1.3;
	refship.TurnDependWeight	= 0.25;
	refship.WindAgainstSpeed   	= 6.0;//boal
    	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
    	refship.DeckType           	= "Medium";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.85;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.65;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.30;
	refship.Track1.LifeTime 	= 14.5;
	refship.Track1.Width		= "5.7, 7.9";
	refship.Track1.Speed		= "6.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 8.5;
	refship.Track2.Width		= "10.0, 12.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Pinnace - Fregatte Berlin
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PINNACEBERLIN]);
	refShip.Name            	= "PinnaceBerlin";
	refship.Soundtype		= "frigate";
	refShip.Class			= 6;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      	= 16;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity        	= 2250;
	refShip.CannonsQuantity		= 20;
	refShip.rcannon 		= 8;
	refShip.lcannon 		= 8;
	refShip.fcannon 		= 2;
	refShip.bcannon 		= 2;
	refShip.MaxCrew			= 140;
	refShip.MinCrew         	= 10;
	refShip.BoardingCrew		= 60;
	refShip.GunnerCrew		= 20;
	refShip.CannonerCrew		= 40;
	refShip.SailorCrew		= 180;
	refShip.SpeedRate		= 14.5;
	refShip.TurnRate        	= 37.0;
	refShip.Price           	= 98000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 3850;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2850;
}
	refShip.SP              	= 250;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= true;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 2.3;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 28;
	refShip.buildtime 		= 80;

	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.035;

	refship.WaterLine		= -0.4;
	refship.SpeedDependWeight	= 0.2;
	refship.SubSeaDependWeight	= 1.3;
	refship.TurnDependWeight	= 0.25;
	refship.WindAgainstSpeed   	= 6.0;//boal
    	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
    	refship.DeckType           	= "Medium";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.85;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.65;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.30;
	refship.Track1.LifeTime 	= 14.5;
	refship.Track1.Width		= "5.7, 7.9";
	refship.Track1.Speed		= "6.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 8.5;
	refship.Track2.Width		= "10.0, 12.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	//// Shnyava
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SHNYAVA]);
	refShip.Name            			= "Shnyava";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1650;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 122;
	refShip.MinCrew         			= 10;
	refShip.BoardingCrew						= 46;
	refShip.GunnerCrew							= 22;
	refShip.CannonerCrew				= 44;
	refShip.SailorCrew					= 95;
	refShip.SpeedRate       			= 12.5;
	refShip.TurnRate        			= 40.0;
	refShip.Price           			= 27000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2800;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// Battle Xebec
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BATTLEXEBEC]);
	refShip.Name            			= "BattleXebec";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 800;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 				= 8;
	refShip.lcannon 				= 8;
	refShip.fcannon 				= 4;
	refShip.bcannon 				= 2;
	refShip.MaxCrew         		= 100;
	refShip.MinCrew         		= 9;
	refShip.BoardingCrew				= 25;
	refShip.GunnerCrew				= 22;
	refShip.CannonerCrew				= 44;
	refShip.SailorCrew				= 84;
	refShip.SpeedRate				= 15.5;
	refShip.TurnRate        			= 66.0;
	refShip.Price           			= 27000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 3400;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2400;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 9.0;
	refShip.sea_enchantment				= 2.0;
	refShip.lowpolycrew				= 8;
	refShip.buildtime 				= 20;

	refship.Rocking.y 				= 0.5;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine = 0.3;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 6.6;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //


	///////////////////////////////////////////////////////////////////////////
	// Hooker1 - Fast Schooner
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_HOOKER1]);
	refShip.Name            			= "Hooker1";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity        			= 1100;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 						= 9;
	refShip.lcannon 						= 9;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 2;
	refShip.MaxCrew         			= 104;
	refShip.MinCrew         			= 9;
	refShip.BoardingCrew					= 29;
	refShip.GunnerCrew				= 22;
	refShip.CannonerCrew					= 44;
	refShip.SailorCrew				= 88;
	refShip.SpeedRate       			= 16.1;
	refShip.TurnRate        			= 60.5;
	refShip.Price           			= 20500;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4050;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3050;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.7;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 8;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.9;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 10.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// ColonialSchooner - Light Colonial Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_COLONIALSCHOONER]);
	refShip.Name            			= "ColonialSchooner";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(150);
	refShip.Capacity        			= 2800;
	refShip.CannonsQuantity		= 30;
	refShip.rcannon 							= 12;
	refShip.lcannon 							= 12;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 182;
	refShip.MinCrew         			= 16;
	refShip.BoardingCrew				= 76;
	refShip.GunnerCrew					= 30;
	refShip.CannonerCrew				= 60;
	refShip.SailorCrew					= 180;
	refShip.SpeedRate       			= 13.5;
	refShip.TurnRate        			= 53.0;
	refShip.Price           			= 29000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3900;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 6.0;
	refShip.sea_enchantment					= 2.0;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 20;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.7;
	refship.SpeedDependWeight			= 0.0;
	refship.SubSeaDependWeight			= 0.2;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 10.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Schooner Xebec - Heavy Schooner
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_XEBEC_FRANCE]);
	refShip.Name            			= "SchoonerXebec";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(200);
	refShip.Capacity        			= 1800;
	refShip.CannonsQuantity		= 24;
	refShip.rcannon 							= 10;
	refShip.lcannon 							= 10;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 128;
	refShip.MinCrew         		= 12;
	refShip.BoardingCrew				= 24;
	refShip.GunnerCrew					= 34;
	refShip.CannonerCrew				= 48;
	refShip.SailorCrew					= 114;
	refShip.SpeedRate					= 15.2;
	refShip.TurnRate        			= 55.0;
	refShip.Price           			= 36600;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4300;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3300;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 6.0;
	refShip.sea_enchantment				= 2.0;
	refShip.lowpolycrew				= 8;
	refShip.buildtime 				= 20;

	refship.Rocking.y 				= 0.5;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine 							= 0.27;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.47;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 5.6;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY		= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 9;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 10.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7;
	refship.Track2.Width	= "3.0, 4.5";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Dutch Fleut
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FLEUT4_50]);
	refShip.Name            			= "Fleut4_50";
	refship.Soundtype					= "corvette";
	refShip.Class					= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity        			= 3900;
	refShip.CannonsQuantity				= 30;
	refShip.rcannon 							= 12;
	refShip.lcannon 							= 12;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 310;
	refShip.MinCrew         			= 18;
	refShip.BoardingCrew						= 202;
	refShip.GunnerCrew							= 30;
	refShip.CannonerCrew				= 60;
	refShip.SailorCrew					= 300;
	refShip.SpeedRate					= 11.9;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 75000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 10800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 9800;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.1;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.4;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.4;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   = 4.0;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Light Galleon - Whydah
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PO_FLEUT50]);
	refShip.Name            			= "PO_Fleut50";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(450);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity		= 30;
	refShip.rcannon 							= 12;
	refShip.lcannon 							= 12;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 330;
	refShip.MinCrew         			= 18;
	refShip.BoardingCrew						= 222;
	refShip.GunnerCrew							= 30;
	refShip.CannonerCrew				= 60;
	refShip.SailorCrew					= 330;
	refShip.SpeedRate					= 14.0;
	refShip.TurnRate        			= 39.0;
	refShip.Price           			= 69000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 10100;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 9100;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.2;
	refShip.sea_enchantment					= 2.1;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.3;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   = 4.0;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Brig SS - Fast Brig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIG3]);
	refShip.Name            			= "Brig3";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1600;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 							= 9;
	refShip.lcannon 							= 9;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 139;
	refShip.MinCrew         			= 34;
	refShip.BoardingCrew				= 29;
	refShip.GunnerCrew					= 32;
	refShip.CannonerCrew				= 44;
	refShip.SailorCrew					= 116;
	refShip.SpeedRate       			= 15.8;
	refShip.TurnRate        			= 47.0;
	refShip.Price           			= 29000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 5300;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 4300;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.49;
	refship.SpeedDependWeight			= 0.37;
	refship.SubSeaDependWeight			= 0.69;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// PacketBrig
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PACKET_BRIG]);
	refShip.Name            			= "Packet_Brig";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1900;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 							= 9;
	refShip.lcannon 							= 9;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 139;
	refShip.MinCrew         			= 34;
	refShip.BoardingCrew				= 19;
	refShip.GunnerCrew					= 32;
	refShip.CannonerCrew				= 44;
	refShip.SailorCrew					= 116;
	refShip.SpeedRate       			= 15.5;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 39000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3500;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.49;
	refship.SpeedDependWeight			= 0.37;
	refship.SubSeaDependWeight			= 0.69;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// ENTERPRISE - Frigate L'Enterprise
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_ENTERPRISE]);
	refShip.Name            			= "Enterprise";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1950;
	refShip.CannonsQuantity		= 24;
	refShip.rcannon 							= 10;
	refShip.lcannon 							= 10;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 122;
	refShip.MinCrew         			= 13;
	refShip.BoardingCrew						= 47;
	refShip.GunnerCrew							= 24;
	refShip.CannonerCrew				= 48;
	refShip.SailorCrew					= 112;
	refShip.SpeedRate       			= 12.5;
	refShip.TurnRate        			= 40.0;
	refShip.Price           			= 27000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4700;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3700;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 12;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Privateer
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SLOOPOFWAR]);
	refShip.Name            			= "SloopofWar";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 8;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity        			= 1650;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 						= 9;
	refShip.lcannon 						= 9;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 2;
	refShip.MaxCrew         			= 120;
	refShip.MinCrew         			= 14;
	refShip.BoardingCrew					= 40;
	refShip.GunnerCrew				= 22;
	refShip.CannonerCrew					= 44;
	refShip.SailorCrew				= 100;
	refShip.SpeedRate					= 14.3;
	refShip.TurnRate        			= 48.0;
	refShip.Price           			= 33000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4100;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3100;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed			= 4.2;
	refShip.sea_enchantment				= 1.5;
	refShip.lowpolycrew 				= 12;
	refShip.buildtime 				= 80;

	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;

	refship.WaterLine = 0.34;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.74;
	refship.TurnDependWeight = 0.8;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   = 4.8;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 18.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

///////////////////////////////////////////////////////////////////////////
	/// Sloop of war
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_NEPTUNUS]);
	refShip.Name            			= "Neptunus";
	refship.Soundtype					= "corvette";
	refShip.Class					= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight								= Tonnes2CWT(190);
	refShip.Capacity        			= 1400;
	refShip.CannonsQuantity				= 16;
	refShip.rcannon 							= 8;
	refShip.lcannon 							= 8;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 170;
	refShip.MinCrew         			= 25;
	refShip.BoardingCrew						= 110;
	refShip.GunnerCrew							= 20;
	refShip.CannonerCrew				= 32;
	refShip.SailorCrew					= 200;
	refShip.SpeedRate					= 16.5;
	refShip.TurnRate        			= 60.0;
	refShip.Price           			= 80000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 4200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3200;
}
	refShip.SP              			= 300;
	//refShip.IsSetupedGerald              		= true;
	//refShip.AbordageLocation			= "Boarding Deck_01";
	refship.CanEncounter					= true;
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.2;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;

	refship.WaterLine							= -0.6;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   = 2.8;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Merchantman - Heavy Pinnace
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PINNACE3_50]);
	refShip.Name            			= "Pinnace3_50";
	refship.Soundtype			= "frigate";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity				= 30;
	refShip.rcannon 							= 11;
	refShip.lcannon 							= 11;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 6;
	refShip.MaxCrew					= 370;
	refShip.MinCrew         			= 22;
	refShip.BoardingCrew				= 258;
	refShip.GunnerCrew				= 30;
	refShip.CannonerCrew				= 60;
	refShip.SailorCrew					= 370;
	refShip.SpeedRate					= 12.3;
	refShip.TurnRate        			= 28.0;
	refShip.Price           			= 91000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 10550;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 9500;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.1;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.99;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.82;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   = 6.0;//boal
    	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
    	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.85;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.7, 7.9";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "10.0, 12.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Caravel
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CARAVEL]);
	refShip.Name            			= "Caravel";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(500);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity		= 30;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 320;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew						= 213;
	refShip.GunnerCrew							= 30;
	refShip.CannonerCrew				= 60;
	refShip.SailorCrew					= 320;
	refShip.SpeedRate					= 10.0;
	refShip.TurnRate        			= 29;
	refShip.Price           			= 42000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 9900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 8900;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.2;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 40;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 4.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 10;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Caravel2 - Heavy Caravel
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CARAVEL2]);
	refShip.Name            			= "Caravel2";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(500);
	refShip.Capacity        			= 3800;
	refShip.CannonsQuantity		= 32;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 370;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew						= 257;
	refShip.GunnerCrew							= 32;
	refShip.CannonerCrew				= 64;
	refShip.SailorCrew					= 262;
	refShip.SpeedRate					= 10.5;
	refShip.TurnRate        			= 28;
	refShip.Price           			= 55000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 10500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 9500;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 40;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.WaterLine							= 0.11;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.61;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 4.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 10;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	//////////////////////////////////////////////////////////////////////////
	// XebecAS - Light Xebec
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_XEBECAS]);
	refShip.Name			= "XebecAS";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon  			= CANNON_TYPE_CULVERINE_LBS4;
	refShip.MaxCaliber  			= 8;
	refShip.Weight			= Tonnes2CWT(300);
	refShip.Capacity   			= 450;
	refShip.CannonsQuantity		= 26;
	refShip.rcannon 				= 11;
	refShip.lcannon 				= 11;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;
	refShip.MaxCrew        			= 125;
	refShip.MinCrew        			= 12;
	refShip.BoardingCrew		= 35;
	refShip.GunnerCrew			= 26;
	refShip.CannonerCrew		= 52;
	refShip.SailorCrew			= 122;
	refShip.SpeedRate      		= 15.5;
	refShip.TurnRate       		= 68.0;
	refShip.Price          		= 30000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP             		= 3900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 2900;
}
	refShip.SP             		= 300;
	refShip.AbordageLocation	= "Boarding Deck_02";
	refship.CabinType          = "Cabin_Small"; // boal 28.03.05
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 9.0;
	refShip.sea_enchantment		= 1.8;
	refShip.lowpolycrew			= 12;
	refShip.buildtime			= 60;

	refship.WindAgainstSpeed   = 10.0;//boal

	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;

	refship.WaterLine	= 0.60;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.90;
	refship.TurnDependWeight		= 0.3;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX	= 2.0;
	refship.InertiaAccelerationY	= 15;	refship.InertiaBrakingY	= 10;
	refship.InertiaAccelerationZ	= 9.0;	refship.InertiaBrakingZ	= 2.0;

	refShip.Height.Bombs.Y	= 1.0;			refShip.Height.Bombs.DY	= 1.0;
	refShip.Height.Grapes.Y	= 2.0;			refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 16.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY	= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Pinnace11 - Light Pinnace
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PINNACE11]);
	refShip.Name            			= "Pinnace11";
	refship.Soundtype			= "frigate";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity        			= 4500;
	refShip.CannonsQuantity		= 26;
	refShip.rcannon 							= 11;
	refShip.lcannon 							= 11;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew					= 370;
	refShip.MinCrew         			= 20;
	refShip.BoardingCrew						= 272;
	refShip.GunnerCrew							= 26;
	refShip.CannonerCrew				= 52;
	refShip.SailorCrew					= 370;
	refShip.SpeedRate					= 13.4;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 88000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 11750;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 10750;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.48;
	refship.SpeedDependWeight			= 0.2;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   = 6.0;//boal
    	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
    	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.85;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.7, 7.9";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "10.0, 12.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// Black Angel
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BLACKANGEL]);
	refShip.Name            			= "BlackAngel";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity        			= 2400;
	refShip.CannonsQuantity			= 32;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 210;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew			= 47;
	refShip.GunnerCrew					= 82;
	refShip.CannonerCrew					= 64;
	refShip.SailorCrew				= 210;
	refShip.SpeedRate				= 15.8;
	refShip.TurnRate        			= 53.0;
	refShip.Price           			= 80000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 6400;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 5400;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed			= 3.2;
	refShip.sea_enchantment				= 1.5;
	refShip.lowpolycrew 				= 16;
	refShip.buildtime 				= 80;

	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.6;
	refship.TurnDependWeight = 0.8;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   = 4.8;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 18.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Battle Corvette
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BATTLECORVETTE]);
	refShip.Name            			= "BattleCorvette";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity        			= 2500;
	refShip.CannonsQuantity			= 32;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 210;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew					= 97;
	refShip.GunnerCrew				= 32;
	refShip.CannonerCrew				= 64;
	refShip.SailorCrew					= 210;
	refShip.SpeedRate				= 15.8;
	refShip.TurnRate        			= 55.0;
	refShip.Price           			= 80000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 6800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 5800;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 3.2;
	refShip.sea_enchantment				= 1.5;
	refShip.lowpolycrew 				= 16;
	refShip.buildtime 				= 80;

	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.8;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 4.8;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 18.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Batavia2 - 22 Gun Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BATAVIA2]);
	refShip.Name            			= "Batavia2";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 1650;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 							= 9;
	refShip.lcannon 							= 9;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 160;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew						= 77;
	refShip.GunnerCrew							= 24;
	refShip.CannonerCrew				= 48;
	refShip.SailorCrew					= 157;
	refShip.SpeedRate       			= 12.5;
	refShip.TurnRate        			= 40.0;
	refShip.Price           			= 27000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 5800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 4800;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.0;
	refship.SpeedDependWeight			= 0.27;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 8;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Crimson Blood
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CRIMSONBLOOD]);
	refShip.Name            			= "CrimsonBlood";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity        			= 2900;
	refShip.CannonsQuantity		= 32;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 200;
	refShip.MinCrew         			= 19;
	refShip.BoardingCrew						= 85;
	refShip.GunnerCrew							= 32;
	refShip.CannonerCrew				= 64;
	refShip.SailorCrew					= 196;
	refShip.SpeedRate					= 14.7;
	refShip.TurnRate        			= 48.0;
	refShip.Price           			= 78000;
	if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 5500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 4500;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.2;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;

	refship.WaterLine							= 0.7;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   = 4.8;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Batavia - Heavy Batavia
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BATAVIA]);
	refShip.Name            			= "Batavia";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(850);
	refShip.Capacity        			= 3400;
	refShip.CannonsQuantity				= 32;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 197;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew						= 84;
	refShip.GunnerCrew							= 32;
	refShip.CannonerCrew				= 64;
	refShip.SailorCrew					= 190;
	refShip.SpeedRate					= 14.7;
	refShip.TurnRate        			= 45.3;
	refShip.Price           			= 72000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 5850;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 4850;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.72;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.92;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   = 4.0;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Fast Frigate - Light Corvette
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CORVFRIG2_50]);
	refShip.Name            			= "CorvFrig2_50";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 2400;
	refShip.CannonsQuantity				= 32;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 211;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew						= 98;
	refShip.GunnerCrew							= 32;
	refShip.CannonerCrew				= 64;
	refShip.SailorCrew					= 200;
	refShip.SpeedRate					= 17.0;
	refShip.TurnRate        			= 56.0;
	refShip.Price           			= 80000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 6100;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 5100;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.4;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.15;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// HMS Greyhound
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GREYHOUND]);
	refShip.Name            			= "Greyhound";
	refship.Soundtype			= "lugger";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 12;
	refShip.Weight			= Tonnes2CWT(250);
	refShip.Capacity        			= 2210;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 							= 10;
	refShip.lcannon 							= 10;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 136;
	refShip.MinCrew         			= 16;
	refShip.BoardingCrew				= 34;
	refShip.GunnerCrew					= 42;
	refShip.CannonerCrew				= 44;
	refShip.SailorCrew					= 134;
	refShip.SpeedRate       			= 14.8;
	refShip.TurnRate        			= 52.0;
	refShip.Price           			= 75000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 5800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 4800;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 3;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.04;

	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.37;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.3;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 12;	refship.InertiaBrakingY		= 9;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 2.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 15.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.8;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// FRIGATE_l - Scout Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATE_L]);
	refShip.Name            			= "Frigate_l";
	refship.Soundtype					= "frigate";
	refShip.Class					= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 16;
	refShip.Weight								= Tonnes2CWT(600);
	refShip.Capacity        			= 2500;
	refShip.Cruit	= 325;
	refShip.CannonsQuantity				= 32;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 197;
	refShip.MinCrew         			= 16;
	refShip.BoardingCrew						= 105;
	refShip.GunnerCrew							= 32;
	refShip.CannonerCrew				= 64;
	refShip.SailorCrew					= 190;
	refShip.SpeedRate					= 13.8;
	refShip.TurnRate        			= 38.5;
	refShip.Price           			= 110000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 5800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 4800;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refShip.BuntLocation			= "Bunt_Deck_1";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.2;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 80;
  	refShip.soiling = 0;
	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;
	refShip.CanEncounter	= false;
	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.7;
	refship.TurnDependWeight			= 0.3;

	refShip.Height.Bombs.Y				= 1.0;		refShip.Height.Bombs.DY		= 1.0;
	refShip.Height.Grapes.Y				= 3.0;		refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 18.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y				= 1.0;		refShip.Height.Balls.DY		= 1.0;

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Galeon - Apostól Felipe
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FELIPE]);
	refShip.Name            		= "Felipe";
	refship.Soundtype				= "frigate";
	refShip.Class			= 5;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      	= 20;
	refShip.Weight						= Tonnes2CWT(1100);
	refShip.Capacity        			= 4950;
	refShip.CannonsQuantity		= 30;
	refShip.rcannon 						= 14;
	refShip.lcannon 						= 14;
	refShip.fcannon 						= 0;
	refShip.bcannon 						= 2;
	refShip.MaxCrew         	= 370;
	refShip.MinCrew         	= 17;
	refShip.BoardingCrew			= 263;
	refShip.GunnerCrew				= 30;
	refShip.CannonerCrew			= 60;
	refShip.SailorCrew			= 370;
	refShip.SpeedRate		= 11.4;
	refShip.TurnRate        		= 25.0;
	refShip.Price           	= 125000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 10800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 9800;
}
	refShip.SP              	= 300;
	refShip.AbordageLocation		= "Boarding Deck_01";
	refship.Type.Merchant		= true;
	refship.Type.War		= false;
	refShip.fWindAgainstSpeed		= 1.9;
	refShip.sea_enchantment		= 1.2;
	refShip.lowpolycrew 		= 20;
	refShip.buildtime 		= 80;


	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.02;

	refship.WaterLine		= 0.0;

	refship.SpeedDependWeight	= 0.15;
	refship.SubSeaDependWeight	= 0.3;
	refship.TurnDependWeight	= 0.2;
	refship.WindAgainstSpeed   	= 2.6;//boal
	refship.CabinType          	= "Cabin"; // boal 28.03.05
	refship.DeckType           	= "Big";

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.98;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.0;
	refship.Track1.LifeTime 	= 14.5;
	refship.Track1.Width		= "5.2, 7.3";
	refship.Track1.Speed		= "5.5, 6.5";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 8.5;
	refship.Track2.Width		= "6.0, 8.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// 28GUNFRIGATE - 28 Gun Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_28GUNFRIGATE]);
	refShip.Name            			= "28GunFrigate";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity				= 28;
	refShip.rcannon 							= 14;
	refShip.lcannon 							= 14;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 180;
	refShip.MinCrew         			= 18;
	refShip.BoardingCrew						= 78;
	refShip.GunnerCrew							= 28;
	refShip.CannonerCrew				= 56;
	refShip.SailorCrew					= 170;
	refShip.SpeedRate					= 14.8;
	refShip.TurnRate        			= 46.0;
	refShip.Price           			= 110000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 6500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 5500;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Frigate Surprise
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SURPRISE]);
	refShip.Name            			= "Surprise";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity				= 30;
	refShip.rcannon 							= 14;
	refShip.lcannon 							= 14;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 280;
	refShip.MinCrew         			= 18;
	refShip.BoardingCrew						= 136;
	refShip.GunnerCrew							= 42;
	refShip.CannonerCrew				= 84;
	refShip.SailorCrew					= 270;
	refShip.SpeedRate					= 14.8;
	refShip.TurnRate        			= 46.0;
	refShip.Price           			= 110000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP              			= 6500;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //


	///////////////////////////////////////////////////////////////////////////
	/// 32GunFrigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_32GunFrigate]);
	refShip.Name            			= "32GunFrigate";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3300;
	refShip.CannonsQuantity				= 32;
	refShip.rcannon 							= 15;
	refShip.lcannon 							= 15;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 230;
	refShip.MinCrew         			= 18;
	refShip.BoardingCrew						= 116;
	refShip.GunnerCrew							= 32;
	refShip.CannonerCrew				= 64;
	refShip.SailorCrew					= 230;
	refShip.SpeedRate					= 14.5;
	refShip.TurnRate        			= 46.0;
	refShip.Price           			= 115000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7000;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6000;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// RaaFrigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_RaaFrigate]);
	refShip.Name            			= "RaaFrigate";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3200;
	refShip.CannonsQuantity				= 32;
	refShip.rcannon 							= 15;
	refShip.lcannon 							= 15;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 205;
	refShip.MinCrew         			= 18;
	refShip.BoardingCrew						= 91;
	refShip.GunnerCrew							= 32;
	refShip.CannonerCrew				= 64;
	refShip.SailorCrew					= 70;
	refShip.SpeedRate					= 14.9;
	refShip.TurnRate        			= 46.0;
	refShip.Price           			= 113000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 6500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 5500;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.3;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Corvette5 - Heavy Corvette
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CORVETTE5]);
	refShip.Name            			= "Corvette5";
	refship.Soundtype			= "corvette";
	refShip.Class			= 5;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity        			= 2250;
	refShip.CannonsQuantity		= 32;
	refShip.rcannon 							= 13;
	refShip.lcannon 							= 13;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 230;
	refShip.MinCrew         			= 16;
	refShip.BoardingCrew						= 118;
	refShip.GunnerCrew							= 34;
	refShip.CannonerCrew				= 68;
	refShip.SailorCrew					= 230;
	refShip.SpeedRate					= 16.7;
	refShip.TurnRate        			= 55.0;
	refShip.Price           			= 88000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7750;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6750;
}
	refShip.SP              			= 300;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.2;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;

	refship.WaterLine							= 0.08;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.38;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   = 4.8;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Fleut of War
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FLEUT2]);
	refShip.Name            			= "FleutOfWar";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity		= 34;
	refShip.rcannon 							= 15;
	refShip.lcannon 							= 15;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 400;
	refShip.MinCrew         			= 18;
	refShip.BoardingCrew						= 260;
	refShip.GunnerCrew							= 34;
	refShip.CannonerCrew				= 68;
	refShip.SailorCrew					= 400;
	refShip.SpeedRate					= 11.0;
	refShip.TurnRate        			= 22.0;
	refShip.Price           			= 62000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 12200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 11200;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.7;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= 0.0;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.6;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 2.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Corvette
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CORVETTE]);
	refShip.Name            			= "Corvette";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(600);
	refShip.Capacity        			= 2500;
	refShip.CannonsQuantity		= 34;
	refShip.rcannon 							= 14;
	refShip.lcannon 							= 14;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 250;
	refShip.MinCrew         			= 20;
	refShip.BoardingCrew						= 128;
	refShip.GunnerCrew							= 34;
	refShip.CannonerCrew				= 68;
	refShip.SailorCrew					= 250;
	refShip.SpeedRate					= 16.7;
	refShip.TurnRate        			= 55.0;
	refShip.Price           			= 88000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7750;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6750;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.2;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;

	refship.WaterLine							= 0.08;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.38;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   = 4.8;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Galeon_h21 - Spanish Heavy Galleon
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GALEON_H21]);
	refShip.Name            			= "Galeon_h21";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(500);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity		= 36;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 390;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew						= 265;
	refShip.GunnerCrew							= 36;
	refShip.CannonerCrew				= 72;
	refShip.SailorCrew					= 380;
	refShip.SpeedRate					= 9.0;
	refShip.TurnRate        			= 24;
	refShip.Price           			= 42000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 11900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 10900;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2.2;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 26;
	refShip.buildtime = 40;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 4.0;//boal

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 10;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Battle Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BATTLEFRIGATE]);
	refShip.Name            			= "BattleFrigate";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 2800;
	refShip.CannonsQuantity				= 42;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 300;
	refShip.MinCrew         			= 17;
	refShip.BoardingCrew						= 157;
	refShip.GunnerCrew							= 42;
	refShip.CannonerCrew				= 84;
	refShip.SailorCrew					= 290;
	refShip.SpeedRate					= 13.8;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 110000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6500;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.3;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Pinnace of War
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_PINNACE2]);
	refShip.Name            			= "Pinnaceofwar";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity				= 40;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 6;
	refShip.MaxCrew         			= 480;
	refShip.MinCrew         			= 18;
	refShip.BoardingCrew						= 342;
	refShip.GunnerCrew							= 40;
	refShip.CannonerCrew				= 80;
	refShip.SailorCrew					= 470;
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 22.0;
	refShip.Price           			= 93000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 12200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 11200;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.8;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= 0.99;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.9;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 2.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// TheBlackPearl - Wicked Wench
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_THEBLACKPEARL]);
	refShip.Name            			= "TheBlackPearl";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3200;
	refShip.CannonsQuantity		= 36;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 270;
	refShip.MinCrew         		= 16;
	refShip.BoardingCrew					= 136;
	refShip.GunnerCrew			= 30;
	refShip.CannonerCrew			= 72;
	refShip.SailorCrew				= 260;
	refShip.SpeedRate       			= 15.6;
	refShip.TurnRate        			= 42.0;
	refShip.Price           				= 65000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              				= 7200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6200;
}
	refShip.SP              				= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant				= true;
	refship.Type.War				= false;
	refShip.fWindAgainstSpeed			= 2.3;
	refShip.sea_enchantment				= 1.2;
	refShip.lowpolycrew 				= 20;
	refShip.buildtime 				= 100;


	refship.Rocking.y 				= 0.4;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine				= 0.5;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 3.6;//boal
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b1			= 1;
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.20;
	refship.Track1.LifeTime 			= 14.5;
	refship.Track1.Width				= "3.7, 3.9";
	refship.Track1.Speed				= "7.0, 8.0";

	refship.Track2.ZStart				= -0.15;
	refship.Track2.LifeTime 			= 8.5;
	refship.Track2.Width				= "8.0, 9.0";
	refship.Track2.Speed				= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// BlackPearl
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BLACKPEARL]);
	refShip.Name            			= "BlackPearl";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 4500;
	refShip.CannonsQuantity		= 36;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 290;
	refShip.MinCrew         			= 16;
	refShip.BoardingCrew					= 166;
	refShip.GunnerCrew				= 36;
	refShip.CannonerCrew					= 72;
	refShip.SailorCrew							= 280;
	refShip.SpeedRate       			= 16.9;
	refShip.TurnRate        			= 58.0;
	refShip.Price           			= 70000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6800;
}
	refShip.SP              			= 350;
	refship.EmblemedSails.normalTex = "ships\sail_BlackPearl.tga.tx";
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.CanEncounter				= false;
	refship.Type.Merchant				= true;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 5.0;
	refShip.sea_enchantment				= 1.2;
	refShip.lowpolycrew 				= 20;
	refShip.buildtime 				= 100;


	refship.Rocking.y 				= 0.4;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine				= 0.5;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 3.6;//boal
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b1			= 1;
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.20;
	refship.Track1.LifeTime 			= 14.5;
	refship.Track1.Width				= "3.7, 3.9";
	refship.Track1.Speed				= "7.0, 8.0";

	refship.Track2.ZStart				= -0.15;
	refship.Track2.LifeTime 			= 8.5;
	refship.Track2.Width				= "8.0, 9.0";
	refship.Track2.Speed				= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// QueenAnnesRevenge
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_QueenAnnesRevenge]);
	refShip.Name            			= "QueenAnnesRevenge";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 4500;
	refShip.CannonsQuantity		= 44;
	refShip.rcannon 							= 20;
	refShip.lcannon 							= 20;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 270;
	refShip.MinCrew         			= 16;
	refShip.BoardingCrew					= 122;
	refShip.GunnerCrew				= 44;
	refShip.CannonerCrew					= 88;
	refShip.SailorCrew							= 260;
	refShip.SpeedRate       			= 16.9;
	refShip.TurnRate        			= 58.0;
	refShip.Price           			= 70000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6800;
}
	refShip.SP              			= 350;
	refship.EmblemedSails.normalTex = "ships\sail_QueenAnnesRevenge.tga.tx";
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.CanEncounter				= true;
	refship.Type.Merchant				= true;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 5.0;
	refShip.sea_enchantment				= 1.2;
	refShip.lowpolycrew 				= 20;
	refShip.buildtime 				= 100;


	refship.Rocking.y 				= 0.4;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine				= 0.5;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   			= 3.6;//boal
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b1			= 1;
	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.20;
	refship.Track1.LifeTime 			= 14.5;
	refship.Track1.Width				= "3.7, 3.9";
	refship.Track1.Speed				= "7.0, 8.0";

	refship.Track2.ZStart				= -0.15;
	refship.Track2.LifeTime 			= 8.5;
	refship.Track2.Width				= "8.0, 9.0";
	refship.Track2.Speed				= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Revenge
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_REVENGE]);
	refShip.Name            			= "Revenge";
	refship.Soundtype				= "frigate";
	refShip.Class					= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight					= Tonnes2CWT(1100);
	refShip.Capacity        			= 5200;
	refShip.CannonsQuantity				= 40;
	refShip.rcannon 				= 19;
	refShip.lcannon 				= 19;
	refShip.fcannon 				= 0;
	refShip.bcannon 				= 2;

	refShip.MaxCrew         			= 240;
	refShip.MinCrew         			= 16;
	refShip.BoardingCrew				= 104;
	refShip.GunnerCrew				= 40;
	refShip.CannonerCrew				= 80;
	refShip.SailorCrew				= 230;

	refShip.SpeedRate				= 8.0;
	refShip.TurnRate        			= 25.0;

	refShip.Price           			= 105000;

		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 6800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 5800;
}
	refShip.SP              			= 350;

	refship.CabinType                               = "Cabin_Small"; // boal 28.03.05
	refship.DeckType                                = "Low";
	refship.CabinType          			= "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           			= "Medium";
	refship.CabinType          	                = "Cabin"; // boal 28.03.05
    	refship.DeckType           	                = "Big";
	refShip.AbordageLocation			= "BOARDING_SMALL_DECK";
	refShip.AbordageLocation	                = "Boarding Deck_01";
	refShip.AbordageLocation			= "Boarding Deck_02";

	refship.Type.Merchant				= true;
	refship.Type.War				= true;

	refShip.fWindAgainstSpeed			= 2.0;
	refShip.sea_enchantment				= 1.2;
	refShip.lowpolycrew                             = 20;
	refShip.buildtime                               = 80;


	refship.Rocking.y                               = 0.4;
	refship.Rocking.az                              = 0.02;

	refship.WaterLine				= 0.0;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed                        = 2.6;//boal

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	/// 30 Gun Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_30GunFrigate]);
	refShip.Name            			= "30GunFrigate";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity				= 42;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 280;
	refShip.MinCrew         			= 18;
	refShip.BoardingCrew						= 136;
	refShip.GunnerCrew							= 42;
	refShip.CannonerCrew				= 84;
	refShip.SailorCrew					= 270;
	refShip.SpeedRate					= 14.8;
	refShip.TurnRate        			= 46.0;
	refShip.Price           			= 110000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6500;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.2;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.8;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

        refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Jamaicaship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_JAMAICASHIP]);
	refShip.Name            			= "JamaicaShip";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 3200;
	refShip.CannonsQuantity		= 36;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         				= 280;
	refShip.MinCrew         				= 38;
	refShip.BoardingCrew				= 151;
	refShip.GunnerCrew				= 36;
	refShip.CannonerCrew				= 72;
	refShip.SailorCrew				= 146;
	refShip.SpeedRate       				= 13.5;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 143000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7100;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6100;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.6;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= -0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// Nightmare
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_NIGHTMARE]);
	refShip.Name            			= "Nightmare";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3300;
	refShip.CannonsQuantity		= 38;
	refShip.rcannon 							= 18; //might be 14
	refShip.lcannon 							= 18; // might be 14
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 340;
	refShip.MinCrew         			= 21;
	refShip.BoardingCrew				= 187;
	refShip.GunnerCrew				= 44;
	refShip.CannonerCrew				= 88;
	refShip.SailorCrew				= 330;
	refShip.SpeedRate       			= 13.2;
	refShip.TurnRate        			= 41.0;
	refShip.Price           			= 140000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 6800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 5800;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 2.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// ColonialFrigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_COLONIALFRIGATE]);
	refShip.Name            			= "ColonialFrigate";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3100;
	refShip.CannonsQuantity		= 42;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 340;
	refShip.MinCrew         		= 22;
	refShip.BoardingCrew				= 192;
	refShip.GunnerCrew			= 42;
	refShip.CannonerCrew				= 84;
	refShip.SailorCrew				= 334;
	refShip.SpeedRate       			= 14.3;
	refShip.TurnRate        			= 48.0;
	refShip.Price           			= 147000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7300;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6300;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed			= 3.0;
	refShip.sea_enchantment				= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine				= 0.5;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Boussole
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BOUSSOLE]);
	refShip.Name 				= "Boussole";
	refship.Soundtype 				= "frigate";
	refShip.Class 				= 4;
	refShip.Cannon 			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber 			= 16;
	refShip.Weight 								= Tonnes2CWT(1000);
	refShip.Capacity 			= 3300;
	refShip.CannonsQuantity 		= 42;
	refShip.rcannon 					= 19;
	refShip.lcannon 					= 19;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew 			= 310;
	refShip.MinCrew 			= 20;
	refShip.BoardingCrew 					= 164;
	refShip.GunnerCrew 			= 42;
	refShip.CannonerCrew 					= 84;
	refShip.SailorCrew 			= 310;
	refShip.SpeedRate 				= 14.8;
	refShip.TurnRate 			= 46.0;
	refShip.Price 				= 145000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP 				= 7500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6500;
}
	refShip.SP  				= 350;
	refShip.AbordageLocation 	= "Boarding Deck_01";
	refship.Type.Merchant 				= false;
	refship.Type.War 					= true;
	refShip.fWindAgainstSpeed 	= 3.3;
	refShip.sea_enchantment 	= 1.2;
	refShip.lowpolycrew 		= 20;
	refShip.buildtime 		= 100;

	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.035;
	refship.WaterLine 		= 0.50;

	refship.SpeedDependWeight 	= 0.3;
	refship.SubSeaDependWeight 	= 1.0;
	refship.TurnDependWeight 	= 0.8;
	refship.WindAgainstSpeed 	= 4.5;//boal
	refship.CabinType 		= "Cabin"; // boal 28.03.05
	refship.DeckType 		= "Big";

	refship.InertiaAccelerationX = 5.0; refship.InertiaBrakingX = 5.0;
	refship.InertiaAccelerationY = 4; refship.InertiaBrakingY = 4;
	refship.InertiaAccelerationZ = 5.0; refship.InertiaBrakingZ = 5.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width = "3.7, 3.9";
	refship.Track1.Speed = "7.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width = "8.0, 9.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// LIGHT FRIGATE
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LIGHTFRIGATE]);
	refShip.Name            			= "LightFrigate";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity		= 40;
	refShip.rcannon 							= 17;
	refShip.lcannon 							= 17;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 320;
	refShip.MinCrew         		= 21;
	refShip.BoardingCrew					= 179;
	refShip.GunnerCrew				= 40;
	refShip.CannonerCrew				= 80;
	refShip.SailorCrew					= 310;
	refShip.SpeedRate				= 14.9;
	refShip.TurnRate        			= 46.0;
	refShip.Price           			= 148000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7300;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6300;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.3;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.69;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.87;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.9;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Galeon HEAVY - Heavy Galleon
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GALEON_H]);
	refShip.Name            			= "Galeon_h";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 24;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 4700;
	refShip.CannonsQuantity		= 38;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 460;
	refShip.MinCrew         			= 26;
	refShip.BoardingCrew						= 320;
	refShip.GunnerCrew							= 38;
	refShip.CannonerCrew				= 76;
	refShip.SailorCrew					= 450;
	refShip.SpeedRate					= 10.0;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 105000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 13300;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 12300;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.5;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= -0.7;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 2.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Fast Galleon - Golden Hind
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FASTGALLEON1]);
	refShip.Name            			= "FastGalleon1";
	refship.Soundtype					= "corvette";
	refShip.Class					= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 24;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity        			= 6600;
	refShip.CannonsQuantity		= 40;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 6;
	refShip.MaxCrew         			= 460;
	refShip.MinCrew         			= 25;
	refShip.BoardingCrew						= 315;
	refShip.GunnerCrew							= 40;
	refShip.CannonerCrew				= 80;
	refShip.SailorCrew					= 450;
	refShip.SpeedRate					= 11.1;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 111000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 13400;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 12400;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 1.6;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 60;

	refship.Rocking.y = 0.45;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= -0.7;
	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 3.2;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// Mermaid Grief
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MERMAIDGRIEF]);
	refShip.Name            			= "MermaidGrief";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 3500;
	refShip.CannonsQuantity		= 44;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 330;
	refShip.MinCrew         			= 22;
	refShip.BoardingCrew						= 176;
	refShip.GunnerCrew				= 44;
	refShip.CannonerCrew						= 88;
	refShip.SailorCrew				= 320;
	refShip.SpeedRate       				= 13.6;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 159000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 6800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 5800;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 2.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.60;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Frigate Sat - Chase Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATE_SAT]);
	refShip.Name            			= "Frigate_sat";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3000;
	refShip.CannonsQuantity		= 44;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 330;
	refShip.MinCrew         		= 20;
	refShip.BoardingCrew					= 178;
	refShip.GunnerCrew				= 44;
	refShip.CannonerCrew				= 88;
	refShip.SailorCrew					= 320;
	refShip.SpeedRate       			= 14.0;
	refShip.TurnRate        			= 48.0;
	refShip.Price           			= 155000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7000;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6000;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 3.3;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.9;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.2;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FRIGATE]);
	refShip.Name            			= "Frigate";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3300;
	refShip.CannonsQuantity		= 46;
	refShip.rcannon 							= 20;
	refShip.lcannon 							= 20;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 353;
	refShip.MinCrew         			= 22;
	refShip.BoardingCrew						= 193;
	refShip.GunnerCrew							= 46;
	refShip.CannonerCrew				= 92;
	refShip.SailorCrew					= 342;
	refShip.SpeedRate       			= 14.7;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 161000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 8400;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 7400;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.50;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// Salamander
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SALAMANDER]);
	refShip.Name            			= "Salamander";
	refship.Soundtype					= "frigate";
	refShip.Class					= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 16;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3300;
	refShip.CannonsQuantity		= 44;
	refShip.rcannon 							= 19;
	refShip.lcannon 							= 19;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 317;
	refShip.MinCrew         		= 20;
	refShip.BoardingCrew						= 165;
	refShip.GunnerCrew				= 44;
	refShip.CannonerCrew				= 88;
	refShip.SailorCrew					= 300;
	refShip.SpeedRate       			= 14.0;
	refShip.TurnRate        			= 38.5;
	refShip.Price           			= 156000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7700;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6700;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 2.8;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.1;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y			= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y			= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y		= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y			= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// 34 Gun Fleut of War - Heavy Fleut
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FLEUTOFWAR34G]);
	refShip.Name            			= "FleutOfWar34G";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 24;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 5500;
	refShip.CannonsQuantity				= 34;
	refShip.rcannon 							= 15;
	refShip.lcannon 							= 15;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 440;
	refShip.MinCrew         			= 25;
	refShip.BoardingCrew						= 313;
	refShip.GunnerCrew							= 34;
	refShip.CannonerCrew				= 68;
	refShip.SailorCrew					= 430;
	refShip.SpeedRate					= 11.3;
	refShip.TurnRate        			= 23.5;
	refShip.Price           			= 106000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 13600;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 12600;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= 0.3;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.9;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 2.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 1.0;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Galeon1 - Carrack
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GALEON1]);
	refShip.Name            			= "Galeon1";
	refship.Soundtype			= "corvette";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 24;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 6850;
	refShip.CannonsQuantity		= 38;
	refShip.rcannon 							= 16;
	refShip.lcannon 							= 16;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 480;
	refShip.MinCrew         			= 27;
	refShip.BoardingCrew						= 339;
	refShip.GunnerCrew							= 38;
	refShip.CannonerCrew				= 76;
	refShip.SailorCrew					= 470;
	refShip.SpeedRate					= 10.0;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 124000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 13800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 12800;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= 0.2;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 2.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Sirius1 - Sirius
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SIRIUS1]);
	refShip.Name            			= "Sirius1";
	refship.Soundtype			= "frigate";
	refShip.Class			= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3750;
	refShip.CannonsQuantity		= 48;
	refShip.rcannon 							= 21;
	refShip.lcannon 							= 21;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 353;
	refShip.MinCrew         			= 22;
	refShip.BoardingCrew						= 187;
	refShip.GunnerCrew							= 48;
	refShip.CannonerCrew				= 96;
	refShip.SailorCrew					= 342;
	refShip.SpeedRate       			= 12.1;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 182000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7400;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6400;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.60;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	///  Unicorn - Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_UNICORN]);
	refShip.Name            			= "Unicorn";
	refship.Soundtype						= "frigate";
	refShip.Class				= 4;
	refShip.Cannon          					= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight									= Tonnes2CWT(1000);
	refShip.Capacity        		= 3000;
	refShip.CannonsQuantity		= 36;
	refShip.rcannon 									= 18;
	refShip.lcannon 									= 18;
	refShip.fcannon 									= 0;
	refShip.bcannon 									= 0;
	refShip.MaxCrew         		= 280;
	refShip.MinCrew         			= 15;
	refShip.BoardingCrew			= 151;
	refShip.GunnerCrew					= 38;
	refShip.CannonerCrew				= 76;
	refShip.SailorCrew			= 270;
	refShip.SpeedRate       				= 13.9;
	refShip.TurnRate        			= 37.0;
	refShip.Price           		= 230000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 8400;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 7400;
}
	refShip.SP              	= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant			= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 2.0;
	refShip.sea_enchantment		= 1.2;
	refShip.lowpolycrew 		= 20;
	refShip.buildtime 		= 220;


	refship.Rocking.y 		= 0.4;
	refship.Rocking.az 		= 0.035;

	refship.WaterLine		= -0.35;

	refship.SpeedDependWeight	= 0.3;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.3;
	refship.WindAgainstSpeed  	= 3.6;//boal
	refship.CabinType          	= "Cabin"; // boal 28.03.05
	refship.DeckType           	= "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y		= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y		= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y		= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.9;
	refShip.GeraldSails.rey_b2.vscale	= 0.7;
	refShip.GeraldSails.rey_b3.vscale	= 0.7;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.20;
	refship.Track1.LifeTime 	= 14.5;
	refship.Track1.Width		= "3.7, 3.9";
	refship.Track1.Speed		= "7.0, 8.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 8.5;
	refship.Track2.Width		= "8.0, 9.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Linefrigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LINEFRIGATE]);
	refShip.Name            			= "Linefrigate";
	refship.Soundtype					= "frigate";
	refShip.Class						= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 24;
	refShip.Weight						= Tonnes2CWT(1700);
	refShip.Capacity        			= 3200;
	refShip.CannonsQuantity				= 40;
	refShip.rcannon 					= 17;
	refShip.lcannon 					= 17;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         			= 340;
	refShip.MinCrew         			= 22;
	refShip.BoardingCrew				= 198;
	refShip.GunnerCrew					= 40;
	refShip.CannonerCrew				= 80;
	refShip.SailorCrew					= 330;
	refShip.SpeedRate       			= 13.5;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 380000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 8000;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 7000;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.86;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Heavy-Merchant VCO
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MERCHANT1]);
	refShip.Name            			= "Merchant1";
	refship.Soundtype					= "lineship";
	refShip.Class					= 4;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 24;
	refShip.Weight								= Tonnes2CWT(2500);
	refShip.Capacity        			= 5800;
	refShip.CannonsQuantity				= 40;
	refShip.rcannon 							= 18;
	refShip.lcannon 							= 18;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         				= 440;
	refShip.MinCrew         				= 30;
	refShip.BoardingCrew				= 290;
	refShip.GunnerCrew				= 40;
	refShip.CannonerCrew				= 80;
	refShip.SailorCrew				= 430;
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 43;
	refShip.Price           			= 191100;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 14000;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 13000;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= false;
	refShip.fWindAgainstSpeed				= 2;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 40;
    	refship.CabinType          	= "Cabin_Medium"; // boal 28.03.05
    	refship.DeckType           	= "Medium";

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;


	refship.WaterLine							= 0.8;
	refship.SpeedDependWeight			= 0.5;
	refship.SubSeaDependWeight			= 0.6;
	refship.TurnDependWeight			= 0.5;

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 10;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "7.2, 9.2";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_a1		= 1;
	refShip.GeraldSails.rey_a1.vscale		= 0.85;
	refShip.GeraldSails.rey_b2.vscale		= 0.85;
	refShip.GeraldSails.rey_b3.vscale		= 0.85;

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// HMS LYDIA
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LYDIA]);
	refShip.Name            			= "Lydia";
	refship.Soundtype			= "frigate";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 3200;
	refShip.CannonsQuantity		= 50;
	refShip.rcannon 							= 21;
	refShip.lcannon 							= 21;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         				= 370;
	refShip.MinCrew         				= 20;
	refShip.BoardingCrew				= 184;
	refShip.GunnerCrew				= 50;
	refShip.CannonerCrew				= 100;
	refShip.SailorCrew				= 170;
	refShip.SpeedRate       				= 13.9;
	refShip.TurnRate        			= 49.0;
	refShip.Price           			= 140000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 6500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 5500;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.5;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= -1.2;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= -0.4;
	refship.TurnDependWeight			= 0.3;

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// West Indiaman
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_INDIAMAN]);
	refShip.Name            			= "Indiaman";
	refship.Soundtype			= "Corvette";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 28;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 6800;
	refShip.CannonsQuantity				= 50;
	refShip.rcannon 							= 22;
	refShip.lcannon 							= 22;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 514;
	refShip.MinCrew         			= 27;
	refShip.BoardingCrew					= 337;
	refShip.GunnerCrew				= 50;
	refShip.CannonerCrew					= 100;
	refShip.SailorCrew				= 500;
	refShip.SpeedRate       				= 12.2;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 190000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 15800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 14800;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= true;
	refship.Type.War					= false;
	refShip.fWindAgainstSpeed				= 1.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.13;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.43;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// 'Fearless'
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FEARLESS]);
	refShip.Name            			= "Fearless";
	refship.Soundtype			= "frigate";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3500;
	refShip.CannonsQuantity		= 56;
	refShip.rcannon 							= 25;
	refShip.lcannon 							= 25;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 389;
	refShip.MinCrew         			= 22;
	refShip.BoardingCrew						= 199;
	refShip.GunnerCrew				= 44;
	refShip.CannonerCrew						= 56;
	refShip.SailorCrew				= 372;
	refShip.SpeedRate       				= 14.3;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 153000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6900;
}
	refShip.SP              			= 350;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.8;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.43;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.79;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Lineship47 - 3rd Rate Lineship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LINESHIP47]);
	refShip.Name            			= "Lineship47";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 28;
	refShip.Weight			= Tonnes2CWT(2100);
	refShip.Capacity        			= 5500;
	refShip.CannonsQuantity		= 60;
	refShip.rcannon 							= 29;
	refShip.lcannon 							= 29;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 430;
	refShip.MinCrew         			= 26;
	refShip.BoardingCrew						= 224;
	refShip.GunnerCrew				= 60;
	refShip.CannonerCrew						= 120;
	refShip.SailorCrew				= 425;
	refShip.SpeedRate       				= 12.0;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 200000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 9200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 8200;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.3;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 4.0;

	refShip.Height.Bombs.Y = 1.0; 		refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; 		refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; 	refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; 		refShip.Height.Balls.DY = 0.5;
;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// War Galleon - Spanish Battle Gallion
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_GALEON]);
	refShip.Name            			= "GaleonW";
	refship.Soundtype			= "corvette";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 28;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 6000;
	refShip.CannonsQuantity				= 56;
	refShip.rcannon 							= 26;
	refShip.lcannon 							= 26;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 460;
	refShip.MinCrew         			= 26;
	refShip.BoardingCrew						= 266;
	refShip.GunnerCrew							= 56;
	refShip.CannonerCrew				= 112;
	refShip.SailorCrew					= 450;
	refShip.SpeedRate					= 8.2;
	refShip.TurnRate        			= 20.0;
	refShip.Price           			= 280000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 14200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 13200;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.3;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 80;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= -0.45;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.1;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 2.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4;	refship.InertiaBrakingX		= 2.5;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// Amsterdam
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_AMSTERDAM]);
	refShip.Name            			= "Amsterdam";
	refship.Soundtype			= "corvette";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 3600;
	refShip.CannonsQuantity				= 50;
	refShip.rcannon 							= 22;
	refShip.lcannon 							= 22;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 470;
	refShip.MinCrew         			= 24;
	refShip.BoardingCrew					= 196;
	refShip.GunnerCrew				= 50;
	refShip.CannonerCrew					= 100;
	refShip.SailorCrew				= 460;
	refShip.SpeedRate       				= 13.2;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 144000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 8800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 7800;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 2.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.13;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.43;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// HMS Mordaunt
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MORDAUNT]);
	refShip.Name 				= "Mordaunt";
	refship.Soundtype 				= "frigate";
	refShip.Class 				= 3;
	refShip.Cannon 				= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber 				= 20;
	refShip.Weight 				= Tonnes2CWT(2500);
	refShip.Capacity 				= 3700;
	refShip.CannonsQuantity 			= 58;
	refShip.rcannon 							= 26;
	refShip.lcannon 							= 26;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew 				= 410;
	refShip.MinCrew 				= 24;
	refShip.BoardingCrew 					= 212;
	refShip.GunnerCrew 				= 58;
	refShip.CannonerCrew 				= 116;
	refShip.SailorCrew 					= 408;
	refShip.SpeedRate 					= 13.2;
	refShip.TurnRate 				= 36.0;
	refShip.Price 					= 164000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP 					= 8300;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 7300;
}
	refShip.SP 					= 400;
	refShip.AbordageLocation = "Boarding Deck_01";
	refship.Type.Merchant 			= false;
	refship.Type.War 		        = true;
	refShip.fWindAgainstSpeed = 2.5;
	refShip.sea_enchantment = 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;
	refship.WaterLine = 0.0;

	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.30;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed = 4.5;//boal
	refship.CabinType = "Cabin"; // boal 28.03.05
	refship.DeckType = "Big";

	refship.InertiaAccelerationX = 5.0; refship.InertiaBrakingX = 5.0;
	refship.InertiaAccelerationY = 4; refship.InertiaBrakingY = 4;
	refship.InertiaAccelerationZ = 5.0; refship.InertiaBrakingZ = 5.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width = "3.7, 3.9";
	refship.Track1.Speed = "7.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width = "8.0, 9.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// War Pinnace
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_WAR_PINNACE]);
	refShip.Name            			= "War_Pinnace";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS8;
	refShip.MaxCaliber      			= 28;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity        			= 6700;
	refShip.CannonsQuantity		= 54;
	refShip.rcannon 							= 23;
	refShip.lcannon 							= 23;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 6;
	refShip.MaxCrew         			= 440;
	refShip.MinCrew         			= 28;
	refShip.BoardingCrew						= 250;
	refShip.GunnerCrew							= 54;
	refShip.CannonerCrew				= 108;
	refShip.SailorCrew					= 430;
	refShip.SpeedRate					= 12.1;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 130000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 15900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 14900;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.5;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= 1.1;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 1.7;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 2.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Dutch Two-decker
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_TWODECKER1_47]);
	refShip.Name            			= "TwoDecker1_47";
	refship.Soundtype			= "linship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(550);
	refShip.Capacity        			= 3900;
	refShip.CannonsQuantity		= 54;
	refShip.rcannon 							= 23;
	refShip.lcannon 							= 23;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 6;
	refShip.MaxCrew         			= 378;
	refShip.MinCrew         			= 20;
	refShip.BoardingCrew						= 196;
	refShip.GunnerCrew				= 54;
	refShip.CannonerCrew						= 108;
	refShip.SailorCrew				= 260;
	refShip.SpeedRate       				= 14.3;
	refShip.TurnRate        			= 45.0;
	refShip.Price           			= 120000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 8550;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 7550;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.5;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 1.2;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.1;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Frigate Constitution
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CONSTITUTION]);
	refShip.Name 				= "Constitution";
	refship.Soundtype 				= "frigate";
	refShip.Class 				= 3;
	refShip.Cannon 				= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber 				= 24;
	refShip.Weight 				= Tonnes2CWT(1000);
	refShip.Capacity 				= 4000;
	refShip.CannonsQuantity 			= 54;
	refShip.rcannon 							= 26;
	refShip.lcannon 							= 26;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew 				= 417;
	refShip.MinCrew 				= 20;
	refShip.BoardingCrew 					= 235;
	refShip.GunnerCrew 				= 54;
	refShip.CannonerCrew 				= 108;
	refShip.SailorCrew 					= 400;
	refShip.SpeedRate 					= 15.6;
	refShip.TurnRate 				= 56.0;
	refShip.Price 					= 180000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP 					= 9000;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 8000;
}
	refShip.SP 					= 400;
	refShip.AbordageLocation = "Boarding Deck_01";
	refship.Type.Merchant 				= false;
	refship.Type.War			        = true;
	refShip.fWindAgainstSpeed = 3.0;
	refShip.sea_enchantment = 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;
	refship.WaterLine = 0.50;

	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed = 4.5;//boal
	refship.CabinType = "Cabin"; // boal 28.03.05
	refship.DeckType = "Big";

	refship.InertiaAccelerationX = 5.0; refship.InertiaBrakingX = 5.0;
	refship.InertiaAccelerationY = 4; refship.InertiaBrakingY = 4;
	refship.InertiaAccelerationZ = 5.0; refship.InertiaBrakingZ = 5.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width = "3.7, 3.9";
	refship.Track1.Speed = "7.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width = "8.0, 9.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// La Licorne
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LA_LICORNE]);
	refShip.Name            			= "La_Licorne";
	refship.Soundtype			= "frigate";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 4900;
	refShip.CannonsQuantity				= 52;
	refShip.rcannon 							= 22;
	refShip.lcannon 							= 22;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         				= 383;
	refShip.MinCrew         				= 24;
	refShip.BoardingCrew				= 203;
	refShip.GunnerCrew				= 52;
	refShip.CannonerCrew				= 104;
	refShip.SailorCrew				= 200;
	refShip.SpeedRate       				= 14.7;
	refShip.TurnRate        			= 42.0;
	refShip.Price           			= 220000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 9700;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 8700;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.2;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= -0.2;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.0;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 10;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Lineship5 - USS Independence
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LINESHIP5]);
	refShip.Name            			= "Lineship5";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 28;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 4200;
	refShip.CannonsQuantity		= 56;
	refShip.rcannon 							= 25;
	refShip.lcannon 							= 25;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 440;
	refShip.MinCrew         		= 26;
	refShip.BoardingCrew						= 246;
	refShip.GunnerCrew				= 56;
	refShip.CannonerCrew				= 112;
	refShip.SailorCrew					= 430;
	refShip.SpeedRate				= 12.9;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 220000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 9700;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 8700;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_02";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.5;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 1.01;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.51;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 3.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 14;	refship.InertiaBrakingY		= 5;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.Height.Bombs.Y				= 3.0;	refShip.Height.Bombs.DY		= 1.5;
	refShip.Height.Grapes.Y				= 4.5;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 24.0;	refShip.Height.Knippels.DY	= 17.0;
	refShip.Height.Balls.Y				= 3.0;	refShip.Height.Balls.DY		= 1.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.6;
	refShip.GeraldSails.rey_b3.vscale	= 0.6;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Lineship - Heavy Lineship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LINESHIP]);
	refShip.Name            			= "Lineship";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(2000);
	refShip.Capacity        			= 5150;
	refShip.CannonsQuantity		= 60;
	refShip.rcannon 							= 28;
	refShip.lcannon 							= 28;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         		= 460;
	refShip.MinCrew         		= 26;
	refShip.BoardingCrew					= 254;
	refShip.GunnerCrew				= 60;
	refShip.CannonerCrew				= 120;
	refShip.SailorCrew					= 450;
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 220000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 10800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 9800;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.5;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.69;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed            = 1.7;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 3.5;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Heavy Trader - Pinnace Of War
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_WARGALLEON2]);
	refShip.Name            			= "WarGalleon2";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(1100);
	refShip.Capacity        			= 5800;
	refShip.CannonsQuantity				= 52;
	refShip.rcannon 							= 22;
	refShip.lcannon 							= 22;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 490;
	refShip.MinCrew         		= 26;
	refShip.BoardingCrew						= 308;
	refShip.GunnerCrew				= 52;
	refShip.CannonerCrew				= 104;
	refShip.SailorCrew					= 482;
	refShip.SpeedRate					= 12.7;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 150000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 16900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 15900;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 2.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 80;


	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= 0.34;

	refship.SpeedDependWeight			= 0.15;
	refship.SubSeaDependWeight			= 0.3;
	refship.TurnDependWeight			= 0.2;
	refship.WindAgainstSpeed   = 2.6;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.5;
	refship.InertiaAccelerationY	= 3;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.0;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.2, 7.3";
	refship.Track1.Speed	= "5.5, 6.5";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "6.0, 8.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Cursed Flying Dutchman - The Flying Dutchman
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CURSEDDUTCHMAN]);
	refShip.Name 					= "CursedDutchman";
	refship.Soundtype 				= "manowar";
	refShip.Class 					= 3;
	refShip.Cannon 								= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber 				= 42;
	refShip.Weight 								= Tonnes2CWT(2200);
	refShip.Capacity 				= 5400;
	refShip.CannonsQuantity 		= 54;
	refShip.rcannon 							= 24;
	refShip.lcannon 							= 24;
	refShip.fcannon 							= 6;
	refShip.bcannon 							= 0;
	refShip.MaxCrew 			= 430;
	refShip.MinCrew 			= 26;
	refShip.BoardingCrew 					= 242;
	refShip.GunnerCrew 				= 54;
	refShip.CannonerCrew 					= 108;
	refShip.SailorCrew 				= 422;
	refShip.SpeedRate 					= 17.8;
	refShip.TurnRate 				= 59.0;
	refShip.Price 					= 200000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP 					= 11900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 10900;
}
	refShip.SP 					= 400;
	refship.EmblemedSails.normalTex = "ships\sail_Dutchman.tga.tx";
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.CanEncounter					= false;
	refship.Type.Merchant					= true;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 5.0;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 3.8;//boal
	refship.CabinType          = "CabineFDM"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;		refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// RN Battle Frigate - Fast Battle Frigate
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_RN_BATTLEFRIGATE]);
	refShip.Name 				= "RN_BattleFrigate";
	refship.Soundtype 				= "frigate";
	refShip.Class 				= 3;
	refShip.Cannon 				= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber 				= 24;
	refShip.Weight 				= Tonnes2CWT(1000);
	refShip.Capacity 				= 4400;
	refShip.CannonsQuantity 			= 54;
	refShip.rcannon 							= 26;
	refShip.lcannon 							= 26;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 2;
	refShip.MaxCrew 				= 390;
	refShip.MinCrew 				= 24;
	refShip.BoardingCrew 					= 204;
	refShip.GunnerCrew 				= 54;
	refShip.CannonerCrew 				= 108;
	refShip.SailorCrew 					= 380;
	refShip.SpeedRate 					= 14.7;
	refShip.TurnRate 				= 42.0;
	refShip.Price 					= 230000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP 					= 10800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 9800;
}
	refShip.SP 					= 400;
	refShip.AbordageLocation = "Boarding Deck_01";
	refship.Type.Merchant			 = false;
	refship.Type.War 			 = true;
	refShip.fWindAgainstSpeed = 3.5;
	refShip.sea_enchantment = 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;
	refship.WaterLine = 0.50;

	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 1.0;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed = 4.5;//boal
	refship.CabinType = "Cabin"; // boal 28.03.05
	refship.DeckType = "Big";

	refship.InertiaAccelerationX = 5.0; refship.InertiaBrakingX = 5.0;
	refship.InertiaAccelerationY = 4; refship.InertiaBrakingY = 4;
	refship.InertiaAccelerationZ = 5.0; refship.InertiaBrakingZ = 5.0;

	refShip.Height.Bombs.Y = 1.0; refShip.Height.Bombs.DY = 0.5;
	refShip.Height.Grapes.Y = 2.0; refShip.Height.Grapes.DY = 1.0;
	refShip.Height.Knippels.Y = 10.0; refShip.Height.Knippels.DY = 8.0;
	refShip.Height.Balls.Y = 1.0; refShip.Height.Balls.DY = 0.5;

	refShip.GeraldSails.rey_b1 = 1;
	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_b1.vscale = 0.9;
	refShip.GeraldSails.rey_b2.vscale = 0.7;
	refShip.GeraldSails.rey_b3.vscale = 0.7;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width = "3.7, 3.9";
	refship.Track1.Speed = "7.0, 8.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width = "8.0, 9.0";
	refship.Track2.Speed = "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Dutchlineship - Dutch Escort Ship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_DUTCHLINESHIP]);
	refShip.Name            			= "Dutchlineship";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(2000);
	refShip.Capacity        			= 4550;
	refShip.CannonsQuantity		= 60;
	refShip.rcannon 					= 26;
	refShip.lcannon 					= 26;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         			= 470;
	refShip.MinCrew         			= 24;
	refShip.BoardingCrew					= 266;
	refShip.GunnerCrew				= 60;
	refShip.CannonerCrew					= 120;
	refShip.SailorCrew				= 460;
	refShip.SpeedRate					= 12.8;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 225000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 11650;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 10650;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation				= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed			= 1.6;
	refShip.sea_enchantment				= 1.1;
	refShip.lowpolycrew 				= 24;
	refShip.buildtime 				= 120;

	refship.Rocking.y 				= 0.3;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine				= -0.25;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.9;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed            		= 1.7;//boal
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 3.5;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b1			= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.15;
	refship.Track1.LifeTime 			= 16.5;
	refship.Track1.Width				= "3.0, 4.0";
	refship.Track1.Speed				= "8.0, 8.0";

	refship.Track2.ZStart				= -0.25;
	refship.Track2.LifeTime 			= 10.5;
	refship.Track2.Width				= "6.0, 7.0";
	refship.Track2.Speed				= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

///////////////////////////////////////////////////////////////////////////
	/// Dutchlineship2 - Frederich William zu Pferde
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_DUTCHLINESHIP2]);
	refShip.Name            			= "Dutchlineship2";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(2000);
	refShip.Capacity        			= 4550;
	refShip.CannonsQuantity		= 60;
	refShip.rcannon 					= 26;
	refShip.lcannon 					= 26;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         			= 410;
	refShip.MinCrew         			= 24;
	refShip.BoardingCrew					= 206;
	refShip.GunnerCrew				= 60;
	refShip.CannonerCrew					= 120;
	refShip.SailorCrew				= 410;
	refShip.SpeedRate					= 14.5;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 225000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 11650;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 10650;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation				= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed			= 1.6;
	refShip.sea_enchantment				= 1.1;
	refShip.lowpolycrew 				= 24;
	refShip.buildtime 				= 120;

	refship.Rocking.y 				= 0.3;
	refship.Rocking.az 				= 0.035;

	refship.WaterLine				= -0.25;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.9;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed            		= 1.7;//boal
	refship.CabinType          			= "Cabin"; // boal 28.03.05
	refship.DeckType           			= "Big";

	refship.InertiaAccelerationX	= 4.5;	refship.InertiaBrakingX		= 4.0;
	refship.InertiaAccelerationY	= 3.5;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 4.5;	refship.InertiaBrakingZ		= 4.0;

	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_b1			= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable				= true;
	refship.Track1.ZStart				= 0.15;
	refship.Track1.LifeTime 			= 16.5;
	refship.Track1.Width				= "3.0, 4.0";
	refship.Track1.Speed				= "8.0, 8.0";

	refship.Track2.ZStart				= -0.25;
	refship.Track2.LifeTime 			= 10.5;
	refship.Track2.Width				= "6.0, 7.0";
	refship.Track2.Speed				= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// LineShip Heavy - Heavy Ship of the Line
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LINESHIPHEAVY]);
	refShip.Name            			= "LineShipHeavy";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS4;
	refShip.MaxCaliber      			= 36;
	refShip.Weight			= Tonnes2CWT(2000);
	refShip.Capacity        			= 5000;
	refShip.CannonsQuantity		= 64;
	refShip.rcannon 							= 28;
	refShip.lcannon 							= 28;
	refShip.fcannon 							= 6;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 480;
	refShip.MinCrew         			= 26;
	refShip.BoardingCrew					= 262;
	refShip.GunnerCrew				= 64;
	refShip.CannonerCrew				= 128;
	refShip.SailorCrew				= 470;
	refShip.SpeedRate       				= 11.5;
	refShip.TurnRate        			= 28.0;
	refShip.Price           			= 230000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 12400;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 11400;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.8;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed            = 1.7;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refShip.Height.Bombs.Y				= 4.5;		refShip.Height.Bombs.DY		= 2.0;
	refShip.Height.Grapes.Y				= 8.0;		refShip.Height.Grapes.DY	= 2.0;
	refShip.Height.Knippels.Y			= 35.0;		refShip.Height.Knippels.DY	= 30.0;
	refShip.Height.Balls.Y				= 4.5;		refShip.Height.Balls.DY		= 2.0;

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Warship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_WARSHIP]);
	refShip.Name            			= "Warship";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 36;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 5400;
	refShip.CannonsQuantity		= 66;
	refShip.rcannon 							= 30;
	refShip.lcannon 							= 30;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 520;
	refShip.MinCrew         		= 28;
	refShip.BoardingCrew						= 294;
	refShip.GunnerCrew				= 66;
	refShip.CannonerCrew				= 132;
	refShip.SailorCrew					= 520;
	refShip.SpeedRate					= 12.5;
	refShip.TurnRate        			= 34;
	refShip.Price           			= 250000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 14900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 13900;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.85;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.5;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 1.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;		refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Battleship - La Couronne
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_COURONNE]);
	refShip.Name            			= "Couronne";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      			= 36;
	refShip.Weight				= Tonnes2CWT(3000);
	refShip.Capacity        			= 5700;
	refShip.CannonsQuantity		= 64;
	refShip.rcannon 						= 24;
	refShip.lcannon 						= 24;
	refShip.fcannon 						= 8;
	refShip.bcannon 						= 8;
	refShip.MaxCrew         	= 560;
	refShip.MinCrew         		= 28;
	refShip.BoardingCrew		= 340;
	refShip.GunnerCrew			= 64;
	refShip.CannonerCrew			= 128;
	refShip.SailorCrew		= 550;
	refShip.SpeedRate		= 11.5;
	refShip.TurnRate        	= 32.0;
	refShip.Price           	= 250000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 15800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 14800;
}
	refShip.SP              	= 400;
	refShip.AbordageLocation		= "Boarding Deck_01";
	refship.Type.Merchant				= false;
	refship.Type.War				= true;
	refShip.fWindAgainstSpeed	= 1.4;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 		= 120;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.035;


	refship.WaterLine		= 0.1;
	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 0.75;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.0;//boal
	refship.CabinType          	= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           	= "Big";

	refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.7;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.65;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 	= 16.5;
	refship.Track1.Width		= "6.0, 8.2";
	refship.Track1.Speed		= "9.0, 9.0";

	refship.Track2.ZStart		= 0.0;
	refship.Track2.LifeTime 	= 13.5;
	refship.Track2.Width		= "8.0, 9.0";
	refship.Track2.Speed		= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Dutchship - Dutch ManOWar
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_DUTCHSHIP]);
	refShip.Name            			= "Dutchship";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS48;
	refShip.MaxCaliber      			= 48;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 6800;
	refShip.CannonsQuantity						= 60;
	refShip.rcannon 							= 24;
	refShip.lcannon 							= 24;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 8;
	refShip.MaxCrew         			= 570;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew						= 360;
	refShip.GunnerCrew							= 60;
	refShip.CannonerCrew				= 120;
	refShip.SailorCrew					= 560;
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 49.0;
	refShip.Price           			= 600000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 15500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 14500;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.99;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 3.8;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.0;		refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;		refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;		refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 0.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Warship1 - Dutch Warship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_WARSHIP1]);
	refShip.Name            			= "Warship1";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 36;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 6800;
	refShip.CannonsQuantity						= 64;
	refShip.rcannon 							= 28;
	refShip.lcannon 							= 28;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 595;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew						= 373;
	refShip.GunnerCrew							= 64;
	refShip.CannonerCrew				= 128;
	refShip.SailorCrew					= 580;
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 49.0;
	refShip.Price           			= 600000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 15500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 14500;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.0;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 3.8;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.0;		refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;		refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;		refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Warship Poseidon
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_POSEIDON]);
	refShip.Name            			= "Poseidon";
	refship.Soundtype			= "lineship";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 36;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 6000;
	refShip.CannonsQuantity		= 66;
	refShip.rcannon 				= 30;
	refShip.lcannon 				= 30;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 4;
	refShip.MaxCrew         		= 623;
	refShip.MinCrew         		= 32;
	refShip.BoardingCrew					= 393;
	refShip.GunnerCrew				= 66;
	refShip.CannonerCrew				= 132;
	refShip.SailorCrew					= 618;
	refShip.SpeedRate			= 12.1;
	refShip.TurnRate        			= 35;
	refShip.Price           			= 423000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 15500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 14500;
}
	refShip.SP              			= 400;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= false;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 1.1;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 		= 120;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.035;

	refship.WaterLine		= 0.05;

	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.1;//boal
	refship.CabinType          	= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           	= "Big";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 	= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Seven Provincien
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SEVENPROVINCIEN]);
	refShip.Name            			= "Sevenprovincien";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(800);
	refShip.Capacity        			= 5800;
	refShip.CannonsQuantity		= 72;
	refShip.rcannon 							= 31;
	refShip.lcannon 							= 31;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 6;
	refShip.MaxCrew				= 640;
	refShip.MinCrew         		= 30;
	refShip.BoardingCrew						= 394;
	refShip.GunnerCrew				= 72;
	refShip.CannonerCrew				= 144;
	refShip.SailorCrew					= 630;
	refShip.SpeedRate					= 12.0;
	refShip.TurnRate        			= 36.0;
	refShip.Price           			= 350000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 14050;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 13050;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.5;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.9;
	refship.SpeedDependWeight			= 0.4;
	refship.SubSeaDependWeight			= 1.1;
	refship.TurnDependWeight			= 0.25;
	refship.WindAgainstSpeed   = 6.0;//boal
    	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
    	refship.DeckType           = "Medium";

	refship.InertiaAccelerationX	= 3.0;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.85;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "5.7, 7.9";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "10.0, 12.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Heavy Warship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_HEAVYWARSHIP]);
	//Breaks all the time...change to Battleship
	//refShip.Name            			= "HeavyWarship";
	refShip.Name            			= "Battleship";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(3000);
	refShip.Capacity        			= 5800;
	refShip.CannonsQuantity		= 74;
	refShip.rcannon 							= 34;
	refShip.lcannon 							= 34;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 650;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew						= 398;
	refShip.GunnerCrew							= 74;
	refShip.CannonerCrew				= 148;
	refShip.SailorCrew					= 640;
	refShip.SpeedRate					= 11.5;
	refShip.TurnRate        			= 27.8;
	refShip.Price           			= 350000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 15900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 14900;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.85;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 2.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 1.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;		refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Battleship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BATTLESHIP]);
	refShip.Name            			= "Battleship";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(3000);
	refShip.Capacity        			= 5900;
	refShip.CannonsQuantity		= 80;
	refShip.rcannon 							= 36;
	refShip.lcannon 							= 36;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 6;
	refShip.MaxCrew         		= 690;
	refShip.MinCrew         		= 30;
	refShip.BoardingCrew						= 420;
	refShip.GunnerCrew				= 80;
	refShip.CannonerCrew				= 160;
	refShip.SailorCrew					= 680;
	refShip.SpeedRate					= 11.5;
	refShip.TurnRate        			= 32.0;
	refShip.Price           			= 380000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 16800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 15800;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;


	refship.WaterLine							= 0.30;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.75;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.7;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "6.0, 8.2";
	refship.Track1.Speed	= "9.0, 9.0";

	refship.Track2.ZStart	= 0.0;
	refship.Track2.LifeTime = 13.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Warship Bellona
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BELLONA]);
	refShip.Name            			= "Bellona";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 6200;
	refShip.CannonsQuantity		= 84;
	refShip.rcannon 				= 40;
	refShip.lcannon 				= 40;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;
	refShip.MaxCrew         		= 690;
	refShip.MinCrew         		= 37;
	refShip.BoardingCrew					= 401;
	refShip.GunnerCrew				= 84;
	refShip.CannonerCrew				= 168;
	refShip.SailorCrew					= 680;
	refShip.SpeedRate			= 12.0;
	refShip.TurnRate        			= 34;
	refShip.Price           			= 420000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 15900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 14900;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= false;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 1.4;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 		= 120;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.035;

	refship.WaterLine		= 0.5;

	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.5;//boal
	refship.CabinType          	= "Cabin"; // boal 28.03.05
	refship.DeckType           	= "Big";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 	= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// LinearShip
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LINEARSHIP]);
	refShip.Name            			= "LinearShip";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 36;
	refShip.Weight			= Tonnes2CWT(3200);
	refShip.Capacity        			= 5900;
	refShip.CannonsQuantity		= 84;
	refShip.rcannon 						= 39;
	refShip.lcannon 						= 39;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 4;
	refShip.MaxCrew         		= 680;
	refShip.MinCrew         		= 30;
	refShip.BoardingCrew						= 398;
	refShip.GunnerCrew				= 84;
	refShip.CannonerCrew				= 168;
	refShip.SailorCrew					= 670;
	refShip.SpeedRate				= 12.0;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 400000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 14800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 13800;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refShip.Height.Bombs.Y				= 4.0;		refShip.Height.Bombs.DY		= 2.0;
	refShip.Height.Grapes.Y				= 7.0;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 36.0;		refShip.Height.Knippels.DY	= 32.0;
	refShip.Height.Balls.Y				= 4.0;		refShip.Height.Balls.DY		= 2.0;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "6.0, 8.2";
	refship.Track1.Speed	= "9.0, 9.0";

	refship.Track2.ZStart	= 0.0;
	refship.Track2.LifeTime = 13.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Shark
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SHARK]);
	refShip.Name            			= "Shark";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight			= Tonnes2CWT(3200);
	refShip.Capacity        			= 5500;
	refShip.CannonsQuantity		= 84;
	refShip.rcannon 						= 39;
	refShip.lcannon 						= 39;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 4;
	refShip.MaxCrew         			= 680;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew					= 398;
	refShip.GunnerCrew				= 84;
	refShip.CannonerCrew				= 168;
	refShip.SailorCrew				= 670;
	refShip.SpeedRate					= 12.7;
	refShip.TurnRate        			= 34.5;
	refShip.Price           			= 410000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 14200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 13200;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.30;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refShip.Height.Bombs.Y				= 4.0;		refShip.Height.Bombs.DY		= 2.0;
	refShip.Height.Grapes.Y				= 7.0;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 36.0;		refShip.Height.Knippels.DY	= 32.0;
	refShip.Height.Balls.Y				= 4.0;		refShip.Height.Balls.DY		= 2.0;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "6.0, 8.2";
	refship.Track1.Speed	= "9.0, 9.0";

	refship.Track2.ZStart	= 0.0;
	refship.Track2.LifeTime = 13.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Superior Warship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FR_SUPERIORWARSHIP1]);
	refShip.Name            			= "FR_SuperiorWarship1";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(3200);
	refShip.Capacity        			= 6400;
	refShip.CannonsQuantity		= 74;
	refShip.rcannon 						= 34;
	refShip.lcannon 						= 34;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 4;
	refShip.MaxCrew         			= 660;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew					= 408;
	refShip.GunnerCrew				= 74;
	refShip.CannonerCrew				= 148;
	refShip.SailorCrew				= 650;
	refShip.SpeedRate					= 11.7;
	refShip.TurnRate        			= 34.5;
	refShip.Price           			= 430000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 15800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 14800;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.30;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.55;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refShip.Height.Bombs.Y				= 4.0;		refShip.Height.Bombs.DY		= 2.0;
	refShip.Height.Grapes.Y				= 7.0;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 36.0;		refShip.Height.Knippels.DY	= 32.0;
	refShip.Height.Balls.Y				= 4.0;		refShip.Height.Balls.DY		= 2.0;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "6.0, 8.2";
	refship.Track1.Speed	= "9.0, 9.0";

	refship.Track2.ZStart	= 0.0;
	refship.Track2.LifeTime = 13.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Battleship1 - Light Battleship
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BATTLESHIP1]);
	refShip.Name            			= "Battleship1";
	refship.Soundtype			= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(3000);
	refShip.Capacity        			= 6800;
	refShip.CannonsQuantity		= 70;
	refShip.rcannon 							= 32;
	refShip.lcannon 							= 32;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         		= 600;
	refShip.MinCrew         		= 30;
	refShip.BoardingCrew						= 360;
	refShip.GunnerCrew				= 70;
	refShip.CannonerCrew				= 140;
	refShip.SailorCrew					= 590;
	refShip.SpeedRate					= 11.7;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 420000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 16200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 15200;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;


	refship.WaterLine							= 0.30;
	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 0.75;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 3.5;	refship.InertiaBrakingX		= 3.0;
	refship.InertiaAccelerationY	= 2.5;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 3.5;	refship.InertiaBrakingZ		= 3.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.7;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.65;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "6.0, 8.2";
	refship.Track1.Speed	= "9.0, 9.0";

	refship.Track2.ZStart	= 0.0;
	refship.Track2.LifeTime = 13.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Warship - Le Superbe
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SUPERBE]);
	refShip.Name            		= "Superbe";
	refship.Soundtype		= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      		= 42;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        		= 6000;
	refShip.CannonsQuantity		= 78;
	refShip.rcannon 			= 37;
	refShip.lcannon 			= 37;
	refShip.fcannon 			= 2;
	refShip.bcannon 			= 2;
	refShip.MaxCrew         		= 650;
	refShip.MinCrew         		= 30;
	refShip.BoardingCrew		= 379;
	refShip.GunnerCrew		= 78;
	refShip.CannonerCrew		= 156;
	refShip.SailorCrew		= 366;
	refShip.SpeedRate		= 12.5;
	refShip.TurnRate        		= 34;
	refShip.Price           		= 450000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              		= 16900;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 15900;
}
	refShip.SP              		= 450;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 1.4;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 			= 120;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.035;

	refship.WaterLine			= -0.1;

	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.5;//boal
	refship.CabinType          		= "Cabin"; // boal 28.03.05
	refship.DeckType           		= "Big";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b1	= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 		= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 		= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Link - 2nd Rate Ship of the line
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_LINK]);
	refShip.Name            			= "Link";
	refship.Soundtype					= "manowar";
	refShip.Class						= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 32;
	refShip.Weight						= Tonnes2CWT(3500);
	refShip.Capacity        			= 5800;
	refShip.CannonsQuantity				= 78;
	refShip.rcannon 					= 37;
	refShip.lcannon 					= 37;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 2;
	refShip.MaxCrew         			= 640;
	refShip.MinCrew         			= 26;
	refShip.BoardingCrew				= 368;
	refShip.GunnerCrew					= 82;
	refShip.CannonerCrew				= 164;
	refShip.SailorCrew					= 630;
	refShip.SpeedRate					= 11.3;
	refShip.TurnRate        			= 20.0;
	refShip.Price           			= 550000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 16500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 15500;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.3;
	refship.Rocking.az = 0.02	;

	refship.WaterLine							= -0.2;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Neptune
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_NEPTUNE]);
	refShip.Name            		= "Neptune";
	refship.Soundtype		= "lineship";
	refShip.Class			= 2;
	refShip.Cannon          		= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      		= 32;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        		= 6000;
	refShip.CannonsQuantity		= 82;
	refShip.rcannon 			= 37;
	refShip.lcannon 			= 37;
	refShip.fcannon 			= 2;
	refShip.bcannon 			= 6;
	refShip.MaxCrew         		= 730;
	refShip.MinCrew         		= 30;
	refShip.BoardingCrew		= 454;
	refShip.GunnerCrew		= 82;
	refShip.CannonerCrew		= 164;
	refShip.SailorCrew		= 446;
	refShip.SpeedRate		= 12.7;
	refShip.TurnRate        		= 34;
	refShip.Price           		= 465000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              		= 17000;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 16000;
}
	refShip.SP              		= 450;
	refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 1.4;
	refShip.sea_enchantment		= 1.1;
	refShip.lowpolycrew 		= 24;
	refShip.buildtime 			= 120;

	refship.Rocking.y 		= 0.5;
	refship.Rocking.az 		= 0.035;

	refship.WaterLine			= 0.2;

	refship.SpeedDependWeight	= 0.35;
	refship.SubSeaDependWeight	= 1.0;
	refship.TurnDependWeight	= 0.4;
	refship.WindAgainstSpeed   	= 1.5;//boal
	refship.CabinType          		= "Cabin"; // boal 28.03.05
	refship.DeckType           		= "Big";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;	refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2	= 1;
	refShip.GeraldSails.rey_b3	= 1;
	refShip.GeraldSails.rey_b1	= 1;
	refShip.GeraldSails.rey_b1.vscale	= 0.8;
	refShip.GeraldSails.rey_b2.vscale	= 0.65;
	refShip.GeraldSails.rey_b3.vscale	= 0.55;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.25;
	refship.Track1.LifeTime 		= 9.5;
	refship.Track1.Width		= "7.0, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 		= 7.5;
	refship.Track2.Width		= "8.0, 10.0";
	refship.Track2.Speed		= "1.0, 2.0";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Intrépide
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_INTREPIDE]);
	refShip.Name            			= "Intrepide";
	refship.Soundtype			= "lineship";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS24;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(2000);
	refShip.Capacity        			= 6150;
	refShip.CannonsQuantity				= 100;
	refShip.rcannon 							= 48;
	refShip.lcannon 							= 48;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         		= 780;
	refShip.MinCrew         		= 33;
	refShip.BoardingCrew						= 327;
	refShip.GunnerCrew				= 100;
	refShip.CannonerCrew				= 200;
	refShip.SailorCrew					= 776;
	refShip.SpeedRate					= 10.0;
	refShip.TurnRate        			= 31.0;
	refShip.Price           			= 420000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 14800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 13800;
}
	refShip.SP              			= 500;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.4;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine					= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.4;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed            = 1.7;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.3;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7.0;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Endeavour
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_ENDEAVOUR]);
	refShip.Name            			= "Endeavour";
	refship.Soundtype			= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS12;
	refShip.MaxCaliber      			= 42;
	refShip.Weight			= Tonnes2CWT(2000);
	refShip.Capacity        			= 6000;
	refShip.CannonsQuantity		= 108;
	refShip.rcannon 							= 52;
	refShip.lcannon 							= 52;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 860;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew						= 506;
	refShip.GunnerCrew							= 108;
	refShip.CannonerCrew				= 216;
	refShip.SailorCrew					= 850;
	refShip.SpeedRate					= 11.4;
	refShip.TurnRate        			= 38.0;
	refShip.Price           			= 464000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 17200;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 16200;
}
	refShip.SP              			= 500;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.2;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine					= 0.4;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 1.15;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed            = 1.7;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 0.3;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 7.0;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.6;
	refShip.GeraldSails.rey_b3.vscale		= 0.6;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.15;
	refship.Track1.LifeTime = 16.5;
	refship.Track1.Width	= "3.0, 4.0";
	refship.Track1.Speed	= "8.0, 8.0";

	refship.Track2.ZStart	= -0.25;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "6.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Manowar fast - Light Man-of-War
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MANOWAR_FAST]);
	refShip.Name            			= "Manowar_fast";
	refship.Soundtype			= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS36;
	refShip.MaxCaliber      			= 48;
	refShip.Weight			= Tonnes2CWT(4000);
	refShip.Capacity        			= 6200;
	refShip.CannonsQuantity		= 106;
	refShip.rcannon 							= 46;
	refShip.lcannon 							= 46;
	refShip.fcannon 							= 6;
	refShip.bcannon 							= 8;
	refShip.MaxCrew         		= 800;
	refShip.MinCrew         		= 30;
	refShip.BoardingCrew					= 552;
	refShip.GunnerCrew				= 106;
	refShip.CannonerCrew				= 212;
	refShip.SailorCrew					= 790;
	refShip.SpeedRate				= 11.0;
	refShip.TurnRate        			= 30.0;
	refShip.Price           			= 480000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 18000;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 17000;
}
	refShip.SP              			= 500;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.3;
	refship.Rocking.az = 0.02;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 0.7;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refShip.Height.Bombs.Y				= 6.7;		refShip.Height.Bombs.DY		= 3.0;
	refShip.Height.Grapes.Y				= 11.0;		refShip.Height.Grapes.DY	= 3.0;
	refShip.Height.Knippels.Y			= 46.0;		refShip.Height.Knippels.DY	= 40.0;
	refShip.Height.Balls.Y				= 6.7;		refShip.Height.Balls.DY		= 3.0;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Manowar
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MANOWAR]);
	refShip.Name            			= "Manowar";
	refship.Soundtype			= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 48;
	refShip.Weight			= Tonnes2CWT(4000);
	refShip.Capacity        			= 6800;
	refShip.CannonsQuantity		= 102;
	refShip.rcannon 							= 46;
	refShip.lcannon 							= 46;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 8;
	refShip.MaxCrew         			= 860;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew						= 524;
	refShip.GunnerCrew							= 102;
	refShip.CannonerCrew				= 204;
	refShip.SailorCrew					= 850;
	refShip.SpeedRate					= 9.5;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 500000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 19500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 18500;
}
	refShip.SP              			= 500;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.3;
	refship.Rocking.az = 0.02	;

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   = 0.7;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	// Battle Manowar
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BATTLEMANOWAR]);
	refShip.Name            			= "BattleManowar";
	refship.Soundtype			= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 48;
	refShip.Weight			= Tonnes2CWT(4100);
	refShip.Capacity        			= 7500;
	refShip.CannonsQuantity				= 102;
	refShip.rcannon 					= 46;
	refShip.lcannon 					= 46;
	refShip.fcannon 					= 2;
	refShip.bcannon 					= 8;
	refShip.MaxCrew         			= 924;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew					= 588;
	refShip.GunnerCrew				= 102;
	refShip.CannonerCrew				= 204;
	refShip.SailorCrew				= 910;
	refShip.SpeedRate					= 9.0;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 570000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 20000;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 19000;
}
	refShip.SP              			= 500;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War					= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.3;
	refship.Rocking.az = 0.02;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 0.7;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refShip.Height.Bombs.Y				= 6.7;		refShip.Height.Bombs.DY		= 3.0;
	refShip.Height.Grapes.Y				= 11.0;		refShip.Height.Grapes.DY	= 3.0;
	refShip.Height.Knippels.Y			= 46.0;		refShip.Height.Knippels.DY	= 40.0;
	refShip.Height.Balls.Y				= 6.7;		refShip.Height.Balls.DY		= 3.0;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	// Ship of the Line - Heavy Man-of-war
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_MANOW50_GUB]);
	refShip.Name            			= "Manow50_gub";
	refship.Soundtype			= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 48;
	refShip.Weight			= Tonnes2CWT(3200);
	refShip.Capacity        			= 8000;
	refShip.CannonsQuantity		= 102;
	refShip.rcannon 						= 46;
	refShip.lcannon 						= 46;
	refShip.fcannon 						= 2;
	refShip.bcannon 						= 8;
	refShip.MaxCrew         			= 800;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew					= 464;
	refShip.GunnerCrew				= 102;
	refShip.CannonerCrew				= 204;
	refShip.SailorCrew					= 790;
	refShip.SpeedRate				= 10.5;
	refShip.TurnRate        			= 35.0;
	refShip.Price           			= 570000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 19500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 18500;
}
	refShip.SP              			= 500;
	refShip.AbordageLocation			= "Boarding Deck_03";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine = 0.0;
	refship.SpeedDependWeight = 0.3;
	refship.SubSeaDependWeight = 0.9;
	refship.TurnDependWeight = 0.8;
	refship.WindAgainstSpeed   = 1.0;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refShip.Height.Bombs.Y				= 4.0;		refShip.Height.Bombs.DY		= 2.0;
	refShip.Height.Grapes.Y				= 7.0;		refShip.Height.Grapes.DY	= 1.5;
	refShip.Height.Knippels.Y			= 36.0;		refShip.Height.Knippels.DY	= 32.0;
	refShip.Height.Balls.Y				= 4.0;		refShip.Height.Balls.DY		= 2.0;

	refship.InertiaAccelerationX	= 0.2;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 3;
	refship.InertiaAccelerationZ	= 3.0;	refship.InertiaBrakingZ		= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Victory
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_VICTORY]);
	refShip.Name            			= "Victory";
	refship.Soundtype			= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 48;
	refShip.Weight			= Tonnes2CWT(4000);
	refShip.Capacity        			= 8500;
	refShip.CannonsQuantity				= 106;
	refShip.rcannon 							= 51;
	refShip.lcannon 							= 51;
	refShip.fcannon 							= 2;
	refShip.bcannon 							= 2;
	refShip.MaxCrew         			= 880;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew						= 532;
	refShip.GunnerCrew							= 106;
	refShip.CannonerCrew				= 216;
	refShip.SailorCrew					= 870;
	refShip.SpeedRate					= 10.8;
	refShip.TurnRate        			= 25.0;
	refShip.Price           			= 570000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 19500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 18500;
}
	refShip.SP              			= 500;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.3;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   = 0.7;//boal
	refship.CabinType          = "Cabin_Huge"; //"Cabin_Victory"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;

	refShip.GeraldSails.rey_b2			= 1;
	refShip.GeraldSails.rey_b3			= 1;
	refShip.GeraldSails.rey_c1			= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 0.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 0.0; //

	///////////////////////////////////////////////////////////////////////////
	///
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SOLEYRU]);
	refShip.Name            			= "SoleyRu";
	refship.Soundtype			= "manowar";
	refShip.Class 				= 1;
	refShip.Cannon 				= CANNON_TYPE_CANNON_LBS48;
	refShip.MaxCaliber 				= 48;
	refShip.Weight 				= Tonnes2CWT(4500);
	refShip.Capacity 				= 10000;
	refShip.CannonsQuantity				= 112;
	refShip.rcannon 							= 48;
	refShip.lcannon 							= 48;
	refShip.fcannon 							= 6;
	refShip.bcannon 							= 10;
	refShip.MaxCrew 			= 1200;
	refShip.MinCrew 			= 36;
	refShip.BoardingCrew 				= 828;
	refShip.GunnerCrew 				= 112;
	refShip.CannonerCrew 					= 224;
	refShip.SailorCrew 				= 1190;
	refShip.SpeedRate 					= 10.6;
	refShip.TurnRate 				= 32.0;
	refShip.Price 					= 650000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP 					= 20700;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 19700;
}
	refShip.SP 					= 500;
	refship.EmblemedSails.normalTex = "ships\parus_SoleyRu.tga.tx";
	refShip.AbordageLocation			= "Boarding Deck_01";

	refship.CanEncounter = false;

	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 1.0;
	refShip.sea_enchantment					= 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.3;
	refship.Rocking.az = 0.02;

	refship.WaterLine							= 0.5;
	refship.SpeedDependWeight			= 0.45;
	refship.SubSeaDependWeight			= 1.8;
	refship.TurnDependWeight			= 0.45;
	refship.WindAgainstSpeed   = 1.3;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 2.0;	refship.InertiaBrakingX		= 2.0;
	refship.InertiaAccelerationY	= 2;	refship.InertiaBrakingY		= 2;
	refship.InertiaAccelerationZ	= 2.0;	refship.InertiaBrakingZ		= 2.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale		= 0.98;
	refShip.GeraldSails.rey_b2.vscale		= 0.98;
	refShip.GeraldSails.rey_b3.vscale		= 0.98;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width	= "6.5, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width	= "16.0, 18.0";
	//Boyer fix
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Spanish Manowar - San Felipe
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SANFELIPE]);
	refShip.Name            	= "SanFelipe";
	refship.Soundtype		= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          	= CANNON_TYPE_CANNON_LBS32;
	refShip.MaxCaliber      	= 48;
	refShip.Weight			= Tonnes2CWT(4000);
	refShip.Capacity        	= 6800;
	refShip.CannonsQuantity		= 108;
	refShip.rcannon 		= 51;
	refShip.lcannon 		= 51;
	refShip.fcannon 		= 2;
	refShip.bcannon 		= 4;
	refShip.MaxCrew         	= 940;
	refShip.MinCrew         	= 30;
	refShip.BoardingCrew		= 586;
	refShip.GunnerCrew		= 108;
	refShip.CannonerCrew		= 216;
	refShip.SailorCrew		= 930;
	refShip.SpeedRate		= 10.4;
	refShip.TurnRate        	= 25.0;
	refShip.Price           	= 1050000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              	= 19500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 18500;
}
	refShip.SP              	= 500;
	//refShip.AbordageLocation	= "Boarding Deck_01";
	refship.Type.Merchant		= false;
	refship.Type.War		= true;
	refShip.fWindAgainstSpeed	= 1.0;
	refShip.sea_enchantment		= 1.0;
	refShip.lowpolycrew 		= 28;
	refShip.buildtime 		= 140;

	refship.Type.Merchant		= false;
	refship.Type.War		= true;
	refship.Rocking.y 		= 0.3;
	refship.Rocking.az 		= 0.02;

	refship.WaterLine		= -0.9;
	refship.SpeedDependWeight	= 0.45;
	refship.SubSeaDependWeight	= 1.8;
	refship.TurnDependWeight	= 0.45;
	refship.WindAgainstSpeed   	= 0.7;//boal
	refship.CabinType          	= "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           	= "Big";

	refship.InertiaAccelerationX	= 1.5;	refship.InertiaBrakingX		= 1.5;
	refship.InertiaAccelerationY	= 1.5;	refship.InertiaBrakingY		= 1.5;
	refship.InertiaAccelerationZ	= 1.5;	refship.InertiaBrakingZ		= 1.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_c1		= 1;
	refShip.GeraldSails.rey_c1.vscale	= 0.98;
	refShip.GeraldSails.rey_b2.vscale	= 0.98;
	refShip.GeraldSails.rey_b3.vscale	= 0.98;

	refship.Track.Enable		= true;
	refship.Track1.ZStart		= 0.30;
	refship.Track1.LifeTime 	= 18.5;
	refship.Track1.Width		= "6.5, 7.5";
	refship.Track1.Speed		= "8.0, 9.0";

	refship.Track2.ZStart		= -0.15;
	refship.Track2.LifeTime 	= 10.5;
	refship.Track2.Width		= "16.0, 18.0";
	refship.Track2.Speed		= "0.15, 0.25";

//Nation
        refShip.england = 0.0; //
        refShip.france = 1.0; //
        refShip.holland = 0.0; //
        refShip.pirate = 0.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// SOLEILROYAL
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_SOLEILROYAL]);
	refShip.Name 				= "SoleilRoyal";
	refship.Soundtype 				= "manowar";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS42;
	refShip.MaxCaliber      			= 48;
	refShip.Weight			= Tonnes2CWT(4500);
	refShip.Capacity        			= 9000;
	refShip.CannonsQuantity				= 112;
	refShip.rcannon 							= 52;
	refShip.lcannon 							= 52;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 900;
	refShip.MinCrew         			= 36;
	refShip.BoardingCrew						= 528;
	refShip.GunnerCrew							= 112;
	refShip.CannonerCrew				= 224;
	refShip.SailorCrew					= 890;
	refShip.SpeedRate					= 10.6;
	refShip.TurnRate        			= 29.0;
	refShip.Price           			= 600000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 20000;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 19000;
}
	refShip.SP              			= 500;
	refShip.AbordageLocation = "Boarding Deck_01";
	refship.Type.Merchant = false;
	refship.Type.War = true;
	refShip.fWindAgainstSpeed = 1.0;
	refShip.sea_enchantment = 1.0;
	refShip.lowpolycrew = 28;
	refShip.buildtime = 140;

	refship.Rocking.y = 0.3;
	refship.Rocking.az = 0.02 ;

	refship.WaterLine = 0.5;
	refship.SpeedDependWeight = 0.45;
	refship.SubSeaDependWeight = 1.8;
	refship.TurnDependWeight = 0.45;
	refship.WindAgainstSpeed = 1.3;//boal
	refship.CabinType          = "Cabin_Huge"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX = 2.0; refship.InertiaBrakingX = 2.0;
	refship.InertiaAccelerationY = 2; refship.InertiaBrakingY = 2;
	refship.InertiaAccelerationZ = 2.0; refship.InertiaBrakingZ = 2.0;

	refShip.GeraldSails.rey_b2 = 1;
	refShip.GeraldSails.rey_b3 = 1;
	refShip.GeraldSails.rey_c1 = 1;
	refShip.GeraldSails.rey_c1.vscale = 0.98;
	refShip.GeraldSails.rey_b2.vscale = 0.98;
	refShip.GeraldSails.rey_b3.vscale = 0.98;

	refship.Track.Enable = true;
	refship.Track1.ZStart = 0.30;
	refship.Track1.LifeTime = 18.5;
	refship.Track1.Width = "6.5, 7.5";
	refship.Track1.Speed = "8.0, 9.0";

	refship.Track2.ZStart = -0.15;
	refship.Track2.LifeTime = 10.5;
	refship.Track2.Width = "16.0, 18.0";

	//////////////////////////////////////////////////////////////////////////
	// BrigQeen
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIGQEEN]);
	refShip.Name			= "BrigQeen";
	refship.Soundtype			= "lugger";
	refShip.Class			= 4;
	refShip.Cannon  			= CANNON_TYPE_CULVERINE_LBS16;
	refShip.MaxCaliber 			 = 20;
	refShip.Weight			= Tonnes2CWT(400);
	refShip.Capacity   			= 2500;
	refShip.CannonsQuantity		= 24;
	refShip.rcannon 				= 10;
	refShip.lcannon 				= 10;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;
	refShip.MaxCrew        		= 130;
	refShip.MinCrew        		= 12;
	refShip.BoardingCrew		= 46;
	refShip.GunnerCrew			= 24;
	refShip.CannonerCrew		= 48;
	refShip.SailorCrew			= 130;
	refShip.SpeedRate      		= 15.0;
	refShip.TurnRate       		= 50.0;
	refShip.Price          		= 67500;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP             		= 5500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 4500;
}
	refShip.SP             		= 350;
	refShip.AbordageLocation	= "Boarding Deck_02";
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 2.0;
	refShip.sea_enchantment		= 1.8;
	refShip.lowpolycrew			= 12;
	refShip.buildtime			= 60;

	refship.WindAgainstSpeed   = 4.5;//boal

	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;

	refship.WaterLine	= 0.50;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.0;			refShip.Height.Bombs.DY	= 1.0;
	refShip.Height.Grapes.Y	= 2.0;			refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 16.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY	= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	// BrigSW
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_BRIGSW]);
	refShip.Name			= "BrigSW";
	refship.Soundtype			= "lugger";
	refShip.Class			= 4;
	refShip.Cannon  			= CANNON_TYPE_CANNON_LBS16;
	refShip.MaxCaliber 			 = 20;
	refShip.Weight			= Tonnes2CWT(400);
	refShip.Capacity   			= 2500;
	refShip.CannonsQuantity		= 24;
	refShip.rcannon 				= 10;
	refShip.lcannon 				= 10;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;
	refShip.MaxCrew        			= 130;
	refShip.MinCrew        			= 12;
	refShip.BoardingCrew		= 46;
	refShip.GunnerCrew			= 24;
	refShip.CannonerCrew		= 48;
	refShip.SailorCrew			= 130;
	refShip.SpeedRate      		= 15.5;
	refShip.TurnRate       		= 45.0;
	refShip.Price          		= 70500;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP             		= 5500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 4500;
}
	refShip.SP             		= 350;
	refShip.AbordageLocation	= "Boarding Deck_02";
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 2.0;
	refShip.sea_enchantment		= 1.8;
	refShip.lowpolycrew			= 12;
	refShip.buildtime			= 60;

	refship.WindAgainstSpeed   = 4.2;//boal

	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;

	refship.WaterLine	= 0.50;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.6;
	refship.TurnDependWeight		= 0.3;

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.0;			refShip.Height.Bombs.DY	= 1.0;
	refShip.Height.Grapes.Y	= 2.0;			refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 16.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY	= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//////////////////////////////////////////////////////////////////////////
	//
	//////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_XebekVML]);
	refShip.Name			= "XebekVML";
	refship.Soundtype			= "lugger";
	refShip.Class			= 4;
	refShip.Cannon  			= CANNON_TYPE_CULVERINE_LBS12;
	refShip.MaxCaliber  			= 12;
	refShip.Weight			= Tonnes2CWT(400);
	refShip.Capacity   			= 2000;
	refShip.CannonsQuantity		= 22;
	refShip.rcannon 				= 9;
	refShip.lcannon 				= 9;
	refShip.fcannon 				= 2;
	refShip.bcannon 				= 2;
	refShip.MaxCrew        			= 118;
	refShip.MinCrew        			= 10;
	refShip.BoardingCrew		= 42;
	refShip.GunnerCrew			= 22;
	refShip.CannonerCrew		= 44;
	refShip.SailorCrew			= 114;
	refShip.SpeedRate      		= 18.5;
	refShip.TurnRate       		= 65.0;
	refShip.Price          		= 150500;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP             		= 4800;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 3800;
}
	refShip.SP             		= 400;
	refShip.AbordageLocation	= "Boarding Deck_02";
	refship.CabinType          = "Cabin_Small"; // boal 28.03.05
	refship.Type.Merchant		= false;
	refship.Type.War			= true;
	refShip.fWindAgainstSpeed	= 11.0;
	refShip.sea_enchantment		= 1.8;
	refShip.lowpolycrew			= 12;
	refShip.buildtime			= 60;

	refship.WindAgainstSpeed   = 10.0;//boal

	refship.Rocking.y	= 0.5;
	refship.Rocking.az	= 0.04;

	refship.WaterLine	= 0.60;
	refship.SpeedDependWeight		= 0.3;
	refship.SubSeaDependWeight		= 0.90;
	refship.TurnDependWeight		= 0.3;

	refship.InertiaAccelerationX	= 5.5;	refship.InertiaBrakingX	= 5.5;
	refship.InertiaAccelerationY	= 8;	refship.InertiaBrakingY	= 8;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ	= 6.0;

	refShip.Height.Bombs.Y	= 1.0;			refShip.Height.Bombs.DY	= 1.0;
	refShip.Height.Grapes.Y	= 2.0;			refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y	= 16.0;		refShip.Height.Knippels.DY	= 10.0;
	refShip.Height.Balls.Y		= 1.0;		refShip.Height.Balls.DY	= 1.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale	= 0.8;
	refShip.GeraldSails.rey_b3.vscale	= 0.8;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 12;
	refship.Track1.Width	= "2.0, 3.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "4.0, 6.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	/// Corvette
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_CORVETTE_QUEST]);
	refShip.Name            			= "Corvette_quest";
	refship.Soundtype			= "corvette";
	refShip.Class			= 3;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 20;
	refShip.Weight			= Tonnes2CWT(680);
	refShip.Capacity        			= 4000;
	refShip.CannonsQuantity				= 40;
	refShip.rcannon 					= 16;
	refShip.lcannon 					= 16;
	refShip.fcannon 					= 4;
	refShip.bcannon 					= 4;
	refShip.MaxCrew         		= 240;
	refShip.MinCrew         		= 20;
	refShip.BoardingCrew			= 100;
	refShip.GunnerCrew				= 40;
	refShip.CannonerCrew			= 80;
	refShip.SailorCrew				= 240;
	refShip.SpeedRate					= 20.0;
	refShip.TurnRate        			= 65.0;
	refShip.Price           			= 150000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7700;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 6700;
}
	refShip.SP              			= 450;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 5.2;
	refShip.sea_enchantment					= 1.5;
	refShip.lowpolycrew = 16;
	refShip.buildtime = 80;

	refship.Rocking.y = 0.8;
	refship.Rocking.az = 0.025;

	refship.WaterLine					= 0.22;
	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.42;
	refship.TurnDependWeight			= 0.35;
	refship.WindAgainstSpeed   = 6.0;//boal
	refship.CabinType          = "Cabin_Medium"; // boal 28.03.05

	refship.InertiaAccelerationX	= 8.0;	refship.InertiaBrakingX		= 8.0;
	refship.InertiaAccelerationY	= 6;	refship.InertiaBrakingY		= 6;
	refship.InertiaAccelerationZ	= 6.0;	refship.InertiaBrakingZ		= 6.0;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.17;
	refship.Track1.LifeTime = 12.5;
	refship.Track1.Width	= "4.0, 5.0";
	refship.Track1.Speed	= "6.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 6.5;
	refship.Track2.Width	= "5.0, 7.0";
	refship.Track2.Speed	= "0.15, 0.25";

	///////////////////////////////////////////////////////////////////////////
	/// Frigate Arabella
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_ARABELLA]);
	refShip.Name            			= "ArabellaShip";
	refship.Soundtype			= "frigate";
	refShip.Class			= 2;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS20;
	refShip.MaxCaliber      			= 24;
	refShip.Weight			= Tonnes2CWT(1000);
	refShip.Capacity        			= 5400;
	refShip.CannonsQuantity				= 52;
	refShip.rcannon 							= 22;
	refShip.lcannon 							= 22;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 4;
	refShip.MaxCrew         			= 300;
	refShip.MinCrew         			= 22;
	refShip.BoardingCrew						= 122;
	refShip.GunnerCrew							= 52;
	refShip.CannonerCrew				= 104;
	refShip.SailorCrew					= 300;
	refShip.SpeedRate       			= 15.4;
	refShip.TurnRate        			= 41.0;
	refShip.Price           			= 250000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 7650;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 8650;
}
	refShip.SP              			= 500;
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 4.0;
	refShip.sea_enchantment					= 1.2;
	refShip.lowpolycrew = 20;
	refShip.buildtime = 100;

	refship.Rocking.y = 0.4;
	refship.Rocking.az = 0.035;
	refship.WaterLine							= 0.0;

	refship.SpeedDependWeight			= 0.3;
	refship.SubSeaDependWeight			= 0.29;
	refship.TurnDependWeight			= 0.3;
	refship.WindAgainstSpeed   = 4.5;//boal
	refship.CabinType          = "Cabin"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 5.0;	refship.InertiaBrakingX		= 5.0;
	refship.InertiaAccelerationY	= 4;	refship.InertiaBrakingY		= 4;
	refship.InertiaAccelerationZ	= 5.0;	refship.InertiaBrakingZ		= 5.0;

	refShip.Height.Bombs.Y				= 1.0;	refShip.Height.Bombs.DY		= 0.5;
	refShip.Height.Grapes.Y				= 2.0;	refShip.Height.Grapes.DY	= 1.0;
	refShip.Height.Knippels.Y			= 10.0;	refShip.Height.Knippels.DY	= 8.0;
	refShip.Height.Balls.Y				= 1.0;	refShip.Height.Balls.DY		= 0.5;

	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.9;
	refShip.GeraldSails.rey_b2.vscale		= 0.7;
	refShip.GeraldSails.rey_b3.vscale		= 0.7;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.20;
	refship.Track1.LifeTime = 14.5;
	refship.Track1.Width	= "3.7, 3.9";
	refship.Track1.Speed	= "7.0, 8.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 8.5;
	refship.Track2.Width	= "8.0, 9.0";
	refship.Track2.Speed	= "0.15, 0.25";

	//Nation
        refShip.england = 1.0; //
        refShip.france = 1.0; //
        refShip.holland = 1.0; //
        refShip.pirate = 1.0; //
        refShip.spain = 1.0; //

	///////////////////////////////////////////////////////////////////////////
	/// Flyingdutchman
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FLYINGDUTCHMAN]);
	refShip.Name            			= "Flyingdutchman";
	refship.Soundtype			= "lineship";
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS48;
	refShip.MaxCaliber      			= 48;
	refShip.Weight			= Tonnes2CWT(2500);
	refShip.Capacity        			= 6800;
	refShip.CannonsQuantity						= 60;
	refShip.rcannon 							= 24;
	refShip.lcannon 							= 24;
	refShip.fcannon 							= 4;
	refShip.bcannon 							= 8;
	refShip.MaxCrew         			= 840;
	refShip.MinCrew         			= 30;
	refShip.BoardingCrew						= 630;
	refShip.GunnerCrew							= 60;
	refShip.CannonerCrew				= 120;
	refShip.SailorCrew					= 840;
	refShip.SpeedRate					= 13.0;
	refShip.TurnRate        			= 49.0;
	refShip.Price           			= 600000;
		if(!RTBL) // = If RTBL is NOT enabled
{
	refShip.HP              			= 20500;
		}
	else // = If RTBL IS enabled
	{
	refShip.HP				= 19500;
}
	refShip.SP              			= 550;
	refship.EmblemedSails.normalTex = "ships\sail_Dutchman.tga.tx";
	refShip.AbordageLocation			= "Boarding Deck_01";
	refship.Type.Merchant					= false;
	refship.Type.War						= true;
	refShip.fWindAgainstSpeed				= 3.0;
	refShip.sea_enchantment					= 1.1;
	refShip.lowpolycrew = 24;
	refShip.buildtime = 120;

	refship.Rocking.y = 0.5;
	refship.Rocking.az = 0.035;

	refship.WaterLine							= 0.5;

	refship.SpeedDependWeight			= 0.35;
	refship.SubSeaDependWeight			= 1.0;
	refship.TurnDependWeight			= 0.4;
	refship.WindAgainstSpeed   = 3.8;//boal
	refship.CabinType          = "CabineFDM"; // boal 28.03.05
	refship.DeckType           = "Big";

	refship.InertiaAccelerationX	= 4.0;	refship.InertiaBrakingX		= 3.5;
	refship.InertiaAccelerationY	= 3.0;		refship.InertiaBrakingY		= 2.5;
	refship.InertiaAccelerationZ	= 4.0;	refship.InertiaBrakingZ		= 3.5;

	refShip.GeraldSails.rey_b2		= 1;
	refShip.GeraldSails.rey_b3		= 1;
	refShip.GeraldSails.rey_b1		= 1;
	refShip.GeraldSails.rey_b1.vscale		= 0.8;
	refShip.GeraldSails.rey_b2.vscale		= 0.65;
	refShip.GeraldSails.rey_b3.vscale		= 0.55;

	refship.Track.Enable	= true;
	refship.Track1.ZStart	= 0.25;
	refship.Track1.LifeTime = 9.5;
	refship.Track1.Width	= "7.0, 7.5";
	refship.Track1.Speed	= "8.0, 9.0";

	refship.Track2.ZStart	= -0.15;
	refship.Track2.LifeTime = 7.5;
	refship.Track2.Width	= "8.0, 10.0";
	refship.Track2.Speed	= "1.0, 2.0";

	///////////////////////////////////////////////////////////////////////////
	/// FORT
	///////////////////////////////////////////////////////////////////////////
	makeref(refShip,ShipsTypes[SHIP_FORT]);
	refShip.Name			= "Fort";
	refShip.isFort      			= true;
	refShip.Class			= 1;
	refShip.Cannon          			= CANNON_TYPE_CANNON_LBS48;
	refShip.MaxCaliber			= 92;
	refShip.Weight			= Tonnes2CWT(22500);
	refShip.Capacity			= 900000;
	refShip.CannonsQuantity		= 68;
	refShip.rcannon 							= 68;
	refShip.lcannon 							= 0;
	refShip.fcannon 							= 0;
	refShip.bcannon 							= 0;
	refShip.MaxCrew         			= 1800;
	refShip.OptCrew         			= 1600;
	refShip.MinCrew         			= 400;
	refShip.BoardingCrew				= 800;
	refShip.GunnerCrew					= 800;
	refShip.CannonerCrew				= 800;
	refShip.SailorCrew					= 0;
	refShip.SpeedRate							= 0.0;
	refShip.TurnRate							= 0;
	refShip.Price									= 12000;
	refShip.HP										= 54000;
	refShip.SP										= 500;
	refShip.buildtime = 240;

	refShip.CanEncounter	= false;

	// Check
	for (int i=0; i<SHIP_TYPES_QUANTITY_WITH_FORT-1; i++)
	{
	  	makeref(refShip, ShipsTypes[i]);
		if (!CheckAttribute(refShip,"Name")) { continue; }
		if (!CheckAttribute(refShip,"TurnRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have TurnRate attribute");
		}
		if (!CheckAttribute(refShip,"SpeedRate"))
		{
			Trace("ERROR: Ship " + i + " doesn't have SpeedRate attribute");
		}
		if (!CheckAttribute(refShip,"Class"))
		{
			Trace("ERROR: Ship " + i + " doesn't have class attribute");
		}
		else
		{
			int iClass = sti(refShip.Class);
			if (iClass > 7) { Trace("ERROR: Ship " + i + " class > 7"); }
			if (iClass < 1) { Trace("ERROR: Ship " + i + " class < 1"); }
		}
		refship.InertiaAccelerationY = stf(refship.InertiaAccelerationY) / 6.0;
		// boal 10/11/05
		refShip.OptCrew = sti(refShip.MaxCrew);
		refShip.MaxCrew = makeint(sti(refShip.MaxCrew) * 1.25 + 0.5);
		refShip.cannonr  = refShip.rcannon;
		refShip.cannonl  = refShip.lcannon;
		refShip.cannonf  = refShip.fcannon;
		refShip.cannonb  = refShip.bcannon;
	}
}
