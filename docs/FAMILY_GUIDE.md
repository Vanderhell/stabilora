# Stabilora family guide

Stabilora provides six independent control and signal-conditioning operations: scalar output clamping, boolean debounce, dual-threshold hysteresis, fixed-size histogram clipping, checked unsigned shifts, and capped exponential timeout backoff.

## Integration

- Use headers under `<stabilora/control/>` and link the CMake target `Stabilora::Stabilora`.
- For direct source integration, compile the matching `src/stabilora_<operation>.c`; timeout backoff additionally needs `src/stabilora_checked_shl_u32.c`.
- The public library is C99 and requires only standard fixed-width integer and boolean headers.
- Check status returns before consuming outputs. Caller owns debounce state and histogram buffers.
- Debounce counter/stable objects must be distinct. Histogram exact in-place alias is supported; partial buffer overlap and overlap with `excess_out` are unsupported.

## API map

| Public header | Function | Summary | Direct test |
|---|---|---|---|
| `stabilora/control/control_output_clamp_i32.h` | `stabilora_control_output_clamp_i32` | Clamp `int32_t` to inclusive bounds | `test_001_control_output_clamp_i32.c` |
| `stabilora/control/debounce_counter_bool.h` | `stabilora_debounce_counter_bool` | Require consecutive differing samples | `test_002_debounce_counter_bool.c` |
| `stabilora/control/debounce_dual_threshold_i32.h` | `stabilora_debounce_dual_threshold_i32` | Schmitt hysteresis with inclusive switching thresholds | `test_003_debounce_dual_threshold_i32.c` |
| `stabilora/control/hist_clip_limit_u32.h` | `stabilora_hist_clip_limit_u32` | Clip 256 bins and report excess | `test_004_hist_clip_limit_u32.c` |
| `stabilora/control/checked_shl_u32.h` | `stabilora_checked_shl_u32` | Exact checked `uint32_t` left shift | `test_006_checked_shl_u32.c` |
| `stabilora/control/timeout_backoff_cap_u32.h` | `stabilora_timeout_backoff_cap_u32` | Return capped exponential backoff | `test_005_timeout_backoff_cap_u32.c` |

See [API_REFERENCE.md](API_REFERENCE.md) for contracts, [TESTING.md](TESTING.md) for actual host and historical hardware evidence, and [AUDIT.md](AUDIT.md) for range analysis.
