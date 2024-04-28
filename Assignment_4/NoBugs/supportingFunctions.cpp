#include "supportingFunctions.h"

void displayMenu()
{
  printString("[1] Generate New Student\n");
  printString("[2] Search Existing Student\n");
  printString("[3] Display BST In Order\n");
  printString("[4] Quit\n\n");
}

void initializeVectorFromFile( string fileName, vector <string> &vec )
{
  // Declare varables
  ifstream file;
  string name;

  // Close the file
  file.open( fileName );

  // (2) Write assertions in your code to check a contract
  assert(("First/Last Name File does not exist", file.is_open( ) ) );

  // skip header
  getline( file, name );

  // process file lines
  while ( getline( file, name ) )
  {
    vec.push_back( name );
  }
}

void printString( string str )
{
  cout << str;
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

string randomName( vector <string> nameVec )
{
  // Declare variables
  random_device rd;
  int index;
  string name;

  // seed the generator
  mt19937 gen(rd());
  uniform_int_distribution<> dis( 0 , nameVec.size() - 1);

  // generate the index
  index = dis(gen);

  // return the name
  return nameVec[ index % nameVec.size() ];
}

double generateGrade( vector <double> &allGrades )
{
  // Declare variables
  random_device rd;
  double grade;

  // seed the generator
  mt19937 gen(rd());
  uniform_real_distribution<> dis(1.0, 100.0);

  // generate the grade
  grade = dis(gen);

  // check that grade is not in vector already
  while ( gradeInVector( grade, allGrades ) )
  {
    grade = dis(gen);
  }

  allGrades.push_back(grade);

  return grade;
}

bool gradeInVector( double grade, vector <double> allGrades)
{
  // Declare variables
  int index = 0;
  int size = allGrades.size();

  // check if items in vector
  if ( size > 0 )
  {
    // loop thru vector
    for ( index = 0; index < size; index++ )
    {
      // compare grade
      if ( grade == allGrades[index])
      {
        return true;
      }
    } // end loop thru vector
  } // end size check
  return false;
}
