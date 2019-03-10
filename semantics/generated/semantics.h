#ifndef _SEMANTICS
#define _SEMANTICS

#include <stdlib.h>

extern int USER_val[2];

extern _Bool USER_out_req[2];
extern int USER_median[2];
extern int USER_fuzz[2];
extern _Bool historically_0_holds[2];
extern int aeval_tmp_rand_int_1[2];
extern int USER_st[2];
extern _Bool USER_med_req[2];
extern _Bool historically_0_signal[2];
extern int aeval_tmp_rand_int_0[2];
extern _Bool USER_stx_req[2];

extern void skolem_0();

extern void skolem_1();

extern void moveHistory();

extern void updateFunction();

extern int generateRandomValue(_Bool lflag, _Bool uflag, int lbound, int ubound);

#endif
