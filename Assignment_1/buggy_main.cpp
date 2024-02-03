#include <iostream> // page 15
#include <math.h>
using namespace std; // page 21

int convert_to_base_10( char base2str[256] );
int get_str_len( char string[256] );
int to_power(int base, int exponent);

// base 10 to binary converter
int main()
{
  /*
  cout << "Hello, World!\n"; // page 15

  const type_name constant_name = initial_value; // page 53

  */

  // declare variables
  char base2str[256], tempStr[256];
  int base10, strLen, index;
  int choice;

  // introduction
  cout << "\n";
  cout << "Name: Claire Whittington\n";
  cout << "Class: CYB136\n";
  cout << "Task: Assignment #1\n\n";
  cout << "Welcome to the Binary to Base 10 converter\n";

  // show rules
  cout << "\n\tRules\n";
  cout << "- Please enter only positive values\n";

  cout<< "\n\tModes\n";
  cout << "[1] Left LSD  (100 = 1)\n";
  cout << "[2] Right LSD (100 = 4)\n";

  cout << "\nPlease pick your mode: ";
  cin >> choice;

  // get input
  cout << "\nPlease enter binary number: ";
  cin >> tempStr;

  strLen = get_str_len( tempStr );

  // copy temp to base2str forwards
  if (choice == 1)
  {
    // copy string to new string
    for ( index = 0; index <= strLen; index++ )
    {
      base2str[ index ] = tempStr[ index ];
    }
  }

  // copy temp to base2str backwards
  else
  {
    for ( index = strLen - 1; index >= 0; index-- )
    {
      base2str[ (strLen - 1) - index ] = tempStr[ index ];
    }
    base2str[strLen] = '\0';
  }

  base10 = convert_to_base_10( base2str );

  // print the output
  cout << "\nConversion to Base 10: " << base10 << "\n";

  return 0;
}

// CONVERTS FROM LEFT TO RIGHT
int convert_to_base_10( char base2str[256] )
{
  int index = 0, bit;
  int sum = 0;
  char mychar;

  // loop thru string
  while (base2str[index] != '\0')
  {
    // get character
    mychar = base2str[index];

    // see if bit is 1
    if (mychar == '1')
    {
      bit = 1;
    }

    // see if bit is zero
    else
    {
      bit = 0;
    }

    // add the power
    sum +=  bit * to_power(2, index);

    // increment the index
    index++;
  }

  // return tp function
  return sum;
}

// get length of a string
  // not including null terminator
int get_str_len( char string[256] )
{
  // initialize variables
  int len = 0;

  // loop thro string
  while (string[len] != '\0')
  {
    len++;
  }

  // return to function
  return len;
}

// raise base to a power
int to_power(int base, int exponent)
{
  // initialize variables
  int index;
  int sum = 1;

  // raise to power
  for (index = 0; index < exponent; index++)
  {
    sum = sum * base;
  }

  // return to function
  return sum;
}
