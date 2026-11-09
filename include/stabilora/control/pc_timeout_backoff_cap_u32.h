#ifndef PC_TIMEOUT_BACKOFF_CAP_U32_H
#define PC_TIMEOUT_BACKOFF_CAP_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Return min(base*2^attempt, cap), mapping arithmetic overflow to cap. */
bool pc_timeout_backoff_cap_u32(uint32_t base, uint32_t attempt,
                                uint32_t cap, uint32_t *delay);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_timeout_backoff_cap_u32
#define pc_timeout_backoff_cap_u32 pc_timeout_backoff_cap_u32
#endif
#ifndef pc_timeout_backoff_cap_u32
#define pc_timeout_backoff_cap_u32 pc_timeout_backoff_cap_u32
#endif
#ifndef PC_PC_TIMEOUT_BACKOFF_CAP_U32_H
#define PC_PC_TIMEOUT_BACKOFF_CAP_U32_H PC_TIMEOUT_BACKOFF_CAP_U32_H
#endif

