#include <stdio.h>

int main(void)
{
    int cents;
    do {
        printf("Change owed in cents: ");
        if (scanf("%d", &cents) != 1) return 1;
    } while (cents < 0);

    const int coins[] = {25, 10, 5, 1};
    int count = 0;
    for (size_t i = 0; i < sizeof coins / sizeof coins[0]; i++) {
        count += cents / coins[i];
        cents %= coins[i];
    }
    printf("%d\n", count);
    return 0;
}
