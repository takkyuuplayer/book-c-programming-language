#include <stdio.h>
#include <string.h>
int strrindex(char source[], char searchfor[]);

int main()
{
    printf("%d\n", strrindex("abcdefabcdef", "abc"));
    printf("%d\n", strrindex("abcdefabcdef", "efg"));
    printf("%d\n", strrindex("abcdefabcdef", "def"));
    printf("%d\n", strrindex("abcdefabcdef", "abcdefa"));
}

int strrindex(char source[], char searchfor[])
{
    int len = strlen(searchfor);
    for (int i = strlen(source) - len; i >= 0; i--)
    {
        short found = 1;
        for (int j = 0; j < len; j++)
        {
            if (source[i + j] != searchfor[j])
            {
                found = 0;
                break;
            }
        }
        if (found)
        {
            return i;
        }
    }

    return -1;
}