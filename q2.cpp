

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
 	>   Hen constructor called.
        Nest constructor called.
        Hen constructor called.
        Hen display called.
        Nest display called.
        Hen display called.
        Hen destructor called.
        Nest destructor called.
        Hen destructor called.
        
 Bad Data case 2 (delete hen variable, not pointer'delete hen')
 	> 
    *** Error in `./main': double free or corruption (out): 0x00007ffd9b96b940 ***
    ======= Backtrace: =========
    /lib/x86_64-linux-gnu/libc.so.6(+0x777e5)[0x7f89a42877e5]
    /lib/x86_64-linux-gnu/libc.so.6(+0x8037a)[0x7f89a429037a]
    /lib/x86_64-linux-gnu/libc.so.6(cfree+0x4c)[0x7f89a429453c]
    ./main[0x40104c]
    ./main[0x4010d6]
    /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7f89a4230830]
    ./main[0x400c19]
    ======= Memory map: ========
    00400000-00402000 r-xp 00000000 08:05 16287602                           
    00601000-00602000 r--p 00001000 08:05 16287602    

 Discussion:
 	Implemented nesting doll style classes. Each class is nested within another. 
    Implemented a program function to run application logic for question 2.  
    Implemented a main method to call program method. 

    Classes create nested scopes as they are embedded. This requires using special syntax to access nested scopes.
    Classes all have an internal name.
    Classes all have constructors and destructors that use the nested class name.

    The delete method was the most challenging pointers and references in C++ are a challenging concept to grasp.
    C++ accesor rules are not easy to understand and thus require some patience.

    To debug use the utility method to halt executiomn. This way you can see the delete method executed and the destructor
    run before the program exits. This is not neccesary for the program source but I wanted to be transparent.
*/

#include <iostream>
#include <unistd.h>

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
  * Hand the program to debug program.
  * Hangs the program so the user can debug the program's execution.
  * C++ executes so fast that to debug execution you need to halt progress.
  */
void hang_program_to_debug()
{
    sleep(5);
}


/**
  * Question 2 program.
  */
void program(bool is_debug)
{ 

    // instantiate classes
    Hen* hen = new Hen;
    Hen::Nest* nest = new Hen::Nest;
    Hen::Nest::Egg* egg = new Hen::Nest::Egg;


    // run display methods
    hen->display();
    nest->display();
    egg->display(); 

    delete hen;
    delete nest;
    delete egg;
    
    if(is_debug)hang_program_to_debug();

}

// ----- Application entry 
 
/**
  * Run program
  */
int main()
{
    program(true); 
    return 0;
}
