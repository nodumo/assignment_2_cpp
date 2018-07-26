/* 
    Title: GoodDocs.cpp
    Description: Program for question 
    Date: July 15, 2018
    Author: Nickanor Odumo
    Version: 1.0
    Copyright: 2018 Nickanor Odumo
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Rewrite program 1 using an inline function to perform the calculation. In the
    test plan for this program (actual results section), compare the time required
    by this program to execute against the time required by the first (non-inline)
    program.

 Compile (assuming Cygwin is running): g++ -o GoodDocs GoodDocs.cpp
 Execution (assuming Cygwin is running): ./GoodDocs.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes: none

 Functions:
    program (string -> ) Application method
    main (->) Program main method
    program (string -> ) Application method
    main (->) Program main method 
    program (string -> ) Application method
    main (->) Program main method

 	
 Variables:
 	 	
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
  *  Multiply values.
  *  @param v1 - Value1. 
  *  @param v2 - Value2. 
  */ 
float multiply_numbers(float v1, float v2)
{
    return v1 * v2;
}

/**
  *  Print program result.
  *  @param programResutl - Program result. 
  */
void print_program_result(float result)
{
    string TIME_TAKE_TO_RUN_MSG = "Time taken to run Multiplication Program: ";
    cout << TIME_TAKE_TO_RUN_MSG << result << "s" << endl;
}

/**
  *  Print program error message.
  */
void print_program_error_message()
{
    string PROGRAM_ERROR_MSG = "Program error. Unable to time program.";
    cout << PROGRAM_ERROR_MSG << endl;
}

/**
  *  Print multiplication result.
  *  @param result - Multuplication result. 
  *  @param v1 - Value 1. 
  *  @param v2 - Value 2.
  */
void print_multiplier_result(int result, int v1, int v2)
{
    cout << result << " = " << v1 << " * " << v2 << endl;
}

// ----- Programs

/**
  *  Run program and time.
  *  @param result - Multuplication result. 
  *  @param v1 - Value 1. 
  *  @param v2 - Value 2.
  */
void program(bool is_debug_mode, float array_size, float starting_value)
{
    // range related values 
    int ARRAY_SIZE = array_size;
    int STARTING_VALUE = starting_value;
    
    // forward iteration array and backward iteration array 
    int forward_array[ARRAY_SIZE];
    int backward_array[ARRAY_SIZE];

    for (int n = STARTING_VALUE; n < ARRAY_SIZE; n++) {
        // build up array 
        forward_array[n]  = n;
        backward_array[n] = (ARRAY_SIZE - n) - 1;
   
        // multiplication result 
        const int multiplication_result = multiply_numbers(forward_array[n], backward_array[n]);
   
        // if debug mode go ahead and log the result
        if (is_debug_mode){
            print_multiplier_result(multiplication_result, forward_array[n], backward_array[n]);
        }
    }
}

/**
  * Run program and time,
  */
float timed_program(bool is_debug_mode)
{

    clock_t start, end, elapsed;
    start = clock();

    program(is_debug_mode, 10000, 100); // run the program and time it

    end = clock();
    elapsed = end - start;

    return ((float)elapsed) / CLOCKS_PER_SEC;
}

// ----- Application entry

/**
  * Run program
  */
int main()
{   bool IS_DEBUG = true;
    try {
        print_program_result(timed_program(IS_DEBUG));
    }
    catch (...) {
        print_program_error_message();
    }
}
