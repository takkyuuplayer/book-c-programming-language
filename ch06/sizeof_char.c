#include <stdio.h>

struct node
{
    char *word;
};
struct node2
{
    char word[2];
};

int main(int argc, char const *argv[])
{
    printf("char * size = %lu\n", sizeof(struct node));
    printf("char[2] size = %lu\n", sizeof(struct node2));
    printf("int size = %lu\n", sizeof(int));
}
