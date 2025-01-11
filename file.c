#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecryptFile(const char *inputFile, const char *outputFile, const char *key) {
    FILE *fin = fopen(inputFile, "rb");  // Open input file in binary read mode
    FILE *fout = fopen(outputFile, "wb");  // Open output file in binary write mode

    if (fin == NULL) {
        printf("Error: Unable to open input file '%s'.\n", inputFile);
        exit(EXIT_FAILURE);
    }
    if (fout == NULL) {
        printf("Error: Unable to open output file '%s'.\n", outputFile);
        fclose(fin);
        exit(EXIT_FAILURE);
    }
  char ch;
    int keyLength = strlen(key);  // Length of the key
    int keyIndex = 0;  // Index to track position in the key

    while ((ch = fgetc(fin)) != EOF) {
        char processedChar = ch ^ key[keyIndex];  // XOR operation

        // Debugging: Print original and processed characters as ASCII values
        printf("Original: %d, Processed: %d\n", ch, processedChar);

        fputc(processedChar, fout);  // Write the processed character to the output file

        // Move to the next character in the key (loop back if needed)
        keyIndex = (keyIndex + 1) % keyLength;
    }


    fclose(fin);
    fclose(fout);

    printf("Operation completed successfully. Output saved to '%s'.\n", outputFile);
}

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
 if (strlen(key) == 0) {
        printf("Error: Key must not be empty. Exiting...\n");
        return EXIT_FAILURE;
    }

    if (choice == 1) {
        printf("\nStarting encryption...\n");
    } else {
        printf("\nStarting decryption...\n");
    }

    
    encryptDecryptFile(inputFile, outputFile, key);

    printf("\nFile operation finished.\n");

   
    return 0;
}
