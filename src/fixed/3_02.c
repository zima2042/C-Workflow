#include <stdio.h>
#include <stddef.h>
#include <windows.h>

size_t mystrlen(char* s) {
    char* p = s;
    while (*p != '\0') {
        p++;
    }
    return (size_t)(p - s);
}

char* mystrcpy(char* dst, char* src) {
    char* p = dst;
    while (*src != '\0') {
        *p = *src;
        p++;
        src++;
    }
    *p = '\0';
    return dst;
}

char* mystrcat(char* dst, char* src) {
    char* p = dst;
    while (*p != '\0') {
        p++;
    }
    while (*src != '\0') {
        *p = *src;
        p++;
        src++;
    }
    *p = '\0';
    return dst;
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    const char* src = "qweRTY_306_114";
    const char* ass = "514";

    char src_copy[20];
    mystrcpy(src_copy, (char*)src);
    printf("拼接前 src_copy 长度: %zu\n", mystrlen(src_copy));
    printf("拼接前 src_copy 内容: %s\n\n", src_copy);

    mystrcat(src_copy, (char*)ass);

    printf("拼接后 src_copy 内容: %s\n", src_copy);
    printf("拼接后 src_copy 长度: %zu\n", mystrlen(src_copy));
    char final_dst[50];
    mystrcpy(final_dst, src_copy);
    printf("最终拷贝结果: %s\n", final_dst);
    return 0;
}