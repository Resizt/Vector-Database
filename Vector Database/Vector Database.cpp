// Vector Database.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <vector>
#include <thread>
#include <iomanip>

using namespace std;

#define VB vector<pair<int, pair <string, int>>> Account;

vector<pair<int, pair <string, int>>> Account;


// New Entry Functions
auto Getname();
auto GetPin();
auto AutoGen();

// Menu Functions
void menu();
void NewEntry(vector<pair<int, pair <string, int>>>&);
void Search(vector<pair<int, pair <string, int>>>);
void DatabaseLoad(vector<pair<int, pair <string, int>>>);

int main(){
	int entry = 0;
	menu();
	while(entry != 4) {
	cin >> entry;
		if		(entry == 1) NewEntry(Account);
		else if (entry == 2) Search(Account);
		else if (entry == 3) DatabaseLoad(Account);
		else if (entry == 4) return 0;
	menu();
	}
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

auto AutoGen() {
	// Auto generate the ID
	int random = 0;
	srand(time(NULL));
	return (int)rand();
}

void menu() {
	//system("cls");
	cout << "Account Database" << endl;
	cout << "--------------------" << endl;
	cout << "1. New Entry\n2. Check User\n3. Check Database\n4. Exit\n";
}

void NewEntry(vector<pair<int, pair <string, int>>> &Account) {
	int pending;
	auto ID = AutoGen();
	auto name = Getname();
	auto Pin = GetPin();
	Account.push_back(make_pair(ID, make_pair(name, Pin)));
	cout << "Your New ID is; " << ID << endl;
	cin >> pending;
}

void Search(vector<pair<int, pair <string, int>>> Account) {
	string test;
	int nf = 0, find;
	cout << "Please Enter Your ID;";
	cin >> find;

	for (int lookfor = 0; lookfor < Account.size(); lookfor++) {
		if (find == Account[lookfor].first) {
			find = lookfor;
		}
		else if (find != Account[lookfor].first && lookfor == 1 - Account.size() && nf == lookfor) {
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

void DatabaseLoad(vector<pair<int, pair <string, int>>> Account) {
	int pending;
	cout << "User in the data base" << endl;
	cout << "--------------" << endl;
	
	for (int i = 0; i < Account.size(); i++)
		cout << Account[i].first << setw(11) << " | " << setw(11) << Account[i].second.first << setw(11) << " | " << setw(11) << Account[i].second.second << endl;

	cout << "Press Enter to continue" << endl;
	cin.get();
	cin >> pending;
}

