#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

/**
 * This class is a simple bare bones example showing use of a copy constructor
 * for the question on the exam.
 * 
 */
class NumContainer
{
    int *array; // int pointer (dynamic memory)
    int size;

public:
    ~NumContainer();
    NumContainer()
    {
        size = 100;
        array = new int[size];
    }
    NumContainer(int s)

    {
        size = s;
        array = new int[size];
    }
    NumContainer(const NumContainer &other)
    {
        size = other.size;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = other.array[i];
        }
    }
};

/**
 *  Destrurctor ~NumContainer()
 */
NumContainer::~NumContainer() {}

/**
 * This is an implementation of our single color rgb class. 
 * 
 */
class RgbColor
{
protected:
    int r; //int 0-255 red
    int g; //int 0-255 green
    int b; //int 0-255 blue


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

    void AddColor(RgbColor rgbcolor);

    // print to stdout
    friend ostream &operator<<(ostream &, const RgbColor &);

    // add (mix) two colors
    RgbColor operator+(const RgbColor &);

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

ostream &operator<<(ostream &os, const RgbColor &rhs)
{
    //system("Color 04");
    os << "[" << rhs.r << "," << rhs.g << "," << rhs.b << "]";
    return os;
}



vector<RgbColor> RgbColor::myColors;


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

int main()
{
    RgbColor newColor;
    int red, green, blue;


	newColor.SetR(30);
	newColor.SetR(21);
	newColor.SetR(111);


    cout << "Enter the colors red, green and blue: ";
	cin >> red >> blue >> green;
	cin.get();
	cout << '\n';

	newColor.SetR(red);
	newColor.SetG(green);
	newColor.SetB(blue);
	// Add account to the database
	newColor.AddColor(newColor);

}