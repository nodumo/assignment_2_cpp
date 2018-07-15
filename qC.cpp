
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

#include <ctime> 
#include <iostream>
#include <cmath>

using namespace std;

// ----- Types and Classes 

/**
  * Question A
  * Cartesian coordinate value.
  */
class Point {
    /**
      * X coordinate.
      */
    int x;
    /**
      * Y coordinate.
      */
    int y;
    // ---- Public
    public: 
        Point(int xValue, int yValue) {
            x = xValue;
            y = yValue;
        }
        ~Point() {
            
        } 
        int getX(){
            return x;
        }
        int setX(int xValue) {
            x = xValue; 
        }
        int getY(){
            return y;
        }
        int setY(int yValue) { 
            y = yValue;
        }

        Point operator+(Point& pt);
	 	Point operator-(Point& pt);
};


// + Operator Overload   Works   
Point Point::operator + (Point& pt) {
	Point result = *this;
	result.setX(result.getX() + pt.getX());
	result.setY (result.getY() + pt.getY());
	return result; 
};

// + Operator Overload   Works   
Point Point::operator - (Point& pt) {
	Point result = *this;
	result.setX(result.getX() - pt.getX());
	result.setY (result.getY() - pt.getY());
	return result; 
};

/**
  * Question B
  * Shape value.
  */
class Shape {   
    // ---- Private  
    private:
    /**
      * Shape name  
      */
    string SHAPE_NAME;
  
    // ---- Public
    public: 

    string shapeName () {
        return SHAPE_NAME;
    }

};

class Rectangle: public Shape {
    // ---- Private 
    private:
 
    // ---- Public
    public: 
    
    /**
      *  Shape constructor.
      *  @param p1 - Point 1.  
      *  @param p2 - Point 2.  
      *  @param p3 - Point 3.   
      *  @param p4 - Point 4. 
      */ 
    Rectangle(Point p1, Point p2, Point p3, Point p4) {
        string SHAPE_NAME = "Rectangle";
    }  
    
    /**
      *  Shape destructor.
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */ 
    ~Rectangle() {
        
    }

    /**
      *  Tests if angle abc is a right angle
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */ 
    int isOrthogonal(Point a, Point b, Point c)
    {
        return (b.getX() - a.getX()) * (b.getX() - c.getX()) + (b.getY() - a.getY()) * (b.getY() - c.getY()) == 0;
    }

    /**
      *  Tests if angle abc is a right angle
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */ 
    int isValidRectangle(Point a, Point b, Point c, Point d)
    {
        return
            isOrthogonal(a, b, c) &&
            isOrthogonal(b, c, d) &&
            isOrthogonal(c, d, a);
    }

};

// ----- Loggers

// ----- Programs

/**
  * Run program and time.
  */
void program()
{

}

// ----- Application entry

/**
  * Run program
  */
int main()
{
    try {
          cout << 1 << endl;
    }
    catch (...) {
       
    }
}
