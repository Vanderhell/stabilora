# Stabilora

Stabilora is a portable C99 library for bounded control decisions: output
clamping, debounce state transitions, dual-threshold qualification and capped
timeouts.

## Scope

The package contains five public functions from the control domain
control family. They are stateless or caller-owned-state operations, require no
heap or operating-system services, and preserve their original `pc_` symbols.
Other control functions are outside this package boundary.

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
bounded control, feedback and limits.

## License

Apache License 2.0, copyright Vanderhell. See `LICENSE` and `NOTICE`.
