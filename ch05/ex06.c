// Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage. How much faster is the program?
// Kernighan, Brian W.. C Programming Language (p. 110). Pearson Education. Kindle Edition.

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXSTORE 5000

char *lineptr[MAXLINES];
int _readlines(char *lineptr[], int nlines, char *store);
void _writelines(char *lineptr[], int nlines);
void _qsort(char *lineptr[], int left, int right);

int main()
{
    int nlines;
    char store[MAXSTORE];

    if ((nlines = _readlines(lineptr, MAXLINES, store)) >= 0)
    {
        _qsort(lineptr, 0, nlines - 1);
        _writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000 /* max length of any input line */
int _getline(char *, int);

int _readlines(char *lineptr[], int maxlines, char *store)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    p = store + strlen(store);
    while ((len = _getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (strlen(store) + len) > MAXSTORE)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}
int _getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void _writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void _qsort(char *v[], int left, int right)
{
    int i, last;
    void _swap(char *v[], int i, int j);
    if (left >= right)
    {
        return;
    }
    _swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            _swap(v, ++last, i);
    _swap(v, left, last);
    _qsort(v, left, last - 1);
    _qsort(v, last + 1, right);
}
void _swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}