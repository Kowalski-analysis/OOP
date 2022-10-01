#include "funcs.h"

int Dialog (const char *msgs[], int n)
{
    const char *error = "";
    int choice;
    do
    {
        puts(error);
        error = "You're wrong. Try again!";
        for (int i = 0; i < n; ++i)
        {
            puts(msgs[i]);
        }
        int eof = getNum(choice);
        if (eof == -1)
        {
            return 0;
        }
    } while (choice < 0 || choice >= n);
    return choice;
}
