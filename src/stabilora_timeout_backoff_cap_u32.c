#include <stabilora/control/timeout_backoff_cap_u32.h>
#include <stabilora/control/checked_shl_u32.h>
#include <stddef.h>

bool stabilora_timeout_backoff_cap_u32(uint32_t base, uint32_t attempt,
                                uint32_t cap, uint32_t *delay)
{
    uint32_t scaled;
    uint32_t result;
    if (delay == NULL || base == 0u || cap == 0u) return false;
    if (base >= cap || attempt >= 32u ||
        !stabilora_checked_shl_u32(base,attempt,&scaled) || scaled >= cap) {
        result = cap;
    } else {
        result = scaled;
    }
    *delay = result;
    return true;
}
