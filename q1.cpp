
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
 	Write a program to manage dvd rental in a video rental store. Create an abstract
    data type that represents a dvd in this store. Consider all the data and
    operations that may be necessary for the dvd type to work well within a rental
    management system. Include a print() member function that displays all the
    information about the dvd. Test your data type by creating an array of ten dvd
    instances and filling them using information read from a test input file that
    you create. Display the dvd information.

 Compile (assuming Cygwin is running): g++ -o GoodDocs GoodDocs.cpp
 Execution (assuming Cygwin is running): ./GoodDocs.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes:
    dvd 
    dvd_manager

 Functions:
    program (string -> ) Application method
    main (->) Program main method
    
    
 Variables:
 	
*/

/*
 TEST PLAN
   
 Normal case:
 	> 
    6
    7af73174360ff4e03c475449
    Coash
    Kathy Rowland

 Bad Data case 1 (bad file image  [change 'csv_file_namee'  to 'not_text.jpg'])
 	> terminate called after throwing an instance of 'std::out_of_range'
      what():  vector::_M_range_check: __n (which is 2) >= this->size() (which is 1)
      Aborted (core dumped)

 Bad Data case 2 (bad file unexplected input, random garbage  [change 'csv_file_namee'  to 'dvd_garbage.vcsv'])
 	> terminate called after throwing an instance of 'std::out_of_range'
    what():  vector::_M_range_check: __n (which is 2) >= this->size() (which is 1)
    Aborted (core dumped)

 Bad Data case 3 (missing file [change 'csv_file_namee'  to 'node'])
    > terminate called after throwing an instance of 'std::runtime_error'
    what():  Missing file cannot read from:node.
    Aborted (core dumped)

    
 Discussion:
 	The program is partially modelled as a procderal imperative program and partially an object oriented program.
    The procedural part of the program is comprised of the File IO and CSV program.
    The object oriented program is comprised of a class that models dvd and a class that manages the rental of the dvds.
 
    The dvd class models dvd entitites as a contained unit represeting the dvd. 
    This class displays the dvd and uses an internal counter to track instances of the dvd variable.

    The dvd manager class models dvd entitites as a contained unit represeting the dvd.
    The dvd manager is tasked with holding a collection of dvds. The manager leverages the external/global procedural code to 
    populate the dvd manafer from the file. This is a side-effecting constructor that may introduce an error.

*/

#include <iostream> // use Standard Input / Output Streams Library
#include <fstream> // use input/output file stream class
#include <sstream> // use input/output string stream
#include <string> // use string
#include <vector> // use vector
#include <stdio.h> // use C library to perform Input/Output operations

using std::cout; // use for control output to a stream buffer
using std::cin; // use standard input stream
using std::endl; // use standard end line
using std::string; // use standard string
using std::ifstream; // use for input stream class to operate on files.
using std::vector; // vector standard

/**
 * CSV reader  namespace
 */
namespace csv_reader {


/**
   * Read lines in a file.
   * @param file_array_source_name - The name of the file to read
   */
vector<string> read_lines_in_file(string file_array_source_name)
{
    vector<string> list_of_rows;
    string line;
    ifstream ifs(file_array_source_name.c_str());
    if (!ifs) {
        throw std::runtime_error("Missing file cannot read from:" + file_array_source_name + ".");
    }
    while (!ifs.eof()) {
        getline(ifs, line);

        list_of_rows.push_back(line);
    }
    return list_of_rows;
}

/**
   * Read CSV file into vector of CSV columns as vector.
   * @param dvdData - The name of the file to look for.
   */
vector<vector<string> > linesIn_file_to_vector_of_csv_rows_as_vector(vector<string> dvdDat)
{
    vector<vector<string> > listOfCSVRows;
    string delimiter = ",";
    for (int i = 0; i < dvdDat.size(); i++) {
        vector<string> listOfCSVColumns;
        string currentString = dvdDat.at(1);
        size_t pos = 0;
        std::string token;
        while ((pos = currentString.find(delimiter)) != string::npos) {
            token = currentString.substr(0, pos);
            listOfCSVColumns.push_back(token);
            currentString.erase(0, pos + delimiter.length());
        }
        listOfCSVRows.push_back(listOfCSVColumns);
    }
    return listOfCSVRows;
}

vector<string> parse(string test, string delimeter_char)
{
    int count = 0; 
    int token = 0;
    vector<string> parsed;
    for (size_t i = 0; i <= count; i++) {
        string x = (test.substr(token, test.find(delimeter_char, token) - token));
        parsed.push_back(x);
        token += test.find(delimeter_char, token + 1) - (token - 1);
        test.find(delimeter_char, token) != std::string::npos ? count++ : count;
    }
    return parsed;
}
}

// dvd managment namespace
namespace dvd_managment {

using namespace csv_reader;

// ----- Classes
/**
   * dvd value class.
   */
class dvd {
    // Semantically immutable values (i.e no setter)
private:
    /* Tracks instances oft this class */
    static int dvd_counter;
    string title;
    string author;
    string subject;
    int dvd_id;
    /**
     * Construct dvd.
     * @param title_value - Set title value.
     * @param author_value - Set author value.
     * @param subject_value - Set subject_value.
     */
public:
    dvd(string title_value, string author_value, string subject_value)
    {
        title = title_value;
        author = author_value;
        subject = subject_value;
        dvd_id = dvd_counter;
        // static side-effects
        dvd_counter++;
    };
    ~dvd(){
     
    }
    /** 
     * Get dvd title.
     */
    string getTitle()
    {
        return title;
    };
    /**
     * Get dvd author.
     */
    string getAuthor()
    {
        return author;
    };
    /**
     * Get dvd subject.
     */
    string getSubject()
    {
        return subject;
    };
    /**
     * Get dvd id.
     */
    int getDVDId()
    {
        return dvd_id;
    };
    /**
     * Get dvd counter value.
     */
    int getDVDCounterVal()
    {
        return dvd_counter;
    };
    /**
     * Display DVD information
     */
    void display()
    {
        cout << getDVDId() << endl; 
        cout << getTitle() << endl; 
        cout << getAuthor() << endl; 
        cout << getSubject() << endl; 
    };
};

/**
   * dvd_manager construct.
   */
class dvd_manager {

private:
    vector<dvd> dvd_checkout_list;

public:
    /**
       * Construct a dvd manager.
       * @param fileName - The name of the file to look for.
       */
    dvd_manager()
    {
    }
    /**
       * Construct a dvd manager with a list of dvds.
       * @param fileName - The name of the file to look for.
       */
    dvd_manager(vector<dvd> dvdCheckoutList_value)
    {
        dvd_checkout_list = dvdCheckoutList_value;
    }
    /**
       * Get checkout list count.
       */
    int get_dvd_checkout_list_count()
    {
        return dvd_checkout_list.size();
    };
    /**
     * Add dvd to checkout list.
     */
    void add_dvd_to_checkout_listt(dvd dvd)
    {
        dvd_checkout_list.push_back(dvd);
    };
    /**
     * Add dvd(s) to checkout list.
     * @param fileName - The name of the file to look for.
     */
    void add_dvd_to_checkout_listt(vector<dvd> dvdList)
    {
        for (int i = 0; i < dvdList.size(); i++) {
            dvd_checkout_list.push_back(dvdList.at(i));
        }
    };
    /**
     * Remove dvd from checkout list by Id.
     * @param fileName - The name of the file to look for.
     */
    int remove_dvd_from_checkout_list_by_id()
    {
        for (int i = 0; i < dvd_checkout_list.size(); i++) {
            int currentDVD = 1;
        }
        return dvd_checkout_list.size();
    };
    /**
     * Display inventory.
     */
    void display_inventory () { 
        string SEPERATOR = "_____________________________";
        for (int i = 0; i < dvd_checkout_list.size(); i++) {
            cout << SEPERATOR << endl; 
            dvd_checkout_list.at(i).display();
            cout << SEPERATOR << endl; 
        }
    }
};

/**
 * Read CSV file into vector of CSV columns.
 * @param fileName - The name of the file to look for.
 */
dvd_manager build_dvd_manager_from_file(string dvd_file)
{   // helpers 
    string DELIM = ",";
    
    // setup aggregator 
    vector<dvd> list_of_dvds;
    vector<string> csvRowsList = read_lines_in_file(dvd_file);
    vector<vector<string> > csv_parse_rows_list = linesIn_file_to_vector_of_csv_rows_as_vector(csvRowsList);

    for (int i = 0; i < csv_parse_rows_list.size(); i++) {
        string csv_row_as_string = csvRowsList.at(i);
        vector<string> csv_row_as_vector = parse(csv_row_as_string, DELIM);
        dvd dvd(csv_row_as_vector.at(0), csv_row_as_vector.at(1), csv_row_as_vector.at(2));
        list_of_dvds.push_back(dvd);
    }


    dvd_manager dvd_manager(list_of_dvds);
    
    return dvd_manager;
}
}  

using namespace dvd_managment;
using namespace csv_reader;


int dvd::dvd_counter = 0;
  
/**
 * Read CSV file into vector of CSV columns.
 * @param fileName - The name of the file to look for.
 */ 
int main()
{
    string csv_file_namee = "dvd.csv";

    dvd_manager manager = build_dvd_manager_from_file(csv_file_namee);

    manager.display_inventory();
    
    return 0;
}
  