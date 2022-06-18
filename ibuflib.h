#ifndef IOBUFLIB_H_
#define IOBUFLIB_H_
#include <conio.h>
#include <windows.h>
#include "ibuflib.c"
#define MAX_OUTPUT 512
#define bool char
#define COLOR int

void readcharacter_(char* character);
void readstring_(char* string, int const length);
void readstringe_(char* string,int const length);

#endif
