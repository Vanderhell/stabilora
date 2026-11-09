#ifndef PC_DEBOUNCE_DUAL_THRESHOLD_I32_H
#define PC_DEBOUNCE_DUAL_THRESHOLD_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Schmitt hysteresis: turn on at upper; turn off at lower. Require lower<upper. */
bool pc_debounce_dual_threshold_i32(int32_t input, int32_t lower,
                                    int32_t upper, bool *active);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_debounce_dual_threshold_i32
#define pc_debounce_dual_threshold_i32 pc_debounce_dual_threshold_i32
#endif
#ifndef pc_debounce_dual_threshold_i32
#define pc_debounce_dual_threshold_i32 pc_debounce_dual_threshold_i32
#endif
#ifndef PC_PC_DEBOUNCE_DUAL_THRESHOLD_I32_H
#define PC_PC_DEBOUNCE_DUAL_THRESHOLD_I32_H PC_DEBOUNCE_DUAL_THRESHOLD_I32_H
#endif

