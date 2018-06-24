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
namespace csvreader
{

/**
   * Read lines in a file.
   * @param fileArraySourceName - The name of the file to read
   */
vector<string> readLinesInFile(string fileArraySourceName)
{
    vector<string> listOfRows;
    string line;
    ifstream ifs(fileArraySourceName.c_str());
    if (!ifs)
    {
        throw std::runtime_error("Missing file cannot read from:" + fileArraySourceName + ".");
    }
    while (!ifs.eof())
    {
        getline(ifs, line);

        listOfRows.push_back(line);
    }
    return listOfRows;
}

/**
   * Read CSV file into vector of CSV columns as vector.
   * @param dvdData - The name of the file to look for.
   */
vector<vector<string> > linesInFileToVectorOfCSVRowsAsVector(vector<string> dvdDat)
{
    vector<vector<string> > listOfCSVRows;
    string delimiter = ",";
    for (int i = 0; i < dvdDat.size(); i++)
    {
        vector<string> listOfCSVColumns;
        string currentString = dvdDat.at(1);
        size_t pos = 0;
        std::string token;
        while ((pos = currentString.find(delimiter)) != string::npos)
        {
            token = currentString.substr(0, pos);
            listOfCSVColumns.push_back(token);
            currentString.erase(0, pos + delimiter.length());
        }
        listOfCSVRows.push_back(listOfCSVColumns);
    }
    return listOfCSVRows;
}

vector<string> parse(string test, string Deli)
{
    int count = 0;
    int token = 0;
    vector<string> parsed;
    for (size_t i = 0; i <= count; i++)
    {
        string x = (test.substr(token, test.find(Deli, token) - token));
        parsed.push_back(x);
        token += test.find(Deli, token + 1) - (token - 1);
        test.find(Deli, token) != std::string::npos ? count++ : count;
    }
    return parsed;
}
}

// DVD managment namespace
namespace dvdManagment
{

using namespace csvreader;

// ----- Classes
/**
   * DVD value class.
   */
class DVD
{
    // Semantically immutable values (i.e no setter)
private:
    /* Tracks instances oft this class */
    static int dvdCounter;
    string title;
    string author;
    string subject;
    int dvdId;
    /**
     * Construct DVD.
     * @param titleValue - Set title value.
     * @param authorValue - Set author value.
     * @param subjectValue - Set subjectValue.
     */
public:
    DVD(string titleValue, string authorValue, string subjectValue)
    {
        title = titleValue;
        author = authorValue;
        subject = subjectValue;
        dvdId = dvdCounter;
        // static side-effects
        dvdCounter++;
    };
    /**
     * Get DVD title.
     */
    string getTitle()
    {
        return title;
    };
    /**
     * Get DVD author.
     */
    string getAuthor()
    {
        return author;
    };
    /**
     * Get DVD subject.
     */
    string getSubject()
    {
        return subject;
    };
    /**
     * Get DVD id.
     */
    int getDVDId()
    {
        return dvdId;
    };
    /**
     * Get DVD counter value.
     */
    int getDVDCounterVal()
    {
        return dvdCounter;
    };
};

/**
   * DVDManager construct.
   */
class DVDManager
{

private:
    vector<DVD> dvdCheckoutList;

public:
    /**
       * Construct a DVD manager.
       * @param fileName - The name of the file to look for.
       */
    DVDManager()
    {
    }
    /**
       * Construct a DVD manager with a list of dvds.
       * @param fileName - The name of the file to look for.
       */
    DVDManager(vector<DVD> dvdCheckoutListValue)
    {
        dvdCheckoutList = dvdCheckoutListValue;
    }
    /**
       * Get checkout list count.
       */
    int getDVDCheckoutListCount()
    {
        return dvdCheckoutList.size();
    };
    /**
     * Add DVD to checkout list.
     */
    void addDVDTOCheckoutList(DVD dvd)
    {
        dvdCheckoutList.push_back(dvd);
    };
    /**
     * Add DVD(s) to checkout list.
     * @param fileName - The name of the file to look for.
     */
    void addDVDTOCheckoutList(vector<DVD> dvdList)
    {
        for (int i = 0; i < dvdList.size(); i++)
        {
            dvdCheckoutList.push_back(dvdList.at(i));
        }
    };
    /**
     * Remove DVD from checkout list by Id.
     * @param fileName - The name of the file to look for.
     */
    int removeDVDFromCheckoutListById()
    {
        for (int i = 0; i < dvdCheckoutList.size(); i++)
        {
            int currentDVD = 1;
        }
        return dvdCheckoutList.size();
    };
};

/**
*Read CSV file into vector of CSV columns.
*@param fileName - The name of the file to look for.
*/
DVDManager buildDVDManagerFromFile(string dvdFile)
{
    string DELIM = ",";

    vector<DVD> listOfDVDs;
    vector<string> csvRowsList = readLinesInFile(dvdFile);
    vector<vector<string> > csvParseRowsList = linesInFileToVectorOfCSVRowsAsVector(csvRowsList);

    for (int i = 0; i < csvParseRowsList.size(); i++)
    {
        string csvRowAsString = csvRowsList.at(i);
        vector<string> csvRowAsVector = parse(csvRowAsString, DELIM);
        DVD dvd(csvRowAsVector.at(0), csvRowAsVector.at(1), csvRowAsVector.at(2));
        listOfDVDs.push_back(dvd);
    }
    DVDManager dvdManager(listOfDVDs);
    return dvdManager;
}
}

using namespace dvdManagment;
using namespace csvreader;

int DVD::dvdCounter = 1;

/**
 * Read CSV file into vector of CSV columns.
 * @param fileName - The name of the file to look for.
 */
int main()
{
    string CSVFileName = "dvd.csv";

    DVDManager dvdManager = buildDVDManagerFromFile(CSVFileName);

    /*
    for (unsigned int i = 0; i < csvRowsList.size(); i++) {
        cout << "DVD 1 title : " << endl;
    } */
    cout << "DVD 1 title : " << endl;
    return 0;
}
