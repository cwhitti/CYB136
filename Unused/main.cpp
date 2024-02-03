#include <iostream>
#include <stdio.h>

/*
  This is silly program inspired by the obsolete internet legend, LongCat.
  The user is prompted to enter a numerical length for LongCat.
  Then, the program prints either an explosion or a very enlongated LongCat.
  A humorous response is added after, reacting to the user's input.
*/

// function prototypes
void draw_cat(int length);
void draw_explosion();
void print_array(const char* array[]);
int get_size(const char* array[]);
int validate_input();

int main()
{
  // declare variables
  int length;

  // show introduction
  printf("\n");
  printf("Name: Claire Whittington\n");
  printf("Class: CYB136\n");
  printf("Task: Assignment #1\n\n");

  printf("Welcome to LongCat generator!\n\n");

  length = validate_input();

  // react to cat
  if (length < 0)
  {
    printf("\nWait... you want a NEGATIVE LongCat???\n\n");

    draw_explosion();

    printf("\nLongCat exploded!!!!!!\n\n");

    printf(":(\n");
  }

  else if ( length != 0 )
  {
    if (length <= 1000000)
    {
      draw_cat(length);

      if ( length <= 5)
      {
        printf("\nYeah, that's about a normal-sized cat.\n");
      }

      else if ( length <= 1000 )
      {
        printf("\nOkay that's a pretty long cat. Nice.\n");
      }

      else
      {
        printf("\nHoly Moly!!! That's a LongCat!!!!!!!!! \n");
      }
    }

    else if ( length > 1000000 )
    {
      printf("\nHuh?\n");
      printf("\nThat's... that's not possible!!!\n\n");
      draw_explosion();
      printf("\nNot even LongCat could handle that length.\n\n");
    }
  }
  else
  {
    printf("\nSilly, LongCat can't be zero long!!\n");
  }
}

// draw the cat
void draw_cat(int length)
{
  // declare variables
  int index;
  const char* middle_cat[] =
  {
    "                   |    ```     |",
    nullptr
  };

  const char* top_cat[] =
    {
      "                 __       / |     ",
      "                 \\ \"-..--'_4|_    ",
      "      _._____     \\ _  _(C \"._'._ ",
      "     ((^     '\"-._( O_ O \".` '. \\",
      "      `\"'--._     \\  y_     \\   \\|",
      "             '-._  \\_ _  __.=-.__,\\_",
      "                 `'-(\" ,(\"___       \\,_____",
      "                     (_,(\"___     .-./     '",
      "                     |   C'___    (5)",
      "                     /    ``  '---'-'.\\",
      "                    |     ```    |`    '\"-._",
      "                    |    ````    \\-.`",
      "                    |    ````    |  \"._ ``",
      "                    /    ````    |     '-.__",
      "                   |     ```     |",
      "                   |     ```     |",
      "                   |     ```     |",
      "                   |     ```     /",
      "                   |    ````    |",
      "                   |    ```     |",
      "                   |    ```     |",
      "                   |    ```     /",
      nullptr
    };

  const char* bottom_cat[] =
    {
      "                   |    ```     |",
      "                   |    ```     |",
      "                   /    ```     |",
      "                  |     ```     |",
      "                  |     ```     !",
      "                  |     ```    / '-.___",
      "                  |    ````    !_      ''-",
      "                  /   `   `    | '--._____)",
      "                  |     /|     !",
      "                  !    / |     /",
      "                  |    | |    /",
      "                  |    | |   /",
      "                  |    / |   |",
      "                  /   /  |   |",
      "                 /   /   |   |",
      "                (,,_]    (,_,)",
      nullptr
    };


  // printf each element of the array
  print_array(top_cat);

  // Print each element of the array
  for (index = 0; index < length; index = index + 1)
  {
    print_array(middle_cat);
  }

  print_array( bottom_cat );
}

// draw an explosion
void draw_explosion()
{
  const char* explosion[] =
  {
      "          _.-^^---....,,---_",
      "       _--                  --_",
      "      <          BOOM!         >)",
      "       \\._                   _./",
      "          ```--. . , ; .--'''",
      "                | |   |",
      "           .-=||  | |=-.",
      "             `-=#$%&%$#=-'",
      "                | ;  :|",
      "       _____.,-#%&$@%#&#~,._____",
      nullptr
  };

  print_array( explosion );
}

// get size of an array
int get_size(const char* array[])
{
  int index = 0;

  while ( array[ index ] != nullptr )
  {
    index++;
  }

  return index;
}

// get size of a string
int get_size_str( char string[128] )
{
  int index = 0;

  while ( string[index] != '\0' )
  {
    index++;
  }

  return index;

}

// print an array
void print_array(const char* array[])
{
  int index = 0;
  int size = get_size( array );

  for (index = 0; index < size; ++index)
  {
    printf("%s\n", array[index] );
  }
}

// validate user input
int validate_input()
{
  // declare variables
  int index, inputSize;
  long int length;
  char inputString[128];
  bool validInput = false;

  // get valid input
  do
  {
    // ask for how long cat should be
    printf("How long should LongCat be? ");
    scanf("%s", inputString);

    index = 0;
    inputSize = get_size_str( inputString );

    // check all letters in input
    while (index < inputSize && isdigit( inputString[ index ] ) )
    {
      ++index;
    }

    // check if every loop
    if (index == inputSize)
    {
      length = std::stoi(inputString);
      validInput = true;
    }

    else
    {
      printf("\n");
      printf("LongCat didn't like that number. Try again!\n\n");
    }
  } while ( !validInput );

  return length;
}
