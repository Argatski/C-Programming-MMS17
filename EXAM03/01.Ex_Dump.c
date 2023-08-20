#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void print_hex_dump(FILE *file) {
    unsigned char buffer[16];
    size_t offset = 0;
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        printf("%08lx: ", offset);
        for (size_t i = 0; i < bytesRead; i++) {
            printf("%02x ", buffer[i]);
        }
        for (size_t i = bytesRead; i < 16; i++) {
            printf("   ");
        }
        printf(" ");
        for (size_t i = 0; i < bytesRead; i++) {
            char c = buffer[i];
            if (c >= 32 && c <= 126) {
                printf("%c", c);
            } else {
                printf(".");
            }
        }
        printf("\n");
        offset += bytesRead;
    }
}

void print_binary(FILE *file) {
    unsigned char buffer;
    while (fread(&buffer, 1, 1, file) > 0) {
        for (int i = 7; i >= 0; i--) {
            printf("%d", (buffer >> i) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <-H/-B>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *print_mode = argv[2];

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    if (strcmp(print_mode, "-H") == 0) {
        print_hex_dump(file);
    } else if (strcmp(print_mode, "-B") == 0) {
        print_binary(file);
    } else {
        printf("Invalid print mode: %s\n", print_mode);
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}
