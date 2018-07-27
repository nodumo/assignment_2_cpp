
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
 	Write a program that creates a class hierarchy for simple geometry. 

    a. Start with a Point class to hold x and y values of a point. Overload the >>
    operator to print point values and the + and – operators to add and subtract
    point coordinates (hint: keep x and y separate In the calculation). 

    b. Create a base class shape which will form the basis of your shapes. The shape
    class will contain functions to calculate area and circumference of the shape,
    plus provide the coordinates (Points) of a rectangle that encloses the shape (a
    bounding box). These will be overloaded by the derived classes as necessary.
    Create a display() function that will display the name of the class plus all
    stored information about the he class (including area, circumference, and
    bounding box).

 Compile (assuming Cygwin is running): g++ -o GoodDocs GoodDocs.cpp
 Execution (assuming Cygwin is running): ./GoodDocs.exe
 
 Notes: in Cygwin, main must return type int
 
 Classes: 
    Point - Point unit.
    shape - Ubstract class.
    circle- Specialized shape.
    square - Specialized shape.
    triangle - Specialized shape.

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
    Point(int xValue, int yValue)
    {
        x = xValue;
        y = yValue;
    }
    ~Point()
    {
    }
    int getX()
    {
        return x;
    }
    int setX(int xValue)
    {
        x = xValue;
    }
    int getY()
    {
        return y;
    }
    int setY(int yValue)
    {
        y = yValue;
    }
    // ---- Operators 
    Point operator >> (Point& pt);
    Point operator +(Point& pt);
    Point operator -(Point& pt);
};

// (+) Addition operator
Point Point::operator+(Point& pt)
{ 
    Point result = *this;
    result.setX(result.getX() + pt.getX());
    result.setY(result.getY() + pt.getY());
    return result;
};

// (-) Subtration operator
Point Point::operator-(Point& pt)
{
    Point result = *this;
    result.setX(result.getX() - pt.getX());
    result.setY(result.getY() - pt.getY());
    return result;
};



// (-) Subtration operator
Point Point::operator>>(Point& pt)
{
    Point result = *this;
    cout << result.getX() << "\n";
    cout << result.getY() << "\n";
};
/**
  * Question B
  * shape value.
  */
class shape {
    // ---- Private
private:
    /**
      * shape name  
      */
    string SHAPE_NAME;

    // ---- Public
public:

    float getArea();

    string shapeName()
    {
        return SHAPE_NAME;
    }
    /**
      *  Tests if angle abc is a right angle
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */
    int isOrthogonal(Point a, Point b, Point c)
    {
        return (b.getX() - a.getX()) * (b.getX() - c.getX()) + 
               (b.getY() - a.getY()) * (b.getY() - c.getY()) == 0;
    }
};

class rectangle : public shape {
    // ---- Private
private: 
    // ---- Public
public:
    /**
      *  shape constructor.
      *  @param p1 - Point 1.  
      *  @param p2 - Point 2.  
      *  @param p3 - Point 3.   
      *  @param p4 - Point 4. 
      */
    rectangle(Point p1, Point p2, Point p3, Point p4)
    {
        string SHAPE_NAME = "rectangle";
    }

    /**
      *  shape destructor.
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */
    ~rectangle()
    {
    }

    /**
      *  Tests if angle abc is a right angle
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */
    int isValidrectangle(Point a, Point b, Point c, Point d)
    {
        return isOrthogonal(a, b, c) && isOrthogonal(b, c, d) && isOrthogonal(c, d, a);
    }
};


class triangle : public shape {  
    // ---- Private
private: 
    // ---- Public
public:
    /**
      *  shape constructor.
      *  @param p1 - Point 1.  
      *  @param p2 - Point 2.  
      *  @param p3 - Point 3.   
      *  @param p4 - Point 4. 
      */
    triangle(Point p1, Point p2, Point p3, Point p4)
    {
        string SHAPE_NAME = "triangle";
    }

    /**
      *  shape destructor.
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */
    ~triangle()
    {
    }

    /**
      *  Tests if angle abc is a right angle
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */
    int isValidtriangle(Point a, Point b, Point c, Point d)
    {
        return isOrthogonal(a, b, c) && isOrthogonal(b, c, d) && isOrthogonal(c, d, a);
    }
};


class circle: public shape {
    // ---- Private
private: 
    // ---- Public
public:
    /**
      *  shape constructor.
      *  @param p1 - Point 1.  
      *  @param p2 - Point 2.  
      *  @param p3 - Point 3.   
      *  @param p4 - Point 4. 
      */
    circle(Point p1, Point p2, Point p3, Point p4)
    {
       // string SHAPE_NAME = "circle";
    }

    /**
      *  shape destructor.
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */
    ~circle()
    {
    }

    /**
      *  Tests if angle abc is a right angle
      *  @param xValue - X value.  
      *  @param yValue - Y value. 
      */
    int isValidCircle(Point a, Point b, Point c, Point d)
    {
        return isOrthogonal(a, b, c) && isOrthogonal(b, c, d) && isOrthogonal(c, d, a);
    }

}; 

// ----- Programs

/**
  * Run program and time.
  */
void program()
{
    Point point = Point(1,2);
}

// ----- Application entry

/**
  * Run program
  */
int main()
{   
    try {

        program();
    }
    catch (...) {
    }
}
 
