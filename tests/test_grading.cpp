#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "grading.h"

TEST_CASE("Student Average Calculation") {
    ScoreGrid scores = {
        {100.0, 90.0, 80.0, 70.0, 60.0}
    };
    REQUIRE(studentAverage(scores, 0) == 80.0);
}
