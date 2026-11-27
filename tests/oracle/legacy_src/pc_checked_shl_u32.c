#include "pc_checked_shl_u32.h"
#include <limits.h>
#include <stddef.h>

bool pc_checked_shl_u32(uint32_t value, unsigned shift, uint32_t *result)
{
    if (result == NULL || shift >= 32u) return false;
    if (value > (UINT32_MAX >> shift)) return false;
    *result = value << shift;
    return true;
}
