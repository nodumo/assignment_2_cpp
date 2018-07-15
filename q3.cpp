
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
    StringBuffer(){

    };

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
            throw std::runtime_error(buildMissingFileExceptionMessage(file));
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

    cout << "stringBuffer1: \n '" << stringBuffer1.getRawString() << "'" << endl;
    cout << "stringBuffer2: \n '" << stringBuffer2.getRawString() << "'" << endl;

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
