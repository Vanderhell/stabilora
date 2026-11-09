#include "pc_debounce_dual_threshold_i32.h"
#include <stddef.h>
bool pc_debounce_dual_threshold_i32(int32_t input, int32_t lower,
                                    int32_t upper, bool *active)
{
    bool next;
    if (active == NULL || lower >= upper) return false;
    next = *active;
    if (next) {
        if (input <= lower) next = false;
    } else if (input >= upper) {
        next = true;
    }
    *active = next;
    return true;
}
