#include <stdio.h>
int input[10] = { 13,45,22,-78,306,34,87,-6,89,32 };
// 下方定义你的返回值类型
struct Result
{
    int max;
    int min;
    double avg;
    int revArr[10];
};
// 下方声明你的函数
struct Result calc(int arr[], int n);
int main()
{
    // 此处填写你的逻辑
    struct Result res = calc(input, 10);
    int i;
    printf("Max: %d\n", res.max);
    printf("Min: %d\n", res.min);
    printf("Avg: %.2f\n", res.avg);

    printf("Original: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", input[i]);
    }
    printf("\n");

    printf("Processed: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", res.revArr[i]);
    }
    printf("\n");
    return 0;
}
// 下方定义你的函数
struct Result calc(int arr[], int n) {
    struct Result ret;
    int sum = 0;
    ret.max = arr[0];
    ret.min = arr[0];
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > ret.max) ret.max = arr[i];
        if (arr[i] < ret.min) ret.min = arr[i];
        ret.revArr[n - 1 - i] = arr[i];
    }
    ret.avg = (double)sum / n;
    return ret;
}