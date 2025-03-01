// Jude Hertting
// Assignment 5 Math Quiz

#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// function prototypes
void getQuestions(const string& filename, vector<string>& questions);
void askQuestions(const vector<string>& questions);

int main()
{
    vector<string> questions;

    // calls function to get questions
    getQuestions("questions.txt", questions);

    cout << "Welcome to the Math Quiz" << endl;

    // calls function to prompt user the questions
    askQuestions(questions);

    cout << "Results saved to QuizResults.txt" << endl;

    (void)_getch();
    return 0;
}

// function to read and store questions from file
void getQuestions(const string& filename, vector<string>& questions) 
{
    // opens file
    ifstream file(filename); 
    string line;

    while (getline(file, line)) 
    {  
        // reads lines and stores in questions vector
        questions.push_back(line); 
    }

    file.close(); 
}

// fucntion to grab 3 random questions and save the results 
void askQuestions(const vector<string>& questions) 
{
    srand(time(0));  

    ofstream resultsFile("QuizResults.txt");

    // loop to get 3 random questions 
    for (int i = 0; i < 3; ++i) 
    {
        int randomIndex = rand() % questions.size();  

        cout << endl;

        cout << "Question " << i + 1 << ": " << questions[randomIndex] << " = " << endl ;
        cout << "Enter your answer: ";

        string userAnswer;
        cin >> userAnswer;  
        
        cout << endl;

        // outputs question and answers to the quizresults file
        resultsFile << questions[randomIndex] << " = " << userAnswer << endl;
    }

    resultsFile.close(); 
}

