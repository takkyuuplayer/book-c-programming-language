#include <stdio.h>

int main() {
    float fahr, celcius;

    printf("| %3s | %6s |\n", "F", "C");
    printf("|--------------|\n");
    for (fahr = 300; fahr >= 0; fahr -= 20)
    {
        celcius = (5.0 / 9.0) * (fahr - 32 );
        printf("| %3.0f | %6.1f |\n", fahr, celcius);
    }
}