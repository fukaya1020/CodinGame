#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXNUM 10000
#define EXTENSTION_LENGTH 100
#define MIMETYPE_LENGTH 500
#define FILENAME_LENGTH 500

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

typedef struct {
    char ext[EXTENSTION_LENGTH];
    char mt[MIMETYPE_LENGTH];
} ExtMt;

/**
 * •¶Žš—ñSrcString‚©‚çRetExt‚ÉŠg’£Žq‚ðŠi”[
 **/
 void *Str2Ext(const char *SrcString, char *RetExt)
{
    int RetLength = 0;
    char flag = 0;
    for (int i = 0; SrcString[i] != NULL; i++) {
        if (flag == 1) {
            if (isalpha(SrcString[i]))
                RetExt[RetLength++] = tolower(SrcString[i]);
        }
        if (SrcString[i] == '.') {
            flag = 1;
            strcpy(RetExt, "");
            RetLength = 0;
        }
    }
}

int FindExt(char *ExtString, ExtMt *ExMtDB, int SearchNum)
{
    for (int i = 0; i < SearchNum; i++) {
        if (strcmp(ExtString, ExMtDB[i].ext) == 0)
            return i;
    }
    return -1;
}

int main()
{
    int N; // Number of elements which make up the association table.
    scanf("%d", &N); fgetc(stdin);
    int Q; // Number Q of file names to be analyzed.
    scanf("%d", &Q); fgetc(stdin);
    ExtMt ExMtList[MAXNUM] = {0};					//‚±‚±‚ÉExtension‚ÆMimetype‚ÌƒŠƒXƒg‚ðŠi”[
    int ExtNumber = 1, MtNumber = 1;

    for (int i = 0; i < N; i++) {
        char EXT[EXTENSTION_LENGTH]; // file extension
        char MT[MIMETYPE_LENGTH]; // MIME type.
        scanf("%s %s", EXT, MT);
		fgetc(stdin);
        char TempEXT[EXTENSTION_LENGTH] = {0};
        for (int j = 0; EXT[j] != NULL; j++)
            TempEXT[j] = tolower(EXT[j]);
        if (i == 0) {
            strcpy(ExMtList[0].ext, TempEXT);
            strcpy(ExMtList[0].mt, MT);
        }
        else {
            for (int k = 0; k < i; k++) {
                if (strcmp(ExMtList[k].ext, TempEXT) == 0)
                    break;
                if (k == i - 1) {
                    strcpy(ExMtList[ExtNumber++].ext, TempEXT);
                    strcpy(ExMtList[MtNumber++].mt, MT);
                }
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        char FNAME[FILENAME_LENGTH]; // One file name per line.
        fgets(FNAME,FILENAME_LENGTH,stdin); // One file name per line.

        char TempExt[EXTENSTION_LENGTH] = {0};
        Str2Ext(FNAME, TempExt);
        int ExtNo = FindExt(TempExt, ExMtList, ExtNumber);

        if (ExtNo == -1)
            printf("UNKNOWN\n");
        else
            printf("%s\n", ExMtList[ExtNo].mt);
    }
}