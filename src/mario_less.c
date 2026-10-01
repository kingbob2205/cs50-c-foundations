#include <stdio.h>

int main(void)
{
    int height;
    do {
        printf("Height (1-8): ");
        if (scanf("%d", &height) != 1) return 1;
    } while (height < 1 || height > 8);

    for (int row = 1; row <= height; row++) {
        for (int space = 0; space < height - row; space++) putchar(' ');
        for (int block = 0; block < row; block++) putchar('#');
        putchar('\n');
    }
    return 0;
}
