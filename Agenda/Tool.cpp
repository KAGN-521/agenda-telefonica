#include "Tool.h"

void print(string message) {
	cout << message;
}

int getInt() {
	int response;
	cin >> response;
	return response;
}

string getString() {
	cin.ignore();
	string response;
	getline(cin, response);
	return response;
}

void clear() {
	system("cls");
}

void pause() {
	system("pause");
}
