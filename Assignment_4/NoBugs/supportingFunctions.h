#ifndef SUPPORTINGFUNCTIONS_H
#define SUPPORTINGFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <random>
#include <vector>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>


using namespace std;

// header declarations
void displayMenu();
void initializeVectorFromFile( string fileName, vector <string> &vec );
void printString( string str );
string promptForString( string prompt );
bool gradeInVector( double grade, vector <double> allGrades);
double generateGrade( vector <double> &allGrades );
string randomName( vector <string> nameVec );

#endif
