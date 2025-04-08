#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "project.h"
#include "file.h"
//All function definitions
void add_contact(cont * ptr,int * size)
{       again:
        printf("Enter contact name   ::");
        getchar();
        scanf("%[^\n]",ptr[*size].name);
        if(validate_name(ptr[*size].name,*size,ptr))
        { 
            printf("please enter the correct contact Name AGAIN!!\n");
            goto again;
        }
        loop: 
         printf("Enter contact mobile   ::");
         getchar();
        scanf("%s",ptr[*size].mobile);
        if(validate_mob(ptr[*size].mobile,*size,ptr))
        {
            printf("Please enter AGAIN your mobile number \n");
            goto loop;
        }
        l:
         printf("Enter Email    ::");
         getchar();
        scanf("%s",ptr[*size].email);
        if(validate_email(ptr[*size].email,*size,ptr))
        {
            printf("please enter the correct email id that should present onlu a-z,0-9 and  at last @gamil.com\n");
            goto l;
        }
        (*size)++;
        printf("\n");
        printf("CONTACT ADDED SUCCESSFULLY!!!\n");
}
void print_contacts( cont *ptr,int *size)
{ 
     if(*size==0)
    {
        printf("No contact recorded update the contacts\n");
    }
    else
    { 
        printf("\n");
        printf("DISPLAYING ALL CONTACTS.....\n");
        printf("\n");
   printf("==================================================================================================\n");
    printf("S.NO\t%-20s%-15s%-30s\n", "NAME", "MOBILE", "EMAIL");
    for(int i=0;i<*size;i++)
    {
        printf("% -5d\t%-20s%-15s%-30s\n",i+1,ptr[i].name,ptr[i].mobile,ptr[i].email);
    }
    printf("==================================================================================================\n");
    }  
}
int print_specific_contact(cont* ptr,char *str,int *size)
{  
    if(*size==0)
    {
        printf("No contact recorded update the contacts\n");
    } 
    int found=0;
    for(int i=0;i<*size;i++)
    {
        if(strcmp(ptr[i].name,str)==0 || strcmp(ptr[i].email,str)==0 || strcmp(ptr[i].mobile,str)==0)
        {   printf("==================================================================================================\n");
            printf("INDEX\t%-20s%-15s%-30s\n","NAME","MOBILE","EMAIL");
            printf("%-5d\t%-20s%-15s%-30s\n",i,ptr[i].name,ptr[i].mobile,ptr[i].email);
         printf("==================================================================================================\n");
            found=1;
        }
    }
    if(found==1)
    {
        return 0;
    }
    if(found==0)
    {
        printf("contact Name,mail id and mobile number is not found\n");
    }
    return 1;
}
int edit_contact(cont *ptr,char * str,int*size)
{  
char ch;
int j,s=0,found1=0,edit_ind,flag=0;
int arr[s];
    for(j=0;j<*size;j++)
    {   
        if(strcmp(ptr[j].name,str)==0|| strcmp(ptr[j].mobile,str)==0||strcmp(ptr[j].email,str)==0)
        {   printf("\n");
            printf("%d \t %s \t\t  %s \t\t%s\n",j,ptr[j].name,ptr[j].mobile,ptr[j].email);
            arr[s++]=j;
            printf("\n");
            found1=1;
        }
    }
    if(found1!=0)
    {
        printf("you selected contact has the above,please select the index that which contact you need to EDIT\n");
        edit:getchar();
        scanf("%d",&edit_ind);
        for(int id=0;id<s;id++)
        {
            if(edit_ind==arr[id])
            {
                flag=1;
                break;
            }
        }
            if(flag==0)
            {
                printf("select correct index from the above list\n");
                goto edit;
            }
        if(edit_ind<0 || edit_ind>*size)
        {
            printf("Enter the correct index that matches the above existing contacts index\n");
            goto edit;
        }
    }   if(found1!=0)
    {
        do
        {
          printf("select which details you need to edit\n");
          printf("\n");
          printf("1.contact Name\n");
          printf("2.Mobile number\n");
          printf("3.Email Address\n");
          int choice1,flag=0;
          getchar();
          scanf("%d",&choice1);
          switch(choice1)
          {
            case 1:
            char name[50];
            printf("enter the new name to edit--> ::");
            name:getchar();
            scanf("%[^\n]",name);
            if(validate_name(name,*size,ptr))
            {
            printf("please enter the correct Name To edit!!\n");
            printf("\n");
            goto name;
            }
            strcpy(ptr[edit_ind].name,name);
            printf("Updated successfully!!\n");
            printf("\n");
            break;
            case 2:
            char mob[100];
            printf("enter the new mobile number to edit-->::");
            mobile:getchar();
            scanf("%s",mob);
            if(validate_mob(mob,*size,ptr))
            {
                printf("Please enter your new mobile number \n");
                printf("\n");
            goto mobile;
            }
            strcpy(ptr[edit_ind].mobile,mob);
            printf("Updated successfully!!\n");
            printf("\n");
            break;
            case 3:
            char newaddress[100];
            printf("enter the new Email address to update-->::");
            mail:getchar();
            scanf("%s",newaddress);
             if(validate_email(newaddress,*size,ptr))
            {
            printf("please enter the correct email id that should present only a-z,0-9 and  at last @gamil.com\n");
            printf("\n");
            goto mail;
            }
            strcpy(ptr[edit_ind].email,newaddress);
            printf("Updated successfully!!\n");
            printf("\n");
            break;
            default:
            printf("select the correct choice\n");
          }
          printf("Do you want to continue to edit press y (or) n-->:: ");
          getchar();
          scanf("%c",&ch);
        } while(ch=='y');
    }
    if(found1==0)
    {
        return 1;

    }
    return 0;
}
 int validate_name(char* str,int size,cont *ptr)
 {
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='0' && str[i]<='9' || str[i]=='@' || str[i]=='#' ||str[i]=='$' || str[i]=='%' || str[i]=='&' || str[i]=='*')
        { 
            printf("Your name should only a-z and A-Z !!!\n");
            return 1;
        }
    }
 }
 int validate_mob(char *str,int size,cont *ptr)
 { int count=0;
    for(int i=0;str[i]!='\0';i++)
    {    
        if(isdigit(str[i]))
        {
            count++;
        }
        else{
            printf("Enter the phone number in DIGITS(0-9)!!!\n");
            return 1;
        }
    }
    if(count!=10)
    { 
        printf("Enter the TEN DIGITS of mobile number\n");
        return 1;
    }
    for(int i=0;i<size;i++)
    {
        if(!strcmp(ptr[i].mobile,str))
        { printf("This Mobile number already exits in our data,Enter a unique phone number\n");
            return 1;
        }
    }
    return 0;    
 }
 int validate_email(char * str2,int size,cont * ptr)
 {
    int i,start=0;
    char str[]={"."};
    if(isdigit(str2[0])||(str2[0]>='A' && str2[0]<='Z')|| str2[0]=='.' || str2[0]=='@'||str2[0]=='&'||str2[0]=='#' ||str2[0]=='$'|| str2[0]=='%' ||str2[0]=='^' ||str2[0]=='*'||str2[0]=='_')
    {
        printf("starting email should not be digit,capital characters and other special characters retry!!!\n");
        return 1;
    }
    if(str2[strlen(str2)-1]=='.' || str2[strlen(str2)-1]==' '||str2[strlen(str2)-1]=='@' ||str2[strlen(str2)-1]=='\t')
    {
        printf("ERROR !!! for last character there should not be any space or any other special characters\n");
        return 1;
    }
    int dot;
    for(i=0;str2[i]!='\0';i++)
    {
        if(str2[i]=='@')
        {
            start=i;
            if(str2[i+1]=='.')
            { 
                dot=i+1;
                printf("after '@' please enter a character not '.'\n");
                return 1;
            }
            break;
        }
    }
    for(int i=start+1;str2[i];i++)
    {
        if(strstr(str2+start,str)==NULL)
        {
            printf("after '@' enter atleast one '.'\n");
            return 1;
        }
    }
    for(int i=0;i<start;i++)
    {
        if(!isalnum(str2[i]))
        {
            printf("before '@' there should not be any special characters like (@,#,$,<,...)\n");
            return 1;
        }
    }
    for( i=0;i<size;i++)
    {
        if(!strcmp(ptr[i].email,str2))
        {
            printf("This Email id already exits in our data,retry!!!\n");
            return 1;
        }
    }
    return 0;
}

int delete_specific_contact(cont * ptr,char * str,int *size)
{   
    int found=0,start_ind,arr_ind=0,flag1=0;
    int arr1[arr_ind];
    for(int i=0;i<*size;i++)
    {   
        if(strcmp(ptr[i].name,str)==0|| strcmp(ptr[i].mobile,str)==0||strcmp(ptr[i].email,str)==0)
        {
            printf("%d \t %s \t\t  %s \t\t%s\n",i,ptr[i].name,ptr[i].mobile,ptr[i].email);
            arr1[arr_ind++]=i;
            found=1;
        }
    }
       if(found!=0)
       {
        printf("your existing contacts matches the above data ,select the index to delete the contact\n");
    check:scanf("%d",&start_ind);
    for(int ind=0;ind<arr_ind;ind++)
    {
        if(arr1[ind]==start_ind)
        {
            flag1=1;
            break;
        }
    }
    if(flag1==0)
    {
      printf("Enter correct index!!\n");
      goto check;
    }
    if(start_ind<0 || start_ind>*size)
    {
        printf("DELETION FAILED !!! Enter a correct index to delete the contact\n");
        goto check;
    }
       }
    if(found!=0)
     {
            for(int j=start_ind;j<*size-1;j++)
            {
                 ptr[j]=ptr[j+1];
            }
            (*size)--;
            printf("Contact record deleted successfully!!!\n");
    }
    if(found==0)
    {
        printf("please enter the correct contact Name or Email or Mobile\n");
        return 1 ;
    }
    return 0;
}


