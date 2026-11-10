# Stabilora
![CI](https://github.com/Vanderhell/stabilora/actions/workflows/ci.yml/badge.svg) ![License](https://img.shields.io/badge/license-Apache--2.0-blue.svg) ![Language](https://img.shields.io/badge/language-C99-informational.svg)

![Stabilora banner](docs/banner.svg)

Output clamping, debounce, dual-threshold qualification, histogram clipping, checked shifts, and capped timeout control.

## Why it exists

Digital inputs and actuator outputs need stable bounded transitions under noisy conditions.

## What is included

- Six independently linkable C99 functions in separate translation units.
- Deterministic integer behavior and explicit failure/output contracts.
- No mandatory heap, threads, operating-system services, or external libraries.
- A static CMake library and optional host tests.

## Quick start

```sh
cmake -S . -B build -DSTABILORA_BUILD_TESTS=ON -DSTABILORA_STRICT_WARNINGS=ON
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

For selective integration, include `<stabilora/control/pc_name.h>` and compile the matching `src/pc_name.c`. With CMake, link the `stabilora` target; its public include root supports the same canonical header path.

## Documentation

| Need | Read |
|---|---|
| Choose a primitive | [Family guide](docs/FAMILY_GUIDE.md) |
| Check every function and contract | [API reference](docs/API_REFERENCE.md) |
| Review per-API findings | [Audit register](docs/AUDIT.md) |
| Reproduce tests and see validation limits | [Testing report](docs/TESTING.md) |
| Review design and dependencies | [Architecture](docs/ARCHITECTURE.md) |
| See measured or pending performance data | [Performance](docs/PERFORMANCE.md) |

## Validation status

Six of six public APIs have standalone test executables. GCC 16.1 Release strict, Clang-cl 19.1.5 Release strict, MSVC 19.42 Debug and Release, Clang-cl AddressSanitizer, and Clang-cl UndefinedBehaviorSanitizer each passed all six tests. Tests use explicit checks that remain enabled in Release. ESP32-S3 v0.2 runtime checks passed for all six APIs (representative deterministic workload; see [TESTING.md](docs/TESTING.md)). No performance or isolated footprint measurement was made.

## License

Apache License 2.0, copyright Vanderhell. See [LICENSE](LICENSE) and [NOTICE](NOTICE).

## Origin

A standalone embedded-C library extracted from the PrimitiveCore product catalog. It is independently buildable and linkable.
