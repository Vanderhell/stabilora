#ifndef PC_DEBOUNCE_COUNTER_BOOL_H
#define PC_DEBOUNCE_COUNTER_BOOL_H
#include <stdbool.h>
#include <stdint.h>
/* Count consecutive samples differing from stable. Matching samples reset the
 * count; reaching threshold changes stable and resets count. Requires threshold
 * > 0, nonnull distinct initialized counter/stable objects and *counter <
 * threshold on entry. Invalid calls preserve both objects. */
bool pc_debounce_counter_bool(bool sample, uint32_t threshold,
                              uint32_t *counter, bool *stable);
#endif
