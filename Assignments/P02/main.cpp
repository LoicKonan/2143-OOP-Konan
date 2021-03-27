#include<sstream>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>

using namespace std;


//below is an instance of our node that will create a node to print out to 
//and link to other nodes
class Node
{
private:
    //private attributes
    /*string EdgeColor;
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
    };// default constructor
    //overloaded default method for our node
    //default string of initials and then countryname
    Node(string CountryInitials, string Name)
    {
        CountryName = Name;
        Initials = CountryInitials;
    }
    //four methods below to get and set the input values

    //setters for out attributes
    void SetInitials(string);
    void SetCountryName(string);

    //getters to get new name and initials
    string GetCountryName();
    string GetInitials();

    //copy constructor for another node
    Node(const Node& other)
    {
        this->Initials = other.Initials;
        this->CountryName = other.CountryName;
    }

    //overloaded outstream operator for our class
    friend ostream& operator<<(ostream& OutFile, const Node& other);

    //infile overloader
    friend istream& operator>>(istream& InFile, Node& Node);
    //destructor for our class
    ~Node() {};

};




//definition for OutFiletream overloading

ostream& operator<<(ostream& OutFile, const Node& nodes)
{
    return OutFile << nodes.Initials << "[ label =" << " \" "
        << nodes.CountryName << " \" ]" << '\n';
};


istream& operator>>(istream& InFile, Node& Node)
{
    InFile >> Node.Initials >> Node.CountryName;
    return InFile;
}



//setters for our class dot operator
void Node::SetInitials(string CountryInitials)
{
    Initials = CountryInitials;
}

void Node::SetCountryName(string name)
{
    CountryName = name;
}

//getter functions for our nodes dot operator
string Node::GetCountryName()
{
    return CountryName;
}
string Node::GetInitials()
{
    return Initials;
}

//creating a structer to read the linked nodes and their edges
struct LinkedNodes
{
    //infile reads node node then edge number
    string FirstCountry;
    string SecondCountry;
    int edge;


    //creating a default constructor to set the values to basic default values
    LinkedNodes()
    {
        FirstCountry = SecondCountry = "Name";
        edge = 0;

    };
    //create an overload for stuct Node
    //assign the values to the structure name
    LinkedNodes(string A, string B, int num)
    {
        FirstCountry = A;
        SecondCountry = B;
        edge = num;
    };

    //overloaded outfile operator that formats the output
    friend ostream& operator<<(ostream& OutFile, LinkedNodes& other)
    {
        //format the output suitable for graphviz
        return OutFile << other.FirstCountry << " ->" << other.SecondCountry <<
            "[ label =" << " \" " << other.edge << " \" ]" << '\n';

    };


};


//function prototypes to read from InFile
void openFiles(ifstream& InFile, ofstream& OutFile);

int main()
{

    ifstream InFile;
    ofstream OutFile;
    openFiles(InFile, OutFile);// prompt for input output

    vector<LinkedNodes*> node_edges;// create a vector of edge pointers called edge
    LinkedNodes* Links;// pointer to edges of the edge stuct

     //create objects for class and structures
    Node nodes;// class node with object nodes

    //variable initialization

    int NumNodes, Numedges, edges;// second line that reads in node numbers
    string GraphType = "", FirstCountry, SecondCountry;
    //these string values are the string values we are reading in


    //read in the first value string to show which kind of graph
    InFile >> GraphType;// read in the graph type and go to next line
    OutFile << GraphType << " MyGraph "<< "{ "<<
        "\n\n";
    InFile >> NumNodes;// read in the next line which is the number of nodes
    
                       //dont need to print out nodes for transfer to graphviz
    //OutFile << "There are :  " << NumNodes << "  Nodes" << endl;
    //this is what we will read until

    while (!InFile.eof())
    {//until eof() is encountered
        for (int i = 0; i < NumNodes;i++)
        {
            // call the outstream and instream overload for 
            // the lines
            //no need for anything else
            InFile >> nodes;
            OutFile << nodes;

        }
        //next link read in the value

        InFile >> Numedges;// read in the number of edges

        OutFile << "\n\n";

        //graphviz doesnt need this
        //OutFile << " There are " << Numedges << " linked nodes" << endl << endl;

        for (int i = 0; i < Numedges;i++)// traverse tille end of read in value
        {
            //read in the first line the first instance

                //read in all three from infile 
                //create new node dynamically
                //store in the vector
            InFile >> FirstCountry >> SecondCountry >> edges;
            Links = new LinkedNodes(FirstCountry, SecondCountry, edges);
            node_edges.push_back(Links);


        }

        for (int i = 0;i < node_edges.size();i++)
        {
            //call ostream overload for the stuct
            //print out each line
            OutFile << *node_edges[i];
        }
        OutFile << "}" << endl; // close off the graph design
    }

    InFile.close();
    OutFile.close();
    return 0;

}

//#####################################################//
//f(x) name                                            // 
//  void openFiles(ifstream& InFile, ofstream& OutFile)//
//                                                     //
//what it does?                                        //
// -> purpOutFilee is to user input in and outfile     //
//                                                     //
//paramters                                            //
// -> utilizes the ofstream and outfile                //
//                                                     //
// return type                                         //
// -> no return type because  void                     //
//#####################################################//

void openFiles(ifstream& InFile, ofstream& OutFile)
{
    // Declare variable for the Files. 
    char InFileName[40];
    char outFileName[40];

    // Prompt the user for InFile name
    cout << "Enter the input file name: ";
    cin >> InFileName;

    // open input file
    InFile.open(InFileName);

    //create failsafe way
    if (InFile.fail()) //OutFile out if the file cannot be opened
    {
        cout << "the input file could not be opened" << endl;
        exit(0);
    }

    // Prompt the user for OutFile name
    cout << "Enter the output file name: ";
    cin >> outFileName;

    // Open outfile.
    OutFile.open(outFileName);
}