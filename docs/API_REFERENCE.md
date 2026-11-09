# Stabilora API reference

Complete public-header inventory generated from the current source tree. Headers remain authoritative.

## include/stabilora/control/pc_control_output_clamp_i32.h

Public API: pc_control_output_clamp_i32

Contract: Clamp value to the inclusive [lower, upper] interval. Invalid bounds or a null output return false and leave *output unchanged.

Header path: include/stabilora/control/pc_control_output_clamp_i32.h

## include/stabilora/control/pc_debounce_counter_bool.h

Public API: pc_debounce_counter_bool

Contract: Require threshold consecutive samples opposite stable before switching.

Header path: include/stabilora/control/pc_debounce_counter_bool.h

## include/stabilora/control/pc_debounce_dual_threshold_i32.h

Public API: pc_debounce_dual_threshold_i32

Contract: Schmitt hysteresis: turn on at upper; turn off at lower. Require lower<upper.

Header path: include/stabilora/control/pc_debounce_dual_threshold_i32.h

## include/stabilora/control/pc_hist_clip_limit_u32.h

Public API: pc_hist_clip_limit_u32

Contract: Cap each of 256 bins at a positive absolute limit and report removed mass. Exact histogram input/output alias is allowed; partial overlap is not. Failure leaves both outputs unchanged.

Header path: include/stabilora/control/pc_hist_clip_limit_u32.h

## include/stabilora/control/pc_checked_shl_u32.h

Public API: pc_checked_shl_u32

Contract: Exact uint32_t left shift. False for shift >= 32, discarded high bits, or null output; on failure output is unchanged.

Header path: include/stabilora/control/pc_checked_shl_u32.h

## include/stabilora/control/pc_timeout_backoff_cap_u32.h

Public API: pc_timeout_backoff_cap_u32

Contract: Return min(base*2^attempt, cap), mapping arithmetic overflow to cap.

Header path: include/stabilora/control/pc_timeout_backoff_cap_u32.h
