#include <stdio.h>
#include <time.h>
#include <windows.h>

long long fib_recursive(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

long long fib_iterative(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 45;
    clock_t start, end;
    double cpu_time_used;

    SetConsoleOutputCP(65001);  /* 让VS调试控制台按UTF-8显示中文，避免乱码 */

    start = clock();
    long long res1 = fib_recursive(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("递归计算第 %d 项: %lld, 耗时: %f 秒\n", n, res1, cpu_time_used);

    start = clock();
    long long res2 = fib_iterative(n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("递推计算第 %d 项: %lld, 耗时: %f 秒\n", n, res2, cpu_time_used);

    return 0;
}