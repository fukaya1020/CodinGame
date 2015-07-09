#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM_WORDS 100000
#define WORD_LENGTH 30

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
int Max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * �ǂ̃A���t�@�x�b�g���g���Ă��邩�𕶎��񂩂���肷��BResString�ɂ��̕������X�g���i�[
 **/
void RemoveDuplication(char *String, char *RetString)
{
    int RetCharLength = 1;
    RetString[0] = String[0];
    for (int i = 1; i < strlen(String); i++) {
        for (int j = 0; j < i; j++) {
            if (String[i] == String[j])
                break;
            if (j == i - 1)
                RetString[RetCharLength++] = String[i];
        }
    }
}

/**
 * ������Word�ƕ������X�gLetters����X�R�A���o���B
 **/
int Word2Score(char *Word, char *Letters)
{
    int Point = 0;

    for (int i = 0; i < Word[i] != 0; i++) {
        char FoundLetter = 0;
        for (int j = 0; j < strlen(Letters); j++) {
            if (Word[i] == Letters[j]) {
                switch (Letters[j]) {
                    case 'e':
                    case 'a':
                    case 'i':
                    case 'o':
                    case 'n':
                    case 'r':
                    case 't':
                    case 'l':
                    case 's':
                    case 'u':
                        FoundLetter = 1;
                        Point += 1;
                        break;
                    case 'd':
                    case 'g':
                        FoundLetter = 1;
                        Point += 2;
                        break;
                    case 'b':
                    case 'c':
                    case 'm':
                    case 'p':
                        FoundLetter = 1;
                        Point += 3;
                        break;
                    case 'f':
                    case 'h':
                    case 'v':
                    case 'w':
                    case 'y':
                        FoundLetter = 1;
                        Point += 4;
                        break;
                    case 'k':
                        FoundLetter = 1;
                        Point += 5;
                        break;
                    case 'j':
                    case 'x':
                        FoundLetter = 1;
                        Point += 8;
                        break;
                    case 'q':
                    case 'z':
                        FoundLetter = 1;
                        Point += 10;
                        break;
                    default:
                        break;
                }
            }
            if ((j == strlen(Letters) - 1) && (FoundLetter == 0))
                return 0;
        }
    }
    return Point;
}

int main()
{
    int N;
    scanf("%d", &N); fgetc(stdin);
    char WordList[MAX_NUM_WORDS][WORD_LENGTH] = {0};
    for (int i = 0; i < N; i++) {
        char W[WORD_LENGTH];
        fgets(W,WORD_LENGTH,stdin);
        strncpy(WordList[i], W, strlen(W)-1);
    }
    char LETTERS[8];
    fgets(LETTERS,8,stdin);

    int HighestScore = 0;                   // �ō��X�R�A
    char HighestStr[WORD_LENGTH] = {0};     // �ō��X�R�A�̒P��
    for (int i = 0; i < N; i++) {
        char TempString[WORD_LENGTH] = {0};
        RemoveDuplication(WordList[i], TempString);     // �A���t�@�x�b�g�̏d��������
        int Score = Word2Score(TempString, LETTERS);    // �X�R�A���o��
        if (HighestScore < Score) {
            HighestScore = Score;
            strcpy(HighestStr, WordList[i]);
            fprintf(stderr, "NEW RECORD: Word:%s Score:%d\n", HighestStr, HighestScore);
        }
    }
    printf("%s\n", HighestStr);
}