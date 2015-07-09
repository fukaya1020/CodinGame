#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_R 100
#define MAX_L 25
#define MAX_NUMBER 2000

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int R;
    scanf("%d", &R);
    int L;
    scanf("%d", &L);
    int NumberBox[MAX_L][MAX_NUMBER] = {0};         // ”—ñ‚ğ‚±‚±‚ÉŠi”[

    NumberBox[0][0] = R;                            // Å‰‚Ì”š‚ğŠi”[
    for (int i = 1; i < L; i++) {
        int TempNum = 0;                            // ‚»‚Ìs‚ÅŠi”[‚³‚ê‚é”š‚Ì”
        int DupNum = 1;                             // ˜A‘±‚µ‚½”š‚Ì˜A‘±”
        for (int j = 0; NumberBox[i-1][j] != 0; j++) {
            if (NumberBox[i-1][j] == NumberBox[i-1][j+1])
                DupNum++;
            else {                                  // ”š‚ğŠi”[
                NumberBox[i][TempNum++] = DupNum;
                NumberBox[i][TempNum++] = NumberBox[i-1][j];
                DupNum = 1;
            }
        }
    }
    for (int i = 0; NumberBox[L-1][i] != 0; i++) {
        printf("%d", NumberBox[L-1][i]);
        if (NumberBox[L-1][i+1] != 0)
            printf(" ");
        else
            printf("\n");
    }
}