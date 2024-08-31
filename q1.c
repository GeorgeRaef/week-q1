#include <stdio.h>
#include <string.h>

#define TOTAL_CONTACTS 100 // Corrected definition

struct Contact
{
    char name[100];
    char phoneNumber[20];
    char email[100];
};

// Corrected function parameter types and contactCount reference
void addContact(struct Contact phonebook[], int *contactCount, const char *name, const char *phoneNumber, const char *email)
{
    if (*contactCount < TOTAL_CONTACTS)
    {
        strcpy(phonebook[*contactCount].name, name);
        strcpy(phonebook[*contactCount].phoneNumber, phoneNumber);
        strcpy(phonebook[*contactCount].email, email);
        (*contactCount)++;
        printf("Contact added successfully!\n");
    }
    else
    {
        printf("Phonebook is full!\n");
    }
}

// Corrected function parameter types
void searchContact(struct Contact phonebook[], int contactCount, const char *name)
{
    int found = 0;
    for (int i = 0; i < contactCount; i++)
    {
        if (strcmp(phonebook[i].name, name) == 0)
        {
            printf("Contact found!\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone Number: %s\n", phonebook[i].phoneNumber);
            printf("Email: %s\n", phonebook[i].email);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Contact not found.\n");
    }
}

void displayContacts(struct Contact phonebook[], int contactCount)
{
    if (contactCount == 0)
    {
        printf("No contacts to display.\n");
    }
    else
    {
        for (int i = 0; i < contactCount; i++)
        {
            printf("Contact %d:\n", i + 1);
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone Number: %s\n", phonebook[i].phoneNumber);
            printf("Email: %s\n", phonebook[i].email);
            printf("------------------------\n");
        }
    }
}

int main()
{
    struct Contact phonebook[TOTAL_CONTACTS]; // Use TOTAL_CONTACTS
    int contactCount = 0;

    // Corrected call to addContact
    addContact(phonebook, &contactCount, "george", "123-456-7890", "george@gggg.com");

    // Corrected call to searchContact
    searchContact(phonebook, contactCount, "george");

    displayContacts(phonebook, contactCount);

    return 0;
}
