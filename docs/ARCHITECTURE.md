# Architecture

Stabilora is a standalone C99 static library composed of six small translation units. Each operation has an independent public header and can be integrated by compiling its matching source file or linking the `stabilora` CMake target.

All state is passed by value or held in caller-owned objects. There is no initialization routine, heap allocation, thread, operating-system service, or mandatory external dependency. The public API does not change between standalone-source and CMake integration.

Boolean functions validate their documented parameters before writing outputs. Debounce and hysteresis state is explicitly caller-owned; histogram buffers are fixed at 256 bins. Exact histogram in-place processing is supported, while partial array overlap and overlap with the excess output are not.

The implementation requires C99 and fixed-width integer types. CMake exports the repository `include/` root for canonical includes such as `<stabilora/control/pc_checked_shl_u32.h>` and retains the direct control-header path for existing users.
