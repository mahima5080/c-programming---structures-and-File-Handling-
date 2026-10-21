#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char text[200];

    // Open file in append mode ('a')
    fp = fopen("notes.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter text to append to 'notes.txt':\n");
    getchar(); // Clear buffer
    fgets(text, sizeof(text), stdin);

    fputs(text, fp);
    fclose(fp);

    printf("Data successfully appended to 'notes.txt'.\n");

    return 0;
}
