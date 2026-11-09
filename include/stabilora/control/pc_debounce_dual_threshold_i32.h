#ifndef PRIMITIVECORE_DEBOUNCE_DUAL_THRESHOLD_I32_H
#define PRIMITIVECORE_DEBOUNCE_DUAL_THRESHOLD_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Schmitt hysteresis: turn on at upper; turn off at lower. Require lower<upper. */
bool rm_debounce_dual_threshold_i32(int32_t input, int32_t lower,
                                    int32_t upper, bool *active);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_debounce_dual_threshold_i32
#define pc_debounce_dual_threshold_i32 rm_debounce_dual_threshold_i32
#endif
#ifndef pc_debounce_dual_threshold_i32
#define pc_debounce_dual_threshold_i32 rm_debounce_dual_threshold_i32
#endif
#ifndef PC_PRIMITIVECORE_DEBOUNCE_DUAL_THRESHOLD_I32_H
#define PC_PRIMITIVECORE_DEBOUNCE_DUAL_THRESHOLD_I32_H PRIMITIVECORE_DEBOUNCE_DUAL_THRESHOLD_I32_H
#endif

