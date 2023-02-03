#include "Account.h"

Account::Account() {}

Account::Account(string name, string pw) {
	username = name;
	password = pw;
}

Account::~Account() { }

void Account::setUsername(string n) { username = n; }

string Account::getUsername() { return username; }

void Account::setpassword(string pw) { password = pw; }

string Account::getPassword() { return password; }
