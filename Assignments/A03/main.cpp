/****************************************************************************
*
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Label:            Basic Project Organization Commenting C++ code
*    Title:            Linked List Comments
*    Course:           CMPS 3013
*    Semester:         Spring 2021
*    Description:
*        Program create a Linked List with various Nodes.
*        This program implements a class that allows a linked list
*        to be used just like an array. It "push" items onto the end of the 
*        list as well as "pop" items off.
*    Usage:
*        - $ ./main filename
*
*    Files:
*          main.cpp    
*
****************************************************************************/


#include <iostream>

using namespace std;


/*
*    Class Name: CircularArrayQue
*    Description:
*        This class implements a linked list with various methods
*        such as push and pop to add or remove nodes from the list.
*        
*    Public Methods:
*        - CircularArrayQue() - default constructor
*        - CircularArrayQue(int size)  - Programmer Define constructor
*        - void Push(int item)
*        - int Pop()
*        - friend ostream &operator<<(ostream &os,const CircularArrayQue &other)

*    Private Methods:
*        - void init(int size = 0) 
*        - bool Full()

*    Usage:
*        - Create a class object of a Linked List
*        - insert or delete nodes from the Linked List

*/
class CircularArrayQue
{
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize;        // items in the queue
    int CurrentSize;


/**
 * Private :  void init
 *
 * Description:
 *            
 *
 * Params:
 *          - int size = 0
 *
 * Returns:
 *          - NULL
 */
    void init(int size = 0)
    {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

/**
 * Private :  bool Full
 *
 * Description:
 *            
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - [bool] CurrentSize == QueSize
 */
    bool Full()
    {
        return CurrentSize == QueSize;
    }


public:
/**
 * Public :  CircularArrayQue
 *
 * Description:
 *            Default Constructor
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - NULL
 */
    CircularArrayQue()
    {
        Container = new int[10];    // allocate new memory
        init(10);
    }


/**
 * Public :   CircularArrayQue
 *
 * Description:
 *            Default Constructor
 *
 * Params:
 *          - int size
 *
 * Returns:
 *          - NULL
 */
    CircularArrayQue(int size)
    {
        Container = new int[size];    // allocate new memory
        init(size);
    }

/**
 * Public : Push
 * 
 * Description:
 *            allocate new memory and init node
 *  
 * Params:
 *          - int item
 * 
 * Returns:
 *          - void
 */
    void Push(int item)
    {
        if (!Full())
        {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        }
        else
        {
            cout << "FULL!!!!" << endl;
        }
    }

/**
 * Public : Pop
 * 
 * Description:
 *      Remove a node
 * 
 * Params:
 *      - None
 * 
 * Returns:
 *      [int] temp
 */

    int Pop()
    {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }

    // Prototye for the overloading the cout
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

/**
 * Public : ostream
 * 
 * Description:
 *      overloading the cout operator to print a List object
 * 
 * Params:
 *      - ostream &os, const CircularArrayQue &other
 * 
 * Returns:
 *      [string] os
 */
ostream &operator<<(ostream &os, const CircularArrayQue &other)
{

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize)
    {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 */
int main()
{
    CircularArrayQue C1(5); // Declare Linked List object.
    C1.Push(1);
    C1.Push(2);
    C1.Push(3);

    cout << C1 << endl; // Display on the screen

    cout << C1 << endl;
}