#ifndef PRIMITIVECORE_TIMEOUT_BACKOFF_CAP_U32_H
#define PRIMITIVECORE_TIMEOUT_BACKOFF_CAP_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Return min(base*2^attempt, cap), mapping arithmetic overflow to cap. */
bool rm_timeout_backoff_cap_u32(uint32_t base, uint32_t attempt,
                                uint32_t cap, uint32_t *delay);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_timeout_backoff_cap_u32
#define pc_timeout_backoff_cap_u32 rm_timeout_backoff_cap_u32
#endif
#ifndef pc_timeout_backoff_cap_u32
#define pc_timeout_backoff_cap_u32 rm_timeout_backoff_cap_u32
#endif
#ifndef PC_PRIMITIVECORE_TIMEOUT_BACKOFF_CAP_U32_H
#define PC_PRIMITIVECORE_TIMEOUT_BACKOFF_CAP_U32_H PRIMITIVECORE_TIMEOUT_BACKOFF_CAP_U32_H
#endif

