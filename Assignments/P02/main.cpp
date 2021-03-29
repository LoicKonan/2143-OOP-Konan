/*****************************************************************************
*
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*
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
 *       - ~Node() {};
 *       - Node(string Countrynode_id, string Name)
 *       - friend ostream& operator<<(ostream& OutFile, Node& other)
 *       - friend istream& operator>>(istream& InFile, Node& Node)
 *
 *   Usage:
 *       - To link the countries and the edge_labels.
 */
class Node
{
private:

    string node_id;
    string node_label;
    string color;
    string style;
    float width;
    string shape;

public:

    /**
    * Public : Node()
    *
    * Description:
    *      - Default Constructor initialize countries name and node_id.
    *
    * Params:
    *      - None.
    *
    * Returns:
    *      - N/A
    */
    Node()
    {
        node_id = node_label = ' ';
        width = 1.5;
        int sides = 6;
        shape = "hexagon";
        color = "green:red;0.25:blue";
        style = "filled";
    }
    
    /**
    * Public : Node()
    *
    * Description:
    *      - Overloaded constructor.
    *
    * Params:
    *      - string Countrynode_id, string Name.
    *
    * Returns:
    *      - N/A
    */
    Node(string Countrynode_id, string Name)
    {
        node_id = node_label = ' ';
        width = 1.5;
        int sides = 6;
        shape = "hexagon";
        color = "green:red;0.25:blue";
        style = "filled";

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
      * Public : ostream()
      *
      * Description:
      *      - Overloading the cout operator to print the countries names.
      *      - Print the countries node_id.
      * Params:
      *      - ostream& OutFile, Node& other
      *
      * Returns:
      *      - [string] ostream
      */
    friend ostream& operator<<(ostream& OutFile, Node& other)
    {
        return OutFile 
            << other.node_id    << " [label =" << " \""
            << other.node_label << " \""       << ", shape = " 
            << other.shape       << ", color = \""  
            << other.color       << "\", style = "      
            << other.style       << ", width = "      
            << other.width       << "]"         << '\n';
    }

    /**
      * Public : istream()
      *
      * Description:
      *      - Overloading the cin operator to read in the countries names.
      *      - To read in the countries node_id.
      * Params:
      *      - istream& InFile, Node& Node
      *
      * Returns:
      *      - [string] istream
      */
    friend istream& operator>>(istream& InFile, Node& Node)
    {
        InFile >> Node.node_id >> Node.node_label;
        return InFile;
    }
};



/*
 *    Struct Name: LinkedNodes
 *
 *   Description:
 *       - Holds The countries  names.
 *       - And the edge_labels between the countries (a connection).
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
    string start_node_id;
    string end_node_id;
    int edge_label;

    /**
      * Public : LinkedNodes()
      *
      * Description:
      *      - Default constructor.
      *      - Initialize countries name and the edge_labels.
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
        start_node_id = end_node_id = " ";
        edge_label = 0;

    }

    /**
      * Public : LinkedNodes()
      *
      * Description:
      *      - Overload constructor.
      *      - Initialize countries name and the edge_labels.
      *
      * Params:
      *      - string A, string B, int num.
      *
      * Returns:
      *      - N/A
      */
    LinkedNodes(string A, string B, int num)
    {
        start_node_id = A;
        end_node_id = B;
        edge_label = num;
    }

    /**
     * Public : ostream
     *
     * Description:
     *      - Overloading the cout operator to print the countries names.
     *      -  To print the edge_labels.
     *
     * Params:
     *      - ostream& OutFile, LinkedNodes& other
     *
     * Returns:
     *      - [string] ostream
     */
    friend ostream& operator<<(ostream& OutFile, LinkedNodes& other)
    {
        return OutFile 
            << other.start_node_id       << " -> " << other.end_node_id
            << " [label =" << " \""     << other.edge_label << " miles\"" 
            << " arrowhead = odiamond]" << '\n';
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

    vector<LinkedNodes*> node_edge_labels;                        // Create a vector of edge_label pointers.
    LinkedNodes* Links;                                     // Pointer to edge_labels.
    Node nodes;                                             // Create object call nodes.

    int NumNodes;
    int Numedge_labels;
    int edge_labels;

    string GraphType = "";
    string start_node_id;
    string end_node_id;


    InFile >> GraphType;                                    // Read in the graph type.
    OutFile << GraphType << " Countries\n{ " << "\n";                 // Display the graph Type.
    InFile >> NumNodes;                                     // Read in number of nodes.

    while (!InFile.eof())                                   // While the file not empty.
    {
        for (int i = 0; i < NumNodes;i++)
        {
            InFile >> nodes;                                // Read in the node and print it out.
            OutFile << nodes;
        }

        InFile >> Numedge_labels;                                 // Read in the number of edge_labels

        for (int i = 0; i < Numedge_labels;i++)
        {
            InFile >> start_node_id >> end_node_id >> edge_labels;
            Links = new LinkedNodes(start_node_id, end_node_id, edge_labels);
            node_edge_labels.push_back(Links);                    // Store in the vector.
        }

        for ( unsigned int i = 0;i < node_edge_labels.size();i++)
        {
            OutFile << *node_edge_labels[i];                      // Print out each line.
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