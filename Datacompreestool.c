#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using RLE
void compressFile(const char *input, const char *output) {
    FILE *fin = fopen(input, "r");
    FILE *fout = fopen(output, "w");

    if (fin == NULL || fout == NULL) {
        printf("Error opening files!\n");
        return;
    }

    char ch, prev;
    int count = 1;

    prev = fgetc(fin);
    while ((ch = fgetc(fin)) != EOF) {
        if (ch == prev) {
            count++;
        } else {
            fprintf(fout, "%c%d", prev, count);
            prev = ch;
            count = 1;
        }
    }
    fprintf(fout, "%c%d", prev, count);

    fclose(fin);
    fclose(fout);
    printf("Compression done successfully.\n");
}

// Function to decompress the compressed file
void decompressFile(const char *input, const char *output) {
    FILE *fin = fopen(input, "r");
    FILE *fout = fopen(output, "w");

    if (fin == NULL || fout == NULL) {
        printf("Error opening files!\n");
        return;
    }

    char ch;
    int count;

    while (fscanf(fin, "%c%d", &ch, &count) == 2) {
        for (int i = 0; i < count; i++) {
            fputc(ch, fout);
        }
    }

    fclose(fin);
    fclose(fout);
    printf("Decompression done successfully.\n");
}

int main() {
    int choice;
    char inputFile[50], outputFile[50];

    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFile);
    printf("Enter output file name: ");
    scanf("%s", outputFile);

    if (choice == 1) {
        compressFile(inputFile, outputFile);
    } else if (choice == 2) {
        decompressFile(inputFile, outputFile);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
