#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STRING_LEN 5
#define TEMP_NUM 256
#define MAX_NUMBER 10000

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int main()
{
    int N; // the number of temperatures to analyse
    scanf("%d", &N); fgetc(stdin);
    char TEMPS[TEMP_NUM]; // the N temperatures expressed as integers ranging from -273 to 5526
    fgets(TEMPS,TEMP_NUM,stdin); // the N temperatures expressed as integers ranging from -273 to 5526
    int TEMPNO[TEMP_NUM] = {0};
    int IncreNumber = 0;

    for (int i = 0; TEMPS[i] != 0; i++) {
        int x = 0;
        char tempstr[STRING_LEN] = {0};
        while (isdigit(TEMPS[i]) || TEMPS[i] == '-')    // tempstrÇ…â∑ìxèÓïÒÇäiî[
            tempstr[x++] = TEMPS[i++];
        TEMPNO[IncreNumber++] = atoi(tempstr);          // TEMPNOÇ…â∑ìxèÓïÒÇintå`éÆÇ≈äiî[
    }

    for (int n = 0; n < N; n++)
        fprintf(stderr, "%d ", TEMPNO[n]);
    fprintf(stderr, "\n");

    int Nearest2Zero = 99999;
    if (N == 0)
        Nearest2Zero = 0;
    else {
        for (int i = 0; i < N; i++) {
            if (abs(TEMPNO[i]) < abs(Nearest2Zero))
                Nearest2Zero = TEMPNO[i];
            if (abs(Nearest2Zero) == abs(TEMPNO[i]))
                if ((Nearest2Zero < 0) && (TEMPNO[i] > 0)) 
                    Nearest2Zero = TEMPNO[i];
        }
    }
    printf("%d\n", Nearest2Zero);
}