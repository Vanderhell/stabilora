# Stabilora API reference

The public C99 surface contains six callable functions. Include paths are rooted at `include/`. Each output contract below follows the public header and implementation. Calls do not allocate memory or retain hidden state.

## `stabilora_control_output_clamp_i32`

Header/source: `stabilora/control/control_output_clamp_i32.h` / `src/stabilora_control_output_clamp_i32.c`.

Clamps an `int32_t` value into inclusive `[lower, upper]`. Equal bounds are valid. Returns `false` for null output or `lower > upper`, leaving output untouched. Input is passed by value, so it may have originated from the output object.

## `stabilora_debounce_counter_bool`

Header/source: `stabilora/control/debounce_counter_bool.h` / `src/stabilora_debounce_counter_bool.c`.

Counts consecutive samples differing from `*stable`; a matching sample resets the count. After `threshold` contrary samples, stable changes to the sample and the counter resets. Requires `threshold > 0`, nonnull distinct initialized counter/stable pointers, and `*counter < threshold` on entry. Invalid calls return false without modifying either object. Valid counter values are `0..threshold-1`, including thresholds up to `UINT32_MAX`; the implementation avoids incrementing past the threshold. Execution and additional storage are O(1); the caller owns both state objects.

## `stabilora_debounce_dual_threshold_i32`

Header/source: `stabilora/control/debounce_dual_threshold_i32.h` / `src/stabilora_debounce_dual_threshold_i32.c`.

Schmitt hysteresis across the full `int32_t` domain. Inactive state activates at `input >= upper`; active state deactivates at `input <= lower`; intermediate values retain state. Requires `lower < upper` and a nonnull initialized state pointer. Invalid calls preserve state. The implementation compares values directly and does not subtract thresholds. Execution and additional storage are O(1); the caller owns the active-state object.

## `stabilora_hist_clip_limit_u32`

Header/source: `stabilora/control/hist_clip_limit_u32.h` / `src/stabilora_hist_clip_limit_u32.c`.

Clips exactly 256 `uint32_t` bins to positive `limit` and reports removed sum in `uint64_t`. Maximum excess `256 * (UINT32_MAX - 1)` fits `uint64_t`. Exact `histogram == clipped` aliasing is supported; partial overlap is unsupported. `excess_out` must be nonnull and disjoint from both arrays. Null pointers or zero limit fail before modifying outputs. Execution is O(256) with O(1) additional storage; the caller supplies both 256-element arrays and the excess output.

## `stabilora_checked_shl_u32`

Header/source: `stabilora/control/checked_shl_u32.h` / `src/stabilora_checked_shl_u32.c`.

Computes exact unsigned `value << shift`. Returns false for null result, `shift >= 32`, or a shift that discards nonzero high bits; output is unchanged on failure. Zero can be shifted by any count 0..31. Execution and additional storage are O(1).

## `stabilora_timeout_backoff_cap_u32`

Header/source: `stabilora/control/timeout_backoff_cap_u32.h` / `src/stabilora_timeout_backoff_cap_u32.c`.

For positive `base` and `cap`, returns `min(base * 2^attempt, cap)`. Saturates to cap for `attempt >= 32`, shift overflow, or scaled value at/above cap. Zero base/cap or null output returns false without writing output. It calls `stabilora_checked_shl_u32`; direct-source builds must also compile `src/stabilora_checked_shl_u32.c`. Execution and additional storage are O(1).

## C integration

```c
#include <stabilora/control/checked_shl_u32.h>

uint32_t result;
if (stabilora_checked_shl_u32(3u, 4u, &result)) {
    /* result is 48 */
}
```

For CMake use `find_package(Stabilora CONFIG REQUIRED)` and link `Stabilora::Stabilora`. For direct C99 integration, compile the operation's `src/stabilora_*.c` file and any dependency listed above.

## Migration from 0.1.x

Version 0.2.0 changes the source and ABI names; no legacy aliases are exported.

| Previous symbol | Current symbol |
|---|---|
| `pc_control_output_clamp_i32` | `stabilora_control_output_clamp_i32` |
| `pc_debounce_counter_bool` | `stabilora_debounce_counter_bool` |
| `pc_debounce_dual_threshold_i32` | `stabilora_debounce_dual_threshold_i32` |
| `pc_hist_clip_limit_u32` | `stabilora_hist_clip_limit_u32` |
| `pc_checked_shl_u32` | `stabilora_checked_shl_u32` |
| `pc_timeout_backoff_cap_u32` | `stabilora_timeout_backoff_cap_u32` |
