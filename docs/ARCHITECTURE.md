# Architecture

Stabilora is a static C99 library. The extracted functions operate on explicit
values and caller-owned state; no hidden initialization or background runtime
exists. Public headers retain the source `pc_` API.
