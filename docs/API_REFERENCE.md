# Stabilora API reference

The public C99 surface contains six callable functions. Include paths below are rooted at `include/`; CMake consumers receive that root as a public include directory. Each function preserves output parameters when it returns `false` unless stated otherwise.

## `pc_control_output_clamp_i32`

Header/source: `stabilora/control/pc_control_output_clamp_i32.h` / `src/pc_control_output_clamp_i32.c`.

Clamps any `int32_t` value into the inclusive `[lower, upper]` interval. Equal bounds are valid. Returns `false` for a null output pointer or `lower > upper`, leaving `*output` untouched. The input is passed by value, so it may have originated from the same object as `output`.

## `pc_debounce_counter_bool`

Header/source: `stabilora/control/pc_debounce_counter_bool.h` / `src/pc_debounce_counter_bool.c`.

Counts consecutive samples different from `*stable`; a matching sample resets the count. After `threshold` contrary samples, it changes `*stable` to the sample and resets `*counter`. Valid calls require `threshold > 0`, nonnull pointers, and `*counter < threshold` on entry. The counter and stable objects must be distinct, initialized objects. Invalid calls return `false` without modifying either object.

The valid counter range is `0..threshold-1`; `threshold` may be as large as `UINT32_MAX`. The implementation increments only when the current count is below `threshold-1`, so it does not wrap.

## `pc_debounce_dual_threshold_i32`

Header/source: `stabilora/control/pc_debounce_dual_threshold_i32.h` / `src/pc_debounce_dual_threshold_i32.c`.

Schmitt hysteresis over the full `int32_t` domain. When inactive, it activates at `input >= upper`; when active, it deactivates at `input <= lower`; between thresholds it retains state. Requires `lower < upper` and a nonnull, initialized `bool *active`. Invalid calls return `false` and preserve state. The implementation uses comparisons only and does not subtract thresholds.

## `pc_hist_clip_limit_u32`

Header/source: `stabilora/control/pc_hist_clip_limit_u32.h` / `src/pc_hist_clip_limit_u32.c`.

Clips exactly 256 `uint32_t` bins to a positive `limit` and returns the sum removed in `uint64_t`. Maximum possible excess is `256 * (UINT32_MAX - 1)`, which fits in `uint64_t`. Exact `histogram == clipped` aliasing is supported; partial overlap is unsupported. `excess_out` must be nonnull and disjoint from both arrays. Null pointers or `limit == 0` return `false` before modifying outputs.

## `pc_checked_shl_u32`

Header/source: `stabilora/control/pc_checked_shl_u32.h` / `src/pc_checked_shl_u32.c`.

Computes exact unsigned `value << shift`. Returns `false` for a null result pointer, `shift >= 32`, or any shift that would discard nonzero high bits. The result pointer is unchanged on failure. Zero may be shifted by any `shift` in `0..31`.

## `pc_timeout_backoff_cap_u32`

Header/source: `stabilora/control/pc_timeout_backoff_cap_u32.h` / `src/pc_timeout_backoff_cap_u32.c`.

For positive `base` and `cap`, returns `min(base * 2^attempt, cap)`. The operation saturates to `cap` for `attempt >= 32`, a `uint32_t` shift overflow, or a scaled value at/above cap. A zero `base`, zero `cap`, or null output returns `false` and preserves output. No overflowing arithmetic or invalid shift is evaluated.

## C integration

```c
#include <stabilora/control/pc_checked_shl_u32.h>

uint32_t result;
if (pc_checked_shl_u32(3u, 4u, &result)) {
    /* result is 48 */
}
```

Compile the matching `src/pc_*.c` translation unit, or link the CMake `stabilora` static library. The installed API is C99 and has no external runtime dependency.
