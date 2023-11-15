#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::pair<std::string, double>> studentGrades;
    std::string name;
    double grade;

    // Allowing the user to input student names and grades
    std::cout << "Enter student names and their corresponding grades. Enter 'exit' to finish.\n";

    while (true) {
        std::cout << "Enter student name (or 'exit' to finish): ";
        std::cin >> name;

        if (name == "exit") {
            if (studentGrades.empty()) {
                std::cout << "No data entered. Exiting program.";
                return 0;
            }
            break;
        }

        std::cout << "Enter " << name << "'s grade: ";
        std::cin >> grade;

        studentGrades.push_back(std::make_pair(name, grade));
    }

    // Calculate the average grade
    double totalGrade = 0.0;
    for (const auto &student : studentGrades) {
        totalGrade += student.second;
    }
    double averageGrade = totalGrade / studentGrades.size();

    // Find highest and lowest grades
    auto highestGrade = std::max_element(studentGrades.begin(), studentGrades.end(),
        [](const auto &a, const auto &b) {
            return a.second < b.second;
        });

    auto lowestGrade = std::min_element(studentGrades.begin(), studentGrades.end(),
        [](const auto &a, const auto &b) {
            return a.second < b.second;
        });

    // Displaying the results
    std::cout << "\nAverage grade: " << averageGrade << std::endl;
    std::cout << "Highest grade: " << highestGrade->second << " (Student: " << highestGrade->first << ")" << std::endl;
    std::cout << "Lowest grade: " << lowestGrade->second << " (Student: " << lowestGrade->first << ")" << std::endl;

    return 0;
}
