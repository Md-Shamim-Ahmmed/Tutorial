//Bismillahir Rahmanir Rahim//
#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;
};
node *head = nullptr, *tail = nullptr;

node* getHead() {
	return head;
}

void insertNode(int data) {
	node* newNode = new node;
	newNode -> data = data;
	newNode -> next = nullptr;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	} else {
		tail -> next = newNode;
		tail = tail -> next;
	}
}

void insertAtStart(int data) {
	node* newNode = new node;
	newNode -> data = data;
	newNode -> next = head;
	head = newNode;
}

int Size(node* temp) {
	int cnt = 0;
	while(temp != nullptr) {
		cnt++;
		temp = temp -> next;
	}
	return cnt;
}

void insertAtPosition(int pos, int data) {
	node* temp = new node;
	node* previousNode = new node;
	node* currentNode = head;
	for (int i = 0; i < pos; i++) {
		previousNode = currentNode;
		currentNode = currentNode -> next;
	}
	temp -> data = data;
	previousNode -> next = temp;
	temp -> next = currentNode;
}

void deleteAtFirst() {
	node *temp = head;
    head = head -> next;
    delete temp;
}

void deleteAtLast() {
    node *currentNode = head;
    node *previousNode = new node;
    while (currentNode -> next != NULL) {
      previousNode = currentNode;
      currentNode = currentNode -> next;	
    }
    tail = previousNode;
    previousNode -> next = NULL;
    delete currentNode;
}

void deleteAtPosition(int pos) {
	if (pos >= Size(head) || pos < 1) {
		return;
	}
    node *currentNode = head;
    node *previousNode = new node;
    for(int i = 1; i < pos; i++) {
      previousNode = currentNode;
      currentNode = currentNode -> next;
    }
    previousNode -> next = currentNode -> next;
}

void display(node* temp) {
	while (temp != nullptr) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}

int main () {
    int size;
	cout << "Enter size : ";
    cin >> size;
    while (size--) {
		int data;
		cout << "Enter element : ";
		cin >> data;
		insertNode(data);
	}
	cout << "Print the list : ";
	display(head);
	cout << '\n' << '\n';
	int data;
	cout << "Enter data for insert : ";
	cin >> data;
	insertAtStart(data);
	cout << "After insert data (" << data << ") at first the list is : ";
	display(head);
	cout << '\n' << '\n';
	cout << "Enter position and data : ";
	int pos;
	cin >> pos >> data;
	insertAtPosition(pos, data);
	cout << "After insert data (" << data << ") at position (" << pos << ") the list is : ";
	display(head);
	cout << '\n' << '\n';
	deleteAtFirst();
	cout << "After delete first element the list is : ";
	display(head);
	cout << '\n' << '\n';
	deleteAtLast();
	cout << "After delete last element the list is : ";
	display(head);
	cout << '\n' << '\n';
	cout << "Enter position for delete a node : ";
	cin >> pos;
	deleteAtPosition(pos);
	cout << "After delete node at position (" << pos << ") the list is : ";
	display(head);
	cout << '\n' << '\n';
	cout << "Size of the list is : " << Size(head) << '\n';
    return 0;
}
