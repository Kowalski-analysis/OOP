#include "funcs.h"

const char *MSGS[] = {"0. Quit", "1. Show parameters", "2. Change parameters", "3. Show coordinates", "4. Show radii", "5. Show radius of curvature", "6. Show type of hypocycloid", "7. Show sectorial square\n"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);

int main() {
    int c;
    Hypocycloid Figure;
    do
    {
        c = Dialog(MSGS, MSGS_SIZE);
        switch (c)
        {
            case 0:
                break;
            case 1:
            {
                Show_parameters(Figure);
                break;
            }
            case 2:
            {
                Change_parameters(&Figure);
                break;
            }
            case 3:
            {
                Show_coordinates(Figure);
                break;
            }
            case 4:
            {
                Show_radii(Figure);
                break;
            }
            case 5:
            {
                Show_radius_curvature(Figure);
                break;
            }
            case 6:
            {
                Show_type(Figure);
                break;
            }
            case 7:
            {
                Show_square(Figure);
                break;
            }
            default: {
                break;
            }
        }
    } while (c != 0);
    return 0;
}
