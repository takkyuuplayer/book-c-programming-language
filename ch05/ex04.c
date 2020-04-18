// Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.
// Kernighan, Brian W.. C Programming Language (p. 107). Pearson Education. Kindle Edition.
#include <stdio.h>
#include <string.h>

int strend(char[], char[]);
int main()
{
    printf("%d\n", strend("abc", "a"));
    printf("%d\n", strend("abc", "c"));
    printf("%d\n", strend("abc", "bc"));
    printf("%d\n", strend("abc", "ba"));
}

int strend(char *s, char *t)
{
    int j;
    int slen = strlen(s), tlen = strlen(t);
    if (slen < tlen)
    {
        return 0;
    }
    for (j = 0; j < tlen; j++)
    {
        if (*(s + slen - tlen + j) != *(t + j))
        {
            return 0;
        }
    }

    return 1;
}