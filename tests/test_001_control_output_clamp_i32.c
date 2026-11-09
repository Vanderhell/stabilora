#include "pc_control_output_clamp_i32.h"
#include <limits.h>
#include <stddef.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    int32_t out=123;
    CHECK(pc_control_output_clamp_i32(INT32_MIN, -10, 10, &out) && out == -10);
    CHECK(pc_control_output_clamp_i32(INT32_MAX, -10, 10, &out) && out == 10);
    CHECK(pc_control_output_clamp_i32(0, -10, 10, &out) && out == 0);
    CHECK(pc_control_output_clamp_i32(5, 5, 5, &out) && out == 5);
    out=123; CHECK(!pc_control_output_clamp_i32(0, 2, 1, &out) && out == 123);
    CHECK(!pc_control_output_clamp_i32(0, 0, 1, NULL));
    { uint32_t seed=375u; uint32_t i;
      for(i=0;i<1000000u;++i){int32_t x,lo,hi,expected; seed=seed*1664525u+1013904223u; x=(int32_t)seed; seed=seed*1664525u+1013904223u; lo=(int32_t)seed; seed=seed*1664525u+1013904223u; hi=(int32_t)seed; if(lo>hi){int32_t t=lo;lo=hi;hi=t;} expected=x<lo?lo:(x>hi?hi:x); CHECK(pc_control_output_clamp_i32(x,lo,hi,&out) && out==expected); }
    }
    return 0;
}
