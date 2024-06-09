#include "TEXT\DIALOGS\Quest\Tenochtitlan\ForAll_Teno.h"
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
			link.l1.go = "exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		//������� � ����� � ������, ������� ����� �� ����
		case "Shore53":
			dialog.text = DLG_TEXT_TE[2];
			link.l1 = DLG_TEXT_TE[3];
			link.l1.go = "Shore53_1";
		break;
		case "Shore53_1":
			dialog.text = DLG_TEXT_TE[4];
			link.l1 = DLG_TEXT_TE[5];
			link.l1.go = "Shore53_2";
		break;
		case "Shore53_2":
			dialog.text = DLG_TEXT_TE[6];
			link.l1 = DLG_TEXT_TE[7];
			link.l1.go = "Shore53_3";
		break;
		case "Shore53_3":
			dialog.text = DLG_TEXT_TE[8];
			link.l1 = DLG_TEXT_TE[9];
			link.l1.go = "Shore53_4";
		break;
		case "Shore53_4":
			dialog.text = DLG_TEXT_TE[10];
			link.l1 = DLG_TEXT_TE[11];
			link.l1.go = "Shore53_5";
		break;
		case "Shore53_5":
			dialog.text = DLG_TEXT_TE[12];
			link.l1 = DLG_TEXT_TE[13];
			link.l1.go = "Shore53_6";
		break;
		case "Shore53_6":
			dialog.text = DLG_TEXT_TE[14];
			link.l1 = DLG_TEXT_TE[15];
			link.l1.go = "Shore53_7";
		break;
		case "Shore53_7":
			dialog.text = DLG_TEXT_TE[16];
			link.l1 = DLG_TEXT_TE[17];
			link.l1.go = "Shore53_8";
		break;
		case "Shore53_8":
			dialog.text = DLG_TEXT_TE[18];
			link.l1 = DLG_TEXT_TE[19];
			link.l1.go = "Shore53_9";
		break;
		case "Shore53_9":
			dialog.text = DLG_TEXT_TE[20];
			link.l1 = DLG_TEXT_TE[21];
			link.l1.go = "Shore53_10";
		break;
		case "Shore53_10":
			dialog.text = DLG_TEXT_TE[22];
			link.l1 = DLG_TEXT_TE[23];
			link.l1.go = "exit";
			AddDialogExitQuestFunction("Teno_startInShore_2");
		break;
	}
}
