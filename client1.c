#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"

#define MAX_FILENAME_SIZE 25

int main() {
    char passwd[MAX_FILENAME_SIZE];
    char shadow[MAX_FILENAME_SIZE];
    FILE *fpasswd, *fshadow;

    // Input filenames from user
    puts("Enter the name of the passwd file along with the extension:");
    scanf("%s", passwd);

    puts("Enter the name of the shadow file along with the extension:");
    scanf("%s", shadow);

    // Open files
    fpasswd = fopen(passwd, "r");
    fshadow = fopen(shadow, "r");

    // Check if files opened successfully
    file_check(fpasswd, passwd);
    file_check(fshadow, shadow);

    // Process passwd file
    puts("****** PASSWD FILE *******");
    passwd_check(fpasswd);

    // Process shadow file
    puts("****** SHADOW FILE *******");
    shadow_check(fshadow);

    // Close files
    fclose(fpasswd);
    fclose(fshadow);

    return 0;
}
