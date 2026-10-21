#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    FILE *fp;
    struct Student s1 = {101, "Mahima Chaudhari", 92.5};
    struct Student s2;

    // 1. Write structure data to file
    fp = fopen("student_record.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    fwrite(&s1, sizeof(struct Student), 1, fp);
    fclose(fp);
    printf("Data successfully written to file 'student_record.dat'.\n");

    // 2. Read structure data back from file
    fp = fopen("student_record.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    fread(&s2, sizeof(struct Student), 1, fp);
    fclose(fp);

    printf("\n--- Read Data From File ---\n");
    printf("ID    : %d\n", s2.id);
    printf("Name  : %s\n", s2.name);
    printf("Marks : %.2f\n", s2.marks);

    return 0;
}
