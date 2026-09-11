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
    // Arrange
    ScoreGrid scores{};
    for (auto& row : scores) {
        for (auto& score : row) {
            score = 85.0;
        }
    }

    // Act
    int result = countAtRisk(scores);

    // Assert
    CHECK(result == 0);
}

TEST_CASE("CountAtRisk CountsBothFailingStudents", "[grading]") {
    // Arrange
    ScoreGrid scores{};
    for (auto& row : scores) {
        for (auto& score : row) {
            score = 85.0;
        }
    }
    
    // Set 2 students to have scores under 70.0
    for (auto& score : scores[0]) {
        score = 50.0;
    }
    for (auto& score : scores[1]) {
        score = 50.0;
    }

    // Act
    int result = countAtRisk(scores);

    // Assert
    CHECK(result == 2);
}

TEST_CASE("FindClassExtremes IdentifiesOverallLowestAndHighestScoresAndRows", "[grading]") {
    // Arrange
    ScoreGrid scores{};
    for (auto& row : scores) {
        for (auto& score : row) {
            score = 75.0;
        }
    }
    scores[1][2] = 12.0; // Lowest score
    scores[3][0] = 98.0; // Highest score

    int lowest = 0;
    int highest = 0;
    int lowestRow = -1;
    int highestRow = -1;

    // Act
    findClassExtremes(scores, lowest, highest, lowestRow, highestRow);

    // Assert
    CHECK(lowest == 12);
    CHECK(highest == 98);
    CHECK(lowestRow == 1);
    CHECK(highestRow == 3);
}

TEST_CASE("ApplyCurve RaisesEveryScoreByTheGivenPoints", "[grading]") {
    // Arrange
    ScoreGrid scores{};
    for (auto& row : scores) {
        row = {70.0, 70.0, 70.0, 70.0};
    }

    // Act
    applyCurve(scores, 5);

    // Assert
    CHECK(scores[0][0] == 75.0);
}

TEST_CASE("ApplyCurve NeverPushesAScoreAboveOneHundred", "[grading]") {
    // Arrange
    ScoreGrid scores{};
    for (auto& row : scores) {
        row = {98.0, 98.0, 98.0, 98.0};
    }

    // Act
    applyCurve(scores, 10);

    // Assert
    CHECK(scores[0][0] == 100.0);
}

TEST_CASE("TopStudent ReturnsTheRowWithTheHighestAverage", "[grading]") {
    // Arrange
    ScoreGrid scores{};
    for (auto& row : scores) {
        row = {70.0, 70.0, 70.0, 70.0};
    }
    scores[2] = {95.0, 95.0, 95.0, 95.0}; // Top student

    // Act
    int bestRow = topStudent(scores);

    // Assert
    CHECK(bestRow == 2);
}
