#ifndef STABILORA_CONTROL_HIST_CLIP_LIMIT_U32_H
#define STABILORA_CONTROL_HIST_CLIP_LIMIT_U32_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif



/* Clip each of 256 bins to positive limit and report removed mass. Exact
 * histogram == clipped alias is allowed; partial overlap is unsupported.
 * excess_out must be nonnull and disjoint from both arrays. Invalid inputs
 * return false before modifying any output. */
bool stabilora_hist_clip_limit_u32(const uint32_t histogram[256], uint32_t limit,
                            uint32_t clipped[256], uint64_t *excess_out);

#ifdef __cplusplus
}
#endif

#endif /* STABILORA_CONTROL_HIST_CLIP_LIMIT_U32_H */
