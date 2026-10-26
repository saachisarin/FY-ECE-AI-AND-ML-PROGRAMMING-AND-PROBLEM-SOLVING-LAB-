#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    printf("=== Menu Driven Calculator ===\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("Addition = %.2lf\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("Subtraction = %.2lf\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("Multiplication = %.2lf\n", result);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("Division = %.2lf\n", result);
            } else {
                printf("Error: Division by zero is undefined!\n");
            }
            break;
        default:
            printf("Invalid choice! Please select an option from 1 to 4.\n");
    }

    return 0;
}