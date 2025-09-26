#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void game(int secretNumber,int currentPlayer) {
    int guess;
    cout << "Player " << currentPlayer << ",enter your guess: ";
    cin >> guess;

    if (guess == secretNumber) {
        cout << "Congratulations,Player " << currentPlayer << "! You guessed the correct number: " << secretNumber << endl;
        return;
    }
    if (guess > secretNumber) {
        cout << "Too high!" << endl;
    } else {
        cout << "Too low!" << endl;
    }
    int nextPlayer = (currentPlayer == 1) ? 2 : 1;
    game(secretNumber, nextPlayer);
}
int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;

    cout << "--- Number Guessing Game ---" << endl;
    cout << "A secret number between 1 and 100 has been generated." << endl;
    cout << "Players will take turns guessing the number." << endl;

    game(secretNumber, 1);

    return 0;
}

