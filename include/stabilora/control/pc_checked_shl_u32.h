#ifndef PC_CHECKED_SHL_U32_H
#define PC_CHECKED_SHL_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Exact uint32_t left shift. False for shift >= 32, discarded high bits, or
 * null output; on failure output is unchanged. */
bool pc_checked_shl_u32(uint32_t value, unsigned shift, uint32_t *result);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_checked_shl_u32
#define pc_checked_shl_u32 pc_checked_shl_u32
#endif
#ifndef pc_checked_shl_u32
#define pc_checked_shl_u32 pc_checked_shl_u32
#endif
#ifndef PC_PC_CHECKED_SHL_U32_H
#define PC_PC_CHECKED_SHL_U32_H PC_CHECKED_SHL_U32_H
#endif

