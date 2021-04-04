#include<iostream>
using namespace std;

template<typename T>
class linked_list {
public:
	template<typename T>
	class node {
	public:
		node<T>*prev;
		T data;
		node<T>*next;
	
		node() {
			prev = NULL;
			data = 0;
			next = NULL;
		}
	};
	node<int> *head;
public:
	linked_list() {
		head = NULL;
	}
	void insertAtstart(T d) {
		node<T> *temp = new node<T>;
		if (head == NULL) {
			head = temp;
			temp->data = d;
			temp->next = NULL;
		}
		else {
			temp->data = d;
			temp->next = head;
			head = temp;
			temp->next->prev = temp;
		}
	}
	void insertAtEnd(T d) {
		node<T> * temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		node<T> *newNode = new node<T>;
		newNode->data = d;
		newNode->prev = temp;
		temp->next = newNode;
	}
	void InsertAtPlace(T d,int i) {
		node<T> *temp1 = new node<T>;
		node<T> *temp2 = new node<T>;
		temp1 = head;
		while (temp1->data != i) {
			temp2 = temp1;
			temp1 = temp1->next;
		}
		node<T> * newNode = new node<T>;
		newNode->data = d;
		newNode->next = temp1;
		temp1->prev = newNode;
		temp2->next = newNode;
		newNode->prev = temp2;
	}
	void deleteAtStart() {
		node<T> *temp = new node<T>;
		temp = head->next;
		temp->prev = NULL;
		delete head;
		head = temp;
	}
	void deleteAtEnd() {
		node<T> *temp = new node<T>;
		node<T> *temp1 = new node<T>;
		temp = head;
		while (temp->next != NULL) {
			temp1 = temp;
			temp = temp->next;
		}
		temp->prev = NULL;
		temp1->next = NULL;
		delete temp;
	}
	void deleteAfterPlace(T i) {
		node<T>*temp = new node<T>;
		node<T>*temp1 = new node<T>;
		temp = head;
		while (temp1->data != i) {
			temp1 = temp;
			temp = temp->next;
		}
		temp1->next = temp->next;
		if (temp->next != NULL) {
			temp->next->prev = temp1;
		}
		delete temp;
	}
	void print() const {
		node<T> *temp = head;
		while (temp != NULL) {
			cout << temp->data <<" >> ";;
			temp = temp->next;
		}
	}
	void removeDuplicates() {
		node<T> *temp1 = new node<T>;
		node<T> *temp2 = new node<T>;
		node<T> *duplicate = new node<T>;
		temp1 = head;
		while (temp1 != NULL && temp1->next != NULL) {
			temp2 = temp1;
			while (temp2->next != NULL) {
				if (temp1->data == temp2->next->data) {
					duplicate = temp2->next;
					temp2->next = temp2->next->next;
					temp2->prev = temp2;
					delete(duplicate);
				}
				else {
					temp2 = temp2->next;
				}
			}
			temp1 = temp1->next;
		}
	}

	void reverse() {
		node<T> *tempHead = new node<T>;
		tempHead = head;
		head = NULL;
		while (tempHead != NULL) {
			node<T> *temp = new node<T>;
			if (head == NULL) {
				head = temp;
				temp->data = tempHead->data;
				temp->next = NULL;
			}
			else {
				temp->data = tempHead->data;
				temp->next = head;
				head = temp;
				temp->next->prev = temp;
			}

			tempHead = tempHead->next;
		}
	}
	~linked_list() {
		delete head;
		delete prev;
		delete next;
		data = 0;
	}
};

int main() {
	linked_list<int> *firstNode;
	firstNode = new linked_list<int>;
	firstNode->insertAtstart(7);
	firstNode->insertAtstart(9);
	firstNode->insertAtEnd(1);
	firstNode->insertAtEnd(2);
	firstNode->insertAtEnd(10);
	firstNode->InsertAtPlace(3,2);
	firstNode->print();
	cout << "\n\n\n";
	firstNode->deleteAtStart();
	firstNode->deleteAtStart();
	firstNode->deleteAtEnd();
	firstNode->deleteAfterPlace(3);
	firstNode->print();
	cout << "\n\n\n";
	firstNode->insertAtEnd(3);
	firstNode->removeDuplicates();
	firstNode->print();
	cout << "\n\n\n";

	firstNode->reverse();
	firstNode->print();
	cout << "\n\n\n";

	return 0;
}