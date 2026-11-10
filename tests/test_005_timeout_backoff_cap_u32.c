#include "pc_timeout_backoff_cap_u32.h"
#include <stdint.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    uint32_t b,c,a,out;
    CHECK(pc_timeout_backoff_cap_u32(100,0,150,&out)&&out==100);
    CHECK(pc_timeout_backoff_cap_u32(100,1,150,&out)&&out==150);
    CHECK(pc_timeout_backoff_cap_u32(100,99,150,&out)&&out==150);
    CHECK(pc_timeout_backoff_cap_u32(200,0,150,&out)&&out==150);
    CHECK(pc_timeout_backoff_cap_u32(150,0,150,&out)&&out==150);
    CHECK(pc_timeout_backoff_cap_u32(1,31,UINT32_MAX,&out)&&out==UINT32_C(0x80000000));
    CHECK(pc_timeout_backoff_cap_u32(1,32,UINT32_MAX,&out)&&out==UINT32_MAX);
    CHECK(pc_timeout_backoff_cap_u32(1,UINT32_MAX,UINT32_MAX,&out)&&out==UINT32_MAX);
    CHECK(pc_timeout_backoff_cap_u32(UINT32_MAX,0,UINT32_MAX,&out)&&out==UINT32_MAX);
    out=77; CHECK(!pc_timeout_backoff_cap_u32(0,1,10,&out)&&out==77);
    CHECK(!pc_timeout_backoff_cap_u32(1,1,0,&out)&&out==77);
    CHECK(!pc_timeout_backoff_cap_u32(1,1,10,NULL));
    for(b=1;b<=255u;++b) for(c=1;c<=255u;++c) for(a=0;a<=40u;++a) {
        uint64_t value = a < 32u ? ((uint64_t)b << a) : UINT64_MAX;
        uint32_t expected = a >= 32u || value >= c ? c : (uint32_t)value;
        CHECK(pc_timeout_backoff_cap_u32(b,a,c,&out)&&out==expected);
    }
    return 0;
}
