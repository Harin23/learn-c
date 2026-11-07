//
// Created by rin-dev on 10/17/26.
//
// Parse a line like Alice,28,Engineer
// into a Person struct with name, age, and title fields. Handle fields with a fixed maximum name length.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//todo look over initializations and memory allocations. buffer smaller than struct props (name, title).
//todo handle line that is too long (reject/truncate). this is part of criteria for lab completion
//todo fix warnings

static constexpr int MAX_LINE_LEN = 512;
static constexpr int MAX_LINES = 100;
static constexpr int MAX_LEN = 128;
static constexpr char DELIMITER = ',';
static constexpr char NEWLINE = '\n';
static constexpr char NUL = '\0';

typedef struct {
    char name[MAX_LEN];
    int age;
    char title[MAX_LEN];
} Person;

int main () {
    FILE *pointer_file = fopen("./sample_contacts.csv", "r");
    char buffer[MAX_LINE_LEN];

    if (pointer_file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    Person personArray[MAX_LINES] = {};

    int row = 0;
    while (row < MAX_LINES && fgets(buffer, sizeof(buffer), pointer_file) != NULL) {
        // printf("Read: %lu, [%c], [%s]", strlen(buffer), buffer[strlen(buffer)], buffer);
        const size_t LENGTH = strlen(buffer);

        if (LENGTH > 0 && !(buffer[LENGTH-1] == NEWLINE || feof(pointer_file))) {
            //drop line didn't fit into buffer
            printf("Skipping line due to buffer overflow.\n");
            int c;
            while (( c = fgetc(pointer_file)) != NEWLINE && c != EOF) {};
            continue;
        }

        Person personTemp = {};
        personArray[row] = personTemp;
        char temp[MAX_LEN]="";
        for (size_t i=0, col = 0, startIndex = 0; i <= LENGTH; i++) {
            if (buffer[i] == DELIMITER || buffer[i] == NEWLINE || buffer[i] == NUL) {
                if (col == 0) {
                    strncpy(personArray[row].name, temp, MAX_LEN-1);
                }

                if (col == 1) {
                    char *p_err;
                    personArray[row].age = (int)strtol(temp, &p_err, 10);
                    if (p_err == temp) {
                        printf("Unable to parse age from line %d: %s\n", row, p_err);
                        personArray[row].age = 0;
                    }
                }

                if (col == 2) {
                    strncpy(personArray[row].title, temp, MAX_LEN-1);
                }
                startIndex = i+1;
                col++;
                strncpy(temp, "", MAX_LEN-1);
            }else {
                const size_t j = i - startIndex;
                if (j < MAX_LEN - 1) {
                    temp[j] = buffer[i];
                }
            }
        }
        printf("\n\nRow: %d, struct name: [%s], struct age: [%d], struct title: [%s]\n\n", row, personArray[row].name, personArray[row].age, personArray[row].title);
        row++;
    }

    if (feof(pointer_file)) {
        printf("\nEnd of file reached.\n");
    } else if (ferror(pointer_file)) {
        printf("\nAn error occurred.\n");
    }

    fclose(pointer_file);
    return 0;
}
