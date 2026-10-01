#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 9
#define MAX_NAME 128

typedef struct { const char *name; int votes; } Candidate;

int main(int argc, char **argv)
{
    if (argc < 2 || argc > MAX_CANDIDATES + 1) { fprintf(stderr, "Usage: plurality candidate... (1-9)\n"); return 1; }
    Candidate candidates[MAX_CANDIDATES];
    for (int i = 1; i < argc; i++) candidates[i - 1] = (Candidate) {argv[i], 0};
    int count;
    printf("Number of voters: ");
    if (scanf("%d", &count) != 1 || count < 0) return 1;
    for (int voter = 0; voter < count; voter++) {
        char name[MAX_NAME];
        printf("Vote: ");
        if (scanf("%127s", name) != 1) return 1;
        int found = 0;
        for (int i = 0; i < argc - 1; i++) {
            if (strcmp(name, candidates[i].name) == 0) { candidates[i].votes++; found = 1; break; }
        }
        if (!found) puts("Invalid vote.");
    }
    int highest = 0;
    for (int i = 0; i < argc - 1; i++) if (candidates[i].votes > highest) highest = candidates[i].votes;
    for (int i = 0; i < argc - 1; i++) if (candidates[i].votes == highest) puts(candidates[i].name);
    return 0;
}
