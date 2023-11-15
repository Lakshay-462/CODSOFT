#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;
    const int maxAttempts = 10;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Can you guess the number between 1 and 100?\n";

    while (attempts < maxAttempts) {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Too high! Try again.\n";
        }

        int attemptsLeft = maxAttempts - attempts;
        cout << "Attempts left: " << attemptsLeft << "\n";

        if (attemptsLeft == 0) {
            cout << "Sorry, you've run out of attempts. The correct number was: " << secretNumber << "\n";
        }
    }

    return 0;
}
