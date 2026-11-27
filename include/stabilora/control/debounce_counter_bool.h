#ifndef STABILORA_CONTROL_DEBOUNCE_COUNTER_BOOL_H
#define STABILORA_CONTROL_DEBOUNCE_COUNTER_BOOL_H
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Count consecutive samples differing from stable. Matching samples reset the
 * count; reaching threshold changes stable and resets count. Requires threshold
 * > 0, nonnull distinct initialized counter/stable objects and *counter <
 * threshold on entry. Invalid calls preserve both objects. */
bool stabilora_debounce_counter_bool(bool sample, uint32_t threshold,
                              uint32_t *counter, bool *stable);

#ifdef __cplusplus
}
#endif

#endif /* STABILORA_CONTROL_DEBOUNCE_COUNTER_BOOL_H */
