#ifndef STABILORA_CONTROL_TIMEOUT_BACKOFF_CAP_U32_H
#define STABILORA_CONTROL_TIMEOUT_BACKOFF_CAP_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Return min(base*2^attempt, cap), mapping arithmetic overflow to cap. */
bool stabilora_timeout_backoff_cap_u32(uint32_t base, uint32_t attempt,
                                uint32_t cap, uint32_t *delay);


#ifdef __cplusplus
}
#endif

#endif /* STABILORA_CONTROL_TIMEOUT_BACKOFF_CAP_U32_H */
