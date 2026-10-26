
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

#ifndef _WIN32
char *strrev(char *str)
{
    int i = 0, j = (int)strlen(str) - 1;
    char t;
    while (i < j) {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
    return str;
}

int strcmpi(const char *a, const char *b)
{
    while (*a && *b &&
           tolower((unsigned char)*a) == tolower((unsigned char)*b)) {
        a++;
        b++;
    }
    return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}
#endif

/* Read a line safely and remove the trailing newline */
void readString(const char *prompt, char *str)
{
    printf("%s", prompt);
    if (fgets(str, SIZE, stdin) != NULL)
        str[strcspn(str, "\n")] = '\0';
}

int main(void)
{
    char str1[SIZE], str2[SIZE];
    int choice, result;

    do {
        printf("\n======= STRING FUNCTIONS MENU =======\n");
        printf(" 1. Length of string\n");
        printf(" 2. Reverse the string\n");
        printf(" 3. Append s2 to s1\n");
        printf(" 4. Copy s2 to s1\n");
        printf(" 5. Compare two strings\n");
        printf(" 6. Compare ignoring case\n");
        printf(" 0. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            choice = -1;
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {

        case 1:
            readString("Enter a string: ", str1);
            printf("Length of \"%s\" = %zu\n", str1, strlen(str1));
            break;

        case 2:
            readString("Enter a string: ", str1);
            printf("Reverse of the string = %s\n", strrev(str1));
            break;

        case 3:
            readString("Enter string 1: ", str1);
            readString("Enter string 2: ", str2);
            if (strlen(str1) + strlen(str2) < SIZE) {
                strcat(str1, str2);
                printf("After strcat, string 1 = %s\n", str1);
            } else
                printf("Result too long for the buffer!\n");
            break;

        case 4:
            readString("Enter string 2 (source): ", str2);
            strcpy(str1, str2);
            printf("After strcpy, string 1 = %s\n", str1);
            break;

        case 5:
            readString("Enter string 1: ", str1);
            readString("Enter string 2: ", str2);
            result = strcmp(str1, str2);
            if (result == 0)
                printf("Strings are EQUAL.\n");
            else if (result < 0)
                printf("String 1 is SMALLER than string 2 (result = %d).\n", result);
            else
                printf("String 1 is GREATER than string 2 (result = %d).\n", result);
            break;

        case 6:
            readString("Enter string 1: ", str1);
            readString("Enter string 2: ", str2);
            if (strcmpi(str1, str2) == 0)
                printf("Strings are EQUAL (ignoring case).\n");
            else
                printf("Strings are NOT equal.\n");
            break;

        case 0:
            printf("Exiting program. Thank you!\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}