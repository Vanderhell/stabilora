# Audit register — Stabilora v0.1.0

Audit scope: all six public headers and implementations, migrated tests, CMake, CI, release documentation, and license metadata. Source audit covers full representable domains by range reasoning plus boundary and deterministic tests; it is not a formal proof for all possible call histories.

| API | Result | Confirmed defect | Validation focus |
|---|---|---|---|
| `pc_control_output_clamp_i32` | OK | None | `INT32_MIN/MAX`, reversed/equal bounds, null output, one million deterministic differential intervals; unchanged output on failure |
| `pc_debounce_counter_bool` | OK | None | Transition/noise sequences, repeated samples, threshold 1 and `UINT32_MAX`, valid/invalid counter invariant, zero threshold, null pointers, failure preservation |
| `pc_debounce_dual_threshold_i32` | OK | None | Exact low/high equality, hysteresis retention and switching, invalid/equal/reversed limits, `INT32_MIN/MAX`, null output and failure preservation |
| `pc_hist_clip_limit_u32` | OK | None | 256 maximum bins, exact in-place alias, disjoint output contract, maximum excess, invalid pointers/zero limit, unchanged outputs on failure, 20,000 seeded histograms |
| `pc_checked_shl_u32` | OK | Missing standalone test was fixed by adding test 006; production code is correct | Shifts 0–31 and 32, `UINT_MAX`, null output, zero, high-bit boundaries, overflow and 100,000 seeded differential cases |
| `pc_timeout_backoff_cap_u32` | OK | None | Attempts 0–40, 31/32/`UINT32_MAX`, saturation, exact cap equality, zero arguments, null output and exhaustive small-domain comparison |

## Range and safety conclusions

- Clamp and hysteresis contain no arithmetic that can overflow. Hysteresis uses comparisons, so extreme signed endpoints are safe.
- Debounce rejects invalid state `counter >= threshold`. At maximum threshold it can increment at most from `UINT32_MAX-2` to `UINT32_MAX-1`, and then the next contrary sample changes state and resets the counter.
- Histogram excess is bounded by `256 * (UINT32_MAX - 1) < 2^40`; accumulation is in `uint64_t`. Exact input/output alias is safe because each source bin is read before that bin is written. Partial overlap is unsupported. `excess_out` must be disjoint from both arrays.
- Checked shift validates the shift width before shifting and verifies that no high bits are discarded.
- Backoff short-circuits attempts at or above 32 and checked-shift overflow to `cap`, which matches the capped mathematical result for positive `base` and `cap`.
- The APIs accept values by value or caller-owned typed pointers. Pointer arguments must designate valid, correctly aligned objects for the documented extent; debounce state objects and histogram excess output must not overlap contrary to the API contract.

No production algorithm defect was confirmed; no algorithm changes were made. Test expectations now remain active in Debug and Release because the suite uses an explicit `CHECK` macro instead of `assert`. A documentation attribution error in `NOTICE` was corrected from Certivox to Stabilora.

## Build and release checks

See [TESTING.md](TESTING.md) for exact compiler versions, commands and executed results. C99 remains the public language contract. Representative target validation passed for all six APIs on an ESP32-S3 v0.2 at 240 MHz; see [TESTING.md](TESTING.md). Performance and isolated footprint remain unmeasured.
