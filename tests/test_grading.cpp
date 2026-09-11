#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "grading.h"

TEST_CASE("Student Average Calculation") {
    ScoreGrid scores = {
        {100.0, 90.0, 80.0, 70.0, 60.0}
    };
    REQUIRE(studentAverage(scores, 0) == 80.0);
}

TEST_CASE("CountAtRisk ReturnsZeroWhenEveryoneIsPassing", "[grading]") {
  
    ScoreGrid scores{};
    for (auto& row : scores) {
        for (auto& score : row) {
            score = 85.0;
        }
    }

    
    int result = countAtRisk(scores);

    
    CHECK(result == 0);
}

TEST_CASE("CountAtRisk CountsBothFailingStudents", "[grading]") {
    
    ScoreGrid scores{};
    for (auto& row : scores) {
        for (auto& score : row) {
            score = 85.0;
        }
    }
    
    
    for (auto& score : scores[0]) {
        score =50.0;
    }
    for (auto& score : scores[1]) {
        score = 50.0;
    }

    
    int result = countAtRisk(scores);

    
    CHECK(result == 2);
}

TEST_CASE("FindClassExtremes IdentifiesOverallLowestAndHighestScoresAndRows", "[grading]") {
    
    ScoreGrid scores{};
    for (auto& row : scores) {
        for (auto& score : row) {
            score = 75.0;
        }
    }
    scores[1][2] = 12.0; 
    scores[3][0] = 98.0; 

    int lowest = 0;
    int highest = 0;
    int lowestRow = -1;
    int highestRow = -1;

    
    findClassExtremes(scores, lowest, highest, lowestRow, highestRow);

    
    CHECK(lowest == 12);
    CHECK(highest == 98);
    CHECK(lowestRow == 1);
    CHECK(highestRow == 3);
}

TEST_CASE("ApplyCurve RaisesEveryScoreByTheGivenPoints", "[grading]") {
    ScoreGrid scores{};
    for (auto& row : scores) {
        row = {70.0, 70.0, 70.0, 70.0};
    }

    
    applyCurve(scores, 5);

    
    CHECK(scores[0][0] == 75.0);
}

TEST_CASE("ApplyCurve NeverPushesAScoreAboveOneHundred", "[grading]") {
   
    ScoreGrid scores{};
    for (auto& row : scores) {
        row = {98.0, 98.0, 98.0, 98.0};
    }

    
    applyCurve(scores, 10);

    
    CHECK(scores[0][0] == 100.0);
}

TEST_CASE("TopStudent ReturnsTheRowWithTheHighestAverage", "[grading]") {
    
    ScoreGrid scores{};
    for (auto& row : scores) {
        row = {70.0, 70.0, 70.0, 70.0};
    }
    scores[2] = {95.0, 95.0, 95.0, 95.0}; 

   
    int bestRow = topStudent(scores);

    
    CHECK(bestRow == 2);
}
