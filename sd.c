#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file;

    // Open the file
    file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long int filesize = ftell(file);
    fclose(file);

    // Write the file with random bytes
    file = fopen(argv[1], "wb");
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < filesize; i++) {
        char randomByte = (char)(rand() % 256); // Generate a random byte (0 to 255)
        fwrite(&randomByte, sizeof(char), 1, file);
    }
    fclose(file);

    // Delete the file
    unlink(argv[1]);

    printf("Wrote %ld bytes to file \"%s\" and then deleted it.\n", filesize, argv[1]);

    return 0;
}
