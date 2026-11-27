# Architecture

Stabilora is a standalone C99 static library with six bounded control and
signal-conditioning operations. Each public API has its own header and source
unit under the product namespace.

All state is caller-owned. The library has no initialization routine, heap
allocation, operating-system service, thread dependency, or mandatory external
library. The namespaced target is `Stabilora::Stabilora`; source-level
integration can compile a selected operation and its documented source
requirements.

The operations include scalar output clamping, two debounce/hysteresis state
updates, fixed 256-bin histogram clipping, checked 32-bit left shift, and a
capped exponential timeout backoff. Histogram exact in-place aliasing is
supported; partial overlap and overlap involving the excess output are not.
