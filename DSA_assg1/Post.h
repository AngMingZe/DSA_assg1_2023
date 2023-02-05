#pragma once
#include <string>
using namespace std;
struct Post
{
	string creator;
	string topicName;
	string message;
	bool pinned = false;
};
