#include <iostream>
using namespace std;

// ----- Types and Classes

/**
  * StringBuffer class.
  * Holds mutable buffer of string content.
  */
class Hen
{

public:
    Hen()
    {
        cout << "Hen constructor called" << endl;
    }
    ~Hen()
    {
        cout << "Hen destructor called" << endl;
    }
    void display()
    {
        cout << "Hen display called" << endl;
    }

    class Nest
    {
    public:
        Nest()
        {
            cout << "Nest constructor called" << endl;
        }
        ~Nest()
        {
            cout << "Nest destructor called" << endl;
        }

        void display()
        {
            cout << "Nest display called" << endl;
        }
        class Egg
        {
        public:
            Egg()
            {
                cout << "Egg constructor called" << endl;
            }
            ~Egg()
            {
                cout << "Egg destructor called" << endl;
            };
            void display()
            {
                cout << "Egg display called" << endl;
            }
        };
    };
};

// ----- Program definition

/**
  * Question 2 program.
  *
  */
int program()
{

    Hen hen;
    Hen::Nest nest;
    Hen::Nest::Egg egg;


    hen.display();
    nest.display();
    egg.display();

    return 0;
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
