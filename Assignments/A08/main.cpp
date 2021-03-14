/**
 * 
 */

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

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
 *  Destructor ~RgbColor()
 */

RgbColor::~RgbColor() {}

/**
 * RgbColor 
 * 
 * @param  {RgbColor} rhs : 
 * @return {RgbColor}     : 
 */
RgbColor RgbColor::operator+(const RgbColor &rhs)
{
    int r = (this->r + rhs.r) / 2;
    int g = (this->g + rhs.g) / 2;
    int b = (this->b + rhs.b) / 2;

    return *this;
}


/**
 * RgbColor::RgbColor 
 * 
 */
RgbColor::RgbColor()
{
    r = g = b = 0;
}


/**
 * RgbColor::RgbColor 
 * 
 * @param  {int} color : 
 */
RgbColor::RgbColor(int color)
{
    r = g = b = color;
}


/**
 * RgbColor::RgbColor 
 * 
 * @param  {int} _r : 
 * @param  {int} _g : 
 * @param  {int} _b : 
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
 * @param  {int} red : 
 */
void RgbColor:: SetR(int red)
{
    r = red;
}


/**
 * RgbColor 
 * 
 * @param  {int} green : 
 */
void RgbColor::SetG(int green)
{
    g = green;
}


/**
 * RgbColor 
 * 
 * @param  {int} blue : 
 */
void RgbColor::SetB(int blue)
{
    b = blue;
}


/**
 * RgbColor 
 * 
 * @return {int}  : 
 */
int RgbColor:: GetR()
{
    return r;
}


/**
 * RgbColor 
 * 
 * @return {int}  : 
 */
int RgbColor::GetG()
{
    return g;
}


/**
 * RgbColor 
 * 
 * @return {int}  : 
 */
int RgbColor::GetB()
{
    return b;
}

/**
 * 
 * @param  {ostream} os   : 
 * @param  {RgbColor} rhs : 
 * @return {ostream}      : 
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
  * @param  {RgbColor} rgbcolor : 
  */
 void RgbColor::AddColor(RgbColor rgbcolor)
{
	myColors.push_back(rgbcolor);
}

/**
 * 
 * @param  {v []} undefined : 
 */
vector<RgbColor> RgbColor::myColors;



/**
 * 
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