# C Foundations: independent CS50-inspired recreations

Small, self-contained C programs covering the concepts from the first three C-focused weeks of CS50x. These are **new portfolio recreations**, not archived course submissions or verified CS50 grades. The descriptions are original summaries; the source code was written for this repository.

| Area | Programs | Core idea |
| --- | --- | --- |
| Week 1 | Hello, Mario (one and two pyramids), Cash, Credit | Input, loops, conditionals, greedy coin counting, Luhn validation |
| Week 2 | Scrabble, Readability, Caesar, Substitution | Arrays, strings, text scoring, character transformation |
| Week 3 | Plurality; Sort notes | Counting votes, tie handling, comparing sorting behavior |

## Build and run

Requires a C11 compiler and `make` (tested with Apple Clang).

```sh
make
./bin/mario_less
./bin/caesar 13
./bin/plurality Alice Bob Charlie
make test
```

Each source is under `src/` and compiles independently. `make test` runs deterministic smoke tests. Interactive programs prompt for input. The cipher programs preserve non-letters and letter case. Credit uses string input so it never loses leading digits through integer conversion.

## Notes on the Sort exercise

The CS50 Sort activity is primarily an observation/identification exercise using supplied binaries, not a missing C source file. [sort-notes.md](sort-notes.md) records the distinguishing behavior of bubble, selection, and merge sort without pretending to reproduce those supplied binaries.

## Scope and provenance

This repository demonstrates beginner C fundamentals. It does not contain the author's original CS50 submissions, CS50 library dependencies, assignment text, or course grading results. It is not intended to be submitted as coursework.
