# Performance

No current execution-cycle, timing, isolated flash, static RAM, or stack measurements are available for Stabilora. Operation counts are bounded by fixed-width arithmetic, six public translation units, and a fixed 256-bin pass for histogram clipping; those facts do not establish target latency or memory bounds.

A historical correctness workload was run on an ESP32-S3 revision v0.2 at 240 MHz with Arduino-ESP32 3.3.10 before the current API namespace and source layout. It did not record function cycles or isolated library footprint. Current-revision hardware validation remains **HW NOT VERIFIED**.

Measure on the intended target before making performance claims. Separate library contribution from firmware framework and validation harness overhead.
