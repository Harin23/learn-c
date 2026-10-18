//
// Created by rin-dev on 10/17/26.
//
// Parse a line like Alice,28,Engineer
// into a Person struct with name, age, and title fields. Handle fields with a fixed maximum name length.
//

#include <stdio.h>

static const int MAX_LINE_LEN = 1024;

//todo clean this up and refactor out of main
int main () {

    FILE *pointer_file = fopen("./sample_contacts.csv", "r");
    char buffer[MAX_LINE_LEN];

    if (pointer_file == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), pointer_file) != NULL) {
        printf("Read: %s", buffer);
    }

    if (feof(pointer_file)) {
        printf("End of file reached.\n");
    } else if (ferror(pointer_file)) {
        printf("An error occurred.\n");
    }

    fclose(pointer_file);
    return 0;
}
