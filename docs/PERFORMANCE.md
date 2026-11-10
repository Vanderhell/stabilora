# Performance

Representative correctness checks for all six APIs passed on an ESP32-S3 v0.2 at 240 MHz (see [TESTING.md](TESTING.md)). No controlled performance or isolated footprint measurements are available; flash, static RAM, stack, and cycle counts for the library remain unmeasured.

The code uses fixed-size storage and bounded work. Histogram clipping processes exactly 256 bins; timeout backoff uses at most one checked shift and bounded branches. Operation counts do not predict target latency. Measure on the actual target before making performance claims or algorithm changes.
