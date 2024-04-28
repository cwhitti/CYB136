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
  string input, gradeStr, lastName, firstName;

  /*
    1) Take your code for assignment 2 or 3, and move the functionality
    into a single function (which may call other functions, of course,
    if you wrote multiple functions in assignment 2 or 3).
    Change the user input into a parameter to the function, so the code
    is now self-contained. You may have to do some serious changes to
    the code to get this to work, in which case you can move somewhat
    further from the original submission.
  */
  string fileName = "student_data.csv" ;
  string lNameFile = "last_names.csv";
  string fNameFile = "first_names.csv";
  ifstream file;
  double grade;

  int index = 0;

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
  Logger.LogInfo("Opened input file");

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
      Logger.LogInfo("Generating new student...");
      // Generate info
      lastName  = randomName( lastNameVec );
      firstName = randomName( firstNameVec );
      grade     = generateGrade( allGrades );

      // 5)  Write a simple set of tests, including some random generation
      // of input values, to test your function representing assignment
      // 2/3's code. Add some tests that detect the contract violation.
      for ( index = 0; index <= 1000; index ++)
      {
        grade     = generateGrade( allGrades );

        // check if grade is bad
          // grade must be between 0 and 100
        if ( grade < 0 || grade > 100 )
        {
          printString("BAD!!!!!!!!!!!!!!");

          // (6) Write assertions in your code to check a contract
          assert(("Grade has been generated wrong.", false));
        }
      }

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

      // log student
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

      // log
      Logger.LogInfo("Searching for student: " + lastName + ", " + firstName);

      // search for student
      studentBST.searchForStudent( lastName, firstName );
    }

    // Option 3
    else if ( input == "3")
    {
      studentBST.displayInOrder();
      Logger.LogInfo("Displaying tree in order.");
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
    // (6) Add a preconditon to reject the bad inputs;
    // not just those violating the contract, but the inputs that cause
    // the non-contract bug to trigger.


    if ( !gradeInVector( grade, allGrades) )
    {
      // append to vec
      allGrades.push_back( grade );

      // insert to BST
      studentBST.insert( lastName, firstName, grade );

      // log student to file
      Logger.LogStudent( firstName, lastName, gradeStr );
    }
  }
}
