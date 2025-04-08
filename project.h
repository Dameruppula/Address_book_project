#ifndef PROJECT_H
#define PROJECT_H

#define MAX_CONTACTS 100
//All function declarations
typedef struct 
{
    char name[100];
    char mobile[20];
    char email[50];
}cont;
void add_contact(cont *,int* );
int validate_name(char*,int,cont *);
int validate_mob(char *,int,cont*);
int validate_email(char*,int ,cont*);
void print_contacts(cont*,int *);
int print_specific_contact(cont*,char*,int* );
int edit_contact(cont*,char *,int*);
int delete_specific_contact(cont*,char*,int*);
void save_contact(cont*,int*);
void load_contact(cont *,int*);

#endif