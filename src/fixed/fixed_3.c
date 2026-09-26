#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main(void)
{
    int arr[10];
    int i, j, temp;
    for (i = 0; i < 10; i++)
    {
        if (scanf("%d", &arr[i]) != 1) {
            printf("输入错误！\n");
            return 1;
        }
    }
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}