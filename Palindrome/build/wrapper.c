#include "palindrome.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

typedef struct msg {
  int length;
  int chas[200];
} msg_t;

extern int generateRandomValue(_Bool lflag, _Bool uflag, int lbound, int ubound) {
  if (lbound == 0 && ubound == 0) {
    int s;
    syscall(SYS_getrandom, &s, sizeof(int), 1);
    return rand();
  } else {
    int min = lflag ? lbound : lbound+1;
    int max = uflag ? ubound : ubound-1;
    int range = max - min + 1;
    int s;
    syscall(SYS_getrandom, &s, sizeof(int), 1);
    double rnd = ((double) rand())/(1.0 + ((double) RAND_MAX));
    if (rnd < 0) rnd = rnd * -1;
    int value = ((int) (((double) range)*rnd));
    return value + min;
  }
}

msg_t step() {
  updateFunction();
  msg_t msg;
  msg.length    = length[0];
  msg.chas[0]   = cha0[0];
  msg.chas[1]   = cha1[0];
  msg.chas[2]   = cha2[0];
  msg.chas[3]   = cha3[0];
  msg.chas[4]   = cha4[0];
  msg.chas[5]   = cha5[0];
  msg.chas[6]   = cha6[0];
  msg.chas[7]   = cha7[0];
  msg.chas[8]   = cha8[0];
  msg.chas[9]   = cha9[0];
  msg.chas[10]  = cha10[0];
  msg.chas[11]  = cha11[0];
  msg.chas[12]  = cha12[0];
  msg.chas[13]  = cha13[0];
  msg.chas[14]  = cha14[0];
  msg.chas[15]  = cha15[0];
  msg.chas[16]  = cha16[0];
  msg.chas[17]  = cha17[0];
  msg.chas[18]  = cha18[0];
  msg.chas[19]  = cha19[0];
  msg.chas[20]  = cha20[0];
  msg.chas[21]  = cha21[0];
  msg.chas[22]  = cha22[0];
  msg.chas[23]  = cha23[0];
  msg.chas[24]  = cha24[0];
  msg.chas[25]  = cha25[0];
  msg.chas[26]  = cha26[0];
  msg.chas[27]  = cha27[0];
  msg.chas[28]  = cha28[0];
  msg.chas[29]  = cha29[0];
  msg.chas[30]  = cha30[0];
  msg.chas[31]  = cha31[0];
  msg.chas[32]  = cha32[0];
  msg.chas[33]  = cha33[0];
  msg.chas[34]  = cha34[0];
  msg.chas[35]  = cha35[0];
  msg.chas[36]  = cha36[0];
  msg.chas[37]  = cha37[0];
  msg.chas[38]  = cha38[0];
  msg.chas[39]  = cha39[0];
  msg.chas[40]  = cha40[0];
  msg.chas[41]  = cha41[0];
  msg.chas[42]  = cha42[0];
  msg.chas[43]  = cha43[0];
  msg.chas[44]  = cha44[0];
  msg.chas[45]  = cha45[0];
  msg.chas[46]  = cha46[0];
  msg.chas[47]  = cha47[0];
  msg.chas[48]  = cha48[0];
  msg.chas[49]  = cha49[0];
  msg.chas[50]  = cha50[0];
  msg.chas[51]  = cha51[0];
  msg.chas[52]  = cha52[0];
  msg.chas[53]  = cha53[0];
  msg.chas[54]  = cha54[0];
  msg.chas[55]  = cha55[0];
  msg.chas[56]  = cha56[0];
  msg.chas[57]  = cha57[0];
  msg.chas[58]  = cha58[0];
  msg.chas[59]  = cha59[0];
  msg.chas[60]  = cha60[0];
  msg.chas[61]  = cha61[0];
  msg.chas[62]  = cha62[0];
  msg.chas[63]  = cha63[0];
  msg.chas[64]  = cha64[0];
  msg.chas[65]  = cha65[0];
  msg.chas[66]  = cha66[0];
  msg.chas[67]  = cha67[0];
  msg.chas[68]  = cha68[0];
  msg.chas[69]  = cha69[0];
  msg.chas[70]  = cha70[0];
  msg.chas[71]  = cha71[0];
  msg.chas[72]  = cha72[0];
  msg.chas[73]  = cha73[0];
  msg.chas[74]  = cha74[0];
  msg.chas[75]  = cha75[0];
  msg.chas[76]  = cha76[0];
  msg.chas[77]  = cha77[0];
  msg.chas[78]  = cha78[0];
  msg.chas[79]  = cha79[0];
  msg.chas[80]  = cha80[0];
  msg.chas[81]  = cha81[0];
  msg.chas[82]  = cha82[0];
  msg.chas[83]  = cha83[0];
  msg.chas[84]  = cha84[0];
  msg.chas[85]  = cha85[0];
  msg.chas[86]  = cha86[0];
  msg.chas[87]  = cha87[0];
  msg.chas[88]  = cha88[0];
  msg.chas[89]  = cha89[0];
  msg.chas[90]  = cha90[0];
  msg.chas[91]  = cha91[0];
  msg.chas[92]  = cha92[0];
  msg.chas[93]  = cha93[0];
  msg.chas[94]  = cha94[0];
  msg.chas[95]  = cha95[0];
  msg.chas[96]  = cha96[0];
  msg.chas[97]  = cha97[0];
  msg.chas[98]  = cha98[0];
  msg.chas[99]  = cha99[0];
  msg.chas[100] = cha100[0];
  msg.chas[101] = cha101[0];
  msg.chas[102] = cha102[0];
  msg.chas[103] = cha103[0];
  msg.chas[104] = cha104[0];
  msg.chas[105] = cha105[0];
  msg.chas[106] = cha106[0];
  msg.chas[107] = cha107[0];
  msg.chas[108] = cha108[0];
  msg.chas[109] = cha109[0];
  msg.chas[110] = cha110[0];
  msg.chas[111] = cha111[0];
  msg.chas[112] = cha112[0];
  msg.chas[113] = cha113[0];
  msg.chas[114] = cha114[0];
  msg.chas[115] = cha115[0];
  msg.chas[116] = cha116[0];
  msg.chas[117] = cha117[0];
  msg.chas[118] = cha118[0];
  msg.chas[119] = cha119[0];
  msg.chas[120] = cha120[0];
  msg.chas[121] = cha121[0];
  msg.chas[122] = cha122[0];
  msg.chas[123] = cha123[0];
  msg.chas[124] = cha124[0];
  msg.chas[125] = cha125[0];
  msg.chas[126] = cha126[0];
  msg.chas[127] = cha127[0];
  msg.chas[128] = cha128[0];
  msg.chas[129] = cha129[0];
  msg.chas[130] = cha130[0];
  msg.chas[131] = cha131[0];
  msg.chas[132] = cha132[0];
  msg.chas[133] = cha133[0];
  msg.chas[134] = cha134[0];
  msg.chas[135] = cha135[0];
  msg.chas[136] = cha136[0];
  msg.chas[137] = cha137[0];
  msg.chas[138] = cha138[0];
  msg.chas[139] = cha139[0];
  msg.chas[140] = cha140[0];
  msg.chas[141] = cha141[0];
  msg.chas[142] = cha142[0];
  msg.chas[143] = cha143[0];
  msg.chas[144] = cha144[0];
  msg.chas[145] = cha145[0];
  msg.chas[146] = cha146[0];
  msg.chas[147] = cha147[0];
  msg.chas[148] = cha148[0];
  msg.chas[149] = cha149[0];
  msg.chas[150] = cha150[0];
  msg.chas[151] = cha151[0];
  msg.chas[152] = cha152[0];
  msg.chas[153] = cha153[0];
  msg.chas[154] = cha154[0];
  msg.chas[155] = cha155[0];
  msg.chas[156] = cha156[0];
  msg.chas[157] = cha157[0];
  msg.chas[158] = cha158[0];
  msg.chas[159] = cha159[0];
  msg.chas[160] = cha160[0];
  msg.chas[161] = cha161[0];
  msg.chas[162] = cha162[0];
  msg.chas[163] = cha163[0];
  msg.chas[164] = cha164[0];
  msg.chas[165] = cha165[0];
  msg.chas[166] = cha166[0];
  msg.chas[167] = cha167[0];
  msg.chas[168] = cha168[0];
  msg.chas[169] = cha169[0];
  msg.chas[170] = cha170[0];
  msg.chas[171] = cha171[0];
  msg.chas[172] = cha172[0];
  msg.chas[173] = cha173[0];
  msg.chas[174] = cha174[0];
  msg.chas[175] = cha175[0];
  msg.chas[176] = cha176[0];
  msg.chas[177] = cha177[0];
  msg.chas[178] = cha178[0];
  msg.chas[179] = cha179[0];
  msg.chas[180] = cha180[0];
  msg.chas[181] = cha181[0];
  msg.chas[182] = cha182[0];
  msg.chas[183] = cha183[0];
  msg.chas[184] = cha184[0];
  msg.chas[185] = cha185[0];
  msg.chas[186] = cha186[0];
  msg.chas[187] = cha187[0];
  msg.chas[188] = cha188[0];
  msg.chas[189] = cha189[0];
  msg.chas[190] = cha190[0];
  msg.chas[191] = cha191[0];
  msg.chas[192] = cha192[0];
  msg.chas[193] = cha193[0];
  msg.chas[194] = cha194[0];
  msg.chas[195] = cha195[0];
  msg.chas[196] = cha196[0];
  msg.chas[197] = cha197[0];
  msg.chas[198] = cha198[0];
  msg.chas[199] = cha199[0];

  return msg;
}
