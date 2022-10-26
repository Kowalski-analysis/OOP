#include "antiplagiat_dialog.h"
#include <limits>
#include <filesystem>

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
    const char *MSGS[] = {"0. Quit", "1. Check quality of password", "2. Enter login and password\n"};
    const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);
    int c;
    std::string path1("../F1.txt");
    std::string path2("../F2.txt");
    do
    {
        c = Dialog(MSGS, MSGS_SIZE);
        switch (c)
        {
            case 0:
                break;
            case 1:
            {
                std::fstream fin = FOpen(path1, 1);
                std::fstream fout = FOpen(path2, 0);
                Result(fin, fout);
                break;
            }
            case 2:
            {
                std::string str1("\n"), str2;
                std::fstream fout = FOpen(path1, 2);
                std::cout << "Enter a login" << std::endl;
                std::cin >> str1;
                str1 += ' ';
                std::cout << "Enter a password" << std::endl;
                std::cin >> str2;
                str2 += ' ';
                FWrite(fout, str1, str2);
                break;
            }
            case 3:
            {
                std::string path = "/path/to/directory";
                for (const auto & entry : std::filesystem::directory_iterator(path))
                    std::cout << entry.path() << std::endl;
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