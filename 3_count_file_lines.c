#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100];
    char ch;
    int lines = 0;

    printf("Enter filename to count lines (e.g., sample.txt): ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'. Make sure it exists!\n", filename);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }
    fclose(fp);

    printf("Total lines in '%s': %d\n", filename, lines);

    return 0;
}
