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

void createNameStr( Employee emp, string &outstr );
stack<Employee> createStack();
queue<Employee> createQueue();

void displayMenu();
//void displayQueue( queue<Employee> );
//void displayStack( stack<Employee> );
void displayVector( vector<Employee> empVect );

//void insertionSort(vector<Employee> &vec);

void printEndline();
void printEmployeeString( Employee emp, string beg );
void printInteger( int num );
void printString( string str );

int promptForInteger( string prompt );
string promptForString( string prompt );

void pushToStack( stack<Employee> &stack, Employee emp );
void removeFromStack( stack<Employee> &stack );

int main()
{
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


  printString("\n\n ===== Beginning Vector Operations =====\n\n");
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

  // VECTOR OPERATONS
  printString("\nDisplaying Employee Vector: Unsorted\n\n");
  displayVector(empVect);

  printString("\n\n ===== Sorting by Bubble Sort =====\n\n");
  bubbleSort(empVect);

  printString("\n\nDisplaying Employee Vector: Bubble Sorted by Surname\n\n");
  displayVector(empVect);

  // STACK OPERATIONS
  printString("\n\n ===== Beginning Stack Operations =====\n\n");

    printString("\n\nPushing employees to stack:\n\n");

    // add employees to stack
    for ( index = 0; index < empVect.size(); index++ )
    {
      printEmployeeString( empVect[ index ], "\tPushing Employee: " );
      pushToStack( stack, empVect[ index ] );
    }

    printString("\n\nRemoving employees from stack:\n\n");

    for ( index = 0; index < 4; index++ )
    {
      printEmployeeString( stack.top(), "\tRemoving Employee: " );
      removeFromStack( stack );
    }

    printString("\n\nPushing employees to stack:\n\n");

    for ( index = 0; index < 1; index++ )
    {
      printEmployeeString( empVect[ index ], "\tPushing Employee: " );
      pushToStack( stack, empVect[ index ] );
    }

    printString("\n\nRemoving all employees from stack:\n\n");

    for ( index = 0; index < stack.size(); index++ )
    {
      printEmployeeString( stack.top(), "\tRemoving Employee: " );
      removeFromStack( stack );
    }

  printString("\n\n ===== Sorting by Insertion Sort =====\n\n");

  // Sort employees by insertion sort
  //insertionSort( empVect );

  // get priority Queue
  printString("\n\nDisplaying Employee Vector: Interstion Sorted by Admin Level\n\n");
  displayVector(empVect);

  return 0;
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

void createNameStr( Employee emp, string &outstr )
{
  string name = emp.name;
  string surname = emp.surname;
  string password = emp.pass;
  string adminLevel = to_string(emp.adminLevel);

  outstr = outstr + "NAME: " + surname + ", " + name
         + " | PASSWORD: " + password
         + " | ADMIN LEVEL: " + adminLevel;
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

void displayVector( vector<Employee> empVect )
{
  int index;
  string beg;

  for ( index = 0; index < empVect.size(); index++ )
  {
    beg = "\t" + to_string(index + 1) + ") ";
    printEmployeeString( empVect[ index ], beg );
  }
  printEndline();
}

void displayMenu()
{
  printString("Menu:\n");
  printString("1) Add Employees\n");
  printString("2) Display Employees\n");
}

/*
void insertionSort(vector<Employee> &vec)
{
  int n = vec.size();
  Employee key;
  int i, j;

  for (i = 1; i < n; i++)
  {
    key = vec[i];
    j = i - 1;

    while (j >= 0 && vec[j].adminLevel > key.adminLevel)
    {
      vec[j + 1] = vec[j];
      j = j - 1;
    }
    vec[j + 1] = key;
  }
}

*/
void printEmployeeString( Employee emp, string beg )
{
  string outstr = beg;

  createNameStr( emp, outstr );

  printString( outstr );

  printEndline();
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
  stack.push( emp );
}

void removeFromStack( stack<Employee> &stack )
{
  stack.pop( );
}
