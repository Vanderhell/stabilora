# Testing and validation

## Coverage

All six public APIs have enabled direct behavioral tests. Checks use explicit `CHECK` logic and stay active in Release. CTest registers 6 behavioral programs, 6 standalone C public-header translation units, and one aggregate C++ header/link smoke test (13 entries total).

| Test program | API | Main coverage |
|---|---|---|
| `test_control_output_clamp_i32.c` | `stabilora_control_output_clamp_i32` | Signed extremes, equal/reversed bounds, null output, one million independent differential intervals, failure preservation |
| `test_debounce_counter_bool.c` | `stabilora_debounce_counter_bool` | Transitions, repeated samples, thresholds 1–32, `UINT32_MAX`, invalid counter/pointers, failure preservation |
| `test_debounce_dual_threshold_i32.c` | `stabilora_debounce_dual_threshold_i32` | Exact threshold equality, state retention/switch, invalid bounds, `INT32_MIN/MAX`, exhaustive small-state cases |
| `test_hist_clip_limit_u32.c` | `stabilora_hist_clip_limit_u32` | 256 bins, in-place alias, maximum excess, invalid pointers/limit, output preservation, 20,000 seeded histograms |
| `test_checked_shl_u32.c` | `stabilora_checked_shl_u32` | Shifts 0–31 and 32, `UINT_MAX`, null output, high-bit/overflow boundaries, 100,000 seeded reference cases |
| `test_timeout_backoff_cap_u32.c` | `stabilora_timeout_backoff_cap_u32` | Attempts 0–40 and max, cap/saturation, invalid inputs, exhaustive small base/cap pairs |

The CMake strict setting uses `-Wall -Wextra -Wpedantic -Werror` on GCC/Clang and `/W4 /WX` on MSVC. The production library and C tests request C99 with extensions disabled. Individual headers are compiled independently as C99; the aggregate header is also included and linked from C++.

## Current host matrix

| Compiler | Configuration | Result |
|---|---|---|
| GCC 16.1.0 MinGW UCRT | Debug | PASS, 13/13 CTest |
| GCC 16.1.0 MinGW UCRT | Release | PASS, 13/13 CTest |
| ClangCL 19.1.5 (Visual Studio 17 2022) | Debug | PASS, 13/13 CTest |
| ClangCL 19.1.5 (Visual Studio 17 2022) | Release | PASS, 13/13 CTest |
| MSVC 19.42.34444 | Debug | PASS, 13/13 CTest |
| MSVC 19.42.34444 | Release | PASS, 13/13 CTest |
| Clang 22 ASan (Visual Studio developer environment) | PASS, 6/6 direct C behavioral programs; all production C files instrumented |
| ClangCL 19.1.5 UBSan (Release) | PASS, 13/13 CTest |
| GCC ASan | NOT RUN: Windows MinGW runtime `libasan` is missing; WSL process creation returned `E_ACCESSDENIED` |
| GCC UBSan | NOT RUN: Windows MinGW runtime `libubsan` is missing; WSL process creation returned `E_ACCESSDENIED` |

The Clang sanitizer runs above instrument the current namespaced implementation. The earlier 2026 report also contains sanitizer results for the pre-namespace revision; they are historical and are not used for this table.

## Integration checks

GCC 16.1 Release verified:

- Installed C-only package consumption with `find_package(Stabilora 0.2 CONFIG REQUIRED)` and target `Stabilora::Stabilora`.
- C-only `add_subdirectory()` consumption; the consumer configuration did not detect a C++ compiler, tests were off by default, and CTest registered zero tests in the consumer build.
- Direct strict C99 compilation and execution of the timeout API with its required checked-shift source unit.

## ESP32-S3

**Current product revision: HW NOT VERIFIED.** A historical report dated 2026-11-10 records representative checks for all six pre-namespace APIs on an ESP32-S3 revision v0.2 at 240 MHz using Arduino-ESP32 3.3.10. It reported a successful device marker. The report predates the public namespace/file migration and has not been repeated against this source revision. It was a correctness workload, not a performance or footprint measurement. No current board was programmed for this revision.

## Reproduce

GCC or Clang single-configuration build:

```sh
cmake -S . -B build -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -DSTABILORA_BUILD_TESTS=ON -DSTABILORA_STRICT_WARNINGS=ON
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

MSVC or ClangCL multi-configuration build:

```powershell
cmake -S . -B build -DSTABILORA_BUILD_TESTS=ON -DSTABILORA_STRICT_WARNINGS=ON
cmake --build build --config Release --parallel
ctest --test-dir build -C Release --output-on-failure
```

The GitHub Actions workflow covers GCC and Clang Debug/Release, MSVC Debug/Release, GCC ASan and GCC UBSan. A current-revision remote run has not yet been verified.
