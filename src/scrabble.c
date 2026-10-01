#include <ctype.h>
#include <stdio.h>

static int score(const char *word)
{
    const int points[26] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
    int total = 0;
    for (size_t i = 0; word[i]; i++) {
        unsigned char ch = (unsigned char) word[i];
        if (isalpha(ch)) total += points[toupper(ch) - 'A'];
    }
    return total;
}

int main(void)
{
    char first[128], second[128];
    printf("Player 1: ");
    if (!fgets(first, sizeof first, stdin)) return 1;
    printf("Player 2: ");
    if (!fgets(second, sizeof second, stdin)) return 1;
    int a = score(first), b = score(second);
    puts(a > b ? "Player 1 wins!" : a < b ? "Player 2 wins!" : "Tie!");
    return 0;
}
