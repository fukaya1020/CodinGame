#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define COMMAND_LENGTH 5

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    // game loop
    while (1) {
        int SX;
        int SY;
        scanf("%d%d", &SX, &SY);

        int HighestMnt = -1; //最も高い山
        int AttackPoint = 0; //アタックポイント

        for (int i = 0; i < 8; i++) {
            int MH; // represents the height of one mountain, from 9 to 0. Mountain heights are provided from left to right.
            scanf("%d", &MH);
            if (HighestMnt < MH) {
                HighestMnt = MH;
                AttackPoint = i;
            }
        }

        if (AttackPoint == SX)
            printf("FIRE\n");
        else
            printf("HOLD\n");
    }
}