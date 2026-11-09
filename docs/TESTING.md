# Testing

| Test category | Count | Platform | Result | Evidence |
|---|---:|---|---|---|
| Migrated unit tests | 5 | Windows host, MSVC 19.42.34444, Release | PASS 5/5 | `tests/`, CTest |
| Strict warning build | 5 | GCC 13.3 / Ubuntu 24.04 | PASS 5/5 | `-Wall -Wextra -Werror` |
| Hardware validation | 0 | ESP32-S3 | HW NOT VERIFIED | No firmware run yet |
| Sanitizers | 0 | Host | NOT TESTED | Toolchain setup pending |

```sh
cmake -S . -B build -DSTABILORA_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build --output-on-failure -C Release
```

Strict GCC reproduction:

```sh
cmake -S . -B build-linux -DSTABILORA_BUILD_TESTS=ON -DCMAKE_C_FLAGS="-Wall -Wextra -Werror"
cmake --build build-linux --parallel
ctest --test-dir build-linux --output-on-failure
```
