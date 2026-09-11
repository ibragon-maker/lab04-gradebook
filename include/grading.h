// include/grading.h
#ifndef GRADING_H
#define GRADING_H

#include "constants.h"

/**
 * @brief Calculates one student's mean score across all assignments.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to average.
 * @return The mean of that student's assignment scores.
 */
[[nodiscard]] double studentAverage(const ScoreGrid& scores,
                                    int studentIndex);

/**
 * @brief Calculates the mean score on one assignment across all students.
 *
 * @pre assignmentIndex is in the range [0, ASSIGNMENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores           The grade grid.
 * @param[in] assignmentIndex  Column of the assignment to average.
 * @return The mean score earned on that assignment.
 */
[[nodiscard]] double assignmentAverage(const ScoreGrid& scores,
                                       int assignmentIndex);

/**
 * @brief Calculates the mean of every score in the grid.
 *
 * @post The scores grid is not modified.
 *
 * @param[in] scores  The grade grid.
 * @return The mean of all STUDENT_COUNT * ASSIGNMENT_COUNT scores.
 */
[[nodiscard]] double classAverage(const ScoreGrid& scores);

/**
 * @brief Finds one student's lowest and highest assignment scores.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post lowest holds that student's minimum score.
 * @post highest holds that student's maximum score.
 * @post The scores grid is not modified.
 *
 * @param[in]  scores        The grade grid.
 * @param[in]  studentIndex  Row of the student to examine.
 * @param[out] lowest        Receives the minimum score.
 * @param[out] highest       Receives the maximum score.
 */
void findExtremes(const ScoreGrid& scores, int studentIndex,
                  double& lowest, double& highest);

/**
 * @brief Counts how many students earned a given letter grade.
 *
 * @pre target is one of 'A', 'B', 'C', 'D', or 'F'.
 * @post The scores grid is not modified.
 *
 * @param[in] scores  The grade grid.
 * @param[in] target  The letter grade to count.
 * @return The number of students whose average earns that letter.
 */
[[nodiscard]] int countGrade(const ScoreGrid& scores, char target);

/**
 * @brief Reports whether a student earned a perfect score on any assignment.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to examine.
 * @return true if any of that student's scores is 100 or above.
 */
[[nodiscard]] bool hasPerfectScore(const ScoreGrid& scores,
                                   int studentIndex);

/**
 * @brief Reports whether a student is academically at risk.
 *
 * A student is at risk when their average is below 70, or when any
 * single assignment score is below 50.
 *
 * @pre studentIndex is in the range [0, STUDENT_COUNT).
 * @post The scores grid is not modified.
 *
 * @param[in] scores        The grade grid.
 * @param[in] studentIndex  Row of the student to examine.
 * @return true if either at-risk condition holds.
 */
[[nodiscard]] bool isAtRisk(const ScoreGrid& scores, int studentIndex);

/**
 * @brief Counts how many students in the class are at risk.
 *
 * @post The scores grid is not modified.
 *
 * @param[in] scores  The grade grid.
 * @return Number of students at risk.
 */
[[nodiscard]] int countAtRisk(const ScoreGrid& scores);

/**
 * @brief Finds the single lowest and highest score in the grid and their row indices.
 *
 * @pre Grid is populated with student scores.
 * @post lowest, highest, lowestRow, and highestRow contain extreme values and row indices.
 * @post The scores grid is not modified.
 *
 * @param[in]  scores      The grade grid.
 * @param[out] lowest      Receives the lowest score in the class.
 * @param[out] highest     Receives the highest score in the class.
 * @param[out] lowestRow   Receives the row index of the lowest score.
 * @param[out] highestRow  Receives the row index of the highest score.
 */
void findClassExtremes(const ScoreGrid& scores, int& lowest, int& highest,
                        int& lowestRow, int& highestRow);

/**
 * @brief Adds points to every score in the grid, capped at 100.
 *
 * @pre Grid has scores and curve points is non-negative.
 * @post Scores in the grid are increased by points up to a maximum of 100.
 *
 * @param[in,out] scores  The grade grid to modify.
 * @param[in]     points  The amount of points to add to each score.
 */
void applyCurve(ScoreGrid& scores, int points);

/**
 * @brief Returns the row index of the student with the highest average score.
 *
 * @pre Grid contains valid student scores.
 * @post The scores grid is not modified.
 *
 * @param[in] scores  The grade grid.
 * @return Row index of the student with the top average.
 */
[[nodiscard]] int topStudent(const ScoreGrid& scores);

#endif
