#ifndef stack_H
#define stack_H

#include<iostream>
#include<fstream>
#include"stack.h"

using namespace std;

class Browser {
private:
	Stack<string> history;
	Stack<string> Redo;
	Stack<string> Undo;
public:
	Browser(){
		loadData();
	}
	
	void printFile(string* file) {
		system("CLS");
		ifstream fin;
		fin.open(*file);
		if (fin.is_open()) {
			while (!fin.eof()) {
				char line[1000];
				fin.getline(line, 1000);
				cout << line << endl;
			}
			fin.close();
		}
		else {
			cout << "\nInvalid URL";
		}
		
	}

	void search() {
		string *file = new string;
		cout << "\nEnter URL that you wanna open : ";
		cin >> *file;
		printFile(file);
		history.Push(*file);
		
	}

	void undo() { // ctrl + z
		if (!history.isEmpty()) {
			string* file = new string;
			*file = history.Top();
			printFile(file);
			Undo.Push(*file);
			history.Pop();
		}
		else {
			cout << "\nHistory Empty :(";
		}
	}

	void redo() { // ctrl + y
		if (!Undo.isEmpty()) {
			string* file = new string;
			*file = Undo.Top();
			printFile(file);
			Redo.Push(*file);
			history.Push(*file);
			Undo.Pop();
		}
	}

	void loadData() {
		ifstream fin;
		fin.open("save.txt");
		if (fin.is_open()) {
			while (!fin.eof()) {
				char file[1000];
				fin.getline(file, 1000);
				string *temp = new string;
				*temp = "";
				
				for (int i = 0; file[i] != '\0'; i++) {
					*temp += file[i];
				}
				if (*temp != "") {
					history.Push(*temp);
				}
			}
			fin.close();
		}
		else {
			cout << "\nRecord not present\n";
		}
	}
	void saveData() {
		ofstream fout;
		fout.open("save.txt");
		if (fout.is_open()) {
			while (!history.isEmpty()) {
				fout<<history.Top() << endl;
				history.Pop();
			}
			fout.close();
		}
		else {
			cout << "\nhistory not save\n";
		}
	}
	~Browser() {
		saveData();
	}
};

#endif