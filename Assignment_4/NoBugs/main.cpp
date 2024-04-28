#include "BSTClass.h"
#include "supportingFunctions.h"
#include "LogClass.h"

void processFileIntoBST(ifstream& file, BST& studentBST,
                                        vector <double> &allGrades,
                                        Log& Logger);

int main(int argc, char const *argv[])
{
  // Declare variables
  bool run = true;
  string input, gradeStr, lastName, firstName, assertMsg;
  string fileName = "student_data.csv" ;
  string lNameFile = "last_names.csv";
  string fNameFile = "first_names.csv";
  ifstream file;
  double grade;

  // intitialize BSTRoot
  BST studentBST;
  Log Logger;

  // initialize vectors
  vector <string> lastNameVec, firstNameVec;
  vector <double> allGrades;

  initializeVectorFromFile( lNameFile, lastNameVec );
  initializeVectorFromFile( fNameFile, firstNameVec );

  // Open the file
  file.open(fileName);

  // (2) Write assertions in your code to check a contract
  assert( ( "Input file not found", file.is_open( ) ) );

  // Process file
  processFileIntoBST( file, studentBST, allGrades, Logger );

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
      // Generate info
      lastName  = randomName( lastNameVec );
      firstName = randomName( firstNameVec );
      grade     = generateGrade( allGrades );

      // concatenate
      gradeStr = to_string( grade );

      // insert new student
      studentBST.insert( lastName, firstName, grade );

      printString( "\n---- Student Added ----\n" );
      printString( "\tName : " );
      printString( lastName );
      printString( ", " );
      printString( firstName );
      printString( "\n" );
      printString( "\tGrade: " );
      printString( gradeStr );
      printString( "%\n" );

      Logger.LogStudent( firstName, lastName, gradeStr );
    }

    // Option 2
    else if ( input == "2")
    {
      // display string
      printString("\n---- Searching Existing Student---- \n");

      // prompt for info
      lastName  = promptForString("Last Name: ");
      firstName = promptForString("First Name: ");

      // search for student
      studentBST.searchForStudent( lastName, firstName );
    }

    // Option 3
    else if ( input == "3")
    {
      studentBST.displayInOrder();
    }

    // Option 3
    else if ( input == "4")
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

  // end program
  return 0;
}


void processFileIntoBST(ifstream& file, BST& studentBST,
                                        vector <double> &allGrades,
                                        Log& Logger )
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

    // check if not a duplicate grade
    if ( !gradeInVector( grade, allGrades) )
    {
      // append to vec
      allGrades.push_back( grade );

      // insert to BST
      studentBST.insert( lastName, firstName, grade );

      Logger.LogStudent( firstName, lastName, gradeStr );
    }

    // else, skip it

  }
}
