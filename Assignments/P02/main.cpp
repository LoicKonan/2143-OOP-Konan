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
    ~Node()
    {
        cout << " node has been destoyed" << endl;
    };

}; 




//definition for OutFiletream overloading

ostream& operator<<(ostream& OutFile, const Node& nodes)
{
    return OutFile << "[" << " NodeName =" << nodes.Initials << "," <<
        " Country= " << nodes.CountryName << "]" << '\n';
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


typedef pair<string, string> linkcountry;



struct Edge
{
    string CountryInitials;
    string CountryInitials2;
    string country1;
    string edge_type;
    map<string, string> linkedcountries;
    map<string, string>::iterator traversal;

    Edge()
    {
        CountryInitials = CountryInitials2 = country1 = edge_type = "";
    }
    Edge(string CountryInit)
    {
        CountryInitials = CountryInit;
        CountryInitials2 = CountryInit;
        country1 = edge_type = "";
    }

    void addStyle(string country2, string edgeammount)
    {
        linkedcountries.insert({country2, edgeammount});
        //our key is going to be the second country value and then edge
    }

    friend ostream& operator<<(ostream& OutFile, Edge& other)
    {
        //first country initials are read in first
        OutFile << other.CountryInitials;

        for (other.traversal = other.linkedcountries.begin(); other.traversal != other.linkedcountries.end(); ++other.traversal)
        {
            // read in the second and third
            OutFile <<"->"<< other.traversal->first << " " << other.traversal->second << ", ";
        }
        
        return OutFile;
    }
};


//function prototypes to read from InFile
void openFiles(ifstream& InFile, ofstream& OutFile);

int main()
{
    
    ifstream InFile;
    ofstream OutFile;
    openFiles(InFile, OutFile);// prompt for input output
    
    vector<Edge*> edge;

     //create objects for class and structures
    Node nodes;// class node with object nodes
    Edge* edges;// pointer to edges of the edge stuct
    //variable initialization

    int NumNodes, Numedges;// second line that reads in node numbers
    string GraphType = "", edgenumber, country2, FirstCountry;
    
    
    
    //read in the first value string to show which kind of graph
    InFile >> GraphType;// read in the graph type and go to next line
    OutFile << "The GraphType is: " << GraphType <<
        "\n\n";
    InFile >> NumNodes;// read in the next line which is the number of nodes

    OutFile << "There are :  " << NumNodes << "  Nodes" << endl;
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
        OutFile << " There are " << Numedges << " linked nodes" << endl << endl;

        for (int i = 0; i < Numedges;i++)// traverse tille end of read in value
        {
            InFile >> FirstCountry;
            edges = new Edge(FirstCountry);

            InFile >> country2;
            InFile >> edgenumber;

            edges->addStyle("country1", country2);
            edges->addStyle("edgenumber", edgenumber);

            edge.push_back(edges);

        }

        for (int i = 0;i < edge.size();i++)
        {
            OutFile << *edge[i] << endl;
        }
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
// -> purpOutFilee is to user input in and outfile          //
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