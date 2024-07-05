/////////////////////////
// GOF 1.2
/////////////////////////

/// Luke159 added new calibure cannon and culverines
/// Luke159 Added switch to reload times
/// Luke159 Added switch to damage multiplyer
/// Luke159 Reduced range of cannon and culverines
/// Luke159 Increased weight of culverines
/// Luke159 Increased prices of cannons and culverines

void InitBaseCannons_CalcSpeedV0(ref rCannon, float fFireRange)
{
	rCannon.FireRange = fFireRange;
	rCannon.SpeedV0 = sqrt(fFireRange * 9.81 / sin( 2.0 * MakeFloat(rCannon.FireAngMax)) );
}

void InitCannons()
{
    ref rCannon;

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS4]);
    rCannon.type = CANNON_NAME_CULVERINE;
    rCannon.name = "caliber4";
    rCannon.picture = "cannons1";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 4;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 10;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 5.7;
    }
    rCannon.Cost = 800;
    rCannon.Weight = 12;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 0.2;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 2.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 1.0;
    }
    rCannon.hp = 40.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,400.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS8]);
    rCannon.type = CANNON_NAME_CULVERINE;
    rCannon.name = "caliber8";
    rCannon.picture = "cannons2";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 8;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 20;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 7.2;
    }
    rCannon.Cost = 1100;
    rCannon.Weight = 15;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 0.4;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 2.5;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 1.6;
    }
    rCannon.hp = 45.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,400.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS12]);
    rCannon.type = CANNON_NAME_CULVERINE;
    rCannon.name = "caliber12";
    rCannon.picture = "cannons3";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 12;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 30;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 8.5;
    }
    rCannon.Cost = 1400;
    rCannon.Weight = 18;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 0.6;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 3.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 2.0;
    }
    rCannon.hp = 50.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,450.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS16]);
    rCannon.type = CANNON_NAME_CULVERINE;
    rCannon.name = "caliber16";
    rCannon.picture = "cannons4";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 16;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 40;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 9.7;
    }
    rCannon.Cost = 1700;
    rCannon.Weight = 21;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 0.8;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 3.5;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 2.5;
    }
    rCannon.hp = 55.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,450.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS20]);
    rCannon.type = CANNON_NAME_CULVERINE;
    rCannon.name = "caliber20";
    rCannon.picture = "cannons5";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 20;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 50;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 11;
    }
    rCannon.Cost = 2000;
    rCannon.Weight = 24;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 1.0;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 4.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 3.0;
    }
    rCannon.hp = 60.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,500.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS24]);
    rCannon.type = CANNON_NAME_CULVERINE;
    rCannon.name = "caliber24";
    rCannon.picture = "cannons6";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 24;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 60;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 12.5;
    }
    rCannon.Cost = 2300;
    rCannon.Weight = 27;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 1.2;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 4.5;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 3.5;
    }
    rCannon.hp = 65.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,500.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS28]);
    rCannon.type = CANNON_NAME_CULVERINE;
    rCannon.name = "caliber28";
    rCannon.picture = "cannons7";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 28;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 70;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 13.7;
    }
    rCannon.Cost = 2600;
    rCannon.Weight = 30;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 1.4;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 5.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 4.0;
    }
    rCannon.hp = 70.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,550.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CULVERINE_LBS32]);
    rCannon.type = CANNON_NAME_CULVERINE;
    rCannon.caliber = 32;
    rCannon.name = "caliber32";
    rCannon.picture = "cannons8";
    rCannon.Sound = "fort_cannon_fire";
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 80;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 15;
    }
    rCannon.Cost = 2900;
    rCannon.Weight = 33;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.45;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 1.6;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 5.5;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 4.5;
    }
    rCannon.TradeOff = true;
    rCannon.hp = 75.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,550.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS4]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.name = "caliber4";
    rCannon.picture = "cannons9";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 4;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 5;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 4.5;
    }
    rCannon.Cost = 200;
    rCannon.Weight = 3;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 0.2;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 1.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 0.6;
    }
    rCannon.hp = 40.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,300.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS8]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.name = "caliber8";
    rCannon.picture = "cannons10";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 8;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 10;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 5.7;
    }
    rCannon.Cost = 500;
    rCannon.Weight = 6;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 0.4;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 1.5;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 0.8;
    }
    rCannon.hp = 45.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,300.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS12]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.name = "caliber12";
    rCannon.picture = "cannons11";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 12;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 20;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 7.2;
    }
    rCannon.Cost = 800;
    rCannon.Weight = 9;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 0.6;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 2.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 1.0;
    }
    rCannon.hp = 50.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,350.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS16]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.name = "caliber16";
    rCannon.picture = "cannons12";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 16;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 30;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 8.5;
    }
    rCannon.Cost = 1100;
    rCannon.Weight = 12;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 0.8;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 2.5;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 1.5;
    }
    rCannon.hp = 55.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,350.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS20]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.name = "caliber20";
    rCannon.picture = "cannons13";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 20;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 40;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 9.7;
    }
    rCannon.Cost = 1400;
    rCannon.Weight = 15;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 1.0;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 3.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 2.0;
    }
    rCannon.hp = 60.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,400.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS24]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.name = "caliber24";
    rCannon.picture = "cannons14";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 24;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 50;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 11;
    }
    rCannon.Weight = 18;
    rCannon.Cost = 1700;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 1.2;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 3.5;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 2.5;
    }
    rCannon.hp = 65.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,400.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS28]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.name = "caliber28";
    rCannon.picture = "cannons15";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 28;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 60;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 12.5;
    }
    rCannon.Cost = 2000;
    rCannon.Weight = 21;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 1.4;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 4.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 3.0;
    }
    rCannon.hp = 70.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,450.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS32]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.caliber = 32;
    rCannon.name = "caliber32";
    rCannon.picture = "cannons16";
    rCannon.Sound = "fort_cannon_fire";
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 70;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 13.7;
    }
    rCannon.Cost = 2300;
    rCannon.Weight = 24;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.45;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 1.6;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 4.5;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 3.5;
    }
    rCannon.TradeOff = true;
    rCannon.hp = 75.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,450.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS36]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.caliber = 36;
    rCannon.name = "caliber36";
    rCannon.picture = "cannons17";
    rCannon.Sound = "fort_cannon_fire";
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 80;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 15;
    }
    rCannon.Cost = 2600;
    rCannon.Weight = 27;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 1.8;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 5.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 4.0;
    }
    rCannon.TradeOff = true;
    rCannon.hp = 80.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,500.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS42]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.caliber = 42;
    rCannon.name = "caliber42";
    rCannon.picture = "cannons18";
    rCannon.Sound = "fort_cannon_fire";
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 90;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 16.5;
    }
    rCannon.Cost = 2900;
    rCannon.Weight = 30;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.45;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 2.0;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 5.5;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 4.5;
    }
    rCannon.TradeOff = true;
    rCannon.hp = 85.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,500.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS48]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.caliber = 48;
    rCannon.name = "caliber48";
    rCannon.picture = "cannons19";
    rCannon.Sound = "fort_cannon_fire";
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 100;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 17.7;
    }
    rCannon.Cost = 3200;
    rCannon.Weight = 33;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.45;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 6.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 5.0;
    }
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 0;
    rCannon.SizeMultiply = 2.2;
    rCannon.HeightMultiply = 1.0;
    rCannon.TradeOff = true;
    rCannon.hp = 90.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,550.0);

    makeref(rCannon,Cannon[CANNON_TYPE_CANNON_LBS92]);
    rCannon.type = CANNON_NAME_CANNON;
    rCannon.name = "caliber92";
    rCannon.picture = "cannons20";
    rCannon.Sound = "cannon_fire";
    rCannon.caliber = 92;
    if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
    {
        rCannon.ReloadTime = 110;

    }
    else // = If Realistic_Reloading IS enabled
    {

        rCannon.ReloadTime = 19;
    }
    rCannon.Cost = 3500;
    rCannon.Weight = 160;
    rCannon.FireAngMax = 0.60;
    rCannon.FireAngMin = -0.35;
    rCannon.TimeSpeedMultiply = 1.0;
    rCannon.BigBall = 1;
    rCannon.SizeMultiply = 2.4;
    rCannon.HeightMultiply = 1.0;
    if(!RTBL) // = If RTBL is NOT enabled
    {
        rCannon.DamageMultiply = 10.0;

    }
    else // = If RTBL IS enabled
    {

        //RTBL
        rCannon.DamageMultiply = 10.0;
    }
    rCannon.hp = 95.0;
    InitBaseCannons_CalcSpeedV0(&rCannon,550.0);

	/*makeref(rCannon,Cannon[CANNON_TYPE_MORTAR]);
	rCannon.type = CANNON_NAME_MORTAR;
	rCannon.caliber = 92;
	rCannon.name = "caliber92";
	rCannon.picture = "cannons21";
	rCannon.Sound = "fort_cannon_fire";
	if(!Realistic_Reloading) // = If Realistic Reloading is NOT enabled
{
	rCannon.ReloadTime = 120;

	}
	else // = If Realistic_Reloading IS enabled
	{

	rCannon.ReloadTime = 20.5;
}
	rCannon.Cost = 3500;
	rCannon.Weight = 160;
	rCannon.FireAngMax = 0.80;
	rCannon.FireAngMin = -0.35;
	if(!RTBL) // = If RTBL is NOT enabled
{
	rCannon.DamageMultiply = 10.0;

	}
	else // = If RTBL IS enabled
	{

	//RTBL
	rCannon.DamageMultiply = 10.0;
	}
	rCannon.TimeSpeedMultiply = 0.8;
	rCannon.BigBall = 1;
	rCannon.SizeMultiply = 2.4;
	rCannon.HeightMultiply = 1.0;
	rCannon.TradeOff = true;
	rCannon.hp = 95.0;
	InitBaseCannons_CalcSpeedV0(&rCannon,550.0);    */
}
