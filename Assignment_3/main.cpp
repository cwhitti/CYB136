#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// declare BST class
class BST;

// header declarations
void displayMenu();
void printString( string str );
void processFileIntoBST(ifstream& file, BST& studentBST);
string promptForString( string prompt );

// declare BST class
class BST
{
  // create StudentNode struct
  struct StudentNode
    {
      string lastName;
      string firstName;
      float grade;

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
  string formatStudentStr( StudentNode const* student )
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
  void initializeNodeFromData( string lastName, string firstName, float grade,
                                                          StudentNode* student)
  {
    student->lastName = lastName;
    student->firstName = firstName;
    student->grade = grade;

    student->leftChild = NULL;
    student->rightChild = NULL;
  }

  // insert
  StudentNode* insert( string lastName, string firstName, float grade,
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
  void privateDisplayInOrder( StudentNode* BSTRoot, int* index )
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
  void privateDisplayPostOrder( StudentNode* BSTRoot, int* index )
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
  void privateDisplayPreOrder( StudentNode* BSTRoot, int* index )
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

<<<<<<< Updated upstream
=======
  StudentNode *removeFromMin( StudentNode *parentPtr, StudentNode *childPtr )
  {
   // check if another layer of recursion is needed
   if ( childPtr -> leftChild != NULL )
   {
    // recursively searches for min node
    return removeFromMin( childPtr, childPtr -> leftChild );
   }

   // no more recursion is needed

   // Update the parent's leftChildPtr to unlink the min node
   parentPtr -> leftChild = childPtr -> rightChild;

   // return child pointer
   return childPtr;
  }

  bool removeItem( string firstName, string lastName, StudentNode *BSTRoot )
  {
    // searches for item
    StudentNode *foundData = search( lastName, firstName, BSTRoot );



    // ensure data is found
    if (foundData != NULL)
    {
     // if found, creates new node from search pointer,
     // setStateNodeData( removedData, *foundData );

     // then removes item from tree using helper function,
      // function: StateDataType *wkgPtr, const StateDataType outData
     BSTRoot = removeItemHelper( BSTRoot, foundData );

     return true;
    }
    // otherwise returns NULL
    return false;
  }

  StudentNode* removeItemHelper( StudentNode *wkgPtr, StudentNode *foundNode )
  {
   // declare variables
   StudentNode *tempPtr;
   float difference;

   // compare state names
    difference = foundNode -> grade - wkgPtr -> grade;

   // check for moving left
   if (difference < 0 )
   {
    // recurse left
    wkgPtr->leftChild = removeItemHelper( wkgPtr->leftChild, foundNode );
   }

   // check for moving right
   else if (difference > 0)
   {
    // recurse right
    wkgPtr->rightChild = removeItemHelper( wkgPtr->rightChild, foundNode );
   }

   // we found the node to remove!!
   else
   {
     // CASE: check for left child null
     if ( wkgPtr->leftChild == NULL )
     {
      // set a temp ptr to wkgPtr
      tempPtr = wkgPtr;

      // set return ptr to right child
      wkgPtr = wkgPtr -> rightChild;

      // free temp ptr
      delete ( tempPtr );
     }

     // otherwise, check for right child null
     else if ( wkgPtr -> rightChild == NULL )
     {
      // set a temp ptr to wkg ptr
      tempPtr = wkgPtr;

      // set return ptr to left child
      wkgPtr = wkgPtr -> leftChild;

      // free temp ptr
      delete ( tempPtr );
     }

     // check for right child has no left child
     else if ( wkgPtr -> rightChild -> leftChild == NULL)
     {
      // copy data from right child into current node
      // wkgPtr = wkgPtr -> rightChild;
      setStudentNodeData( wkgPtr, *wkgPtr -> rightChild );

      // set temp ptr to right child
      tempPtr = wkgPtr -> rightChild;

      // link around the right child
      wkgPtr -> rightChild = tempPtr -> rightChild;

      // free the right child node
      delete ( tempPtr );
     }

     // assume right child has left child
     else
     {
       // call removeFromMin, capture returned node
       tempPtr = removeFromMin( wkgPtr -> rightChild, wkgPtr -> leftChild );

       // set current node to captured node
       // wkgPtr = tempPtr;
       setStudentNodeData( wkgPtr, *tempPtr );

       // free captured node
       delete( tempPtr );
     } // end checks for found data
   }
   // end
   return wkgPtr;
  }
>>>>>>> Stashed changes

  void searchForStudent( string lastName, string firstName,
                                                        StudentNode* BSTRoot)
  {
    // declare variables
    StudentNode* foundNode = NULL;
    string str;

    // check if root is NULL
    if (BSTRoot != NULL)
    {
      // find find node
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

  StudentNode* search(string lastName, string firstName, StudentNode* node)
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
  void insert( string lastName, string firstName, float grade )
  {
    //cout << "\n---- Inserting New Student ----\n\n";
    BSTRoot = insert( lastName, firstName, grade, BSTRoot );
  }

  // display BST in order
  void displayInOrder()
  {
    // declare variables
    int index = 0;

    // process In Order
    cout << "\n---- Displaying Students In Order ----\n\n";
    privateDisplayInOrder( BSTRoot, &index );
  }

  // display BST postorder
  void displayPostOrder()
  {
    // declare variables
    int index = 0;

    // process Post Order
    cout << "\n---- Displaying Students Post Order ----\n\n";
    privateDisplayPostOrder( BSTRoot, &index );
  }

  // display BST preorder
  void displayPreOrder()
  {
    // declare variables
    int index = 0;

    // process Pre order
    cout << "\n---- Displaying Students Pre Order ----\n\n";
    privateDisplayPreOrder( BSTRoot, &index );
  }

  // search in BST
  void searchForStudent( string lastName, string firstName )
  {
    cout << "\n---- Searching for Student ----\n\n";
    searchForStudent( lastName, firstName, BSTRoot );
  }
};

int main(int argc, char const *argv[])
{
  // Declare variables
  bool run = true;
  string input, gradeStr, lastName, firstName, fileName;
  ifstream file;
  float grade;

  // intitialize BSTRoot
  BST studentBST;

  // check for > 2 args
  if ( argc >= 2 )
  {
    // grab fileName
    fileName = argv[1];

    // Open the file
    file.open(fileName);

    // Check if file is opened, initializing BST
    if ( file.is_open() )
    {
      // Process file
      processFileIntoBST( file, studentBST );

      // file not needed now
      file.close();

      // display what was created
      studentBST.displayInOrder();

      // begin the user input
      while ( run )
      {
        // Show menu
        printString("\n---- Menu Choices ----\n");
        displayMenu();

          // get input
        input = promptForString("Program Choice: ");

        // Option 1
        if ( input == "1")
        {
          // display string
          printString("\n---- Add New Student---- \n");

          // prompt for info
          lastName = promptForString("Last Name: ");
          firstName = promptForString("First Name: ");
          gradeStr = promptForString("Grade: ");

          // cast grade to int
          grade = stof( gradeStr );

          // insert new student
          studentBST.insert( lastName, firstName, grade );
        }

        // Option 2
        else if ( input == "2")
        {
          // display string
          printString("\n---- Searching Existing Student---- \n");

          // prompt for info
          lastName = promptForString("Last Name: ");
          firstName = promptForString("First Name: ");

          // search for student
          studentBST.searchForStudent( lastName, firstName );
        }

        // Option 3
        else if ( input == "3")
        {
          studentBST.displayInOrder();
        }

        // Option 4
        else if ( input == "4" )
        {
          run = false;
        }

        // No valid input
        else
        {
          // display string
          printString("\nInvalid input, please try again\n");
        } // Check for menu input
      } // End while loop
    } // Check if file opened

    // File doesnt exist
    else
    {
      printString("File not found: " + fileName + "\n");
    }

  } // Check if >= 2 args provided

  // Bad file input, file not supplied
  else
  {
    printString("File not supplied in command arguments\n");
  }

  // end program
  return 0;
}

void displayMenu()
{
  printString("[1] Add New Student\n");
  printString("[2] Search Existing Student\n");
  printString("[3] Display BST In Order\n");
  printString("[4] Quit\n\n");
}

void printString( string str )
{
  cout << str;
}

void processFileIntoBST(ifstream& file, BST& studentBST)
{
  // declare variables
  string line, lastName, firstName, gradeStr;
  float grade;

  // skip header
  getline( file, line );

  // process file lines
  while ( getline( file, line ) )
  {
    // convert yo stringstream obj
    stringstream ss(line);

    // get each col
    getline( ss, lastName, ',' );
    getline( ss, firstName, ',' );
    getline( ss, gradeStr );

    // Convert gradeStr to floating-point number
    grade = stof(gradeStr);

    // insert to BST
    studentBST.insert( lastName, firstName, grade );
  }
}

string promptForString( string prompt )
{
  // Declare variables
  string outStr;

  // Print prompt
  cout << prompt;

  // Get input
  cin >> outStr;

  // return the
  return outStr;
}
