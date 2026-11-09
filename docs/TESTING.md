# Testing

| Test category | Count | Platform | Result | Evidence |
|---|---:|---|---|---|
| Migrated unit tests | 5 | Windows host, MSVC 19.42.34444, Release | PASS 5/5 | `tests/`, CTest |
| Hardware validation | 0 | ESP32-S3 | HW NOT VERIFIED | No firmware run yet |
| Sanitizers | 0 | Host | NOT TESTED | Toolchain setup pending |

```sh
cmake -S . -B build -DSTABILORA_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```
