/*****************************************************************************
*
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Author:           Ethan Coyle
*    Email:            Ejcoyle0912@my.msutexas.edu
*
*    Label:            P02
*    Title:            Program 02 - Graphviz Class
*    Course:           CMPS 2143
*    Semester:         Spring 2021
*
*    Description:
*                      This Program is about implementing a **graphviz Language 
*                      "wrapper" or "facade"**.
*                      This means we will be implementing a (tiny) **subset** of 
*                      the graphviz language capability so we can visualize some
*                      of the typical data structures that will show all the 
*                      countries of the world with a distance needed to travel to
*                      or from each other.
*    Files:
*         main.cpp
*         output.txt
*         input.txt
*
*    Usage:
*           main.cpp          : driver program
*           input.txt         : Input file
*           output.txt        : output file
*
******************************************************************************/
#include<sstream>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>

using namespace std;

//Function prototypes to read from and write to a file.
void openFiles(ifstream& InFile, ofstream& OutFile);

/*
 *    Struct Name: LinkedNodes
 * 
 *   Description:
 *       - Holds The countries  names.
 *       - And the edges between the countries (a connection).
 *
 *   Public Methods:
 * 	     - LinkedNodes()
 *       - LinkedNodes(string A, string B, int num)
 *
 *   Private Methods:
 *       - None
 *
 *   Usage:
 * 	     - Creates node for a Linked List. 
 * 
 */
struct LinkedNodes
{
    string FirstCountry;
    string SecondCountry;
    int edge;

/**
  * Public : LinkedNodes()
  * 
  * Description:
  *      - Default constructor.
  *      - Initialize countries name and the edges.
  *      - friend ostream& operator<<(ostream& OutFile, LinkedNodes& other).
  * 
  * Params:
  *      - None.
  * 
  * Returns:
  *      - N/A
  */
    LinkedNodes()                                  
    {
        FirstCountry = SecondCountry = "Name";
        edge = 0;

    }

/**
  * Public : LinkedNodes()
  * 
  * Description:
  *      - Overload constructor.
  *      - Initialize countries name and the edges.
  * 
  * Params:
  *      - string A, string B, int num.
  * 
  * Returns:
  *      - N/A
  */
    LinkedNodes(string A, string B, int num) 
    {
        FirstCountry = A;
        SecondCountry = B;
        edge = num;
    }

 /**
  * Public : ostream
  * 
  * Description:
  *      - Overloading the cout operator to print the countries names.
  *      -  To print the edges.
  *
  * Params:
  *      - ostream& OutFile, LinkedNodes& other
  * 
  * Returns:
  *      - [string] ostream
  */
    friend ostream& operator<<(ostream& OutFile, LinkedNodes& other)
    {
        return OutFile << other.FirstCountry << " -> " << other.SecondCountry 
        << " [label =" << " \"" << other.edge << " miles\"]" << '\n';
    }
};

/*
 *    Class Name: Node
 * 
 *    Description:
 *        - A class to store a Node node and to link to other nodes.
 *       
 *    private Methods:
 *        - None.
 *
 *   public Methods:
 *       - Node()
 *       - Node(string CountryInitials, string Name)  
 *       - Node(const Node& other)
 *       - ~Node() {};
 *       - void SetInitials(string CountryInitials)
 *       - void SetCountryName(string Name)
 *       - string GetCountryName()
 *       - string GetInitials()
 *       - friend ostream& operator<<(ostream& OutFile, Node& other)
 *       - friend istream& operator>>(istream& InFile, Node& Node)
 *       
 *   Usage:
 *       - To link the countries and the edges.
 */
class Node
{
private:
    /*private attributes
    string EdgeColor;
    string FillColor;
    string OutlineColor;
    string EdgeStyle;
    string Name;
    string NodeNumber;*/

    string Initials;
    string CountryName;

public:

  /**
  * Public : Node()
  * 
  * Description:
  *      - Default Constructor initialize countries name and initials.
  * 
  * Params:
  *      - None.
  * 
  * Returns:
  *      - N/A
  */
    Node()
    {
        Initials = CountryName = 'a';
    }

  /**
  * Public : Node()
  * 
  * Description:
  *      - Overloaded constructor to initialize countries name and initials.
  * 
  * Params:
  *      - string CountryInitials, string Name.
  * 
  * Returns:
  *      - N/A
  */
    Node(string CountryInitials, string Name)
    {
        CountryName = Name;
        Initials = CountryInitials;
    }

  /**
  * Public : Node()
  * 
  * Description:
  *      - Copy constructor to initialize countries name
  *      - and initials with the values of the other object.
  * 
  * Params:
  *      - const Node& other.
  * 
  * Returns:
  *      - N/A
  */
    Node(const Node& other)
    {
        this->Initials = other.Initials;
        this->CountryName = other.CountryName;
    }

/**
  * Public : ~Node()
  * 
  * Description:
  *      - Destructor.
  * 
  * Params:
  *      - None.
  * 
  * Returns:
  *      - N/A
  */
    ~Node() {};

/**
 * Public : SetInitials()
 *
 * Description:
 *      - setter for the Countries initials
 *
 * Params:
 *      - string CountryInitials
 *
 * Returns:
 *      - void
 */
    void SetInitials(string CountryInitials)
    {
        Initials = CountryInitials;
    }


  /**
  * Public : SetCountryName()
  *  
  * Description:
  *      - setter for the Countries Name
  *
  * Params:
  *      - string Name
  *
  * Returns:
  *      - void
  */
    void SetCountryName(string Name)
    {
        CountryName = Name;
    }

 /**
  * Public : GetCountryName()
  *
  * Description:
  *      - Getter for the contryies Names.
  * Params:
  *      - none.
  *
  * Returns:
  *      - string
  */
    string GetCountryName()
    {
        return CountryName;
    }

 /**
  * Public : GetInitials()
  *
  * Description:
  *      - Getter for the contryies Initials.
  * Params:
  *      - none.
  *
  * Returns:
  *      - string
  */
    string GetInitials()
    {
        return Initials;
    }

/**
  * Public : ostream()
  * 
  * Description:
  *      - Overloading the cout operator to print the countries names.
  *      - Print the countries initials.
  * Params:
  *      - ostream& OutFile, Node& other
  * 
  * Returns:
  *      - [string] ostream
  */
    friend ostream& operator<<(ostream& OutFile, Node& other)
    {
        return OutFile << other.Initials << " [label =" << " \""
        << other.CountryName << "\"]" << '\n';
    }

/**
  * Public : istream()
  * 
  * Description:
  *      - Overloading the cin operator to read in the countries names.
  *      - To read in the countries initials.
  * Params:
  *      - istream& InFile, Node& Node
  * 
  * Returns:
  *      - [string] istream
  */
    friend istream& operator>>(istream& InFile, Node& Node)
    {
        InFile >> Node.Initials >> Node.CountryName;
        return InFile;
    }
};

/**
 * Main Driver
 *
 * For this program
 * 
 */
int main()
{
    ifstream InFile;
    ofstream OutFile;
    openFiles(InFile, OutFile);

    vector<LinkedNodes*> node_edges;                        // Create a vector of edge pointers.
    LinkedNodes* Links;                                     // Pointer to edges.
    Node nodes;                                             // Create object call nodes
    int NumNodes;
    int Numedges;
    int edges;
    string GraphType = "", FirstCountry, SecondCountry;

    InFile >> GraphType;                                    // Read in the graph type.
    OutFile << GraphType << "\n{ "<< "\n";                  // Display the graph Type.
    InFile >> NumNodes;                                     // Read in number of nodes.
    
    while (!InFile.eof())                                   // While the file not empty.
    {
        for (int i = 0; i < NumNodes;i++)
        { 
            InFile >> nodes;                                // Read in the node and print it out.
            OutFile << nodes;
        }

        InFile >> Numedges;                                 // Read in the number of edges

        for (int i = 0; i < Numedges;i++)          
        {                                                   
            InFile >> FirstCountry >> SecondCountry >> edges;
            Links = new LinkedNodes(FirstCountry, SecondCountry, edges);
            node_edges.push_back(Links);                    // Store in the vector.
        }

        for (int i = 0;i < node_edges.size();i++)
        {                                                   
            OutFile << *node_edges[i];                      // Print out each line.
        }
        OutFile << "}" << endl;                             
    }

    InFile.close();
    OutFile.close();
    return 0;

}

/**
 *
 * Function Name: openFiles ()
 *
 * Description:   
 *      - To prompt the user to enter infile and output file name.
 *      - To Make sure the infile can be open.
 *
 * Parameters:    
 *      - ifstream& InFile, ofstream& OutFile 
 *
 * Returns:
 *      - void
 *
 */
void openFiles(ifstream& InFile, ofstream& OutFile)
{
    char InFileName[40];                                    // Declare variable for the Files. 
    char outFileName[40];

    cout << "Enter the input file name: ";                  // Prompt the user for InFile name.
    cin >> InFileName;

    InFile.open(InFileName);                                // Open input file.

    if (InFile.fail())                                      // Create failsafe way.
    {
        cout << "the input file could not be opened" << endl;
        exit(0);
    }

    cout << "Enter the output file name: ";                 // Prompt the user for OutFile name.
    cin >> outFileName;

    OutFile.open(outFileName);                              // Open outfile.
}