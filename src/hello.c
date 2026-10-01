#include <stdio.h>

int main(void)
{
    char name[128];
    printf("Name: ");
    if (!fgets(name, sizeof name, stdin)) return 1;
    for (size_t i = 0; name[i]; i++) {
        if (name[i] == '\n') { name[i] = '\0'; break; }
    }
    printf("hello, %s\n", name);
    return 0;
}
