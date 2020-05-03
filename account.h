#ifndef FOO_DOT_H    /* This is an "include guard" */
#define FOO_DOT_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/

/**
 * This is a function declaration.
 * It tells the compiler that the function exists somewhere.
 */
int login(char* username, char* password);
int signup(char* username, char* password, char* usertype, char* privilege);
void read_all_pharmacist();
void read_all_lab();
void read_doctor();

#endif /* FOO_DOT_H */
