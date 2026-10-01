#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 2 || strlen(argv[1]) != 26) { fprintf(stderr, "Usage: substitution 26-letter-key\n"); return 1; }
    int seen[26] = {0};
    for (int i = 0; i < 26; i++) {
        unsigned char ch = (unsigned char) argv[1][i];
        if (!isalpha(ch) || seen[toupper(ch) - 'A']++) { fprintf(stderr, "Key needs 26 unique letters.\n"); return 1; }
    }
    char text[8192];
    printf("plaintext: ");
    if (!fgets(text, sizeof text, stdin)) return 1;
    printf("ciphertext: ");
    for (size_t i = 0; text[i]; i++) {
        unsigned char ch = (unsigned char) text[i];
        if (isalpha(ch)) {
            unsigned char mapped = (unsigned char) argv[1][toupper(ch) - 'A'];
            putchar(isupper(ch) ? toupper(mapped) : tolower(mapped));
        } else putchar(ch);
    }
    return 0;
}
