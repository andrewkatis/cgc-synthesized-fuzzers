#include "simple_integer_calculator.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

typedef struct strChar {
    int cha1;
    int cha2;
    int cha3;
    int cha4;
    int cha5;
    int cha6;
} strChar_t;

typedef struct expr {
    int typeF;
    int operF;
    strChar_t strF;
    int cmd;
    int typeB;
    int operB;
    strChar_t strB;
} expr_t;

typedef struct msg {
    int length
    expr_t exp1;
    expr_t exp2;
    expr_t exp3;
    expr_t exp4;
    expr_t exp5;
    expr_t exp6;
    expr_t exp7;
    expr_t exp8;
    expr_t exp9;
    expr_t exp10;
    expr_t exp11;
    expr_t exp12;
    expr_t exp13;
    expr_t exp14;
    expr_t exp15;
    expr_t exp16;
    expr_t exp17;
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
    srand(time(NULL));
    updateFunction();
    msg_t msg;
    msg.length          = length[0];

    msg.exp1.typeF      = msg_exp1_typeF[0];
    msg.exp1.operF      = msg_exp1_operF[0];
    msg.exp1.strF.cha1  = msg_exp1_strF_cha1[0];
    msg.exp1.strF.cha2  = msg_exp1_strF_cha2[0];
    msg.exp1.strF.cha3  = msg_exp1_strF_cha3[0];
    msg.exp1.strF.cha4  = msg_exp1_strF_cha4[0];
    msg.exp1.strF.cha5  = msg_exp1_strF_cha5[0];
    msg.exp1.strF.cha6  = msg_exp1_strF_cha6[0];
    msg.exp1.cmd        = msg_exp1_cmd[0];
    msg.exp1.typeB      = msg_exp1_typeB[0];
    msg.exp1.operB      = msg_exp1_operB[0];
    msg.exp1.strB.cha1  = msg_exp1_strB_cha1[0];
    msg.exp1.strB.cha2  = msg_exp1_strB_cha2[0];
    msg.exp1.strB.cha3  = msg_exp1_strB_cha3[0];
    msg.exp1.strB.cha4  = msg_exp1_strB_cha4[0];
    msg.exp1.strB.cha5  = msg_exp1_strB_cha5[0];
    msg.exp1.strB.cha6  = msg_exp1_strB_cha6[0];

    msg.exp2.typeF      = msg_exp2_typeF[0];
    msg.exp2.operF      = msg_exp2_operF[0];
    msg.exp2.strF.cha1  = msg_exp2_strF_cha1[0];
    msg.exp2.strF.cha2  = msg_exp2_strF_cha2[0];
    msg.exp2.strF.cha3  = msg_exp2_strF_cha3[0];
    msg.exp2.strF.cha4  = msg_exp2_strF_cha4[0];
    msg.exp2.strF.cha5  = msg_exp2_strF_cha5[0];
    msg.exp2.strF.cha6  = msg_exp2_strF_cha6[0];
    msg.exp2.cmd        = msg_exp2_cmd[0];
    msg.exp2.typeB      = msg_exp2_typeB[0];
    msg.exp2.operB      = msg_exp2_operB[0];
    msg.exp2.strB.cha1  = msg_exp2_strB_cha1[0];
    msg.exp2.strB.cha2  = msg_exp2_strB_cha2[0];
    msg.exp2.strB.cha3  = msg_exp2_strB_cha3[0];
    msg.exp2.strB.cha4  = msg_exp2_strB_cha4[0];
    msg.exp2.strB.cha5  = msg_exp2_strB_cha5[0];
    msg.exp2.strB.cha6  = msg_exp2_strB_cha6[0];

    msg.exp3.typeF      = msg_exp3_typeF[0];
    msg.exp3.operF      = msg_exp3_operF[0];
    msg.exp3.strF.cha1  = msg_exp3_strF_cha1[0];
    msg.exp3.strF.cha2  = msg_exp3_strF_cha2[0];
    msg.exp3.strF.cha3  = msg_exp3_strF_cha3[0];
    msg.exp3.strF.cha4  = msg_exp3_strF_cha4[0];
    msg.exp3.strF.cha5  = msg_exp3_strF_cha5[0];
    msg.exp3.strF.cha6  = msg_exp3_strF_cha6[0];
    msg.exp3.cmd        = msg_exp3_cmd[0];
    msg.exp3.typeB      = msg_exp3_typeB[0];
    msg.exp3.operB      = msg_exp3_operB[0];
    msg.exp3.strB.cha1  = msg_exp3_strB_cha1[0];
    msg.exp3.strB.cha2  = msg_exp3_strB_cha2[0];
    msg.exp3.strB.cha3  = msg_exp3_strB_cha3[0];
    msg.exp3.strB.cha4  = msg_exp3_strB_cha4[0];
    msg.exp3.strB.cha5  = msg_exp3_strB_cha5[0];
    msg.exp3.strB.cha6  = msg_exp3_strB_cha6[0];

    msg.exp4.typeF      = msg_exp4_typeF[0];
    msg.exp4.operF      = msg_exp4_operF[0];
    msg.exp4.strF.cha1  = msg_exp4_strF_cha1[0];
    msg.exp4.strF.cha2  = msg_exp4_strF_cha2[0];
    msg.exp4.strF.cha3  = msg_exp4_strF_cha3[0];
    msg.exp4.strF.cha4  = msg_exp4_strF_cha4[0];
    msg.exp4.strF.cha5  = msg_exp4_strF_cha5[0];
    msg.exp4.strF.cha6  = msg_exp4_strF_cha6[0];
    msg.exp4.cmd        = msg_exp4_cmd[0];
    msg.exp4.typeB      = msg_exp4_typeB[0];
    msg.exp4.operB      = msg_exp4_operB[0];
    msg.exp4.strB.cha1  = msg_exp4_strB_cha1[0];
    msg.exp4.strB.cha2  = msg_exp4_strB_cha2[0];
    msg.exp4.strB.cha3  = msg_exp4_strB_cha3[0];
    msg.exp4.strB.cha4  = msg_exp4_strB_cha4[0];
    msg.exp4.strB.cha5  = msg_exp4_strB_cha5[0];
    msg.exp4.strB.cha6  = msg_exp4_strB_cha6[0];

    msg.exp5.typeF      = msg_exp5_typeF[0];
    msg.exp5.operF      = msg_exp5_operF[0];
    msg.exp5.strF.cha1  = msg_exp5_strF_cha1[0];
    msg.exp5.strF.cha2  = msg_exp5_strF_cha2[0];
    msg.exp5.strF.cha3  = msg_exp5_strF_cha3[0];
    msg.exp5.strF.cha4  = msg_exp5_strF_cha4[0];
    msg.exp5.strF.cha5  = msg_exp5_strF_cha5[0];
    msg.exp5.strF.cha6  = msg_exp5_strF_cha6[0];
    msg.exp5.cmd        = msg_exp5_cmd[0];
    msg.exp5.typeB      = msg_exp5_typeB[0];
    msg.exp5.operB      = msg_exp5_operB[0];
    msg.exp5.strB.cha1  = msg_exp5_strB_cha1[0];
    msg.exp5.strB.cha2  = msg_exp5_strB_cha2[0];
    msg.exp5.strB.cha3  = msg_exp5_strB_cha3[0];
    msg.exp5.strB.cha4  = msg_exp5_strB_cha4[0];
    msg.exp5.strB.cha5  = msg_exp5_strB_cha5[0];
    msg.exp5.strB.cha6  = msg_exp5_strB_cha6[0];

    msg.exp6.typeF      = msg_exp6_typeF[0];
    msg.exp6.operF      = msg_exp6_operF[0];
    msg.exp6.strF.cha1  = msg_exp6_strF_cha1[0];
    msg.exp6.strF.cha2  = msg_exp6_strF_cha2[0];
    msg.exp6.strF.cha3  = msg_exp6_strF_cha3[0];
    msg.exp6.strF.cha4  = msg_exp6_strF_cha4[0];
    msg.exp6.strF.cha5  = msg_exp6_strF_cha5[0];
    msg.exp6.strF.cha6  = msg_exp6_strF_cha6[0];
    msg.exp6.cmd        = msg_exp6_cmd[0];
    msg.exp6.typeB      = msg_exp6_typeB[0];
    msg.exp6.operB      = msg_exp6_operB[0];
    msg.exp6.strB.cha1  = msg_exp6_strB_cha1[0];
    msg.exp6.strB.cha2  = msg_exp6_strB_cha2[0];
    msg.exp6.strB.cha3  = msg_exp6_strB_cha3[0];
    msg.exp6.strB.cha4  = msg_exp6_strB_cha4[0];
    msg.exp6.strB.cha5  = msg_exp6_strB_cha5[0];
    msg.exp6.strB.cha6  = msg_exp6_strB_cha6[0];

    msg.exp7.typeF      = msg_exp7_typeF[0];
    msg.exp7.operF      = msg_exp7_operF[0];
    msg.exp7.strF.cha1  = msg_exp7_strF_cha1[0];
    msg.exp7.strF.cha2  = msg_exp7_strF_cha2[0];
    msg.exp7.strF.cha3  = msg_exp7_strF_cha3[0];
    msg.exp7.strF.cha4  = msg_exp7_strF_cha4[0];
    msg.exp7.strF.cha5  = msg_exp7_strF_cha5[0];
    msg.exp7.strF.cha6  = msg_exp7_strF_cha6[0];
    msg.exp7.cmd        = msg_exp7_cmd[0];
    msg.exp7.typeB      = msg_exp7_typeB[0];
    msg.exp7.operB      = msg_exp7_operB[0];
    msg.exp7.strB.cha1  = msg_exp7_strB_cha1[0];
    msg.exp7.strB.cha2  = msg_exp7_strB_cha2[0];
    msg.exp7.strB.cha3  = msg_exp7_strB_cha3[0];
    msg.exp7.strB.cha4  = msg_exp7_strB_cha4[0];
    msg.exp7.strB.cha5  = msg_exp7_strB_cha5[0];
    msg.exp7.strB.cha6  = msg_exp7_strB_cha6[0];

    msg.exp8.typeF      = msg_exp8_typeF[0];
    msg.exp8.operF      = msg_exp8_operF[0];
    msg.exp8.strF.cha1  = msg_exp8_strF_cha1[0];
    msg.exp8.strF.cha2  = msg_exp8_strF_cha2[0];
    msg.exp8.strF.cha3  = msg_exp8_strF_cha3[0];
    msg.exp8.strF.cha4  = msg_exp8_strF_cha4[0];
    msg.exp8.strF.cha5  = msg_exp8_strF_cha5[0];
    msg.exp8.strF.cha6  = msg_exp8_strF_cha6[0];
    msg.exp8.cmd        = msg_exp8_cmd[0];
    msg.exp8.typeB      = msg_exp8_typeB[0];
    msg.exp8.operB      = msg_exp8_operB[0];
    msg.exp8.strB.cha1  = msg_exp8_strB_cha1[0];
    msg.exp8.strB.cha2  = msg_exp8_strB_cha2[0];
    msg.exp8.strB.cha3  = msg_exp8_strB_cha3[0];
    msg.exp8.strB.cha4  = msg_exp8_strB_cha4[0];
    msg.exp8.strB.cha5  = msg_exp8_strB_cha5[0];
    msg.exp8.strB.cha6  = msg_exp8_strB_cha6[0];

    msg.exp9.typeF      = msg_exp9_typeF[0];
    msg.exp9.operF      = msg_exp9_operF[0];
    msg.exp9.strF.cha1  = msg_exp9_strF_cha1[0];
    msg.exp9.strF.cha2  = msg_exp9_strF_cha2[0];
    msg.exp9.strF.cha3  = msg_exp9_strF_cha3[0];
    msg.exp9.strF.cha4  = msg_exp9_strF_cha4[0];
    msg.exp9.strF.cha5  = msg_exp9_strF_cha5[0];
    msg.exp9.strF.cha6  = msg_exp9_strF_cha6[0];
    msg.exp9.cmd        = msg_exp9_cmd[0];
    msg.exp9.typeB      = msg_exp9_typeB[0];
    msg.exp9.operB      = msg_exp9_operB[0];
    msg.exp9.strB.cha1  = msg_exp9_strB_cha1[0];
    msg.exp9.strB.cha2  = msg_exp9_strB_cha2[0];
    msg.exp9.strB.cha3  = msg_exp9_strB_cha3[0];
    msg.exp9.strB.cha4  = msg_exp9_strB_cha4[0];
    msg.exp9.strB.cha5  = msg_exp9_strB_cha5[0];
    msg.exp9.strB.cha6  = msg_exp9_strB_cha6[0];

    msg.exp10.typeF     = msg_exp10_typeF[0];
    msg.exp10.operF     = msg_exp10_operF[0];
    msg.exp10.strF.cha1 = msg_exp10_strF_cha1[0];
    msg.exp10.strF.cha2 = msg_exp10_strF_cha2[0];
    msg.exp10.strF.cha3 = msg_exp10_strF_cha3[0];
    msg.exp10.strF.cha4 = msg_exp10_strF_cha4[0];
    msg.exp10.strF.cha5 = msg_exp10_strF_cha5[0];
    msg.exp10.strF.cha6 = msg_exp10_strF_cha6[0];
    msg.exp10.cmd       = msg_exp10_cmd[0];
    msg.exp10.typeB     = msg_exp10_typeB[0];
    msg.exp10.operB     = msg_exp10_operB[0];
    msg.exp10.strB.cha1 = msg_exp10_strB_cha1[0];
    msg.exp10.strB.cha2 = msg_exp10_strB_cha2[0];
    msg.exp10.strB.cha3 = msg_exp10_strB_cha3[0];
    msg.exp10.strB.cha4 = msg_exp10_strB_cha4[0];
    msg.exp10.strB.cha5 = msg_exp10_strB_cha5[0];
    msg.exp10.strB.cha6 = msg_exp10_strB_cha6[0];

    msg.exp11.typeF     = msg_exp11_typeF[0];
    msg.exp11.operF     = msg_exp11_operF[0];
    msg.exp11.strF.cha1 = msg_exp11_strF_cha1[0];
    msg.exp11.strF.cha2 = msg_exp11_strF_cha2[0];
    msg.exp11.strF.cha3 = msg_exp11_strF_cha3[0];
    msg.exp11.strF.cha4 = msg_exp11_strF_cha4[0];
    msg.exp11.strF.cha5 = msg_exp11_strF_cha5[0];
    msg.exp11.strF.cha6 = msg_exp11_strF_cha6[0];
    msg.exp11.cmd       = msg_exp11_cmd[0];
    msg.exp11.typeB     = msg_exp11_typeB[0];
    msg.exp11.operB     = msg_exp11_operB[0];
    msg.exp11.strB.cha1 = msg_exp11_strB_cha1[0];
    msg.exp11.strB.cha2 = msg_exp11_strB_cha2[0];
    msg.exp11.strB.cha3 = msg_exp11_strB_cha3[0];
    msg.exp11.strB.cha4 = msg_exp11_strB_cha4[0];
    msg.exp11.strB.cha5 = msg_exp11_strB_cha5[0];
    msg.exp11.strB.cha6 = msg_exp11_strB_cha6[0];

    msg.exp12.typeF     = msg_exp12_typeF[0];
    msg.exp12.operF     = msg_exp12_operF[0];
    msg.exp12.strF.cha1 = msg_exp12_strF_cha1[0];
    msg.exp12.strF.cha2 = msg_exp12_strF_cha2[0];
    msg.exp12.strF.cha3 = msg_exp12_strF_cha3[0];
    msg.exp12.strF.cha4 = msg_exp12_strF_cha4[0];
    msg.exp12.strF.cha5 = msg_exp12_strF_cha5[0];
    msg.exp12.strF.cha6 = msg_exp12_strF_cha6[0];
    msg.exp12.cmd       = msg_exp12_cmd[0];
    msg.exp12.typeB     = msg_exp12_typeB[0];
    msg.exp12.operB     = msg_exp12_operB[0];
    msg.exp12.strB.cha1 = msg_exp12_strB_cha1[0];
    msg.exp12.strB.cha2 = msg_exp12_strB_cha2[0];
    msg.exp12.strB.cha3 = msg_exp12_strB_cha3[0];
    msg.exp12.strB.cha4 = msg_exp12_strB_cha4[0];
    msg.exp12.strB.cha5 = msg_exp12_strB_cha5[0];
    msg.exp12.strB.cha6 = msg_exp12_strB_cha6[0];

    msg.exp13.typeF     = msg_exp13_typeF[0];
    msg.exp13.operF     = msg_exp13_operF[0];
    msg.exp13.strF.cha1 = msg_exp13_strF_cha1[0];
    msg.exp13.strF.cha2 = msg_exp13_strF_cha2[0];
    msg.exp13.strF.cha3 = msg_exp13_strF_cha3[0];
    msg.exp13.strF.cha4 = msg_exp13_strF_cha4[0];
    msg.exp13.strF.cha5 = msg_exp13_strF_cha5[0];
    msg.exp13.strF.cha6 = msg_exp13_strF_cha6[0];
    msg.exp13.cmd       = msg_exp13_cmd[0];
    msg.exp13.typeB     = msg_exp13_typeB[0];
    msg.exp13.operB     = msg_exp13_operB[0];
    msg.exp13.strB.cha1 = msg_exp13_strB_cha1[0];
    msg.exp13.strB.cha2 = msg_exp13_strB_cha2[0];
    msg.exp13.strB.cha3 = msg_exp13_strB_cha3[0];
    msg.exp13.strB.cha4 = msg_exp13_strB_cha4[0];
    msg.exp13.strB.cha5 = msg_exp13_strB_cha5[0];
    msg.exp13.strB.cha6 = msg_exp13_strB_cha6[0];

    msg.exp14.typeF     = msg_exp14_typeF[0];
    msg.exp14.operF     = msg_exp14_operF[0];
    msg.exp14.strF.cha1 = msg_exp14_strF_cha1[0];
    msg.exp14.strF.cha2 = msg_exp14_strF_cha2[0];
    msg.exp14.strF.cha3 = msg_exp14_strF_cha3[0];
    msg.exp14.strF.cha4 = msg_exp14_strF_cha4[0];
    msg.exp14.strF.cha5 = msg_exp14_strF_cha5[0];
    msg.exp14.strF.cha6 = msg_exp14_strF_cha6[0];
    msg.exp14.cmd       = msg_exp14_cmd[0];
    msg.exp14.typeB     = msg_exp14_typeB[0];
    msg.exp14.operB     = msg_exp14_operB[0];
    msg.exp14.strB.cha1 = msg_exp14_strB_cha1[0];
    msg.exp14.strB.cha2 = msg_exp14_strB_cha2[0];
    msg.exp14.strB.cha3 = msg_exp14_strB_cha3[0];
    msg.exp14.strB.cha4 = msg_exp14_strB_cha4[0];
    msg.exp14.strB.cha5 = msg_exp14_strB_cha5[0];
    msg.exp14.strB.cha6 = msg_exp14_strB_cha6[0];

    msg.exp15.typeF     = msg_exp15_typeF[0];
    msg.exp15.operF     = msg_exp15_operF[0];
    msg.exp15.strF.cha1 = msg_exp15_strF_cha1[0];
    msg.exp15.strF.cha2 = msg_exp15_strF_cha2[0];
    msg.exp15.strF.cha3 = msg_exp15_strF_cha3[0];
    msg.exp15.strF.cha4 = msg_exp15_strF_cha4[0];
    msg.exp15.strF.cha5 = msg_exp15_strF_cha5[0];
    msg.exp15.strF.cha6 = msg_exp15_strF_cha6[0];
    msg.exp15.cmd       = msg_exp15_cmd[0];
    msg.exp15.typeB     = msg_exp15_typeB[0];
    msg.exp15.operB     = msg_exp15_operB[0];
    msg.exp15.strB.cha1 = msg_exp15_strB_cha1[0];
    msg.exp15.strB.cha2 = msg_exp15_strB_cha2[0];
    msg.exp15.strB.cha3 = msg_exp15_strB_cha3[0];
    msg.exp15.strB.cha4 = msg_exp15_strB_cha4[0];
    msg.exp15.strB.cha5 = msg_exp15_strB_cha5[0];
    msg.exp15.strB.cha6 = msg_exp15_strB_cha6[0];

    msg.exp16.typeF     = msg_exp16_typeF[0];
    msg.exp16.operF     = msg_exp16_operF[0];
    msg.exp16.strF.cha1 = msg_exp16_strF_cha1[0];
    msg.exp16.strF.cha2 = msg_exp16_strF_cha2[0];
    msg.exp16.strF.cha3 = msg_exp16_strF_cha3[0];
    msg.exp16.strF.cha4 = msg_exp16_strF_cha4[0];
    msg.exp16.strF.cha5 = msg_exp16_strF_cha5[0];
    msg.exp16.strF.cha6 = msg_exp16_strF_cha6[0];
    msg.exp16.cmd       = msg_exp16_cmd[0];
    msg.exp16.typeB     = msg_exp16_typeB[0];
    msg.exp16.operB     = msg_exp16_operB[0];
    msg.exp16.strB.cha1 = msg_exp16_strB_cha1[0];
    msg.exp16.strB.cha2 = msg_exp16_strB_cha2[0];
    msg.exp16.strB.cha3 = msg_exp16_strB_cha3[0];
    msg.exp16.strB.cha4 = msg_exp16_strB_cha4[0];
    msg.exp16.strB.cha5 = msg_exp16_strB_cha5[0];
    msg.exp16.strB.cha6 = msg_exp16_strB_cha6[0];

    msg.exp17.typeF     = msg_exp17_typeF[0];
    msg.exp17.operF     = msg_exp17_operF[0];
    msg.exp17.strF.cha1 = msg_exp17_strF_cha1[0];
    msg.exp17.strF.cha2 = msg_exp17_strF_cha2[0];
    msg.exp17.strF.cha3 = msg_exp17_strF_cha3[0];
    msg.exp17.strF.cha4 = msg_exp17_strF_cha4[0];
    msg.exp17.strF.cha5 = msg_exp17_strF_cha5[0];
    msg.exp17.strF.cha6 = msg_exp17_strF_cha6[0];
    msg.exp17.cmd       = msg_exp17_cmd[0];
    msg.exp17.typeB     = msg_exp17_typeB[0];
    msg.exp17.operB     = msg_exp17_operB[0];
    msg.exp17.strB.cha1 = msg_exp17_strB_cha1[0];
    msg.exp17.strB.cha2 = msg_exp17_strB_cha2[0];
    msg.exp17.strB.cha3 = msg_exp17_strB_cha3[0];
    msg.exp17.strB.cha4 = msg_exp17_strB_cha4[0];
    msg.exp17.strB.cha5 = msg_exp17_strB_cha5[0];
    msg.exp17.strB.cha6 = msg_exp17_strB_cha6[0];
    return msg;
}
