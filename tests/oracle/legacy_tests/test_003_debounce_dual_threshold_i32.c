#include "pc_debounce_dual_threshold_i32.h"
#include <stddef.h>
#include <stdint.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void) {
    bool on=false;
    int32_t lo,hi,x;
    int initial;
    CHECK(pc_debounce_dual_threshold_i32(9,0,10,&on) && !on);
    CHECK(pc_debounce_dual_threshold_i32(10,0,10,&on) && on);
    CHECK(pc_debounce_dual_threshold_i32(5,0,10,&on) && on);
    CHECK(pc_debounce_dual_threshold_i32(0,0,10,&on) && !on);
    CHECK(pc_debounce_dual_threshold_i32(INT32_MAX,INT32_MIN,INT32_MAX,&on) && on);
    CHECK(pc_debounce_dual_threshold_i32(INT32_MIN,INT32_MIN,INT32_MAX,&on) && !on);
    CHECK(pc_debounce_dual_threshold_i32(0,0,1,&on) && !on);
    on = false; CHECK(!pc_debounce_dual_threshold_i32(0,1,1,&on) && !on);
    on = true; CHECK(!pc_debounce_dual_threshold_i32(0,2,1,&on) && on);
    CHECK(!pc_debounce_dual_threshold_i32(0,0,1,NULL));
    for (lo=-8;lo<=7;++lo) for (hi=lo+1;hi<=8;++hi)
      for (x=-9;x<=9;++x) for (initial=0;initial<=1;++initial) {
        bool state=initial != 0, expected=state;
        if (state && x<=lo) expected=false;
        if (!state && x>=hi) expected=true;
        CHECK(pc_debounce_dual_threshold_i32(x,lo,hi,&state));
        CHECK(state==expected);
      }
    return 0;
}
