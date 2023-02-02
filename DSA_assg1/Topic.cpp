#include "Topic.h"

Topic::Topic() {}

Topic::Topic(string name, string m) {
	username = name;
	message = m;
}

void Topic::setUsername(string n) { username = n; }

string Topic::getUsername() { return username; }

void Topic::setMessage(string m) { message = m; }

string Topic::getMessage() { return message; }
