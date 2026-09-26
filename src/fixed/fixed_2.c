#include <stdio.h>
#include <stdlib.h> 
int main(void)
{
    char* str;
    int capacity = 10;
    int length = 0;
    int letters = 0, numbers = 0, others = 0;
    int i = 0;
    int ch;

    str = (char*)malloc(capacity * sizeof(char));
    if (str == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (length >= capacity - 1) {
            capacity = capacity * 2;
            char* temp = (char*)realloc(str, capacity * sizeof(char));
            if (temp == NULL) {
                free(str);
                printf("内存扩容失败\n");
                return 1;
            }
            str = temp;
        }
        str[length++] = (char)ch;
    }
    str[length] = '\0';

    for (i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            letters++;
            str[i] = str[i] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            letters++;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            numbers++;
        }
        else {
            others++;
        }
    }
    printf("Letters: %d, Numbers: %d, Others: %d, %s\n", letters, numbers, others, str);
    free(str);
    str = NULL;
    return 0;
}