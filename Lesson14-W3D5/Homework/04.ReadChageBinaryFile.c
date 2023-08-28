#include <stdio.h>


int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "ab+");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    char command;
    while (scanf(" %c", &command) != EOF) {
        if (command == 'd') {
            fseek(file, 0, SEEK_SET);
            int byte;
            while ((byte = fgetc(file)) != EOF) {
                printf("%02x ", byte);
            }
            printf("\n");
        } else if (command == 't') {
            fseek(file, 0, SEEK_SET);
            int byte;
            while ((byte = fgetc(file)) != EOF) {
                printf("%c", byte);
            }
            printf("\n");
        } else if (command == 'a') {
            unsigned int newByte;
            scanf("%x", &newByte);
            fputc(newByte, file);
        } else if (command == 'c') {
            int start, end;
            scanf("%d %d", &start, &end);
            FILE *tempFile = tmpfile();
            fseek(file, 0, SEEK_SET);
            int byte;
            while ((byte = fgetc(file)) != EOF) {
                if (ftell(file) < start || ftell(file) > end) {
                    fputc(byte, tempFile);
                }
            }
            fclose(file);
            file = tempFile;
        } else if (command == 'e') {
            int index;
            unsigned int newByte;
            scanf("%d %x", &index, &newByte);
            fseek(file, index, SEEK_SET);
            fputc(newByte, file);
        }
        else
        {
            fclose(file);
            return 0;
        }
    }


    return 0;
}