# Stabilora family guide

Stabilora provides output clamping, boolean debounce, dual-threshold hysteresis, histogram clipping, checked unsigned shifts, and capped timeout backoff for embedded C applications.

## Integration

- Include `<stabilora/control/pc_name.h>` and compile the matching `src/pc_name.c`, or link the `stabilora` CMake static library.
- The library and headers require C99 and fixed-width integer types.
- Check every boolean return before using output values; outputs are preserved on documented failures.
- Allocate and initialize caller-owned state and 256-bin buffers. Debounce's counter/stable objects and histogram's excess output must not overlap.

## API map

| Header | Function | Summary | Test |
|---|---|---|---|
| `pc_control_output_clamp_i32.h` | `pc_control_output_clamp_i32` | Clamp `int32_t` to inclusive bounds | `test_001` |
| `pc_debounce_counter_bool.h` | `pc_debounce_counter_bool` | Require consecutive differing samples | `test_002` |
| `pc_debounce_dual_threshold_i32.h` | `pc_debounce_dual_threshold_i32` | Schmitt hysteresis with inclusive switching thresholds | `test_003` |
| `pc_hist_clip_limit_u32.h` | `pc_hist_clip_limit_u32` | Clip 256 bins and report excess | `test_004` |
| `pc_timeout_backoff_cap_u32.h` | `pc_timeout_backoff_cap_u32` | Return capped exponential backoff | `test_005` |
| `pc_checked_shl_u32.h` | `pc_checked_shl_u32` | Exact checked `uint32_t` left shift | `test_006` |

See [API_REFERENCE.md](API_REFERENCE.md) for exact limits and failure semantics, [TESTING.md](TESTING.md) for host and ESP32-S3 validation evidence, and [AUDIT.md](AUDIT.md) for the per-API audit register.
