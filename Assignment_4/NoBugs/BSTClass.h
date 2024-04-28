#ifndef BSTCLASS_H
#define BSTCLASS_H

#include "supportingFunctions.h"

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
    StudentNode* clearTree( StudentNode *node );

    // format a str
    string formatStudentStr( StudentNode const* student );

    // initialize a node
    void initializeNodeFromData( string lastName, string firstName, float grade,
                                                            StudentNode* student);
    // insert
    StudentNode* insert( string lastName, string firstName, float grade,
                                                                StudentNode *node);

    // DINO
    void privateDisplayInOrder( StudentNode* BSTRoot, int* index );

    // DPOSTO
    void privateDisplayPostOrder( StudentNode* BSTRoot, int* index );

    // DPREO
    void privateDisplayPreOrder( StudentNode* BSTRoot, int* index );

    void searchForStudent( string lastName, string firstName,
                                                            StudentNode* BSTRoot);

    StudentNode* search( string lastName, string firstName, StudentNode* node );

    void setStudentNodeData( StudentNode *destPtr, const StudentNode source );

  public:

    // Constructor for BST
    BST();

    // Deconstructor for BST
    ~BST();

    // insert into BST
    void insert( string lastName, string firstName, float grade );

    // display BST in order
    void displayInOrder();

    // display BST postorder
    void displayPostOrder();

    // display BST preorder
    void displayPreOrder();

    // search in BST
    void searchForStudent( string lastName, string firstName );
  };

#endif
