#include<iostream>
#include"Web browser.h"
using namespace std;
int menu() {
	int operation = -1;
	while (operation < 0 || operation > 3) {
		cout << "\n0: Exit";
		cout << "\n1: Search";
		cout << "\n2: Redo";
		cout << "\n3: Undo\n ----> ";
		cin >> operation;
	}
	return operation;
}
int main() {
	Browser bro;
	int opetion = -1;
	while (opetion) {
		opetion = menu();
		if (opetion == 1) {
			bro.search();
		}
		else if (opetion == 2) {
			bro.undo();
		}
		else if (opetion == 3) {
			bro.redo();
		}
	}


	return 0;
}