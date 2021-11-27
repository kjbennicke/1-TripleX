#include <iostream>
#include <ctime>
using namespace std;

void PlayIntroduction(int Difficulty){
     //Greeting message to terminal
    cout<< "-------------------------------------------------\n";
    cout<< "Welcome Agent Orange. Your hacking layer "<< Difficulty << "\n";
    cout<< "The code is 3 numbers.\n";
    }

bool PlayGame(int Difficulty){
    //Intialization of Code
    int CodeA = rand()% Difficulty + Difficulty;
    int CodeB = rand()% Difficulty + Difficulty;
    int CodeC = rand()% Difficulty + Difficulty;
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    PlayIntroduction(Difficulty);
    cout<< "They add up to: "<< CodeSum << endl;
    cout<< "They multiply to: "<< CodeProduct << endl;
    cout<< "-------------------------------------------------\n";

    //Recieves Players Guess
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    cout << "You entered: " << GuessA << GuessB<< GuessC << endl;

    //Logic for processing input
    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        cout << "YOU WIN!! Level "<< Difficulty << endl;  
        
        return true;  
    }
    else{
        cout << "YOU ARE DEAD!!" << endl; 
        return false;
    }
    
}
int main(){
    srand(time(NULL));
    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while(LevelDifficulty <= MaxLevel){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();//clears and erros
        cin.ignore();//discards the buffer
        system("clear");
        if(bLevelComplete){
            ++LevelDifficulty;
        }
    }
    cout << "--------------------------------------------------------------------------\n";
    cout << "You have broken through all security layers and are now in the Mainframe!!\n";
    cout << "--------------------------------------------------------------------------";
    return 0;
}