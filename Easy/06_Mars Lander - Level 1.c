#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_N 30

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // the number of points used to draw the surface of Mars.
    scanf("%d", &N);
    int LAND_X[MAX_N] = {0};   // X coordinate of a surface point. (0 to 6999)
    int LAND_Y[MAX_N] = {0};   // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
    int FlatS, FlatM, FlatE;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &LAND_X[i], &LAND_Y[i]);
        if (i > 0) {
            if (LAND_Y[i] == LAND_Y[i-1]) {
                FlatS = LAND_X[i-1];
                FlatE = LAND_X[i];
            }
        }
    }
    FlatM = (FlatS + FlatE) / 2;

    // game loop
    while (1) {
        int X;
        int Y;
        int HS; // the horizontal speed (in m/s), can be negative.
        int VS; // the vertical speed (in m/s), can be negative.
        int F; // the quantity of remaining fuel in liters.
        int R; // the rotation angle in degrees (-90 to 90).
        int P; // the thrust power (0 to 4).
        scanf("%d%d%d%d%d%d%d", &X, &Y, &HS, &VS, &F, &R, &P);

        fprintf(stderr, "%d %d %d %d %d %d %d\n", X, Y, HS, VS, F, R, P);

        if (VS > -40)
            printf("%d 0\n", HSpeed);
        else
            printf("%d 4\n", HSpeed);
    }
}