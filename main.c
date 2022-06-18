#include <conio.h>
#include <time.h>
#include <math.h>
#include "ibuflib.h"


char _messWin[62] = "\nCorrect! Press Y to continue, or N to exit, R for rush mode: \0";
char _messLoss[62] = "\nWrong! Press Y to continue, or N to exit, R for rush mode: \0";

void writeExpression(int numA, char sign, int numB)
{
    const int L = 10;
    char TnumA[L], TnumB[L];
    itoa(numA, TnumA, 10);
    itoa(numB, TnumB, 10);
    for (int i=0;TnumA[i]!='\0';i++) {putch(TnumA[i]);} putch(sign);
    for (int i=0;TnumB[i]!='\0';i++) {putch(TnumB[i]);} putch('=');
}

int main()
{
    char Answer, Sign, result[10];;
    int isUsing = 1, isCorrect = 0, isRashmode = 0;
    int NumA = rand()&10+1, NumB = rand()&10+1, TNumC = rand()%4+1;

    while (isUsing > 0) {
        system("cls");
        isCorrect = 0;
        srand(time(NULL));
        NumA = rand()&10+1, NumB = rand()&10+1, TNumC = rand()%4+1;
        if (NumB == 0 && TNumC == 4) {
            NumB = rand()&10+1;
        }
        switch(TNumC) {
            case 1: Sign = '+'; break;
            case 2: Sign = '-'; break;
            case 3: Sign = 'x'; break;
            case 4: Sign = '/'; break;
            default: Sign = 'F'; break;
        }
        writeExpression(NumA, Sign, NumB);
        readstringe_(result, 10);

        switch(TNumC) {
            case 1: {if ((atoi(result)) == (NumA+NumB)) {isCorrect = 1;} break;}
            case 2: {if ((atoi(result)) == (NumA-NumB)) {isCorrect = 1;} break;}
            case 3: {if ((atoi(result)) == (NumA*NumB)) {isCorrect = 1;} break;}
            case 4: {if ((atoi(result)) == (NumA/NumB)) {isCorrect = 1;} break;}
            default: putch('w'); break;
        }

        if (isCorrect == 1 && !(isRashmode)) {
            for (int i = 0; _messWin[i] != '\0'; i++) {
                putch(_messWin[i]);
            }
        }
        else if (isCorrect == 0 && !(isRashmode)) {
            for (int i = 0; _messLoss[i] != '\0'; i++) {
                putch(_messLoss[i]);
            }
        }
        else if (isCorrect == 0 && isRashmode) {
            isRashmode = 0;
            for (int i = 0; _messLoss[i] != '\0'; i++) {
                putch(_messLoss[i]);
            }
        }

        if(isRashmode == 1) {
            continue;
        }

        readcharacter_(&Answer);


        if (Answer == 'N' || Answer == 'n') {
            break;
        }
        else if (Answer == 'Y' || Answer == 'y') {
            continue;
        }
        else if (Answer == 'R' || Answer == 'r') {
            isRashmode = 1;continue;
        }
    }

    return 0;
}

