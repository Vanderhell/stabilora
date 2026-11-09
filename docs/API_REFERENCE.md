# Stabilora API reference

This reference explains every public header in the Stabilora product. It is generated from the current headers and test sources; the header remains authoritative when a detail conflicts.

## Reading the entries
Each entry states the public symbol, implementation unit, contract, edge/failure behavior and a call extracted from the validating test source. The examples are evidence-oriented; adapt buffer ownership and numeric units to the application.

## include/stabilora/control/pc_control_output_clamp_i32.h

**Public symbol:** pc_control_output_clamp_i32

**Implementation unit:** src/pc_control_output_clamp_i32.c

**Purpose and contract:** Clamp value to the inclusive [lower, upper] interval. Invalid bounds or a null output return false and leave *output unchanged.

**Validation source:** tests/test_001_control_output_clamp_i32.c

**Test-derived call:**
```c
pc_control_output_clamp_i32(INT32_MIN, -10, 10, &out) && out == -10);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/stabilora/control/pc_debounce_counter_bool.h

**Public symbol:** pc_debounce_counter_bool

**Implementation unit:** src/pc_debounce_counter_bool.c

**Purpose and contract:** Require threshold consecutive samples opposite stable before switching.

**Validation source:** tests/test_002_debounce_counter_bool.c

**Test-derived call:**
```c
pc_debounce_counter_bool(x,t,&nc,&ns\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/stabilora/control/pc_debounce_dual_threshold_i32.h

**Public symbol:** pc_debounce_dual_threshold_i32

**Implementation unit:** src/pc_debounce_dual_threshold_i32.c

**Purpose and contract:** Schmitt hysteresis: turn on at upper; turn off at lower. Require lower<upper.

**Validation source:** tests/test_003_debounce_dual_threshold_i32.c

**Test-derived call:**
```c
pc_debounce_dual_threshold_i32(9,0,10,&on) && !on);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/stabilora/control/pc_hist_clip_limit_u32.h

**Public symbol:** pc_hist_clip_limit_u32

**Implementation unit:** src/pc_hist_clip_limit_u32.c

**Purpose and contract:** Cap each of 256 bins at a positive absolute limit and report removed mass. Exact histogram input/output alias is allowed; partial overlap is not. Failure leaves both outputs unchanged.

**Validation source:** tests/test_004_hist_clip_limit_u32.c

**Test-derived call:**
```c
pc_hist_clip_limit_u32(input, limit, out, &excess\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/stabilora/control/pc_checked_shl_u32.h

**Public symbol:** pc_checked_shl_u32

**Implementation unit:** src/pc_checked_shl_u32.c

**Purpose and contract:** Exact uint32_t left shift. False for shift >= 32, discarded high bits, or null output; on failure output is unchanged.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/stabilora/control/pc_timeout_backoff_cap_u32.h

**Public symbol:** pc_timeout_backoff_cap_u32

**Implementation unit:** src/pc_timeout_backoff_cap_u32.c

**Purpose and contract:** Return min(base*2^attempt, cap), mapping arithmetic overflow to cap.

**Validation source:** tests/test_005_timeout_backoff_cap_u32.c

**Test-derived call:**
```c
pc_timeout_backoff_cap_u32(100,0,150,&out)&&out==100);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

