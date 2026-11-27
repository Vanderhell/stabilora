#ifndef STABILORA_CONTROL_CONTROL_OUTPUT_CLAMP_I32_H
#define STABILORA_CONTROL_CONTROL_OUTPUT_CLAMP_I32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Clamp value to the inclusive [lower, upper] interval. Invalid bounds or a
 * null output return false and leave *output unchanged. */
bool stabilora_control_output_clamp_i32(int32_t value, int32_t lower, int32_t upper, int32_t *output);


#ifdef __cplusplus
}
#endif

#endif /* STABILORA_CONTROL_CONTROL_OUTPUT_CLAMP_I32_H */
