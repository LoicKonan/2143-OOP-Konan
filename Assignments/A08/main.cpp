/**
* Author:              Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Label:            A08
*    Title:            Copy Constructor
*    Course:           CMPS 2143
*    Semester:         Spring 2021
*
*    Description:
*        In this Program we had to Re-write the RgbColor class using a vector to hold all of the rgb colors 
*        so that it stores many colors the new class name is ColorPallette. 
*        Implemented Inheritance with the two main class in order to make sure that they are tightly couples.
*    Usage:
*        - $ ./main filename
*
*    Files:
*          main.cpp    
* 
*/

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;


/**
*    Class Name: RgbColor
*
*    Description:
*        This is an implementation of our single color rgb class.
* 
*    Public Methods:
*
*       ~RgbColor();             // Destructor
*       RgbColor();              // default constructor
*       RgbColor(int);           // overloaded 1
*       RgbColor(int, int, int); // overloaded 2
*
*       void SetR(int);          // setter red
*       void SetG(int);          // setter green
*       void SetB(int);          // setter blue
*
*       int GetR();              // getter red
*       int GetG();              // getter green
*       int GetB();              // getter blue
*
*       void GrayScale();        // averages colors
*
*       void AddColor(RgbColor rgbcolor);
*
*       friend ostream &operator<<(ostream &, const RgbColor &); // print to stdout
*
*       RgbColor operator+(const RgbColor &);   // add (mix) two colors
*
*       static vector<RgbColor> myColors;
*
*        Usage:
*            - Create a class of colors.
*
*/
class RgbColor
{
protected:
    int r;                  // int 0-255 red
    int g;                  // int 0-255 green
    int b;                  // int 0-255 blue


public:
    ~RgbColor();
    RgbColor();              // default constructor
    RgbColor(int);           // overloaded 1
    RgbColor(int, int, int); // overloaded 2

    void SetR(int);          // setter red
    void SetG(int);          // setter green
    void SetB(int);          // setter blue

    int GetR();              // getter red
    int GetG();              // getter green
    int GetB();              // getter blue

    void GrayScale();        // averages colors

    void AddColor(RgbColor rgbcolor);

    friend ostream &operator<<(ostream &, const RgbColor &); // print to stdout

    RgbColor operator+(const RgbColor &);   // add (mix) two colors

    static vector<RgbColor> myColors;
};


/**
 * Public :  RgbColor()
 *
 * Description:
 *           Default Constructor
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - NULL
 */
RgbColor::RgbColor()
{
    r = g = b = 0;
}


/**
 * Public :   ~RgbColor() {}
 *
 * Description:
 *            Destructor
 *
 * Params:
 *          - NONE
 *
 * Returns:
 *          - NULL
 */
RgbColor::~RgbColor() 
{}


/**
 * Public :    GrayScale() 
 * 
 * Description:
 *            - averages colors
 *  
 * Params:
 *            - NONE
 * 
 * Returns:
 *            - void
 */
void RgbColor:: GrayScale()           
{
    b = g = r = ((r + g + b) / 3);    
{


/**
 * Public :    operator+(const RgbColor &rhs) 
 * 
 * Description:
 *            - assignment operator overload that adds values
 *  
 * Params:
 *            - (const RgbColor &rhs
 * 
 * Returns:
 *            - RgbColor
 */
RgbColor RgbColor::operator+(const RgbColor &rhs)
{
    int r = (this->r + rhs.r) / 2;
    int g = (this->g + rhs.g) / 2;
    int b = (this->b + rhs.b) / 2;

    return *this;
}


/**
 * Public :  RgbColor()
 *
 * Description:
 *          - Overload Constructor
 *
 * Params:
 *          - int
 *
 * Returns:
 *          - NULL
 */
RgbColor::RgbColor(int color)
{
    r = g = b = color;
}



/**
 * Public :  RgbColor()
 *
 * Description:
 *          - Overload Constructor
 *
 * Params:
 *          - int, int, int
 *
 * Returns:
 *          - NULL
 */
RgbColor::RgbColor(int _r, int _g, int _b)
{
    r = _r;
    g = _g;
    b = _b;
}


/**
 * RgbColor 
 * 
 */
void RgbColor:: SetR(int red)
{
    r = red;
}


/**
 * RgbColor 
 * 
 */
void RgbColor::SetG(int green)
{
    g = green;
}


/**
 * RgbColor 
 * 
 */
void RgbColor::SetB(int blue)
{
    b = blue;
}


/**
 * RgbColor 
 * 
 */
int RgbColor:: GetR()
{
    return r;
}


/**
 * RgbColor 
 * 
 */
int RgbColor::GetG()
{
    return g;
}


/**
 * RgbColor 
 * 
 */
int RgbColor::GetB()
{
    return b;
}

/**

 * Public : ostream
 * 
 * Description:
 *      overloading the cout operator to print 
 * 
 * Params:
 *      - ostream &os, const const RgbColor &rhs
 * 
 * Returns:
 *      [string] os
 */   
ostream &operator<<(ostream &os, const RgbColor &rhs)
{
    // system("Color 04");
    os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
    return os;
}


 /**
  * RgbColor 
  * 
  */
 void RgbColor::AddColor(RgbColor rgbcolor)
{
	myColors.push_back(rgbcolor);
}

/**
 *
 */
vector<RgbColor> RgbColor::myColors;

/**
 * Main Driver
 * 
 */
int main()
{
    RgbColor newColor1, newColor;

    int red, green, blue;

    cout << "Enter the colors red, green and blue: ";
	cin >> red >> blue >> green;

	newColor.SetR(red);
	newColor.SetG(green);
	newColor.SetB(blue);
    newColor.GetR();
	newColor.GetG();
	newColor.GetB();
    newColor.AddColor(newColor); // Add account to the database
    cout<< newColor <<endl;



    cout << "Enter the colors for the next colorpalette red, green and blue: ";
	cin >> red >> blue >> green;
	newColor1.SetR(red);
	newColor1.SetG(green);
	newColor1.SetB(blue);
    newColor1.GetR();
	newColor1.GetG();
	newColor1.GetB();
	newColor1.AddColor(newColor1); // Add account to the database
    cout<< newColor1 <<endl;
}