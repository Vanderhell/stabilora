# Changelog

## 0.2.0 - product API namespace migration

**Breaking API change:** all public `pc_*` operations and related public
identifiers now use the unique `stabilora_*` / `STABILORA_*` namespace. Header
basenames no longer include `pc_`. See `docs/API_REFERENCE.md` for the complete
symbol mapping. No production algorithm was changed.

- Added the `Stabilora::Stabilora` CMake target, install rules and package config.
- Made tests opt-in and added isolated C header and C++ header checks.
- Historical ESP32-S3 results are retained but current-revision hardware status
  is HW NOT VERIFIED.
