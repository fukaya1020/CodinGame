#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TARGET_NAME_LENGTH 256

/**
 * CodinGame planet is being attacked by slimy insectoid aliens.
 **/
int main()
{

    // game loop
    while (1) {
        char enemy1[TARGET_NAME_LENGTH]; // name of enemy 1
        scanf("%s", enemy1);
        int dist1; // distance to enemy 1
        scanf("%d", &dist1);
        char enemy2[TARGET_NAME_LENGTH]; // name of enemy 2
        scanf("%s", enemy2);
        int dist2; // distance to enemy 2
        scanf("%d", &dist2);
        int minDist = 0; //ç≈íZÇÃìGÇ‹Ç≈ÇÃãóó£
        char target[TARGET_NAME_LENGTH] = ""; //ç≈íZÇÃìG

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        if (dist1 <= dist2) {
            minDist = dist1;
            strcpy(target, enemy1);
        }    
        else {
            minDist = dist2;
            strcpy(target, enemy2);
        }
        fprintf(stderr, "enemy:%s Distance:%d\n", target, minDist);

        printf("%s\n", target); // replace with correct ship name
    }
}