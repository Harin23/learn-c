//
// Created by rin-dev on 10/17/26.
//
// Parse a line like Alice,28,Engineer
// into a Person struct with name, age, and title fields. Handle fields with a fixed maximum name length.
//

#include <stdio.h>
#include <string.h>

static constexpr int MAX_LINE_LEN = 1024;
static constexpr char delimiter[] = ",";
static constexpr char newline[] = "\n";

typedef struct {
    char name[MAX_LINE_LEN];
    int age;
    char title[MAX_LINE_LEN];
} Person;

int main () {
    FILE *pointer_file = fopen("./sample_contacts.csv", "r");
    char buffer[MAX_LINE_LEN];

    if (pointer_file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }


    while (fgets(buffer, sizeof(buffer), pointer_file) != NULL) {
        printf("Read: %s", buffer);
        // Get the first token
        char *token = strtok(buffer, delimiter);//c automatically passes the pointer to first element in array so equivalent of `&delimiter[0]`

        // char [][]
        // Walk through the rest of the tokens
        while (token != NULL) {
            const size_t length = strcspn(token, newline);
            if (length != strlen(token)) {

            }
            printf("Token: [%s]\n updatedToken: [%s]", token, updatedToken);
            
            // Subsequent calls require NULL as the first argument
            token = strtok(nullptr, delimiter);
        }
    }

    if (feof(pointer_file)) {
        printf("End of file reached.\n");
    } else if (ferror(pointer_file)) {
        printf("An error occurred.\n");
    }

    fclose(pointer_file);
    return 0;
}
