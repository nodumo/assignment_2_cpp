

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
 	Write a program in which you create a Hen class. Inside this class, nest a Nest
    class. Inside Nest, place an Egg class. Each class should have a display()
    member function. For each class, create a constructor and a destructor that
    prints an appropriate message when it is called. In main(), create an instance
    of each class using new and call the display() function for each one. After
    calling display(), free the storage using delete.

 Compile (assuming Cygwin is running): g++ -o GoodDocs GoodDocs.cpp
 Execution (assuming Cygwin is running): ./GoodDocs.exe  
 
 Notes: in Cygwin, main must return type int
 
 Classes: 
    Hen - Hen outer class. 
    Nest - Nest inner class.
    Egg  - Egg inner-most class.

 Functions:
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

#include <iostream>

using std;
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
