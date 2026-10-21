#include <stdio.h>

// Structure Definition
struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    struct Student s;

    printf("--- Enter Student Details ---\n");
    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    // Remove trailing newline character
    for (int i = 0; s.name[i] != '\0'; i++) {
        if (s.name[i] == '\n') {
            s.name[i] = '\0';
            break;
        }
    }

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    printf("\n--- Displaying Student Record ---\n");
    printf("Name  : %s\n", s.name);
    printf("Age   : %d\n", s.age);
    printf("Marks : %.2f\n", s.marks);

    return 0;
}
