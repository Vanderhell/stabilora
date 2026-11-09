#include "pc_hist_clip_limit_u32.h"
#include <assert.h>
#include <stdint.h>
#include <stddef.h>

static uint32_t h[256], out[256];
static uint32_t state = UINT32_C(0x4445A11C);

static uint32_t next_u32(void)
{
    state ^= state << 13; state ^= state >> 17; state ^= state << 5;
    return state;
}

static void verify(const uint32_t *input, uint32_t limit)
{
    uint64_t excess = UINT64_MAX, sum_in = 0u, sum_out = 0u;
    assert(pc_hist_clip_limit_u32(input, limit, out, &excess));
    for (size_t i = 0u; i < 256u; ++i) {
        assert(out[i] == (input[i] > limit ? limit : input[i]));
        sum_in += input[i]; sum_out += out[i];
    }
    assert(sum_in == sum_out + excess);
}

int main(void)
{
    uint64_t excess = UINT64_C(0x1122334455667788);
    for (size_t i = 0u; i < 256u; ++i) h[i] = UINT32_MAX;
    for (size_t i = 0u; i < 256u; ++i) out[i] = 0xA5A5A5A5u;
    assert(!pc_hist_clip_limit_u32(h, 0u, out, &excess));
    assert(excess == UINT64_C(0x1122334455667788));
    for (size_t i = 0u; i < 256u; ++i) assert(out[i] == 0xA5A5A5A5u);
    assert(!pc_hist_clip_limit_u32(NULL, 1u, out, &excess));
    assert(!pc_hist_clip_limit_u32(h, 1u, NULL, &excess));
    assert(!pc_hist_clip_limit_u32(h, 1u, out, NULL));

    verify(h, UINT32_MAX);
    verify(h, UINT32_MAX - 1u);
    verify(h, 1u);
    assert(pc_hist_clip_limit_u32(h, UINT32_MAX - 1u, h, &excess));
    assert(excess == 256u);
    for (size_t i = 0u; i < 256u; ++i) assert(h[i] == UINT32_MAX - 1u);

    for (size_t k = 0u; k < 20000u; ++k) {
        uint32_t limit = next_u32() | 1u;
        for (size_t i = 0u; i < 256u; ++i) h[i] = next_u32();
        verify(h, limit);
    }
    for (size_t i = 0u; i < 256u; ++i) h[i] = 0u;
    verify(h, 1u);
    return 0;
}
