#ifndef STABILORA_CONTROL_CHECKED_SHL_U32_H
#define STABILORA_CONTROL_CHECKED_SHL_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Exact uint32_t left shift. False for shift >= 32, discarded high bits, or
 * null output; on failure output is unchanged. */
bool stabilora_checked_shl_u32(uint32_t value, unsigned shift, uint32_t *result);


#ifdef __cplusplus
}
#endif

#endif /* STABILORA_CONTROL_CHECKED_SHL_U32_H */
