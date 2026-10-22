//
// Created by rin-dev on 10/17/26.
//
// Parse a line like Alice,28,Engineer
// into a Person struct with name, age, and title fields. Handle fields with a fixed maximum name length.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// static constexpr int MAX_LINE_LEN = 1024;
static constexpr int MAX_LINES = 100;
static constexpr int MAX_LEN = 512;
static constexpr char DELIMITER[] = ",";
static constexpr char NEWLINE[] = "\n";

typedef struct {
    char name[MAX_LEN];
    int age;
    char title[MAX_LEN];
} Person;

//todo drop strtok
//todo could use strcspn with DELIMITER to get length of string before next occurance
int main () {
    FILE *pointer_file = fopen("./sample_contacts.csv", "r");
    char buffer[MAX_LINES];

    if (pointer_file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    Person personArray[MAX_LINES] = {};

    int row = 0;
    while (row < MAX_LINES && fgets(buffer, sizeof(buffer), pointer_file) != NULL) {
        printf("Read: %s", buffer);
        // Get the first token
        char *token = strtok(buffer, DELIMITER);//c automatically passes the pointer to first element in array so equivalent of `&delimiter[0]`

        int col = 0;
        Person personTemp = {};
        personArray[row] = personTemp;
        // Walk through the rest of the tokens
        while (token != NULL) {
            printf("r: %d,c: %d, token: [%s]\n", row, col, token);

            if (col == 0) {
                strncpy(personArray[row].name, token, MAX_LEN-1);
                personArray[row].name[MAX_LEN-1] = '\0';
            }

            if (col == 1) {
                char *p_err;
                personArray[row].age = (int)strtol(token, &p_err, 10);
                if (p_err == token) {
                    printf("Unable to parse age from line %d: %s\n", row, p_err);
                }
            }

            if (col == 2) {
                const size_t length = strcspn(token, NEWLINE);
                strncpy(personArray[row].title, token, MAX_LEN-1);
                personArray[row].title[length] = '\0';
            }

            // Subsequent calls require NULL as the first argument
            token = strtok(nullptr, DELIMITER);
            col++;
        }
        printf("Row: %d, struct name: [%s], struct age: [%d], struct title: [%s]\n", row, personArray[row].name, personArray[row].age, personArray[row].title);
        row++;
    }

    if (feof(pointer_file)) {
        printf("End of file reached.\n");
    } else if (ferror(pointer_file)) {
        printf("An error occurred.\n");
    }

    fclose(pointer_file);
    return 0;
}
