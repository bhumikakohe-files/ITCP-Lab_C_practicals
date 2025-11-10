//AIM:Write a C program (name it "filecopy. c")  that copies the contents of one file to a destination file. This program will read data from one file and copy them to another. The first input that the program will need is the names of the two files: input file ("input.txt") and output file ("output.txt").
// Once the two file names have been obtained, the program must open the input file and 
//create and open the output file.
//ROLL NO 102
#include <stdio.h>
#include <stdlib.h>

int main() {
    char inputFileName[100], outputFileName[100];
    FILE *inputFile, *outputFile;
    char ch;

    // Prompt for file names
    printf("Enter input file name (e.g., input.txt): ");
    scanf("%s", inputFileName);

    printf("Enter output file name (e.g., output.txt): ");
    scanf("%s", outputFileName);

    // Open input file for reading
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open output file for writing (creates if not exists)
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error creating output file");
        fclose(inputFile);
        return 1;
    }

    // Copy contents character by character
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch, outputFile);
    }

    printf("File copied successfully.\n");

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
