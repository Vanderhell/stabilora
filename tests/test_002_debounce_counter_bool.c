#include "pc_debounce_counter_bool.h"
#include <stdint.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)

int main(void)
{
    uint32_t threshold, count, stable_bit, sample_bit;
    for (threshold = 1u; threshold <= 32u; ++threshold) {
        for (count = 0u; count < threshold; ++count) {
            for (stable_bit = 0u; stable_bit < 2u; ++stable_bit) {
                for (sample_bit = 0u; sample_bit < 2u; ++sample_bit) {
                    bool stable = stable_bit != 0u;
                    const bool sample = sample_bit != 0u;
                    uint32_t next_count = count;
                    bool next_stable = stable;
                    const bool switches = sample != stable && count == threshold - 1u;
                    CHECK(pc_debounce_counter_bool(sample, threshold,
                                                   &next_count, &next_stable));
                    if (switches) CHECK(next_stable == sample && next_count == 0u);
                    else if (sample == stable) CHECK(next_stable == stable && next_count == 0u);
                    else CHECK(next_stable == stable && next_count == count + 1u);
                }
            }
        }
    }
    {
        uint32_t c = 0u;
        bool s = false;
        CHECK(pc_debounce_counter_bool(true, 1u, &c, &s) && c == 0u && s);
        c = UINT32_MAX - 1u; s = false;
        CHECK(pc_debounce_counter_bool(true, UINT32_MAX, &c, &s) && c == 0u && s);
        c = UINT32_MAX - 2u; s = false;
        CHECK(pc_debounce_counter_bool(true, UINT32_MAX, &c, &s) && c == UINT32_MAX - 1u && !s);
        c = 0u; s = false;
        CHECK(pc_debounce_counter_bool(true, 3u, &c, &s) && c == 1u && !s);
        CHECK(pc_debounce_counter_bool(false, 3u, &c, &s) && c == 0u && !s);
        CHECK(pc_debounce_counter_bool(true, 3u, &c, &s) && c == 1u && !s);
        CHECK(pc_debounce_counter_bool(true, 3u, &c, &s) && c == 2u && !s);
        CHECK(pc_debounce_counter_bool(true, 3u, &c, &s) && c == 0u && s);
        CHECK(pc_debounce_counter_bool(true, 3u, &c, &s) && c == 0u && s);
        CHECK(pc_debounce_counter_bool(false, 3u, &c, &s) && c == 1u && s);
    }
    {
        uint32_t c = UINT32_MAX;
        bool s = true;
        CHECK(!pc_debounce_counter_bool(false, UINT32_MAX, &c, &s));
        CHECK(c == UINT32_MAX && s);
        c = 3u; s = false;
        CHECK(!pc_debounce_counter_bool(true, 0u, &c, &s));
        CHECK(c == 3u && !s);
        CHECK(!pc_debounce_counter_bool(true, 2u, NULL, &s) && !s);
        CHECK(!pc_debounce_counter_bool(true, 2u, &c, NULL) && c == 3u);
    }
    return 0;
}
