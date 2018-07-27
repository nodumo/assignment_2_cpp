
/* 
    Title: StringBuffer.cpp
    Description: Program for question 
    Date: July 15, 2018
    Author: Nickanor Odumo
    Version: 1.0
    Copyright: 2018 Nickanor Odumo
*/

/*
 DOCUMENTATION
 
 Program Purpose:
 	Write a program in which you create a Text class that contains a string object
    to hold the text of a file. Give it two constructors: a default constructor and
    a constructor that takes a string argument that is the name of the file to open.
    When the second constructor is used, open the file and read the contents of the
    file into the string member object. Add a member function contents() to return
    the string so that you can display it. In main(), open a file using Text and
    display the contents.

 Compile (assuming Cygwin is running): g++ -o StringBuffer StringBuffer.cpp
    Execution (assuming Cygwin is running): ./StringBuffer.exe
 
 Notes: in Cygwin, main must return type intz
 
 Classes: 
    StringBuffer

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
#include <string>
#include <fstream>

using namespace std;

/**
  * StringBuffer class.
  * Holds mutable buffer of string content.
  */
class StringBuffer
{
private:
    // Internal mutable store for strings
    string text;

public:
    /**
      * Construct with empty string.
      * @return void Side effecting function.
      */
    StringBuffer(){};

    /**
      * Constuct with file as data.
      * @param file File to populate object with.
      * @return void Side effecting function.
      */
    StringBuffer(string file)
    {
        string line;
        ifstream srcFile(file.c_str());
        if (!srcFile)
        {
            throw runtime_error(buildMissingFileExceptionMessage(file));
        }
        if (srcFile.is_open())
        {  
            while (getline(srcFile, line))
            {
                text += line + '\n';
            }
            srcFile.close();
        }
    };

    /**
      * Get raw string data.
      * @return void Side effecting function.
      */
    string getRawString()
    {
        return text;
    } 

    /**
      * Log context. 
      * Log buffer content and prepend the context of which entity's content is being logged.
      */
    void logRawString(string context)
    {
        cout << context << "\n '" << getRawString() << "'" << endl;
    }

    /**
      * Build missing file exception message.
      * @return void Side effecting function.
      */
    string buildMissingFileExceptionMessage(string file)
    {
        return ("Missin file exception: Cannot read and stream from: '" + file + "'.");
    }
};

// ----- Program definition

/**
  * Question 3 program.
  * Read create string buffer objects with both constructor and output text.
  */
int program(string testFile)
{
    StringBuffer stringBuffer1;
    StringBuffer stringBuffer2(testFile);

    stringBuffer1.logRawString("stringBuffer1");
    stringBuffer2.logRawString("stringBuffer2");
    
    return 0;
}
  
// ----- Application entry

/**
  * Run program
  */
int main()
{
    string TEST_FILE = "dvd.csv";

    return program(TEST_FILE);
}
