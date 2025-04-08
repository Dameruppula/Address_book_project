#include<stdio.h>
#include "file.h"
#include<string.h>
//functions to save the data in to a file and load from a file
void save_contact(cont *ptr, int *size) {
    FILE *fptr = fopen("contacts.csv", "w");//open the file in read mode
    if (fptr == NULL) {
        printf("Error: Unable to save contacts.\n");
        return;
    }
    fprintf(fptr, "#%d\n", *size);  // printing the contact count in the file
    for (int i = 0; i < *size; i++) {
        fprintf(fptr, "%s,%s,%s\n",ptr[i].name,ptr[i].mobile,ptr[i].email);
    }
    fclose(fptr);
    printf("Contacts saved successfully!\n");
}
void load_contact(cont *ptr, int *size) {
    FILE *fptr = fopen("contacts.csv", "r");//open the file in read mode for loading the contacts
    if (fptr == NULL) {
        printf("No previous contacts found. Start fresh.\n");
        return;
    }
    fscanf(fptr, "#%d\n", size);  // Read the contact count form a file
    for (int i = 0; i < *size; i++) {
        fscanf(fptr, "%[^,],%[^,],%[^\n]\n",ptr[i].name,ptr[i].mobile,ptr[i].email);
    }
    fclose(fptr);
    printf("Contacts loaded successfully! Total contacts: %d\n", *size);
}