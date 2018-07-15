
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

#include <iostream>

using std::cout; // use for control output to a stream buffer
using std::cin; // use standard input stream
using std::endl; // use standard end line
using std::string; // use standard string

// ----- Utils

/**
  *  Print constructor and destructor.
  *  @param className - Class name. 
  *  @param actionName - Action name. 
  */
void printConstructorAndDestructor(string className, string actionName)
{
    cout << className << " " << actionName << " called." << endl;
}

/**
  *  Print constructor message.
  *  @param className - Class name. 
  */
void printConstructor(string className)
{   string ACTION = "constructor";
    printConstructorAndDestructor(className, "constructor");
}

/**
  *  Print destructor message.
  *  @param className - Class name. 
  */
void printDestructor(string className)
{
    printConstructorAndDestructor(className, "destructor");
}

/**
  *  Print display.
  *  @param className - Class name. 
  */
void printdDisplay(string className)
{
    cout << className << " display called." << endl;
}

// ----- Types and Classes

/**
  * Hen class.
  */
class Hen {
private:
    string HEN_CLASS_NAME = "Hen";

public:
    Hen()
    {
        printConstructor(HEN_CLASS_NAME);
    }
    ~Hen()
    {
        printDestructor(HEN_CLASS_NAME);
    }
    void display()
    {
        printdDisplay(HEN_CLASS_NAME);
    }

    /**
      * Nest class.
      */
    class Nest {
    private:
        string NEST_CLASS_NAME = "Nest";

    public:
        Nest()
        {
            printConstructor(NEST_CLASS_NAME);
        }
        ~Nest()
        {
            printDestructor(NEST_CLASS_NAME);
        }

        void display()
        {
            printdDisplay(NEST_CLASS_NAME);
        }
        /**
          * Nest class.
          */
        class Egg {
        private:
            string EGG_CLASS_NAME = "Hen";

        public:
            Egg()
            {
                printConstructor(EGG_CLASS_NAME);
            }
            ~Egg()
            {
                printDestructor(EGG_CLASS_NAME);
            };
            void display()
            {
                printdDisplay(EGG_CLASS_NAME);
            }
        };
    };
};

// ----- Program definition

/**
  * Question 2 program.
  */
void program()
{ 

    while(true)
{
	cout << "I am inside loop" << endl;
}

    // instantiate classes
    Hen hen;
    Hen::Nest nest;
    Hen::Nest::Egg egg;

    // run display methods
    hen.display();
    nest.display();
    egg.display();
}

// ----- Application entry

/**
  * Run program
  */
int main()
{
    program();
    return 0;
}
