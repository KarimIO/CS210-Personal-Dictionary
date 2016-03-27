#include <iostream>
#include <string>
#include <fstream>
#include "hashTable.h"

struct UserInfo {
	std::string pass;
	int admin;
};

bool readUserbase(hashTable<std::string, UserInfo> &hash) {
	FILE *input;

/*#ifdef UseSecure
	if (fopen_s(&input, "userpass.txt", "r") != 0) {
		std::cout << "The userbase failed to load. Quitting." << std::endl;
		system("pause");
		return false;
	}
#else*/
	input = fopen("userpass.txt", "r");

	if (!input) {
		std::cout << "The userbase failed to load. Quitting." << std::endl;
		system("pause");
		return false;
	}
//#endif

	while (feof(input) == 0) {
		char user[256];
		char pass[256];
		int admin;

/*#ifdef UseSecure
		fscanf_s(input, "%s %s %i", user, pass, &admin);
#else*/
		// This requires a _CRT_SECURE_NO_WARNINGS preprocessor
		fscanf(input, "%s %s %i", user, pass, &admin);
//#endif
		UserInfo userInfo;
		userInfo.pass = pass;
		userInfo.admin = (admin != 0);

		hash.insert(std::string(user), userInfo);

	}

	if (input) {
		if (fclose(input) != 0) {
			printf("The file failed to close.\n");
		}
	}

	return true;
}

int main() {
	hashTable<std::string, UserInfo> hash(true, "", 64);
	if (!readUserbase(hash))
		return false; 

	std::string name, password, pass2;
	UserInfo userInfo;
	bool found = false;
	bool passCorrect = false;
	bool admin;

	while (!passCorrect) {
		std::cout << "Please insert your username: ";
		std::cin >> name;

		found = hash.get(name, userInfo);

		if (found) {
			std::cout << "Found User! Please insert your password: ";
			std::cin >> password;
			passCorrect = (userInfo.pass == password);

			if (passCorrect)
				std::cout << "Passwords Match" << std::endl;
			else
				std::cout << "Passwords Mismatch" << std::endl;
		}
		else
			std::cout << "No user found" << std::endl;
	}

	system("pause");
	system("cls");

	std::cout << "Username: " << name << std::endl;
	admin = userInfo.admin;
	std::cout << (admin ? "Admin" : "Regular") << std::endl;

	system("pause");
	return true;
}