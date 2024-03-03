#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Employee
{
  public:

    // declare variable
    string name;
    string surname;
    string pass;
    int adminLevel;

    // constructor
    Employee(string empName, string empSurname, string empPass, int empLevel)
    {
      name = empName;
      surname = empSurname;
      pass = encryptPassword( empPass );
      adminLevel = empLevel;
    }

    string encryptPassword( string empPass )
    {
      // declare variables
      string salt = "KjqTa8Gg0qprf0xwV4s7AVCXE";
      string hash;
      int index, passLen = empPass.length();
      char encryptedChar;

      // sum integer values of pass characeter
      for ( index = 0; index < passLen; index++ )
      {
        encryptedChar = empPass[ index ] ^ salt[index % salt.length()];

        encryptedChar = ( (encryptedChar % ('z' - '0' + 1)) + '0');

        if ( (encryptedChar > '9') && (encryptedChar < 'A') )
        {
          encryptedChar = encryptedChar + ( 'A' - '9');
        }

        if ( (encryptedChar > 'Z') && (encryptedChar < 'a') )
        {
          encryptedChar = encryptedChar + ( 'a' - 'Z');
        }

        hash += encryptedChar;
      }

      return hash;
    }
};

// Prototypes
void bubbleSort(vector<Employee>& vec);

stack<Employee> createStack();
queue<Employee> createQueue();

void displayMenu();
void displayQueue( queue<Employee> );
void displayStack( stack<Employee> );
void displayVector( vector<Employee> empVect );

void printEndline();
void printEmployeeString( Employee emp, int index );
void printInteger( int num );
void printString( string str );

int promptForInteger( string prompt );
string promptForString( string prompt );

void pushToStack( stack<Employee> &stack, Employee emp );

int main()
{
  /
  // initialize variables
  vector<Employee> empVect;
  stack<Employee> stack = createStack();
  queue<Employee> queue = createQueue();

  int index;

  Employee emp1  = Employee("Emily", "Skinner", "SwiftCat573", 1);
  Employee emp2 = Employee("Guillermo", "Maynard", "CrimsonRiver224", 3);
  Employee emp3  = Employee("Frederic", "Hart", "VelvetRose654", 2);
  Employee emp4  = Employee("Doyle", "Simon", "CelestialSky456", 3);
  Employee emp5  = Employee("Nikki", "Riley", "SparklingOcean1234", 4);
  Employee emp6  = Employee("Herman", "Richard", "GentleBreeze3210", 3);
  Employee emp7  = Employee("Edwina", "Calhoun", "LivelyBrook0987", 1);
  Employee emp8  = Employee("Bettie", "Sanchez", "SwiftEagle6543", 3);
  Employee emp9  = Employee("Aimee", "Vaughn", "CautiousLion8765", 4);
  Employee emp10  = Employee("Marcel", "Barnes", "TranquilCanyon6789", 4);
  Employee emp11  = Employee("Gwen", "Chase", "CuriousCat123", 2);
  Employee emp12  = Employee("Mac", "Williamson", "LuckyClover567", 4);
  Employee emp13  = Employee("Stephen", "Austin", "WiseOwl789", 3);
  Employee emp14  = Employee("Brianna", "Cooley", "FancyFlower123", 3);
  Employee emp15  = Employee("Carolyn", "Whitaker", "MysticMoon789", 3);


  // add employee
  empVect.push_back( emp1 );
  empVect.push_back( emp2 );
  empVect.push_back( emp3 );
  empVect.push_back( emp4 );
  empVect.push_back( emp5 );
  empVect.push_back( emp6 );
  empVect.push_back( emp7 );
  empVect.push_back( emp8 );
  empVect.push_back( emp9 );
  empVect.push_back( emp10 );
  empVect.push_back( emp11 );
  empVect.push_back( emp12 );
  empVect.push_back( emp13 );
  empVect.push_back( emp14 );
  empVect.push_back( emp15 );

  // sort employees by admin level
  printString("\nDisplaying Employee Vector: Unsorted\n");
  displayVector(empVect);

  bubbleSort(empVect);

  printString("\n\nDisplaying Employee Vector: Bubble Sorted by Surname\n");
  displayVector(empVect);

  // STACK OPERATIONS
  printString("\n\nBeginning Stack Operations\n");

    // add employees to stack
    for ( index = 0; index < )

    // print STACK

    // remove 2 employees

    // print stack

    // add two new employees

  // sort employees by name, print using QUEUE

  // get priority Queue

  // display employees

  return 0;
}


// Function to create a stack of Employee objects
stack<Employee> createStack()
{
  stack<Employee> newStack;
  return newStack;
}

// Function to create a queue of Employee objects
queue<Employee> createQueue()
{
  queue<Employee> newQueue;
  return newQueue;
}

// Bubble Sort function for sorting Employee objects by surname
void bubbleSort(vector<Employee>& vec)
{

  int size = vec.size();
  int outerIndex, innerIndex;

  for (outerIndex = 0; outerIndex < size - 1; outerIndex++)
  {
    for (innerIndex = 0; innerIndex < size - outerIndex - 1; innerIndex++)
    {
      // Compare surnames
      if (vec[innerIndex].surname > vec[innerIndex + 1].surname)
      {
        // Swap if the condition is true
        swap(vec[innerIndex], vec[innerIndex + 1]);
      }
    }
  }
}

void displayQueue( queue<Employee> )
{

}

void displayStack( stack<Employee> )
{

}

void displayVector( vector<Employee> empVect )
{
  int index;

  for ( index = 0; index < empVect.size(); index++ )
  {
    printEmployeeString( empVect[ index ], index );
  }
  printEndline();
}

void displayMenu()
{
  printString("Menu:\n");
  printString("1) Add Employees\n");
  printString("2) Display Employees\n");
}

void printEmployeeString( Employee emp, int index )
{
  string name = emp.name;
  string surname = emp.surname;
  string pass = emp.pass;
  int level = emp.adminLevel;

  printEndline();
  printString("\t");
  printInteger(index + 1);
  printString( ") NAME: " );
  printString( surname );
  printString( ", " );
  printString( name );
  printString( " | PASSWORD: " );
  printString( pass );
  printString( " | ADMIN LEVEL: " );
  printInteger( level );

}

int promptForInteger( string prompt )
{
  int outNum;

  cout << prompt;
  cin >> outNum;

  return outNum;
}

string promptForString( string prompt )
{
  string outStr;

  cout << prompt;
  cin >> outStr;

  return outStr;
}

void printEndline()
{
  cout << "\n";
}
void printString( string str )
{
  cout << str;
}

void printInteger( int num )
{
  cout << num;
}

void pushToStack( stack<Employee> &stack, Employee emp )
{
  stack.push( emp )
}
