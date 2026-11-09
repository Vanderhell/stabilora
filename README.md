# Stabilora

Stabilora is a portable C99 library for bounded control decisions: output
clamping, debounce state transitions, dual-threshold qualification and capped
timeouts.

## Scope

This first extraction contains five public functions from the PrimitiveCore
control family. They are stateless or caller-owned-state operations, require no
heap or operating-system services, and preserve their original `pc_` symbols.
The remaining control records stay in PrimitiveCore until their independent
source evidence is restored.

## Build and test

```sh
cmake -S . -B build -DSTABILORA_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

## Validation status

Host tests are migrated and form the extraction gate. ESP32-S3 validation and
isolated footprint measurements are pending; no hardware result is claimed.

## Name and origin

Stabilora combines *stabilis* (steady) and *aurora* (a controlled transition
from uncertainty to a clear state). It reflects debounce, hysteresis and
bounded-output behavior. The product originates from
`control/feedback_and_limits` in PrimitiveCore.

## License

Apache License 2.0, copyright Vanderhell. See `LICENSE` and `NOTICE`.
