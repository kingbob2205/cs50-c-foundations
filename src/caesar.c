#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2 || !*argv[1]) { fprintf(stderr, "Usage: caesar key\n"); return 1; }
    for (const char *p = argv[1]; *p; p++) {
        if (!isdigit((unsigned char) *p)) { fprintf(stderr, "Key must be a nonnegative integer.\n"); return 1; }
    }
    errno = 0;
    char *end;
    unsigned long key = strtoul(argv[1], &end, 10);
    if (errno || *end) { fprintf(stderr, "Key is too large.\n"); return 1; }
    char text[8192];
    printf("plaintext: ");
    if (!fgets(text, sizeof text, stdin)) return 1;
    printf("ciphertext: ");
    for (size_t i = 0; text[i]; i++) {
        unsigned char ch = (unsigned char) text[i];
        if (isalpha(ch)) {
            int base = isupper(ch) ? 'A' : 'a';
            putchar(base + (ch - base + key % 26) % 26);
        } else putchar(ch);
    }
    return 0;
}
