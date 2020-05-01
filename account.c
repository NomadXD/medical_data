#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

typedef struct Person{
    char username[31];
    char password[127];
    char usertype[15];
    char privilege[3];
} Person;

typedef struct Account{
    char accountType[15];
    char username[31];
    char password[31];
    char privilegeLevel[3];
} Account;

 char *str2md5(const char *str, int length) {
    int n;
    MD5_CTX c;
    unsigned char digest[16];
    char *out = (char*)malloc(33);

    MD5_Init(&c);

    while (length > 0) {
        if (length > 512) {
            MD5_Update(&c, str, 512);
        } else {
            MD5_Update(&c, str, length);
        }
        length -= 512;
        str += 512;
    }

    MD5_Final(digest, &c);

    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }

    return out;
}

void login()
{

    char line[200];
    Person persons[200];
    FILE  *read_file;

    read_file = fopen("test.txt", "r");
    if (read_file == NULL)
        return -1;

    printf("File successfully read \n");

    char *output = str2md5("hello", strlen("hello"));
    printf("%s\n", output);

    Person person;

    while (fgets(line, sizeof(line), read_file) != NULL)
    {
        sscanf(line,"%s%s%s%s",person.username, person.password, person.usertype, person.privilege);
        printf("%s %s %s %s\n", person.username, person.password, person.usertype, person.privilege);
    }
    fclose(read_file);

}

int signup(char* username, char* password, char* usertype, char* privilege)
{
FILE *fp;
fp=fopen("test.txt", "a");
if(fp == NULL)
    exit(-1);

char *hashedPassword = str2md5(password, strlen(password));
fprintf(fp,"%-15s%-30s%-15s%-15s\n", username, usertype, privilege, hashedPassword);
fclose(fp);
return 1;

}





