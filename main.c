#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

typedef struct Person{
    char name[20];
    char address[30];
    char phone[20];
} Person;

typedef struct Account{
    char accountType[15];
    char username[31];
    char password[31];
    int privilegeLevel;
} Account;

void menu();
void mainMenu();
void optionsMenu();
void options();
int choice1 = 0;
int choice2 = 3;

int main(void)
 {

    //signup("xxxxxx","password","Doctor");
    //login();

    menu();



    return 0;


 }



 void menu(){

        do {
        choice2 = 0;
        mainMenu();

        switch(choice1) {
            Account account;
            int type;
            case 1:
                printf("Please provide the required details for registration\n");
                printf("*** SELECT A USERNAME ***\n");
                printf("Only alphanumeric characters and _ are allowed.\n");
                printf("No spaces are allowed. Use _ for multiple words\n");
                printf("Username: ");
                scanf("%s",account.username);
                printf("*** SELECT AN ACCOUNT TYPE ***\n");
                printf("Account types => | Doctor = 1 | | Patient = 2 | | Nurse = 3 | \n");
                printf("Account type: ");
                scanf("%d",&type);
                while(!(type == 1 || type == 2 || type == 3)){
                    printf("Inavalid input. Please select a valid input.\n");
                    printf("Account types => | Doctor = 1 | | Patient = 2 | | Nurse = 3 | \n");
                    scanf("%d",&type);
                }
                printf("*** SELECT A PASSWORD ***\n");
                printf("Password: ");
                scanf("%s", account.password);
                printf("Username is %s and password is %s. User type is %d",account.username,account.password,type);
                break;

            case 2:
                options();
                break;

            case 3:
                break;

        }

    } while(choice1 != 3);


}

void options(void) {

    do {
        optionsMenu();

        switch(choice2){

            case 1:
                printf("So difficult!\n");
                break;

            case 2:
                printf("Beep!\n");
                break;

            case 3:
                break;

            default:
                break;

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

void optionsMenu(void) {

    printf("Options Menu\n");
    printf("1 - Difficulty\n");
    printf("2 - Sound\n");
    printf("3 - Back\n");
    printf("Please choose: ");
    scanf("%d",&choice2);

}
