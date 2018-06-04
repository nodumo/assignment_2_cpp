#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
  * StringBuffer class.
  * Holds mutable buffer of string content.
  */
class StringBuffer {

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
        ifstream srcFile (file.c_str());
        if (!srcFile) {
            throw std::runtime_error(buildMissingFileExceptionMessage(file));
        }
        if (srcFile.is_open())
        {
           while (getline(srcFile,line))
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
int program (string testFile) {
    StringBuffer stringBuffer1;
    StringBuffer stringBuffer2 (testFile);

    cout << "stringBuffer1: \n '" << stringBuffer1.getRawString() << "'" << endl;
    cout << "stringBuffer2: \n '" << stringBuffer2.getRawString() << "'" << endl;

    return 0;
}

// ----- Application entry

/**
  * Run program
  */
int main() {

    string TEST_FILE = "dvd.csv";

    return program(TEST_FILE);
}
