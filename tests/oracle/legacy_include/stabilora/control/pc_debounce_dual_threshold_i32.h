/* Schmitt hysteresis: activate at upper; deactivate at lower. Requires lower < upper. */
#ifndef PC_DEBOUNCE_DUAL_THRESHOLD_I32_H
#define PC_DEBOUNCE_DUAL_THRESHOLD_I32_H
#include <stdbool.h>
#include <stdint.h>
/* A nonnull initialized active pointer is required. Invalid bounds return false
 * and preserve *active. Comparisons cover the complete int32_t domain. */
bool pc_debounce_dual_threshold_i32(int32_t input, int32_t lower,
                                    int32_t upper, bool *active);
#endif
