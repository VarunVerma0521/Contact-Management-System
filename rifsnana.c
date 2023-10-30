#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define the structure for a contact
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

// Function to add a contact
void addContact(struct Contact* contacts, int* contactCount) {
    if (*contactCount >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    struct Contact newContact;
    printf("Enter contact name: ");
    scanf(" %49[^\n]", newContact.name);
    printf("Enter phone number: ");
    scanf(" %14s", newContact.phone);
    printf("Enter email address: ");
    scanf(" %49s", newContact.email);

    contacts[(*contactCount)++] = newContact;
    printf("Contact added successfully.\n");
}

// Function to display all contacts
void displayContacts(struct Contact* contacts, int contactCount) {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("\n");
    }
}

// Function to save contacts to a file
void saveContacts(struct Contact* contacts, int contactCount) {
    FILE* file = fopen("contacts.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        fprintf(file, "%s;%s;%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(file);
    printf("Contacts saved to file.\n");
}

// Function to load contacts from a file
void loadContacts(struct Contact* contacts, int* contactCount) {
    FILE* file = fopen("contacts.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    while ((*contactCount) < MAX_CONTACTS && fscanf(file, "%49[^;];%14[^;];%49[^\n]\n",
        contacts[*contactCount].name, contacts[*contactCount].phone, contacts[*contactCount].email) == 3) {
        (*contactCount)++;
    }

    fclose(file);
    printf("Contacts loaded from file.\n");
}

// Function to search for a contact by name, email or phone
void searchContact(struct Contact* contacts, int contactCount) {
    if (contactCount == 0) {
        printf("No contacts available.\n");
        return;
    }

    char query[50];
    int found = 0;

    printf("Enter contact name, email or phone to search: ");
    scanf(" %49[^\n]", query);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, query) == 0 || strcmp(contacts[i].email, query) == 0 || strcmp(contacts[i].phone, query) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            found++;
            break;
        }
    }

    if (!found) {
        printf("No contact with that name, email or phone.\n");
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    // Load contacts from a file at the beginning
    loadContacts(contacts, &contactCount);

    while (1) {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Save Contacts to File\n");
        printf("4. Search Contact by Name, Email or Phone\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                displayContacts(contacts, contactCount);
                break;
            case 3:
                saveContacts(contacts, contactCount);
                break;
            case 4:
                searchContact(contacts, contactCount);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}