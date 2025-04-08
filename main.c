/* DOCUMENTATION
NAME:Dameruppula Abhinay
Description:AddressBook project
Date:30/11/2024
 */
#include<stdio.h>
#include<stdlib.h>
#include "project.h"
#include "file.h"
#include "populate.h"
#include<unistd.h>

int main()
{
    cont s[MAX_CONTACTS];
    int size=0;
      int option;
        int ch;
    // for(int i=1;i<=100;i++)//program to print loading message
    // {
    //     printf("Loading wait!!![");
    //     for(int j=1;j<=100;j++)
    //     {
    //         if(j<=i)
    //         {
    //             printf("_");
    //         }
    //         else{
    //             printf(" ");
    //         }
    //     }
        
    //     printf("]%d%%",i);
    //     fflush(stdout); 
    //     usleep(30000);
    //     //printf("\r");
    // }
    // fflush(stdout); 
    // printf("\n");

        load_contact(s,&size);//load contacts from the contacts.csv sheet
        printf("\n");
         printf("~~~~~~~~~~~~WELCOME TO ADDRESS BOOK PROJECT~~~~~~~~~~~~~~\n");
        //populateAddressBook(s,&size);
       do
       {
        printf("\n");
       printf("please select your option\n");
        printf("1.ADD CONTACT📒\n");
        printf("2.DISPLAY ALL CONTACTS💻\n");
        printf("3.DISPLAY SPECIFIC CONTACT🔍\n");
        printf("4.TO EDIT CONTACT📝\n");
        printf("5.DELETE CONTACT🚮\n");
        printf("6.SAVE CONTACTS🔃\n");
        printf("7.EXIT ↗️\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
             add_contact(s,&size);
             break;
             case 2:
            print_contacts(s,&size);
             break;
             case 3:
             int choice;
                printf("choose your choice to print the specific contact\n");
                printf("1.To print the contact by name 📛 :\n");
                printf("2.To print the contact by mobile number 📞:\n");
                printf("3.To print the contact by email address 📧:\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    char str[100];
                     printf("please enter contact name to print the data--> ::");
                     b:getchar();
                    scanf("%[^\n]",str);
                    if(print_specific_contact(s,str,&size))
                    {
                        printf("Enter contact name again\n");
                        goto b;
                    }
                    break;
                    case 2:
                    char mob1[100];
                    printf("Enter a mobile number to print the data ::\n");
                    a:getchar();
                     scanf("%s",mob1);
                    if(print_specific_contact(s,mob1,&size))
                    {
                        printf("Enter number again!!!\n");
                        goto a;
                    }
                    break;
                    case 3:
                    char add[100];
                    printf("Enter a mail address to print the contact   ::\n");
                    c:getchar();
                    scanf("%s",add);
                    if(print_specific_contact(s,add,&size))
                    {
                        printf("enter email again\n");
                        goto c;
                    }
                    break;
                    default:
                    printf("please choose the correct choice from the above MENU!!!\n");
                    break;
                }
            break;
            case 4:
            if(size==0)
            { 
                printf("No contact found to update the contacts,please update the data once\n");
            }
            else{
            char name[100];
             printf("enter the contact name to edit-->::");
             edit_c:getchar();
             scanf("%[^\n]",name);
             if(edit_contact(s,name,&size))
             {
                printf("enter the correct contact to edit the contact\n ");
                goto edit_c;
             }
            }
             break;
             case 5:
             if(size==0)
             {
                printf("No contact record found to delete the contact!!Add the contact to delete\n");
             }
             else{
             int opt;
                printf("choose your choice to delete specific contact\n");
                printf("1.To delete the contact by name ::\n");
                printf("2.To delete contact by mobile number    ::\n");
                printf("3.To delete contact by email address    ::\n");
                scanf("%d",&opt);
                switch(opt)
                {
                    case 1:
                    char str[100];
                    name:
                    printf("please enter contact name to delete the contact-->::");
                    getchar();
                    scanf("%[^\n]",str);
                    if(delete_specific_contact(s,str,&size))
                    {
                        goto name;
                    }
                    break;
                    case 2:
                    char mob1[100];
                    mob:
                    printf("Enter a mobile number to delete the contact-->::");
                    getchar();
                    scanf("%s",mob1);
                    if(delete_specific_contact(s,mob1,&size))
                    {
                        goto mob;
                    }
                    break;
                    case 3:
                    char add[100];
                    add:
                    printf("Enter a mail address to delete the contact--->::");
                      getchar();
                    scanf(" %s",add);
                    if(delete_specific_contact(s,add,&size))
                    {
                        goto add;
                    }
                    break;
                }
             }
            break;
              case 6:
              save_contact(s,&size);
            break;
             case 7:
             exit(0);//totally exit from the program
             break; 
             default:
             printf("enter the correct choice to access the contacts\n");
        }
        printf("Do you want to continue press '1,No to '0'---->::");
        scanf("%d",&ch);
    }while(ch==1);
}
