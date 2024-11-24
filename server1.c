#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"

#define MAX_LINE_LENGTH 1000
#define MAX_FIELDS 100

// Function to check if the file is opened successfully
void file_check(FILE *fp, char file_name[]) {
    if (fp == NULL) {
        printf("Error: Unable to open file %s. Please check the file name and try again.\n", file_name);
        exit(1);
    }
    printf("%s file opened successfully.\n", file_name);
}

// Function to validate the passwd file
void passwd_check(FILE *fpasswd) {
    char line[MAX_LINE_LENGTH];
    char split[MAX_FIELDS][MAX_LINE_LENGTH];
    char *token;
    int line_no, field_no;

    for (line_no = 0; fgets(line, MAX_LINE_LENGTH, fpasswd) != NULL; line_no++) {
        if (line[0] == ':' || line[0] == ' ') {
            printf("Error in line %d: User account name is empty or blank.\n", line_no + 1);
            continue;
        }

        token = strtok(line, ":");
        field_no = 0;
        while (token != NULL) {
            strcpy(split[field_no], token);
            token = strtok(NULL, ":");
            field_no++;
        }

        // Validate password field
        if (split[1][0] != 'x') {
            printf("Error in line %d: Password for user %s is invalid.\n", line_no + 1, split[0]);
        }

        // Validate user ID field
        if (!isdigit(split[2][0])) {
            printf("Error in line %d: User ID for user %s is invalid.\n", line_no + 1, split[0]);
        }
    }
}

// Function to validate the shadow file
void shadow_check(FILE *fshadow) {
    char line[MAX_LINE_LENGTH];
    char split[MAX_FIELDS][MAX_LINE_LENGTH];
    char *token;
    int line_no, field_no;

    for (line_no = 0; fgets(line, MAX_LINE_LENGTH, fshadow) != NULL; line_no++) {
        if (line[0] == ':' || line[0] == ' ') {
            printf("Error in line %d: User account name is empty or blank.\n", line_no + 1);
            continue;
        }

        token = strtok(line, ":");
        field_no = 0;
        while (token != NULL) {
            strcpy(split[field_no], token);
            token = strtok(NULL, ":");
            field_no++;
        }

        // Validate password field
        if (split[1][0] != '*' && split[1][0] != '!' && strlen(split[1]) != 98) {
            printf("Error in line %d: Password for user %s is invalid.\n", line_no + 1, split[0]);
        }

        // Validate user ID field
        if (!isdigit(split[2][0])) {
            printf("Error in line %d: User ID for user %s is invalid.\n", line_no + 1, split[0]);
        }
    }
}
