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

    if (strcmp(inputFile, outputFile) == 0) {
        printf("Error: Input and output file names must be different to avoid overwriting.\n");
        return EXIT_FAILURE;
    }

    
    if (choice == 1) {
        printf("Enter a key for encryption (multiple characters allowed): ");
    } else {
        printf("Enter a key for decryption (multiple characters allowed): ");
    }

    scanf("%s", key);

   
    return 0;
}
