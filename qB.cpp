
/* 
 Title: GoodDocs.cpp
 Description: Saying Hello with C++
 Date: January 3, 2009
 Author: Richard S. Huntrods
 Version: 1.0
 Copyright: 2009 Richard S. Huntrods
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Demonstrate proper format for documentation, test plans and comments.
 	Also demonstrate user prompts, keyboard input, simple calculations and output.

 Compile (assuming Cygwin is running): g++ -o GoodDocs GoodDocs.cpp
 Execution (assuming Cygwin is running): ./GoodDocs.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes: none

 Variables:
 	name - char array sized for 131 characters - used to store user's name (one word only)
 	age - int - used to store user's age as an integer number
*/

/*
 TEST PLAN
 
 Normal case:
 	>What is your name? Richard
 	>What is your age? 21
 	>Hello! My name is Richard, and I am 21 years old!
 	>In 10 years, I will be 31 years old!

 Bad Data case 1 (more than one name)
 	>What is your name? Richard Huntrods
 	>What is your age? 21
 	>Hello! My name is Richard, and I am 21 years old!
 	>In 10 years, I will be 31 years old!
 
 Bad Data case 2 (nonsense or non-alpha name)
 	>What is your name? zb23xx!
 	>What is your age? 21
 	>Hello! My name is zb23xx!, and I am 21 years old!
 	>In 10 years, I will be 31 years old!
 
 Bad Data case 3 (negative age)
 	>What is your name? Richard
 	>What is your age? -1
 	>Hello! My name is Richard, and I am -1 years old!
 	>In 10 years, I will be 9 years old!
 
 Bad Data case 4 (floating point age)
 	>What is your name? Richard
 	>What is your age? 12.5
 	>Hello! My name is Richard, and I am 12 years old!
 	>In 10 years, I will be 22 years old!
 
 Discussion:
 	The program accepts only a single word for the name input (whitespace delimits the word - comma, space, period, etc.)
 	The program also attempts to convert the age input into an integer, even if this produces a nonsense result (i.e. 'five').
 	Negative numbers are allowed and processed as if legitimate, and floating point numbers are truncated.
 
*/

#include <ctime> 
#include <iostream>

using namespace std;

// ----- Loggers

/**
  * Print program result.
  */
void printProgramResult(float result)
{
    cout << "Time taken to run Multiplication Program: " << result << "s" << endl;
}

/**
  * Print program error message.
  */
void printProgramErrorMessaage()
{
    cout << "Program error. Unable to time program." << endl;
}

/**
  * Print program multiplier result.
  */
void printMultiplierResult(int result, int v1, int v2)
{
    cout << result << " = " << v1 << " * " << v2 << endl;
}

// ----- Programs

/**
  * Run program and time.
  */
void program()
{
    time_t now = time(0);

    char* dt = ctime(&now);

    int ARRAY_SIZE = 100;

    int STARTING_VALUE = 10;

    int forwardArray[ARRAY_SIZE];

    int backwardArray[ARRAY_SIZE];

    for (int n = STARTING_VALUE; n < ARRAY_SIZE; n++) {
        forwardArray[n] = n;
        backwardArray[n] = (ARRAY_SIZE - n) - 1;

        const double multiplicationResult = forwardArray[n] * backwardArray[n];

        printMultiplierResult(multiplicationResult, forwardArray[n], backwardArray[n]);
    }
}

/**
  * Run program and time.
  */
float timedProgram()
{

    clock_t start, end, elapsed;
    start = clock();

    program();

    end = clock();
    elapsed = end - start;

    return ((float)elapsed) / CLOCKS_PER_SEC;
}

// ----- Application entry

/**
  * Run program
  */
int main()
{
    try {
        printProgramResult(timedProgram());
    }
    catch (...) {
        printProgramErrorMessaage();
    }
}
