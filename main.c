// Data Structure: Define a structure for contacts with fields like name, phone number, email, etc.

// Operations: Add a contact
// View all contacts
// Search for a contact by name
// Delete a contact Edit a contact's information

// Storage: Implement a mechanism to store contacts persistently using file I/O to save contact information to a text file.

// User Interface: Create a text-based interface with menus and prompts for user interaction.

// Error Handling: Implement error handling for cases like trying to delete or edit a contact that doesn't exist.

// User Interface
#include <stdio.h>
void main()
{
  int action;
  printf("hello\nWelcome to Advance Contact Management System. ");
  printf("Here's Tthe list of action u can perform :-");
  printf("1. Add Contact\n2. View All Contact\n3. Search For a Contact\n4. Delete a Contact\n5. Edit contact \n6. Add To Your Contact List ");
  printf("Enter The S.no of Action You Want To Perform");
  scanf("%d",&action);
}
