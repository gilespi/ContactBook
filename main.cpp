#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Contact.h"
#include "ContactBook.h"

using namespace std;

int main()
{
    ContactBook contactBook("contacts.txt");

    while (true) {
        
        cout << endl << "\nMain Menu:" << endl << endl;
        
        cout << "1 - Enter contact" << endl;
        cout << "2 - Display contact" << endl;
        cout << "3 - Save contact" << endl;
        cout << "4 - Edit contact" << endl;
        cout << "5 - Delete contact" << endl;
        cout << "6 - Exit program" << endl;
      
        cout << endl << "Choice: " << endl;

        int choice;
         cin >> choice;

            switch (choice) {
            case 1: {
                string name, phone, address, email;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Phone number: ";
                cin >> phone;
                cout << "Enter Address: ";
                cin >> address;
                cout << "Enter Email: ";
                cin >> email;
                contactBook.addContact(Contact(name, phone, address, email));
                break;
            }
            case 2:
                contactBook.displayContacts();
                break;
            case 3:
                contactBook.saveContacts();
                cout << "\tThe contact was successfully saved." << endl;
                break;
            case 4: {
                string name, newPhone, newAddress, newEmail;
                cout << "Enter the contact you want to edit: " << endl;
                cin >> name;
                cout << "Enter new Phone number: " << endl;
                cin >> newPhone;
                cout << "Enter new Address: " << endl;
                cin >> newAddress;
                cout << "Enter new Email: " << endl;
                cin >> newEmail;
                contactBook.editContact(name, newPhone, newAddress, newEmail);
                break;
            }
            case 5: {
                string name;
                cout << "Enter the contact you want to delete: " << endl;
                cin >> name;
                contactBook.deleteContacts(name);
                cout << "\tContact " << name << " is succesfully deleted." << endl;
                break;
            }
            case 6:
                cout << "\tEnd of program." << endl;
                return 0;
            default:
                cout << "\tWrong choice. Try Again." << endl;
            }
        
    }

	return 0;
}