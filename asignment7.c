#include <stdio.h>

// Define the structure for Student
struct Student {
    int roll_no;
    char name[50];
    float marks[3];
    float total;
    float percentage;
};

int main() {
    int n, i, j;

    // Accept the number of students
    printf("Enter the number of students: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    struct Student students[n];

    // Accept details for each student
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);
        
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].roll_no);

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        students[i].total = 0;
        printf("Enter marks of 3 subjects:\n");
        for (j = 0; j < 3; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }

        // Calculate percentage
        students[i].percentage = students[i].total / 3.0;
    }

    // Display the results in the required format
    printf("\n---------------------------------------------------------------------------------\n");
    printf("%-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s\n", 
           "Roll No", "Name", "Subject: 1", "Subject: 2", "Subject: 3", "Total", "Percentage");
    printf("---------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-10d | %-10s | %-10.0f | %-10.0f | %-10.0f | %-10.0f | %-10.2f\n",
               students[i].roll_no,
               students[i].name,
               students[i].marks[0],
               students[i].marks[1],
               students[i].marks[2],
               students[i].total,
               students[i].percentage);
    }
    printf("---------------------------------------------------------------------------------\n");

    return 0;
}