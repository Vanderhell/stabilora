#include "pc_debounce_counter_bool.h"
#include <stddef.h>

bool pc_debounce_counter_bool(bool sample, uint32_t threshold,
                              uint32_t *counter, bool *stable)
{
    uint32_t count;
    bool value;
    if (counter == NULL || stable == NULL || threshold == 0u) return false;
    count = *counter;
    value = *stable;
    if (count >= threshold) return false;
    if (sample == value) {
        count = 0u;
    } else if (count == threshold - 1u) {
        value = sample;
        count = 0u;
    } else {
        ++count;
    }
    *counter = count;
    *stable = value;
    return true;
}
