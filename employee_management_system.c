#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

void addEmployee() {
    FILE *fp = fopen("employees.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct Employee emp;
    printf("\n--- Add New Employee ---\n");
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Name: ");
    getchar(); // Clear newline
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(emp.department, sizeof(emp.department), stdin);
    emp.department[strcspn(emp.department, "\n")] = '\0';

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(struct Employee), 1, fp);
    fclose(fp);

    printf("Employee added successfully and saved to file!\n");
}

void displayEmployees() {
    FILE *fp = fopen("employees.dat", "rb");
    if (fp == NULL) {
        printf("\nNo employee records found. Add an employee first!\n");
        return;
    }

    struct Employee emp;
    printf("\n=======================================================\n");
    printf("               EMPLOYEE DIRECTORY                      \n");
    printf("=======================================================\n");
    printf("%-10s %-20s %-15s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("-------------------------------------------------------\n");

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1) {
        printf("%-10d %-20s %-15s $%-10.2f\n", emp.id, emp.name, emp.department, emp.salary);
    }

    printf("=======================================================\n");
    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n==========================================\n");
        printf("      EMPLOYEE MANAGEMENT SYSTEM          \n");
        printf("==========================================\n");
        printf("1. Add Employee\n");
        printf("2. View All Employees\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
