#include "pc_hist_clip_limit_u32.h"
#include <stddef.h>

bool pc_hist_clip_limit_u32(const uint32_t histogram[256], uint32_t limit,
                            uint32_t clipped[256], uint64_t *excess_out)
{
    uint64_t excess = 0u;
    size_t i;
    if (histogram == NULL || clipped == NULL || excess_out == NULL || limit == 0u)
        return false;
    for (i = 0u; i < 256u; ++i) {
        uint32_t value = histogram[i];
        if (value > limit) {
            excess += (uint64_t)(value - limit);
            clipped[i] = limit;
        } else {
            clipped[i] = value;
        }
    }
    *excess_out = excess;
    return true;
}
