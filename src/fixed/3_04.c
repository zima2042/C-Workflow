#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    int* arr = NULL;
    int capacity = 5;
    int cnt = 0;
    int val;

    SetConsoleOutputCP(65001);

    arr = (int*)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        printf("初始内存分配失败！\n");
        return 1;
    }

    printf("请输入整数（输入 -1 结束）：\n");
    while (1) {
        scanf("%d", &val);
        if (val == -1) {
            break;
        }

        if (cnt >= capacity) {
            capacity *= 2;
            int* temp = (int*)realloc(arr, capacity * sizeof(int));
            if (temp == NULL) {
                printf("内存扩展失败！\n");
                free(arr);
                arr = NULL;
                return 1;
            }
            arr = temp;
        }

        arr[cnt] = val;
        cnt++;
    }

    if (cnt == 0) {
        printf("未输入有效数据。\n");
        free(arr);
        arr = NULL;
        return 0;
    }

    int max = arr[0];
    int min = arr[0];
    double sum = 0.0;
    for (int i = 0; i < cnt; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
        sum += arr[i];
    }
    double avg = sum / cnt;

    printf("1. 数据总个数 Cnt: %d\n", cnt);
    printf("2. 最大值 Max: %d\n", max);
    printf("3. 最小值 Min: %d\n", min);
    printf("4. 平均值 Avg: %.2f\n", avg);

    printf("5. 逆序输出: ");
    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}