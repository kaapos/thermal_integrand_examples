#include "math.h"

#include "WolframRTL.h"

static WolframCompileLibrary_Functions funStructCompile;

static const mint UnitIncrements[3] = {1, 1, 1};

static LibraryFunctionPointer FP0;

static LibraryFunctionPointer FP1;

static UnaryMathFunctionPointer FP2;

static MArgument FPA[4];


static mint I0_1;

static mint I0_2;

static mint I0_3;

static mint I0_4;

static mint I0_5;

static mint I0_6;

static mint I0_7;

static mint I0_8;

static mint I0_9;

static mint I0_10;

static mint I0_11;

static mint I0_12;

static mint I0_13;

static mint I0_14;

static mint I0_15;

static mint I0_16;

static MTensor T0_44B = 0;

static MTensor* T0_44 = &T0_44B;

static mbool B1_1;

static mbool B1_18;

static mint I1_1;

static mint I1_2;

static mint I1_3;

static mint I1_4;

static mint I1_5;

static mint I1_6;

static mint I1_7;

static mint I1_8;

static mint I1_9;

static mint I1_10;

static mint I1_11;

static mint I1_12;

static mint I1_13;

static mint I1_14;

static mint I1_15;

static mint I1_16;

static mint I1_17;

static mint I1_18;

static mreal R1_11;

static mreal R1_13;

static mreal R1_14;

static mreal R1_16;

static mreal R1_19;

static mint I3_3;

static mint I3_4;

static mint I3_5;

static mint I3_6;

static mint I3_7;

static mint I3_8;

static mint I3_10;

static mint I3_11;

static mint I3_12;

static mint I3_13;

static mint I3_14;

static mint I3_15;

static mint I3_16;

static mint I3_17;

static mint I3_18;

static mint I3_19;

static mint I3_20;

static mreal R3_9;

static mreal R3_22;

static mreal R3_32;

static mreal R3_36;

static mreal R3_386;

static mint I4_3;

static mint I4_4;

static mint I4_5;

static mint I4_6;

static mreal R4_2;

static mreal *P2;

static mbool initialize = 1;

#include "internalEdgeMomenta_wolfram.h"

DLLEXPORT int Initialize_internalEdgeMomenta_wolfram(WolframLibraryData libData)
{
int err = 0;
if( initialize)
{
funStructCompile = libData->compileLibraryFunctions;
I0_7 = (mint) 7;
I0_9 = (mint) 9;
{
mint S0[2];
S0[0] = 16;
S0[1] = 3;
err = funStructCompile->MTensor_allocate(T0_44, 3, 2, S0);
if( err)
{
goto error_label;
}
P2 = MTensor_getRealDataMacro(*T0_44);
P2[0] = 0.;
P2[1] = 0.;
P2[2] = 0.;
P2[3] = 0.;
P2[4] = 0.;
P2[5] = 0.;
P2[6] = 0.;
P2[7] = 0.;
P2[8] = 0.;
P2[9] = 0.;
P2[10] = 0.;
P2[11] = 0.;
P2[12] = 0.;
P2[13] = 0.;
P2[14] = 0.;
P2[15] = 0.;
P2[16] = 0.;
P2[17] = 0.;
P2[18] = 0.;
P2[19] = 0.;
P2[20] = 0.;
P2[21] = 0.;
P2[22] = 0.;
P2[23] = 0.;
P2[24] = 0.;
P2[25] = 0.;
P2[26] = 0.;
P2[27] = 0.;
P2[28] = 0.;
P2[29] = 0.;
P2[30] = 0.;
P2[31] = 0.;
P2[32] = 0.;
P2[33] = 0.;
P2[34] = 0.;
P2[35] = 0.;
P2[36] = 0.;
P2[37] = 0.;
P2[38] = 0.;
P2[39] = 0.;
P2[40] = 0.;
P2[41] = 0.;
P2[42] = 0.;
P2[43] = 0.;
P2[44] = 0.;
P2[45] = 0.;
P2[46] = 0.;
P2[47] = 0.;
}
I0_8 = (mint) 8;
I0_16 = (mint) 16;
I0_13 = (mint) 13;
I0_14 = (mint) 14;
I0_3 = (mint) 2;
I0_15 = (mint) 15;
I0_1 = (mint) 1;
I0_6 = (mint) 6;
I0_2 = (mint) 3;
I0_11 = (mint) 11;
I0_10 = (mint) 10;
I0_4 = (mint) 4;
I0_5 = (mint) 5;
I0_12 = (mint) 12;
I1_7 = (mint) 7;
I1_9 = (mint) 9;
I1_17 = (mint) 0;
B1_18 = (mbool) 0;
I1_8 = (mint) 8;
R1_19 = (mreal) 0.5;
R1_13 = (mreal) 0.;
I1_18 = (mint) -1;
I1_16 = (mint) 16;
I1_13 = (mint) 13;
I1_14 = (mint) 14;
I1_5 = (mint) 2;
I1_15 = (mint) 15;
I1_3 = (mint) 1;
R1_14 = (mreal) 1.;
B1_1 = (mbool) 1;
I1_4 = (mint) 6;
I1_6 = (mint) 3;
I1_11 = (mint) 11;
I1_10 = (mint) 10;
R1_11 = (mreal) 3.141592653589793;
I1_1 = (mint) 4;
I1_2 = (mint) 5;
I1_12 = (mint) 12;
R1_16 = (mreal) 7.;
I3_11 = (mint) 7;
I3_13 = (mint) 9;
R3_22 = (mreal) 0.5;
I3_12 = (mint) 8;
R3_386 = (mreal) 0.;
R3_9 = (mreal) -0.25;
I3_20 = (mint) 16;
I3_17 = (mint) 13;
R3_32 = (mreal) 0.125;
I3_18 = (mint) 14;
I3_4 = (mint) 2;
I3_19 = (mint) 15;
I3_3 = (mint) 1;
I3_7 = (mint) -3;
I3_8 = (mint) 6;
I3_5 = (mint) 3;
I3_15 = (mint) 11;
I3_14 = (mint) 10;
R3_36 = (mreal) 3.141592653589793;
I3_6 = (mint) 4;
I3_10 = (mint) 5;
I3_16 = (mint) 12;
R4_2 = (mreal) -0.25;
I4_4 = (mint) 2;
I4_3 = (mint) 1;
I4_5 = (mint) 3;
I4_6 = (mint) 4;
FP0 = funStructCompile->getFunctionCallPointer("CopyTensor");
if( FP0 == 0)
{
return LIBRARY_FUNCTION_ERROR;
}
FP1 = funStructCompile->getFunctionCallPointer("DotVV");
if( FP1 == 0)
{
return LIBRARY_FUNCTION_ERROR;
}
FP2 = funStructCompile->getUnaryMathFunction(44, 3);/*  Sign  */
if( FP2 == 0)
{
return LIBRARY_FUNCTION_ERROR;
}
initialize = 0;
}
error_label:
return err;
}

DLLEXPORT void Uninitialize_internalEdgeMomenta_wolfram(WolframLibraryData libData)
{
if( !initialize)
{
initialize = 1;
}
}

static int F1(WolframLibraryData libData, MTensor A1, mint A2, MTensor A3, mint A4, mint A5, mreal A6, mreal A7, mreal *Res)
{
mint I4_0;
mint I4_1;
mint I4_2;
mreal R4_0;
mreal R4_1;
mreal R4_3;
mreal R4_4;
mreal R4_5;
mreal R4_6;
mreal R4_7;
mreal R4_8;
mreal R4_9;
mreal R4_10;
mreal R4_11;
mreal R4_12;
mreal R4_13;
mreal R4_14;
mreal R4_15;
mreal R4_16;
mreal R4_17;
mreal R4_18;
mreal R4_19;
mreal R4_20;
mreal R4_21;
mreal R4_22;
mreal R4_23;
mreal R4_24;
mreal R4_25;
mreal R4_26;
mreal R4_27;
mreal R4_28;
mreal R4_29;
mreal R4_30;
mreal R4_31;
mreal R4_32;
mreal R4_33;
mreal R4_34;
mreal R4_35;
mreal R4_36;
mreal R4_37;
mreal R4_38;
mreal R4_39;
mreal R4_40;
mreal R4_41;
mreal R4_42;
mreal R4_43;
mreal R4_44;
mreal R4_45;
mreal R4_46;
MTensor* T4_0;
MTensor* T4_1;
MTensor* T4_2;
MTensor* T4_3;
MTensor* T4_4;
MTensor* T4_5;
MTensor* T4_6;
MTensor* T4_7;
MTensor* T4_8;
MTensor* T4_9;
MTensorInitializationData Tinit;
mreal *P1;
mint *D1;
MArgument FPA[4];
int err = 0;
Tinit = funStructCompile->GetInitializedMTensors(libData, 8);
T4_2 = MTensorInitializationData_getTensor(Tinit, 0);
T4_3 = MTensorInitializationData_getTensor(Tinit, 1);
T4_4 = MTensorInitializationData_getTensor(Tinit, 2);
T4_5 = MTensorInitializationData_getTensor(Tinit, 3);
T4_6 = MTensorInitializationData_getTensor(Tinit, 4);
T4_7 = MTensorInitializationData_getTensor(Tinit, 5);
T4_8 = MTensorInitializationData_getTensor(Tinit, 6);
T4_9 = MTensorInitializationData_getTensor(Tinit, 7);
T4_0 = &A1;
I4_0 = A2;
T4_1 = &A3;
P1 = MTensor_getRealDataMacro(*T4_1);
D1 = MTensor_getDimensionsMacro(*T4_1);
I4_1 = A4;
I4_2 = A5;
R4_0 = A6;
R4_1 = A7;
err = funStructCompile->MTensor_getMTensorInitialized(T4_2, *T4_0, &I4_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T4_2, 3, T4_3);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T4_4, *T4_0, &I4_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T4_3, *T4_4, 3, T4_5);
if( err)
{
goto error_label;
}
R4_3 = (mreal) I4_1;
R4_4 = R4_2 * R4_3;
err = funStructCompile->MTensor_getMTensorInitialized(T4_6, *T4_0, &I4_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T4_3, *T4_6, 3, T4_7);
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T4_2;
MArgument_getMTensorAddress(FPA[1]) = T4_2;
MArgument_getIntegerAddress(FPA[2]) = &I4_6;
MArgument_getRealAddress(FPA[3]) = &R4_3;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R4_5 = pow(R4_3, R4_4);
MArgument_getMTensorAddress(FPA[0]) = T4_5;
MArgument_getMTensorAddress(FPA[1]) = T4_5;
MArgument_getIntegerAddress(FPA[2]) = &I4_6;
MArgument_getRealAddress(FPA[3]) = &R4_6;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R4_7 = pow(R4_6, R4_4);
err = funStructCompile->Math_T_T(43, 4, *T4_4, 3, T4_8);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T4_8, *T4_6, 3, T4_9);
if( err)
{
goto error_label;
}
R4_8 = sqrt(R4_3);
{
mint S0 = D1[0];
if( I4_4 > 0)
{
if( I4_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I4_4 - 1;
}
else
{
if( I4_4 == 0 || I4_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I4_4;
}
R4_9 = P1[S0];
}
R4_10 = -R4_9;
R4_11 = R4_8 + R4_10;
R4_12 = R4_11 * R4_11;
R4_13 = (mreal) I4_2;
R4_14 = R4_2 * R4_13;
R4_13 = pow(R4_12, R4_14);
MArgument_getMTensorAddress(FPA[0]) = T4_7;
MArgument_getMTensorAddress(FPA[1]) = T4_7;
MArgument_getIntegerAddress(FPA[2]) = &I4_6;
MArgument_getRealAddress(FPA[3]) = &R4_15;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R4_16 = pow(R4_15, R4_4);
MArgument_getMTensorAddress(FPA[0]) = T4_9;
MArgument_getMTensorAddress(FPA[1]) = T4_9;
MArgument_getIntegerAddress(FPA[2]) = &I4_6;
MArgument_getRealAddress(FPA[3]) = &R4_17;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R4_18 = pow(R4_17, R4_4);
MArgument_getMTensorAddress(FPA[0]) = T4_4;
MArgument_getMTensorAddress(FPA[1]) = T4_4;
MArgument_getIntegerAddress(FPA[2]) = &I4_6;
MArgument_getRealAddress(FPA[3]) = &R4_19;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R4_20 = pow(R4_19, R4_4);
R4_21 = sqrt(R4_19);
R4_22 = R4_21 + R4_10;
R4_23 = R4_22 * R4_22;
R4_24 = pow(R4_23, R4_14);
MArgument_getMTensorAddress(FPA[0]) = T4_6;
MArgument_getMTensorAddress(FPA[1]) = T4_6;
MArgument_getIntegerAddress(FPA[2]) = &I4_6;
MArgument_getRealAddress(FPA[3]) = &R4_25;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R4_26 = pow(R4_25, R4_4);
R4_27 = sqrt(R4_25);
R4_28 = R4_27 + R4_10;
R4_29 = R4_28 * R4_28;
R4_30 = pow(R4_29, R4_14);
R4_31 = R4_5 * R4_7 * R4_16 * R4_13;
R4_32 = R4_5 * R4_7 * R4_18 * R4_13;
R4_33 = R4_5 * R4_16 * R4_18 * R4_13;
R4_34 = R4_20 * R4_7 * R4_16 * R4_24;
R4_35 = R4_20 * R4_7 * R4_18 * R4_24;
R4_36 = R4_20 * R4_16 * R4_18 * R4_24;
R4_37 = R4_5 * R4_20 * R4_16 * R4_13 * R4_24;
R4_38 = R4_5 * R4_20 * R4_18 * R4_13 * R4_24;
R4_39 = R4_7 * R4_26 * R4_16 * R4_30;
R4_40 = R4_7 * R4_26 * R4_18 * R4_30;
R4_41 = R4_26 * R4_16 * R4_18 * R4_30;
R4_42 = R4_5 * R4_7 * R4_26 * R4_13 * R4_30;
R4_43 = R4_5 * R4_26 * R4_18 * R4_13 * R4_30;
R4_44 = R4_20 * R4_7 * R4_26 * R4_24 * R4_30;
R4_45 = R4_20 * R4_26 * R4_16 * R4_24 * R4_30;
R4_46 = R4_5 * R4_20 * R4_26 * R4_13 * R4_24 * R4_30;
R4_31 = R4_31 + R4_32 + R4_33 + R4_34 + R4_35 + R4_36 + R4_37 + R4_38 + R4_39 + R4_40 + R4_41 + R4_42 + R4_43 + R4_44 + R4_45 + R4_46;
*Res = R4_31;
error_label:
funStructCompile->ReleaseInitializedMTensors(Tinit);
return err;
}

static int F0(WolframLibraryData libData, MTensor A1, mint A2, MTensor A3, mint A4, mint A5, mreal A6, mreal A7, mreal *Res)
{
mbool B3_0;
mbool B3_1;
mbool B3_2;
mbool B3_3;
mbool B3_4;
mbool B3_5;
mbool B3_6;
mbool B3_7;
mbool B3_8;
mbool B3_9;
mbool B3_10;
mbool B3_11;
mbool B3_12;
mbool B3_13;
mbool B3_14;
mbool B3_15;
mint I3_0;
mint I3_1;
mint I3_2;
mint I3_9;
mreal R3_0;
mreal R3_1;
mreal R3_2;
mreal R3_3;
mreal R3_4;
mreal R3_5;
mreal R3_6;
mreal R3_7;
mreal R3_8;
mreal R3_10;
mreal R3_11;
mreal R3_12;
mreal R3_13;
mreal R3_14;
mreal R3_15;
mreal R3_16;
mreal R3_17;
mreal R3_18;
mreal R3_19;
mreal R3_20;
mreal R3_21;
mreal R3_23;
mreal R3_24;
mreal R3_25;
mreal R3_26;
mreal R3_27;
mreal R3_28;
mreal R3_29;
mreal R3_30;
mreal R3_31;
mreal R3_33;
mreal R3_34;
mreal R3_35;
mreal R3_37;
mreal R3_38;
mreal R3_39;
mreal R3_40;
mreal R3_41;
mreal R3_42;
mreal R3_43;
mreal R3_44;
mreal R3_45;
mreal R3_46;
mreal R3_47;
mreal R3_48;
mreal R3_49;
mreal R3_50;
mreal R3_51;
mreal R3_52;
mreal R3_53;
mreal R3_54;
mreal R3_55;
mreal R3_56;
mreal R3_57;
mreal R3_58;
mreal R3_59;
mreal R3_60;
mreal R3_61;
mreal R3_62;
mreal R3_63;
mreal R3_64;
mreal R3_65;
mreal R3_66;
mreal R3_67;
mreal R3_68;
mreal R3_69;
mreal R3_70;
mreal R3_71;
mreal R3_72;
mreal R3_73;
mreal R3_74;
mreal R3_75;
mreal R3_76;
mreal R3_77;
mreal R3_78;
mreal R3_79;
mreal R3_80;
mreal R3_81;
mreal R3_82;
mreal R3_83;
mreal R3_84;
mreal R3_85;
mreal R3_86;
mreal R3_87;
mreal R3_88;
mreal R3_89;
mreal R3_90;
mreal R3_91;
mreal R3_92;
mreal R3_93;
mreal R3_94;
mreal R3_95;
mreal R3_96;
mreal R3_97;
mreal R3_98;
mreal R3_99;
mreal R3_100;
mreal R3_101;
mreal R3_102;
mreal R3_103;
mreal R3_104;
mreal R3_105;
mreal R3_106;
mreal R3_107;
mreal R3_108;
mreal R3_109;
mreal R3_110;
mreal R3_111;
mreal R3_112;
mreal R3_113;
mreal R3_114;
mreal R3_115;
mreal R3_116;
mreal R3_117;
mreal R3_118;
mreal R3_119;
mreal R3_120;
mreal R3_121;
mreal R3_122;
mreal R3_123;
mreal R3_124;
mreal R3_125;
mreal R3_126;
mreal R3_127;
mreal R3_128;
mreal R3_129;
mreal R3_130;
mreal R3_131;
mreal R3_132;
mreal R3_133;
mreal R3_134;
mreal R3_135;
mreal R3_136;
mreal R3_137;
mreal R3_138;
mreal R3_139;
mreal R3_140;
mreal R3_141;
mreal R3_142;
mreal R3_143;
mreal R3_144;
mreal R3_145;
mreal R3_146;
mreal R3_147;
mreal R3_148;
mreal R3_149;
mreal R3_150;
mreal R3_151;
mreal R3_152;
mreal R3_153;
mreal R3_154;
mreal R3_155;
mreal R3_156;
mreal R3_157;
mreal R3_158;
mreal R3_159;
mreal R3_160;
mreal R3_161;
mreal R3_162;
mreal R3_163;
mreal R3_164;
mreal R3_165;
mreal R3_166;
mreal R3_167;
mreal R3_168;
mreal R3_169;
mreal R3_170;
mreal R3_171;
mreal R3_172;
mreal R3_173;
mreal R3_174;
mreal R3_175;
mreal R3_176;
mreal R3_177;
mreal R3_178;
mreal R3_179;
mreal R3_180;
mreal R3_181;
mreal R3_182;
mreal R3_183;
mreal R3_184;
mreal R3_185;
mreal R3_186;
mreal R3_187;
mreal R3_188;
mreal R3_189;
mreal R3_190;
mreal R3_191;
mreal R3_192;
mreal R3_193;
mreal R3_194;
mreal R3_195;
mreal R3_196;
mreal R3_197;
mreal R3_198;
mreal R3_199;
mreal R3_200;
mreal R3_201;
mreal R3_202;
mreal R3_203;
mreal R3_204;
mreal R3_205;
mreal R3_206;
mreal R3_207;
mreal R3_208;
mreal R3_209;
mreal R3_210;
mreal R3_211;
mreal R3_212;
mreal R3_213;
mreal R3_214;
mreal R3_215;
mreal R3_216;
mreal R3_217;
mreal R3_218;
mreal R3_219;
mreal R3_220;
mreal R3_221;
mreal R3_222;
mreal R3_223;
mreal R3_224;
mreal R3_225;
mreal R3_226;
mreal R3_227;
mreal R3_228;
mreal R3_229;
mreal R3_230;
mreal R3_231;
mreal R3_232;
mreal R3_233;
mreal R3_234;
mreal R3_235;
mreal R3_236;
mreal R3_237;
mreal R3_238;
mreal R3_239;
mreal R3_240;
mreal R3_241;
mreal R3_242;
mreal R3_243;
mreal R3_244;
mreal R3_245;
mreal R3_246;
mreal R3_247;
mreal R3_248;
mreal R3_249;
mreal R3_250;
mreal R3_251;
mreal R3_252;
mreal R3_253;
mreal R3_254;
mreal R3_255;
mreal R3_256;
mreal R3_257;
mreal R3_258;
mreal R3_259;
mreal R3_260;
mreal R3_261;
mreal R3_262;
mreal R3_263;
mreal R3_264;
mreal R3_265;
mreal R3_266;
mreal R3_267;
mreal R3_268;
mreal R3_269;
mreal R3_270;
mreal R3_271;
mreal R3_272;
mreal R3_273;
mreal R3_274;
mreal R3_275;
mreal R3_276;
mreal R3_277;
mreal R3_278;
mreal R3_279;
mreal R3_280;
mreal R3_281;
mreal R3_282;
mreal R3_283;
mreal R3_284;
mreal R3_285;
mreal R3_286;
mreal R3_287;
mreal R3_288;
mreal R3_289;
mreal R3_290;
mreal R3_291;
mreal R3_292;
mreal R3_293;
mreal R3_294;
mreal R3_295;
mreal R3_296;
mreal R3_297;
mreal R3_298;
mreal R3_299;
mreal R3_300;
mreal R3_301;
mreal R3_302;
mreal R3_303;
mreal R3_304;
mreal R3_305;
mreal R3_306;
mreal R3_307;
mreal R3_308;
mreal R3_309;
mreal R3_310;
mreal R3_311;
mreal R3_312;
mreal R3_313;
mreal R3_314;
mreal R3_315;
mreal R3_316;
mreal R3_317;
mreal R3_318;
mreal R3_319;
mreal R3_320;
mreal R3_321;
mreal R3_322;
mreal R3_323;
mreal R3_324;
mreal R3_325;
mreal R3_326;
mreal R3_327;
mreal R3_328;
mreal R3_329;
mreal R3_330;
mreal R3_331;
mreal R3_332;
mreal R3_333;
mreal R3_334;
mreal R3_335;
mreal R3_336;
mreal R3_337;
mreal R3_338;
mreal R3_339;
mreal R3_340;
mreal R3_341;
mreal R3_342;
mreal R3_343;
mreal R3_344;
mreal R3_345;
mreal R3_346;
mreal R3_347;
mreal R3_348;
mreal R3_349;
mreal R3_350;
mreal R3_351;
mreal R3_352;
mreal R3_353;
mreal R3_354;
mreal R3_355;
mreal R3_356;
mreal R3_357;
mreal R3_358;
mreal R3_359;
mreal R3_360;
mreal R3_361;
mreal R3_362;
mreal R3_363;
mreal R3_364;
mreal R3_365;
mreal R3_366;
mreal R3_367;
mreal R3_368;
mreal R3_369;
mreal R3_370;
mreal R3_371;
mreal R3_372;
mreal R3_373;
mreal R3_374;
mreal R3_375;
mreal R3_376;
mreal R3_377;
mreal R3_378;
mreal R3_379;
mreal R3_380;
mreal R3_381;
mreal R3_382;
mreal R3_383;
mreal R3_384;
mreal R3_385;
MTensor* T3_0;
MTensor* T3_1;
MTensor* T3_2;
MTensor* T3_3;
MTensor* T3_4;
MTensor* T3_5;
MTensor* T3_6;
MTensor* T3_7;
MTensor* T3_8;
MTensor* T3_9;
MTensor* T3_10;
MTensor* T3_11;
MTensor* T3_12;
MTensor* T3_13;
MTensor* T3_14;
MTensor* T3_15;
MTensor* T3_16;
MTensor* T3_17;
MTensor* T3_18;
MTensor* T3_19;
MTensor* T3_20;
MTensor* T3_21;
MTensor* T3_22;
MTensor* T3_23;
MTensor* T3_24;
MTensor* T3_25;
MTensor* T3_26;
MTensor* T3_27;
MTensor* T3_28;
MTensor* T3_29;
MTensor* T3_30;
MTensor* T3_31;
MTensor* T3_32;
MTensor* T3_33;
MTensor* T3_34;
MTensor* T3_35;
MTensor* T3_36;
MTensor* T3_37;
MTensor* T3_38;
MTensor* T3_39;
MTensor* T3_40;
MTensor* T3_41;
MTensor* T3_42;
MTensor* T3_43;
MTensor* T3_44;
MTensor* T3_45;
MTensor* T3_46;
MTensor* T3_47;
MTensor* T3_48;
MTensor* T3_49;
MTensor* T3_50;
MTensor* T3_51;
MTensor* T3_52;
MTensor* T3_53;
MTensor* T3_54;
MTensor* T3_55;
MTensor* T3_56;
MTensor* T3_57;
MTensor* T3_58;
MTensor* T3_59;
MTensor* T3_60;
MTensor* T3_61;
MTensor* T3_62;
MTensor* T3_63;
MTensor* T3_64;
MTensor* T3_65;
MTensor* T3_66;
MTensor* T3_67;
MTensor* T3_68;
MTensor* T3_69;
MTensor* T3_70;
MTensor* T3_71;
MTensor* T3_72;
MTensor* T3_73;
MTensor* T3_74;
MTensor* T3_75;
MTensor* T3_76;
MTensor* T3_77;
MTensor* T3_78;
MTensor* T3_79;
MTensor* T3_80;
MTensor* T3_81;
MTensor* T3_82;
MTensor* T3_83;
MTensor* T3_84;
MTensor* T3_85;
MTensor* T3_86;
MTensor* T3_87;
MTensor* T3_88;
MTensor* T3_89;
MTensor* T3_90;
MTensor* T3_91;
MTensor* T3_92;
MTensor* T3_93;
MTensor* T3_94;
MTensorInitializationData Tinit;
mreal *P1;
mint *D1;
MArgument FPA[4];
int err = 0;
Tinit = funStructCompile->GetInitializedMTensors(libData, 93);
T3_10 = MTensorInitializationData_getTensor(Tinit, 0);
T3_11 = MTensorInitializationData_getTensor(Tinit, 1);
T3_12 = MTensorInitializationData_getTensor(Tinit, 2);
T3_13 = MTensorInitializationData_getTensor(Tinit, 3);
T3_14 = MTensorInitializationData_getTensor(Tinit, 4);
T3_15 = MTensorInitializationData_getTensor(Tinit, 5);
T3_16 = MTensorInitializationData_getTensor(Tinit, 6);
T3_17 = MTensorInitializationData_getTensor(Tinit, 7);
T3_18 = MTensorInitializationData_getTensor(Tinit, 8);
T3_19 = MTensorInitializationData_getTensor(Tinit, 9);
T3_2 = MTensorInitializationData_getTensor(Tinit, 10);
T3_20 = MTensorInitializationData_getTensor(Tinit, 11);
T3_21 = MTensorInitializationData_getTensor(Tinit, 12);
T3_22 = MTensorInitializationData_getTensor(Tinit, 13);
T3_23 = MTensorInitializationData_getTensor(Tinit, 14);
T3_24 = MTensorInitializationData_getTensor(Tinit, 15);
T3_25 = MTensorInitializationData_getTensor(Tinit, 16);
T3_26 = MTensorInitializationData_getTensor(Tinit, 17);
T3_27 = MTensorInitializationData_getTensor(Tinit, 18);
T3_28 = MTensorInitializationData_getTensor(Tinit, 19);
T3_29 = MTensorInitializationData_getTensor(Tinit, 20);
T3_3 = MTensorInitializationData_getTensor(Tinit, 21);
T3_30 = MTensorInitializationData_getTensor(Tinit, 22);
T3_31 = MTensorInitializationData_getTensor(Tinit, 23);
T3_32 = MTensorInitializationData_getTensor(Tinit, 24);
T3_33 = MTensorInitializationData_getTensor(Tinit, 25);
T3_34 = MTensorInitializationData_getTensor(Tinit, 26);
T3_35 = MTensorInitializationData_getTensor(Tinit, 27);
T3_36 = MTensorInitializationData_getTensor(Tinit, 28);
T3_37 = MTensorInitializationData_getTensor(Tinit, 29);
T3_38 = MTensorInitializationData_getTensor(Tinit, 30);
T3_39 = MTensorInitializationData_getTensor(Tinit, 31);
T3_4 = MTensorInitializationData_getTensor(Tinit, 32);
T3_40 = MTensorInitializationData_getTensor(Tinit, 33);
T3_41 = MTensorInitializationData_getTensor(Tinit, 34);
T3_42 = MTensorInitializationData_getTensor(Tinit, 35);
T3_43 = MTensorInitializationData_getTensor(Tinit, 36);
T3_44 = MTensorInitializationData_getTensor(Tinit, 37);
T3_45 = MTensorInitializationData_getTensor(Tinit, 38);
T3_46 = MTensorInitializationData_getTensor(Tinit, 39);
T3_47 = MTensorInitializationData_getTensor(Tinit, 40);
T3_48 = MTensorInitializationData_getTensor(Tinit, 41);
T3_49 = MTensorInitializationData_getTensor(Tinit, 42);
T3_5 = MTensorInitializationData_getTensor(Tinit, 43);
T3_50 = MTensorInitializationData_getTensor(Tinit, 44);
T3_51 = MTensorInitializationData_getTensor(Tinit, 45);
T3_52 = MTensorInitializationData_getTensor(Tinit, 46);
T3_53 = MTensorInitializationData_getTensor(Tinit, 47);
T3_54 = MTensorInitializationData_getTensor(Tinit, 48);
T3_55 = MTensorInitializationData_getTensor(Tinit, 49);
T3_56 = MTensorInitializationData_getTensor(Tinit, 50);
T3_57 = MTensorInitializationData_getTensor(Tinit, 51);
T3_58 = MTensorInitializationData_getTensor(Tinit, 52);
T3_59 = MTensorInitializationData_getTensor(Tinit, 53);
T3_6 = MTensorInitializationData_getTensor(Tinit, 54);
T3_60 = MTensorInitializationData_getTensor(Tinit, 55);
T3_61 = MTensorInitializationData_getTensor(Tinit, 56);
T3_62 = MTensorInitializationData_getTensor(Tinit, 57);
T3_63 = MTensorInitializationData_getTensor(Tinit, 58);
T3_64 = MTensorInitializationData_getTensor(Tinit, 59);
T3_65 = MTensorInitializationData_getTensor(Tinit, 60);
T3_66 = MTensorInitializationData_getTensor(Tinit, 61);
T3_67 = MTensorInitializationData_getTensor(Tinit, 62);
T3_68 = MTensorInitializationData_getTensor(Tinit, 63);
T3_69 = MTensorInitializationData_getTensor(Tinit, 64);
T3_7 = MTensorInitializationData_getTensor(Tinit, 65);
T3_70 = MTensorInitializationData_getTensor(Tinit, 66);
T3_71 = MTensorInitializationData_getTensor(Tinit, 67);
T3_72 = MTensorInitializationData_getTensor(Tinit, 68);
T3_73 = MTensorInitializationData_getTensor(Tinit, 69);
T3_74 = MTensorInitializationData_getTensor(Tinit, 70);
T3_75 = MTensorInitializationData_getTensor(Tinit, 71);
T3_76 = MTensorInitializationData_getTensor(Tinit, 72);
T3_77 = MTensorInitializationData_getTensor(Tinit, 73);
T3_78 = MTensorInitializationData_getTensor(Tinit, 74);
T3_79 = MTensorInitializationData_getTensor(Tinit, 75);
T3_8 = MTensorInitializationData_getTensor(Tinit, 76);
T3_80 = MTensorInitializationData_getTensor(Tinit, 77);
T3_81 = MTensorInitializationData_getTensor(Tinit, 78);
T3_82 = MTensorInitializationData_getTensor(Tinit, 79);
T3_83 = MTensorInitializationData_getTensor(Tinit, 80);
T3_84 = MTensorInitializationData_getTensor(Tinit, 81);
T3_85 = MTensorInitializationData_getTensor(Tinit, 82);
T3_86 = MTensorInitializationData_getTensor(Tinit, 83);
T3_87 = MTensorInitializationData_getTensor(Tinit, 84);
T3_88 = MTensorInitializationData_getTensor(Tinit, 85);
T3_89 = MTensorInitializationData_getTensor(Tinit, 86);
T3_9 = MTensorInitializationData_getTensor(Tinit, 87);
T3_90 = MTensorInitializationData_getTensor(Tinit, 88);
T3_91 = MTensorInitializationData_getTensor(Tinit, 89);
T3_92 = MTensorInitializationData_getTensor(Tinit, 90);
T3_93 = MTensorInitializationData_getTensor(Tinit, 91);
T3_94 = MTensorInitializationData_getTensor(Tinit, 92);
T3_0 = &A1;
I3_0 = A2;
T3_1 = &A3;
P1 = MTensor_getRealDataMacro(*T3_1);
D1 = MTensor_getDimensionsMacro(*T3_1);
I3_1 = A4;
I3_2 = A5;
R3_0 = A6;
R3_1 = A7;
B3_0 = I3_0 == I3_3;
if( !B3_0)
{
goto lab84;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_2, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_3, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_2 = P1[S0];
}
R3_3 = R3_2 * R3_2;
R3_4 = sqrt(R3_3);
R3_5 = -R3_0;
R3_6 = (mreal) I3_3;
R3_6 = R3_6 + R3_5;
err = funStructCompile->MTensor_getMTensorInitialized(T3_4, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_2;
MArgument_getMTensorAddress(FPA[1]) = T3_2;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_7;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_3;
MArgument_getMTensorAddress(FPA[1]) = T3_3;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_8;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_10 = (mreal) I3_1;
R3_11 = R3_9 * R3_10;
R3_10 = (mreal) I3_3;
R3_10 = R3_10 + R3_11;
MArgument_getMTensorAddress(FPA[0]) = T3_4;
MArgument_getMTensorAddress(FPA[1]) = T3_4;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_12;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_13 = sqrt(R3_7);
R3_14 = sqrt(R3_8);
R3_15 = -R3_2;
R3_16 = (mreal) I3_2;
R3_17 = R3_9 * R3_16;
R3_16 = sqrt(R3_12);
R3_18 = -R3_13;
R3_19 = R3_18 + R3_4;
R3_20 = R3_19 < 0 ? -R3_19 : R3_19;
R3_21 = pow(R3_1, R3_0);
R3_23 = R3_22 * R3_0;
R3_24 = pow(R3_3, R3_23);
R3_25 = -R3_14;
R3_26 = R3_25 + R3_4;
R3_27 = R3_26 < 0 ? -R3_26 : R3_26;
R3_28 = -R3_4;
R3_29 = -R3_16;
R3_30 = R3_29 + R3_4;
R3_31 = R3_30 < 0 ? -R3_30 : R3_30;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_33 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_33 = 1;
while( S0)
{
if( S0 & 1)
{
R3_33 = S1 * R3_33;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_33 = 1 / R3_33;
}
}
R3_34 = 1 / R3_33;
R3_33 = (mreal) I3_7;
R3_33 = R3_33 * R3_0;
R3_35 = pow(R3_1, R3_33);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_33 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_33 = 1;
while( S0)
{
if( S0 & 1)
{
R3_33 = S1 * R3_33;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_33 = 1 / R3_33;
}
}
R3_37 = 1 / R3_33;
R3_33 = pow(R3_20, R3_6);
R3_38 = pow(R3_27, R3_6);
R3_39 = pow(R3_31, R3_6);
R3_40 = pow(R3_7, R3_10);
R3_41 = pow(R3_8, R3_10);
R3_42 = pow(R3_12, R3_10);
R3_43 = R3_13 + R3_15;
R3_44 = R3_43 * R3_43;
R3_43 = pow(R3_44, R3_17);
R3_44 = R3_14 + R3_15;
R3_45 = R3_44 * R3_44;
R3_44 = pow(R3_45, R3_17);
R3_45 = R3_16 + R3_15;
R3_46 = R3_45 * R3_45;
R3_45 = pow(R3_46, R3_17);
R3_46 = pow(R3_20, R3_0);
R3_47 = R3_13 + R3_28;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_47), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_47 = (mreal) I3_9;
R3_46 = R3_46 * R3_47;
R3_47 = R3_21 + R3_24 + R3_46;
R3_46 = R3_47 * R3_47;
R3_47 = pow(R3_27, R3_0);
R3_48 = R3_14 + R3_28;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_48), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_48 = (mreal) I3_9;
R3_47 = R3_47 * R3_48;
R3_48 = R3_21 + R3_24 + R3_47;
R3_47 = R3_48 * R3_48;
R3_48 = pow(R3_31, R3_0);
R3_49 = R3_16 + R3_28;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_49), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_49 = (mreal) I3_9;
R3_48 = R3_48 * R3_49;
R3_49 = R3_21 + R3_24 + R3_48;
R3_48 = R3_49 * R3_49;
R3_49 = R3_32 * R3_34 * R3_35 * R3_37 * R3_33 * R3_38 * R3_39 * R3_40 * R3_41 * R3_42 * R3_43 * R3_44 * R3_45 * R3_46 * R3_47 * R3_48;
R3_74 = R3_49;
goto lab1261;
lab84:
B3_1 = I3_0 == I3_4;
if( !B3_1)
{
goto lab164;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_5, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_5, 3, T3_6);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_7, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_6, *T3_7, 3, T3_8);
if( err)
{
goto error_label;
}
R3_34 = -R3_0;
R3_35 = (mreal) I3_3;
R3_35 = R3_35 + R3_34;
err = funStructCompile->MTensor_getMTensorInitialized(T3_9, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_37 = P1[S0];
}
R3_33 = R3_37 * R3_37;
R3_38 = sqrt(R3_33);
MArgument_getMTensorAddress(FPA[0]) = T3_5;
MArgument_getMTensorAddress(FPA[1]) = T3_5;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_39;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_8;
MArgument_getMTensorAddress(FPA[1]) = T3_8;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_40;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_41 = (mreal) I3_1;
R3_42 = R3_9 * R3_41;
R3_41 = (mreal) I3_3;
R3_41 = R3_41 + R3_42;
MArgument_getMTensorAddress(FPA[0]) = T3_9;
MArgument_getMTensorAddress(FPA[1]) = T3_9;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_43;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_44 = sqrt(R3_39);
R3_45 = sqrt(R3_43);
R3_46 = -R3_37;
R3_47 = (mreal) I3_2;
R3_48 = R3_9 * R3_47;
R3_47 = R3_40 < 0 ? -R3_40 : R3_40;
R3_50 = pow(R3_1, R3_0);
R3_51 = R3_22 * R3_0;
R3_52 = -R3_44;
R3_53 = R3_52 + R3_38;
R3_54 = R3_53 < 0 ? -R3_53 : R3_53;
R3_55 = pow(R3_33, R3_51);
R3_56 = -R3_45;
R3_57 = R3_56 + R3_38;
R3_58 = R3_57 < 0 ? -R3_57 : R3_57;
R3_59 = -R3_38;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_60 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_60 = 1;
while( S0)
{
if( S0 & 1)
{
R3_60 = S1 * R3_60;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_60 = 1 / R3_60;
}
}
R3_61 = 1 / R3_60;
R3_60 = (mreal) I3_7;
R3_60 = R3_60 * R3_0;
R3_62 = pow(R3_1, R3_60);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_60 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_60 = 1;
while( S0)
{
if( S0 & 1)
{
R3_60 = S1 * R3_60;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_60 = 1 / R3_60;
}
}
R3_63 = 1 / R3_60;
R3_60 = R3_22 * R3_35;
R3_64 = pow(R3_47, R3_60);
R3_60 = pow(R3_54, R3_35);
R3_65 = pow(R3_58, R3_35);
R3_66 = pow(R3_39, R3_41);
R3_67 = pow(R3_40, R3_41);
R3_68 = pow(R3_43, R3_41);
R3_69 = R3_44 + R3_46;
R3_70 = R3_69 * R3_69;
R3_69 = pow(R3_70, R3_48);
R3_70 = R3_45 + R3_46;
R3_71 = R3_70 * R3_70;
R3_70 = pow(R3_71, R3_48);
R3_71 = pow(R3_47, R3_51);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_40), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_72 = (mreal) I3_9;
R3_73 = sqrt(R3_72);
R3_71 = R3_71 * R3_73;
R3_73 = R3_50 + R3_71;
R3_71 = R3_73 * R3_73;
R3_73 = pow(R3_54, R3_0);
R3_72 = R3_44 + R3_59;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_72), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_72 = (mreal) I3_9;
R3_73 = R3_73 * R3_72;
R3_72 = R3_50 + R3_55 + R3_73;
R3_73 = R3_72 * R3_72;
R3_72 = pow(R3_58, R3_0);
R3_74 = R3_45 + R3_59;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_74), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_74 = (mreal) I3_9;
R3_72 = R3_72 * R3_74;
R3_74 = R3_50 + R3_55 + R3_72;
R3_72 = R3_74 * R3_74;
R3_74 = R3_32 * R3_61 * R3_62 * R3_63 * R3_64 * R3_60 * R3_65 * R3_66 * R3_67 * R3_68 * R3_69 * R3_70 * R3_71 * R3_73 * R3_72;
R3_100 = R3_74;
goto lab1260;
lab164:
B3_2 = I3_0 == I3_5;
if( !B3_2)
{
goto lab244;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_10, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_10, 3, T3_11);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_12, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_11, *T3_12, 3, T3_13);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_14, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
R3_61 = -R3_0;
R3_62 = (mreal) I3_3;
R3_62 = R3_62 + R3_61;
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_63 = P1[S0];
}
R3_64 = R3_63 * R3_63;
R3_60 = sqrt(R3_64);
MArgument_getMTensorAddress(FPA[0]) = T3_14;
MArgument_getMTensorAddress(FPA[1]) = T3_14;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_65;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_12;
MArgument_getMTensorAddress(FPA[1]) = T3_12;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_66;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_67 = (mreal) I3_1;
R3_68 = R3_9 * R3_67;
R3_67 = (mreal) I3_3;
R3_67 = R3_67 + R3_68;
MArgument_getMTensorAddress(FPA[0]) = T3_13;
MArgument_getMTensorAddress(FPA[1]) = T3_13;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_69;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_70 = sqrt(R3_65);
R3_71 = sqrt(R3_66);
R3_73 = -R3_63;
R3_72 = (mreal) I3_2;
R3_75 = R3_9 * R3_72;
R3_72 = R3_69 < 0 ? -R3_69 : R3_69;
R3_76 = pow(R3_1, R3_0);
R3_77 = R3_22 * R3_0;
R3_78 = -R3_70;
R3_79 = R3_78 + R3_60;
R3_80 = R3_79 < 0 ? -R3_79 : R3_79;
R3_81 = pow(R3_64, R3_77);
R3_82 = -R3_71;
R3_83 = R3_82 + R3_60;
R3_84 = R3_83 < 0 ? -R3_83 : R3_83;
R3_85 = -R3_60;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_86 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_86 = 1;
while( S0)
{
if( S0 & 1)
{
R3_86 = S1 * R3_86;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_86 = 1 / R3_86;
}
}
R3_87 = 1 / R3_86;
R3_86 = (mreal) I3_7;
R3_86 = R3_86 * R3_0;
R3_88 = pow(R3_1, R3_86);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_86 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_86 = 1;
while( S0)
{
if( S0 & 1)
{
R3_86 = S1 * R3_86;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_86 = 1 / R3_86;
}
}
R3_89 = 1 / R3_86;
R3_86 = R3_22 * R3_62;
R3_90 = pow(R3_72, R3_86);
R3_86 = pow(R3_80, R3_62);
R3_91 = pow(R3_84, R3_62);
R3_92 = pow(R3_65, R3_67);
R3_93 = pow(R3_66, R3_67);
R3_94 = pow(R3_69, R3_67);
R3_95 = R3_70 + R3_73;
R3_96 = R3_95 * R3_95;
R3_95 = pow(R3_96, R3_75);
R3_96 = R3_71 + R3_73;
R3_97 = R3_96 * R3_96;
R3_96 = pow(R3_97, R3_75);
R3_97 = pow(R3_72, R3_77);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_69), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_98 = (mreal) I3_9;
R3_99 = sqrt(R3_98);
R3_97 = R3_97 * R3_99;
R3_99 = R3_76 + R3_97;
R3_97 = R3_99 * R3_99;
R3_99 = pow(R3_80, R3_0);
R3_98 = R3_70 + R3_85;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_98), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_98 = (mreal) I3_9;
R3_99 = R3_99 * R3_98;
R3_98 = R3_76 + R3_81 + R3_99;
R3_99 = R3_98 * R3_98;
R3_98 = pow(R3_84, R3_0);
R3_100 = R3_71 + R3_85;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_100), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_100 = (mreal) I3_9;
R3_98 = R3_98 * R3_100;
R3_100 = R3_76 + R3_81 + R3_98;
R3_98 = R3_100 * R3_100;
R3_100 = R3_32 * R3_87 * R3_88 * R3_89 * R3_90 * R3_86 * R3_91 * R3_92 * R3_93 * R3_94 * R3_95 * R3_96 * R3_97 * R3_99 * R3_98;
R3_126 = R3_100;
goto lab1259;
lab244:
B3_3 = I3_0 == I3_6;
if( !B3_3)
{
goto lab324;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_15, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_15, 3, T3_16);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_17, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_16, *T3_17, 3, T3_18);
if( err)
{
goto error_label;
}
R3_87 = -R3_0;
R3_88 = (mreal) I3_3;
R3_88 = R3_88 + R3_87;
err = funStructCompile->MTensor_getMTensorInitialized(T3_19, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_89 = P1[S0];
}
R3_90 = R3_89 * R3_89;
R3_86 = sqrt(R3_90);
MArgument_getMTensorAddress(FPA[0]) = T3_15;
MArgument_getMTensorAddress(FPA[1]) = T3_15;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_91;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_19;
MArgument_getMTensorAddress(FPA[1]) = T3_19;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_92;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_93 = (mreal) I3_1;
R3_94 = R3_9 * R3_93;
R3_93 = (mreal) I3_3;
R3_93 = R3_93 + R3_94;
MArgument_getMTensorAddress(FPA[0]) = T3_18;
MArgument_getMTensorAddress(FPA[1]) = T3_18;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_95;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_96 = sqrt(R3_91);
R3_97 = sqrt(R3_92);
R3_99 = -R3_89;
R3_98 = (mreal) I3_2;
R3_101 = R3_9 * R3_98;
R3_98 = R3_95 < 0 ? -R3_95 : R3_95;
R3_102 = pow(R3_1, R3_0);
R3_103 = R3_22 * R3_0;
R3_104 = -R3_96;
R3_105 = R3_104 + R3_86;
R3_106 = R3_105 < 0 ? -R3_105 : R3_105;
R3_107 = pow(R3_90, R3_103);
R3_108 = -R3_97;
R3_109 = R3_108 + R3_86;
R3_110 = R3_109 < 0 ? -R3_109 : R3_109;
R3_111 = -R3_86;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_112 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_112 = 1;
while( S0)
{
if( S0 & 1)
{
R3_112 = S1 * R3_112;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_112 = 1 / R3_112;
}
}
R3_113 = 1 / R3_112;
R3_112 = (mreal) I3_7;
R3_112 = R3_112 * R3_0;
R3_114 = pow(R3_1, R3_112);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_112 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_112 = 1;
while( S0)
{
if( S0 & 1)
{
R3_112 = S1 * R3_112;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_112 = 1 / R3_112;
}
}
R3_115 = 1 / R3_112;
R3_112 = R3_22 * R3_88;
R3_116 = pow(R3_98, R3_112);
R3_112 = pow(R3_106, R3_88);
R3_117 = pow(R3_110, R3_88);
R3_118 = pow(R3_91, R3_93);
R3_119 = pow(R3_92, R3_93);
R3_120 = pow(R3_95, R3_93);
R3_121 = R3_96 + R3_99;
R3_122 = R3_121 * R3_121;
R3_121 = pow(R3_122, R3_101);
R3_122 = R3_97 + R3_99;
R3_123 = R3_122 * R3_122;
R3_122 = pow(R3_123, R3_101);
R3_123 = pow(R3_98, R3_103);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_95), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_124 = (mreal) I3_9;
R3_125 = sqrt(R3_124);
R3_123 = R3_123 * R3_125;
R3_125 = R3_102 + R3_123;
R3_123 = R3_125 * R3_125;
R3_125 = pow(R3_106, R3_0);
R3_124 = R3_96 + R3_111;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_124), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_124 = (mreal) I3_9;
R3_125 = R3_125 * R3_124;
R3_124 = R3_102 + R3_107 + R3_125;
R3_125 = R3_124 * R3_124;
R3_124 = pow(R3_110, R3_0);
R3_126 = R3_97 + R3_111;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_126), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_126 = (mreal) I3_9;
R3_124 = R3_124 * R3_126;
R3_126 = R3_102 + R3_107 + R3_124;
R3_124 = R3_126 * R3_126;
R3_126 = R3_32 * R3_113 * R3_114 * R3_115 * R3_116 * R3_112 * R3_117 * R3_118 * R3_119 * R3_120 * R3_121 * R3_122 * R3_123 * R3_125 * R3_124;
R3_152 = R3_126;
goto lab1258;
lab324:
B3_4 = I3_0 == I3_10;
if( !B3_4)
{
goto lab404;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_20, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_20, 3, T3_21);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_22, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_21, *T3_22, 3, T3_23);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_24, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
R3_113 = -R3_0;
R3_114 = (mreal) I3_3;
R3_114 = R3_114 + R3_113;
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_115 = P1[S0];
}
R3_116 = R3_115 * R3_115;
R3_112 = sqrt(R3_116);
MArgument_getMTensorAddress(FPA[0]) = T3_24;
MArgument_getMTensorAddress(FPA[1]) = T3_24;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_117;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_20;
MArgument_getMTensorAddress(FPA[1]) = T3_20;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_118;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_119 = (mreal) I3_1;
R3_120 = R3_9 * R3_119;
R3_119 = (mreal) I3_3;
R3_119 = R3_119 + R3_120;
MArgument_getMTensorAddress(FPA[0]) = T3_23;
MArgument_getMTensorAddress(FPA[1]) = T3_23;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_121;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_122 = sqrt(R3_117);
R3_123 = sqrt(R3_118);
R3_125 = -R3_115;
R3_124 = (mreal) I3_2;
R3_127 = R3_9 * R3_124;
R3_124 = R3_121 < 0 ? -R3_121 : R3_121;
R3_128 = pow(R3_1, R3_0);
R3_129 = R3_22 * R3_0;
R3_130 = -R3_122;
R3_131 = R3_130 + R3_112;
R3_132 = R3_131 < 0 ? -R3_131 : R3_131;
R3_133 = pow(R3_116, R3_129);
R3_134 = -R3_123;
R3_135 = R3_134 + R3_112;
R3_136 = R3_135 < 0 ? -R3_135 : R3_135;
R3_137 = -R3_112;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_138 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_138 = 1;
while( S0)
{
if( S0 & 1)
{
R3_138 = S1 * R3_138;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_138 = 1 / R3_138;
}
}
R3_139 = 1 / R3_138;
R3_138 = (mreal) I3_7;
R3_138 = R3_138 * R3_0;
R3_140 = pow(R3_1, R3_138);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_138 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_138 = 1;
while( S0)
{
if( S0 & 1)
{
R3_138 = S1 * R3_138;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_138 = 1 / R3_138;
}
}
R3_141 = 1 / R3_138;
R3_138 = R3_22 * R3_114;
R3_142 = pow(R3_124, R3_138);
R3_138 = pow(R3_132, R3_114);
R3_143 = pow(R3_136, R3_114);
R3_144 = pow(R3_117, R3_119);
R3_145 = pow(R3_118, R3_119);
R3_146 = pow(R3_121, R3_119);
R3_147 = R3_122 + R3_125;
R3_148 = R3_147 * R3_147;
R3_147 = pow(R3_148, R3_127);
R3_148 = R3_123 + R3_125;
R3_149 = R3_148 * R3_148;
R3_148 = pow(R3_149, R3_127);
R3_149 = pow(R3_124, R3_129);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_121), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_150 = (mreal) I3_9;
R3_151 = sqrt(R3_150);
R3_149 = R3_149 * R3_151;
R3_151 = R3_128 + R3_149;
R3_149 = R3_151 * R3_151;
R3_151 = pow(R3_132, R3_0);
R3_150 = R3_122 + R3_137;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_150), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_150 = (mreal) I3_9;
R3_151 = R3_151 * R3_150;
R3_150 = R3_128 + R3_133 + R3_151;
R3_151 = R3_150 * R3_150;
R3_150 = pow(R3_136, R3_0);
R3_152 = R3_123 + R3_137;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_152), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_152 = (mreal) I3_9;
R3_150 = R3_150 * R3_152;
R3_152 = R3_128 + R3_133 + R3_150;
R3_150 = R3_152 * R3_152;
R3_152 = R3_32 * R3_139 * R3_140 * R3_141 * R3_142 * R3_138 * R3_143 * R3_144 * R3_145 * R3_146 * R3_147 * R3_148 * R3_149 * R3_151 * R3_150;
R3_173 = R3_152;
goto lab1257;
lab404:
B3_5 = I3_0 == I3_8;
if( !B3_5)
{
goto lab479;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_25, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_25, 3, T3_26);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_27, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_26, *T3_27, 3, T3_28);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_29, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_26, *T3_29, 3, T3_30);
if( err)
{
goto error_label;
}
R3_139 = -R3_0;
R3_140 = (mreal) I3_3;
R3_140 = R3_140 + R3_139;
R3_141 = R3_22 * R3_140;
MArgument_getMTensorAddress(FPA[0]) = T3_25;
MArgument_getMTensorAddress(FPA[1]) = T3_25;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_142;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_28;
MArgument_getMTensorAddress(FPA[1]) = T3_28;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_138;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_143 = (mreal) I3_1;
R3_144 = R3_9 * R3_143;
R3_143 = (mreal) I3_3;
R3_143 = R3_143 + R3_144;
MArgument_getMTensorAddress(FPA[0]) = T3_30;
MArgument_getMTensorAddress(FPA[1]) = T3_30;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_145;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_146 = sqrt(R3_142);
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_147 = P1[S0];
}
R3_148 = R3_138 < 0 ? -R3_138 : R3_138;
R3_149 = pow(R3_1, R3_0);
R3_151 = R3_145 < 0 ? -R3_145 : R3_145;
R3_150 = R3_22 * R3_0;
R3_153 = R3_147 * R3_147;
R3_154 = -R3_146;
R3_155 = sqrt(R3_153);
R3_156 = R3_154 + R3_155;
R3_157 = R3_156 < 0 ? -R3_156 : R3_156;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_158 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_158 = 1;
while( S0)
{
if( S0 & 1)
{
R3_158 = S1 * R3_158;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_158 = 1 / R3_158;
}
}
R3_159 = 1 / R3_158;
R3_158 = (mreal) I3_7;
R3_158 = R3_158 * R3_0;
R3_160 = pow(R3_1, R3_158);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_158 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_158 = 1;
while( S0)
{
if( S0 & 1)
{
R3_158 = S1 * R3_158;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_158 = 1 / R3_158;
}
}
R3_161 = 1 / R3_158;
R3_158 = pow(R3_148, R3_141);
R3_162 = pow(R3_151, R3_141);
R3_163 = pow(R3_157, R3_140);
R3_164 = pow(R3_142, R3_143);
R3_165 = pow(R3_138, R3_143);
R3_166 = pow(R3_145, R3_143);
R3_167 = -R3_147;
R3_168 = R3_146 + R3_167;
R3_167 = R3_168 * R3_168;
R3_168 = (mreal) I3_2;
R3_169 = R3_9 * R3_168;
R3_168 = pow(R3_167, R3_169);
R3_167 = pow(R3_148, R3_150);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_138), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_169 = (mreal) I3_9;
R3_170 = sqrt(R3_169);
R3_167 = R3_167 * R3_170;
R3_170 = R3_149 + R3_167;
R3_167 = R3_170 * R3_170;
R3_170 = pow(R3_151, R3_150);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_145), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_169 = (mreal) I3_9;
R3_171 = sqrt(R3_169);
R3_170 = R3_170 * R3_171;
R3_171 = R3_149 + R3_170;
R3_170 = R3_171 * R3_171;
R3_171 = pow(R3_153, R3_150);
R3_169 = pow(R3_157, R3_0);
R3_172 = -R3_155;
R3_173 = R3_146 + R3_172;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_173), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_173 = (mreal) I3_9;
R3_169 = R3_169 * R3_173;
R3_173 = R3_149 + R3_171 + R3_169;
R3_171 = R3_173 * R3_173;
R3_173 = R3_32 * R3_159 * R3_160 * R3_161 * R3_158 * R3_162 * R3_163 * R3_164 * R3_165 * R3_166 * R3_168 * R3_167 * R3_170 * R3_171;
R3_193 = R3_173;
goto lab1256;
lab479:
B3_6 = I3_0 == I3_11;
if( !B3_6)
{
goto lab555;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_31, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_31, 3, T3_32);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_33, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_32, *T3_33, 3, T3_34);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_35, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_35, 3, T3_36);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_36, *T3_33, 3, T3_37);
if( err)
{
goto error_label;
}
R3_159 = -R3_0;
R3_160 = (mreal) I3_3;
R3_160 = R3_160 + R3_159;
R3_161 = R3_22 * R3_160;
MArgument_getMTensorAddress(FPA[0]) = T3_31;
MArgument_getMTensorAddress(FPA[1]) = T3_31;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_158;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_34;
MArgument_getMTensorAddress(FPA[1]) = T3_34;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_162;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_163 = (mreal) I3_1;
R3_164 = R3_9 * R3_163;
R3_163 = (mreal) I3_3;
R3_163 = R3_163 + R3_164;
MArgument_getMTensorAddress(FPA[0]) = T3_37;
MArgument_getMTensorAddress(FPA[1]) = T3_37;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_165;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_166 = sqrt(R3_158);
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_168 = P1[S0];
}
R3_167 = R3_162 < 0 ? -R3_162 : R3_162;
R3_170 = pow(R3_1, R3_0);
R3_171 = R3_165 < 0 ? -R3_165 : R3_165;
R3_169 = R3_22 * R3_0;
R3_172 = R3_168 * R3_168;
R3_174 = -R3_166;
R3_175 = sqrt(R3_172);
R3_176 = R3_174 + R3_175;
R3_177 = R3_176 < 0 ? -R3_176 : R3_176;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_178 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_178 = 1;
while( S0)
{
if( S0 & 1)
{
R3_178 = S1 * R3_178;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_178 = 1 / R3_178;
}
}
R3_179 = 1 / R3_178;
R3_178 = (mreal) I3_7;
R3_178 = R3_178 * R3_0;
R3_180 = pow(R3_1, R3_178);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_178 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_178 = 1;
while( S0)
{
if( S0 & 1)
{
R3_178 = S1 * R3_178;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_178 = 1 / R3_178;
}
}
R3_181 = 1 / R3_178;
R3_178 = pow(R3_167, R3_161);
R3_182 = pow(R3_171, R3_161);
R3_183 = pow(R3_177, R3_160);
R3_184 = pow(R3_158, R3_163);
R3_185 = pow(R3_162, R3_163);
R3_186 = pow(R3_165, R3_163);
R3_187 = -R3_168;
R3_188 = R3_166 + R3_187;
R3_187 = R3_188 * R3_188;
R3_188 = (mreal) I3_2;
R3_189 = R3_9 * R3_188;
R3_188 = pow(R3_187, R3_189);
R3_187 = pow(R3_167, R3_169);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_162), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_189 = (mreal) I3_9;
R3_190 = sqrt(R3_189);
R3_187 = R3_187 * R3_190;
R3_190 = R3_170 + R3_187;
R3_187 = R3_190 * R3_190;
R3_190 = pow(R3_171, R3_169);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_165), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_189 = (mreal) I3_9;
R3_191 = sqrt(R3_189);
R3_190 = R3_190 * R3_191;
R3_191 = R3_170 + R3_190;
R3_190 = R3_191 * R3_191;
R3_191 = pow(R3_172, R3_169);
R3_189 = pow(R3_177, R3_0);
R3_192 = -R3_175;
R3_193 = R3_166 + R3_192;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_193), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_193 = (mreal) I3_9;
R3_189 = R3_189 * R3_193;
R3_193 = R3_170 + R3_191 + R3_189;
R3_191 = R3_193 * R3_193;
R3_193 = R3_32 * R3_179 * R3_180 * R3_181 * R3_178 * R3_182 * R3_183 * R3_184 * R3_185 * R3_186 * R3_188 * R3_187 * R3_190 * R3_191;
R3_213 = R3_193;
goto lab1255;
lab555:
B3_7 = I3_0 == I3_12;
if( !B3_7)
{
goto lab631;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_38, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_38, 3, T3_39);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_40, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_39, *T3_40, 3, T3_41);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_40, 3, T3_42);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_43, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_42, *T3_43, 3, T3_44);
if( err)
{
goto error_label;
}
R3_179 = -R3_0;
R3_180 = (mreal) I3_3;
R3_180 = R3_180 + R3_179;
R3_181 = R3_22 * R3_180;
MArgument_getMTensorAddress(FPA[0]) = T3_38;
MArgument_getMTensorAddress(FPA[1]) = T3_38;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_178;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_41;
MArgument_getMTensorAddress(FPA[1]) = T3_41;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_182;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_183 = (mreal) I3_1;
R3_184 = R3_9 * R3_183;
R3_183 = (mreal) I3_3;
R3_183 = R3_183 + R3_184;
MArgument_getMTensorAddress(FPA[0]) = T3_44;
MArgument_getMTensorAddress(FPA[1]) = T3_44;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_185;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_186 = sqrt(R3_178);
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_188 = P1[S0];
}
R3_187 = R3_182 < 0 ? -R3_182 : R3_182;
R3_190 = pow(R3_1, R3_0);
R3_191 = R3_185 < 0 ? -R3_185 : R3_185;
R3_189 = R3_22 * R3_0;
R3_192 = R3_188 * R3_188;
R3_194 = -R3_186;
R3_195 = sqrt(R3_192);
R3_196 = R3_194 + R3_195;
R3_197 = R3_196 < 0 ? -R3_196 : R3_196;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_198 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_198 = 1;
while( S0)
{
if( S0 & 1)
{
R3_198 = S1 * R3_198;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_198 = 1 / R3_198;
}
}
R3_199 = 1 / R3_198;
R3_198 = (mreal) I3_7;
R3_198 = R3_198 * R3_0;
R3_200 = pow(R3_1, R3_198);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_198 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_198 = 1;
while( S0)
{
if( S0 & 1)
{
R3_198 = S1 * R3_198;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_198 = 1 / R3_198;
}
}
R3_201 = 1 / R3_198;
R3_198 = pow(R3_187, R3_181);
R3_202 = pow(R3_191, R3_181);
R3_203 = pow(R3_197, R3_180);
R3_204 = pow(R3_178, R3_183);
R3_205 = pow(R3_182, R3_183);
R3_206 = pow(R3_185, R3_183);
R3_207 = -R3_188;
R3_208 = R3_186 + R3_207;
R3_207 = R3_208 * R3_208;
R3_208 = (mreal) I3_2;
R3_209 = R3_9 * R3_208;
R3_208 = pow(R3_207, R3_209);
R3_207 = pow(R3_187, R3_189);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_182), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_209 = (mreal) I3_9;
R3_210 = sqrt(R3_209);
R3_207 = R3_207 * R3_210;
R3_210 = R3_190 + R3_207;
R3_207 = R3_210 * R3_210;
R3_210 = pow(R3_191, R3_189);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_185), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_209 = (mreal) I3_9;
R3_211 = sqrt(R3_209);
R3_210 = R3_210 * R3_211;
R3_211 = R3_190 + R3_210;
R3_210 = R3_211 * R3_211;
R3_211 = pow(R3_192, R3_189);
R3_209 = pow(R3_197, R3_0);
R3_212 = -R3_195;
R3_213 = R3_186 + R3_212;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_213), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_213 = (mreal) I3_9;
R3_209 = R3_209 * R3_213;
R3_213 = R3_190 + R3_211 + R3_209;
R3_211 = R3_213 * R3_213;
R3_213 = R3_32 * R3_199 * R3_200 * R3_201 * R3_198 * R3_202 * R3_203 * R3_204 * R3_205 * R3_206 * R3_208 * R3_207 * R3_210 * R3_211;
R3_238 = R3_213;
goto lab1254;
lab631:
B3_8 = I3_0 == I3_13;
if( !B3_8)
{
goto lab711;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_45, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_45, 3, T3_46);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_47, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_46, *T3_47, 3, T3_48);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_49, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
R3_199 = -R3_0;
R3_200 = (mreal) I3_3;
R3_200 = R3_200 + R3_199;
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_201 = P1[S0];
}
R3_198 = R3_201 * R3_201;
R3_202 = sqrt(R3_198);
MArgument_getMTensorAddress(FPA[0]) = T3_49;
MArgument_getMTensorAddress(FPA[1]) = T3_49;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_203;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_47;
MArgument_getMTensorAddress(FPA[1]) = T3_47;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_204;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_205 = (mreal) I3_1;
R3_206 = R3_9 * R3_205;
R3_205 = (mreal) I3_3;
R3_205 = R3_205 + R3_206;
MArgument_getMTensorAddress(FPA[0]) = T3_48;
MArgument_getMTensorAddress(FPA[1]) = T3_48;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_208;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_207 = sqrt(R3_203);
R3_210 = sqrt(R3_204);
R3_211 = -R3_201;
R3_209 = (mreal) I3_2;
R3_212 = R3_9 * R3_209;
R3_209 = R3_208 < 0 ? -R3_208 : R3_208;
R3_214 = pow(R3_1, R3_0);
R3_215 = R3_22 * R3_0;
R3_216 = -R3_207;
R3_217 = R3_216 + R3_202;
R3_218 = R3_217 < 0 ? -R3_217 : R3_217;
R3_219 = pow(R3_198, R3_215);
R3_220 = -R3_210;
R3_221 = R3_220 + R3_202;
R3_222 = R3_221 < 0 ? -R3_221 : R3_221;
R3_223 = -R3_202;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_224 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_224 = 1;
while( S0)
{
if( S0 & 1)
{
R3_224 = S1 * R3_224;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_224 = 1 / R3_224;
}
}
R3_225 = 1 / R3_224;
R3_224 = (mreal) I3_7;
R3_224 = R3_224 * R3_0;
R3_226 = pow(R3_1, R3_224);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_224 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_224 = 1;
while( S0)
{
if( S0 & 1)
{
R3_224 = S1 * R3_224;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_224 = 1 / R3_224;
}
}
R3_227 = 1 / R3_224;
R3_224 = R3_22 * R3_200;
R3_228 = pow(R3_209, R3_224);
R3_224 = pow(R3_218, R3_200);
R3_229 = pow(R3_222, R3_200);
R3_230 = pow(R3_203, R3_205);
R3_231 = pow(R3_204, R3_205);
R3_232 = pow(R3_208, R3_205);
R3_233 = R3_207 + R3_211;
R3_234 = R3_233 * R3_233;
R3_233 = pow(R3_234, R3_212);
R3_234 = R3_210 + R3_211;
R3_235 = R3_234 * R3_234;
R3_234 = pow(R3_235, R3_212);
R3_235 = pow(R3_209, R3_215);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_208), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_236 = (mreal) I3_9;
R3_237 = sqrt(R3_236);
R3_235 = R3_235 * R3_237;
R3_237 = R3_214 + R3_235;
R3_235 = R3_237 * R3_237;
R3_237 = pow(R3_218, R3_0);
R3_236 = R3_207 + R3_223;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_236), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_236 = (mreal) I3_9;
R3_237 = R3_237 * R3_236;
R3_236 = R3_214 + R3_219 + R3_237;
R3_237 = R3_236 * R3_236;
R3_236 = pow(R3_222, R3_0);
R3_238 = R3_210 + R3_223;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_238), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_238 = (mreal) I3_9;
R3_236 = R3_236 * R3_238;
R3_238 = R3_214 + R3_219 + R3_236;
R3_236 = R3_238 * R3_238;
R3_238 = R3_32 * R3_225 * R3_226 * R3_227 * R3_228 * R3_224 * R3_229 * R3_230 * R3_231 * R3_232 * R3_233 * R3_234 * R3_235 * R3_237 * R3_236;
R3_264 = R3_238;
goto lab1253;
lab711:
B3_9 = I3_0 == I3_14;
if( !B3_9)
{
goto lab791;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_50, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_50, 3, T3_51);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_52, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_51, *T3_52, 3, T3_53);
if( err)
{
goto error_label;
}
R3_225 = -R3_0;
R3_226 = (mreal) I3_3;
R3_226 = R3_226 + R3_225;
err = funStructCompile->MTensor_getMTensorInitialized(T3_54, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_227 = P1[S0];
}
R3_228 = R3_227 * R3_227;
R3_224 = sqrt(R3_228);
MArgument_getMTensorAddress(FPA[0]) = T3_52;
MArgument_getMTensorAddress(FPA[1]) = T3_52;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_229;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_53;
MArgument_getMTensorAddress(FPA[1]) = T3_53;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_230;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_231 = (mreal) I3_1;
R3_232 = R3_9 * R3_231;
R3_231 = (mreal) I3_3;
R3_231 = R3_231 + R3_232;
MArgument_getMTensorAddress(FPA[0]) = T3_54;
MArgument_getMTensorAddress(FPA[1]) = T3_54;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_233;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_234 = sqrt(R3_229);
R3_235 = sqrt(R3_233);
R3_237 = -R3_227;
R3_236 = (mreal) I3_2;
R3_239 = R3_9 * R3_236;
R3_236 = R3_230 < 0 ? -R3_230 : R3_230;
R3_240 = pow(R3_1, R3_0);
R3_241 = R3_22 * R3_0;
R3_242 = -R3_234;
R3_243 = R3_242 + R3_224;
R3_244 = R3_243 < 0 ? -R3_243 : R3_243;
R3_245 = pow(R3_228, R3_241);
R3_246 = -R3_235;
R3_247 = R3_246 + R3_224;
R3_248 = R3_247 < 0 ? -R3_247 : R3_247;
R3_249 = -R3_224;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_250 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_250 = 1;
while( S0)
{
if( S0 & 1)
{
R3_250 = S1 * R3_250;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_250 = 1 / R3_250;
}
}
R3_251 = 1 / R3_250;
R3_250 = (mreal) I3_7;
R3_250 = R3_250 * R3_0;
R3_252 = pow(R3_1, R3_250);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_250 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_250 = 1;
while( S0)
{
if( S0 & 1)
{
R3_250 = S1 * R3_250;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_250 = 1 / R3_250;
}
}
R3_253 = 1 / R3_250;
R3_250 = R3_22 * R3_226;
R3_254 = pow(R3_236, R3_250);
R3_250 = pow(R3_244, R3_226);
R3_255 = pow(R3_248, R3_226);
R3_256 = pow(R3_229, R3_231);
R3_257 = pow(R3_230, R3_231);
R3_258 = pow(R3_233, R3_231);
R3_259 = R3_234 + R3_237;
R3_260 = R3_259 * R3_259;
R3_259 = pow(R3_260, R3_239);
R3_260 = R3_235 + R3_237;
R3_261 = R3_260 * R3_260;
R3_260 = pow(R3_261, R3_239);
R3_261 = pow(R3_236, R3_241);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_230), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_262 = (mreal) I3_9;
R3_263 = sqrt(R3_262);
R3_261 = R3_261 * R3_263;
R3_263 = R3_240 + R3_261;
R3_261 = R3_263 * R3_263;
R3_263 = pow(R3_244, R3_0);
R3_262 = R3_234 + R3_249;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_262), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_262 = (mreal) I3_9;
R3_263 = R3_263 * R3_262;
R3_262 = R3_240 + R3_245 + R3_263;
R3_263 = R3_262 * R3_262;
R3_262 = pow(R3_248, R3_0);
R3_264 = R3_235 + R3_249;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_264), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_264 = (mreal) I3_9;
R3_262 = R3_262 * R3_264;
R3_264 = R3_240 + R3_245 + R3_262;
R3_262 = R3_264 * R3_264;
R3_264 = R3_32 * R3_251 * R3_252 * R3_253 * R3_254 * R3_250 * R3_255 * R3_256 * R3_257 * R3_258 * R3_259 * R3_260 * R3_261 * R3_263 * R3_262;
R3_285 = R3_264;
goto lab1252;
lab791:
B3_10 = I3_0 == I3_15;
if( !B3_10)
{
goto lab866;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_55, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_55, 3, T3_56);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_57, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_56, *T3_57, 3, T3_58);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_59, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_56, *T3_59, 3, T3_60);
if( err)
{
goto error_label;
}
R3_251 = -R3_0;
R3_252 = (mreal) I3_3;
R3_252 = R3_252 + R3_251;
R3_253 = R3_22 * R3_252;
MArgument_getMTensorAddress(FPA[0]) = T3_58;
MArgument_getMTensorAddress(FPA[1]) = T3_58;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_254;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_59;
MArgument_getMTensorAddress(FPA[1]) = T3_59;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_250;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_255 = (mreal) I3_1;
R3_256 = R3_9 * R3_255;
R3_255 = (mreal) I3_3;
R3_255 = R3_255 + R3_256;
MArgument_getMTensorAddress(FPA[0]) = T3_60;
MArgument_getMTensorAddress(FPA[1]) = T3_60;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_257;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_258 = sqrt(R3_250);
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_259 = P1[S0];
}
R3_260 = R3_254 < 0 ? -R3_254 : R3_254;
R3_261 = pow(R3_1, R3_0);
R3_263 = R3_257 < 0 ? -R3_257 : R3_257;
R3_262 = R3_22 * R3_0;
R3_265 = R3_259 * R3_259;
R3_266 = -R3_258;
R3_267 = sqrt(R3_265);
R3_268 = R3_266 + R3_267;
R3_269 = R3_268 < 0 ? -R3_268 : R3_268;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_270 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_270 = 1;
while( S0)
{
if( S0 & 1)
{
R3_270 = S1 * R3_270;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_270 = 1 / R3_270;
}
}
R3_271 = 1 / R3_270;
R3_270 = (mreal) I3_7;
R3_270 = R3_270 * R3_0;
R3_272 = pow(R3_1, R3_270);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_270 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_270 = 1;
while( S0)
{
if( S0 & 1)
{
R3_270 = S1 * R3_270;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_270 = 1 / R3_270;
}
}
R3_273 = 1 / R3_270;
R3_270 = pow(R3_260, R3_253);
R3_274 = pow(R3_263, R3_253);
R3_275 = pow(R3_269, R3_252);
R3_276 = pow(R3_254, R3_255);
R3_277 = pow(R3_250, R3_255);
R3_278 = pow(R3_257, R3_255);
R3_279 = -R3_259;
R3_280 = R3_258 + R3_279;
R3_279 = R3_280 * R3_280;
R3_280 = (mreal) I3_2;
R3_281 = R3_9 * R3_280;
R3_280 = pow(R3_279, R3_281);
R3_279 = pow(R3_260, R3_262);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_254), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_281 = (mreal) I3_9;
R3_282 = sqrt(R3_281);
R3_279 = R3_279 * R3_282;
R3_282 = R3_261 + R3_279;
R3_279 = R3_282 * R3_282;
R3_282 = pow(R3_263, R3_262);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_257), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_281 = (mreal) I3_9;
R3_283 = sqrt(R3_281);
R3_282 = R3_282 * R3_283;
R3_283 = R3_261 + R3_282;
R3_282 = R3_283 * R3_283;
R3_283 = pow(R3_265, R3_262);
R3_281 = pow(R3_269, R3_0);
R3_284 = -R3_267;
R3_285 = R3_258 + R3_284;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_285), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_285 = (mreal) I3_9;
R3_281 = R3_281 * R3_285;
R3_285 = R3_261 + R3_283 + R3_281;
R3_283 = R3_285 * R3_285;
R3_285 = R3_32 * R3_271 * R3_272 * R3_273 * R3_270 * R3_274 * R3_275 * R3_276 * R3_277 * R3_278 * R3_280 * R3_279 * R3_282 * R3_283;
R3_305 = R3_285;
goto lab1251;
lab866:
B3_11 = I3_0 == I3_16;
if( !B3_11)
{
goto lab942;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_61, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_61, 3, T3_62);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_63, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_62, *T3_63, 3, T3_64);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_65, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_65, 3, T3_66);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_66, *T3_63, 3, T3_67);
if( err)
{
goto error_label;
}
R3_271 = -R3_0;
R3_272 = (mreal) I3_3;
R3_272 = R3_272 + R3_271;
R3_273 = R3_22 * R3_272;
MArgument_getMTensorAddress(FPA[0]) = T3_63;
MArgument_getMTensorAddress(FPA[1]) = T3_63;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_270;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_64;
MArgument_getMTensorAddress(FPA[1]) = T3_64;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_274;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_275 = (mreal) I3_1;
R3_276 = R3_9 * R3_275;
R3_275 = (mreal) I3_3;
R3_275 = R3_275 + R3_276;
MArgument_getMTensorAddress(FPA[0]) = T3_67;
MArgument_getMTensorAddress(FPA[1]) = T3_67;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_277;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_278 = sqrt(R3_270);
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_280 = P1[S0];
}
R3_279 = R3_274 < 0 ? -R3_274 : R3_274;
R3_282 = pow(R3_1, R3_0);
R3_283 = R3_277 < 0 ? -R3_277 : R3_277;
R3_281 = R3_22 * R3_0;
R3_284 = R3_280 * R3_280;
R3_286 = -R3_278;
R3_287 = sqrt(R3_284);
R3_288 = R3_286 + R3_287;
R3_289 = R3_288 < 0 ? -R3_288 : R3_288;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_290 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_290 = 1;
while( S0)
{
if( S0 & 1)
{
R3_290 = S1 * R3_290;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_290 = 1 / R3_290;
}
}
R3_291 = 1 / R3_290;
R3_290 = (mreal) I3_7;
R3_290 = R3_290 * R3_0;
R3_292 = pow(R3_1, R3_290);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_290 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_290 = 1;
while( S0)
{
if( S0 & 1)
{
R3_290 = S1 * R3_290;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_290 = 1 / R3_290;
}
}
R3_293 = 1 / R3_290;
R3_290 = pow(R3_279, R3_273);
R3_294 = pow(R3_283, R3_273);
R3_295 = pow(R3_289, R3_272);
R3_296 = pow(R3_270, R3_275);
R3_297 = pow(R3_274, R3_275);
R3_298 = pow(R3_277, R3_275);
R3_299 = -R3_280;
R3_300 = R3_278 + R3_299;
R3_299 = R3_300 * R3_300;
R3_300 = (mreal) I3_2;
R3_301 = R3_9 * R3_300;
R3_300 = pow(R3_299, R3_301);
R3_299 = pow(R3_279, R3_281);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_274), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_301 = (mreal) I3_9;
R3_302 = sqrt(R3_301);
R3_299 = R3_299 * R3_302;
R3_302 = R3_282 + R3_299;
R3_299 = R3_302 * R3_302;
R3_302 = pow(R3_283, R3_281);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_277), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_301 = (mreal) I3_9;
R3_303 = sqrt(R3_301);
R3_302 = R3_302 * R3_303;
R3_303 = R3_282 + R3_302;
R3_302 = R3_303 * R3_303;
R3_303 = pow(R3_284, R3_281);
R3_301 = pow(R3_289, R3_0);
R3_304 = -R3_287;
R3_305 = R3_278 + R3_304;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_305), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_305 = (mreal) I3_9;
R3_301 = R3_301 * R3_305;
R3_305 = R3_282 + R3_303 + R3_301;
R3_303 = R3_305 * R3_305;
R3_305 = R3_32 * R3_291 * R3_292 * R3_293 * R3_290 * R3_294 * R3_295 * R3_296 * R3_297 * R3_298 * R3_300 * R3_299 * R3_302 * R3_303;
R3_325 = R3_305;
goto lab1250;
lab942:
B3_12 = I3_0 == I3_17;
if( !B3_12)
{
goto lab1018;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_68, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_68, 3, T3_69);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_70, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_69, *T3_70, 3, T3_71);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_70, 3, T3_72);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_73, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_72, *T3_73, 3, T3_74);
if( err)
{
goto error_label;
}
R3_291 = -R3_0;
R3_292 = (mreal) I3_3;
R3_292 = R3_292 + R3_291;
R3_293 = R3_22 * R3_292;
MArgument_getMTensorAddress(FPA[0]) = T3_71;
MArgument_getMTensorAddress(FPA[1]) = T3_71;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_290;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_73;
MArgument_getMTensorAddress(FPA[1]) = T3_73;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_294;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_295 = (mreal) I3_1;
R3_296 = R3_9 * R3_295;
R3_295 = (mreal) I3_3;
R3_295 = R3_295 + R3_296;
MArgument_getMTensorAddress(FPA[0]) = T3_74;
MArgument_getMTensorAddress(FPA[1]) = T3_74;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_297;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_298 = sqrt(R3_294);
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_300 = P1[S0];
}
R3_299 = R3_290 < 0 ? -R3_290 : R3_290;
R3_302 = pow(R3_1, R3_0);
R3_303 = R3_297 < 0 ? -R3_297 : R3_297;
R3_301 = R3_22 * R3_0;
R3_304 = R3_300 * R3_300;
R3_306 = -R3_298;
R3_307 = sqrt(R3_304);
R3_308 = R3_306 + R3_307;
R3_309 = R3_308 < 0 ? -R3_308 : R3_308;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_310 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_310 = 1;
while( S0)
{
if( S0 & 1)
{
R3_310 = S1 * R3_310;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_310 = 1 / R3_310;
}
}
R3_311 = 1 / R3_310;
R3_310 = (mreal) I3_7;
R3_310 = R3_310 * R3_0;
R3_312 = pow(R3_1, R3_310);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_310 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_310 = 1;
while( S0)
{
if( S0 & 1)
{
R3_310 = S1 * R3_310;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_310 = 1 / R3_310;
}
}
R3_313 = 1 / R3_310;
R3_310 = pow(R3_299, R3_293);
R3_314 = pow(R3_303, R3_293);
R3_315 = pow(R3_309, R3_292);
R3_316 = pow(R3_290, R3_295);
R3_317 = pow(R3_294, R3_295);
R3_318 = pow(R3_297, R3_295);
R3_319 = -R3_300;
R3_320 = R3_298 + R3_319;
R3_319 = R3_320 * R3_320;
R3_320 = (mreal) I3_2;
R3_321 = R3_9 * R3_320;
R3_320 = pow(R3_319, R3_321);
R3_319 = pow(R3_299, R3_301);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_290), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_321 = (mreal) I3_9;
R3_322 = sqrt(R3_321);
R3_319 = R3_319 * R3_322;
R3_322 = R3_302 + R3_319;
R3_319 = R3_322 * R3_322;
R3_322 = pow(R3_303, R3_301);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_297), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_321 = (mreal) I3_9;
R3_323 = sqrt(R3_321);
R3_322 = R3_322 * R3_323;
R3_323 = R3_302 + R3_322;
R3_322 = R3_323 * R3_323;
R3_323 = pow(R3_304, R3_301);
R3_321 = pow(R3_309, R3_0);
R3_324 = -R3_307;
R3_325 = R3_298 + R3_324;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_325), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_325 = (mreal) I3_9;
R3_321 = R3_321 * R3_325;
R3_325 = R3_302 + R3_323 + R3_321;
R3_323 = R3_325 * R3_325;
R3_325 = R3_32 * R3_311 * R3_312 * R3_313 * R3_310 * R3_314 * R3_315 * R3_316 * R3_317 * R3_318 * R3_320 * R3_319 * R3_322 * R3_323;
R3_345 = R3_325;
goto lab1249;
lab1018:
B3_13 = I3_0 == I3_18;
if( !B3_13)
{
goto lab1093;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_75, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_75, 3, T3_76);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_77, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_76, *T3_77, 3, T3_78);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_79, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_76, *T3_79, 3, T3_80);
if( err)
{
goto error_label;
}
R3_311 = -R3_0;
R3_312 = (mreal) I3_3;
R3_312 = R3_312 + R3_311;
R3_313 = R3_22 * R3_312;
MArgument_getMTensorAddress(FPA[0]) = T3_77;
MArgument_getMTensorAddress(FPA[1]) = T3_77;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_310;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_78;
MArgument_getMTensorAddress(FPA[1]) = T3_78;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_314;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_315 = (mreal) I3_1;
R3_316 = R3_9 * R3_315;
R3_315 = (mreal) I3_3;
R3_315 = R3_315 + R3_316;
MArgument_getMTensorAddress(FPA[0]) = T3_80;
MArgument_getMTensorAddress(FPA[1]) = T3_80;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_317;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_318 = sqrt(R3_310);
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_320 = P1[S0];
}
R3_319 = R3_314 < 0 ? -R3_314 : R3_314;
R3_322 = pow(R3_1, R3_0);
R3_323 = R3_317 < 0 ? -R3_317 : R3_317;
R3_321 = R3_22 * R3_0;
R3_324 = R3_320 * R3_320;
R3_326 = -R3_318;
R3_327 = sqrt(R3_324);
R3_328 = R3_326 + R3_327;
R3_329 = R3_328 < 0 ? -R3_328 : R3_328;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_330 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_330 = 1;
while( S0)
{
if( S0 & 1)
{
R3_330 = S1 * R3_330;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_330 = 1 / R3_330;
}
}
R3_331 = 1 / R3_330;
R3_330 = (mreal) I3_7;
R3_330 = R3_330 * R3_0;
R3_332 = pow(R3_1, R3_330);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_330 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_330 = 1;
while( S0)
{
if( S0 & 1)
{
R3_330 = S1 * R3_330;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_330 = 1 / R3_330;
}
}
R3_333 = 1 / R3_330;
R3_330 = pow(R3_319, R3_313);
R3_334 = pow(R3_323, R3_313);
R3_335 = pow(R3_329, R3_312);
R3_336 = pow(R3_310, R3_315);
R3_337 = pow(R3_314, R3_315);
R3_338 = pow(R3_317, R3_315);
R3_339 = -R3_320;
R3_340 = R3_318 + R3_339;
R3_339 = R3_340 * R3_340;
R3_340 = (mreal) I3_2;
R3_341 = R3_9 * R3_340;
R3_340 = pow(R3_339, R3_341);
R3_339 = pow(R3_319, R3_321);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_314), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_341 = (mreal) I3_9;
R3_342 = sqrt(R3_341);
R3_339 = R3_339 * R3_342;
R3_342 = R3_322 + R3_339;
R3_339 = R3_342 * R3_342;
R3_342 = pow(R3_323, R3_321);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_317), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_341 = (mreal) I3_9;
R3_343 = sqrt(R3_341);
R3_342 = R3_342 * R3_343;
R3_343 = R3_322 + R3_342;
R3_342 = R3_343 * R3_343;
R3_343 = pow(R3_324, R3_321);
R3_341 = pow(R3_329, R3_0);
R3_344 = -R3_327;
R3_345 = R3_318 + R3_344;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_345), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_345 = (mreal) I3_9;
R3_341 = R3_341 * R3_345;
R3_345 = R3_322 + R3_343 + R3_341;
R3_343 = R3_345 * R3_345;
R3_345 = R3_32 * R3_331 * R3_332 * R3_333 * R3_330 * R3_334 * R3_335 * R3_336 * R3_337 * R3_338 * R3_340 * R3_339 * R3_342 * R3_343;
R3_365 = R3_345;
goto lab1248;
lab1093:
B3_14 = I3_0 == I3_19;
if( !B3_14)
{
goto lab1169;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_81, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_81, 3, T3_82);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_83, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_82, *T3_83, 3, T3_84);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_85, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_85, 3, T3_86);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_86, *T3_83, 3, T3_87);
if( err)
{
goto error_label;
}
R3_331 = -R3_0;
R3_332 = (mreal) I3_3;
R3_332 = R3_332 + R3_331;
R3_333 = R3_22 * R3_332;
MArgument_getMTensorAddress(FPA[0]) = T3_85;
MArgument_getMTensorAddress(FPA[1]) = T3_85;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_330;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_84;
MArgument_getMTensorAddress(FPA[1]) = T3_84;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_334;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_335 = (mreal) I3_1;
R3_336 = R3_9 * R3_335;
R3_335 = (mreal) I3_3;
R3_335 = R3_335 + R3_336;
MArgument_getMTensorAddress(FPA[0]) = T3_87;
MArgument_getMTensorAddress(FPA[1]) = T3_87;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_337;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_338 = sqrt(R3_330);
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_340 = P1[S0];
}
R3_339 = R3_334 < 0 ? -R3_334 : R3_334;
R3_342 = pow(R3_1, R3_0);
R3_343 = R3_337 < 0 ? -R3_337 : R3_337;
R3_341 = R3_22 * R3_0;
R3_344 = R3_340 * R3_340;
R3_346 = -R3_338;
R3_347 = sqrt(R3_344);
R3_348 = R3_346 + R3_347;
R3_349 = R3_348 < 0 ? -R3_348 : R3_348;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_350 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_350 = 1;
while( S0)
{
if( S0 & 1)
{
R3_350 = S1 * R3_350;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_350 = 1 / R3_350;
}
}
R3_351 = 1 / R3_350;
R3_350 = (mreal) I3_7;
R3_350 = R3_350 * R3_0;
R3_352 = pow(R3_1, R3_350);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_350 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_350 = 1;
while( S0)
{
if( S0 & 1)
{
R3_350 = S1 * R3_350;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_350 = 1 / R3_350;
}
}
R3_353 = 1 / R3_350;
R3_350 = pow(R3_339, R3_333);
R3_354 = pow(R3_343, R3_333);
R3_355 = pow(R3_349, R3_332);
R3_356 = pow(R3_330, R3_335);
R3_357 = pow(R3_334, R3_335);
R3_358 = pow(R3_337, R3_335);
R3_359 = -R3_340;
R3_360 = R3_338 + R3_359;
R3_359 = R3_360 * R3_360;
R3_360 = (mreal) I3_2;
R3_361 = R3_9 * R3_360;
R3_360 = pow(R3_359, R3_361);
R3_359 = pow(R3_339, R3_341);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_334), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_361 = (mreal) I3_9;
R3_362 = sqrt(R3_361);
R3_359 = R3_359 * R3_362;
R3_362 = R3_342 + R3_359;
R3_359 = R3_362 * R3_362;
R3_362 = pow(R3_343, R3_341);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_337), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_361 = (mreal) I3_9;
R3_363 = sqrt(R3_361);
R3_362 = R3_362 * R3_363;
R3_363 = R3_342 + R3_362;
R3_362 = R3_363 * R3_363;
R3_363 = pow(R3_344, R3_341);
R3_361 = pow(R3_349, R3_0);
R3_364 = -R3_347;
R3_365 = R3_338 + R3_364;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_365), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_365 = (mreal) I3_9;
R3_361 = R3_361 * R3_365;
R3_365 = R3_342 + R3_363 + R3_361;
R3_363 = R3_365 * R3_365;
R3_365 = R3_32 * R3_351 * R3_352 * R3_353 * R3_350 * R3_354 * R3_355 * R3_356 * R3_357 * R3_358 * R3_360 * R3_359 * R3_362 * R3_363;
R3_385 = R3_365;
goto lab1247;
lab1169:
B3_15 = I3_0 == I3_20;
if( !B3_15)
{
goto lab1245;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_88, *T3_0, &I3_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_88, 3, T3_89);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_90, *T3_0, &I3_4, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_89, *T3_90, 3, T3_91);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T3_90, 3, T3_92);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T3_93, *T3_0, &I3_5, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T3_92, *T3_93, 3, T3_94);
if( err)
{
goto error_label;
}
R3_351 = -R3_0;
R3_352 = (mreal) I3_3;
R3_352 = R3_352 + R3_351;
R3_353 = R3_22 * R3_352;
MArgument_getMTensorAddress(FPA[0]) = T3_90;
MArgument_getMTensorAddress(FPA[1]) = T3_90;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_350;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
MArgument_getMTensorAddress(FPA[0]) = T3_91;
MArgument_getMTensorAddress(FPA[1]) = T3_91;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_354;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_355 = (mreal) I3_1;
R3_356 = R3_9 * R3_355;
R3_355 = (mreal) I3_3;
R3_355 = R3_355 + R3_356;
MArgument_getMTensorAddress(FPA[0]) = T3_94;
MArgument_getMTensorAddress(FPA[1]) = T3_94;
MArgument_getIntegerAddress(FPA[2]) = &I3_6;
MArgument_getRealAddress(FPA[3]) = &R3_357;
err = FP1(libData, 3, FPA, FPA[3]);/*  DotVV  */
if( err)
{
goto error_label;
}
R3_358 = sqrt(R3_350);
{
mint S0 = D1[0];
if( I3_4 > 0)
{
if( I3_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I3_4 - 1;
}
else
{
if( I3_4 == 0 || I3_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I3_4;
}
R3_360 = P1[S0];
}
R3_359 = R3_354 < 0 ? -R3_354 : R3_354;
R3_362 = pow(R3_1, R3_0);
R3_363 = R3_357 < 0 ? -R3_357 : R3_357;
R3_361 = R3_22 * R3_0;
R3_364 = R3_360 * R3_360;
R3_366 = -R3_358;
R3_367 = sqrt(R3_364);
R3_368 = R3_366 + R3_367;
R3_369 = R3_368 < 0 ? -R3_368 : R3_368;
if( I3_5 == 0)
{
if( R3_0 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_370 = 1;
}
}
else
{
mint S0 = I3_5;
mreal S1 = R3_0;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_370 = 1;
while( S0)
{
if( S0 & 1)
{
R3_370 = S1 * R3_370;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_370 = 1 / R3_370;
}
}
R3_371 = 1 / R3_370;
R3_370 = (mreal) I3_7;
R3_370 = R3_370 * R3_0;
R3_372 = pow(R3_1, R3_370);
if( I3_8 == 0)
{
if( R3_36 == 0)
{
err = 1;
goto error_label;
}
else
{
R3_370 = 1;
}
}
else
{
mint S0 = I3_8;
mreal S1 = R3_36;
mbool S2 = 0;
if( S0 < 0)
{
S2 = 1;
S0 = -S0;
}
R3_370 = 1;
while( S0)
{
if( S0 & 1)
{
R3_370 = S1 * R3_370;
}
S1 = S1 * S1;
S0 = S0 >> 1;
}
if( S2)
{
R3_370 = 1 / R3_370;
}
}
R3_373 = 1 / R3_370;
R3_370 = pow(R3_359, R3_353);
R3_374 = pow(R3_363, R3_353);
R3_375 = pow(R3_369, R3_352);
R3_376 = pow(R3_350, R3_355);
R3_377 = pow(R3_354, R3_355);
R3_378 = pow(R3_357, R3_355);
R3_379 = -R3_360;
R3_380 = R3_358 + R3_379;
R3_379 = R3_380 * R3_380;
R3_380 = (mreal) I3_2;
R3_381 = R3_9 * R3_380;
R3_380 = pow(R3_379, R3_381);
R3_379 = pow(R3_359, R3_361);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_354), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_381 = (mreal) I3_9;
R3_382 = sqrt(R3_381);
R3_379 = R3_379 * R3_382;
R3_382 = R3_362 + R3_379;
R3_379 = R3_382 * R3_382;
R3_382 = pow(R3_363, R3_361);
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_357), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_381 = (mreal) I3_9;
R3_383 = sqrt(R3_381);
R3_382 = R3_382 * R3_383;
R3_383 = R3_362 + R3_382;
R3_382 = R3_383 * R3_383;
R3_383 = pow(R3_364, R3_361);
R3_381 = pow(R3_369, R3_0);
R3_384 = -R3_367;
R3_385 = R3_358 + R3_384;
{
mint S0 = FP2((void*) (&I3_9), (void*) (&R3_385), 1, UnitIncrements, 4);/*  Sign  */
err = S0 == 0 ? 0 : LIBRARY_NUMERICAL_ERROR;
if( err)
{
goto error_label;
}
}
R3_385 = (mreal) I3_9;
R3_381 = R3_381 * R3_385;
R3_385 = R3_362 + R3_383 + R3_381;
R3_383 = R3_385 * R3_385;
R3_385 = R3_32 * R3_371 * R3_372 * R3_373 * R3_370 * R3_374 * R3_375 * R3_376 * R3_377 * R3_378 * R3_380 * R3_379 * R3_382 * R3_383;
R3_372 = R3_385;
goto lab1246;
lab1245:
R3_372 = R3_386;
lab1246:
R3_385 = R3_372;
lab1247:
R3_365 = R3_385;
lab1248:
R3_345 = R3_365;
lab1249:
R3_325 = R3_345;
lab1250:
R3_305 = R3_325;
lab1251:
R3_285 = R3_305;
lab1252:
R3_264 = R3_285;
lab1253:
R3_238 = R3_264;
lab1254:
R3_213 = R3_238;
lab1255:
R3_193 = R3_213;
lab1256:
R3_173 = R3_193;
lab1257:
R3_152 = R3_173;
lab1258:
R3_126 = R3_152;
lab1259:
R3_100 = R3_126;
lab1260:
R3_74 = R3_100;
lab1261:
*Res = R3_74;
error_label:
funStructCompile->ReleaseInitializedMTensors(Tinit);
return err;
}

DLLEXPORT int internalEdgeMomenta_wolfram(WolframLibraryData libData, MTensor A1, mint A2, MTensor A3, MTensor *Res)
{
mbool B0_0;
mbool B0_1;
mbool B0_2;
mbool B0_3;
mbool B0_4;
mbool B0_5;
mbool B0_6;
mbool B0_7;
mbool B0_8;
mbool B0_9;
mbool B0_10;
mbool B0_11;
mbool B0_12;
mbool B0_13;
mbool B0_14;
mbool B0_15;
mint I0_0;
MTensor* T0_0;
MTensor* T0_1;
MTensor* T0_2;
MTensor* T0_3;
MTensor* T0_4;
MTensor* T0_5;
MTensor* T0_6;
MTensor* T0_7;
MTensor* T0_8;
MTensor* T0_9;
MTensor* T0_10;
MTensor* T0_11;
MTensor* T0_12;
MTensor* T0_13;
MTensor* T0_14;
MTensor* T0_15;
MTensor* T0_16;
MTensor* T0_17;
MTensor* T0_18;
MTensor* T0_19;
MTensor* T0_20;
MTensor* T0_21;
MTensor* T0_22;
MTensor* T0_23;
MTensor* T0_24;
MTensor* T0_25;
MTensor* T0_26;
MTensor* T0_27;
MTensor* T0_28;
MTensor* T0_29;
MTensor* T0_30;
MTensor* T0_31;
MTensor* T0_32;
MTensor* T0_33;
MTensor* T0_34;
MTensor* T0_35;
MTensor* T0_36;
MTensor* T0_37;
MTensor* T0_38;
MTensor* T0_39;
MTensor* T0_40;
MTensor* T0_41;
MTensor* T0_42;
MTensor* T0_43;
MTensorInitializationData Tinit;
mint *D3;
mint *D5;
mint *D12;
mint *D15;
mint *D23;
mint *D30;
mint *D32;
mint *D34;
mint *D38;
mint *D42;
mint *D44;
mint *D50;
mint *D52;
MArgument FPA[2];
int err = 0;
Tinit = funStructCompile->GetInitializedMTensors(libData, 42);
T0_10 = MTensorInitializationData_getTensor(Tinit, 0);
T0_11 = MTensorInitializationData_getTensor(Tinit, 1);
T0_12 = MTensorInitializationData_getTensor(Tinit, 2);
T0_13 = MTensorInitializationData_getTensor(Tinit, 3);
T0_14 = MTensorInitializationData_getTensor(Tinit, 4);
T0_15 = MTensorInitializationData_getTensor(Tinit, 5);
T0_16 = MTensorInitializationData_getTensor(Tinit, 6);
T0_17 = MTensorInitializationData_getTensor(Tinit, 7);
T0_18 = MTensorInitializationData_getTensor(Tinit, 8);
T0_19 = MTensorInitializationData_getTensor(Tinit, 9);
T0_2 = MTensorInitializationData_getTensor(Tinit, 10);
T0_20 = MTensorInitializationData_getTensor(Tinit, 11);
T0_21 = MTensorInitializationData_getTensor(Tinit, 12);
T0_22 = MTensorInitializationData_getTensor(Tinit, 13);
T0_23 = MTensorInitializationData_getTensor(Tinit, 14);
T0_24 = MTensorInitializationData_getTensor(Tinit, 15);
T0_25 = MTensorInitializationData_getTensor(Tinit, 16);
T0_26 = MTensorInitializationData_getTensor(Tinit, 17);
T0_27 = MTensorInitializationData_getTensor(Tinit, 18);
T0_28 = MTensorInitializationData_getTensor(Tinit, 19);
T0_29 = MTensorInitializationData_getTensor(Tinit, 20);
T0_3 = MTensorInitializationData_getTensor(Tinit, 21);
T0_30 = MTensorInitializationData_getTensor(Tinit, 22);
T0_31 = MTensorInitializationData_getTensor(Tinit, 23);
T0_32 = MTensorInitializationData_getTensor(Tinit, 24);
T0_33 = MTensorInitializationData_getTensor(Tinit, 25);
T0_34 = MTensorInitializationData_getTensor(Tinit, 26);
T0_35 = MTensorInitializationData_getTensor(Tinit, 27);
T0_36 = MTensorInitializationData_getTensor(Tinit, 28);
T0_37 = MTensorInitializationData_getTensor(Tinit, 29);
T0_38 = MTensorInitializationData_getTensor(Tinit, 30);
T0_39 = MTensorInitializationData_getTensor(Tinit, 31);
T0_4 = MTensorInitializationData_getTensor(Tinit, 32);
T0_40 = MTensorInitializationData_getTensor(Tinit, 33);
T0_41 = MTensorInitializationData_getTensor(Tinit, 34);
T0_42 = MTensorInitializationData_getTensor(Tinit, 35);
T0_43 = MTensorInitializationData_getTensor(Tinit, 36);
T0_5 = MTensorInitializationData_getTensor(Tinit, 37);
T0_6 = MTensorInitializationData_getTensor(Tinit, 38);
T0_7 = MTensorInitializationData_getTensor(Tinit, 39);
T0_8 = MTensorInitializationData_getTensor(Tinit, 40);
T0_9 = MTensorInitializationData_getTensor(Tinit, 41);
T0_0 = &A1;
I0_0 = A2;
T0_1 = &A3;
B0_0 = I0_0 == I0_1;
if( !B0_0)
{
goto lab9;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_2, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D3 = MTensor_getDimensionsMacro(*T0_2);
err = funStructCompile->MTensor_getMTensorInitialized(T0_3, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_4, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
D5 = MTensor_getDimensionsMacro(*T0_4);
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D3[S2];
}
err = funStructCompile->MTensor_allocate(T0_5, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_2;
S1[1] = *T0_3;
S1[2] = *T0_4;
err = funStructCompile->MTensor_fillFromMTensor(*T0_5, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_5;
MArgument_getMTensorAddress(FPA[1]) = T0_6;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab181;
lab9:
B0_1 = I0_0 == I0_3;
if( !B0_1)
{
goto lab19;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_2, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D3 = MTensor_getDimensionsMacro(*T0_2);
err = funStructCompile->MTensor_getMTensorInitialized(T0_3, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T0_3, 3, T0_4);
if( err)
{
goto error_label;
}
D5 = MTensor_getDimensionsMacro(*T0_4);
D5 = MTensor_getDimensionsMacro(*T0_4);
err = funStructCompile->Math_TT_T(257, 4, *T0_2, *T0_4, 3, T0_3);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_4, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
D5 = MTensor_getDimensionsMacro(*T0_4);
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D3[S2];
}
err = funStructCompile->MTensor_allocate(T0_6, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_2;
S1[1] = *T0_3;
S1[2] = *T0_4;
err = funStructCompile->MTensor_fillFromMTensor(*T0_6, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_6;
MArgument_getMTensorAddress(FPA[1]) = T0_7;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab180;
lab19:
B0_2 = I0_0 == I0_2;
if( !B0_2)
{
goto lab28;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_3, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_4, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D5 = MTensor_getDimensionsMacro(*T0_4);
err = funStructCompile->MTensor_getMTensorInitialized(T0_7, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_3, *T0_7, 3, T0_8);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D5[S2];
}
err = funStructCompile->MTensor_allocate(T0_7, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_4;
S1[1] = *T0_8;
S1[2] = *T0_3;
err = funStructCompile->MTensor_fillFromMTensor(*T0_7, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_7;
MArgument_getMTensorAddress(FPA[1]) = T0_10;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab179;
lab28:
B0_3 = I0_0 == I0_4;
if( !B0_3)
{
goto lab38;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_4, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D5 = MTensor_getDimensionsMacro(*T0_4);
err = funStructCompile->MTensor_getMTensorInitialized(T0_8, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_9, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
D12 = MTensor_getDimensionsMacro(*T0_9);
err = funStructCompile->Math_T_T(43, 4, *T0_9, 3, T0_10);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_4, *T0_10, 3, T0_9);
if( err)
{
goto error_label;
}
D12 = MTensor_getDimensionsMacro(*T0_9);
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D5[S2];
}
err = funStructCompile->MTensor_allocate(T0_10, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_4;
S1[1] = *T0_8;
S1[2] = *T0_9;
err = funStructCompile->MTensor_fillFromMTensor(*T0_10, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_10;
MArgument_getMTensorAddress(FPA[1]) = T0_12;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab178;
lab38:
B0_4 = I0_0 == I0_5;
if( !B0_4)
{
goto lab48;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_8, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_9, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D12 = MTensor_getDimensionsMacro(*T0_9);
err = funStructCompile->MTensor_getMTensorInitialized(T0_11, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
D15 = MTensor_getDimensionsMacro(*T0_11);
err = funStructCompile->Math_T_T(43, 4, *T0_11, 3, T0_12);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_8, *T0_12, 3, T0_11);
if( err)
{
goto error_label;
}
D15 = MTensor_getDimensionsMacro(*T0_11);
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D12[S2];
}
err = funStructCompile->MTensor_allocate(T0_12, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_9;
S1[1] = *T0_8;
S1[2] = *T0_11;
err = funStructCompile->MTensor_fillFromMTensor(*T0_12, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_12;
MArgument_getMTensorAddress(FPA[1]) = T0_14;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab177;
lab48:
B0_5 = I0_0 == I0_6;
if( !B0_5)
{
goto lab60;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_9, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D12 = MTensor_getDimensionsMacro(*T0_9);
err = funStructCompile->MTensor_getMTensorInitialized(T0_11, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
D15 = MTensor_getDimensionsMacro(*T0_11);
err = funStructCompile->Math_T_T(43, 4, *T0_11, 3, T0_13);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_9, *T0_13, 3, T0_11);
if( err)
{
goto error_label;
}
D15 = MTensor_getDimensionsMacro(*T0_11);
err = funStructCompile->MTensor_getMTensorInitialized(T0_13, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T0_13, 3, T0_14);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_9, *T0_14, 3, T0_13);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D12[S2];
}
err = funStructCompile->MTensor_allocate(T0_14, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_9;
S1[1] = *T0_11;
S1[2] = *T0_13;
err = funStructCompile->MTensor_fillFromMTensor(*T0_14, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_14;
MArgument_getMTensorAddress(FPA[1]) = T0_18;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab176;
lab60:
B0_6 = I0_0 == I0_7;
if( !B0_6)
{
goto lab71;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_11, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D15 = MTensor_getDimensionsMacro(*T0_11);
err = funStructCompile->MTensor_getMTensorInitialized(T0_13, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T0_13, 3, T0_15);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_16, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_11, *T0_15, 3, T0_17);
if( err)
{
goto error_label;
}
D23 = MTensor_getDimensionsMacro(*T0_17);
err = funStructCompile->Math_TT_T(257, 4, *T0_17, *T0_16, 3, T0_17);
if( err)
{
goto error_label;
}
D23 = MTensor_getDimensionsMacro(*T0_17);
err = funStructCompile->Math_TT_T(257, 4, *T0_11, *T0_15, 3, T0_16);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D15[S2];
}
err = funStructCompile->MTensor_allocate(T0_18, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_11;
S1[1] = *T0_17;
S1[2] = *T0_16;
err = funStructCompile->MTensor_fillFromMTensor(*T0_18, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_18;
MArgument_getMTensorAddress(FPA[1]) = T0_22;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab175;
lab71:
B0_7 = I0_0 == I0_8;
if( !B0_7)
{
goto lab83;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_17, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D23 = MTensor_getDimensionsMacro(*T0_17);
err = funStructCompile->MTensor_getMTensorInitialized(T0_16, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T0_16, 3, T0_19);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_17, *T0_19, 3, T0_20);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_21, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T0_21, 3, T0_22);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_17, *T0_19, 3, T0_21);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_21, *T0_22, 3, T0_21);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D23[S2];
}
err = funStructCompile->MTensor_allocate(T0_22, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_17;
S1[1] = *T0_20;
S1[2] = *T0_21;
err = funStructCompile->MTensor_fillFromMTensor(*T0_22, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_22;
MArgument_getMTensorAddress(FPA[1]) = T0_24;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab174;
lab83:
B0_8 = I0_0 == I0_9;
if( !B0_8)
{
goto lab92;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_20, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_21, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_20, *T0_21, 3, T0_23);
if( err)
{
goto error_label;
}
D30 = MTensor_getDimensionsMacro(*T0_23);
err = funStructCompile->MTensor_getMTensorInitialized(T0_21, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D30[S2];
}
err = funStructCompile->MTensor_allocate(T0_24, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_23;
S1[1] = *T0_21;
S1[2] = *T0_20;
err = funStructCompile->MTensor_fillFromMTensor(*T0_24, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_24;
MArgument_getMTensorAddress(FPA[1]) = T0_26;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab173;
lab92:
B0_9 = I0_0 == I0_10;
if( !B0_9)
{
goto lab101;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_23, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
D30 = MTensor_getDimensionsMacro(*T0_23);
err = funStructCompile->MTensor_getMTensorInitialized(T0_21, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_23, *T0_21, 3, T0_25);
if( err)
{
goto error_label;
}
D32 = MTensor_getDimensionsMacro(*T0_25);
err = funStructCompile->MTensor_getMTensorInitialized(T0_21, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D32[S2];
}
err = funStructCompile->MTensor_allocate(T0_26, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_25;
S1[1] = *T0_23;
S1[2] = *T0_21;
err = funStructCompile->MTensor_fillFromMTensor(*T0_26, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_26;
MArgument_getMTensorAddress(FPA[1]) = T0_29;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab172;
lab101:
B0_10 = I0_0 == I0_11;
if( !B0_10)
{
goto lab112;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_25, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D32 = MTensor_getDimensionsMacro(*T0_25);
err = funStructCompile->MTensor_getMTensorInitialized(T0_21, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_25, *T0_21, 3, T0_27);
if( err)
{
goto error_label;
}
D34 = MTensor_getDimensionsMacro(*T0_27);
err = funStructCompile->MTensor_getMTensorInitialized(T0_28, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T0_28, 3, T0_29);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_25, *T0_21, 3, T0_28);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_28, *T0_29, 3, T0_28);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D34[S2];
}
err = funStructCompile->MTensor_allocate(T0_29, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_27;
S1[1] = *T0_28;
S1[2] = *T0_25;
err = funStructCompile->MTensor_fillFromMTensor(*T0_29, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_29;
MArgument_getMTensorAddress(FPA[1]) = T0_28;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab171;
lab112:
B0_11 = I0_0 == I0_12;
if( !B0_11)
{
goto lab122;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_27, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D34 = MTensor_getDimensionsMacro(*T0_27);
err = funStructCompile->MTensor_getMTensorInitialized(T0_28, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_27, *T0_28, 3, T0_30);
if( err)
{
goto error_label;
}
D38 = MTensor_getDimensionsMacro(*T0_30);
err = funStructCompile->MTensor_getMTensorInitialized(T0_28, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_27, *T0_28, 3, T0_31);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D38[S2];
}
err = funStructCompile->MTensor_allocate(T0_28, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_30;
S1[1] = *T0_31;
S1[2] = *T0_27;
err = funStructCompile->MTensor_fillFromMTensor(*T0_28, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_28;
MArgument_getMTensorAddress(FPA[1]) = T0_34;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab170;
lab122:
B0_12 = I0_0 == I0_13;
if( !B0_12)
{
goto lab132;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_30, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D38 = MTensor_getDimensionsMacro(*T0_30);
err = funStructCompile->MTensor_getMTensorInitialized(T0_31, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_32, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_30, *T0_32, 3, T0_33);
if( err)
{
goto error_label;
}
D42 = MTensor_getDimensionsMacro(*T0_33);
err = funStructCompile->Math_TT_T(257, 4, *T0_33, *T0_31, 3, T0_33);
if( err)
{
goto error_label;
}
D42 = MTensor_getDimensionsMacro(*T0_33);
err = funStructCompile->Math_TT_T(257, 4, *T0_30, *T0_31, 3, T0_32);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D42[S2];
}
err = funStructCompile->MTensor_allocate(T0_34, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_33;
S1[1] = *T0_32;
S1[2] = *T0_30;
err = funStructCompile->MTensor_fillFromMTensor(*T0_34, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_34;
MArgument_getMTensorAddress(FPA[1]) = T0_37;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab169;
lab132:
B0_13 = I0_0 == I0_14;
if( !B0_13)
{
goto lab143;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_33, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D42 = MTensor_getDimensionsMacro(*T0_33);
err = funStructCompile->MTensor_getMTensorInitialized(T0_32, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_33, *T0_32, 3, T0_35);
if( err)
{
goto error_label;
}
D44 = MTensor_getDimensionsMacro(*T0_35);
err = funStructCompile->MTensor_getMTensorInitialized(T0_36, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T0_36, 3, T0_37);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_33, *T0_37, 3, T0_36);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_36, *T0_32, 3, T0_36);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D44[S2];
}
err = funStructCompile->MTensor_allocate(T0_37, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_35;
S1[1] = *T0_33;
S1[2] = *T0_36;
err = funStructCompile->MTensor_fillFromMTensor(*T0_37, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_37;
MArgument_getMTensorAddress(FPA[1]) = T0_41;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab168;
lab143:
B0_14 = I0_0 == I0_15;
if( !B0_14)
{
goto lab154;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_35, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D44 = MTensor_getDimensionsMacro(*T0_35);
err = funStructCompile->MTensor_getMTensorInitialized(T0_36, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T0_36, 3, T0_38);
if( err)
{
goto error_label;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_39, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_35, *T0_39, 3, T0_40);
if( err)
{
goto error_label;
}
D50 = MTensor_getDimensionsMacro(*T0_40);
err = funStructCompile->Math_TT_T(257, 4, *T0_40, *T0_38, 3, T0_40);
if( err)
{
goto error_label;
}
D50 = MTensor_getDimensionsMacro(*T0_40);
err = funStructCompile->Math_TT_T(257, 4, *T0_35, *T0_38, 3, T0_39);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D50[S2];
}
err = funStructCompile->MTensor_allocate(T0_41, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_40;
S1[1] = *T0_35;
S1[2] = *T0_39;
err = funStructCompile->MTensor_fillFromMTensor(*T0_41, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_41;
MArgument_getMTensorAddress(FPA[1]) = T0_43;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab167;
lab154:
B0_15 = I0_0 == I0_16;
if( !B0_15)
{
goto lab165;
}
err = funStructCompile->MTensor_getMTensorInitialized(T0_40, *T0_0, &I0_1, 1);
if( err)
{
goto error_label;
}
D50 = MTensor_getDimensionsMacro(*T0_40);
err = funStructCompile->MTensor_getMTensorInitialized(T0_39, *T0_0, &I0_3, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_40, *T0_39, 3, T0_42);
if( err)
{
goto error_label;
}
D52 = MTensor_getDimensionsMacro(*T0_42);
err = funStructCompile->MTensor_getMTensorInitialized(T0_39, *T0_0, &I0_2, 1);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_T_T(43, 4, *T0_39, 3, T0_43);
if( err)
{
goto error_label;
}
err = funStructCompile->Math_TT_T(257, 4, *T0_40, *T0_43, 3, T0_39);
if( err)
{
goto error_label;
}
{
mint S0[2] = {3, 0};
MTensor S1[3];
mint S2;
for( S2 = 0; S2 < 1; S2++)
{
S0[S2 + 1] = D52[S2];
}
err = funStructCompile->MTensor_allocate(T0_43, 3, 2, S0);
if( err)
{
goto error_label;
}
S1[0] = *T0_42;
S1[1] = *T0_40;
S1[2] = *T0_39;
err = funStructCompile->MTensor_fillFromMTensor(*T0_43, S1);
if( err)
{
goto error_label;
}
}
MArgument_getMTensorAddress(FPA[0]) = T0_43;
MArgument_getMTensorAddress(FPA[1]) = T0_39;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
goto lab166;
lab165:
MArgument_getMTensorAddress(FPA[0]) = T0_44;
MArgument_getMTensorAddress(FPA[1]) = T0_39;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab166:
MArgument_getMTensorAddress(FPA[0]) = T0_39;
MArgument_getMTensorAddress(FPA[1]) = T0_43;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab167:
MArgument_getMTensorAddress(FPA[0]) = T0_43;
MArgument_getMTensorAddress(FPA[1]) = T0_41;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab168:
MArgument_getMTensorAddress(FPA[0]) = T0_41;
MArgument_getMTensorAddress(FPA[1]) = T0_37;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab169:
MArgument_getMTensorAddress(FPA[0]) = T0_37;
MArgument_getMTensorAddress(FPA[1]) = T0_34;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab170:
MArgument_getMTensorAddress(FPA[0]) = T0_34;
MArgument_getMTensorAddress(FPA[1]) = T0_28;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab171:
MArgument_getMTensorAddress(FPA[0]) = T0_28;
MArgument_getMTensorAddress(FPA[1]) = T0_29;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab172:
MArgument_getMTensorAddress(FPA[0]) = T0_29;
MArgument_getMTensorAddress(FPA[1]) = T0_26;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab173:
MArgument_getMTensorAddress(FPA[0]) = T0_26;
MArgument_getMTensorAddress(FPA[1]) = T0_24;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab174:
MArgument_getMTensorAddress(FPA[0]) = T0_24;
MArgument_getMTensorAddress(FPA[1]) = T0_22;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab175:
MArgument_getMTensorAddress(FPA[0]) = T0_22;
MArgument_getMTensorAddress(FPA[1]) = T0_18;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab176:
MArgument_getMTensorAddress(FPA[0]) = T0_18;
MArgument_getMTensorAddress(FPA[1]) = T0_14;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab177:
MArgument_getMTensorAddress(FPA[0]) = T0_14;
MArgument_getMTensorAddress(FPA[1]) = T0_12;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab178:
MArgument_getMTensorAddress(FPA[0]) = T0_12;
MArgument_getMTensorAddress(FPA[1]) = T0_10;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab179:
MArgument_getMTensorAddress(FPA[0]) = T0_10;
MArgument_getMTensorAddress(FPA[1]) = T0_7;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab180:
MArgument_getMTensorAddress(FPA[0]) = T0_7;
MArgument_getMTensorAddress(FPA[1]) = T0_6;
err = FP0(libData, 1, FPA, FPA[1]);/*  CopyTensor  */
if( err)
{
goto error_label;
}
lab181:
funStructCompile->MTensor_copy(Res, *T0_6);
error_label:
funStructCompile->ReleaseInitializedMTensors(Tinit);
funStructCompile->WolframLibraryData_cleanUp(libData, 1);
return err;
}

DLLEXPORT int loopMomenta_wolfram(WolframLibraryData libData, MTensor A1, mint A2, MTensor A3, mreal A4, mreal A5, mreal A6, mreal A7, MTensor *Res)
{
mbool B1_0;
mbool B1_2;
mbool B1_3;
mbool B1_4;
mbool B1_5;
mbool B1_6;
mbool B1_7;
mbool B1_8;
mbool B1_9;
mbool B1_10;
mbool B1_11;
mbool B1_12;
mbool B1_13;
mbool B1_14;
mbool B1_15;
mbool B1_16;
mbool B1_17;
mint I1_0;
mreal R1_0;
mreal R1_1;
mreal R1_2;
mreal R1_3;
mreal R1_4;
mreal R1_5;
mreal R1_6;
mreal R1_7;
mreal R1_8;
mreal R1_9;
mreal R1_10;
mreal R1_12;
mreal R1_15;
mreal R1_17;
mreal R1_18;
mreal R1_20;
mreal R1_21;
mreal R1_22;
mreal R1_23;
mreal R1_24;
mreal R1_25;
mreal R1_26;
mreal R1_27;
mreal R1_28;
mreal R1_29;
mreal R1_30;
mreal R1_31;
mreal R1_32;
mreal R1_33;
mreal R1_34;
mreal R1_35;
mreal R1_36;
mreal R1_37;
mreal R1_38;
mreal R1_39;
mreal R1_40;
mreal R1_41;
mreal R1_42;
mreal R1_43;
mreal R1_44;
mreal R1_45;
mreal R1_46;
mreal R1_47;
mreal R1_48;
mreal R1_49;
mreal R1_50;
mreal R1_51;
mreal R1_52;
mreal R1_53;
mreal R1_54;
mreal R1_55;
mreal R1_56;
mreal R1_57;
mreal R1_58;
mreal R1_59;
mreal R1_60;
mreal R1_61;
mreal R1_62;
mreal R1_63;
mreal R1_64;
mreal R1_65;
mreal R1_66;
mreal R1_67;
mreal R1_68;
mreal R1_69;
mreal R1_70;
mreal R1_71;
mreal R1_72;
mreal R1_73;
mreal R1_74;
mreal R1_75;
mreal R1_76;
mreal R1_77;
mreal R1_78;
mreal R1_79;
mreal R1_80;
mreal R1_81;
mreal R1_82;
MTensor* T1_0;
MTensor* T1_1;
MTensor* T1_2;
MTensorInitializationData Tinit;
mreal *P0;
mint *D0;
mreal *P1;
mint *D1;
mreal *P2;
int err = 0;
Tinit = funStructCompile->GetInitializedMTensors(libData, 1);
T1_2 = MTensorInitializationData_getTensor(Tinit, 0);
T1_0 = &A1;
P0 = MTensor_getRealDataMacro(*T1_0);
D0 = MTensor_getDimensionsMacro(*T1_0);
I1_0 = A2;
T1_1 = &A3;
P1 = MTensor_getRealDataMacro(*T1_1);
D1 = MTensor_getDimensionsMacro(*T1_1);
R1_0 = A4;
R1_1 = A5;
R1_2 = A6;
R1_3 = A7;
{
mint S0 = D0[0];
if( I1_1 > 0)
{
if( I1_1 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_1 - 1;
}
else
{
if( I1_1 == 0 || I1_1 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_1;
}
R1_4 = P0[S0];
}
{
mint S0 = D0[0];
if( I1_2 > 0)
{
if( I1_2 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_2 - 1;
}
else
{
if( I1_2 == 0 || I1_2 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_2;
}
R1_5 = P0[S0];
}
R1_6 = -R1_5;
R1_7 = (mreal) I1_3;
R1_7 = R1_7 + R1_6;
R1_8 = R1_7 * R1_5;
R1_9 = sqrt(R1_8);
{
mint S0 = D0[0];
if( I1_4 > 0)
{
if( I1_4 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_4 - 1;
}
else
{
if( I1_4 == 0 || I1_4 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_4;
}
R1_10 = P0[S0];
}
R1_12 = (mreal) I1_5;
R1_12 = R1_12 * R1_11 * R1_10;
B1_0 = I1_0 == I1_3;
if( !B1_0)
{
goto lab15;
}
B1_2 = B1_1;
goto lab87;
lab15:
B1_2 = I1_0 == I1_5;
if( !B1_2)
{
goto lab19;
}
B1_3 = B1_1;
goto lab86;
lab19:
B1_3 = I1_0 == I1_6;
if( !B1_3)
{
goto lab23;
}
B1_4 = B1_1;
goto lab85;
lab23:
B1_4 = I1_0 == I1_1;
if( !B1_4)
{
goto lab27;
}
B1_5 = B1_1;
goto lab84;
lab27:
B1_5 = I1_0 == I1_2;
if( !B1_5)
{
goto lab31;
}
B1_6 = B1_1;
goto lab83;
lab31:
B1_6 = I1_0 == I1_4;
if( !B1_6)
{
goto lab35;
}
B1_7 = B1_1;
goto lab82;
lab35:
B1_7 = I1_0 == I1_7;
if( !B1_7)
{
goto lab39;
}
B1_8 = B1_1;
goto lab81;
lab39:
B1_8 = I1_0 == I1_8;
if( !B1_8)
{
goto lab43;
}
B1_9 = B1_1;
goto lab80;
lab43:
B1_9 = I1_0 == I1_9;
if( !B1_9)
{
goto lab47;
}
B1_10 = B1_1;
goto lab79;
lab47:
B1_10 = I1_0 == I1_10;
if( !B1_10)
{
goto lab51;
}
B1_11 = B1_1;
goto lab78;
lab51:
B1_11 = I1_0 == I1_11;
if( !B1_11)
{
goto lab55;
}
B1_12 = B1_1;
goto lab77;
lab55:
B1_12 = I1_0 == I1_12;
if( !B1_12)
{
goto lab59;
}
B1_13 = B1_1;
goto lab76;
lab59:
B1_13 = I1_0 == I1_13;
if( !B1_13)
{
goto lab63;
}
B1_14 = B1_1;
goto lab75;
lab63:
B1_14 = I1_0 == I1_14;
if( !B1_14)
{
goto lab67;
}
B1_15 = B1_1;
goto lab74;
lab67:
B1_15 = I1_0 == I1_15;
if( !B1_15)
{
goto lab71;
}
B1_17 = B1_1;
goto lab73;
lab71:
B1_16 = I1_0 == I1_16;
B1_17 = B1_16;
lab73:
B1_15 = B1_17;
lab74:
B1_14 = B1_15;
lab75:
B1_13 = B1_14;
lab76:
B1_12 = B1_13;
lab77:
B1_11 = B1_12;
lab78:
B1_10 = B1_11;
lab79:
B1_9 = B1_10;
lab80:
B1_8 = B1_9;
lab81:
B1_7 = B1_8;
lab82:
B1_6 = B1_7;
lab83:
B1_5 = B1_6;
lab84:
B1_4 = B1_5;
lab85:
B1_3 = B1_4;
lab86:
B1_2 = B1_3;
lab87:
if( !B1_2)
{
goto lab183;
}
{
mint S0 = D0[0];
if( I1_3 > 0)
{
if( I1_3 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_3 - 1;
}
else
{
if( I1_3 == 0 || I1_3 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_3;
}
R1_15 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_15;
S0[1] = R1_3;
B1_0 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_0)
{
goto lab93;
}
R1_18 = R1_13;
goto lab181;
lab93:
{
mint S0 = D0[0];
if( I1_3 > 0)
{
if( I1_3 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_3 - 1;
}
else
{
if( I1_3 == 0 || I1_3 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_3;
}
R1_15 = P0[S0];
}
R1_17 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_17;
S0[1] = R1_15;
B1_3 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_3)
{
goto lab113;
}
{
mint S0 = D0[0];
if( I1_3 > 0)
{
if( I1_3 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_3 - 1;
}
else
{
if( I1_3 == 0 || I1_3 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_3;
}
R1_15 = P0[S0];
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P1[S0];
}
R1_18 = R1_17 * R1_17;
R1_17 = R1_19 * R1_0;
R1_20 = pow(R1_18, R1_17);
R1_18 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P1[S0];
}
R1_21 = R1_17 * R1_17;
R1_17 = R1_19 * R1_0;
R1_22 = pow(R1_21, R1_17);
R1_18 = R1_18 + R1_22;
R1_22 = 1 / R1_18;
R1_20 = R1_20 * R1_22;
{
mreal S0[2];
S0[0] = R1_15;
S0[1] = R1_20;
B1_4 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_6 = B1_4;
goto lab114;
lab113:
B1_6 = B1_18;
lab114:
if( !B1_6)
{
goto lab135;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_15 = P1[S0];
}
R1_20 = R1_15 * R1_15;
{
mint S0 = D0[0];
if( I1_3 > 0)
{
if( I1_3 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_3 - 1;
}
else
{
if( I1_3 == 0 || I1_3 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_3;
}
R1_22 = P0[S0];
}
R1_18 = sqrt(R1_20);
R1_21 = R1_19 * R1_0;
R1_17 = pow(R1_20, R1_21);
R1_21 = pow(R1_1, R1_0);
R1_23 = -R1_22;
R1_24 = (mreal) I1_3;
R1_24 = R1_24 + R1_23;
R1_23 = 1 / R1_24;
R1_21 = R1_21 * R1_23 * R1_22;
R1_23 = -R1_21;
R1_17 = R1_17 + R1_23;
R1_23 = 1 / R1_0;
R1_21 = pow(R1_17, R1_23);
R1_17 = -R1_21;
R1_18 = R1_18 + R1_17;
R1_24 = R1_18;
goto lab180;
lab135:
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P1[S0];
}
R1_21 = R1_17 * R1_17;
R1_17 = R1_19 * R1_0;
R1_23 = pow(R1_21, R1_17);
R1_21 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P1[S0];
}
R1_24 = R1_17 * R1_17;
R1_17 = R1_19 * R1_0;
R1_25 = pow(R1_24, R1_17);
R1_21 = R1_21 + R1_25;
R1_25 = 1 / R1_21;
R1_23 = R1_23 * R1_25;
{
mint S0 = D0[0];
if( I1_3 > 0)
{
if( I1_3 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_3 - 1;
}
else
{
if( I1_3 == 0 || I1_3 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_3;
}
R1_25 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_23;
S0[1] = R1_25;
B1_3 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_3)
{
goto lab157;
}
{
mint S0 = D0[0];
if( I1_3 > 0)
{
if( I1_3 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_3 - 1;
}
else
{
if( I1_3 == 0 || I1_3 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_3;
}
R1_23 = P0[S0];
}
R1_25 = -R1_2;
R1_21 = (mreal) I1_3;
R1_21 = R1_21 + R1_25;
{
mreal S0[2];
S0[0] = R1_23;
S0[1] = R1_21;
B1_4 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_7 = B1_4;
goto lab158;
lab157:
B1_7 = B1_18;
lab158:
if( !B1_7)
{
goto lab178;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_23 = P1[S0];
}
R1_21 = R1_23 * R1_23;
{
mint S0 = D0[0];
if( I1_3 > 0)
{
if( I1_3 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_3 - 1;
}
else
{
if( I1_3 == 0 || I1_3 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_3;
}
R1_25 = P0[S0];
}
R1_24 = sqrt(R1_21);
R1_17 = R1_19 * R1_0;
R1_26 = pow(R1_21, R1_17);
R1_17 = -R1_26;
R1_26 = pow(R1_1, R1_0);
R1_27 = -R1_25;
R1_28 = (mreal) I1_3;
R1_28 = R1_28 + R1_27;
R1_27 = 1 / R1_28;
R1_26 = R1_26 * R1_27 * R1_25;
R1_17 = R1_17 + R1_26;
R1_26 = 1 / R1_0;
R1_27 = pow(R1_17, R1_26);
R1_24 = R1_24 + R1_27;
R1_27 = R1_24;
goto lab179;
lab178:
R1_27 = R1_13;
lab179:
R1_24 = R1_27;
lab180:
R1_18 = R1_24;
lab181:
R1_24 = R1_18;
goto lab184;
lab183:
R1_24 = R1_13;
lab184:
R1_18 = R1_14 * R1_24;
R1_24 = -R1_4;
R1_27 = (mreal) I1_3;
R1_27 = R1_27 + R1_24;
R1_27 = R1_27 * R1_4;
R1_24 = sqrt(R1_27);
B1_2 = I1_0 == I1_3;
if( !B1_2)
{
goto lab194;
}
B1_0 = B1_1;
goto lab211;
lab194:
B1_0 = I1_0 == I1_5;
if( !B1_0)
{
goto lab198;
}
B1_6 = B1_1;
goto lab210;
lab198:
B1_6 = I1_0 == I1_6;
if( !B1_6)
{
goto lab202;
}
B1_7 = B1_1;
goto lab209;
lab202:
B1_7 = I1_0 == I1_1;
if( !B1_7)
{
goto lab206;
}
B1_4 = B1_1;
goto lab208;
lab206:
B1_3 = I1_0 == I1_2;
B1_4 = B1_3;
lab208:
B1_7 = B1_4;
lab209:
B1_6 = B1_7;
lab210:
B1_0 = B1_6;
lab211:
if( !B1_0)
{
goto lab307;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_27 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_27;
S0[1] = R1_3;
B1_2 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_2)
{
goto lab217;
}
R1_26 = R1_13;
goto lab305;
lab217:
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_27 = P0[S0];
}
R1_17 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_17;
S0[1] = R1_27;
B1_6 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_6)
{
goto lab237;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_27 = P0[S0];
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P1[S0];
}
R1_26 = R1_17 * R1_17;
R1_17 = R1_19 * R1_0;
R1_28 = pow(R1_26, R1_17);
R1_26 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P1[S0];
}
R1_29 = R1_17 * R1_17;
R1_17 = R1_19 * R1_0;
R1_30 = pow(R1_29, R1_17);
R1_26 = R1_26 + R1_30;
R1_30 = 1 / R1_26;
R1_28 = R1_28 * R1_30;
{
mreal S0[2];
S0[0] = R1_27;
S0[1] = R1_28;
B1_7 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_4 = B1_7;
goto lab238;
lab237:
B1_4 = B1_18;
lab238:
if( !B1_4)
{
goto lab259;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_27 = P1[S0];
}
R1_28 = R1_27 * R1_27;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_30 = P0[S0];
}
R1_26 = sqrt(R1_28);
R1_29 = R1_19 * R1_0;
R1_17 = pow(R1_28, R1_29);
R1_29 = pow(R1_1, R1_0);
R1_31 = -R1_30;
R1_32 = (mreal) I1_3;
R1_32 = R1_32 + R1_31;
R1_31 = 1 / R1_32;
R1_29 = R1_29 * R1_31 * R1_30;
R1_31 = -R1_29;
R1_17 = R1_17 + R1_31;
R1_31 = 1 / R1_0;
R1_29 = pow(R1_17, R1_31);
R1_17 = -R1_29;
R1_26 = R1_26 + R1_17;
R1_32 = R1_26;
goto lab304;
lab259:
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P1[S0];
}
R1_29 = R1_17 * R1_17;
R1_17 = R1_19 * R1_0;
R1_31 = pow(R1_29, R1_17);
R1_29 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P1[S0];
}
R1_32 = R1_17 * R1_17;
R1_17 = R1_19 * R1_0;
R1_33 = pow(R1_32, R1_17);
R1_29 = R1_29 + R1_33;
R1_33 = 1 / R1_29;
R1_31 = R1_31 * R1_33;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_33 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_31;
S0[1] = R1_33;
B1_6 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_6)
{
goto lab281;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_31 = P0[S0];
}
R1_33 = -R1_2;
R1_29 = (mreal) I1_3;
R1_29 = R1_29 + R1_33;
{
mreal S0[2];
S0[0] = R1_31;
S0[1] = R1_29;
B1_7 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_3 = B1_7;
goto lab282;
lab281:
B1_3 = B1_18;
lab282:
if( !B1_3)
{
goto lab302;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_31 = P1[S0];
}
R1_29 = R1_31 * R1_31;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_33 = P0[S0];
}
R1_32 = sqrt(R1_29);
R1_17 = R1_19 * R1_0;
R1_34 = pow(R1_29, R1_17);
R1_17 = -R1_34;
R1_34 = pow(R1_1, R1_0);
R1_35 = -R1_33;
R1_36 = (mreal) I1_3;
R1_36 = R1_36 + R1_35;
R1_35 = 1 / R1_36;
R1_34 = R1_34 * R1_35 * R1_33;
R1_17 = R1_17 + R1_34;
R1_34 = 1 / R1_0;
R1_35 = pow(R1_17, R1_34);
R1_32 = R1_32 + R1_35;
R1_35 = R1_32;
goto lab303;
lab302:
R1_35 = R1_13;
lab303:
R1_32 = R1_35;
lab304:
R1_26 = R1_32;
lab305:
R1_34 = R1_26;
goto lab518;
lab307:
B1_2 = I1_0 == I1_4;
if( !B1_2)
{
goto lab311;
}
B1_4 = B1_1;
goto lab318;
lab311:
B1_4 = I1_0 == I1_7;
if( !B1_4)
{
goto lab315;
}
B1_6 = B1_1;
goto lab317;
lab315:
B1_3 = I1_0 == I1_8;
B1_6 = B1_3;
lab317:
B1_4 = B1_6;
lab318:
if( !B1_4)
{
goto lab352;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_32 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_32;
S0[1] = R1_3;
B1_2 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_2)
{
goto lab324;
}
R1_34 = R1_13;
goto lab350;
lab324:
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_32 = P0[S0];
}
R1_35 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_35;
S0[1] = R1_32;
B1_6 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_6)
{
goto lab335;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_32 = P0[S0];
}
R1_35 = -R1_2;
R1_17 = (mreal) I1_3;
R1_17 = R1_17 + R1_35;
{
mreal S0[2];
S0[0] = R1_32;
S0[1] = R1_17;
B1_3 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_7 = B1_3;
goto lab336;
lab335:
B1_7 = B1_18;
lab336:
if( !B1_7)
{
goto lab348;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_32 = P0[S0];
}
R1_17 = pow(R1_1, R1_0);
R1_35 = -R1_32;
R1_34 = (mreal) I1_3;
R1_34 = R1_34 + R1_35;
R1_35 = 1 / R1_34;
R1_17 = R1_17 * R1_35 * R1_32;
R1_35 = 1 / R1_0;
R1_34 = pow(R1_17, R1_35);
R1_17 = R1_34;
goto lab349;
lab348:
R1_17 = R1_13;
lab349:
R1_34 = R1_17;
lab350:
R1_36 = R1_34;
goto lab517;
lab352:
B1_2 = I1_0 == I1_9;
if( !B1_2)
{
goto lab356;
}
B1_6 = B1_1;
goto lab358;
lab356:
B1_7 = I1_0 == I1_10;
B1_6 = B1_7;
lab358:
if( !B1_6)
{
goto lab454;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_17;
S0[1] = R1_3;
B1_2 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_2)
{
goto lab364;
}
R1_36 = R1_13;
goto lab452;
lab364:
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P0[S0];
}
R1_35 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_35;
S0[1] = R1_17;
B1_7 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_7)
{
goto lab384;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P0[S0];
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_35 = P1[S0];
}
R1_36 = R1_35 * R1_35;
R1_35 = R1_19 * R1_0;
R1_37 = pow(R1_36, R1_35);
R1_36 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_35 = P1[S0];
}
R1_38 = R1_35 * R1_35;
R1_35 = R1_19 * R1_0;
R1_39 = pow(R1_38, R1_35);
R1_36 = R1_36 + R1_39;
R1_39 = 1 / R1_36;
R1_37 = R1_37 * R1_39;
{
mreal S0[2];
S0[0] = R1_17;
S0[1] = R1_37;
B1_3 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_8 = B1_3;
goto lab385;
lab384:
B1_8 = B1_18;
lab385:
if( !B1_8)
{
goto lab406;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_17 = P1[S0];
}
R1_37 = R1_17 * R1_17;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_39 = P0[S0];
}
R1_36 = sqrt(R1_37);
R1_38 = R1_19 * R1_0;
R1_35 = pow(R1_37, R1_38);
R1_38 = pow(R1_1, R1_0);
R1_40 = -R1_39;
R1_41 = (mreal) I1_3;
R1_41 = R1_41 + R1_40;
R1_40 = 1 / R1_41;
R1_38 = R1_38 * R1_40 * R1_39;
R1_40 = -R1_38;
R1_35 = R1_35 + R1_40;
R1_40 = 1 / R1_0;
R1_38 = pow(R1_35, R1_40);
R1_35 = -R1_38;
R1_36 = R1_36 + R1_35;
R1_41 = R1_36;
goto lab451;
lab406:
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_35 = P1[S0];
}
R1_38 = R1_35 * R1_35;
R1_35 = R1_19 * R1_0;
R1_40 = pow(R1_38, R1_35);
R1_38 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_35 = P1[S0];
}
R1_41 = R1_35 * R1_35;
R1_35 = R1_19 * R1_0;
R1_42 = pow(R1_41, R1_35);
R1_38 = R1_38 + R1_42;
R1_42 = 1 / R1_38;
R1_40 = R1_40 * R1_42;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_42 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_40;
S0[1] = R1_42;
B1_7 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_7)
{
goto lab428;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_40 = P0[S0];
}
R1_42 = -R1_2;
R1_38 = (mreal) I1_3;
R1_38 = R1_38 + R1_42;
{
mreal S0[2];
S0[0] = R1_40;
S0[1] = R1_38;
B1_3 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_9 = B1_3;
goto lab429;
lab428:
B1_9 = B1_18;
lab429:
if( !B1_9)
{
goto lab449;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_40 = P1[S0];
}
R1_38 = R1_40 * R1_40;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_42 = P0[S0];
}
R1_41 = sqrt(R1_38);
R1_35 = R1_19 * R1_0;
R1_43 = pow(R1_38, R1_35);
R1_35 = -R1_43;
R1_43 = pow(R1_1, R1_0);
R1_44 = -R1_42;
R1_45 = (mreal) I1_3;
R1_45 = R1_45 + R1_44;
R1_44 = 1 / R1_45;
R1_43 = R1_43 * R1_44 * R1_42;
R1_35 = R1_35 + R1_43;
R1_43 = 1 / R1_0;
R1_44 = pow(R1_35, R1_43);
R1_41 = R1_41 + R1_44;
R1_44 = R1_41;
goto lab450;
lab449:
R1_44 = R1_13;
lab450:
R1_41 = R1_44;
lab451:
R1_36 = R1_41;
lab452:
R1_43 = R1_36;
goto lab516;
lab454:
B1_2 = I1_0 == I1_11;
if( !B1_2)
{
goto lab458;
}
B1_8 = B1_1;
goto lab480;
lab458:
B1_8 = I1_0 == I1_12;
if( !B1_8)
{
goto lab462;
}
B1_9 = B1_1;
goto lab479;
lab462:
B1_9 = I1_0 == I1_13;
if( !B1_9)
{
goto lab466;
}
B1_7 = B1_1;
goto lab478;
lab466:
B1_7 = I1_0 == I1_14;
if( !B1_7)
{
goto lab470;
}
B1_3 = B1_1;
goto lab477;
lab470:
B1_3 = I1_0 == I1_15;
if( !B1_3)
{
goto lab474;
}
B1_11 = B1_1;
goto lab476;
lab474:
B1_10 = I1_0 == I1_16;
B1_11 = B1_10;
lab476:
B1_3 = B1_11;
lab477:
B1_7 = B1_3;
lab478:
B1_9 = B1_7;
lab479:
B1_8 = B1_9;
lab480:
if( !B1_8)
{
goto lab514;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_41 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_41;
S0[1] = R1_3;
B1_2 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_2)
{
goto lab486;
}
R1_43 = R1_13;
goto lab512;
lab486:
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_41 = P0[S0];
}
R1_44 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_44;
S0[1] = R1_41;
B1_9 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_9)
{
goto lab497;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_41 = P0[S0];
}
R1_44 = -R1_2;
R1_35 = (mreal) I1_3;
R1_35 = R1_35 + R1_44;
{
mreal S0[2];
S0[0] = R1_41;
S0[1] = R1_35;
B1_7 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_3 = B1_7;
goto lab498;
lab497:
B1_3 = B1_18;
lab498:
if( !B1_3)
{
goto lab510;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_41 = P0[S0];
}
R1_35 = pow(R1_1, R1_0);
R1_44 = -R1_41;
R1_43 = (mreal) I1_3;
R1_43 = R1_43 + R1_44;
R1_44 = 1 / R1_43;
R1_35 = R1_35 * R1_44 * R1_41;
R1_44 = 1 / R1_0;
R1_43 = pow(R1_35, R1_44);
R1_35 = R1_43;
goto lab511;
lab510:
R1_35 = R1_13;
lab511:
R1_43 = R1_35;
lab512:
R1_35 = R1_43;
goto lab515;
lab514:
R1_35 = R1_13;
lab515:
R1_43 = R1_35;
lab516:
R1_36 = R1_43;
lab517:
R1_34 = R1_36;
lab518:
R1_26 = (mreal) I1_5;
R1_26 = R1_26 * R1_24 * R1_34;
R1_24 = (mreal) I1_5;
R1_24 = R1_24 * R1_4;
R1_34 = (mreal) I1_18;
R1_34 = R1_34 + R1_24;
B1_0 = I1_0 == I1_3;
if( !B1_0)
{
goto lab528;
}
B1_4 = B1_1;
goto lab545;
lab528:
B1_4 = I1_0 == I1_5;
if( !B1_4)
{
goto lab532;
}
B1_6 = B1_1;
goto lab544;
lab532:
B1_6 = I1_0 == I1_6;
if( !B1_6)
{
goto lab536;
}
B1_8 = B1_1;
goto lab543;
lab536:
B1_8 = I1_0 == I1_1;
if( !B1_8)
{
goto lab540;
}
B1_3 = B1_1;
goto lab542;
lab540:
B1_2 = I1_0 == I1_2;
B1_3 = B1_2;
lab542:
B1_8 = B1_3;
lab543:
B1_6 = B1_8;
lab544:
B1_4 = B1_6;
lab545:
if( !B1_4)
{
goto lab641;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_24 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_24;
S0[1] = R1_3;
B1_0 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_0)
{
goto lab551;
}
R1_43 = R1_13;
goto lab639;
lab551:
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_24 = P0[S0];
}
R1_36 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_36;
S0[1] = R1_24;
B1_6 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_6)
{
goto lab571;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_24 = P0[S0];
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_36 = P1[S0];
}
R1_43 = R1_36 * R1_36;
R1_36 = R1_19 * R1_0;
R1_35 = pow(R1_43, R1_36);
R1_43 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_36 = P1[S0];
}
R1_44 = R1_36 * R1_36;
R1_36 = R1_19 * R1_0;
R1_45 = pow(R1_44, R1_36);
R1_43 = R1_43 + R1_45;
R1_45 = 1 / R1_43;
R1_35 = R1_35 * R1_45;
{
mreal S0[2];
S0[0] = R1_24;
S0[1] = R1_35;
B1_8 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_3 = B1_8;
goto lab572;
lab571:
B1_3 = B1_18;
lab572:
if( !B1_3)
{
goto lab593;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_24 = P1[S0];
}
R1_35 = R1_24 * R1_24;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_45 = P0[S0];
}
R1_43 = sqrt(R1_35);
R1_44 = R1_19 * R1_0;
R1_36 = pow(R1_35, R1_44);
R1_44 = pow(R1_1, R1_0);
R1_46 = -R1_45;
R1_47 = (mreal) I1_3;
R1_47 = R1_47 + R1_46;
R1_46 = 1 / R1_47;
R1_44 = R1_44 * R1_46 * R1_45;
R1_46 = -R1_44;
R1_36 = R1_36 + R1_46;
R1_46 = 1 / R1_0;
R1_44 = pow(R1_36, R1_46);
R1_36 = -R1_44;
R1_43 = R1_43 + R1_36;
R1_47 = R1_43;
goto lab638;
lab593:
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_36 = P1[S0];
}
R1_44 = R1_36 * R1_36;
R1_36 = R1_19 * R1_0;
R1_46 = pow(R1_44, R1_36);
R1_44 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_36 = P1[S0];
}
R1_47 = R1_36 * R1_36;
R1_36 = R1_19 * R1_0;
R1_48 = pow(R1_47, R1_36);
R1_44 = R1_44 + R1_48;
R1_48 = 1 / R1_44;
R1_46 = R1_46 * R1_48;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_48 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_46;
S0[1] = R1_48;
B1_6 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_6)
{
goto lab615;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_46 = P0[S0];
}
R1_48 = -R1_2;
R1_44 = (mreal) I1_3;
R1_44 = R1_44 + R1_48;
{
mreal S0[2];
S0[0] = R1_46;
S0[1] = R1_44;
B1_8 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_2 = B1_8;
goto lab616;
lab615:
B1_2 = B1_18;
lab616:
if( !B1_2)
{
goto lab636;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_46 = P1[S0];
}
R1_44 = R1_46 * R1_46;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_48 = P0[S0];
}
R1_47 = sqrt(R1_44);
R1_36 = R1_19 * R1_0;
R1_49 = pow(R1_44, R1_36);
R1_36 = -R1_49;
R1_49 = pow(R1_1, R1_0);
R1_50 = -R1_48;
R1_51 = (mreal) I1_3;
R1_51 = R1_51 + R1_50;
R1_50 = 1 / R1_51;
R1_49 = R1_49 * R1_50 * R1_48;
R1_36 = R1_36 + R1_49;
R1_49 = 1 / R1_0;
R1_50 = pow(R1_36, R1_49);
R1_47 = R1_47 + R1_50;
R1_50 = R1_47;
goto lab637;
lab636:
R1_50 = R1_13;
lab637:
R1_47 = R1_50;
lab638:
R1_43 = R1_47;
lab639:
R1_49 = R1_43;
goto lab852;
lab641:
B1_0 = I1_0 == I1_4;
if( !B1_0)
{
goto lab645;
}
B1_3 = B1_1;
goto lab652;
lab645:
B1_3 = I1_0 == I1_7;
if( !B1_3)
{
goto lab649;
}
B1_6 = B1_1;
goto lab651;
lab649:
B1_2 = I1_0 == I1_8;
B1_6 = B1_2;
lab651:
B1_3 = B1_6;
lab652:
if( !B1_3)
{
goto lab686;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_47 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_47;
S0[1] = R1_3;
B1_0 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_0)
{
goto lab658;
}
R1_49 = R1_13;
goto lab684;
lab658:
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_47 = P0[S0];
}
R1_50 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_50;
S0[1] = R1_47;
B1_6 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_6)
{
goto lab669;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_47 = P0[S0];
}
R1_50 = -R1_2;
R1_36 = (mreal) I1_3;
R1_36 = R1_36 + R1_50;
{
mreal S0[2];
S0[0] = R1_47;
S0[1] = R1_36;
B1_2 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_8 = B1_2;
goto lab670;
lab669:
B1_8 = B1_18;
lab670:
if( !B1_8)
{
goto lab682;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_47 = P0[S0];
}
R1_36 = pow(R1_1, R1_0);
R1_50 = -R1_47;
R1_49 = (mreal) I1_3;
R1_49 = R1_49 + R1_50;
R1_50 = 1 / R1_49;
R1_36 = R1_36 * R1_50 * R1_47;
R1_50 = 1 / R1_0;
R1_49 = pow(R1_36, R1_50);
R1_36 = R1_49;
goto lab683;
lab682:
R1_36 = R1_13;
lab683:
R1_49 = R1_36;
lab684:
R1_51 = R1_49;
goto lab851;
lab686:
B1_0 = I1_0 == I1_9;
if( !B1_0)
{
goto lab690;
}
B1_6 = B1_1;
goto lab692;
lab690:
B1_8 = I1_0 == I1_10;
B1_6 = B1_8;
lab692:
if( !B1_6)
{
goto lab788;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_36 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_36;
S0[1] = R1_3;
B1_0 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_0)
{
goto lab698;
}
R1_51 = R1_13;
goto lab786;
lab698:
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_36 = P0[S0];
}
R1_50 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_50;
S0[1] = R1_36;
B1_8 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_8)
{
goto lab718;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_36 = P0[S0];
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_50 = P1[S0];
}
R1_51 = R1_50 * R1_50;
R1_50 = R1_19 * R1_0;
R1_52 = pow(R1_51, R1_50);
R1_51 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_50 = P1[S0];
}
R1_53 = R1_50 * R1_50;
R1_50 = R1_19 * R1_0;
R1_54 = pow(R1_53, R1_50);
R1_51 = R1_51 + R1_54;
R1_54 = 1 / R1_51;
R1_52 = R1_52 * R1_54;
{
mreal S0[2];
S0[0] = R1_36;
S0[1] = R1_52;
B1_2 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_9 = B1_2;
goto lab719;
lab718:
B1_9 = B1_18;
lab719:
if( !B1_9)
{
goto lab740;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_36 = P1[S0];
}
R1_52 = R1_36 * R1_36;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_54 = P0[S0];
}
R1_51 = sqrt(R1_52);
R1_53 = R1_19 * R1_0;
R1_50 = pow(R1_52, R1_53);
R1_53 = pow(R1_1, R1_0);
R1_55 = -R1_54;
R1_56 = (mreal) I1_3;
R1_56 = R1_56 + R1_55;
R1_55 = 1 / R1_56;
R1_53 = R1_53 * R1_55 * R1_54;
R1_55 = -R1_53;
R1_50 = R1_50 + R1_55;
R1_55 = 1 / R1_0;
R1_53 = pow(R1_50, R1_55);
R1_50 = -R1_53;
R1_51 = R1_51 + R1_50;
R1_56 = R1_51;
goto lab785;
lab740:
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_50 = P1[S0];
}
R1_53 = R1_50 * R1_50;
R1_50 = R1_19 * R1_0;
R1_55 = pow(R1_53, R1_50);
R1_53 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_50 = P1[S0];
}
R1_56 = R1_50 * R1_50;
R1_50 = R1_19 * R1_0;
R1_57 = pow(R1_56, R1_50);
R1_53 = R1_53 + R1_57;
R1_57 = 1 / R1_53;
R1_55 = R1_55 * R1_57;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_57 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_55;
S0[1] = R1_57;
B1_8 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_8)
{
goto lab762;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_55 = P0[S0];
}
R1_57 = -R1_2;
R1_53 = (mreal) I1_3;
R1_53 = R1_53 + R1_57;
{
mreal S0[2];
S0[0] = R1_55;
S0[1] = R1_53;
B1_2 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_7 = B1_2;
goto lab763;
lab762:
B1_7 = B1_18;
lab763:
if( !B1_7)
{
goto lab783;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_55 = P1[S0];
}
R1_53 = R1_55 * R1_55;
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_57 = P0[S0];
}
R1_56 = sqrt(R1_53);
R1_50 = R1_19 * R1_0;
R1_58 = pow(R1_53, R1_50);
R1_50 = -R1_58;
R1_58 = pow(R1_1, R1_0);
R1_59 = -R1_57;
R1_60 = (mreal) I1_3;
R1_60 = R1_60 + R1_59;
R1_59 = 1 / R1_60;
R1_58 = R1_58 * R1_59 * R1_57;
R1_50 = R1_50 + R1_58;
R1_58 = 1 / R1_0;
R1_59 = pow(R1_50, R1_58);
R1_56 = R1_56 + R1_59;
R1_59 = R1_56;
goto lab784;
lab783:
R1_59 = R1_13;
lab784:
R1_56 = R1_59;
lab785:
R1_51 = R1_56;
lab786:
R1_58 = R1_51;
goto lab850;
lab788:
B1_0 = I1_0 == I1_11;
if( !B1_0)
{
goto lab792;
}
B1_9 = B1_1;
goto lab814;
lab792:
B1_9 = I1_0 == I1_12;
if( !B1_9)
{
goto lab796;
}
B1_7 = B1_1;
goto lab813;
lab796:
B1_7 = I1_0 == I1_13;
if( !B1_7)
{
goto lab800;
}
B1_8 = B1_1;
goto lab812;
lab800:
B1_8 = I1_0 == I1_14;
if( !B1_8)
{
goto lab804;
}
B1_2 = B1_1;
goto lab811;
lab804:
B1_2 = I1_0 == I1_15;
if( !B1_2)
{
goto lab808;
}
B1_10 = B1_1;
goto lab810;
lab808:
B1_11 = I1_0 == I1_16;
B1_10 = B1_11;
lab810:
B1_2 = B1_10;
lab811:
B1_8 = B1_2;
lab812:
B1_7 = B1_8;
lab813:
B1_9 = B1_7;
lab814:
if( !B1_9)
{
goto lab848;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_56 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_56;
S0[1] = R1_3;
B1_0 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_0)
{
goto lab820;
}
R1_58 = R1_13;
goto lab846;
lab820:
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_56 = P0[S0];
}
R1_59 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_59;
S0[1] = R1_56;
B1_7 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_7)
{
goto lab831;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_56 = P0[S0];
}
R1_59 = -R1_2;
R1_50 = (mreal) I1_3;
R1_50 = R1_50 + R1_59;
{
mreal S0[2];
S0[0] = R1_56;
S0[1] = R1_50;
B1_8 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_2 = B1_8;
goto lab832;
lab831:
B1_2 = B1_18;
lab832:
if( !B1_2)
{
goto lab844;
}
{
mint S0 = D0[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_56 = P0[S0];
}
R1_50 = pow(R1_1, R1_0);
R1_59 = -R1_56;
R1_58 = (mreal) I1_3;
R1_58 = R1_58 + R1_59;
R1_59 = 1 / R1_58;
R1_50 = R1_50 * R1_59 * R1_56;
R1_59 = 1 / R1_0;
R1_58 = pow(R1_50, R1_59);
R1_50 = R1_58;
goto lab845;
lab844:
R1_50 = R1_13;
lab845:
R1_58 = R1_50;
lab846:
R1_50 = R1_58;
goto lab849;
lab848:
R1_50 = R1_13;
lab849:
R1_58 = R1_50;
lab850:
R1_51 = R1_58;
lab851:
R1_49 = R1_51;
lab852:
R1_34 = R1_34 * R1_49;
R1_49 = cos(R1_12);
B1_4 = I1_0 == I1_3;
if( !B1_4)
{
goto lab951;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_43 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_43;
S0[1] = R1_3;
B1_3 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_3)
{
goto lab861;
}
R1_58 = R1_13;
goto lab949;
lab861:
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_43 = P0[S0];
}
R1_51 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_51;
S0[1] = R1_43;
B1_6 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_6)
{
goto lab881;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_43 = P0[S0];
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_51 = P1[S0];
}
R1_58 = R1_51 * R1_51;
R1_51 = R1_19 * R1_0;
R1_50 = pow(R1_58, R1_51);
R1_58 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_51 = P1[S0];
}
R1_59 = R1_51 * R1_51;
R1_51 = R1_19 * R1_0;
R1_60 = pow(R1_59, R1_51);
R1_58 = R1_58 + R1_60;
R1_60 = 1 / R1_58;
R1_50 = R1_50 * R1_60;
{
mreal S0[2];
S0[0] = R1_43;
S0[1] = R1_50;
B1_9 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_0 = B1_9;
goto lab882;
lab881:
B1_0 = B1_18;
lab882:
if( !B1_0)
{
goto lab903;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_43 = P1[S0];
}
R1_50 = R1_43 * R1_43;
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_60 = P0[S0];
}
R1_58 = sqrt(R1_50);
R1_59 = R1_19 * R1_0;
R1_51 = pow(R1_50, R1_59);
R1_59 = pow(R1_1, R1_0);
R1_61 = -R1_60;
R1_62 = (mreal) I1_3;
R1_62 = R1_62 + R1_61;
R1_61 = 1 / R1_62;
R1_59 = R1_59 * R1_61 * R1_60;
R1_61 = -R1_59;
R1_51 = R1_51 + R1_61;
R1_61 = 1 / R1_0;
R1_59 = pow(R1_51, R1_61);
R1_51 = -R1_59;
R1_58 = R1_58 + R1_51;
R1_62 = R1_58;
goto lab948;
lab903:
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_51 = P1[S0];
}
R1_59 = R1_51 * R1_51;
R1_51 = R1_19 * R1_0;
R1_61 = pow(R1_59, R1_51);
R1_59 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_51 = P1[S0];
}
R1_62 = R1_51 * R1_51;
R1_51 = R1_19 * R1_0;
R1_63 = pow(R1_62, R1_51);
R1_59 = R1_59 + R1_63;
R1_63 = 1 / R1_59;
R1_61 = R1_61 * R1_63;
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_63 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_61;
S0[1] = R1_63;
B1_6 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_6)
{
goto lab925;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_61 = P0[S0];
}
R1_63 = -R1_2;
R1_59 = (mreal) I1_3;
R1_59 = R1_59 + R1_63;
{
mreal S0[2];
S0[0] = R1_61;
S0[1] = R1_59;
B1_9 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_2 = B1_9;
goto lab926;
lab925:
B1_2 = B1_18;
lab926:
if( !B1_2)
{
goto lab946;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_61 = P1[S0];
}
R1_59 = R1_61 * R1_61;
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_63 = P0[S0];
}
R1_62 = sqrt(R1_59);
R1_51 = R1_19 * R1_0;
R1_64 = pow(R1_59, R1_51);
R1_51 = -R1_64;
R1_64 = pow(R1_1, R1_0);
R1_65 = -R1_63;
R1_66 = (mreal) I1_3;
R1_66 = R1_66 + R1_65;
R1_65 = 1 / R1_66;
R1_64 = R1_64 * R1_65 * R1_63;
R1_51 = R1_51 + R1_64;
R1_64 = 1 / R1_0;
R1_65 = pow(R1_51, R1_64);
R1_62 = R1_62 + R1_65;
R1_65 = R1_62;
goto lab947;
lab946:
R1_65 = R1_13;
lab947:
R1_62 = R1_65;
lab948:
R1_58 = R1_62;
lab949:
R1_64 = R1_58;
goto lab1058;
lab951:
B1_3 = I1_0 == I1_5;
if( !B1_3)
{
goto lab955;
}
B1_0 = B1_1;
goto lab1022;
lab955:
B1_0 = I1_0 == I1_6;
if( !B1_0)
{
goto lab959;
}
B1_2 = B1_1;
goto lab1021;
lab959:
B1_2 = I1_0 == I1_1;
if( !B1_2)
{
goto lab963;
}
B1_6 = B1_1;
goto lab1020;
lab963:
B1_6 = I1_0 == I1_2;
if( !B1_6)
{
goto lab967;
}
B1_9 = B1_1;
goto lab1019;
lab967:
B1_9 = I1_0 == I1_4;
if( !B1_9)
{
goto lab971;
}
B1_7 = B1_1;
goto lab1018;
lab971:
B1_7 = I1_0 == I1_7;
if( !B1_7)
{
goto lab975;
}
B1_8 = B1_1;
goto lab1017;
lab975:
B1_8 = I1_0 == I1_8;
if( !B1_8)
{
goto lab979;
}
B1_10 = B1_1;
goto lab1016;
lab979:
B1_10 = I1_0 == I1_9;
if( !B1_10)
{
goto lab983;
}
B1_11 = B1_1;
goto lab1015;
lab983:
B1_11 = I1_0 == I1_10;
if( !B1_11)
{
goto lab987;
}
B1_12 = B1_1;
goto lab1014;
lab987:
B1_12 = I1_0 == I1_11;
if( !B1_12)
{
goto lab991;
}
B1_13 = B1_1;
goto lab1013;
lab991:
B1_13 = I1_0 == I1_12;
if( !B1_13)
{
goto lab995;
}
B1_14 = B1_1;
goto lab1012;
lab995:
B1_14 = I1_0 == I1_13;
if( !B1_14)
{
goto lab999;
}
B1_15 = B1_1;
goto lab1011;
lab999:
B1_15 = I1_0 == I1_14;
if( !B1_15)
{
goto lab1003;
}
B1_17 = B1_1;
goto lab1010;
lab1003:
B1_17 = I1_0 == I1_15;
if( !B1_17)
{
goto lab1007;
}
B1_5 = B1_1;
goto lab1009;
lab1007:
B1_16 = I1_0 == I1_16;
B1_5 = B1_16;
lab1009:
B1_17 = B1_5;
lab1010:
B1_15 = B1_17;
lab1011:
B1_14 = B1_15;
lab1012:
B1_13 = B1_14;
lab1013:
B1_12 = B1_13;
lab1014:
B1_11 = B1_12;
lab1015:
B1_10 = B1_11;
lab1016:
B1_8 = B1_10;
lab1017:
B1_7 = B1_8;
lab1018:
B1_9 = B1_7;
lab1019:
B1_6 = B1_9;
lab1020:
B1_2 = B1_6;
lab1021:
B1_0 = B1_2;
lab1022:
if( !B1_0)
{
goto lab1056;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_62 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_62;
S0[1] = R1_3;
B1_3 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_3)
{
goto lab1028;
}
R1_64 = R1_13;
goto lab1054;
lab1028:
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_62 = P0[S0];
}
R1_65 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_65;
S0[1] = R1_62;
B1_2 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_2)
{
goto lab1039;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_62 = P0[S0];
}
R1_65 = -R1_2;
R1_51 = (mreal) I1_3;
R1_51 = R1_51 + R1_65;
{
mreal S0[2];
S0[0] = R1_62;
S0[1] = R1_51;
B1_6 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_9 = B1_6;
goto lab1040;
lab1039:
B1_9 = B1_18;
lab1040:
if( !B1_9)
{
goto lab1052;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_62 = P0[S0];
}
R1_51 = pow(R1_1, R1_0);
R1_65 = -R1_62;
R1_64 = (mreal) I1_3;
R1_64 = R1_64 + R1_65;
R1_65 = 1 / R1_64;
R1_51 = R1_51 * R1_65 * R1_62;
R1_65 = 1 / R1_0;
R1_64 = pow(R1_51, R1_65);
R1_51 = R1_64;
goto lab1053;
lab1052:
R1_51 = R1_13;
lab1053:
R1_64 = R1_51;
lab1054:
R1_51 = R1_64;
goto lab1057;
lab1056:
R1_51 = R1_13;
lab1057:
R1_64 = R1_51;
lab1058:
R1_58 = (mreal) I1_5;
R1_58 = R1_58 * R1_49 * R1_9 * R1_64;
B1_4 = I1_0 == I1_3;
if( !B1_4)
{
goto lab1157;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_49 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_49;
S0[1] = R1_3;
B1_0 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_0)
{
goto lab1067;
}
R1_51 = R1_13;
goto lab1155;
lab1067:
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_49 = P0[S0];
}
R1_64 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_64;
S0[1] = R1_49;
B1_3 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_3)
{
goto lab1087;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_49 = P0[S0];
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_64 = P1[S0];
}
R1_51 = R1_64 * R1_64;
R1_64 = R1_19 * R1_0;
R1_65 = pow(R1_51, R1_64);
R1_51 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_64 = P1[S0];
}
R1_66 = R1_64 * R1_64;
R1_64 = R1_19 * R1_0;
R1_67 = pow(R1_66, R1_64);
R1_51 = R1_51 + R1_67;
R1_67 = 1 / R1_51;
R1_65 = R1_65 * R1_67;
{
mreal S0[2];
S0[0] = R1_49;
S0[1] = R1_65;
B1_9 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_2 = B1_9;
goto lab1088;
lab1087:
B1_2 = B1_18;
lab1088:
if( !B1_2)
{
goto lab1109;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_49 = P1[S0];
}
R1_65 = R1_49 * R1_49;
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_67 = P0[S0];
}
R1_51 = sqrt(R1_65);
R1_66 = R1_19 * R1_0;
R1_64 = pow(R1_65, R1_66);
R1_66 = pow(R1_1, R1_0);
R1_68 = -R1_67;
R1_69 = (mreal) I1_3;
R1_69 = R1_69 + R1_68;
R1_68 = 1 / R1_69;
R1_66 = R1_66 * R1_68 * R1_67;
R1_68 = -R1_66;
R1_64 = R1_64 + R1_68;
R1_68 = 1 / R1_0;
R1_66 = pow(R1_64, R1_68);
R1_64 = -R1_66;
R1_51 = R1_51 + R1_64;
R1_69 = R1_51;
goto lab1154;
lab1109:
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_64 = P1[S0];
}
R1_66 = R1_64 * R1_64;
R1_64 = R1_19 * R1_0;
R1_68 = pow(R1_66, R1_64);
R1_66 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_64 = P1[S0];
}
R1_69 = R1_64 * R1_64;
R1_64 = R1_19 * R1_0;
R1_70 = pow(R1_69, R1_64);
R1_66 = R1_66 + R1_70;
R1_70 = 1 / R1_66;
R1_68 = R1_68 * R1_70;
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_70 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_68;
S0[1] = R1_70;
B1_3 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_3)
{
goto lab1131;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_68 = P0[S0];
}
R1_70 = -R1_2;
R1_66 = (mreal) I1_3;
R1_66 = R1_66 + R1_70;
{
mreal S0[2];
S0[0] = R1_68;
S0[1] = R1_66;
B1_9 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_6 = B1_9;
goto lab1132;
lab1131:
B1_6 = B1_18;
lab1132:
if( !B1_6)
{
goto lab1152;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_68 = P1[S0];
}
R1_66 = R1_68 * R1_68;
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_70 = P0[S0];
}
R1_69 = sqrt(R1_66);
R1_64 = R1_19 * R1_0;
R1_71 = pow(R1_66, R1_64);
R1_64 = -R1_71;
R1_71 = pow(R1_1, R1_0);
R1_72 = -R1_70;
R1_73 = (mreal) I1_3;
R1_73 = R1_73 + R1_72;
R1_72 = 1 / R1_73;
R1_71 = R1_71 * R1_72 * R1_70;
R1_64 = R1_64 + R1_71;
R1_71 = 1 / R1_0;
R1_72 = pow(R1_64, R1_71);
R1_69 = R1_69 + R1_72;
R1_72 = R1_69;
goto lab1153;
lab1152:
R1_72 = R1_13;
lab1153:
R1_69 = R1_72;
lab1154:
R1_51 = R1_69;
lab1155:
R1_71 = R1_51;
goto lab1264;
lab1157:
B1_0 = I1_0 == I1_5;
if( !B1_0)
{
goto lab1161;
}
B1_2 = B1_1;
goto lab1228;
lab1161:
B1_2 = I1_0 == I1_6;
if( !B1_2)
{
goto lab1165;
}
B1_6 = B1_1;
goto lab1227;
lab1165:
B1_6 = I1_0 == I1_1;
if( !B1_6)
{
goto lab1169;
}
B1_3 = B1_1;
goto lab1226;
lab1169:
B1_3 = I1_0 == I1_2;
if( !B1_3)
{
goto lab1173;
}
B1_9 = B1_1;
goto lab1225;
lab1173:
B1_9 = I1_0 == I1_4;
if( !B1_9)
{
goto lab1177;
}
B1_7 = B1_1;
goto lab1224;
lab1177:
B1_7 = I1_0 == I1_7;
if( !B1_7)
{
goto lab1181;
}
B1_8 = B1_1;
goto lab1223;
lab1181:
B1_8 = I1_0 == I1_8;
if( !B1_8)
{
goto lab1185;
}
B1_10 = B1_1;
goto lab1222;
lab1185:
B1_10 = I1_0 == I1_9;
if( !B1_10)
{
goto lab1189;
}
B1_11 = B1_1;
goto lab1221;
lab1189:
B1_11 = I1_0 == I1_10;
if( !B1_11)
{
goto lab1193;
}
B1_12 = B1_1;
goto lab1220;
lab1193:
B1_12 = I1_0 == I1_11;
if( !B1_12)
{
goto lab1197;
}
B1_13 = B1_1;
goto lab1219;
lab1197:
B1_13 = I1_0 == I1_12;
if( !B1_13)
{
goto lab1201;
}
B1_14 = B1_1;
goto lab1218;
lab1201:
B1_14 = I1_0 == I1_13;
if( !B1_14)
{
goto lab1205;
}
B1_15 = B1_1;
goto lab1217;
lab1205:
B1_15 = I1_0 == I1_14;
if( !B1_15)
{
goto lab1209;
}
B1_17 = B1_1;
goto lab1216;
lab1209:
B1_17 = I1_0 == I1_15;
if( !B1_17)
{
goto lab1213;
}
B1_16 = B1_1;
goto lab1215;
lab1213:
B1_5 = I1_0 == I1_16;
B1_16 = B1_5;
lab1215:
B1_17 = B1_16;
lab1216:
B1_15 = B1_17;
lab1217:
B1_14 = B1_15;
lab1218:
B1_13 = B1_14;
lab1219:
B1_12 = B1_13;
lab1220:
B1_11 = B1_12;
lab1221:
B1_10 = B1_11;
lab1222:
B1_8 = B1_10;
lab1223:
B1_7 = B1_8;
lab1224:
B1_9 = B1_7;
lab1225:
B1_3 = B1_9;
lab1226:
B1_6 = B1_3;
lab1227:
B1_2 = B1_6;
lab1228:
if( !B1_2)
{
goto lab1262;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_69 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_69;
S0[1] = R1_3;
B1_0 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_0)
{
goto lab1234;
}
R1_71 = R1_13;
goto lab1260;
lab1234:
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_69 = P0[S0];
}
R1_72 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_72;
S0[1] = R1_69;
B1_6 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_6)
{
goto lab1245;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_69 = P0[S0];
}
R1_72 = -R1_2;
R1_64 = (mreal) I1_3;
R1_64 = R1_64 + R1_72;
{
mreal S0[2];
S0[0] = R1_69;
S0[1] = R1_64;
B1_3 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_9 = B1_3;
goto lab1246;
lab1245:
B1_9 = B1_18;
lab1246:
if( !B1_9)
{
goto lab1258;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_69 = P0[S0];
}
R1_64 = pow(R1_1, R1_0);
R1_72 = -R1_69;
R1_71 = (mreal) I1_3;
R1_71 = R1_71 + R1_72;
R1_72 = 1 / R1_71;
R1_64 = R1_64 * R1_72 * R1_69;
R1_72 = 1 / R1_0;
R1_71 = pow(R1_64, R1_72);
R1_64 = R1_71;
goto lab1259;
lab1258:
R1_64 = R1_13;
lab1259:
R1_71 = R1_64;
lab1260:
R1_64 = R1_71;
goto lab1263;
lab1262:
R1_64 = R1_13;
lab1263:
R1_71 = R1_64;
lab1264:
R1_51 = sin(R1_12);
R1_64 = (mreal) I1_5;
R1_64 = R1_64 * R1_9 * R1_71 * R1_51;
R1_71 = (mreal) I1_5;
R1_71 = R1_71 * R1_5;
R1_51 = (mreal) I1_18;
R1_51 = R1_51 + R1_71;
B1_4 = I1_0 == I1_3;
if( !B1_4)
{
goto lab1368;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_71 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_71;
S0[1] = R1_3;
B1_2 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_2)
{
goto lab1278;
}
R1_73 = R1_13;
goto lab1366;
lab1278:
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_71 = P0[S0];
}
R1_72 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_72;
S0[1] = R1_71;
B1_0 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_0)
{
goto lab1298;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_71 = P0[S0];
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_72 = P1[S0];
}
R1_73 = R1_72 * R1_72;
R1_72 = R1_19 * R1_0;
R1_74 = pow(R1_73, R1_72);
R1_73 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_72 = P1[S0];
}
R1_75 = R1_72 * R1_72;
R1_72 = R1_19 * R1_0;
R1_76 = pow(R1_75, R1_72);
R1_73 = R1_73 + R1_76;
R1_76 = 1 / R1_73;
R1_74 = R1_74 * R1_76;
{
mreal S0[2];
S0[0] = R1_71;
S0[1] = R1_74;
B1_9 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_6 = B1_9;
goto lab1299;
lab1298:
B1_6 = B1_18;
lab1299:
if( !B1_6)
{
goto lab1320;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_71 = P1[S0];
}
R1_74 = R1_71 * R1_71;
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_76 = P0[S0];
}
R1_73 = sqrt(R1_74);
R1_75 = R1_19 * R1_0;
R1_72 = pow(R1_74, R1_75);
R1_75 = pow(R1_1, R1_0);
R1_77 = -R1_76;
R1_78 = (mreal) I1_3;
R1_78 = R1_78 + R1_77;
R1_77 = 1 / R1_78;
R1_75 = R1_75 * R1_77 * R1_76;
R1_77 = -R1_75;
R1_72 = R1_72 + R1_77;
R1_77 = 1 / R1_0;
R1_75 = pow(R1_72, R1_77);
R1_72 = -R1_75;
R1_73 = R1_73 + R1_72;
R1_78 = R1_73;
goto lab1365;
lab1320:
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_72 = P1[S0];
}
R1_75 = R1_72 * R1_72;
R1_72 = R1_19 * R1_0;
R1_77 = pow(R1_75, R1_72);
R1_75 = pow(R1_1, R1_0);
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_72 = P1[S0];
}
R1_78 = R1_72 * R1_72;
R1_72 = R1_19 * R1_0;
R1_79 = pow(R1_78, R1_72);
R1_75 = R1_75 + R1_79;
R1_79 = 1 / R1_75;
R1_77 = R1_77 * R1_79;
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_79 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_77;
S0[1] = R1_79;
B1_0 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_0)
{
goto lab1342;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_77 = P0[S0];
}
R1_79 = -R1_2;
R1_75 = (mreal) I1_3;
R1_75 = R1_75 + R1_79;
{
mreal S0[2];
S0[0] = R1_77;
S0[1] = R1_75;
B1_9 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_3 = B1_9;
goto lab1343;
lab1342:
B1_3 = B1_18;
lab1343:
if( !B1_3)
{
goto lab1363;
}
{
mint S0 = D1[0];
if( I1_5 > 0)
{
if( I1_5 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_5 - 1;
}
else
{
if( I1_5 == 0 || I1_5 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_5;
}
R1_77 = P1[S0];
}
R1_75 = R1_77 * R1_77;
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_79 = P0[S0];
}
R1_78 = sqrt(R1_75);
R1_72 = R1_19 * R1_0;
R1_80 = pow(R1_75, R1_72);
R1_72 = -R1_80;
R1_80 = pow(R1_1, R1_0);
R1_81 = -R1_79;
R1_82 = (mreal) I1_3;
R1_82 = R1_82 + R1_81;
R1_81 = 1 / R1_82;
R1_80 = R1_80 * R1_81 * R1_79;
R1_72 = R1_72 + R1_80;
R1_80 = 1 / R1_0;
R1_81 = pow(R1_72, R1_80);
R1_78 = R1_78 + R1_81;
R1_81 = R1_78;
goto lab1364;
lab1363:
R1_81 = R1_13;
lab1364:
R1_78 = R1_81;
lab1365:
R1_73 = R1_78;
lab1366:
R1_80 = R1_73;
goto lab1475;
lab1368:
B1_2 = I1_0 == I1_5;
if( !B1_2)
{
goto lab1372;
}
B1_6 = B1_1;
goto lab1439;
lab1372:
B1_6 = I1_0 == I1_6;
if( !B1_6)
{
goto lab1376;
}
B1_3 = B1_1;
goto lab1438;
lab1376:
B1_3 = I1_0 == I1_1;
if( !B1_3)
{
goto lab1380;
}
B1_0 = B1_1;
goto lab1437;
lab1380:
B1_0 = I1_0 == I1_2;
if( !B1_0)
{
goto lab1384;
}
B1_9 = B1_1;
goto lab1436;
lab1384:
B1_9 = I1_0 == I1_4;
if( !B1_9)
{
goto lab1388;
}
B1_7 = B1_1;
goto lab1435;
lab1388:
B1_7 = I1_0 == I1_7;
if( !B1_7)
{
goto lab1392;
}
B1_8 = B1_1;
goto lab1434;
lab1392:
B1_8 = I1_0 == I1_8;
if( !B1_8)
{
goto lab1396;
}
B1_10 = B1_1;
goto lab1433;
lab1396:
B1_10 = I1_0 == I1_9;
if( !B1_10)
{
goto lab1400;
}
B1_11 = B1_1;
goto lab1432;
lab1400:
B1_11 = I1_0 == I1_10;
if( !B1_11)
{
goto lab1404;
}
B1_12 = B1_1;
goto lab1431;
lab1404:
B1_12 = I1_0 == I1_11;
if( !B1_12)
{
goto lab1408;
}
B1_13 = B1_1;
goto lab1430;
lab1408:
B1_13 = I1_0 == I1_12;
if( !B1_13)
{
goto lab1412;
}
B1_14 = B1_1;
goto lab1429;
lab1412:
B1_14 = I1_0 == I1_13;
if( !B1_14)
{
goto lab1416;
}
B1_15 = B1_1;
goto lab1428;
lab1416:
B1_15 = I1_0 == I1_14;
if( !B1_15)
{
goto lab1420;
}
B1_17 = B1_1;
goto lab1427;
lab1420:
B1_17 = I1_0 == I1_15;
if( !B1_17)
{
goto lab1424;
}
B1_5 = B1_1;
goto lab1426;
lab1424:
B1_16 = I1_0 == I1_16;
B1_5 = B1_16;
lab1426:
B1_17 = B1_5;
lab1427:
B1_15 = B1_17;
lab1428:
B1_14 = B1_15;
lab1429:
B1_13 = B1_14;
lab1430:
B1_12 = B1_13;
lab1431:
B1_11 = B1_12;
lab1432:
B1_10 = B1_11;
lab1433:
B1_8 = B1_10;
lab1434:
B1_7 = B1_8;
lab1435:
B1_9 = B1_7;
lab1436:
B1_0 = B1_9;
lab1437:
B1_3 = B1_0;
lab1438:
B1_6 = B1_3;
lab1439:
if( !B1_6)
{
goto lab1473;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_78 = P0[S0];
}
{
mreal S0[2];
S0[0] = R1_78;
S0[1] = R1_3;
B1_2 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
if( !B1_2)
{
goto lab1445;
}
R1_80 = R1_13;
goto lab1471;
lab1445:
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_78 = P0[S0];
}
R1_81 = (mreal) I1_17;
{
mreal S0[2];
S0[0] = R1_81;
S0[1] = R1_78;
B1_3 = funStructCompile->Compare_R(4, R1_16, 2, S0);
}
if( !B1_3)
{
goto lab1456;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_78 = P0[S0];
}
R1_81 = -R1_2;
R1_72 = (mreal) I1_3;
R1_72 = R1_72 + R1_81;
{
mreal S0[2];
S0[0] = R1_78;
S0[1] = R1_72;
B1_0 = funStructCompile->Compare_R(3, R1_16, 2, S0);
}
B1_9 = B1_0;
goto lab1457;
lab1456:
B1_9 = B1_18;
lab1457:
if( !B1_9)
{
goto lab1469;
}
{
mint S0 = D0[0];
if( I1_6 > 0)
{
if( I1_6 > S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = I1_6 - 1;
}
else
{
if( I1_6 == 0 || I1_6 < -S0)
{
return LIBRARY_DIMENSION_ERROR;
}
S0 = S0 + I1_6;
}
R1_78 = P0[S0];
}
R1_72 = pow(R1_1, R1_0);
R1_81 = -R1_78;
R1_80 = (mreal) I1_3;
R1_80 = R1_80 + R1_81;
R1_81 = 1 / R1_80;
R1_72 = R1_72 * R1_81 * R1_78;
R1_81 = 1 / R1_0;
R1_80 = pow(R1_72, R1_81);
R1_72 = R1_80;
goto lab1470;
lab1469:
R1_72 = R1_13;
lab1470:
R1_80 = R1_72;
lab1471:
R1_72 = R1_80;
goto lab1474;
lab1473:
R1_72 = R1_13;
lab1474:
R1_80 = R1_72;
lab1475:
R1_51 = R1_51 * R1_80;
{
mint S0[2] = {3, 3};
err = funStructCompile->MTensor_allocate(T1_2, 3, 2, S0);
if( err)
{
goto error_label;
}
P2 = MTensor_getRealDataMacro(*T1_2);
P2[0] = R1_13;
P2[1] = R1_13;
P2[2] = R1_18;
P2[3] = R1_26;
P2[4] = R1_13;
P2[5] = R1_34;
P2[6] = R1_58;
P2[7] = R1_64;
P2[8] = R1_51;
}
funStructCompile->MTensor_copy(Res, *T1_2);
error_label:
funStructCompile->ReleaseInitializedMTensors(Tinit);
funStructCompile->WolframLibraryData_cleanUp(libData, 1);
return err;
}

DLLEXPORT int jacobian_wolfram(WolframLibraryData libData, MTensor A1, mint A2, MTensor A3, mint A4, mint A5, mreal A6, mreal A7, mreal *Res)
{
mint I2_0;
mint I2_1;
mint I2_2;
mreal R2_0;
mreal R2_1;
mreal R2_2;
mreal R2_3;
mreal R2_4;
mreal R2_5;
MTensor* T2_0;
MTensor* T2_1;
int err = 0;
T2_0 = &A1;
I2_0 = A2;
T2_1 = &A3;
I2_1 = A4;
I2_2 = A5;
R2_0 = A6;
R2_1 = A7;
err = F0(libData, *T2_0, I2_0, *T2_1, I2_1, I2_2, R2_0, R2_1, &R2_3);
if( err)
{
goto error_label;
}
err = F1(libData, *T2_0, I2_0, *T2_1, I2_1, I2_2, R2_0, R2_1, &R2_4);
if( err)
{
goto error_label;
}
R2_2 = 1 / R2_4;
R2_5 = R2_3 * R2_2;
*Res = R2_5;
error_label:
funStructCompile->WolframLibraryData_cleanUp(libData, 1);
return err;
}

