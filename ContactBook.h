#ifndef CONTACT_BOOK_H
#define CONTACT_BOOK_H

#include <iostream>
#include <vector>
#include <string>

#include "Contact.h"

using namespace std;

class ContactBook
{


	public:
		ContactBook(string filename);
		void addContact(const Contact& contact);
		void displayContacts() const;
		void saveContacts() const;
		void editContact(const string& name, const string& newPhone, 
			 const string& newAddress, const string& newEmail);
		void deleteContacts(const string& name);

	private:
		vector<Contact> contacts;
		string filename;
		void loadContacts();

		
};

#endif
