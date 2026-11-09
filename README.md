# Stabilora
![CI](https://github.com/Vanderhell/stabilora/actions/workflows/ci.yml/badge.svg) ![License](https://img.shields.io/badge/license-Apache--2.0-blue.svg) ![Language](https://img.shields.io/badge/language-C99-informational.svg)

![Stabilora banner](docs/banner.svg)

Output clamping, debounce, dual-threshold qualification and capped timeout control.

## Why it exists

Digital inputs and actuator outputs need stable bounded transitions under noisy conditions.

## What is included

- Portable C99-oriented implementation.
- Deterministic integer or fixed-point behavior documented at function level.
- No mandatory heap, threads or operating-system services.
- Separate translation units for selective linking.

## Quick start

```sh
cmake -S . -B build -DSTABILORA_BUILD_TESTS=ON
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

For a minimal integration, include only the required public header and compile the matching source unit. The library does not require the rest of PrimitiveCore.

## Documentation

| Need | Read |
|---|---|
| Choose a primitive | [Family guide](docs/FAMILY_GUIDE.md) |
| Check every function and contract | [API reference](docs/API_REFERENCE.md) |
| Reproduce tests and see validation limits | [Testing report](docs/TESTING.md) |
| Review design and dependencies | [Architecture](docs/ARCHITECTURE.md) |
| See measured or pending performance data | [Performance](docs/PERFORMANCE.md) |

## At a glance

The public surface consists of 6 headers and 6 callable API entries under include/. Implementations are in src/ and tests are in tests/. State, buffers and output ownership are explicit in each header contract.

The CMake test option is STABILORA_BUILD_TESTS. The library has no mandatory third-party dependency. Platform-specific link requirements are documented in CMake and the affected API header.

## Validation status

5/5 MSVC tests and 5/5 GCC strict-warning tests passed.
See docs/TESTING.md for reproducible commands, coverage boundaries and hardware status.

Detailed overflow, rounding, invalid-input, memory-ownership and state rules are defined by the public headers and API reference. Do not infer them from the product name alone.

## License

Apache License 2.0, copyright Vanderhell. See [LICENSE](LICENSE) and [NOTICE](NOTICE).

## Origin

A standalone embedded-C library extracted from the PrimitiveCore product catalog. It is independently buildable and linkable.
