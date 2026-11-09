# Stabilora family guide

## What this family solves

**Control and hysteresis.** Output clamping, debounce, dual-threshold qualification and capped timeout control.

This guide describes the complete public family as an independent embedded-C product. Each primitive remains separately linkable; select only the headers and source units required by the application.

## When to use this family

Use Stabilora when the application needs the operations listed below and requires deterministic behavior, explicit caller-owned memory, and no mandatory operating-system services.

## Family at a glance

```mermaid
flowchart LR
    A[Application input] --> B[Validate representation and bounds]
    B --> C[Select one public primitive]
    C --> D[Check status or output contract]
    D --> E[Use result with documented units]
```

## Primitive map

| Public header | Symbol | Purpose and contract | Validation source |
|---|---|---|---|
| `include/stabilora/control/pc_control_output_clamp_i32.h` | `pc_control_output_clamp_i32` | Clamp value to the inclusive [lower, upper] interval. Invalid bounds or a null output return false and leave *output unchanged. | tests/test_001_control_output_clamp_i32.c |
| `include/stabilora/control/pc_debounce_counter_bool.h` | `pc_debounce_counter_bool` | Require threshold consecutive samples opposite stable before switching. | tests/test_002_debounce_counter_bool.c |
| `include/stabilora/control/pc_debounce_dual_threshold_i32.h` | `pc_debounce_dual_threshold_i32` | Schmitt hysteresis: turn on at upper; turn off at lower. Require lower<upper. | tests/test_003_debounce_dual_threshold_i32.c |
| `include/stabilora/control/pc_hist_clip_limit_u32.h` | `pc_hist_clip_limit_u32` | Cap each of 256 bins at a positive absolute limit and report removed mass. Exact histogram input/output alias is allowed; partial overlap is not. Failure leaves both outputs unchanged. | tests/test_004_hist_clip_limit_u32.c |
| `include/stabilora/control/pc_checked_shl_u32.h` | `pc_checked_shl_u32` | Exact uint32_t left shift. False for shift >= 32, discarded high bits, or null output; on failure output is unchanged. | No enabled test source was found by symbol search. |
| `include/stabilora/control/pc_timeout_backoff_cap_u32.h` | `pc_timeout_backoff_cap_u32` | Return min(base*2^attempt, cap), mapping arithmetic overflow to cap. | tests/test_005_timeout_backoff_cap_u32.c |

## Selection guidance

- Choose the primitive whose width, representation, rounding, saturation, wrapping, and error contract match the application.
- Do not substitute a similarly named function without checking the public header.
- Allocate state and buffers in the caller; respect documented aliasing and output-preservation rules.
- Treat entries marked without a validation source as requiring additional product-level tests before release.

## Integration checklist

1. Include only the required public header.
2. Compile the matching source translation unit or use the product CMake target.
3. Check every boolean/status return before consuming an output.
4. Add application-specific boundary tests for units, widths, invalid inputs, and overflow behavior.
5. Run the documented host tests before target integration.

## Complexity and footprint

The product is split into independent translation units. Exact flash, RAM, stack, and cycle costs depend on the selected functions, compiler, optimization, and MCU; unmeasured values remain explicitly marked PENDING in the testing documentation.

## Validation boundary

The API reference links each public entry to its implementation and available validation source. Hardware status is reported only when reproducible target evidence exists.
