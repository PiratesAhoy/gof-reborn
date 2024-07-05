// Note from MAXIMUS
// If anyone will change (or will add new) .label or (.id) - please
// be patient and add this label into RESOURCE\INI\TEXTS\(all languages)\interface_strings.txt
// It's VERY important for multilingual BUILD
void InitIslands()
{
		int		n, i;

	for (i=0; i<MAX_ISLANDS; i++)
	{
	DeleteAttribute(&Islands[i], "");

		Islands[i].id = "";
		Islands[i].reload_enable = true;
		Islands[i].visible = true;
		Islands[i].colonyquantity = 1;
		Islands[i].net = true;
		
		Islands[i].ImmersionDistance = 450000.0;
		Islands[i].ImmersionDepth = 0.0;
		Islands[i].maxviewdist = 5000.0;
	}

	// ==================================================================================================
	// Create temp module for enumerate locators
		object	locator;
		CreateEntity(&locator,"locator");
		n = 0;
	// Falaise de fleur
		Islands[n].id = "FalaiseDeFleur";
		Islands[n].model = "FalaiseDeFleur";
		Islands[n].filespath.models = "islands\FalaiseDeFleur";
		Islands[n].refl_model = "FalaiseDeFleur_refl";
		Islands[n].locators = "FalaiseDeFleur_locators";
		Islands[n].LoadGroup.g1 = "IslandShips1";
		Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name# Port"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Falaise_de_fleur_port_01";
		Islands[n].reload.l1.emerge = "sea";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Octopus Bay";
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "Falaise_de_Fleur_shore";
		Islands[n].reload.l2.emerge = "reload1";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l3.name = "reload_fort1";
		Islands[n].reload.l3.go = "Fort"; // KK
		Islands[n].reload.l3.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l3.emerge = "see";
		Islands[n].reload.l3.radius = 250.0;
		Islands[n].reload.l3.commander = "FalaiseDeFleur Commander"; // KK
		Islands[n].reload.l3.fort.model = "FalaiseDeFleur_fort1";
		Islands[n].reload.l3.fort.locators = "FalaiseDeFleur_fort1_locators";
		Islands[n].reload.l3.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Export.id2 = GOOD_CHOCOLATE;
		//Islands[n].Trade.Export.id3 = GOOD_LINEN;
		//Islands[n].Trade.Export.id4 = GOOD_SILK;
		//Islands[n].Trade.Export.id5 = GOOD_SILVER;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_EBONY;
		//Islands[n].Trade.Import.id3 = GOOD_RUM;
		//Islands[n].Trade.Import.id4 = GOOD_LEATHER;
		//Islands[n].Trade.Import.id5 = GOOD_GOLD;
		//Islands[n].Trade.Import.id6 = GOOD_TREATMENT;
		//Islands[n].Trade.Contraband.id1 = GOOD_SANDAL;
		//Islands[n].Trade.Contraband.id2 = GOOD_FRUITS;
		//Islands[n].Trade.Contraband.id3 = GOOD_CINNAMON;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Redmond
		n = n + 1;
 Islands[n].id = "Redmond";
		Islands[n].model = "redmond";
		Islands[n].filespath.models = "islands\redmond";
		Islands[n].refl_model = "redmond_refl";
		Islands[n].locators = "redmond_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		// NK -->
		// NK <--
		Islands[n].jungle.patch = "Redmond_jungle";
		Islands[n].jungle.texture = "junglesprites";
		Islands[n].jungle.scale = 12.5;

		Islands[n].reload.l1.label = "#stown_name# Port"; // KK
		Islands[n].reload.l1.name = "reload_2";
		Islands[n].reload.l1.go = "REDMOND_PORT";
		Islands[n].reload.l1.emerge = "sea_1";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

           Islands[n].reload.l2.label = "Devil's Throat";
			Islands[n].reload.l2.name = "reload_1";
			Islands[n].reload.l2.go = "Redmond_Shore_01";
			Islands[n].reload.l2.emerge = "reload1";
			Islands[n].reload.l2.radius = 200.0;
			Islands[n].reload.l2.tex = "t1";

			Islands[n].reload.l3.label = "Rocky Shore";
			Islands[n].reload.l3.name = "reload_3";
			Islands[n].reload.l3.go = "Redmond_Shore_02";
			Islands[n].reload.l3.emerge = "reload1";
			Islands[n].reload.l3.radius = 200.0;
			Islands[n].reload.l3.tex = "t1";
			

		Islands[n].reload.l4.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l4.name = "reload_fort1";
		Islands[n].reload.l4.go = "Fort"; // KK
		Islands[n].reload.l4.GoAfterBoard.location = "reload_2";
		Islands[n].reload.l4.emerge = "see";
		Islands[n].reload.l4.commander = "Redmond Commander"; // KK
		Islands[n].reload.l4.radius = 250.0;
		Islands[n].reload.l4.fort.model = "Redmond_fort1";
		Islands[n].reload.l4.fort.locators = "Redmond_fort1_locators";
		Islands[n].reload.l4.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		////Islands[n].Trade.Export.id1 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Export.id2 = GOOD_LINEN;
		//Islands[n].Trade.Export.id3 = GOOD_ALE;
		//Islands[n].Trade.Export.id4 = GOOD_CLOTHES;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_CINNAMON;
		//Islands[n].Trade.Import.id3 = GOOD_SILK;
		//Islands[n].Trade.Import.id4 = GOOD_SANDAL;
		//Islands[n].Trade.Contraband.id1 = GOOD_EBONY;
		//Islands[n].Trade.Contraband.id2 = GOOD_COFFEE;
		//Islands[n].Trade.Contraband.id3 = GOOD_PAPRIKA;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Isla Muelle
		n = n + 1;
 Islands[n].id = "IslaMuelle";
		Islands[n].model = "IslaMuelle";
		Islands[n].filespath.models = "islands\IslaMuelle";
		Islands[n].refl_model = "IslaMuelle_refl";
		Islands[n].locators = "IslaMuelle_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name# Port"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Muelle_port";
		Islands[n].reload.l1.emerge = "Reload3";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Shore";
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "Muelle_shore_02";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.enable = false;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Oyster Beach";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Muelle_shore";
		Islands[n].reload.l3.emerge = "reload2";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l4.name = "reload_fort1";
		Islands[n].reload.l4.go = "Fort"; // KK
		Islands[n].reload.l4.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l4.emerge = "see";
		Islands[n].reload.l4.commander = "IslaMuelle Commander"; // KK
		Islands[n].reload.l4.radius = 250.0;
		Islands[n].reload.l4.fort.model = "IslaMuelle_fort1";
		Islands[n].reload.l4.fort.locators = "IslaMuelle_fort1_locators";
		Islands[n].reload.l4.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_EBONY;
		//Islands[n].Trade.Export.id2 = GOOD_MAHOGANY;
		//Islands[n].Trade.Export.id3 = GOOD_CINNAMON;
		//Islands[n].Trade.Export.id4 = GOOD_SANDAL;
		//Islands[n].Trade.Export.id5 = GOOD_GOLD;
		//Islands[n].Trade.Export.id6 = GOOD_BRICKS;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id3 = GOOD_SUGAR;
		//Islands[n].Trade.Import.id4 = GOOD_LINEN;
		//Islands[n].Trade.Import.id5 = GOOD_SILVER;
		//Islands[n].Trade.Import.id6 = GOOD_TREATMENT;
		//Islands[n].Trade.Contraband.id1 = GOOD_ALE;
		//Islands[n].Trade.Contraband.id2 = GOOD_SILK;
		//Islands[n].Trade.Contraband.id3 = GOOD_TOBACCO;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Oxbay
		n = n + 1;
 Islands[n].id = "Oxbay";
		Islands[n].model = "Oxbay";
		Islands[n].filespath.models = "islands\Oxbay";
		Islands[n].refl_model = "Oxbay_refl";
		Islands[n].locators = "Oxbay_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name# Port"; // KK
		Islands[n].reload.l1.name = "reload_2";
		Islands[n].reload.l1.go = "Oxbay_port";
		Islands[n].reload.l1.emerge = "reload2";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "#stown_name# Port"; // KK
		Islands[n].reload.l2.name = "reload_1";
		Islands[n].reload.l2.go = "Greenford_port";
		Islands[n].reload.l2.emerge = "reload1";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";
		Islands[n].reload.l2.istown = true;

		Islands[n].reload.l3.label = "Gray Rock Bay";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Oxbay_shore_02";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 300.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Lighthouse";
		Islands[n].reload.l4.name = "reload_4";
		Islands[n].reload.l4.go = "Oxbay_lighthouse";
		Islands[n].reload.l4.emerge = "reload3";
		Islands[n].reload.l4.radius = 200.0;
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "Far Beach";
		Islands[n].reload.l5.name = "reload_5";
		Islands[n].reload.l5.go = "Oxbay_Shore_01";
		Islands[n].reload.l5.emerge = "see";
		Islands[n].reload.l5.radius = 200.0;
		Islands[n].reload.l5.tex = "t1";

		Islands[n].reload.l6.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l6.name = "reload_fort1";
		Islands[n].reload.l6.go = "Fort"; // KK
		Islands[n].reload.l6.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l6.emerge = "see";
		Islands[n].reload.l6.radius = 250.0;
		Islands[n].reload.l6.commander = "Greenford Commander"; // KK
		Islands[n].reload.l6.fort.model = "Oxbay_fort1";
		Islands[n].reload.l6.fort.locators = "Oxbay_fort1_locators";
		Islands[n].reload.l6.tex = "t1";

		Islands[n].reload.l7.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l7.name = "reload_fort2";
		Islands[n].reload.l7.go = "Fort"; // KK
		Islands[n].reload.l7.GoAfterBoard.location = "reload_2";
		Islands[n].reload.l7.emerge = "see";
		Islands[n].reload.l7.commander = "Oxbay Commander"; // KK
		Islands[n].reload.l7.radius = 250.0;
		Islands[n].reload.l7.fort.model = "Oxbay_fort2";
		Islands[n].reload.l7.fort.locators = "Oxbay_fort2_locators";
		Islands[n].reload.l7.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_SANDAL;
		//Islands[n].Trade.Export.id2 = GOOD_RUM;
		//Islands[n].Trade.Export.id3 = GOOD_TOBACCO;
		//Islands[n].Trade.Export.id4 = GOOD_SILVER;
		//Islands[n].Trade.Export.id5 = GOOD_GOLD;
		//Islands[n].Trade.Import.id1 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id2 = GOOD_CHOCOLATE;
		//Islands[n].Trade.Import.id3 = GOOD_SILK;
		//Islands[n].Trade.Import.id4 = GOOD_LEATHER;
		//Islands[n].Trade.Contraband.id1 = GOOD_EBONY;
		//Islands[n].Trade.Contraband.id2 = GOOD_COFFEE;
		//Islands[n].Trade.Contraband.id3 = GOOD_PAPRIKA;
		//Islands[n].Trade.Contraband.id4 = GOOD_BRICKS;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Conceicao
		n = n + 1;
 Islands[n].id = "Conceicao";
		Islands[n].model = "Conceicao";
		Islands[n].filespath.models = "islands\Conceicao";
		Islands[n].refl_model = "Conceicao_refl";
		Islands[n].locators = "Conceicao_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name# Port"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Conceicao_port";
		Islands[n].reload.l1.emerge = "reload2";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Sunny Haven";
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "Conceicao_shore_01";
		Islands[n].reload.l2.emerge = "reload1";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Leviathan Rock";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Conceicao_shore_02";
		Islands[n].reload.l3.emerge = "see";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l4.name = "reload_fort1";
		Islands[n].reload.l4.go = "Fort"; // KK
		Islands[n].reload.l4.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l4.emerge = "see";
		Islands[n].reload.l4.radius = 250.0;
		Islands[n].reload.l4.commander = "Conceicao Commander"; // KK
		Islands[n].reload.l4.fort.locators = "Conceicao_fort1_locators";
		Islands[n].reload.l4.fort.model = "Conceicao_fort1";
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "Linda Praia";
		Islands[n].reload.l5.name = "reload_4";
		Islands[n].reload.l5.go = "Conceicao_Shore_03";
		Islands[n].reload.l5.emerge = "see";
		Islands[n].reload.l5.radius = 200.0;
		Islands[n].reload.l5.tex = "t1";
		Islands[n].reload.l5.enable = false;

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Export.id2 = GOOD_SUGAR;
		//Islands[n].Trade.Export.id3 = GOOD_CINNAMON;
		//Islands[n].Trade.Export.id4 = GOOD_FRUITS;
		//Islands[n].Trade.Import.id1 = GOOD_SILK;
		//Islands[n].Trade.Import.id2 = GOOD_ALE;
		//Islands[n].Trade.Import.id3 = GOOD_RUM;
		//Islands[n].Trade.Import.id4 = GOOD_CHOCOLATE;
		//Islands[n].Trade.Import.id5 = GOOD_GOLD;
		//Islands[n].Trade.Import.id6 = GOOD_SILVER;
		//Islands[n].Trade.Import.id7 = GOOD_TREATMENT;
		//Islands[n].Trade.Contraband.id1 = GOOD_WINE;
		//Islands[n].Trade.Contraband.id2 = GOOD_MAHOGANY;
		//Islands[n].Trade.Contraband.id3 = GOOD_COPRA;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Douwesen
		n = n + 1;
		Islands[n].id = "Douwesen";
		Islands[n].model = "Douwesen";
		Islands[n].filespath.models = "islands\Douwesen";
		Islands[n].refl_model = "Douwesen_refl";
		Islands[n].locators = "Douwesen_locators";
		Islands[n].LoadGroup.g1 = "IslandShips1";
		Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name# Port"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Douwesen_port";
		Islands[n].reload.l1.emerge = "reload2";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Palm Beach";
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "Douwesen_shore_01";
		Islands[n].reload.l2.emerge = "reload1";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Crab Cliffs";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Douwesen_shore_02";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l4.name = "reload_fort1";
		Islands[n].reload.l4.go = "Fort"; // KK
		Islands[n].reload.l4.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l4.emerge = "see";
		Islands[n].reload.l4.radius = 250.0;
		Islands[n].reload.l4.commander = "Douwesen Commander"; // KK
		Islands[n].reload.l4.fort.model = "Douwesen_fort1";
		Islands[n].reload.l4.fort.locators = "Douwesen_fort1_locators";
		Islands[n].reload.l4.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor-town.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_TOBACCO;
		//Islands[n].Trade.Export.id2 = GOOD_COFFEE;
		//Islands[n].Trade.Export.id3 = GOOD_COPRA;
		//Islands[n].Trade.Export.id4 = GOOD_ALE;
		//Islands[n].Trade.Export.id5 = GOOD_FOOD;
		//Islands[n].Trade.Export.id6 = GOOD_TREATMENT;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id3 = GOOD_WHEAT;
		//Islands[n].Trade.Import.id4 = GOOD_RUM;
		//Islands[n].Trade.Import.id5 = GOOD_GOLD;
		//Islands[n].Trade.Import.id6 = GOOD_SILVER;
		//Islands[n].Trade.Import.id7 = GOOD_OIL;
		//Islands[n].Trade.Import.id8 = GOOD_COTTON;
		//Islands[n].Trade.Contraband.id1 = GOOD_SUGAR;
		//Islands[n].Trade.Contraband.id2 = GOOD_LINEN;
		//Islands[n].Trade.Contraband.id3 = GOOD_WINE;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Quebradas
		n = n + 1;
		Islands[n].id = "QuebradasCostillas";
		Islands[n].model = "QuebradasCostillas";
		Islands[n].filespath.models = "islands\QuebradasCostillas";
		Islands[n].refl_model = "QuebradasCostillas_refl";
		Islands[n].locators = "QuebradasCostillas_locators";
		Islands[n].LoadGroup.g1 = "IslandShips1";
		Islands[n].visible = true; // KK
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name# Port"; // KK
		Islands[n].reload.l1.name = "reload_2";
		Islands[n].reload.l1.go = "Charlestown_port";
		Islands[n].reload.l1.emerge = "reload1_back";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "#stown_name# Port"; // KK
		Islands[n].reload.l2.name = "reload_1";
		Islands[n].reload.l2.go = "QC_port";
		Islands[n].reload.l2.emerge = "reload1";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "White bay";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "QC_Shore1";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l4.name = "reload_fort1";
		Islands[n].reload.l4.go = "Fort"; // KK
		Islands[n].reload.l4.GoAfterBoard.location = "reload_2";
		Islands[n].reload.l4.emerge = "see";
		Islands[n].reload.l4.radius = 250.0;
		Islands[n].reload.l4.commander = "Charlestown Commander"; // KK
		Islands[n].reload.l4.fort.model = "QuebradasCostillas_Fort1";
		Islands[n].reload.l4.fort.locators = "QuebradasCostillas_Fort1_locators";
		Islands[n].reload.l4.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_RUM;
		//Islands[n].Trade.Export.id2 = GOOD_ALE;
		//Islands[n].Trade.Export.id3 = GOOD_WINE;
		//Islands[n].Trade.Export.id4 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id1 = GOOD_GOLD;
		//Islands[n].Trade.Import.id2 = GOOD_SILVER;
		//Islands[n].Trade.Import.id3 = GOOD_MAHOGANY;
		//Islands[n].Trade.Import.id4 = GOOD_GUNPOWDER;
		//Islands[n].Trade.Import.id5 = GOOD_CLOTHES;
		//Islands[n].Trade.Import.id6 = GOOD_COTTON;
		//Islands[n].Trade.Import.id7 = GOOD_OIL;
		//Islands[n].Trade.Contraband.id1 = GOOD_EBONY;
		//Islands[n].Trade.Contraband.id2 = GOOD_COFFEE;
		//Islands[n].Trade.Contraband.id3 = GOOD_PAPRIKA;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Khael Roa
		n = n + 1;
		Islands[n].id = "KhaelRoa";
		Islands[n].model = "KhaelRoa";
		Islands[n].filespath.models = "islands\KhaelRoa";
		Islands[n].refl_model = "KhaelRoa_refl";
		Islands[n].locators = "KhaelRoa_locators";
		Islands[n].visible = false;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "Khael Roa Shore";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "KhaelRoa_port";
		Islands[n].reload.l1.emerge = "Reload2";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.enable = false;
		Islands[n].reload.l1.tex = "t1";


				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================

	// ==================================================================================================
	// Cayman
		n = n + 1;
		Islands[n].id = "Cayman";
		Islands[n].model = "Cayman";
		Islands[n].filespath.models = "islands\Cayman";
		Islands[n].refl_model = "Cayman_refl";
		Islands[n].locators = "Cayman_locators";
		Islands[n].LoadGroup.g1 = "IslandShips1";
		Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name#"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Cayman_port";
		Islands[n].reload.l1.emerge = "sea";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Cayman Kai";
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "Cayman_Shore_02";
		Islands[n].reload.l2.emerge = "see"; // KK
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Sand Bluff";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Cayman_Shore_03";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Eden Rock";
		Islands[n].reload.l4.name = "reload_4";
		Islands[n].reload.l4.go = "Cayman_Shore_01";
		Islands[n].reload.l4.emerge = "reload1";
		Islands[n].reload.l4.radius = 200.0;
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l5.name = "reload1_2";  // Mirsaneli: was reload_1 which caused missing fort commander
		Islands[n].reload.l5.go = "Fort"; // KK
		Islands[n].reload.l5.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l5.emerge = "see";
		Islands[n].reload.l5.radius = 250.0;
		Islands[n].reload.l5.commander = "Grand Cayman Commander"; // KK
		Islands[n].reload.l5.fort.model = "Cayman_fort1";
		Islands[n].reload.l5.fort.locators = "Cayman_fort1_locators";
		Islands[n].reload.l5.tex = "t1";

//		Islands[n].reload.l6.label = "reload 5";
//		Islands[n].reload.l6.name = "reload_5";
//		Islands[n].reload.l6.go = "";
//		Islands[n].reload.l6.emerge = "";
//		Islands[n].reload.l6.radius = 200.0;
//		Islands[n].reload.l6.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_SANDAL;
		//Islands[n].Trade.Export.id2 = GOOD_RUM;
		//Islands[n].Trade.Export.id3 = GOOD_TOBACCO;
		//Islands[n].Trade.Import.id1 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id2 = GOOD_CHOCOLATE;
		//Islands[n].Trade.Import.id3 = GOOD_SILK;
		//Islands[n].Trade.Import.id4 = GOOD_LEATHER;
		//Islands[n].Trade.Contraband.id1 = GOOD_EBONY;
		//Islands[n].Trade.Contraband.id2 = GOOD_COFFEE;
		//Islands[n].Trade.Contraband.id3 = GOOD_PAPRIKA;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Hispaniola (Gaity)
		n = n + 1;
		Islands[n].id = "Hispaniola";
		Islands[n].model = "Gaity";
		Islands[n].filespath.models = "islands\Gaity";
		Islands[n].refl_model = "Gaity_refl";
		Islands[n].locators = "Gaity_locators";
		Islands[n].LoadGroup.g1 = "IslandShips1";
		Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name#"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "PoPrince_Port";
		Islands[n].reload.l1.emerge = "Reload2";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "#stown_name#"; // KK
		Islands[n].reload.l2.name = "reload_3";
		Islands[n].reload.l2.go = "Santo_Domingo_port";
		Islands[n].reload.l2.emerge = "Reload1";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";
		Islands[n].reload.l2.istown = true;

		Islands[n].reload.l3.label = "#stown_name# Port"; // KK
		Islands[n].reload.l3.name = "reload_7";
		Islands[n].reload.l3.go = "Tortuga_port";
		Islands[n].reload.l3.emerge = "Reload2";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";
		Islands[n].reload.l3.istown = true;

		Islands[n].reload.l4.label = "Boca de Yuman";
		Islands[n].reload.l4.name = "reload_2";
		Islands[n].reload.l4.go = "Hispaniola_shore_01";
		Islands[n].reload.l4.emerge = "Reload1";
		Islands[n].reload.l4.radius = 200.0;
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "Boca de Hubon";
		Islands[n].reload.l5.name = "reload_4";
		Islands[n].reload.l5.go = "Hispaniola_shore_02";
		Islands[n].reload.l5.emerge = "Reload1";
		Islands[n].reload.l5.radius = 200.0;
		Islands[n].reload.l5.tex = "t1";

		Islands[n].reload.l6.label = "Cape Francos";
		Islands[n].reload.l6.name = "reload_5";
		Islands[n].reload.l6.go = "Hispaniola_shore_03";
		Islands[n].reload.l6.emerge = "see";
		Islands[n].reload.l6.radius = 200.0;
		Islands[n].reload.l6.tex = "t1";

		Islands[n].reload.l7.label = "Ile a Vache";
		Islands[n].reload.l7.name = "reload_9";
		Islands[n].reload.l7.go = "Hispaniola_shore_04";
		Islands[n].reload.l7.emerge = "Reload1";
		Islands[n].reload.l7.radius = 200.0;
		Islands[n].reload.l7.tex = "t1";

		Islands[n].reload.l8.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l8.name = "reload1_2";
		Islands[n].reload.l8.go = "Fort"; // KK
		Islands[n].reload.l8.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l8.emerge = "see";
		Islands[n].reload.l8.radius = 250.0;
		Islands[n].reload.l8.commander = "Port au Prince Commander"; // KK
		Islands[n].reload.l8.fort.model = "Gaity_fort2";
		Islands[n].reload.l8.fort.locators = "Gaity_fort2_locators";
		Islands[n].reload.l8.tex = "t1";

		Islands[n].reload.l9.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l9.name = "reload_8";
		Islands[n].reload.l9.go = "Fort"; // KK
		Islands[n].reload.l9.GoAfterBoard.location = "reload_3";
		Islands[n].reload.l9.emerge = "see";
		Islands[n].reload.l9.radius = 250.0;
		Islands[n].reload.l9.commander = "Santo Domingo Commander"; // KK
		Islands[n].reload.l9.fort.model = "Gaity_fort1";
		Islands[n].reload.l9.fort.locators = "Gaity_fort1_locators";
		Islands[n].reload.l9.tex = "t1";

		Islands[n].reload.l10.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l10.name = "reload_6";
		Islands[n].reload.l10.go = "Fort"; // KK
		Islands[n].reload.l10.GoAfterBoard.location = "reload_7";
		Islands[n].reload.l10.emerge = "see";
		Islands[n].reload.l10.radius = 250.0;
		Islands[n].reload.l10.commander = "Tortuga Commander"; // KK
		Islands[n].reload.l10.fort.model = "Gaity_fort3";
		Islands[n].reload.l10.fort.locators = "Gaity_fort3_locators";
		Islands[n].reload.l10.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_EBONY;
		//Islands[n].Trade.Export.id2 = GOOD_MAHOGANY;
		//Islands[n].Trade.Export.id3 = GOOD_CINNAMON;
		//Islands[n].Trade.Export.id4 = GOOD_SANDAL;
		//Islands[n].Trade.Export.id5 = GOOD_GOLD;
		//Islands[n].Trade.Export.id6 = GOOD_SILVER;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id3 = GOOD_SUGAR;
		//Islands[n].Trade.Import.id4 = GOOD_LINEN;
		//Islands[n].Trade.Import.id5 = GOOD_TREATMENT;
		//Islands[n].Trade.Contraband.id1 = GOOD_ALE;
		//Islands[n].Trade.Contraband.id2 = GOOD_SILK;
		//Islands[n].Trade.Contraband.id3 = GOOD_TOBACCO;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Cuba
		n = n + 1;
		Islands[n].id = "Cuba";
		Islands[n].model = "Cuba";
		Islands[n].filespath.models = "islands\Cuba";
		Islands[n].refl_model = "Cuba_refl";
		Islands[n].locators = "Cuba_locators";
		Islands[n].LoadGroup.g1 = "IslandShips1";
		Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name#"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Santiago_port"; // KK
		Islands[n].reload.l1.emerge = "reload2"; // KK
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "#stown_name#"; // KK
		Islands[n].reload.l2.name = "reload_3";
		Islands[n].reload.l2.go = "Cuba_Port";
		Islands[n].reload.l2.emerge = "sea_2";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";
		Islands[n].reload.l2.istown = true;

// KK -->
		Islands[n].reload.l3.label = "Bahia de San Antonio";
		Islands[n].reload.l3.name = "reload_5";
		Islands[n].reload.l3.go = "Cuba_shore_01";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Bahia de Moa";
		Islands[n].reload.l4.name = "reload_2";
		Islands[n].reload.l4.go = "Cuba_shore_02";
		Islands[n].reload.l4.emerge = "Reload2";
		Islands[n].reload.l4.radius = 200.0;
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "Peninsula de Zapata";
		Islands[n].reload.l5.name = "reload_6";
		Islands[n].reload.l5.go = "Cuba_Shore_06";
		Islands[n].reload.l5.emerge = "Reload1";
		Islands[n].reload.l5.radius = 200.0;
		Islands[n].reload.l5.tex = "t1";

		Islands[n].reload.l6.label = "Punta de Maisi";
		Islands[n].reload.l6.name = "reload_7";
		Islands[n].reload.l6.go = "Cuba_Shore_03";
		Islands[n].reload.l6.emerge = "Reload1";
		Islands[n].reload.l6.radius = 200.0;
		Islands[n].reload.l6.tex = "t1";

		Islands[n].reload.l7.label = "Playa de Sierra Maestra";
		Islands[n].reload.l7.name = "reload_8";
		Islands[n].reload.l7.go = "Cuba_Shore_05";
		Islands[n].reload.l7.emerge = "Reload1";
		Islands[n].reload.l7.radius = 200.0;
		Islands[n].reload.l7.tex = "t1";
		Islands[n].reload.l7.enable = false;

		Islands[n].reload.l8.label = "Playa de Sabana";
		Islands[n].reload.l8.name = "reload_9";
		Islands[n].reload.l8.go = "Cuba_Shore_04";
		Islands[n].reload.l8.emerge = "Reload1";
		Islands[n].reload.l8.radius = 200.0;
		Islands[n].reload.l8.tex = "t1";
// <-- KK

		Islands[n].reload.l9.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l9.name = "reload1_2";
		Islands[n].reload.l9.go = "Fort"; // KK
		Islands[n].reload.l9.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l9.emerge = "see";
		Islands[n].reload.l9.radius = 250.0;
		Islands[n].reload.l9.commander = "Santiago Commander"; // KK
		Islands[n].reload.l9.fort.model = "Cuba_fort1";
		Islands[n].reload.l9.fort.locators = "Cuba_fort1_locators";
		Islands[n].reload.l9.tex = "t1";

		Islands[n].reload.l10.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l10.name = "reload_4";
		Islands[n].reload.l10.go = "Fort"; // KK
		Islands[n].reload.l10.GoAfterBoard.location = "reload_3";
		Islands[n].reload.l10.emerge = "see";
		Islands[n].reload.l10.radius = 250.0;
		Islands[n].reload.l10.commander = "Havana Commander"; // KK
		Islands[n].reload.l10.fort.model = "Cuba_fort2";
		Islands[n].reload.l10.fort.locators = "Cuba_fort2_locators";
		Islands[n].reload.l10.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_EBONY;
		//Islands[n].Trade.Export.id2 = GOOD_MAHOGANY;
		//Islands[n].Trade.Export.id3 = GOOD_CINNAMON;
		//Islands[n].Trade.Export.id4 = GOOD_SANDAL;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id3 = GOOD_SUGAR;
		//Islands[n].Trade.Import.id4 = GOOD_LINEN;
		//Islands[n].Trade.Import.id5 = GOOD_TREATMENT;
		//Islands[n].Trade.Contraband.id1 = GOOD_ALE;
		//Islands[n].Trade.Contraband.id2 = GOOD_SILK;
		//Islands[n].Trade.Contraband.id3 = GOOD_TOBACCO;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Guadeloupe
		n = n + 1;
		Islands[n].id = "Guadeloupe";
		Islands[n].model = "Guadelupa";
		Islands[n].filespath.models = "islands\Guadelupa";
		Islands[n].refl_model = "Guadelupa_refl";
		Islands[n].locators = "Guadelupa_locators";
		Islands[n].LoadGroup.g1 = "IslandShips1";
		Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name#"; // KK
		Islands[n].reload.l1.name = "reload_2";
		Islands[n].reload.l1.go = "Guadeloupe_Port";
		Islands[n].reload.l1.emerge = "reload2_back";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Anse Casse-Bois";
		Islands[n].reload.l2.name = "reload_3";
		Islands[n].reload.l2.go = "Guadeloupe_shore_01";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l3.name = "reload_1";
		Islands[n].reload.l3.go = "Fort"; // KK
		Islands[n].reload.l3.GoAfterBoard.location = "reload_2";
		Islands[n].reload.l3.emerge = "see";
		Islands[n].reload.l3.radius = 250.0;
		Islands[n].reload.l3.commander = "Pointe a Pitre Commander"; // KK
		Islands[n].reload.l3.fort.model = "Guadelupa_fort1";
		Islands[n].reload.l3.fort.locators = "Guadelupa_fort1_locators";
		Islands[n].reload.l3.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Export.id2 = GOOD_CHOCOLATE;
		//Islands[n].Trade.Export.id3 = GOOD_LINEN;
		//Islands[n].Trade.Export.id4 = GOOD_SILK;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_EBONY;
		//Islands[n].Trade.Import.id3 = GOOD_RUM;
		//Islands[n].Trade.Import.id4 = GOOD_LEATHER;
		//Islands[n].Trade.Import.id5 = GOOD_GOLD;
		//Islands[n].Trade.Import.id6 = GOOD_SILVER;
		//Islands[n].Trade.Contraband.id1 = GOOD_SANDAL;
		//Islands[n].Trade.Contraband.id2 = GOOD_FRUITS;
		//Islands[n].Trade.Contraband.id3 = GOOD_CINNAMON;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Saint Martin (SENT)	// changed by ccc Feb 06
		n = n + 1;
 Islands[n].id = "SaintMartin";
		Islands[n].model = "sent";
		Islands[n].filespath.models = "islands\sent";
		Islands[n].refl_model = "sent_refl";
		Islands[n].locators = "sent_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name#"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Philipsburg_port";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Fort Amsterdam";
		Islands[n].reload.l2.name = "reload1_2";
		Islands[n].reload.l2.go = "Fort"; // KK
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 250.0;
		Islands[n].reload.l2.commander = "Philipsburg Commander"; // KK
		Islands[n].reload.l2.fort.model = "Sent_fort2";
		Islands[n].reload.l2.fort.locators = "Sent_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "#stown_name#"; // KK
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Marigot_port";
		Islands[n].reload.l3.emerge = "sea";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";
		Islands[n].reload.l3.istown = true;

		Islands[n].reload.l4.label = "Fort St Louis";
		Islands[n].reload.l4.name = "reload_5";
		Islands[n].reload.l4.go = "Fort"; // KK
		Islands[n].reload.l4.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l4.emerge = "see";
		Islands[n].reload.l4.radius = 250.0;
		Islands[n].reload.l4.commander = "Marigot Commander"; // KK
		Islands[n].reload.l4.fort.model = "Sent_fort1";
		Islands[n].reload.l4.fort.locators = "Sent_fort2_locators";
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "Simpson Bay";
		Islands[n].reload.l5.name = "reload_2";
		Islands[n].reload.l5.go = "SaintMartin_shore_01";
		Islands[n].reload.l5.emerge = "reload1";
		Islands[n].reload.l5.radius = 200.0;
		Islands[n].reload.l5.tex = "t1";

		Islands[n].reload.l6.label = "Baie Orient";
		Islands[n].reload.l6.name = "reload_4";
		Islands[n].reload.l6.go = "SaintMartin_shore_02";
		Islands[n].reload.l6.emerge = "see";	// Akella's spelling ;)
		Islands[n].reload.l6.radius = 200.0;
		Islands[n].reload.l6.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Export.id2 = GOOD_CHOCOLATE;
		//Islands[n].Trade.Export.id3 = GOOD_LINEN;
		//Islands[n].Trade.Export.id4 = GOOD_SILK;
		//Islands[n].Trade.Export.id5 = GOOD_GOLD;
		//Islands[n].Trade.Export.id6 = GOOD_SILVER;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_EBONY;
		//Islands[n].Trade.Import.id3 = GOOD_RUM;
		//Islands[n].Trade.Import.id4 = GOOD_LEATHER;
		//Islands[n].Trade.Contraband.id1 = GOOD_SANDAL;
		//Islands[n].Trade.Contraband.id2 = GOOD_FRUITS;
		//Islands[n].Trade.Contraband.id3 = GOOD_CINNAMON; // KK

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Antigua	changed by ccc Jan 06
		n = n + 1;
 Islands[n].id = "Antigua";
		Islands[n].model = "Antigua";
		Islands[n].filespath.models = "islands\Antigua";
		Islands[n].refl_model = "Antigua_refl";
		Islands[n].locators = "Antigua_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "Fort James";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Fort"; // KK
		Islands[n].reload.l1.GoAfterBoard.location = "reload_2";
		Islands[n].reload.l1.emerge = "see";
		Islands[n].reload.l1.radius = 250.0;
		Islands[n].reload.l1.commander = "St John's Commander"; // KK
		Islands[n].reload.l1.fort.model = "Antigua_fort1";
		Islands[n].reload.l1.fort.locators = "Antigua_fort1_locators";
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "#stown_name#"; // KK
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "Antigua_port";
		Islands[n].reload.l2.emerge = "sea_2";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Muscetto Cove";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Antigua_shore";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		// victualler stores only ship supplies
		//Islands[n].Trade.Contraband.id1 = GOOD_CHOCOLATE;
		//Islands[n].Trade.Contraband.id2 = GOOD_SILK;
		//Islands[n].Trade.Contraband.id3 = GOOD_LEATHER;
		//Islands[n].Trade.Contraband.id4 = GOOD_EBONY;
		//Islands[n].Trade.Contraband.id5 = GOOD_COFFEE;
		//Islands[n].Trade.Contraband.id6 = GOOD_PAPRIKA;
		//Islands[n].Trade.Contraband.id7 = GOOD_SANDAL;
		//Islands[n].Trade.Contraband.id8 = GOOD_FRUITS;
		//Islands[n].Trade.Contraband.id9 = GOOD_CINNAMON;
		//Islands[n].Trade.Contraband.id10 = GOOD_TOBACCO;
		//Islands[n].Trade.Contraband.id11 = GOOD_ALE;
		//Islands[n].Trade.Contraband.id12 = GOOD_OIL;
		//Islands[n].Trade.Contraband.id13 = GOOD_COPRA;
		//Islands[n].Trade.Contraband.id14 = GOOD_WINE;
		//Islands[n].Trade.Contraband.id15 = GOOD_MAHOGANY;
		//Islands[n].Trade.Contraband.id16 = GOOD_SUGAR;
		//Islands[n].Trade.Contraband.id17 = GOOD_COTTON;
		//Islands[n].Trade.Contraband.id18 = GOOD_CLOTHES;
		//Islands[n].Trade.Contraband.id19 = GOOD_LINEN;
		//Islands[n].Trade.Contraband.id20 = GOOD_TREATMENT;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Turks
		n = n + 1;
 Islands[n].id = "Turks";
		Islands[n].model = "Terks";
		Islands[n].filespath.models = "islands\Terks";
		Islands[n].refl_model = "Terks_refl";
		Islands[n].locators = "Terks_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
// KK -->
// KK <--

		Islands[n].reload.l1.label = "#stown_name#"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Turks_Port";
		Islands[n].reload.l1.emerge = "Reload1";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Turtle Bay";
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "Turks_Lighthouse";
		Islands[n].reload.l2.emerge = "reload3";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";
		Islands[n].reload.l2.ships.l0.ay = 3.0;    // LDH 12Dec16

		Islands[n].reload.l3.label = "White reefs";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Turks_shore_01";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Sandy Point";
		Islands[n].reload.l4.name = "reload_4";
		Islands[n].reload.l4.go = "Turks_Shore_04";
		Islands[n].reload.l4.emerge = "reload3";
		Islands[n].reload.l4.radius = 200.0;
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "Birds Cove";
		Islands[n].reload.l5.name = "reload_5";
		Islands[n].reload.l5.go = "Turks_shore_05";
		Islands[n].reload.l5.emerge = "see";
		Islands[n].reload.l5.radius = 200.0;
		Islands[n].reload.l5.tex = "t1";

		Islands[n].reload.l6.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l6.name = "reload1_2";
		Islands[n].reload.l6.go = "Fort"; // KK
		Islands[n].reload.l6.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l6.emerge = "see";
		Islands[n].reload.l6.radius = 250.0;
		Islands[n].reload.l6.commander = "Grand Turk Commander"; // KK
		Islands[n].reload.l6.fort.model = "Terks_fort1";
		Islands[n].reload.l6.fort.locators = "Terks_fort1_locators";
		Islands[n].reload.l6.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

// KK -->
		//Islands[n].Trade.Export.id1 = GOOD_RUM;
		//Islands[n].Trade.Export.id2 = GOOD_WINE;
		//Islands[n].Trade.Export.id3 = GOOD_LEATHER;
		//Islands[n].Trade.Export.id4 = GOOD_FRUITS;
		//Islands[n].Trade.Import.id1 = GOOD_SUGAR;
		//Islands[n].Trade.Import.id2 = GOOD_TREATMENT;
		//Islands[n].Trade.Import.id3 = GOOD_GOLD;
		//Islands[n].Trade.Import.id4 = GOOD_SILVER;
// <-- KK

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

// KK -->
	// ==================================================================================================
	// Curacao
		n = n + 1;
 Islands[n].id = "Curacao";
		Islands[n].model = "Curacao";
		Islands[n].filespath.models = "islands\Curacao";
		Islands[n].refl_model = "Curacao_refl";
		Islands[n].locators = "Curacao_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name# Port"; // KK
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Willemstad_port";
		Islands[n].reload.l1.emerge = "sea";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Bullen Bay";
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "Curacao_shore_01";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Bocht Van Hato";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Curacao_shore_02";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";
		Islands[n].reload.l3.enable = false;

		Islands[n].reload.l4.label = "#stown_name# Fort"; // KK
		Islands[n].reload.l4.name = "reload_fort1";
		Islands[n].reload.l4.go = "Fort"; // KK
		Islands[n].reload.l4.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l4.emerge = "see";
		Islands[n].reload.l4.radius = 250.0;
		Islands[n].reload.l4.commander = "Willemstad Commander"; // KK
		Islands[n].reload.l4.fort.model = "Curacao_fort1";
		Islands[n].reload.l4.fort.locators = "Curacao_fort1_locators";
		Islands[n].reload.l4.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_TOBACCO;
		//Islands[n].Trade.Export.id2 = GOOD_COFFEE;
		//Islands[n].Trade.Export.id3 = GOOD_COPRA;
		//Islands[n].Trade.Export.id4 = GOOD_ALE;
		//Islands[n].Trade.Export.id5 = GOOD_FOOD;
		//Islands[n].Trade.Export.id6 = GOOD_TREATMENT;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id3 = GOOD_WHEAT;
		//Islands[n].Trade.Import.id4 = GOOD_GOLD;
		//Islands[n].Trade.Import.id5 = GOOD_SILVER;
		//Islands[n].Trade.Contraband.id1 = GOOD_SUGAR;
		//Islands[n].Trade.Contraband.id2 = GOOD_LINEN;
		//Islands[n].Trade.Contraband.id3 = GOOD_WINE;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Eleuthera
		n = n + 1;
		Islands[n].id = "Eleuthera";
		Islands[n].model = "Eleuthera";
		Islands[n].filespath.models = "islands\Eleuthera";
		Islands[n].refl_model = "Eleuthera_refl";
		Islands[n].locators = "Eleuthera_locators";
		Islands[n].LoadGroup.g1 = "IslandShips1";
		Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name# Port";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Eleuthera_Port";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "#stown_name# Fort";
		Islands[n].reload.l2.name = "reload_fort1";
		Islands[n].reload.l2.go = "Fort"; // KK
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 250.0;
		Islands[n].reload.l2.commander = "Eleuthera Commander";
		Islands[n].reload.l2.fort.model = "Eleuthera_fort1";
		Islands[n].reload.l2.fort.locators = "Eleuthera_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "#stown_name# Port";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "Alice_Port";
		Islands[n].reload.l3.emerge = "reload61";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";
		Islands[n].reload.l3.istown = true;

		//JRH
		Islands[n].reload.l4.label = "Citadel Rock";
		Islands[n].reload.l4.name = "reload_4";
		Islands[n].reload.l4.go = "Eleuthera_shore";
		Islands[n].reload.l4.emerge = "reload2";
		Islands[n].reload.l4.radius = 300.0;
		Islands[n].reload.l4.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_TOBACCO;
		//Islands[n].Trade.Export.id2 = GOOD_COFFEE;
		//Islands[n].Trade.Export.id3 = GOOD_COPRA;
		//Islands[n].Trade.Export.id4 = GOOD_ALE;
		//Islands[n].Trade.Export.id5 = GOOD_FOOD;
		//Islands[n].Trade.Export.id6 = GOOD_TREATMENT;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id3 = GOOD_WHEAT;
		//Islands[n].Trade.Import.id4 = GOOD_GOLD;
		//Islands[n].Trade.Import.id5 = GOOD_SILVER;
		//Islands[n].Trade.Import.id6 = GOOD_OIL;
		//Islands[n].Trade.Import.id7 = GOOD_BRICKS;
		//Islands[n].Trade.Import.id8 = GOOD_CLOTHES;
		//Islands[n].Trade.Contraband.id1 = GOOD_SUGAR;
		//Islands[n].Trade.Contraband.id2 = GOOD_LINEN;
		//Islands[n].Trade.Contraband.id3 = GOOD_WINE;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

	// ==================================================================================================
	// Aruba
		n = n + 1;
		Islands[n].id = "Aruba";
		Islands[n].model = "Aruba";
		Islands[n].filespath.models = "islands\Aruba";
		Islands[n].refl_model = "Aruba_refl";
		Islands[n].locators = "Aruba_locators";
		Islands[n].LoadGroup.g1 = "IslandShips1";
		Islands[n].visible = true;
		// NK -->
		// NK <--

		Islands[n].reload.l1.label = "#stown_name# Port";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Oranjestad_port";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Rocky Cove";
		Islands[n].reload.l2.name = "reload_3";
		Islands[n].reload.l2.go = "Aruba_shore";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		/*Islands[n].reload.l3.label = "#stown_name# Fort";
		Islands[n].reload.l3.name = "reload_1";
		Islands[n].reload.l3.go = "Fort"; // KK
		Islands[n].reload.l3.GoAfterBoard.location = "reload_2";
		Islands[n].reload.l3.emerge = "see";
		Islands[n].reload.l3.radius = 250.0;
		Islands[n].reload.l3.commander = "Oranjestad Commander"; // KK
		Islands[n].reload.l3.fort.model = "Aruba_fort1";
		Islands[n].reload.l3.fort.locators = "Aruba_fort1_locators";
		Islands[n].reload.l3.tex = "t1";
		Islands[n].reload.l3.ships.l0.x = -5.0;
		Islands[n].reload.l3.ships.l0.z = -150.0;
		Islands[n].reload.l3.ships.l0.ay = 0.0; */

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		//Islands[n].Trade.Export.id1 = GOOD_TOBACCO;
		//Islands[n].Trade.Export.id2 = GOOD_COFFEE;
		//Islands[n].Trade.Export.id3 = GOOD_COPRA;
		//Islands[n].Trade.Export.id4 = GOOD_ALE;
		//Islands[n].Trade.Export.id5 = GOOD_FOOD;
		//Islands[n].Trade.Export.id6 = GOOD_TREATMENT;
		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id3 = GOOD_WHEAT;
		//Islands[n].Trade.Import.id4 = GOOD_GOLD;
		//Islands[n].Trade.Import.id5 = GOOD_SILVER;
		//Islands[n].Trade.Contraband.id1 = GOOD_SUGAR;
		//Islands[n].Trade.Contraband.id2 = GOOD_LINEN;
		//Islands[n].Trade.Contraband.id3 = GOOD_WINE;

				SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
// <-- KK


	/////////////////////////////////////////////////////////////////////////
	/// PortoBello   (Mein)
	/////////////////////////////////////////////////////////////////////////
		n = n + 1;
		Islands[n].id = "PortoBello";
		Islands[n].model = "PortoBello";
		Islands[n].filespath.models = "islands\PortoBello";
		Islands[n].refl_model = "PortoBello_refl";
		Islands[n].locators = "PortoBello_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		Islands[n].jungle.patch = "PortoBello_jungles";
		Islands[n].jungle.texture = "junglesprites";
		Islands[n].jungle.scale = 12.5;
		//Islands[n].ImmersionDistance = 4000;
		//Islands[n].ImmersionDepth = 250;
		Islands[n].TexturePath = "PortoBello";

		Islands[n].reload.l1.label = "PortoBello Port";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "PortoBello_town";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "PortoBello Fort";
		Islands[n].reload.l2.name = "reload_fort1";
		Islands[n].reload.l2.go = "PortoBello_fort";
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 600.0;
		Islands[n].reload.l2.fortname = "fort_PortoBello";
		Islands[n].reload.l2.colonyname = "PortoBello";
		Islands[n].reload.l2.fort.model = "PortoBello_fort1";
		Islands[n].reload.l2.fort.locators = "PortoBello_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Shore46";
		Islands[n].reload.l3.name = "reload_2";
		Islands[n].reload.l3.go = "Shore46";
		Islands[n].reload.l3.emerge = "sea";
		Islands[n].reload.l3.radius = 600.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Shore47";
		Islands[n].reload.l4.name = "reload_3";
		Islands[n].reload.l4.go = "Shore47";
		Islands[n].reload.l4.emerge = "sea";
		Islands[n].reload.l4.radius = 600.0;
		Islands[n].reload.l4.tex = "t1";
		
		Islands[n].reload.l5.label = "Shore48";
		Islands[n].reload.l5.name = "reload_4";
		Islands[n].reload.l5.go = "Shore48";
		Islands[n].reload.l5.emerge = "sea";
		Islands[n].reload.l5.radius = 600.0;
		Islands[n].reload.l5.tex = "t1";
		
	    //Islands[n].Trade.Export.id1 = GOOD_MEDICAMENT;
		//Islands[n].Trade.Export.id2 = GOOD_OIL;
		//Islands[n].Trade.Export.id3 = GOOD_WINE;
		//Islands[n].Trade.Export.id4 = GOOD_SUGAR;
		//Islands[n].Trade.Export.id5 = GOOD_ALE;
		//Islands[n].Trade.Export.id6 = GOOD_LINEN;
		//Islands[n].Trade.Export.id7 = GOOD_CINNAMON;

		//Islands[n].Trade.Import.id1 = GOOD_RUM;
		//Islands[n].Trade.Import.id2 = GOOD_BALLS;
		//Islands[n].Trade.Import.id3 = GOOD_SILK;
		//Islands[n].Trade.Import.id4 = GOOD_PAPRIKA;
		//Islands[n].Trade.Import.id5 = GOOD_SANDAL;
		//Islands[n].Trade.Import.id6 = GOOD_LEATHER;
		//Islands[n].Trade.Import.id7 = GOOD_SAILCLOTH;

		//Islands[n].Trade.Contraband.id1 = GOOD_SLAVES;
		//Islands[n].Trade.Contraband.id2 = GOOD_BRICK;
		//Islands[n].Trade.Contraband.id3 = GOOD_COPRA;
        //Islands[n].Trade.Contraband.id4 = GOOD_FRUITS;
        //Islands[n].Trade.Contraband.id5 = GOOD_CLOTHES;

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
	/////////////////////////////////////////////////////////////////////////
	/// Cartahena   (Mein)
	/////////////////////////////////////////////////////////////////////////
		n = n + 1;
		Islands[n].id = "Cartahena";
		Islands[n].model = "Cartahena";
		Islands[n].filespath.models = "islands\Cartahena";
		Islands[n].refl_model = "Cartahena_refl";
		Islands[n].locators = "Cartahena_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		Islands[n].jungle.patch = "Cartahena_jungles";
		Islands[n].jungle.texture = "junglesprites";
		Islands[n].jungle.scale = 10.0;
		//Islands[n].ImmersionDistance = 4000;
		//Islands[n].ImmersionDepth = 250;
		Islands[n].TexturePath = "Cartahena";

		Islands[n].reload.l1.label = "Cartahena Port";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Cartahena_town";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Cartahena Fort";
		Islands[n].reload.l2.name = "reload_fort1";
		Islands[n].reload.l2.go = "Cartahena_fort";
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 600.0;
		Islands[n].reload.l2.fortname = "fort_Cartahena";
		Islands[n].reload.l2.colonyname = "Cartahena";
		Islands[n].reload.l2.fort.model = "Cartahena_fort1";
		Islands[n].reload.l2.fort.locators = "Cartahena_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Shore25";
		Islands[n].reload.l3.name = "reload_2";
		Islands[n].reload.l3.go = "Shore25";
		Islands[n].reload.l3.emerge = "sea";
		Islands[n].reload.l3.radius = 600.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Mayak11";
		Islands[n].reload.l4.name = "reload_3";
		Islands[n].reload.l4.go = "Mayak11";
		Islands[n].reload.l4.emerge = "sea";
		Islands[n].reload.l4.radius = 600.0;
		Islands[n].reload.l4.tex = "t1";
		
        //Islands[n].Trade.Export.id1 = GOOD_WHEAT;
		//Islands[n].Trade.Export.id2 = GOOD_CHOCOLATE;
		//Islands[n].Trade.Export.id3 = GOOD_GRAPES;
		//Islands[n].Trade.Export.id4 = GOOD_OIL;
		//Islands[n].Trade.Export.id5 = GOOD_PLANKS;
		//Islands[n].Trade.Export.id6 = GOOD_COTTON;
		//Islands[n].Trade.Export.id7 = GOOD_EBONY;

		//Islands[n].Trade.Import.id1 = GOOD_CLOTHES;
		//Islands[n].Trade.Import.id2 = GOOD_COFFEE;
		//Islands[n].Trade.Import.id3 = GOOD_MEDICAMENT;
		//Islands[n].Trade.Import.id4 = GOOD_RUM;
		//Islands[n].Trade.Import.id5 = GOOD_FRUITS;
		//Islands[n].Trade.Import.id6 = GOOD_LEATHER;
		//Islands[n].Trade.Import.id7 = GOOD_TOBACCO;

		//Islands[n].Trade.Contraband.id1 = GOOD_SLAVES;
		//Islands[n].Trade.Contraband.id2 = GOOD_BRICK;
		//Islands[n].Trade.Contraband.id3 = GOOD_SAILCLOTH;
        //Islands[n].Trade.Contraband.id4 = GOOD_PAPRIKA;
        //Islands[n].Trade.Contraband.id5 = GOOD_SILK;
        
		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
	/////////////////////////////////////////////////////////////////////////
	/// Maracaibo   (Mein)
	/////////////////////////////////////////////////////////////////////////
		n = n + 1;
		Islands[n].id = "Maracaibo";
		Islands[n].model = "Maracaibo";
		Islands[n].filespath.models = "islands\Maracaibo";
		Islands[n].refl_model = "Maracaibo_refl";
		Islands[n].locators = "Maracaibo_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		Islands[n].jungle.patch = "Maracaibo_jungles";
		Islands[n].jungle.texture = "junglesprites";
		Islands[n].jungle.scale = 10.0;
		//Islands[n].ImmersionDistance = 4000;
		//Islands[n].ImmersionDepth = 250;
		Islands[n].TexturePath = "Maracaibo";

		Islands[n].reload.l1.label = "Maracaibo Port";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Maracaibo_town";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Maracaibo Fort";
		Islands[n].reload.l2.name = "reload_fort1";
		Islands[n].reload.l2.go = "Maracaibo_fort";
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 600.0;
		Islands[n].reload.l2.fortname = "fort_Maracaibo";
		Islands[n].reload.l2.colonyname = "Maracaibo";
		Islands[n].reload.l2.fort.model = "Maracaibo_fort1";
		Islands[n].reload.l2.fort.locators = "Maracaibo_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Shore37";
		Islands[n].reload.l3.name = "reload_2";
		Islands[n].reload.l3.go = "Shore37";
		Islands[n].reload.l3.emerge = "sea";
		Islands[n].reload.l3.radius = 600.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Shore_ship3";
		Islands[n].reload.l4.name = "reload_3";
		Islands[n].reload.l4.go = "Shore_ship3";
		Islands[n].reload.l4.emerge = "sea";
		Islands[n].reload.l4.radius = 600.0;
		Islands[n].reload.l4.tex = "t1";

        //Islands[n].Trade.Export.id1 = GOOD_GOLD;
		//Islands[n].Trade.Export.id2 = GOOD_SILVER;
		//Islands[n].Trade.Export.id3 = GOOD_MAHOGANY;
		//Islands[n].Trade.Export.id4 = GOOD_EBONY;
		//Islands[n].Trade.Export.id5 = GOOD_PLANKS;
		//Islands[n].Trade.Export.id6 = GOOD_SANDAL;
		//Islands[n].Trade.Export.id7 = GOOD_SUGAR;

		//Islands[n].Trade.Import.id1 = GOOD_CLOTHES;
		//Islands[n].Trade.Import.id2 = GOOD_BRICK;
		//Islands[n].Trade.Import.id3 = GOOD_MEDICAMENT;
		//Islands[n].Trade.Import.id4 = GOOD_RUM;
		//Islands[n].Trade.Import.id5 = GOOD_FRUITS;
		//Islands[n].Trade.Import.id6 = GOOD_WINE;
		//Islands[n].Trade.Import.id7 = GOOD_WHEAT;

		//Islands[n].Trade.Contraband.id1 = GOOD_SLAVES;
		//Islands[n].Trade.Contraband.id2 = GOOD_WEAPON;
		//Islands[n].Trade.Contraband.id3 = GOOD_POWDER;
        //Islands[n].Trade.Contraband.id4 = GOOD_FOOD;
        //Islands[n].Trade.Contraband.id5 = GOOD_LEATHER;
        
		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
	/////////////////////////////////////////////////////////////////////////
	/// Caracas   (Mein)
	/////////////////////////////////////////////////////////////////////////
		n = n + 1;
		Islands[n].id = "Caracas";
		Islands[n].model = "Caracas";
		Islands[n].filespath.models = "islands\Caracas";
		Islands[n].refl_model = "Caracas_refl";
		Islands[n].locators = "Caracas_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		Islands[n].jungle.patch = "Caracas_jungles";
		Islands[n].jungle.texture = "junglesprites";
		Islands[n].jungle.scale = 10.0;
		//Islands[n].ImmersionDistance = 4000;
		//Islands[n].ImmersionDepth = 250;
		Islands[n].TexturePath = "Caracas";

		Islands[n].reload.l1.label = "Caracas Port";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Caracas_town";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Caracas Fort";
		Islands[n].reload.l2.name = "reload_fort1";
		Islands[n].reload.l2.go = "Caracas_fort";
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 600.0;
		Islands[n].reload.l2.fortname = "fort_Caracas";
		Islands[n].reload.l2.colonyname = "Caracas";
		Islands[n].reload.l2.fort.model = "Caracas_fort1";
		Islands[n].reload.l2.fort.locators = "Caracas_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Shore21";
		Islands[n].reload.l3.name = "reload_2";
		Islands[n].reload.l3.go = "Shore21";
		Islands[n].reload.l3.emerge = "sea";
		Islands[n].reload.l3.radius = 600.0;
		Islands[n].reload.l3.tex = "t1";
		
        //Islands[n].Trade.Export.id1 = GOOD_COFFEE;
		//Islands[n].Trade.Export.id2 = GOOD_COTTON;
		//Islands[n].Trade.Export.id3 = GOOD_CLOTHES;
		//Islands[n].Trade.Export.id4 = GOOD_SUGAR;
		//Islands[n].Trade.Export.id5 = GOOD_COPRA;
		//Islands[n].Trade.Export.id6 = GOOD_ALE;
		//Islands[n].Trade.Export.id7 = GOOD_PLANKS;

		//Islands[n].Trade.Import.id1 = GOOD_BALLS;
		//Islands[n].Trade.Import.id2 = GOOD_GRAPES;
		//Islands[n].Trade.Import.id3 = GOOD_KNIPPELS;
		//Islands[n].Trade.Import.id4 = GOOD_BOMBS;
		//Islands[n].Trade.Import.id5 = GOOD_POWDER;
		//Islands[n].Trade.Import.id6 = GOOD_MEDICAMENT;
		//Islands[n].Trade.Import.id7 = GOOD_WEAPON;

		//Islands[n].Trade.Contraband.id1 = GOOD_SLAVES;
		//Islands[n].Trade.Contraband.id2 = GOOD_LEATHER;
		//Islands[n].Trade.Contraband.id3 = GOOD_WINE;
        //Islands[n].Trade.Contraband.id4 = GOOD_RUM;
        //Islands[n].Trade.Contraband.id5 = GOOD_TOBACCO;
         
		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
	/////////////////////////////////////////////////////////////////////////
	/// Cumana   (Mein)
	/////////////////////////////////////////////////////////////////////////
		n = n + 1;
		Islands[n].id = "Cumana";
		Islands[n].model = "Cumana";
		Islands[n].filespath.models = "islands\Cumana";
		Islands[n].refl_model = "Cumana_refl";
		Islands[n].locators = "Cumana_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		Islands[n].jungle.patch = "Cumana_jungles";
		Islands[n].jungle.texture = "junglesprites";
		Islands[n].jungle.scale = 10.0;
		//Islands[n].ImmersionDistance = 4000;
		//Islands[n].ImmersionDepth = 250;
		Islands[n].TexturePath = "Cumana";

		Islands[n].reload.l1.label = "Cumana Port";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Cumana_town";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Cumana Fort";
		Islands[n].reload.l2.name = "reload_fort1";
		Islands[n].reload.l2.go = "Cumana_fort";
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 600.0;
		Islands[n].reload.l2.fortname = "fort_Cumana";
		Islands[n].reload.l2.colonyname = "Cumana";
		Islands[n].reload.l2.fort.model = "Cumana_fort1";
		Islands[n].reload.l2.fort.locators = "Cumana_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Shore20";
		Islands[n].reload.l3.name = "reload_2";
		Islands[n].reload.l3.go = "Shore20";
		Islands[n].reload.l3.emerge = "sea";
		Islands[n].reload.l3.radius = 600.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Shore19";
		Islands[n].reload.l4.name = "reload_3";
		Islands[n].reload.l4.go = "Shore19";
		Islands[n].reload.l4.emerge = "sea";
		Islands[n].reload.l4.radius = 600.0;
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "Shore18";
		Islands[n].reload.l5.name = "reload_4";
		Islands[n].reload.l5.go = "Shore18";
		Islands[n].reload.l5.emerge = "sea";
		Islands[n].reload.l5.radius = 600.0;
		Islands[n].reload.l5.tex = "t1"; 

        // boal 16.04.04 -->
		//Islands[n].Trade.Export.id1 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Export.id2 = GOOD_WHEAT;
		//Islands[n].Trade.Export.id3 = GOOD_LINEN;
		//Islands[n].Trade.Export.id4 = GOOD_SANDAL;
		//Islands[n].Trade.Export.id5 = GOOD_EBONY;
		//Islands[n].Trade.Export.id6 = GOOD_OIL;
		//Islands[n].Trade.Export.id7 = GOOD_COFFEE;

		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_WINE;
		//Islands[n].Trade.Import.id3 = GOOD_RUM;
		//Islands[n].Trade.Import.id4 = GOOD_CHOCOLATE;
		//Islands[n].Trade.Import.id5 = GOOD_PAPRIKA;
		//Islands[n].Trade.Import.id6 = GOOD_GOLD;
		//Islands[n].Trade.Import.id7 = GOOD_SILVER;

		//Islands[n].Trade.Contraband.id1 = GOOD_SLAVES;
		//Islands[n].Trade.Contraband.id2 = GOOD_CINNAMON;
		//Islands[n].Trade.Contraband.id3 = GOOD_MEDICAMENT;
        //Islands[n].Trade.Contraband.id4 = GOOD_SILK;
        //Islands[n].Trade.Contraband.id5 = GOOD_FRUITS;
        // boal 16.04.04 <--
		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
		
	/////////////////////////////////////////////////////////////////////////
	/// SantaCatalina   (Mein)
	/////////////////////////////////////////////////////////////////////////
		n = n + 1;
		Islands[n].id = "SantaCatalina";
		Islands[n].model = "SantaCatalina";
		Islands[n].filespath.models = "islands\SantaCatalina";
		Islands[n].refl_model = "SantaCatalina_refl";
		Islands[n].locators = "SantaCatalina_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		Islands[n].jungle.patch = "SantaCatalina_jungles";
		Islands[n].jungle.texture = "junglesprites";
		Islands[n].jungle.scale = 16.0;
		//Islands[n].ImmersionDistance = 4000;
		//Islands[n].ImmersionDepth = 250;
		Islands[n].TexturePath = "SantaCatalina";

		Islands[n].reload.l1.label = "SantaCatalina Port";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "SantaCatalina_town";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "SantaCatalina Fort";
		Islands[n].reload.l2.name = "reload_fort1";
		Islands[n].reload.l2.go = "SantaCatalina_fort";
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 600.0;
		Islands[n].reload.l2.fortname = "fort_SantaCatalina";
		Islands[n].reload.l2.colonyname = "SantaCatalina";
		Islands[n].reload.l2.fort.model = "SantaCatalina_fort1";
		Islands[n].reload.l2.fort.locators = "SantaCatalina_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Shore53";
		Islands[n].reload.l3.name = "reload_2";
		Islands[n].reload.l3.go = "Shore53";
		Islands[n].reload.l3.emerge = "sea";
		Islands[n].reload.l3.radius = 600.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Shore54";
		Islands[n].reload.l4.name = "reload_3";
		Islands[n].reload.l4.go = "Shore54";
		Islands[n].reload.l4.emerge = "sea";
		Islands[n].reload.l4.radius = 600.0;
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "Shore55";
		Islands[n].reload.l5.name = "reload_4";
		Islands[n].reload.l5.go = "Shore55";
		Islands[n].reload.l5.emerge = "sea";
		Islands[n].reload.l5.radius = 600.0;
		Islands[n].reload.l5.tex = "t1";

	    //Islands[n].Trade.Export.id1 = GOOD_BALLS;
		//Islands[n].Trade.Export.id2 = GOOD_GRAPES;
		//Islands[n].Trade.Export.id3 = GOOD_KNIPPELS;
		//Islands[n].Trade.Export.id4 = GOOD_BOMBS;
		//Islands[n].Trade.Export.id5 = GOOD_POWDER;
		//Islands[n].Trade.Export.id6 = GOOD_WINE;
		//Islands[n].Trade.Export.id7 = GOOD_WEAPON;

		//Islands[n].Trade.Import.id1 = GOOD_SILK;
		//Islands[n].Trade.Import.id2 = GOOD_COTTON;
		//Islands[n].Trade.Import.id3 = GOOD_SAILCLOTH;
		//Islands[n].Trade.Import.id4 = GOOD_CLOTHES;
		//Islands[n].Trade.Import.id5 = GOOD_TOBACCO;
		//Islands[n].Trade.Import.id6 = GOOD_GOLD;
		//Islands[n].Trade.Import.id7 = GOOD_SILVER;

		//Islands[n].Trade.Contraband.id1 = GOOD_SLAVES;
		//Islands[n].Trade.Contraband.id2 = GOOD_COPRA;
		//Islands[n].Trade.Contraband.id3 = GOOD_PAPRIKA;
        //Islands[n].Trade.Contraband.id4 = GOOD_SANDAL;
        //Islands[n].Trade.Contraband.id5 = GOOD_LEATHER;

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
	/////////////////////////////////////////////////////////////////////////
	/// Beliz   (Mein)
	/////////////////////////////////////////////////////////////////////////
		n = n + 1;
		Islands[n].id = "Beliz";
		Islands[n].model = "Beliz";
		Islands[n].filespath.models = "islands\Beliz";
		Islands[n].refl_model = "Beliz_refl";
		Islands[n].locators = "Beliz_locators";
Islands[n].LoadGroup.g1 = "IslandShips1";
Islands[n].visible = true;
		Islands[n].jungle.patch = "Beliz_jungles";
		Islands[n].jungle.texture = "junglesprites";
		Islands[n].jungle.scale = 16;
		//Islands[n].ImmersionDistance = 4000;
		//Islands[n].ImmersionDepth = 250;
		Islands[n].TexturePath = "Beliz";

		Islands[n].reload.l1.label = "Beliz Port";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "Beliz_town";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "Beliz Fort";
		Islands[n].reload.l2.name = "reload_fort1";
		Islands[n].reload.l2.go = "Beliz_fort";
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 600.0;
		Islands[n].reload.l2.fortname = "fort_Beliz";
		Islands[n].reload.l2.colonyname = "Beliz";
		Islands[n].reload.l2.fort.model = "Beliz_fort1";
		Islands[n].reload.l2.fort.locators = "Beliz_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Shore8";
		Islands[n].reload.l3.name = "reload_2";
		Islands[n].reload.l3.go = "Shore8";
		Islands[n].reload.l3.emerge = "sea";
		Islands[n].reload.l3.radius = 600.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].reload.l4.label = "Shore7";
		Islands[n].reload.l4.name = "reload_3";
		Islands[n].reload.l4.go = "Shore7";
		Islands[n].reload.l4.emerge = "sea";
		Islands[n].reload.l4.radius = 600.0;
		Islands[n].reload.l4.tex = "t1";

		Islands[n].reload.l5.label = "Shore6";
		Islands[n].reload.l5.name = "reload_4";
		Islands[n].reload.l5.go = "Shore6";
		Islands[n].reload.l5.emerge = "sea";
		Islands[n].reload.l5.radius = 600.0;
		Islands[n].reload.l5.tex = "t1";

		Islands[n].reload.l6.label = "Shore_ship2";
		Islands[n].reload.l6.name = "reload_5";
		Islands[n].reload.l6.go = "Shore_ship2";
		Islands[n].reload.l6.emerge = "sea";
		Islands[n].reload.l6.radius = 600.0;
		Islands[n].reload.l6.tex = "t1";

		Islands[n].reload.l7.label = "Shore9";
		Islands[n].reload.l7.name = "reload_6";
		Islands[n].reload.l7.go = "Shore9";
		Islands[n].reload.l7.emerge = "sea";
		Islands[n].reload.l7.radius = 600.0;
		Islands[n].reload.l7.tex = "t1";

		Islands[n].reload.l8.label = "Shore10";
		Islands[n].reload.l8.name = "reload_7";
		Islands[n].reload.l8.go = "Shore10";
		Islands[n].reload.l8.emerge = "sea";
		Islands[n].reload.l8.radius = 600.0;
		Islands[n].reload.l8.tex = "t1";

        //Islands[n].Trade.Export.id1 = GOOD_SILVER;
		//Islands[n].Trade.Export.id2 = GOOD_EBONY;
		//Islands[n].Trade.Export.id3 = GOOD_CINNAMON;
		//Islands[n].Trade.Export.id4 = GOOD_WINE;
		//Islands[n].Trade.Export.id5 = GOOD_RUM;
		//Islands[n].Trade.Export.id6 = GOOD_WHEAT;
		//Islands[n].Trade.Export.id7 = GOOD_COTTON;

		//Islands[n].Trade.Import.id1 = GOOD_PLANKS;
		//Islands[n].Trade.Import.id2 = GOOD_WEAPON;
		//Islands[n].Trade.Import.id3 = GOOD_SANDAL;
		//Islands[n].Trade.Import.id4 = GOOD_PAPRIKA;
		//Islands[n].Trade.Import.id5 = GOOD_TOBACCO;
		//Islands[n].Trade.Import.id6 = GOOD_LINEN;
		//Islands[n].Trade.Import.id7 = GOOD_CHOCOLATE;

		//Islands[n].Trade.Contraband.id1 = GOOD_SLAVES;
		//Islands[n].Trade.Contraband.id2 = GOOD_OIL;
		//Islands[n].Trade.Contraband.id3 = GOOD_SAILCLOTH;
        //Islands[n].Trade.Contraband.id4 = GOOD_COFFEE;
        //Islands[n].Trade.Contraband.id5 = GOOD_LEATHER;

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

        // boal 28.01.2004 -->
        //Islands[n].Trade.Contraband.id1 = GOOD_SLAVES;
        // boal 28.01.2004 <--
		
		/////////////////////////////////////////////////////////////////////////
	/// ГПК
	/////////////////////////////////////////////////////////////////////////
		n = n + 1;
		Islands[n].id = "LostShipsCity";
		Islands[n].model = "LostShipsCity";
		Islands[n].filespath.models = "islands\LostShipsCity";
		Islands[n].refl_model = "LostShipsCity_refl";
		Islands[n].locators = "LostShipsCity_locators";
		Islands[n].visible = false;
		Islands[n].reload_enable = false;
		Islands[n].TexturePath = "LostShipsCity";

		Islands[n].reload.l1.label = "LSC North";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "LostShipsCity_town";
		Islands[n].reload.l1.emerge = "reload1_back";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.pic = 0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true; 

		Islands[n].reload.l2.label = "LSC South";
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "LostShipsCity_town";
		Islands[n].reload.l2.emerge = "reload1_back";
		Islands[n].reload.l2.radius = 600.0;
		Islands[n].reload.l2.pic = 0;
		Islands[n].reload.l2.tex = "t1";
		Islands[n].reload.l2.istown = true;

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
		
		// ==================================================================================================
	// Petit Tabac
		n = n + 1;
		Islands[n].id = "Battle_Rocks";
		Islands[n].model = "Dominica";
		Islands[n].filespath.models = "islands\Dominica";
		Islands[n].refl_model = "dominica_refl";
		Islands[n].locators = "dominica_locators";
		Islands[n].visible = false;

		Islands[n].reload.l1.label = "Devil Creek";
		Islands[n].reload.l1.name = "reload_2";
		Islands[n].reload.l1.go = "Devil_Creek";
		Islands[n].reload.l1.emerge = "see";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.enable = false;

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);

		// ==================================================================================================
	// Isla Mona
		n = n + 1;
		Islands[n].id = "IslaMona";
		Islands[n].model = "islamona";
		Islands[n].filespath.models = "islands\IslaDeMuerte";
		Islands[n].refl_model = "islamona_refl";
		Islands[n].locators = "islamona_locators";
		Islands[n].visible = false;

		Islands[n].reload.l1.label = "Isla Mona Shore";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "IslaMona_port";
		Islands[n].reload.l1.emerge = "Reload3";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.enable = false;
		Islands[n].reload.l1.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
		
		// ==================================================================================================
	// Isla de Muerte
		n = n + 1;
		Islands[n].id = "IslaDeMuerte";
		Islands[n].model = "islamona";
		Islands[n].filespath.models = "islands\IslaDeMuerte";
		Islands[n].refl_model = "islamona_refl";
		Islands[n].locators = "islamona_locators";
		Islands[n].reload_enable = false;
		Islands[n].visible = false;

		Islands[n].reload.l1.label = "Deserted shore";
		Islands[n].reload.l1.name = "reload_1";
		Islands[n].reload.l1.go = "IslaDeMuerte_shore_01";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 200.0;
		Islands[n].reload.l1.tex = "t1";

		Islands[n].reload.l2.label = "Dead Man's Bay";
		Islands[n].reload.l2.name = "reload_2";
		Islands[n].reload.l2.go = "IslaDeMuerte_shore_02";
		Islands[n].reload.l2.emerge = "sea_back";
		Islands[n].reload.l2.radius = 200.0;
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Witch's Rock";
		Islands[n].reload.l3.name = "reload_3";
		Islands[n].reload.l3.go = "IslaDeMuerte_shore_03";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 200.0;
		Islands[n].reload.l3.tex = "t1";

	Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
		/////////////////////////////////////////////////////////////////////////
	/// StKitts
	/////////////////////////////////////////////////////////////////////////
		n = n + 1;
		Islands[n].id = "StKitts";
		Islands[n].model = "StKitts";
		Islands[n].filespath.models = "islands\StKitts";
		Islands[n].refl_model = "StKitts_refl";
		Islands[n].locators = "StKitts_locators";
		Islands[n].visible = true;
		Islands[n].net = true;
		Islands[n].LoadGroup.g1 = "IslandShips1";
		//Islands[n].ImmersionDistance = 4000;
		//Islands[n].ImmersionDepth = 250;
		Islands[n].TexturePath = "StKitts";

		Islands[n].reload.l1.label = "StKitts Port";
		Islands[n].reload.l1.name = "Reload_1";
		Islands[n].reload.l1.go = "StKitts_town";
		Islands[n].reload.l1.emerge = "reload1";
		Islands[n].reload.l1.radius = 600.0;
		Islands[n].reload.l1.tex = "t1";
		Islands[n].reload.l1.istown = true;

		Islands[n].reload.l2.label = "StKitts Fort";
		Islands[n].reload.l2.name = "Reload_fort1";
		Islands[n].reload.l2.go = "StKitts_fort";
		Islands[n].reload.l2.GoAfterBoard.location = "reload_1";
		Islands[n].reload.l2.emerge = "see";
		Islands[n].reload.l2.radius = 600.0;
		Islands[n].reload.l2.fortname = "fort_StKitts";
		Islands[n].reload.l2.colonyname = "StKitts";
		Islands[n].reload.l2.fort.model = "StKitts_fort1";
		Islands[n].reload.l2.fort.locators = "StKitts_fort1_locators";
		Islands[n].reload.l2.tex = "t1";

		Islands[n].reload.l3.label = "Shore_15";
		Islands[n].reload.l3.name = "Reload_3";
		Islands[n].reload.l3.go = "StKitts_shore_1";
		Islands[n].reload.l3.emerge = "reload1";
		Islands[n].reload.l3.radius = 600.0;
		Islands[n].reload.l3.tex = "t1";

		Islands[n].InterfaceTextures.t1 = "battle_interface\moor_7.tga";
		Islands[n].InterfaceTextures.t1.h = 4;
		Islands[n].InterfaceTextures.t1.v = 1;

		SendMessage(&locator,"le",LM_LOCATE_I,&Islands[n]);
		
iNumIslands = n;
		Trace("How islands = " + iNumIslands);
		/////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////
		
		DeleteClass(&locator);		
}
