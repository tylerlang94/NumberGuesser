#include <iostream>
#include "../Headers/Random.h"

bool PlayGame(int guesses, int number) {
    for (int count {1}; count <= guesses; ++count) {
        std::cout << "Guess Number: " << count << '\n';
        std::cout << "What is your guess: ";

        int guess{};
        std::cin >> guess;

        if (guess > number) {
            std::cout << "Your guess of " << guess << " is too high\n";
        }
        else if (guess < number) {
            std::cout << "Your guess of " << guess << " is too low\n";
        }
        else {
            return true;
        }
    }
    return false;
}

bool PlayAgain(){
    while(true){
        char ch{};
        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> ch;

        switch (ch){
            case 'y':
            case 'Y':
                return true;
            case 'n':
            case 'N':
                return false;
            default:
                PlayAgain();
        }
    }
}

int main() {
    constexpr int guesses {7};
               
    do {
        int number {Random::get(1,100)};

        std::cout << "Lets play a game. I am thinking of a number between 1 and 100. You have " << guesses << " tries\n";

        bool won{PlayGame(guesses, number)};

        if (won) {
            std::cout << "Correct! You Win! ";
        }
        else {
            std::cout << "Sorry but you lose! The correct number was " << number << '\n';
        }
    } while (PlayAgain());

    std::cout << "Thank you for playing! Come agian soon!";
    return 0;
}

