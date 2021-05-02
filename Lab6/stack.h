#include<iostream>
using namespace std;
template <class T>
class Node
{
public:
T data;
Node<T>* next;
};
template <class T>
class List {
public:
	Node<T>* head;
	Node<T>* tail;

	List(){
		head = nullptr;
		tail = nullptr;
	}
	void insertAtEnd(T value) {
		Node<T>* newNode = new Node<T>;
		newNode->data = value;
		newNode->next = nullptr;
		if (head == nullptr){
			head = tail = newNode;
		}
		else{
			tail->next = newNode;
		tail = tail->next;
		}
	}

	void RemoveAtEnd() {
		Node<T> * current = head;
		// Do nothing if list is already Empty 
		if (current != nullptr) {
		//One element
			if (head == tail) {
				head = tail = nullptr;
				delete current;
			}
			else {
			//Find second last element
				while (current->next != tail) {
					current = current->next;
				}
				tail = current;
				current = current->next;
				tail->next = nullptr;
				delete current;
			}
		}
	} 

	bool isEmpty() {
		return head == nullptr;
	}

	void print() {
			Node<T> *temp=head;
			while(temp!=nullptr){
				cout<<temp->data;
				temp=temp->next;
				cout<<"\n";
			}
		}
	~List() {
		while (!isEmpty()){
			RemoveAtEnd();
		}
	}
};
template <class T>
class Stack {

private:
//Data Member:
List<T>collection;
public:
//Required Functions:
void Push (T val){
	collection.insertAtEnd(val);
}
void Pop (){
 collection.RemoveAtEnd();
}

T Top() {
	return collection.tail->data;
}

bool isEmpty(){
	return collection.isEmpty();
}
bool isFull(){ ////Think about this (This will always return false)
	return false;
} 
Stack() {} //default constructor: This will be empty
void print()        //Made to test the code
{
		collection.print();
}

};






