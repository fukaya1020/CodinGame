#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEL_NO 10000
#define MAX_LENGTH 20

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    scanf("%d", &N);
    char PhoneData[MAX_TEL_NO][MAX_LENGTH] = {0};

    for (int i = 0; i < N; i++) {
        char telephone[MAX_LENGTH] = 0;
        scanf("%s", telephone);
        strcpy(PhoneData[i], telephone);
    }

    // �ŏ��̃i���o�[�͂��ׂ�TotalNum�ɐ�������
    int TotalNum = strlen(PhoneData[0]);
    // ���݂̃i���o�[�Ɖߋ��̃i���o�[���r
    for (int i = 1; i < N; i++) {                   // �Q�ƒ��̃i���o�[
        int DuplicateDigit = 0;                     // �ߋ��̃i���o�[�Ƃ��Ԃ��Ă��錅��
        for (int j = 0; j < i; j++) {               // �ߋ��̃i���o�[���ׂĂƔ�r
            for (int k = 0; (PhoneData[i][k] != 0) || (PhoneData[j][k] != 0); k++) {
                if (PhoneData[i][k] == PhoneData[j][k]) {
                    if (DuplicateDigit < k + 1)
                        DuplicateDigit = k + 1;
                }
                else
                    break;
            }
        }
        TotalNum += strlen(PhoneData[i]) - DuplicateDigit;
    }
    printf("%d\n", TotalNum); // The number of elements (referencing a number) stored in the structure.
}