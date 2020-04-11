// Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
// Kernighan, Brian W.. C Programming Language (p. 107). Pearson Education. Kindle Edition.
#include <stdio.h>
#include <string.h>

void _strncpy(char[], char[], size_t n);
void _strncat(char[], char[], size_t n);
int _strncmp(char[], char[], size_t n);

int main()
{
    char s[100] = "abcde";
    char *t = "xyz";
    _strncpy(s, t, 2);
    printf("%s\n", s);

    _strncat(s, t, 1);
    printf("%s\n", s);

    printf("%d\n", _strncmp(s, "wxyA", 1));
    printf("%d\n", _strncmp(s, "xyA", 2));
    printf("%d\n", _strncmp(s, "xyA", 3));
    printf("%d\n", _strncmp(s, "xyA", 3));
    printf("%d\n", _strncmp(s, "yzA", 1));
}

void _strncpy(char *s, char *t, size_t n)
{
    char *end = t + n;
    while ((*s++ = *t++) && t < end)
    {
    }
}

void _strncat(char *s, char *t, size_t n)
{
    char *end = t + n;
    size_t slen = strlen(s);
    while ((*(s++ + slen) = *t++) && t < end)
    {
    }
}
int _strncmp(char *s, char *t, size_t n)
{
    char *end = t + n;
    while (t < end)
    {
        char cs = *s++;
        char ct = *t++;
        if (cs < ct)
        {
            return -1;
        }
        else if (cs > ct)
        {
            return 1;
        }
    }
    return 0;
}