#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include "hashTable.h"
#include "BinaryTree.h"

struct UserInfo {
	std::string pass;
	int admin;
};

struct PersonInfo {
	std::string Position;
	int Room;
	std::string Mobile;
	std::string Phone;
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
		std::system("pause");
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

int getControl(std::string name, bool admin) {
	std::cout << "Username: " << name << std::endl << std::endl;
	std::cout << "Enter a number to do the corresponding command: " << std::endl;

	int command = -1;
	if (admin) {
		std::cout << "1 - Reload Directory" << std::endl;
		std::cout << "2 - Save Directory" << std::endl;
		std::cout << "3 - Add Person" << std::endl;
		std::cout << "4 - Change Person Info" << std::endl;
		std::cout << "5 - Delete Person" << std::endl;
		std::cout << "6 - List People" << std::endl;
		std::cout << "7 - View Person by Name" << std::endl << std::endl;
		std::cout << "0 - Exit Program" << std::endl << std::endl;

		std::cout << "Your Input: ";
		std::cin >> command;

		while (command < 0 || command > 7) {
			std::cout << "Invalid input. Try again: ";
			std::cin >> command;
		}
	}
	else {
		std::cout << "7 - View Person by Name" << std::endl << std::endl;
		std::cout << "0 - Exit Program" << std::endl;

		while (command != 0 && command != 7) {
			std::cout << "Invalid input. Try again: ";
			std::cin >> command;
		}
		
	}

	return command;
}

void LoadDirectory(FILE *input, binaryTree<std::string, PersonInfo> &tree) {
	input = fopen("directory.txt", "r");

	if (!input) {
		std::cout << "The userbase failed to load. Quitting." << std::endl;
		std::system("pause");
		return;
	}

	char buffer[1024];
	char *name;
	PersonInfo pi;
	while (feof(input) == 0) {
		fscanf(input, "%[^\n]\n", buffer);
		name = strtok(buffer, ",");
		pi.Position = strtok(NULL, ",");
		pi.Room = std::stoi(strtok(NULL, ","));
		pi.Mobile = strtok(NULL, ",");
		pi.Phone = strtok(NULL, ",");

		tree.insert(name, pi);
	}
}

void SearchUser(binaryTree<std::string, PersonInfo> &tree) {
	std::string searchStr;
	std::cout << "Search for user: ";
	std::getline(std::cin, searchStr);
	std::getline(std::cin, searchStr);
	std::cout << tree.search(searchStr) << std::endl;
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

	admin = (bool)userInfo.admin;

	FILE *input = NULL;
	binaryTree<std::string, PersonInfo> tree;

	int control;
	while ((control = getControl(name, admin)) != 0) {
		switch (control) {
		case 1:
			LoadDirectory(input, tree);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			SearchUser(tree);
			break;
		}

		/*
		std::cout << "1 - Reload Directory" << std::endl;
		std::cout << "2 - Save Directory" << std::endl;
		std::cout << "3 - Add Person" << std::endl;
		std::cout << "4 - Change Person Info" << std::endl;
		std::cout << "5 - Delete Person" << std::endl;
		std::cout << "6 - List People" << std::endl;
		std::cout << "7 - View Person by Name" << std::endl << std::endl;
		*/

		std::system("pause");
		std::system("cls");
	}


	std::cout << "Shutting Down..." << std::endl;
	return true;
}