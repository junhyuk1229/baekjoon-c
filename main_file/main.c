#include <stdio.h>
#include <stdlib.h>


enum bool{
    false, true
};

typedef enum bool bool;


bool checkValidList(char **inputMap, short *checkList, int listNum)   {
    //Check if the list is valid
    for(int i = listNum; i >= 2; i--)   {
        if(checkList[i] >= 0 && inputMap[listNum - i][i - 1] == '-')    return false;
        if(checkList[i] != 0 && inputMap[listNum - i][i - 1] == '0')    return false;
        if(checkList[i] <= 0 && inputMap[listNum - i][i - 1] == '+')    return false;
    }
    return true;
}


bool loopList(char **inputMap, short *checkList, short *outputList, int listNum) {
    //Add number to list
    for(int i = 0; i < listNum; i++)    {
        printf("%hd ", outputList[i]);
    }
    printf("\n\n");
    if(inputMap[listNum][0] == '0') {
        outputList[listNum] = 0;
        checkList[listNum] = 0;

        listNum++;

        if (!checkValidList(inputMap, checkList, listNum))    {
            return false;
        }

        if (loopList(inputMap, checkList, outputList, listNum)) {
            return true;
        }

        listNum--;
    } else {
        //Check if it is negative
        bool isNeg = false;
        if(inputMap[listNum][0] == '-') {
            isNeg = true;
        }

        for(int i = 1; i <= 10; i++) {
            if(isNeg)   {
                outputList[listNum] = -i;
                checkList[listNum] = -i;
            } else {
                outputList[listNum] = i;
                checkList[listNum] = i;
            }

            for(int j = 0; j < listNum; j++)    {
                checkList[j] += outputList[listNum];
            }

            listNum++;

            if (!checkValidList(inputMap, checkList, listNum))    {
                continue;
            }

            if (loopList(inputMap, checkList, outputList, listNum)) {
                return true;
            }

            listNum--;
        }
    }


    return true;
}


int main()
{
    //Get input and process input
    short inputNum;
    scanf("%hd", &inputNum);
    getchar();

    printf("%hd\n", inputNum);

    char **inputStr = (char **)malloc(sizeof(char *) * inputNum);
    for(int i = 0; i < inputNum; i++)  {
        inputStr[i] = (char *)malloc(sizeof(char) * (inputNum - i + 1));
        for(int j = 0; j < inputNum - i; j++)  {
            inputStr[i][j] = getchar();
        }
        inputStr[i][inputNum - i] = '\0';

        printf("%s\n", inputStr[i]);

    }


    //Create extra data
    short *outputList = (short *)malloc(sizeof(short) * inputNum);
    short *checkList = (short *)malloc(sizeof(short) * inputNum);


    //Loop through the list and check if valid
    loopList(inputStr, checkList, outputList, 0);

    for(int i = 0; i < inputNum; i++)  {
        printf("%hd\n", outputList[i]);
    }

    //Free list pointers
    for(int i = 0; i < inputNum; i++)  {
        free(inputStr[i]);
    }
    free(inputStr);

    free(outputList);
    free(checkList);


    return 0;
}
