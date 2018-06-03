#include <iostream>
using namespace std;

// ----- Types and Classes

/**
  * StringBuffer class.
  * Holds mutable buffer of string content.
  */
class Hen {

  public:

    void display() {
      cout << "Hen display called \n";
    }
  Hen() {
    cout << "Hen constructor called \n";
  }~Hen() {
    cout << "Hen destructor called \n";
  }

  class Nest
  {
    public:

      void display() {
        cout << "Nest display called \n";
      }
    Nest() {
      cout << "Nest constructor called \n";
    }~Nest() {
      cout << "Nest destructor called \n";
    }

    class Egg

    {
      public:

        void display() {
          cout << "Egg display called \n";
        }
      Egg() {
        cout << "Egg constructor called \n";
      }~Egg() {
        cout << "Egg destructor called \n";
      };
    };
  };
};

// ----- Program definition

/**
  * Question 2 program.
  *
  */
int program () {

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
int main() {
    return program();
}
