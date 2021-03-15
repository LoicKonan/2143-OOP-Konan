/**
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Label:            A08
*    Title:            Copy Constructor
*    Course:           CMPS 2143
*    Semester:         Spring 2021
*
*    Description:
*        In this Program we had to Re-write the RgbColor class to hold many colors,
*        and store the different colors in a dynamically allocated structure
*        this new class name is ColorPallette. Also added a system command to make the 
*        console Text output to change color by using a random number generator and 
*        deciding which color to apply.
*        The console output text will differ bettween these following colors:
*        Red, Green, Blue and the standard color white.
*
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
#include <ctime>

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
*       friend ostream &operator<<(ostream &, const RgbColor &);
*
*       RgbColor operator+(const RgbColor &); 
*
*       static vector<RgbColor> myColors;
*
*       Usage:
*            - Create a class of colors.
*
*/
class RgbColor
{
protected:
    int r; // int 0-255 red
    int g; // int 0-255 green
    int b; // int 0-255 blue

public:
    ~RgbColor();
    RgbColor();              // default constructor
    RgbColor(int);           // overloaded 1
    RgbColor(int, int, int); // overloaded 2

    void SetR(int); // setter red
    void SetG(int); // setter green
    void SetB(int); // setter blue

    int GetR(); // getter red
    int GetG(); // getter green
    int GetB(); // getter blue

    void GrayScale(); // averages colors

    friend ostream &operator<<(ostream &, const RgbColor &); // print to stdout

    RgbColor operator+(const RgbColor &); // add (mix) two colors
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
RgbColor::~RgbColor() {}

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
void RgbColor::GrayScale()
{
    b = g = r = ((r + g + b) / 3);
}

/**
 * Public :    operator+(const RgbColor &rhs) 
 * 
 * Description:
 *            - assignment operator overload that adds values.
 *  
 * Params:
 *            - (const RgbColor &rhs)
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
 * Public :  SetR(int red)
 *
 * Description:
 *          - setter for red
 *
 * Params:
 *          - int
 *
 * Returns:
 *          - NULL
 */
void RgbColor::SetR(int red)
{
    r = red;
}

/**
 * Public :  SetG(int green)
 *
 * Description:
 *          - setter for green
 *
 * Params:
 *          - int
 *
 * Returns:
 *          - NULL
 */
void RgbColor::SetG(int green)
{
    g = green;
}

/**
 * Public :  SetB(int blue)
 *
 * Description:
 *          - setter for blue
 *
 * Params:
 *          - int
 *
 * Returns:
 *          - NULL
 */
void RgbColor::SetB(int blue)
{
    b = blue;
}

/**
 * Public :  GetR()
 *
 * Description:
 *          - Getter for Red
 * Params:
 *          - none
 *
 * Returns:
 *          - int
 */
int RgbColor::GetR()
{
    return r;
}

/**
 * Public :  GetG()
 *
 * Description:
 *          - Getter for Green
 * Params:
 *          - none
 *
 * Returns:
 *          - int
 */
int RgbColor::GetG()
{
    return g;
}

/**
 * Public :  GetB()
 *
 * Description:
 *          - Getter for Blue
 * Params:
 *          - none
 *
 * Returns:
 *          - int
 */
int RgbColor::GetB()
{
    return b;
}

/**

 * Public : ostream
 * 
 * Description:
 *      overloading the cout operator to print the colors
 *      I also added a system command to change the output of the console.
 * 
 * Params:
 *      - ostream &os, const const RgbColor &rhs
 * 
 * Returns:
 *      [string] os
 */
ostream &operator<<(ostream &os, const RgbColor &rhs)
{
    // I added 3 system command below to change the color of the ouput on your console.
    srand((unsigned)time(0));
    int i;
    i = (rand() % 4);

    if (i == 1)
    {
        system("Color 0A"); // Will display Green
        return os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
    }
    else if (i == 2)
    {
        system("Color 0C"); // Will display Red
        return os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
    }
    else if (i == 3)
    {
        system("Color 09"); // Will display Blue
        return os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
    }
    else
        system("Color 07"); // Will display white
        return os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
}

/**
*    Class Name: ColorPallette
*
*    Description:
*         class to hold many colors, and store them in a 
*         dynamically allocated structure.
* 
*    Public Methods:
*
*       ~ColorPallette();
*       ColorPallette();
*       ColorPallette(int s);
*       ColorPallette(const ColorPallette &other);
*
*       Usage:
*            - To store many colors.
*
*/
class ColorPallette
{
protected:
    RgbColor *array; // int pointer (dynamic memory)
    int size;

public:
    ~ColorPallette();
    ColorPallette();
    ColorPallette(int s);
    ColorPallette(const ColorPallette &other);
};

/**
 * Public :  ColorPallette()
 *
 * Description:
 *          - Default Constructor
 *
 * Params:
 *          - none
 *
 * Returns:
 *          - NULL
 */
ColorPallette::ColorPallette()
{
    size = 100;
    array = new RgbColor[size];
}

/**
 * Public :  ColorPallette()
 *
 * Description:
 *          - Destructor
 *
 * Params:
 *          - none
 *
 * Returns:
 *          - NULL
 */
ColorPallette::~ColorPallette() {}

/**
 * Public :  ColorPallette()
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
ColorPallette::ColorPallette(int s)
{
    size = s;
    array = new RgbColor[size];
}

/**
 * Public :  ColorPallette(const ColorPallette &other)
 *
 * Description:
 *          - overload construtor
 *
 * Params:
 *          - const ColorPallette &other
 *
 * Returns:
 *          - NULL
 */
ColorPallette::ColorPallette(const ColorPallette &other)
{
    size = other.size;
    array = new RgbColor[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = other.array[i];
    }
}

/**
 * Main Driver
 * 
 */
int main()
{
    RgbColor newColor;

    RgbColor Color1(255, 200, 11);
    RgbColor Color2(100, 14, 123);
    RgbColor Color3 = Color1 + Color2;
    cout << Color3 << endl
         << endl;

    // Prompt the user to enter is own set of colors.
    int red, green, blue;
    cout << "Enter the colors red, green and blue\n";
    cin >> red >> blue >> green;

    newColor.SetR(red);
    newColor.SetG(green);
    newColor.SetB(blue);
    newColor.GetR();
    newColor.GetG();
    newColor.GetB();

    // Display the color that the user picked.
    cout << newColor << endl;
}