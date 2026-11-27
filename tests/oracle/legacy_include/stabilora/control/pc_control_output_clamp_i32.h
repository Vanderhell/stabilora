#ifndef PC_CONTROL_OUTPUT_CLAMP_I32_H
#define PC_CONTROL_OUTPUT_CLAMP_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Clamp value to the inclusive [lower, upper] interval. Invalid bounds or a
 * null output return false and leave *output unchanged. */
bool pc_control_output_clamp_i32(int32_t value, int32_t lower, int32_t upper, int32_t *output);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_control_output_clamp_i32
#define pc_control_output_clamp_i32 pc_control_output_clamp_i32
#endif
#ifndef pc_control_output_clamp_i32
#define pc_control_output_clamp_i32 pc_control_output_clamp_i32
#endif
#ifndef PC_PC_CONTROL_OUTPUT_CLAMP_I32_H
#define PC_PC_CONTROL_OUTPUT_CLAMP_I32_H PC_CONTROL_OUTPUT_CLAMP_I32_H
#endif

