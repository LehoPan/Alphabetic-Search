#include <iostream> 
#include <iterator> 
#include <map> 
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Asks for guess and checks it. if wrong, will ask for guess again.
void word_guess(map<string, int> myMap, int correctAnswer);


int main(){
    //input stream declare and open
    ifstream in_stream;

    //opens input stream to word file
    in_stream.open("newWords.txt");
    if (in_stream.fail()){
        cout << "Input file opening failed.\n";
        exit(1);
    }

    //variable for keeping track of what order the word being assigned is, and the word itself
    int counter = 1;
    string word;
    
    //empty container
    map<string, int> wordMap;

    //insert elements with word as key and placement as value
    while(in_stream >> word){
        wordMap.insert(pair<string, int>(word, counter));
        counter++;
    }

    //assign random word in list as the "target" word
    srand((unsigned) time(0));
    int correctAnswer = (rand() % 2992) + 1;
    
    //uncomment if you want answer to be displayed for testing purposes
    /*
    cout << correctAnswer << endl;
    */

    //guesses word
    word_guess(wordMap, correctAnswer);

    //message for winning
    cout << "Congrats on guessing the right word! Thanks for playing the game.\n";


    return 0;
}


void word_guess(map<string, int> myMap, int correctAnswer){
    //declaring iterators 
    map<string, int>::iterator it; 

    //string to hold guess
    string guess;

    //asks for the guess, and tests if correct. if wrong, user is told whether the guess is before or after alphabetically
    //if guess is wrong, reruns function to ask again
    cout << "Please enter you word guess: ";
    cin >> guess;
    it = myMap.find(guess); 
        
    if(it == myMap.end()) {
        cout << "Guess is invalid or not-found in list.\n"; 
        word_guess(myMap, correctAnswer);

    }
    else{
        if(it->second == correctAnswer){
            //just does nothing and ends the function
        }
        else if(it->second < correctAnswer){
            cout << "Sorry, but your guess is alphabetically before the target.\n";
            word_guess(myMap, correctAnswer);
        }
        else{
            cout << "Sorry, but your guess is alphabetically after the target.\n";
            word_guess(myMap, correctAnswer);
        }
    }
    cout << endl; 



}