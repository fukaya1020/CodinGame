#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define COMMAND_LENGTH 6

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int R; // the length of the road before the gap.
    scanf("%d", &R);
    int G; // the length of the gap.
    scanf("%d", &G);
    int L; // the length of the landing platform.
    scanf("%d", &L);
    int Destination = R + G + L;
    int RestX = Destination;

    // game loop
    while (1) {
        int S; // the motorbike's speed.
        scanf("%d", &S);
        int X; // the position on the road of the motorbike.
        scanf("%d", &X);
        char Command[COMMAND_LENGTH] = "";

        if (R + G - X > 0) {            //現在位置がギャップ終わり地点よりも前
            if (R + G - X > S) {        //現在位置＋現スピードがギャップ終わり地点よりも前
                if (S < G + 1)          //現スピードがギャップの長さよりも遅い
                    strcpy(Command, "SPEED"); 
                else if (S > G + 1)     //現スピードがギャップの長さよりも早い
                    strcpy(Command, "SLOW"); 
                else                    //現スピードがギャップの長さと同じ
                    strcpy(Command, "WAIT");
           }
           else                         //現在位置＋現スピードがギャップ終わり地点よりも後
                strcpy(Command, "JUMP"); 
        }
        else                            //現在位置がギャップ終わり地点よりも後
            strcpy(Command, "SLOW");

        fprintf(stderr, "X:%d, Speed:%d, RestX%d\n", X, S, RestX);
        fprintf(stderr, "Length to Gap:%d, Gap Length:%d, Landing PF:%d\n", R, G, L);

        RestX -= S;
        printf("%s\n", Command); // A single line containing one of 4 keywords: SPEED, SLOW, JUMP, WAIT.
    }
}