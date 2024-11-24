# pwck-mimic

## **Overview**
`pwck-mimic` is a C-based program that replicates the functionality of the Linux `pwck` command. It verifies the integrity of user authentication files (`passwd` and `shadow`) by validating their format and consistency. This project uses a modular design with a Makefile for simplified execution and comes with example files (`passwd.txt` and `shadow.txt`) for testing.

---

## **What is the `pwck` Command?**
The Linux `pwck` command is a system administration utility that checks the validity of `/etc/passwd` and `/etc/shadow` files. It ensures these files are correctly formatted and consistent. `pwck-mimic` provides a similar functionality using custom code written in C.

---

## **Programming Language**
This project is implemented in **C**, leveraging modular programming principles for scalability and maintainability.

---

## **Files in the Project**
1. **`client1.c`**: Contains the main program logic that:
   - Opens the `passwd` and `shadow` files.
   - Checks for errors in file access and passes the files for validation.

2. **`server1.c`**: Includes the logic to:
   - Validate the `passwd` file for inconsistencies, such as:
     - Empty usernames.
     - Missing or invalid password fields.
     - Non-numeric user IDs.
   - Validate the `shadow` file for errors, such as:
     - Empty usernames.
     - Invalid password formats.
     - Non-numeric user IDs.

3. **`interface.h`**: Header file containing function declarations used in the project.

4. **`passwd.txt`**: Sample `passwd` file used for testing the program.

5. **`shadow.txt`**: Sample `shadow` file used for testing the program.

6. **`lab3.mk`**: Makefile used for building and running the project.

---

## **Features**
- **File Integrity Checks**: Ensures that all fields in the `passwd` and `shadow` files follow the correct format.
- **Validation Logic**:
  - Checks for empty fields.
  - Ensures passwords are properly formatted (e.g., encrypted or valid placeholders like `x`, `*`, or `!`).
  - Verifies that user IDs are numeric.
- **Modular Design**: Implements separation of concerns with reusable functions.
- **Example Files**: Comes with sample files (`passwd.txt` and `shadow.txt`) for quick testing.
- **Makefile Support**: Simplifies the build and execution process.

---

## **How to Run**
1. Ensure you have a C compiler (like GCC) installed on your system.
2. Use the following command to compile and run the program using the provided Makefile:

   ```bash
   make -f lab3.mk

3. After successful compilation, execute the program: ./lab3
   
 4. Follow the program's instructions to enter the names of the passwd and shadow files you wish to validate.

## **Space and Time Complexity**

### **Time Complexity**
- **File Parsing**:
  - Reading and parsing the `passwd` or `shadow` file: **O(n)**, where `n` is the number of lines in the file.
- **Validation**:
  - Checking the fields within each line: **O(m)**, where `m` is the number of fields per line.

### **Space Complexity**
- **In-Memory Storage**:
  - Temporary storage for file content: **O(n)**, where `n` is the number of lines in the largest file.
