#include <stdio.h>

# define LOWER 0
# define UPPER 300
# define STEP 20

int main() {
    float fahr, celcius;

    printf("| %3s | %6s |\n", "F", "C");
    printf("|--------------|\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    {
        celcius = (5.0 / 9.0) * (fahr - 32 );
        printf("| %3.0f | %6.1f |\n", fahr, celcius);
    }
}