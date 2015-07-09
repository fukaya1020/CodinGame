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

        if (R + G - X > 0) {            //���݈ʒu���M���b�v�I���n�_�����O
            if (R + G - X > S) {        //���݈ʒu�{���X�s�[�h���M���b�v�I���n�_�����O
                if (S < G + 1)          //���X�s�[�h���M���b�v�̒��������x��
                    strcpy(Command, "SPEED"); 
                else if (S > G + 1)     //���X�s�[�h���M���b�v�̒�����������
                    strcpy(Command, "SLOW"); 
                else                    //���X�s�[�h���M���b�v�̒����Ɠ���
                    strcpy(Command, "WAIT");
           }
           else                         //���݈ʒu�{���X�s�[�h���M���b�v�I���n�_������
                strcpy(Command, "JUMP"); 
        }
        else                            //���݈ʒu���M���b�v�I���n�_������
            strcpy(Command, "SLOW");

        fprintf(stderr, "X:%d, Speed:%d, RestX%d\n", X, S, RestX);
        fprintf(stderr, "Length to Gap:%d, Gap Length:%d, Landing PF:%d\n", R, G, L);

        RestX -= S;
        printf("%s\n", Command); // A single line containing one of 4 keywords: SPEED, SLOW, JUMP, WAIT.
    }
}