#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int LX; // the X position of the light of power
    int LY; // the Y position of the light of power
    int TX; // Thor's starting X position
    int TY; // Thor's starting Y position
    scanf("%d%d%d%d", &LX, &LY, &TX, &TY);

    int CurrentX = TX; //Thor's current X position
    int CurrentY = TY; //Thor's current Y position

    // game loop
    while (1) {
        char direction[3] = "";
        int E; // The level of Thor's remaining energy, representing the number of moves he can still make.
        scanf("%d", &E);

        if (LY > CurrentY) {
            CurrentY++;
            strcat(direction, "S");
        }
        else if (LY < CurrentY) {
            CurrentY--;
            strcat(direction, "N");
        }
        if (LX > CurrentX) {
            CurrentX++;
            strcat(direction, "E");
        }
        else if (LX < CurrentX) {
            CurrentX--;
            strcat(direction, "W");
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        fprintf(stderr, "Direction:%s, Position: %d.%d\n", direction, CurrentX, CurrentY);

        printf("%s\n", direction); // A single line providing the move to be made: N NE E SE S SW W or NW
    }
}