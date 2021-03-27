/*****************************************************************************
*
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Author:           Ethan Coyle
*    Email:            Ejcoyle0912@my.msutexas.edu
*    Author:           Jonathan Hogan
*    Email:            jon.hogan83@gmail.com
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


// creating a struct to read the linked nodes and their edges
struct LinkedNodes
{
    string FirstCountry;
    string SecondCountry;
    int edge;


    // creating a default constructor to set the values to basic default values
    LinkedNodes()
    {
        FirstCountry = SecondCountry = "Name";
        edge = 0;

    }

    //create an overload for stuct Node
    LinkedNodes(string A, string B, int num)
    {
        FirstCountry = A;
        SecondCountry = B;
        edge = num;
    };

    //overloaded outfile operator that formats the output
    friend ostream& operator<<(ostream& OutFile, LinkedNodes& other)
    {
        return OutFile << other.FirstCountry << " ->" << other.SecondCountry <<
            "[ label =" << " \" " << other.edge << " \" ]" << '\n';
    };
};



//below is an instance of our node that will create a node to print out to 
//and link to other nodes
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
    //default constructor to hold our values
    Node()
    {
        Initials = CountryName = 'a';
    };

    // Overloaded default method for our node
    // Default string of initials and then countryname
    Node(string CountryInitials, string Name)
    {
        CountryName = Name;
        Initials = CountryInitials;
    }

    ~Node() {};

    void SetInitials(string CountryInitials)
    {
        Initials = CountryInitials;
    }

    void SetCountryName(string Name)
    {
        CountryName = Name;
    }

    string GetCountryName()
    {
        return CountryName;
    }

    string GetInitials()
    {
        return Initials;
    }

    // copy constructor for another node
    Node(const Node& other)
    {
        this->Initials = other.Initials;
        this->CountryName = other.CountryName;
    }

    friend ostream& operator<<(ostream& OutFile, Node& other)
    {
        return OutFile << other.Initials << "[label =" << " \" "
        << other.CountryName << " \"]" << '\n';
    }

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
        OutFile << "\n\n";

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