#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define HEIGHT_MAX 30
#define STR_LENGTH 256
#define ASCII_ART_MAX 1024
#define ASCII_A 65
#define ALPHABET_NUM 26

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;      //Length of char
    scanf("%d", &L); fgetc(stdin);
    int H;      //Length of height
    scanf("%d", &H); fgetc(stdin);
    char T[STR_LENGTH];      //String to convert to Ascii art
    fgets(T,STR_LENGTH,stdin);
    char AsciiArt[HEIGHT_MAX][ASCII_ART_MAX] = {0}; //�A�X�L�[�A�[�g��ۑ�����f�[�^
    for (int i = 0; i < H; i++) { 
        char ROW[ASCII_ART_MAX];
        fgets(ROW,ASCII_ART_MAX,stdin);
        strcpy(AsciiArt[i], ROW);                   //�A�X�L�[�A�[�g�f�[�^��AsciiArt�ɕۑ�
    }

    int OutputPosition[STR_LENGTH] = {0};
    for (int i = 0; i < strlen(T)-1; i++) {
        T[i] = toupper(T[i]);                       //�啶���ɕϊ�
        if (!isalpha(T[i]))
            OutputPosition[i] = ALPHABET_NUM * L;   //�X�^�[�g�ʒu���Ō��?�ɂ����Ă���
        else
            OutputPosition[i] = (int)(T[i] - ASCII_A) * L;  //�X�^�[�g�ʒu���e�A���t�@�x�b�g�ɍ��킹��
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < strlen(T)-1; j++) {
            for (int k = 0; k < L; k++) {
                int temp = k + OutputPosition[j];
                printf("%c", AsciiArt[i][temp]);
            }
        }
        printf("\n");
    }
}