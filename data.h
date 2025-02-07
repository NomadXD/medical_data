#ifndef FOO_DOT_H    /* This is an "include guard" */
#define FOO_DOT_H    /* prevents the file from being included twice. */
                     /* Including a header file twice causes all kinds */
                     /* of interesting problems.*/

/**
 * This is a function declaration.
 * It tells the compiler that the function exists somewhere.
 */
int create_medical_report(char* username, char* first_name, char* last_name, char* nic, char* telephone_num, char* sickness_name, char* sickness_details,
                            char* drug_prescription, char* test_prescription);


void read_all(char* username);
void read_pharmacist();
void read_lab();
void read_patient(char* username);

#endif /* FOO_DOT_H */
