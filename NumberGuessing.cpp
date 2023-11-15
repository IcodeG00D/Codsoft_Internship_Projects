#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    int randomNumber = std::rand() % 100 + 1;
    
    int userGuess;
    int attempts = 0;


    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        std::cout << "Guess the number (between 1 and 100): ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number, which is " << randomNumber << " in " << attempts << " attempts." << std::endl;
        }
    }while (userGuess != randomNumber);

    return 0;
}
