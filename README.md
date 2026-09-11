# lab04

## do my tests actually catch anything?

1. isAtRisk threshold 70 -> 60
   caught by: countatrisk countsbothfailingstudents
   if not caught, the test i was missing: n/a (caught it after setting test scores to 65.0)

2. applyCurve cap removed
   caught by: applycurve neverpushesascoreaboveonehundred
   if not caught, the test i was missing: n/a

3. topStudent loop stops one early
   caught by: topstudent returnstherowwiththehighestaverage
 if not caught, the test i was missing: a test where the highest scoring student is in the last row of the grid.
