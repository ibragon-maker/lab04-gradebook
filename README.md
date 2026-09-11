# lab04

Did my tests actually catch anything?

1. isAtRisk threshold 70 -> 60
   caught by: countatrisk countsbothfailingstudents
   if not caught, the test i was missing: n/a (caught it after setting test scores to 65.0)

2. applyCurve cap removed
   caught by: applycurve neverpushesascoreaboveonehundred
   if not caught, the test i was missing: n/a

3. topStudent loop stops one early
   caught by: topstudent returnstherowwiththehighestaverage
 if not caught, the test i was missing, a test where the highest scoring student is in the last row of the grid.


## module overview
- `include/grading.h`: header declaring core gradebook structures and functions.
- `src/grading.cpp`: implementation of grade calculations, curving, and statistics.
- `tests/test_grading.cpp`: catch2 unit test suite verifying postconditions and boundary cases.
- `src/main.cpp`: entry point for running the main application.

## how to build and test

cmake -S . -B build
cmake --build build
ctest --test-dir build
