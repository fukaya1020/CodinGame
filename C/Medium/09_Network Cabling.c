#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_N 100000

long double min(long double a, long double b)
{
    return (a < b ? a : b);
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    scanf("%d", &N);
    long YPos[MAX_N] = {0};
    long XMax = 0, XMin = 0;
    long YSum = 0;
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        scanf("%d%d", &X, &Y);
        YPos[i] = Y;
        if ((i == 0) || (XMax < X))
            XMax = X;
        if ((i == 0) || (XMin > X))
            XMin = X;
        YSum += Y;
    }

    long double YAve = (double)YSum / N;
    long YMin, YCent;
    for (int i = 0; i < N; i++) {
        long double dist = fabs(YPos[i] - YAve);
        if ((i == 0) || (dist < YMin)) {
            YMin = dist;
            YCent = YPos[i];
        }
    }
    fprintf(stderr, "%d  %d  %ld  %ld\n", XMax, XMin, YMin, YCent);

    long CableLength = (XMax - XMin);
    for (int i = 0; i < N; i++)
        CableLength += abs(YPos[i] - YCent);

    printf("%ld\n", CableLength);
}