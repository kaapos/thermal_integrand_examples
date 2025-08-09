#include "math.h"

#include "WolframRTL.h"

static WolframCompileLibrary_Functions funStructCompile;

static LibraryFunctionPointer FP0;

static MArgument FPA[4];


static mint I0_0;

static mint I0_1;

static mint I0_2;

static mint I0_3;

static mint I0_4;

static mbool initialize = 1;

#include "OSEsAndSPs_wolfram.h"

DLLEXPORT int Initialize_OSEsAndSPs_wolfram(WolframLibraryData libData)
{
if( initialize)
{
funStructCompile = libData->compileLibraryFunctions;
I0_3 = (mint) -2;
I0_2 = (mint) 2;
I0_0 = (mint) 1;
I0_4 = (mint) 3;
I0_1 = (mint) 4;
FP0 = funStructCompile->getFunctionCallPointer("DotVV");
if( FP0 == 0)
{
return LIBRARY_FUNCTION_ERROR;
}
initialize = 0;
}
return 0;
}

DLLEXPORT void Uninitialize_OSEsAndSPs_wolfram(WolframLibraryData libData)
{
if( !initialize)
{
initialize = 1;
}
}

DLLEXPORT int OSEsAndSPs_wolfram(WolframLibraryData libData, MTensor A1, MTensor A2, MTensor *Res)
{
mreal R0_0;
mreal R0_1;
mreal R0_2;
mreal R0_3;
mreal R0_4;
mreal R0_5;
mreal R0_6;
mreal R0_7;
mreal R0_8;
mreal R0_9;
mreal R0_10;
mreal R0_11;
mreal R0_12;
mreal R0_13;
mreal R0_14;
mreal R0_15;
mreal R0_16;
mreal R0_17;
mreal R0_18;
mreal R0_19;
mreal R0_20;
mreal R0_21;
mreal R0_22;
mreal R0_23;
mreal R0_24;
mreal R0_25;
mreal R0_26;
mreal R0_27;
mreal R0_28;
mreal R0_29;
mreal R0_30;
mreal R0_31;
mreal R0_32;
mreal R0_33;
mreal R0_34;
mreal R0_35;
mreal R0_36;
mreal R0_37;
mreal R0_38;
mreal R0_39;
mreal R0_40;
mreal R0_41;
mreal R0_42;
mreal R0_43;
mreal R0_44;
mreal R0_45;
mreal R0_46;
mreal R0_47;
mreal R0_48;
mreal R0_49;
mreal R0_50;
mreal R0_51;
mreal R0_52;
mreal R0_53;
MTensor* T0_0;
MTensor* T0_1;
MTensor* T0_2;
MTensor* T0_3;
MTensor* T0_4;
MTensor* T0_5;
MTensorInitializationData Tinit;
mreal *P1;
mint *D1;
mreal *P5;
MArgument FPA[4];
int err = 0;
Tinit = funStructCompile->GetInitializedMTensors(libData, 4);
T0_2 = MTensorInitializationData_getTensor(Tinit, 0);
T0_3 = MTensorInitializationData_getTensor(Tinit, 1);
T0_4 = MTensorInitializationData_getTensor(Tinit, 2);
T0_5 = MTensorInitializationData_getTensor(Tinit, 3);
T0_0 = &A1;
T0_1 = &A2;
P1 = MTensor_getRealDataMacro(*T0_1);
D1 = MTensor_getDimensionsMacro(*T0_1);
err = funStructCompile->MTensor_getMTensorInitialized(T0_2, *T0_0, &I0_0, 1);
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T0_2;
MArgument_getMTensorAddress(FPA[1]) = T0_2;
MArgument_getIntegerAddress(FPA[2]) = &I0_1;
MArgument_getRealAddress(FPA[3]) = &R0_0;
err = FP0(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_3, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T0_2;
MArgument_getMTensorAddress(FPA[1]) = T0_3;
MArgument_getIntegerAddress(FPA[2]) = &I0_1;
MArgument_getRealAddress(FPA[3]) = &R0_1;
err = FP0(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R0_2 = (mreal) I0_3;
R0_2 = R0_2 * R0_1;
MArgument_getMTensorAddress(FPA[0]) = T0_3;
MArgument_getMTensorAddress(FPA[1]) = T0_3;
MArgument_getIntegerAddress(FPA[2]) = &I0_1;
MArgument_getRealAddress(FPA[3]) = &R0_3;
err = FP0(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
{
mint S0 = D1[0];
if( I0_0 > 0)
{
if( I0_0 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I0_0 - 1;
}
else
{
if( I0_0 == 0 || I0_0 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I0_0;
}
R0_4 = P1[S0];
}
R0_5 = R0_4 * R0_4;
R0_6 = R0_0 + R0_2 + R0_3 + R0_5;
R0_7 = sqrt(R0_6);
err = funStructCompile->MTensor_getMTensorInitialized(T0_4, *T0_0, &I0_4, 1);
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T0_2;
MArgument_getMTensorAddress(FPA[1]) = T0_4;
MArgument_getIntegerAddress(FPA[2]) = &I0_1;
MArgument_getRealAddress(FPA[3]) = &R0_8;
err = FP0(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R0_9 = (mreal) I0_3;
R0_9 = R0_9 * R0_8;
MArgument_getMTensorAddress(FPA[0]) = T0_4;
MArgument_getMTensorAddress(FPA[1]) = T0_4;
MArgument_getIntegerAddress(FPA[2]) = &I0_1;
MArgument_getRealAddress(FPA[3]) = &R0_10;
err = FP0(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T0_3;
MArgument_getMTensorAddress(FPA[1]) = T0_4;
MArgument_getIntegerAddress(FPA[2]) = &I0_1;
MArgument_getRealAddress(FPA[3]) = &R0_11;
err = FP0(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R0_12 = (mreal) I0_3;
R0_12 = R0_12 * R0_11;
R0_13 = R0_0 + R0_9 + R0_10 + R0_5;
R0_14 = sqrt(R0_13);
R0_15 = R0_3 + R0_12 + R0_10 + R0_5;
R0_16 = sqrt(R0_15);
R0_17 = -R0_8;
R0_18 = -R0_0;
R0_19 = -R0_1;
R0_20 = -R0_3;
R0_21 = -R0_11;
R0_22 = R0_0 + R0_2 + R0_3;
R0_23 = R0_19 + R0_8 + R0_3 + R0_21;
R0_24 = R0_0 + R0_19 + R0_17 + R0_11;
R0_25 = R0_1 + R0_17 + R0_20 + R0_11;
R0_26 = -R0_10;
R0_27 = R0_19 + R0_8 + R0_11 + R0_26;
R0_28 = R0_0 + R0_9 + R0_10;
R0_29 = R0_3 + R0_12 + R0_10;
R0_30 = sqrt(R0_0);
R0_31 = R0_0 + R0_5;
R0_32 = sqrt(R0_31);
R0_31 = sqrt(R0_22);
R0_33 = sqrt(R0_3);
R0_34 = R0_3 + R0_5;
R0_35 = sqrt(R0_34);
R0_34 = sqrt(R0_28);
R0_36 = sqrt(R0_29);
R0_37 = sqrt(R0_10);
R0_38 = R0_10 + R0_5;
R0_39 = sqrt(R0_38);
R0_38 = R0_0 + R0_19;
R0_40 = R0_18 + R0_1;
R0_41 = R0_0 + R0_17;
R0_42 = R0_1 + R0_17;
R0_43 = R0_18 + R0_8;
R0_44 = R0_19 + R0_8;
R0_45 = R0_1 + R0_20;
R0_46 = R0_8 + R0_21;
R0_47 = R0_1 + R0_21;
R0_48 = R0_3 + R0_21;
R0_49 = R0_20 + R0_11;
R0_50 = R0_1 + R0_17 + R0_21 + R0_10;
R0_51 = R0_8 + R0_26;
R0_52 = R0_11 + R0_26;
R0_53 = R0_21 + R0_10;
{
mint S0[1] = {47};
err = funStructCompile->MTensor_allocate(T0_5, 3, 1, S0);
if( err)
{
goto error_label;
}
P5 = MTensor_getRealDataMacro(*T0_5);
P5[0] = R0_30;
P5[1] = R0_32;
P5[2] = R0_31;
P5[3] = R0_7;
P5[4] = R0_33;
P5[5] = R0_35;
P5[6] = R0_7;
P5[7] = R0_34;
P5[8] = R0_14;
P5[9] = R0_36;
P5[10] = R0_16;
P5[11] = R0_37;
P5[12] = R0_39;
P5[13] = R0_14;
P5[14] = R0_16;
P5[15] = R0_0;
P5[16] = R0_38;
P5[17] = R0_1;
P5[18] = R0_40;
P5[19] = R0_41;
P5[20] = R0_42;
P5[21] = R0_8;
P5[22] = R0_43;
P5[23] = R0_44;
P5[24] = R0_45;
P5[25] = R0_24;
P5[26] = R0_25;
P5[27] = R0_46;
P5[28] = R0_23;
P5[29] = R0_3;
P5[30] = R0_47;
P5[31] = R0_48;
P5[32] = R0_11;
P5[33] = R0_49;
P5[34] = R0_22;
P5[35] = R0_23;
P5[36] = R0_24;
P5[37] = R0_25;
P5[38] = R0_50;
P5[39] = R0_51;
P5[40] = R0_27;
P5[41] = R0_52;
P5[42] = R0_27;
P5[43] = R0_10;
P5[44] = R0_53;
P5[45] = R0_28;
P5[46] = R0_29;
}
funStructCompile->MTensor_copy(Res, *T0_5);
error_label:
funStructCompile->ReleaseInitializedMTensors(Tinit);
funStructCompile->WolframLibraryData_cleanUp(libData, 1);
return err;
}

