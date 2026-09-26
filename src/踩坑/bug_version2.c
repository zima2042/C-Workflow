#include <stdio.h>
#include <windows.h>

int main(void)
{
    char str[10000];
    int letters = 0, numbers = 0, others = 0;
    int i = 0;
    fgets(str, sizeof(str), stdin);
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            letters++;
            str[i] = str[i] - 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            letters++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            numbers++;
        }
        else if (str[i] != '\n')
        {
            others++;
        }
        i++;
    }
    printf("letters: %d, numbers: %d, others: %d, %s", letters, numbers, others, str);
    return 0;
}