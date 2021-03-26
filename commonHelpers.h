// ===================================================================================
//  Assignment: 2 //  Milestone : 2
// ===================================================================================
//  Student Name  : Edgar David Garcia Torres
//  Student ID    : 104433206
//  Student Email : edgarciat-torres@myseneca.ca
//  Course Section: ZZA
// ===================================================================================

// ----------------------------------------------------------------------------
// defines/macros


// ----------------------------------------------------------------------------
// structures


//----------------------------------------------------------------------------
// function prototypes

#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_
// Header file contents goes here...

int currentYear(void);
void clearStandardInputBuffer(void);

int currentYear(void);
void clearStandardInputBuffer(void);

// 1. function to get integers 
int getInteger();

// 2. function to get positive integers
int getPositiveInteger();

// 3. Function to get integers with in a range given in the arguments
int getIntFromRange(int min, int max);

// 4. Function to get float point double numbers
double getDouble();

// 5. Function to positive double numbers
double getPositiveDouble();

// 6. Function to get single characters
char getCharOption(char C[7]);

// 7. function to get strings with a defined length
void getCString(char* C, int  min, int max);

#endif // !COMMON_HELPERS_H_