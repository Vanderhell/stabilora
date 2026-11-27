# Contributing

Changes should preserve the public C99 contracts, deterministic behavior,
caller-owned state and buffers, and absence of mandatory heap or operating
system dependencies.

Run the strict CMake build and CTest suite in Debug and Release before opening
a pull request. Add an enabled regression test for every behavior change; do
not rely on `assert()` because Release may define `NDEBUG`. Keep test references
independent of production algorithms, and state unavailable compiler or hardware
checks explicitly.

Keep performance statements backed by target measurements. Describe affected
APIs and include the exact build/test commands in the pull request.
