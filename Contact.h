#ifndef CONTACT_H
#define CONTACT_H

#include <string>

using namespace std;

class Contact
{
	public:
		Contact(string name, string phone, string address, string email);
		void setPhone(const string& phone);
		void setAddress(const string& address);
		void setEmail(const string& email);
		string getName() const;
		string getPhone() const;
		string getAddress() const;
		string getEmail() const;

	private:
		string name;
		string phone;
		string address;
		string email;
};

#endif
