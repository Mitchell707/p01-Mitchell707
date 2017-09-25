//Author: Mitchell Beck

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int maxNum = 10;
int gameMode = 0;
int guess = 0;
int count = 0;
    
char again;

int main()
{

    cout << "What gamemode do you want?\n" << "1. Difference\n" << "2. Above or below\n" << "Type the number of the gamemode you want\n";
    cin >> gameMode;

    //cout << "gameMode: " << gameMode << endl;     

        while(gameMode != 1 || gameMode != 2)
        {
            if(gameMode == 1 || gameMode == 2)
            {
                break;
            }
            else
            {
                cout << "That is not a valid gamemode. Please try again.\n";
                cin >> gameMode;
            }
        }

    cout << "What is the highest number you would like to have?" << endl << "1 to ";
    cin >> maxNum;
    
    /*
    initialize random seed. Do this only once at the beginning of the main-function
    */ 
    srand ( time(NULL) ); 
    int randomNumber; // this variable will hold the random number
    /*
    generate secret number: between 1 and 10. Change the 10 to a different value to    
    generate random numbers up to that maximum value 
    */ 
    randomNumber = rand() % maxNum + 1;

    //cout << randomNumber << endl;

    while(guess != randomNumber)
    {
        cout << "Type in your guess: ";
        cin >> guess;

        if(guess != randomNumber)
        {
            if(gameMode == 1)
            {
                cout << "You are " << abs(randomNumber - guess) << " away from the correct number\n";
            }
            else
            {
                if(guess > randomNumber)
                {
                     cout << "Your guess is too large.\n";
                }
                else
                {
                    cout << "Your guess is too small.\n";
                }
            }
         guess = 0;
         count++;
       }
    }

    cout << "Congratulations, you have gotten the correct number " << randomNumber << " in " << count << " guesses." << endl;
    
    cout << "Do you wish to play again\n(Y)es or (N)o: ";
    cin >> again;

    if(again == 'Y' || again == 'y')
    {
        main();
    }
        
    return 0;

}
