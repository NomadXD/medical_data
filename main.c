#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"
#include "data.h"

typedef struct Account{
    char accountType[15];
    char username[31];
    char password[31];
    char privilegeLevel[3];
} Account;

typedef struct Record{
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

void menu();
void mainMenu();
void optionsMenu();
void options();
int choice1 = 0;
int choice2 = 3;

int main(void)
 {
    menu();

    return 0;

 }


 void menu(){

        do {
        choice2 = 0;
        mainMenu();

        switch(choice1) {
            case 1:;
                Account _account;
                int type;
                printf("Please provide the required details for registration\n");
                printf("*** SELECT AN ACCOUNT TYPE ***\n");
                printf("Account types => | Doctor = 1 | | Patient = 2 | | Pharmacist = 3 | | Lab Technician = 4 | \n");
                printf("Account type: ");
                scanf("%d",&type);
                while(!(type == 1 || type == 2 || type == 3 || type == 4)){
                    printf("Inavalid input. Please select a valid input.\n");
                    printf("Account types => | Doctor = 1 | | Patient = 2 | | Pharmacist = 3 | | Lab Technician = 4 | \n");
                    scanf("%d",&type);
                    printf("Account type: ");
                }
                if(type == 1){
                    strcpy(_account.accountType,"Doctor");
                    strcpy(_account.privilegeLevel,"1");
                }else if(type == 2){
                    strcpy(_account.accountType,"Patient");
                    strcpy(_account.privilegeLevel,"2");
                }else if(type == 3){
                    strcpy(_account.accountType,"Pharmacist");
                    strcpy(_account.privilegeLevel,"3");
                }else{
                    strcpy(_account.accountType,"Lab");
                    strcpy(_account.privilegeLevel,"4");
                }
                type = 0;
                printf("*** SELECT A USERNAME ***\n");
                printf("Only alphanumeric characters and _ are allowed.\n");
                printf("No spaces are allowed. Use _ for multiple words\n");
                printf("Username: ");
                scanf("%s",_account.username);
                printf("*** SELECT A PASSWORD ***\n");
                printf("Password: ");
                scanf("%s", _account.password);
                if(signup(_account.username, _account.password, _account.accountType, _account.privilegeLevel)){
                    printf("Account successfully created for %s under account type %s \n", _account.username, _account.accountType);
                    printf("Login using the username and password you provided\n");
                }else{
                    printf("Account creation failed!! Try again.");
                }

                break;

            case 2: ;
                char username_provided[31];
                char password_provided[31];
                printf("Provide your username and password\n");
                printf("Username:");
                scanf("%s",username_provided);
                printf("Password:");
                scanf("%s",password_provided);
                int status;
                if(login(username_provided, password_provided) == 1){
                    status = 1;
                    printf("Welcome %s .You have logged in as a doctor.\n",username_provided);
                    options(status, username_provided);
                }else if (login(username_provided, password_provided) == 2){
                    status = 2;
                    printf("Welcome %s .You have logged in as a patient.\n",username_provided);
                    options(status, username_provided);
                }else if(login(username_provided, password_provided) == 3){
                    status = 3;
                    printf("Welcome %s .You have logged in as a pharmacist.\n",username_provided);
                    options(status, username_provided);
                }else if(login(username_provided, password_provided) == 4){
                    status = 4;
                    printf("Welcome %s .You have logged in as a Lab Technician.\n",username_provided);
                    options(status, username_provided);
                }else if(login(username_provided, password_provided) == 5){
                    printf("Invalid password for the username %s\n", username_provided);
                }else{
                    printf("Username %s is not registered. Register as a user first.\n",username_provided);
                }
                break;

            case 3:
                break;

        }

    } while(choice1 != 3);


}

void options(int status,char* username) {

    do {
        optionsMenu(status);
        if(status == 1){

            switch(choice2){

                case 1:;
                    Record record;
                    printf("Please provide the required details.....\n");
                    printf("Username of the patient: ");
                    scanf("%s",record.username);
                    printf("First Name of the patient: ");
                    scanf("%s", record.first_name);
                    printf("Last name of the patient:");
                    scanf("%s", record.last_name);
                    printf("NIC of the patient:");
                    scanf("%s",record.nic);
                    printf("Telephone number:");
                    scanf("%s",record.telephone);
                    printf("Sickness:");
                    scanf("%s",record.sickness);
                    printf("Sickness details:");
                    scanf("%s",record.sickness_detail);
                    printf("Medical prescription:");
                    scanf("%s", record.medical_prescription);
                    printf("Test prescription:");
                    scanf("%s",record.test_prescription);
                    if(create_medical_report(username,record.username,record.first_name,record.last_name,record.nic,record.telephone,record.sickness,record.sickness_detail,record.medical_prescription,record.test_prescription)){
                        printf("Record successfully entered\n");
                    }else{

                        printf("Record creation failed\n");
                    }
                    break;

                case 2:
                    read_all(username);
                    printf("read call called");
                    break;

                case 4:
                    read_all_pharmacist();
                    break;

                case 5:
                    read_all_lab();

                case 3:
                    break;

                default:
                    printf("Invalid input\n");
                    break;

            }

        }else if (status == 2){

            switch(choice2){

                    case 1:
                        read_patient(username);
                        break;

                    case 2:
                        read_doctor();
                        break;

                    case 3:
                        break;

                    default:
                        printf("Invalid input\n");
                        break;

            }

        }else if (status == 3){

            switch(choice2){

                    case 1:
                        read_pharmacist();
                        break;

                    case 2:
                        read_doctor();
                        break;

                    case 3:
                        break;

                    default:
                        printf("Invalid input\n");
                        break;

            }


        }else if (status == 4){

            switch(choice2){

                    case 1:;
                        read_lab();
                        break;

                    case 2:
                        read_doctor();
                        break;

                    case 3:
                        break;

                    default:
                        printf("Invalid input\n");
                        break;

            }


        }

    } while(choice2 != 3);


}




void mainMenu(void) {

    printf("--------------------------Main Menu-----------------------------\n");
    printf("1 - Register\n");
    printf("2 - Sign In\n");
    printf("3 - Quit\n");
    printf("Please choose: ");
    scanf("%d",&choice1);

}

void optionsMenu(int status) {

    if(status == 1){

        printf("Options Menu\n");
        printf("1 - Add patient data\n");
        printf("2 - View patient data\n");
        printf("4 - View pharmacists\n");
        printf("5 - View lab technicians\n");
        printf("3 - Log out\n");

    }else if (status == 2){

        printf("Options Menu\n");
        printf("1 - View Medical data\n");
        printf("2 - View Regsitered doctots\n");
        printf("3 - Log out\n");

    }else if (status == 3){

        printf("Options Menu\n");
        printf("1 - View Medical prescriptons\n");
        printf("2 - View Regsitered doctots\n");
        printf("3 - Log out\n");

    }else if (status == 4){

        printf("Options Menu\n");
        printf("1 - View Lab test prescriptons\n");
        printf("2 - View Regsitered doctots\n");
        printf("3 - Log out\n");

    }

    printf("Please choose: ");
    scanf("%d",&choice2);

}
