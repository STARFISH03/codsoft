#include <iostream>
using namespace std;
int main(){

    int secretNum = rand() % 100 + 1;
    int guessedNum;
    int attempts = 0;
    cout << "Welcome to the Guess the Number Game!" <<endl;
    cout << "I'm thinking of a number between 1 and 100. Try to guess it." <<endl;

    do
    {
        cout << "ENTER THE NUMBER YOU GUESSED-";
        cin >>guessedNum ;
        attempts++;
        if (guessedNum < secretNum)
        {
            cout << "Too low. Try again." <<endl;
        }
        else if (guessedNum > secretNum)
        {
            cout << "Too high. Try again." <<endl;
        }
        else
        {
            cout << "Congratulations! You guessed the number " << secretNum << " in " << attempts << " attempts." << endl;
        }
    } while (guessedNum != secretNum);

    return 0;
}
