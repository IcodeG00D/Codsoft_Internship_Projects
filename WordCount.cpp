#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int countWordsInFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 0;
    }

    std::string word;
    int wordCount = 0;

    while (file >> word) {
        wordCount++;
    }

    file.close();

    return wordCount;
}

int main() {
    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    int totalWords = countWordsInFile(fileName);

    if (totalWords > 0) {
        std::cout << "Total words in the file: " << totalWords << std::endl;
    }

    return 0;
}
