#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record{
    char doctorname[31];
    char username[31];
    char first_name[31];
    char last_name[31];
    char nic[15];
    char telephone[15];
    char sickness[31];
    char sickness_detail[63];
    char medical_prescription[63];
    char test_prescription[63];
} Record;

int create_medical_report(char* doctorname,char* username, char* first_name, char* last_name, char* nic, char* telephone_num, char* sickness_name, char* sickness_details,
                            char* drug_prescription, char* test_prescription)
{

FILE *fp;
fp=fopen("data.txt", "a");
if(fp == NULL)
    exit(-1);

fprintf(fp,"%-15s%-15s%-15s%-15s%-15s%-15s%-15s%-30s%-30s%-30s\n", doctorname,username, first_name, last_name, nic,telephone_num,sickness_name,sickness_details,drug_prescription,test_prescription);
fclose(fp);
return 1;

}

void read_all(char* username)
{
    char line[400];
    FILE  *read_file;

    read_file = fopen("data.txt", "r");
    if (read_file == NULL){
        printf("No records\n");
    }else{

        Record record;
        int found = 1;
        while (fgets(line, sizeof(line), read_file) != NULL)
        {
            sscanf(line,"%s%s%s%s%s%s%s%s%s%s",record.doctorname, record.username, record.first_name, record.last_name, record.nic, record.telephone, record.sickness, record.sickness_detail, record.medical_prescription, record.test_prescription);
            if(!strcmp(record.doctorname,username)){
                printf("%s | %s | %s | %s | %s | %s | %s | %s | %s\n",record.username, record.first_name, record.last_name, record.nic, record.telephone, record.sickness, record.sickness_detail, record.medical_prescription, record.test_prescription);
                found = 0;
            }

        }
        if(found){
            printf("No records\n");
        }
        fclose(read_file);
    }


}

void read_pharmacist()
{
    char line[400];
    FILE  *read_file;

    read_file = fopen("data.txt", "r");
    if (read_file == NULL){
        printf("No records\n");
    }else{

        Record _record;

        while (fgets(line, sizeof(line), read_file) != NULL)
        {

            sscanf(line,"%s%s%s%s%s%s%s%s%s%s",_record.doctorname, _record.username, _record.first_name, _record.last_name, _record.nic, _record.telephone, _record.sickness, _record.sickness_detail, _record.medical_prescription, _record.test_prescription);
            printf("%s | %s | %s\n",_record.username, _record.sickness,_record.medical_prescription);

        }
        fclose(read_file);

    }

}


void read_lab()
{

    char line[400];
    FILE  *read_file;

    read_file = fopen("data.txt", "r");
    if (read_file == NULL){
        printf("No records\n");
    }else{

        Record record;

        while (fgets(line, sizeof(line), read_file) != NULL)
        {
            sscanf(line,"%s%s%s%s%s%s%s%s%s%s",record.doctorname,record.username, record.first_name, record.last_name, record.nic, record.telephone, record.sickness, record.sickness_detail, record.medical_prescription, record.test_prescription);
            printf("%s | %s | %s\n",record.username, record.sickness,record.test_prescription);

        }
        fclose(read_file);


    }



}


void read_patient(char* username)
{

char line[400];
    FILE  *read_file;

    read_file = fopen("data.txt", "r");
    if (read_file == NULL){
        printf("No records\n");
    }else{

        Record record;
        int found = 1;
        while (fgets(line, sizeof(line), read_file) != NULL)
        {
            sscanf(line,"%s%s%s%s%s%s%s%s%s%s",record.doctorname, record.username, record.first_name, record.last_name, record.nic, record.telephone, record.sickness, record.sickness_detail, record.medical_prescription, record.test_prescription);
            if(!strcmp(record.username,username)){
                printf("%s | %s | %s | %s | %s | %s | %s | %s | %s\n",record.doctorname, record.first_name, record.last_name, record.nic, record.telephone, record.sickness, record.sickness_detail, record.medical_prescription, record.test_prescription);
                found = 0;
            }

        }
        if(found){
            printf("No records\n");
        }
        fclose(read_file);
    }

}
