#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 100000

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
//クイックソートのための関数
int cmp(const void *p, const void *q) {
    return *(int*)p - *(int*)q;
} 
 
int main()
{
    int N;
    scanf("%d", &N);
 
    int HorseData[MAX_NUM] = {0};
    for (int i = 0; i < N; i++) {
        int Pi;
        scanf("%d", &Pi);
        HorseData[i] = Pi;
    }

	//クイックソート
    qsort(HorseData, N, sizeof(int), cmp);

    int MinDiff = 9999999; //Minimum Diff between horses
    for (int i = 0; i < N - 1; i++) {
        if (abs(HorseData[i+1] - HorseData[i]) < MinDiff)
            MinDiff = abs(HorseData[i+1] - HorseData[i]);
    }
    printf("%d\n", MinDiff);
}