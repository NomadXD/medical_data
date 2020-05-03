#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

typedef struct Account{
    char accountType[15];
    char username[31];
    char password[31];
    char privilegeLevel[1];
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

int login(char* username, char* password)
{

    char line[200];
    //Account account[200];
    int isValid = 0;
    FILE  *read_file;

    read_file = fopen("config.txt", "r");
    if (read_file == NULL)
        return -1;

    Account account;

    char *comaparePassword = str2md5(password, strlen(password));
    while (fgets(line, sizeof(line), read_file) != NULL)
    {
        char privilege[1];
        sscanf(line,"%s%s%s%s",account.username, account.accountType, privilege, account.password);

        if(!strcmp(username,account.username)){
            int temp = strcmp(comaparePassword,account.password);

            if(!(strcmp(comaparePassword,account.password))){
                isValid = privilege[0] - '0';
                break;
            }else{
                isValid = 5;
            }
        }

    }
    fclose(read_file);
    return isValid;

}

int signup(char* username, char* password, char* usertype, char* privilege)
{
FILE *fp;
fp=fopen("config.txt", "a");
if(fp == NULL)
    exit(-1);

char *hashedPassword = str2md5(password, strlen(password));
fprintf(fp,"%-15s%-15s%-15s%-15s\n", username, usertype, privilege, hashedPassword);
fclose(fp);
return 1;

}

void read_doctor()
{

char line[200];
FILE  *read_file;
read_file = fopen("config.txt", "r");
if (read_file == NULL){
    printf("No records\n");
}else{

    Account account;
    int not_found = 1;
    while (fgets(line, sizeof(line), read_file) != NULL)
    {
        char privilege[1];
        sscanf(line,"%s%s%s%s",account.username, account.accountType, privilege, account.password);

        if(!strcmp("Doctor",account.accountType)){
            printf("%s", account.username);
            not_found = 0;
        }

    }
    if(not_found){
        printf("No doctors registered\n");
    }
    fclose(read_file);

}

}


void read_all_lab()
{

char line[200];
FILE  *read_file;
read_file = fopen("config.txt", "r");
if (read_file == NULL){
    printf("No records\n");
}else{

    Account account;
    int not_found = 1;
    while (fgets(line, sizeof(line), read_file) != NULL)
    {
        char privilege[1];
        sscanf(line,"%s%s%s%s",account.username, account.accountType, privilege, account.password);

        if(!strcmp("Lab",account.accountType)){
            printf("%s", account.username);
            not_found = 0;
        }

    }
    if(not_found){
        printf("No Lab technicians registered\n");
    }
    fclose(read_file);

}

}


void read_all_pharmacist()
{

char line[200];
FILE  *read_file;
read_file = fopen("config.txt", "r");
if (read_file == NULL){
    printf("No records\n");
}else{

    Account account;
    int not_found = 1;
    while (fgets(line, sizeof(line), read_file) != NULL)
    {
        char privilege[1];
        sscanf(line,"%s%s%s%s",account.username, account.accountType, privilege, account.password);

        if(!strcmp("Pharmacist",account.accountType)){
            printf("%s", account.username);
            not_found = 0;
        }

    }
    if(not_found){
        printf("No Pharmacsits registered\n");
    }
    fclose(read_file);

}

}





