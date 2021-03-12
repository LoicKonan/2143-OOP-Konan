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


RgbColor RgbColor::operator+(const RgbColor &rhs)
{
    int r = (this->r + rhs.r) / 2;
    int g = (this->g + rhs.g) / 2;
    int b = (this->b + rhs.b) / 2;

    return *this;
}

RgbColor::RgbColor()
{
    r = g = b = 0;
}

RgbColor::RgbColor(int color)
{
    r = g = b = color;
}

RgbColor::RgbColor(int _r, int _g, int _b)
{
    r = _r;
    g = _g;
    b = _b;
}

void RgbColor:: SetR(int red)
{
    r = red;
}

void RgbColor::SetG(int green)
{
    g = green;
}

void RgbColor::SetB(int blue)
{
    b = blue;
}

int RgbColor:: GetR()
{
    return r;
}

int RgbColor::GetG()
{
    return g;
}

int RgbColor::GetB()
{
    return b;
}

 void RgbColor::AddColor(RgbColor rgbcolor)
{
	myColors.push_back(rgbcolor);
}



ostream &operator<<(ostream &os, const RgbColor &rhs)
{
    // system("Color 04");
    os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
    return os;
}

vector<RgbColor> RgbColor::myColors;


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