#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MESSAGE_LENGTH 100
#define CHAR_7BIT 7
#define MESSAGE_LENGTH_7BIT MESSAGE_LENGTH*CHAR_7BIT
#define HIGHEST_BIT 128
#define OUTPUT_LENGTH 10000

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    char MESSAGE[MESSAGE_LENGTH];
    fgets(MESSAGE,MESSAGE_LENGTH,stdin);
    char BitMessage[MESSAGE_LENGTH_7BIT] = {0};
    int temp_msg = 0;

    for (int i = 0; i < strlen(MESSAGE) - 1; i++) {
        temp_msg = MESSAGE[i] & 0x7f;                   // ÅãˆÊ‚Ìƒrƒbƒg‚ðœ‹Ž
        for (int j = 0; j < CHAR_7BIT; j++) {           // BitMessage‚Ì•¶Žš—ñ‚É01‚ð•À‚×‚Ä‚¢‚­
            if (temp_msg >= pow(2, CHAR_7BIT - j - 1)) {
                BitMessage[i * CHAR_7BIT + j] = 1;
                temp_msg = temp_msg - pow(2, (CHAR_7BIT - j - 1));
            }
            else
                BitMessage[i * CHAR_7BIT + j] = 0;
        }
    }
    for (int l = 0; l < CHAR_7BIT*(strlen(MESSAGE) - 1); l++)
        fprintf(stderr, "%d", BitMessage[l]);
    fprintf(stderr, "\n");
    
    char OutputStr[OUTPUT_LENGTH] = {0};

    if (BitMessage[0] == 0)
        sprintf(OutputStr, "00 0");
    else if (BitMessage[0] == 1)
        sprintf(OutputStr, "0 0");

    for (int i = 1; i < CHAR_7BIT*(strlen(MESSAGE)-1); i++) {
        if (BitMessage[i] != BitMessage[i-1]) {
            if (BitMessage[i] == 0)
                strcat(OutputStr, " 00 0");
            else if (BitMessage[i] == 1)
                strcat(OutputStr, " 0 0");
        }
        else
            strcat(OutputStr, "0");
    }
    printf("%s\n", OutputStr);
}