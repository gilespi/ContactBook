#include "Contact.h"

#include <string>

using namespace std;

Contact::Contact(string name, string phone, string address, string email)
{
	this->name = name;
	this->phone = phone;
	this->address = address;
	this->email = email;
}


void Contact::setPhone(const string& phone)
{
	this->phone = phone;
}

void Contact::setAddress(const string& address)
{
	this->address = address;
}

void Contact::setEmail(const string& email)
{
	this->email = email;
}

string Contact::getName() const
{
	return name;
}

string Contact::getPhone() const
{
	return phone;
}

string Contact::getAddress() const
{
	return address;
}

string Contact::getEmail() const
{
	return email;
}