#ifndef STABILORA_CONTROL_DEBOUNCE_DUAL_THRESHOLD_I32_H
#define STABILORA_CONTROL_DEBOUNCE_DUAL_THRESHOLD_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Schmitt hysteresis: activate at upper; deactivate at lower. Requires lower < upper. */
/* A nonnull initialized active pointer is required. Invalid bounds return false
 * and preserve *active. Comparisons cover the complete int32_t domain. */
bool stabilora_debounce_dual_threshold_i32(int32_t input, int32_t lower,
                                    int32_t upper, bool *active);

#ifdef __cplusplus
}
#endif

#endif /* STABILORA_CONTROL_DEBOUNCE_DUAL_THRESHOLD_I32_H */
