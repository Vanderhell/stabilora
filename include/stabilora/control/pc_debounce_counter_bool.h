#ifndef PRIMITIVECORE_DEBOUNCE_COUNTER_BOOL_H
#define PRIMITIVECORE_DEBOUNCE_COUNTER_BOOL_H
#include <stdbool.h>
#include <stdint.h>
/* Require threshold consecutive samples opposite stable before switching. */
bool rm_debounce_counter_bool(bool sample, uint32_t threshold,
                              uint32_t *counter, bool *stable);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_debounce_counter_bool
#define pc_debounce_counter_bool rm_debounce_counter_bool
#endif
#ifndef pc_debounce_counter_bool
#define pc_debounce_counter_bool rm_debounce_counter_bool
#endif
#ifndef PC_PRIMITIVECORE_DEBOUNCE_COUNTER_BOOL_H
#define PC_PRIMITIVECORE_DEBOUNCE_COUNTER_BOOL_H PRIMITIVECORE_DEBOUNCE_COUNTER_BOOL_H
#endif

