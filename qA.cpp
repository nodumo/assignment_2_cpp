
#include <ctime>
#include <iostream>

using namespace std;

// ----- Loggers

/**
  *  Multiply values.
  *  @param v - Value. 
  */ 
float multiplyNumbers(float v, float v2)
{
    return v * v2;
}

/**
  *  Print program result.
  *  @param programResutl - Program result. 
  */
void printProgramResult(float result)
{
    string TIME_TAKE_TO_RUN_MSG = "Time taken to run Multiplication Program: ";
    cout << TIME_TAKE_TO_RUN_MSG << result << "s" << endl;
}

/**
  *  Print program error message.
  */
void printProgramErrorMessaage()
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
void printMultiplierResult(int result, int v1, int v2)
{
    cout << result << " = " << v1 << " * " << v2 << endl;
}

// ----- Programs

/**
  * Run program and time.
  */
void program(bool isDebugMode, float arraySize, float startingValue)
{
    // range related values 
    int ARRAY_SIZE = arraySize;
    int STARTING_VALUE = startingValue;
    
    // forward iteration array and backward iteration array 
    int forwardArray[ARRAY_SIZE];
    int backwardArray[ARRAY_SIZE];

    for (int n = STARTING_VALUE; n < ARRAY_SIZE; n++) {
        forwardArray[n]  = n;
        backwardArray[n] = (ARRAY_SIZE - n) - 1;
        const int multiplicationResult = multiplyNumbers(forwardArray[n], backwardArray[n]);
        if (isDebugMode){
            printMultiplierResult(multiplicationResult, forwardArray[n], backwardArray[n]);
        }
    }
}

/**
  * Run program and time.
  */
float timedProgram(bool isDebugMode)
{

    clock_t start, end, elapsed;
    start = clock();

    program(isDebugMode, 10000, 100); // run the program and time it

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
        printProgramResult(timedProgram(true));
    }
    catch (...) {
        printProgramErrorMessaage();
    }
}
