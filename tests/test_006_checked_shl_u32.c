#include <stabilora/control/pc_checked_shl_u32.h>
#include <limits.h>
#include <stdint.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
static uint32_t state = UINT32_C(0x1234ABCD);
static uint32_t next_u32(void)
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}
static bool check_one(uint32_t value, unsigned shift)
{
    uint32_t actual = UINT32_C(0xA5A5A5A5);
    const uint64_t wide = (uint64_t)value << shift;
    const bool expected_ok = shift < 32u && wide <= UINT32_MAX;
    const bool actual_ok = pc_checked_shl_u32(value, shift, &actual);
    return actual_ok == expected_ok &&
           (expected_ok ? (uint64_t)actual == wide : actual == UINT32_C(0xA5A5A5A5));
}
int main(void)
{
    static const uint32_t values[] = {0u,1u,2u,3u,UINT32_C(0x7fffffff),
        UINT32_C(0x80000000),UINT32_C(0x80000001),UINT32_MAX};
    size_t i;
    unsigned shift;
    uint32_t output = 99u;
    CHECK(!pc_checked_shl_u32(1u, 32u, &output) && output == 99u);
    CHECK(!pc_checked_shl_u32(1u, UINT_MAX, &output) && output == 99u);
    CHECK(!pc_checked_shl_u32(1u, 0u, NULL));
    for (i = 0u; i < sizeof values / sizeof values[0]; ++i)
        for (shift = 0u; shift <= 32u; ++shift)
            CHECK(check_one(values[i], shift));
    for (shift = 0u; shift < 32u; ++shift) {
        const uint32_t max_exact = UINT32_MAX >> shift;
        CHECK(check_one(max_exact, shift));
        if (max_exact != UINT32_MAX) CHECK(check_one(max_exact + 1u, shift));
    }
    for (i = 0u; i < 100000u; ++i) {
        const uint32_t value = next_u32();
        shift = next_u32() % 33u;
        CHECK(check_one(value, shift));
    }
    return 0;
}
