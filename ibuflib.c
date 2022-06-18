#include <conio.h>
#include <windows.h>
#include "ibuflib.h"
#define MAX_OUTPUT 512
#define bool int
#define COLOR int

void readcharacter_(char* character) {(*character) = getch();}
void readstring_(char* string, int const length) {
    int i = 0;
    char errorMessage1[256] = "\nError - too long expression (1)\0";
    for (i = 0; i < length - 1; i++) {
        readcharacter_(string+i);
        if(*(string+i) == '\r') {
            *(string+i) = '\0';
            break;
        }
        if(*(string+i) == '\b') {
            *(string+i) = ' ';
            i--;
            *(string+i) = '\0';
            i--;
        }
        else {
            *(string+i+1) = '\0';
            putch('\b');putch(' '); putch('\b');
        }
        if (i == length-2) {
            for (int j = 0; errorMessage1[i] != '\0'; i++) {
                putch(errorMessage1[i]);
            }
        }
    }
}
void readstringe_(char* string, int const length) {
    int i = 0;
    char errorMessage1[33] = "\nError - too long expression (1)\0";
    for (i = 0; i < length - 1; i++) {
        readcharacter_(string+i);
        if(*(string+i) == '\r') {
            *(string+i) = '\0';
            break;
        }
        else if(*(string+i) == '\b') {
            putch('\b');putch(' '); putch('\b');
            *(string+i) = ' ';
            i--;
            *(string+i) = '\0';
            i--;
        }
        else {
            *(string+i+1) = '\0';
            putch(*(string+i));
        }
        if (i == length-2) {
            for (int j = 0; errorMessage1[i] != '\0'; i++) {
                putch(errorMessage1[i]);
            }
        }
    }
}
