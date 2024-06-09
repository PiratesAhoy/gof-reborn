#include "TEXT\DIALOGS\Quest\Tenochtitlan\Montesuma.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			dialog.text = DLG_TEXT_TE[0];
			link.l1 = DLG_TEXT_TE[1];
			link.l1.go = "FT_1";	
			if (pchar.questTemp.Teno == "takeFire")
			{
				dialog.text = DLG_TEXT_TE[2];
				link.l1 = DLG_TEXT_TE[3];
				link.l1.go = "FTS_1";
			}
		break;
		case "FT_1":
			dialog.text = DLG_TEXT_TE[4];
			link.l1 = DLG_TEXT_TE[5];
			link.l1.go = "FT_3";
		break;
		case "FT_3":
			dialog.text = DLG_TEXT_TE[6];
			link.l1 = DLG_TEXT_TE[7];
			link.l1.go = "FT_4";
		break;
		case "FT_4":
			dialog.text = DLG_TEXT_TE[8];
			link.l1 = DLG_TEXT_TE[9] + GetFullName(pchar) + DLG_TEXT_TE[10];
			link.l1.go = "FT_5";
		break;
		case "FT_5":
			dialog.text = DLG_TEXT_TE[11] + GetFullName(pchar) + DLG_TEXT_TE[12];
			link.l1 = DLG_TEXT_TE[13];
			link.l1.go = "FT_6";
		break;
		case "FT_6":
			dialog.text = DLG_TEXT_TE[14];
			link.l1 = DLG_TEXT_TE[15];
			link.l1.go = "FT_7";
		break;
		case "FT_7":
			dialog.text = DLG_TEXT_TE[16];
			link.l1 = DLG_TEXT_TE[17];
			link.l1.go = "FT_8";
		break;
		case "FT_8":
			dialog.text = DLG_TEXT_TE[18]+
				DLG_TEXT_TE[19]+
				DLG_TEXT_TE[20]+
				DLG_TEXT_TE[21]+
				DLG_TEXT_TE[22]+
				DLG_TEXT_TE[23];
			link.l1 = DLG_TEXT_TE[24];
			link.l1.go = "FT_9";
		break;
		case "FT_9":
			dialog.text = DLG_TEXT_TE[25];
			link.l1 = DLG_TEXT_TE[26];
			link.l1.go = "FT_10";
		break;
		case "FT_10":
			dialog.text = DLG_TEXT_TE[27];
			link.l1 = DLG_TEXT_TE[28];
			link.l1.go = "FT_11";
		break;
		case "FT_11":
			dialog.text = DLG_TEXT_TE[29];
			link.l1 = DLG_TEXT_TE[30];
			link.l1.go = "FT_12";
		break;
		case "FT_12":
			dialog.text = DLG_TEXT_TE[31];
			link.l1 = DLG_TEXT_TE[32];
			link.l1.go = "FT_13";
		break;
		case "FT_13":
			dialog.text = DLG_TEXT_TE[33];
			link.l1 = DLG_TEXT_TE[34];
			link.l1.go = "FT_14";
		break;
		case "FT_14":
			dialog.text = DLG_TEXT_TE[35];
			link.l1 = DLG_TEXT_TE[36];
			link.l1.go = "FT_15";
		break;
		case "FT_15":
			dialog.text = DLG_TEXT_TE[37];
			link.l1 = DLG_TEXT_TE[38];
			link.l1.go = "FT_16";
		break;
		case "FT_16":
			dialog.text = DLG_TEXT_TE[39];
			link.l1 = DLG_TEXT_TE[40];
			link.l1.go = "FT_17";
		break;
		case "FT_17":
			dialog.text = DLG_TEXT_TE[41];
			link.l1 = DLG_TEXT_TE[42];
			link.l1.go = "FT_18";
		break;
		case "FT_18":
			dialog.text = DLG_TEXT_TE[43];
			link.l1 = DLG_TEXT_TE[44];
			link.l1.go = "FT_19";
		break;
		case "FT_19":
			dialog.text = DLG_TEXT_TE[45];
			link.l1 = DLG_TEXT_TE[46];
			link.l1.go = "FT_20";
		break;
		case "FT_20":
			dialog.text = DLG_TEXT_TE[47];
			link.l1 = DLG_TEXT_TE[48];
			link.l1.go = "FT_21";
		break;
		case "FT_21":
			dialog.text = DLG_TEXT_TE[49];
			link.l1 = DLG_TEXT_TE[50];
			link.l1.go = "FT_22";
		break;
		case "FT_22":
			dialog.text = DLG_TEXT_TE[51];
			link.l1 = DLG_TEXT_TE[52];
			link.l1.go = "FT_23";
		break;
		case "FT_23":
			dialog.text = DLG_TEXT_TE[53];
			link.l1 = DLG_TEXT_TE[54];
			link.l1.go = "FT_24";
		break;
		case "FT_24":
			dialog.text = DLG_TEXT_TE[55];
			link.l1 = DLG_TEXT_TE[56];
			link.l1.go = "FT_25";
		break;
		case "FT_25":
			dialog.text = DLG_TEXT_TE[57];
			link.l1 = DLG_TEXT_TE[58];
			link.l1.go = "exit";
			npchar.location.locator = "quest1";
			NextDiag.TempNode = "Fire";	
			AddDialogExitQuestFunction("Teno_MontesumaGoQuest1");
		break;
		//--------------
		case "FTS_1":
			dialog.text = DLG_TEXT_TE[59];
			link.l1 = DLG_TEXT_TE[60] + GetFullName(pchar) + DLG_TEXT_TE[61];
			link.l1.go = "FTS_2";
		break;
		case "FTS_2":
			dialog.text = DLG_TEXT_TE[62] + GetFullName(pchar) + DLG_TEXT_TE[63];
			link.l1 = DLG_TEXT_TE[64];
			link.l1.go = "FTS_3";
		break;
		case "FTS_3":
			dialog.text = DLG_TEXT_TE[65];
			link.l1 = DLG_TEXT_TE[66];
			link.l1.go = "FTS_4";
		break;
		case "FTS_4":
			dialog.text = DLG_TEXT_TE[67]+
				DLG_TEXT_TE[68]+
				DLG_TEXT_TE[69]+
				DLG_TEXT_TE[70]+
				DLG_TEXT_TE[71]+
				DLG_TEXT_TE[72];
			link.l1 = DLG_TEXT_TE[73];
			link.l1.go = "FTS_5";
		break;
		case "FTS_5":
			dialog.text = DLG_TEXT_TE[74];
			link.l1 = DLG_TEXT_TE[75];
			link.l1.go = "FTS_6";
		break;
		case "FTS_6":
			dialog.text = DLG_TEXT_TE[76];
			link.l1 = DLG_TEXT_TE[77];
			link.l1.go = "FTS_7";
		break;
		case "FTS_7":
			dialog.text = DLG_TEXT_TE[78];
			link.l1 = DLG_TEXT_TE[79];
			link.l1.go = "FTS_8";
		break;
		case "FTS_8":
			dialog.text = DLG_TEXT_TE[80];
			link.l1 = DLG_TEXT_TE[81];
			link.l1.go = "FTS_9";
		break;
		case "FTS_9":
			dialog.text = DLG_TEXT_TE[82];
			link.l1 = DLG_TEXT_TE[83];
			link.l1.go = "FTS_10";
		break;
		case "FTS_10":
			dialog.text = DLG_TEXT_TE[84];
			link.l1 = DLG_TEXT_TE[85];
			link.l1.go = "FTS_11";
		break;
		case "FTS_11":
			dialog.text = DLG_TEXT_TE[86];
			link.l1 = DLG_TEXT_TE[87];
			link.l1.go = "FTS_12";
		break;
		case "FTS_12":
			dialog.text = DLG_TEXT_TE[88];
			link.l1 = DLG_TEXT_TE[89];
			link.l1.go = "FTS_13";
		break;
		case "FTS_13":
			dialog.text = DLG_TEXT_TE[90];
			link.l1 = DLG_TEXT_TE[91];
			link.l1.go = "FTS_14";
		break;
		case "FTS_14":
			dialog.text = DLG_TEXT_TE[92];
			link.l1 = DLG_TEXT_TE[93];
			link.l1.go = "Fire_1";
		break;
		//после снятия огня
		case "Fire":
			if (CheckAttribute(loadedLocation, "gotoFire"))
			{
				dialog.text = DLG_TEXT_TE[94];
				link.l1 = DLG_TEXT_TE[95];
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT_TE[96];
				link.l1 = DLG_TEXT_TE[97];
				link.l1.go = "Fire_1";
			}			
		break;
		case "Fire_1":
			dialog.text = DLG_TEXT_TE[98];
			link.l1 = DLG_TEXT_TE[99];
			link.l1.go = "Fire_2";
		break;
		case "Fire_2":
			dialog.text = DLG_TEXT_TE[100];
			link.l1 = DLG_TEXT_TE[101];
			link.l1.go = "Fire_3";
		break;
		case "Fire_3":
			dialog.text = DLG_TEXT_TE[102];
			link.l1 = DLG_TEXT_TE[103];
			link.l1.go = "Fire_4";
		break;
		case "Fire_4":
			dialog.text = DLG_TEXT_TE[104];
			link.l1 = DLG_TEXT_TE[105];
			link.l1.go = "Fire_5";
		break;
		case "Fire_5":
			dialog.text = DLG_TEXT_TE[106];
			link.l1 = DLG_TEXT_TE[107];
			link.l1.go = "Fire_6";
		break;
		case "Fire_6":
			dialog.text = DLG_TEXT_TE[108];
			link.l1 = DLG_TEXT_TE[109];
			link.l1.go = "Fire_7";
		break;
		case "Fire_7":
			dialog.text = DLG_TEXT_TE[110];
			link.l1 = DLG_TEXT_TE[111];
			link.l1.go = "exit";
			NextDiag.TempNode = "Totem";
			pchar.questTemp.Teno = "openTenTemples";
			AddQuestRecord("Tenochtitlan", "3");
		break;

		case "Totem":
			dialog.text = DLG_TEXT_TE[112];
			link.l1 = DLG_TEXT_TE[113];
			link.l1.go = "exit";
		break;

        //после драки с 
		case "AfterGTemple":
			if (CheckCharacterItem(pchar, "SkullAztec")) //череп найден
			{
				dialog.text = DLG_TEXT_TE[114];
				if (CheckCharacterItem(pchar, "pistol7"))
				{
					link.l1 = DLG_TEXT_TE[115];
					link.l1.go = "Skull_1";
				}
				else
				{
					link.l1 = DLG_TEXT_TE[116];
					link.l1.go = "NotShootgun_1";
				}
			}
			else
			{
				dialog.text = DLG_TEXT_TE[117];
				link.l1 = DLG_TEXT_TE[118];
				link.l1.go = "NotSkull";
			}
		break;
		//с собой нет черепа
		case "NotSkull":
			dialog.text = DLG_TEXT_TE[119];
			link.l1 = DLG_TEXT_TE[120];
			link.l1.go = "NotSkull_1";
		break;
		case "NotSkull_1":
			chrDisableReloadToLocation = true;
			LAi_group_SetRelation("MontesumaGroup", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("MontesumaGroup", LAI_GROUP_PLAYER, true);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "NotShootgun_1":
			dialog.text = DLG_TEXT_TE[121];
			link.l1 = DLG_TEXT_TE[122];
			link.l1.go = "NotShootgun_2";
		break;
		case "NotShootgun_2":
			dialog.text = DLG_TEXT_TE[123];
			link.l1 = DLG_TEXT_TE[124];
			link.l1.go = "NotShootgun_3";
		break;
		case "NotShootgun_3":
			dialog.text = DLG_TEXT_TE[125];
			link.l1 = DLG_TEXT_TE[126];
			link.l1.go = "Skull_1";
		break;

		case "Skull_1":
			dialog.text = DLG_TEXT_TE[127];
			link.l1 = DLG_TEXT_TE[128];
			link.l1.go = "Skull_2";
		break;
		case "Skull_2":
			dialog.text = DLG_TEXT_TE[129];
			link.l1 = DLG_TEXT_TE[130];
			link.l1.go = "Skull_3";
		break;
		case "Skull_3":
			dialog.text = DLG_TEXT_TE[131];
			link.l1 = DLG_TEXT_TE[132];
			link.l1.go = "Skull_4";
		break;
		case "Skull_4":
			dialog.text = DLG_TEXT_TE[133];
			link.l1 = DLG_TEXT_TE[134];
			link.l1.go = "Skull_5";
		break;
		case "Skull_5":
			dialog.text = DLG_TEXT_TE[135];
			link.l1 = DLG_TEXT_TE[136];
			link.l1.go = "Skull_6";
		break;
		case "Skull_6":
			dialog.text = DLG_TEXT_TE[137];
			link.l1 = DLG_TEXT_TE[138];
			link.l1.go = "Skull_7";
		break;
		case "Skull_7":
			AddQuestRecord("Tenochtitlan", "5");
			LAi_SetImmortal(npchar, false);
			LocatorReloadEnterDisable("Tenochtitlan", "reload1_back", false);
			LAi_SetWarriorType(sld);
			LAi_group_MoveCharacter(sld, "MontesumaGroup");
			LAi_group_SetRelation("MontesumaGroup", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("MontesumaGroup", LAI_GROUP_PLAYER, false);
			LAi_group_SetCheck("MontesumaGroup", "OpenTheDoors");
			pchar.quest.Teno_clearGroups.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Teno_clearGroups.win_condition.l1.location = pchar.location;
			pchar.quest.Teno_clearGroups.function = "Teno_clearGroups";
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("MainHeroFightModeOn");
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
}
