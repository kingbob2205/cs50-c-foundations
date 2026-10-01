# Recognizing sorting algorithms

The introductory Sort exercise uses precompiled programs. This is a study note, not a claim to possess their source code.

| Algorithm | What to watch for | Complexity |
| --- | --- | --- |
| Bubble sort | Adjacent swaps; an already sorted list can finish quickly with an early-exit optimization | Best O(n), worst O(n²) with early exit |
| Selection sort | Repeated scan for the smallest remaining item; roughly the same number of comparisons even when sorted | O(n²) |
| Merge sort | Divide into halves, sort, then merge; scales better on large inputs | O(n log n) |

Timing alone is not proof because input shape, implementation details, and hardware matter. Compare behavior on sorted, reversed, and random data together.
