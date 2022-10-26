#include "antiplagiat_dialog.h"
#include <limits>

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

void Menu ()
{
    const char *MSGS[] = {"0. Quit", "1. Enter a password", "2. Check quality of password\n"};
    const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);
    int c;
    std::string path = "File.txt";
    FOpen(path);
    do
    {
        c = Dialog(MSGS, MSGS_SIZE);
        switch (c)
        {
            case 0:
                break;
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            default: {
                break;
            }
        }
    } while (c != 0);
}

template <typename T>
int getNum (T &Num)
{
    while (!(std::cin >> Num) || Num == INT32_MIN)
    {
        if (std::cin.eof())
            return -1;

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Invalid value" << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 1;
}

