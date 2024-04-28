#include "supportingFunctions.h"
#include "BSTClass.h"

// clearTree
BST::StudentNode* BST::clearTree( StudentNode *node )
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
string BST::formatStudentStr( StudentNode const* student )
{
  // declare variables
  float grade = student->grade;
  stringstream ss;
  string strGrade, str;

  // convert to string with a precision of 2
  ss << fixed << setprecision(2) << grade;
  strGrade = ss.str();

  // create return string
  str = strGrade + " - " +
               student->lastName + ", " + student->firstName + '\n';

  // return the str
  return str;
}

// initialize a node
void BST::initializeNodeFromData( string lastName, string firstName, float grade,
                                                        StudentNode* student)
{
  student->lastName = lastName;
  student->firstName = firstName;
  student->grade = grade;

  student->leftChild = NULL;
  student->rightChild = NULL;
}

// insert
BST::StudentNode* BST::insert( string lastName, string firstName, float grade,
                                                            StudentNode *node)
{
  // declare variables
  StudentNode* newNode;

  // check if root is null
  if (node == NULL)
  {
    // create new instance of studentNode
    newNode = new StudentNode;

    initializeNodeFromData(lastName, firstName, grade, newNode);

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
void BST::privateDisplayInOrder( StudentNode* BSTRoot, int* index )
{
  string studentStr;

  // set precision
  cout.precision(2);

  // check if root is null
  if ( BSTRoot != NULL )
  {
    // go left
    privateDisplayInOrder( BSTRoot->rightChild, index );

    // format current node
    studentStr = formatStudentStr( BSTRoot );

    // increase item number
    (*index)++;

    if (*index >= 10)
    {
      // print current node
      cout << to_string(*index) + ") " + studentStr;
    }

    else
    {
      // print current node
      cout << " " + to_string(*index) + ") " + studentStr;
    }

    // go right
    privateDisplayInOrder( BSTRoot->leftChild, index );
  }
}

// DPOSTO
void BST::privateDisplayPostOrder( StudentNode* BSTRoot, int* index )
{
  string studentStr;

  // check if root is null
  if ( BSTRoot != NULL )
  {
    // go left
    privateDisplayPostOrder( BSTRoot->leftChild, index );

    // go right
    privateDisplayPostOrder( BSTRoot->rightChild, index );

    // increase item number
    (*index)++;

    // format current node
    studentStr = formatStudentStr( BSTRoot );

    if ( *index >= 10 )
    {
      // print current node
      cout << to_string(*index) + ") " + studentStr;
    }

    else
    {
      // set precision
      cout.precision(2);
      // print current node
      cout << " " + to_string(*index) + ") " + studentStr;
    }
  }
}

// DPREO
void BST::privateDisplayPreOrder( StudentNode* BSTRoot, int* index )
{
  // declare variables
  string studentStr;

  // check if root is null
  if ( BSTRoot != NULL )
  {
    // increase item number
    (*index)++;

    // format current node
    studentStr = formatStudentStr( BSTRoot );

    if (*index >= 10)
    {
      // set precision
      cout.precision(2);

      // print current node
      cout << to_string(*index) + ") " + studentStr;
    }

    else
    {
      // set precision
      cout.precision(2);

      // print current node
      cout << " " + to_string(*index) + ") " + studentStr;
    }

    // go left
    privateDisplayPreOrder( BSTRoot->leftChild, index );

    // go right
    privateDisplayPreOrder( BSTRoot->rightChild, index );
  }
}

void BST::searchForStudent( string lastName, string firstName,
                                                        StudentNode* BSTRoot)
{
  // declare variables
  StudentNode* foundNode = NULL;
  string str;

  // check if root is NULL
  if (BSTRoot != NULL)
  {
    // find node
    foundNode = search( lastName, firstName, BSTRoot );

    // was the node found?
    if ( foundNode != NULL )
    {
      // yes, display node data
      printString("(!) Student Record Found: ");

      str = formatStudentStr(foundNode );

      printString( str );
    }

    // Node was not found
    else
    {
      printString("(!) Student Not Found.\n");
    }
  }
}

BST::StudentNode* BST::search( string lastName, string firstName, StudentNode* node )
{
  // No node found
  if (node == NULL)
  {
    return NULL;
  }

  // Check if the current node matches the search criteria
  if (node->firstName == firstName && node->lastName == lastName)
  {
    return node;
  }

  // search in the left subtree
  StudentNode *foundNode = search(lastName, firstName, node->leftChild);

   // Found in the left subtree
  if ( foundNode != NULL )
  {
    return foundNode;
  }

  // Recursively search in the right subtree
  return search(lastName, firstName, node->rightChild);
}

void BST::setStudentNodeData( StudentNode *destPtr, const StudentNode source )
{
 destPtr -> lastName = source.lastName;
 destPtr -> firstName = source.firstName;
 destPtr -> grade = source.grade;

 destPtr -> leftChild = source.leftChild;
 destPtr -> rightChild = source.rightChild;
}

// Constructor for BST
BST::BST() {
  BSTRoot = NULL;
}

// Deconstructor for BST
BST::~BST() {
  BSTRoot = clearTree( BSTRoot );
}

// insert into BST
void BST::insert( string lastName, string firstName, float grade )
{
  //cout << "\n---- Inserting New Student ----\n\n";
  BSTRoot = insert( lastName, firstName, grade, BSTRoot );
}

// display BST in order
void BST::displayInOrder()
{
  // declare variables
  int index = 0;

  // process In Order
  cout << "\n---- Displaying Students In Order ----\n\n";
  privateDisplayInOrder( BSTRoot, &index );
}

// display BST postorder
void BST::displayPostOrder()
{
  // declare variables
  int index = 0;

  // process Post Order
  cout << "\n---- Displaying Students Post Order ----\n\n";
  privateDisplayPostOrder( BSTRoot, &index );
}

// display BST preorder
void BST::displayPreOrder()
{
  // declare variables
  int index = 0;

  // process Pre order
  cout << "\n---- Displaying Students Pre Order ----\n\n";
  privateDisplayPreOrder( BSTRoot, &index );
}

// search in BST
void BST::searchForStudent( string lastName, string firstName )
{
  cout << "\n---- Searching for Student ----\n\n";
  searchForStudent( lastName, firstName, BSTRoot );
}
