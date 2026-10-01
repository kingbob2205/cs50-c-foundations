#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    char text[8192];
    printf("Text: ");
    if (!fgets(text, sizeof text, stdin)) return 1;
    int letters = 0, words = 0, sentences = 0, in_word = 0;
    for (size_t i = 0; text[i]; i++) {
        unsigned char ch = (unsigned char) text[i];
        if (isalpha(ch)) letters++;
        if (!isspace(ch) && !in_word) { words++; in_word = 1; }
        if (isspace(ch)) in_word = 0;
        if (ch == '.' || ch == '!' || ch == '?') sentences++;
    }
    if (words == 0) { puts("No words to score."); return 0; }
    double l = 100.0 * letters / words, s = 100.0 * sentences / words;
    int grade = (int) round(0.0588 * l - 0.296 * s - 15.8);
    if (grade < 1) puts("Before Grade 1");
    else if (grade >= 16) puts("Grade 16+");
    else printf("Grade %d\n", grade);
    return 0;
}
