#ifndef PC_DEBOUNCE_COUNTER_BOOL_H
#define PC_DEBOUNCE_COUNTER_BOOL_H
#include <stdbool.h>
#include <stdint.h>
/* Require threshold consecutive samples opposite stable before switching. */
bool pc_debounce_counter_bool(bool sample, uint32_t threshold,
                              uint32_t *counter, bool *stable);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_debounce_counter_bool
#define pc_debounce_counter_bool pc_debounce_counter_bool
#endif
#ifndef pc_debounce_counter_bool
#define pc_debounce_counter_bool pc_debounce_counter_bool
#endif
#ifndef PC_PC_DEBOUNCE_COUNTER_BOOL_H
#define PC_PC_DEBOUNCE_COUNTER_BOOL_H PC_DEBOUNCE_COUNTER_BOOL_H
#endif

