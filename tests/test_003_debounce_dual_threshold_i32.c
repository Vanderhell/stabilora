#include "pc_debounce_dual_threshold_i32.h"
#include <assert.h>
#include <stdint.h>
int main(void) {
    bool on=false;
    int lo,hi,x,initial;
    assert(pc_debounce_dual_threshold_i32(9,0,10,&on) && !on);
    assert(pc_debounce_dual_threshold_i32(10,0,10,&on) && on);
    assert(pc_debounce_dual_threshold_i32(5,0,10,&on) && on);
    assert(pc_debounce_dual_threshold_i32(0,0,10,&on) && !on);
    assert(pc_debounce_dual_threshold_i32(INT32_MAX,INT32_MIN,INT32_MAX,&on) && on);
    assert(pc_debounce_dual_threshold_i32(INT32_MIN,INT32_MIN,INT32_MAX,&on) && !on);
    assert(pc_debounce_dual_threshold_i32(0,0,1,&on) && !on);
    assert(!pc_debounce_dual_threshold_i32(0,1,1,&on) && !on);
    assert(!pc_debounce_dual_threshold_i32(0,2,1,&on) && !on);
    assert(!pc_debounce_dual_threshold_i32(0,0,1,NULL));
    for (lo=-8;lo<=7;++lo) for (hi=lo+1;hi<=8;++hi)
      for (x=-9;x<=9;++x) for (initial=0;initial<=1;++initial) {
        bool state=initial, expected=initial;
        if (initial && x<=lo) expected=false;
        if (!initial && x>=hi) expected=true;
        assert(pc_debounce_dual_threshold_i32(x,lo,hi,&state));
        assert(state==expected);
      }
    return 0;
}
