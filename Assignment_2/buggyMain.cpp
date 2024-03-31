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

struct compare
{
    bool operator()(Employee a, Employee b)
    {
        return a.adminLevel > b.adminLevel;
    }
};

// priority_queue<Employee, vector<Employee>, compare> queue:

// Prototypes
void bubbleSort(vector<Employee>& vec);

void createNameStr( Employee emp, string &outstr );
priority_queue<Employee, vector<Employee>, compare> createPriorityQueue();
stack<Employee> createStack();
queue<Employee> createQueue();

void displayIntro();
void displayMenu();
void displayMenu2();
void displayVector( vector<Employee> empVect );

void insertionSort( vector<Employee>& employees );

void printEndline();
void printEmployeeString( Employee emp, string beg );
void printInteger( int num );
void printString( string str );

int promptForInteger( string prompt );
string promptForString( string prompt );

void pushToPriorityQueue( priority_queue<Employee, vector<Employee>, compare> &queue, Employee emp );
void pushToQueue( queue<Employee> &queue, Employee emp );
void pushToStack( stack<Employee> &stack, Employee emp );

void removeFromPriorityQueue( priority_queue<Employee, vector<Employee>, compare> &queue);
void removeFromQueue( queue<Employee> &queue );
void removeFromStack( stack<Employee> &stack );

int main()
{
  // initialize variables
  vector<Employee> empVect;
  stack<Employee> stack = createStack();
  queue<Employee> queue = createQueue();
  priority_queue<Employee, vector<Employee>, compare> pQueue;

  int index;
  string choice = "";
  bool moveOn = false;

  Employee emp1  = Employee("Emily", "Skinner", "SwiftCat573", 1);
  Employee emp2 = Employee("Guillermo", "Maynard", "CrimsonRiver224", 2);
  Employee emp3  = Employee("Frederic", "Hart", "VelvetRose654", 3);
  Employee emp4  = Employee("Doyle", "Simon", "CelestialSky456", 4);
  Employee emp5  = Employee("Nikki", "Riley", "SparklingOcean1234", 5);
  Employee emp6  = Employee("Herman", "Richard", "GentleBreeze3210", 6);
  Employee emp7  = Employee("Edwina", "Calhoun", "LivelyBrook0987", 2);
  Employee emp8  = Employee("Bettie", "Sanchez", "SwiftEagle6543", 7);
  Employee emp9  = Employee("Aimee", "Vaughn", "CautiousLion8765", 8);
  Employee emp10  = Employee("Marcel", "Barnes", "TranquilCanyon6789", 3);
  Employee emp11  = Employee("Gwen", "Chase", "CuriousCat123", 8);
  Employee emp12  = Employee("Mac", "Williamson", "LuckyClover567", 4);
  Employee emp13  = Employee("Stephen", "Austin", "WiseOwl789", 2);
  Employee emp14  = Employee("Brianna", "Cooley", "FancyFlower123", 8);
  Employee emp15  = Employee("Carolyn", "Whitaker", "MysticMoon789", 2);

  printString("\n\n ===== Beginning Vector Operations =====\n\n");

  // add employees
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

  displayIntro();

  while ( choice != "4" )
  {
    displayMenu();

    choice = promptForString("Choice: ");

    if ( choice == "1" )
    {
      // display employee vector
      printString("\nDisplaying Employee Vector\n\n");
      displayVector(empVect);
      moveOn = true;
    }

    else if ( choice == "2" )
    {
      // printString("2) Sort employees by last name with Bubble Sort\n");
      printString("\n\n ===== Sorting by Bubble Sort =====\n\n");
      bubbleSort(empVect);

      printString("\n\nDisplaying Employee Vector: Bubble Sorted by Surname\n\n");
      displayVector(empVect);
      moveOn = true;
    }

    else if ( choice == "3" )
    {
      //printString("3) Sort employees by admin level with Insertion Sort\n");
      printString("\n\n ===== Sorting by Insertion Sort =====\n\n");

      // Sort employees by insertion sort
      insertionSort( empVect );

      // get priority Queue
      printString("\n\nDisplaying Employee Vector: Interstion Sorted by Admin Level\n\n");
      displayVector(empVect);
      moveOn = true;
    }

    if (moveOn)
    {
      // moveOn = false;

      displayMenu2();

      choice = promptForString("Choose data structure: ");

      if ( choice == "1" )
      {
        // STACK OPERATIONS
        printString("\n\n ===== Beginning Stack Operations =====\n\n");

          printString("\n\nPushing employees to stack:\n\n");

          // add employees to stack
          for ( index = 0; index < empVect.size(); index++ )
          {
              printEmployeeString( empVect[ index ], "\tPushing Employee: " );
              pushToStack( stack, empVect[ index ] );
          }

            printString("\n\nRemoving a few employess from stack:\n\n");

            for ( index = 0; index < 8; index++ )
            {
              printEmployeeString( stack.top(), "\tRemoving Employee: " );
              removeFromStack( stack );
            }

            printString("\n\nPushing employees to stack:\n\n");

            for ( index = 0; index < 3; index++ )
            {
              printEmployeeString( empVect[ index ], "\tPushing Employee: " );
              pushToStack( stack, empVect[ index ] );
            }

            printString("\n\nRemoving all employees from stack:\n\n");

            while (!stack.empty())
            {
              printEmployeeString( stack.top(), "\tRemoving Employee: " );
              removeFromStack( stack );
            }

        printString("\n\n ===== Beginning Stack Operations =====\n\n");
      }

      else if ( choice == "2" )
      {
        // NORMAL QUEUE OPERATIONS
        printString("\n\n ===== Beginning Normal Queue Operations =====\n\n");

          printString("\n\nPushing employees to Queue:\n\n");

            // add employees to stack
            for ( index = 0; index < empVect.size(); index++ )
            {
              printEmployeeString( empVect[ index ], "\tPushing Employee: " );
              pushToQueue( queue, empVect[ index ] );
            }

            printString("\n\nRemoving a few employess from queue:\n\n");

            for ( index = 0; index < 8; index++ )
            {
              printEmployeeString( queue.front(), "\tRemoving Employee: " );
              removeFromQueue( queue );
            }

            printString("\n\nPushing employees to queue:\n\n");

            for ( index = 0; index < 3; index++ )
            {
              printEmployeeString( empVect[ index ], "\tPushing Employee: " );
              pushToQueue( queue, empVect[ index ] );
            }

            printString("\n\nRemoving all employees from queue:\n\n");

            while ( !queue.empty() )
            {
              printEmployeeString( queue.front(), "\tRemoving Employee: " );
              removeFromQueue( queue );
            }

        printString("\n\n ===== Ending Normal Queue Operations =====\n\n");
      }

      else if ( choice == "3" )
      {
        printString("\n\n ===== Beginning Priority Queue Operations =====\n\n");

          printString("\nHIGHEST PRIORITY: Level 1");
          printString("\nLOWEST PRIORITY : Level 8");

          printString("\n\nPushing employees to Priority Queue:\n\n");

          // add employees to stack
            for ( index = 0; index < empVect.size(); index++ )
            {
              printEmployeeString( empVect[ index ], "\tPushing Employee: " );
              pushToPriorityQueue( pQueue, empVect[ index ] );
            }

            printString("\n\nRemoving a few employess from Priority queue:\n\n");

            for ( index = 0; index < 8; index++ )
            {
              printEmployeeString( pQueue.top(), "\tRemoving Employee: " );
              removeFromPriorityQueue( pQueue );
            }

            printString("\n\nPushing employees to Priority queue:\n\n");

            for ( index = 0; index < 3; index++ )
            {
              printEmployeeString( empVect[ index ], "\tPushing Employee: " );
              pushToQueue( queue, empVect[ index ] );
            }

            printString("\n\nRemoving all employees from Priority queue:\n\n");

            while ( !queue.empty() )
            {
              printEmployeeString( pQueue.top(), "\tRemoving all Employees from Priority Queue: " );
              removeFromQueue( queue );
            }

        printString("\n\n ===== Ending Priority Queue Operations =====\n\n");
      }
    }
  }
  printString("Ending program.\n");
  // VECTOR OPERATONS
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

void displayIntro()
{
  printString("\nWelcome to the CYB136 Queue and Stack demonstration!");
  printString("\nThis program creates employees and adds them to a list.");
  printString("\nEmployyes have a firts name, last name, encrypyted password, and admin level.");
  printString("\nAs for admin levels, 1 is the highest priority level and 8 is the lowest.");
}

void displayMenu()
{
  printString("\n\n\tMENU\n");
  printString("1) Show Employees\n");
  printString("2) Sort employees by last name with Bubble Sort\n");
  printString("3) Sort employees by admin level with Insertion Sort\n");
  printString("4) QUIT\n\n");
}

void displayMenu2()
{
  printString("\n\n\tMENU\n");
  printString("1) Demonstate Stack\n");
  printString("2) Demonstate Normal Queue\n");
  printString("3) Demonstate Priority Queue (based on admin level)\n");
  printString("4) QUIT\n\n");
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

void insertionSort(vector<Employee>& employees)
{
  int n = employees.size();
  for (int i = 1; i < n; ++i)
  {
    Employee key = employees[i];
    int j = i - 1;

    // Move elements of employees[0..i-1], that are greater than key.adminLevel, to one position ahead of their current position
    while (j >= 0 && employees[j].adminLevel < key.adminLevel)
    {
      employees[j + 1] = employees[j];
      j = j - 1;
    }
    employees[j + 1] = key;
  }
  }

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

void pushToPriorityQueue( priority_queue<Employee, vector<Employee>, compare> &queue, Employee emp )
{
  queue.push( emp );
}

void pushToQueue( queue<Employee> &queue, Employee emp )
{
  queue.push( emp );
}

void pushToStack( stack<Employee> &stack, Employee emp )
{
  stack.push( emp );
}

void removeFromPriorityQueue( priority_queue<Employee, vector<Employee>, compare> &queue )
{
  queue.pop( );
}
void removeFromQueue( queue<Employee> &queue)
{
  queue.pop( );
}

void removeFromStack( stack<Employee> &stack )
{
  stack.pop( );
}
