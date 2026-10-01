#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char number[128];
    printf("Number: ");
    if (!fgets(number, sizeof number, stdin)) return 1;
    size_t length = strcspn(number, "\n");
    number[length] = '\0';
    if (length == 0) { puts("INVALID"); return 0; }

    int sum = 0;
    for (size_t offset = 0; offset < length; offset++) {
        unsigned char ch = (unsigned char) number[length - 1 - offset];
        if (!isdigit(ch)) { puts("INVALID"); return 0; }
        int digit = ch - '0';
        if (offset % 2 == 1) {
            digit *= 2;
            sum += digit / 10 + digit % 10;
        } else sum += digit;
    }
    if (sum % 10 != 0) { puts("INVALID"); return 0; }

    if (length == 15 && number[0] == '3' && (number[1] == '4' || number[1] == '7')) puts("AMEX");
    else if (length == 16 && number[0] == '5' && number[1] >= '1' && number[1] <= '5') puts("MASTERCARD");
    else if ((length == 13 || length == 16) && number[0] == '4') puts("VISA");
    else puts("INVALID");
    return 0;
}
