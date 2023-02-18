#include <stdio.h>
#include <stdlib.h>

int main()
{
    int heightNum, widthNum, operationNum;
    scanf("%d %d %d", &heightNum, &widthNum, &operationNum);

    int **inputArr = (int **)malloc(sizeof(int *) * heightNum);
    for (int i = 0; i < heightNum; i++) {
        inputArr[i] = (int *)malloc(sizeof(int) * widthNum);
        for (int j = 0; j < widthNum; j++)  {
            scanf("%d", &inputArr[i][j]);
        }
    }

    for (int i = 0; i < heightNum; i++) {
        for (int j = 0; j < widthNum; j++)  {
            printf("%d ", inputArr[i][j]);
        }
        printf("\n");
    }

    int **operationArr = (int **)malloc(sizeof(int *) * operationNum);
    for (int i = 0; i < operationNum; i++) {
        operationArr[i] = (int *)malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++)  {
            scanf("%d", &operationArr[i][j]);
        }
    }

    for (int i = 0; i < operationNum; i++) {
        for (int j = 0; j < 3; j++)  {
            printf("%d ", operationArr[i][j]);
        }
        printf("\n");
    }

    free(inputArr);
    free(operationArr);
}
