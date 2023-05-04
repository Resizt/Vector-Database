// Vector Database.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <vector>
#include <thread>
#include <unordered_map>

using namespace std;

void menu() {
	system("cls");
	cout << "Account Database" << endl;
	cout << "--------------------" << endl;
	cout << "1. New Entry\n2. Check User\n3. Check Database\n4. Exit\n";
}

void nEntry() {

}

auto Getname() {
	// User Input their name
	string name;
	cout << "Enter Only your first name" << endl;
	cin >> name;
	return name;
}

auto GetPin() {
	// User Input their Pin
	cout << "Enter your Pin" << endl;
	int entry;
	cin >> entry;
	return entry;
}

auto AutoGen(){
	// Auto generate the ID
	int random = 0;
	srand(time(NULL));
	return (int)rand();
}

int main()
{
	int entry = 0, pending, find;
	string name;
	vector<pair<int, pair <string, int>>> Account;
	menu();

	while(entry != 4) {
	cin >> entry;
		switch (entry)
		{
		case 1:
		{
			auto name = Getname();
			auto ID = AutoGen();
			auto Pin = GetPin();
			Account.push_back(make_pair(ID, make_pair(name, Pin)));
			cout << "Your New ID is; " << ID << endl;
			cin >> pending;
		}
		break;
		case 2:
		{
			string test;
			int nf = 0;
			cout << "Please Enter Your ID;";
			cin >> find;

			for (int lookfor = 0; lookfor < Account.size(); lookfor++) {
				if (find == Account[lookfor].first) {
					find = lookfor;
				}
				else if (find != Account[lookfor].first && lookfor == 1 - Account.size() && nf == lookfor){
					nf++;
					cout << "Account not found" << endl;
					cout << "Please reenter ID; "; 
					cin >> find;
				}
			}

			cout << "--------------------" << endl;
			cout << "Account found" << endl;
			cout << Account[find].first << " | " << Account[find].second.first << " | " << Account[find].second.second << endl;
			cout << "Press Enter to continue" << endl;
			cin >> test;
			cin.get();
		}
		break;
		case 3:
		{
			cout << "User in the data base" << endl;
			cout << "--------------" << endl;
			for (int i = 0; i < Account.size(); i++) {
				cout << Account[i].first << " | " << Account[i].second.first << " | " << Account[i].second.second << endl;
			}
			cout << "Press Enter to continue" << endl;
			cin.get();
		}
		break;
		case 4:
		return 0;
		break;
		}
		menu();
	}
}
