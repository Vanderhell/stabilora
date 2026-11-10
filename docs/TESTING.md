# Testing and validation

All six public functions have an independent test executable. Checks use an explicit `CHECK` macro and remain active when `NDEBUG` is defined in Release builds. The tests include boundary cases, invalid arguments, output-preservation checks, deterministic sequences, and independent mathematical references where applicable.

## Reproduce strict Release tests

```sh
cmake -S . -B build -DSTABILORA_BUILD_TESTS=ON -DSTABILORA_STRICT_WARNINGS=ON -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

MSVC multi-configuration builds:

```powershell
cmake -S . -B build-msvc -DSTABILORA_BUILD_TESTS=ON -DSTABILORA_STRICT_WARNINGS=ON
cmake --build build-msvc --config Debug --parallel
ctest --test-dir build-msvc -C Debug --output-on-failure
cmake --build build-msvc --config Release --parallel
ctest --test-dir build-msvc -C Release --output-on-failure
```

## Sanitizers

GCC or Clang on a supported host:

```sh
cmake -S . -B build-san -DSTABILORA_BUILD_TESTS=ON -DSTABILORA_STRICT_WARNINGS=ON -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer"
cmake --build build-san --parallel
ctest --test-dir build-san --output-on-failure
```

On Windows, Clang-cl AddressSanitizer can be run in a Visual Studio Developer shell. The executed local run compiled each test with all production translation units and ran each resulting binary:

```powershell
$src = (Get-ChildItem src\*.c).FullName
foreach ($test in Get-ChildItem tests\*.c) {
    $exe = Join-Path $env:TEMP ($test.BaseName + '.exe')
    & clang-cl /nologo /fsanitize=address /O2 /MD /Iinclude /Iinclude\stabilora\control $test.FullName $src "/Fe:$exe"
    if ($LASTEXITCODE -ne 0) { throw "ASan compile failed: $($test.Name)" }
    & $exe
    if ($LASTEXITCODE -ne 0) { throw "ASan test failed: $($test.Name)" }
}
```

## Coverage map

| Test | API | Cases |
|---|---|---|
| `test_001_control_output_clamp_i32` | clamp | signed extremes, interval edges, invalid bounds, null output, one million deterministic differential intervals |
| `test_002_debounce_counter_bool` | debounce | all transitions for thresholds 1–32 and valid counts, input sequences, repeated samples, maximum threshold/count, invalid state and pointers |
| `test_003_debounce_dual_threshold_i32` | hysteresis | exact threshold equality, state changes/retention, invalid bounds, signed extremes, exhaustive small-domain state transitions |
| `test_004_hist_clip_limit_u32` | histogram | 256 maximum bins, exact in-place alias, excess invariant, failure preservation, 20,000 seeded histograms |
| `test_005_timeout_backoff_cap_u32` | timeout backoff | attempts 0–40 and maximum, overflow/cap behavior, invalid parameters, exhaustive base/cap 1–255 comparison |
| `test_006_checked_shl_u32` | checked shift | shifts 0–31/32, high-bit boundaries, null output, unchanged output on failure, 100,000 seeded reference cases |

## ESP32-S3 device run (2026-11-10)

Arduino CLI 1.4.1 compiled the six production C translation units and a temporary firmware harness with Arduino-ESP32 core 3.3.10. The board identified itself as ESP32-S3 revision v0.2 at 240 MHz on COM19 (USB-Serial/JTAG). It printed `STABILORA_HW PASS`. Workload: clamp 100,000 deterministic differential intervals; debounce transition/noise sequence and `UINT32_MAX` cases; hysteresis 100,000 deterministic cases plus signed endpoints; histogram 5,000 seeded 256-bin cases plus 256 maximum bins, maximum excess and exact in-place alias; checked shift 100,000 seeded cases plus shifts 0 to 32 and high-bit edges; timeout backoff 100,000 deterministic cases plus overflow, cap and max-attempt edges. Firmware compiled and uploaded with flash verification. This is functional target evidence for representative cases, not exhaustive input coverage or an MCU performance/footprint measurement.

## Executed local results (2026-11-10)

| Configuration | Result |
|---|---|
| GCC 16.1, C99, strict warnings, Release | PASS, 6/6 |
| Clang-cl 19.1.5, strict warnings, Release | PASS, 6/6 |
| MSVC 19.42.34444, strict warnings, Debug | PASS, 6/6 |
| MSVC 19.42.34444, strict warnings, Release | PASS, 6/6 |
| Clang-cl AddressSanitizer, direct instrumented build/run | PASS, 6/6 |
| Clang-cl UndefinedBehaviorSanitizer, Release | PASS, 6/6 |
| GCC ASan/UBSan | NOT RUN: Windows MinGW installation lacks `libasan` and `libubsan` |
| Clang GNU driver | NOT RUN: standalone Windows Clang configuration lacks a usable linker/runtime environment |
| ESP32-S3 v0.2, 240 MHz, Arduino-ESP32 3.3.10, COM19 USB-Serial/JTAG | PASS, all six APIs; see device workload below |

The CMake/Ninja Clang-cl ASan link configuration could not automatically pass the sanitizer runtime flags to its direct MSVC-style linker invocation, so the local ASan run used Clang-cl to compile and link the six test programs directly. CI runs GCC and Clang strict Release tests plus combined ASan/UBSan on Ubuntu, and MSVC Debug and Release on Windows. Results are reported only after those workflow jobs actually run.
