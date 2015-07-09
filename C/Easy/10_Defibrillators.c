#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define NAME_LEN 256
#define LON_LAT_LEN 50
#define DATA_NUM 1000
#define DEFI_LEN 256
#define RAD_EARTH 6371
#define POINTINFO_DATA_NUM 6

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

/* ポイントでの各情報 */ 
typedef struct {
    int num;
    char Name[NAME_LEN];
    char Address[NAME_LEN];
    char PhoneNum[NAME_LEN];
    double lon;
    double lat;
} PointInfo;


/**
 * ２点間の距離を計算.
 **/
double CalcDistance(double LonA, double LonB, double LatA, double LatB)
{
    double x = (LonB - LonA) * cos((LatA + LatB) / 2);
    double y = LatB - LatA;

    return sqrt(x * x + y * y) * RAD_EARTH;
}

/**
 * ,を含む文字列をdoubleの形にして返す.
 **/
double Str2Double(char *SourceNum)
{
    for (int i = 0; SourceNum[i] != 0; i++)
        if (SourceNum[i] == ',')
            SourceNum[i] = '.';

    return atof(SourceNum);
}

/**
 * SourceStringの文字列から構造体PointInfoに代入して返す
 **/
PointInfo String2Data(char *SourceString)
{
    PointInfo OutData = {0};
    char TempString[POINTINFO_DATA_NUM][NAME_LEN] = {0};
    int IncString = 0;
    int IncTmp = 0;
    for (int i = 0; SourceString[i] != 0; i++) {      //TempStringに各情報を文字列として代入
        if (SourceString[i] == ';') {
            IncString++;
            IncTmp = 0;
        }
        else {
            if ((IncTmp == 0) && (SourceString[i] == ' '))
                ;
            else
                TempString[IncString][IncTmp] = SourceString[i];
            IncTmp++;
        }
    }
    
    // 構造体OutDataに各データを代入
    OutData.num = atoi(TempString[0]);
    if (*TempString[1] != NULL)
        strcpy(OutData.Name, TempString[1]);
    if (*TempString[2] != NULL)
        strcpy(OutData.Address, TempString[2]);
    if (*TempString[3] != NULL)
        strcpy(OutData.PhoneNum, TempString[3]);
    OutData.lon = Str2Double(TempString[4]);
    OutData.lat = Str2Double(TempString[5]);

    return OutData;
}

int main()
{
    char LON[LON_LAT_LEN];
    scanf("%s", LON); fgetc(stdin);
    char LAT[LON_LAT_LEN];
    scanf("%s", LAT); fgetc(stdin);
    int N;
    scanf("%d", &N); fgetc(stdin);
    PointInfo InfoData[DATA_NUM] = {0};
    for (int i = 0; i < N; i++) {
        char DEFIB[DEFI_LEN];
        fgets(DEFIB,DEFI_LEN,stdin);
        InfoData[i] = String2Data(DEFIB);   // InfoDataに各データを入力
    }
    
    double LonVal = Str2Double(LON);
    double LatVal = Str2Double(LAT);

    PointInfo ShortestPoint = InfoData[0];
    double SmallestDist;
    for (int j = 0; j < N; j++) {
        double TempDist = CalcDistance(LonVal, InfoData[j].lon, LatVal, InfoData[j].lat);
        if ((j == 0) || (SmallestDist > TempDist)) {
            SmallestDist = TempDist;
            ShortestPoint = InfoData[j];
        }
    }

    printf("%s\n", ShortestPoint.Name);
}