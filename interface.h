#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>

// File Integrity Check: Verifies if the file can be opened.
void file_check(FILE *fp, char file_name[]);

// Passwd File Validation: Validates the integrity of the passwd file.
void passwd_check(FILE *fpasswd);

// Shadow File Validation: Validates the integrity of the shadow file.
void shadow_check(FILE *fshadow);

#endif // INTERFACE_H
