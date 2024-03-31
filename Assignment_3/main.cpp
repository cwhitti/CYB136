#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// declare BST class
class BST;

// header declarations
void processFileIntoBST(ifstream& file, BST studentBST);

// declare BST class
class BST
{
  // create StudentNode struct
  struct StudentNode
    {
      string lastName;
      string firstName;
      int grade;

      StudentNode *leftChild;
      StudentNode *rightChild;
    };

  // create root pointer
  StudentNode *BSTRoot;

// create private functions
private:

  // clearTree
  StudentNode* clearTree( StudentNode *node )
  {
    // check if node not empty
    if ( node != NULL )
    {
      // clear left
      clearTree(node->leftChild);

      // clear right
      clearTree(node->rightChild);

      // delete node
      delete node;
    }
    // return NULL back up
    return NULL;
  }

  // format a str
  string formatStudentStr( StudentNode const* student, int index )
  {
    string str = to_string(index) + ") " + to_string(student->grade) + " - " +
                                    student->lastName + ", " +
                                    student->firstName + '\n';
    return str;
  }

  // initialize a node
  void initializeNodeFromData( string lastName, string firstName, int grade,
                                                            StudentNode student)
  {
    student.lastName = lastName;
    student.firstName = firstName;
    student.grade = grade;

    student.leftChild = NULL;
    student.rightChild = NULL;
  }

  // insert
  StudentNode* insert( string lastName, string firstName, int grade,
                                                              StudentNode *node)
  {
    // declare variables
    StudentNode* newNode;

    // check if root is null
    if (node == NULL)
    {
      // create new instance of studentNode
      newNode = new StudentNode;

      initializeNodeFromData(lastName, firstName, grade, *newNode);

      return newNode;
    }

    // Data found, go left if new grade <= current grade
    else if ( grade <= node -> grade )
    {
      // insert left
      node->leftChild = insert(lastName, firstName, grade, node->leftChild);
    }

    // Data found, go left if new grade > current grade
    else
    {
      node->rightChild = insert(lastName, firstName, grade, node->rightChild);
    }

    // return Node
    return node;
  }

  // DINO
  void privateDisplayInOrder( StudentNode* BSTRoot, int index )
  {

  }

  // DPOSTO
  void privateDisplayPostOrder( StudentNode* BSTRoot, int index )
  {


  }

  // DPREO
  void privateDisplayPreOrder( StudentNode* BSTRoot, int index )
  {
    string studentStr;

    if ( BSTRoot != NULL )
    {
      // increment index
      index = index + 1;

      // go left
      privateDisplayPreOrder( BSTRoot->leftChild, index );

      // format current node
      studentStr = formatStudentStr( BSTRoot, index );

      // print current node
      cout << studentStr;

      // go right
      privateDisplayPreOrder( BSTRoot->leftChild, index );
    }

  }

public:

  // Constructor for BST
  BST() {
    BSTRoot = NULL;
  }

  // Deconstructor for BST
  ~BST() {
    BSTRoot = clearTree( BSTRoot );
  }

  // insert into BST
  void insert( string lastName, string firstName, int grade )
  {
    BSTRoot = insert( lastName, firstName, grade, BSTRoot);
  }

  // display BST in order
  void displayInOrder()
  {
    int index = 0;
    privateDisplayInOrder( BSTRoot, index );
  }

  // display BST postorder
  void displayPostOrder()
  {
    int index = 0;
    privateDisplayPostOrder( BSTRoot, index );
  }

  // display BST preorder
  void displayPreOrder()
  {
    int index = 0;
    privateDisplayPreOrder( BSTRoot, index );
  }
};


int main(int argc, char const *argv[])
{
  // Declare variables
  string fileName = argv[1];
  ifstream file;
  file.open(fileName); // Open the file

  BST studentBST;

  // Check if file is opened, initializing BST
  if (file.is_open())
  {
      // Process file
      processFileIntoBST(file, studentBST);

      // Pre-order
      studentBST.displayPreOrder();
  }

  return 0;
}

void processFileIntoBST(ifstream& file, BST studentBST)
{
  // declare variables
  string line, lastName, firstName, gradeStr;
  int grade;

  while (getline(file, line))
  {
    // convert yo stringstream obj
    stringstream ss(line);

    // get each col
    getline(ss, lastName, ',');
    getline(ss, firstName, ',');
    getline(ss, gradeStr);

    // convert grade to integer
    grade = stoi( gradeStr );

    // insert to BST
    studentBST.insert( lastName, firstName, grade );
  }
}
