#ifndef PC_HIST_CLIP_LIMIT_U32_H
#define PC_HIST_CLIP_LIMIT_U32_H

#include <stdbool.h>
#include <stdint.h>

/* Cap each of 256 bins at a positive absolute limit and report removed mass.
 * Exact histogram input/output alias is allowed; partial overlap is not.
 * Failure leaves both outputs unchanged. */
bool pc_hist_clip_limit_u32(const uint32_t histogram[256], uint32_t limit,
                            uint32_t clipped[256], uint64_t *excess_out);

#endif
