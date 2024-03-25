#include "ContactBook.h"


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

ContactBook::ContactBook(string filename)
{
	loadContacts();
}

void ContactBook::addContact(const Contact& contact)
{
	contacts.push_back(contact);
}

void ContactBook::displayContacts() const
{
	if (contacts.empty()) {
		cout << endl << "Contact Book is empty." << endl;
		return;
	}

	cout << "\nContacts:" << endl;
	for (const auto& contact : contacts) {
		cout << setw(10) << "Name:" << setw(20) << "Phone:" << setw(30) 
			<< "Address:" << setw(40) << "Email:" << endl;
		cout << setw(10) << contact.getName() << setw(20) << contact.getPhone()
			<< setw(30) << contact.getAddress() << setw(40) << contact.getEmail() << endl;
	}
}


void ContactBook::saveContacts() const
{
	ofstream file("contacts.txt");

	if (!file)
	{
		cout << "\tError! Unable to open file." << endl;
		return;
	}

	for (const auto& contact : contacts) {
		file << contact.getName() << "," << contact.getPhone()
			<< "," << contact.getAddress() << "," << contact.getEmail() << endl;
	}

	file.close();
	
}

void ContactBook::editContact(const string& name, const string& newPhone,
	const string& newAddress, const string& newEmail)
{
	for (auto& contact : contacts)
	{
		if (contact.getName() == name)
		{
			contact.setPhone(newPhone);
			contact.setAddress(newAddress);
			contact.setEmail(newEmail);
			cout << endl;
			cout << "\tThe contact has been edited." << endl;
		}
	}
}

void ContactBook::deleteContacts(const string& name)
{
	for (auto item = contacts.begin(); item != contacts.end(); item++) {
		if (item -> getName() == name) {
			contacts.erase(item);
			saveContacts();
			return;
		}
	}
}

void ContactBook::loadContacts() {
	ifstream file("contacts.txt");
	string line;

	if (!file) {
		cout << "\tError! Unable to open file." << endl;
		return;
	}

	while (getline(file, line)) {
		size_t pos = line.find(',');
		if (pos != string::npos) {
			string name = line.substr(0, pos);
			string phone = line.substr(pos + 1);
			string address = line.substr(pos + 5);
			string email = line.substr(pos + 1);
			contacts.emplace_back(name, phone, address, email);
		}
	}

	file.close();
}
