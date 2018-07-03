#include <ctime> 
#include <iostream>

using namespace std;

// ----- Types and Classes 

/**
  * Question A
  */
class Point {
    /**
      * X coordinate.
      */
    int x;
    /**
      * Y coordinate.
      */
    int y;
    // ---- Public
    public: 
        Point(int xValue, int yValue) {
            x = xValue;
            y = yValue;
        }
        ~Point() {
            
        }

};

/**
  * Question B
  */
class Shape {
    /**
      * X coordinate.
      */
    int x;
    /**
      * Y coordinate.
      */
    int y;
    // ---- Public
    public: 
        Shape(int xValue, int yValue) {
            x = xValue;
            y = yValue;
        }
        ~Shape() {
            
        }

};

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
