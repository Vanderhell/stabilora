#include "pc_control_output_clamp_i32.h"
#include <stddef.h>
bool rm_control_output_clamp_i32(int32_t value, int32_t lower, int32_t upper, int32_t *output)
{
    int32_t result;
    if (output == NULL || lower > upper) return false;
    result = value < lower ? lower : (value > upper ? upper : value);
    *output = result;
    return true;
}
