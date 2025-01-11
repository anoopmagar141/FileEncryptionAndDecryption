#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char inputFile[100], outputFile[100];
    char key[100];  // Allowing user to enter a key with up to 100 characters
    int choice;

    printf("Choose an operation:\n");
    printf("1. Encryption\n");
    printf("2. Decryption\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice. Exiting...\n");
        return EXIT_FAILURE;
    }

    printf("Enter the input file name: ");
    scanf("%s", inputFile);

    printf("Enter the output file name: ");
    scanf("%s", outputFile);


    return 0;
}
