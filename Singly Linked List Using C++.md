# singly-linked list using C++
##### What is singly-linked list ???
A **singly linked list** is a type of linked list that is unidirectional, that is, it can be traversed in only one direction from head to the last node (tail).

The elements of a linked list are called the **nodes**. A **node** has two fields **data part** and **next part**. The data field contains the data being stored in that specific node. It cannot just be a single variable. There may be many variables presenting the data section of a node. The next field contains the address of the next node. So this is the place where the link between nodes is established.
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/Linked_List_Node.png">
</p>

No matter how many nodes are present in the linked list, the very first node is called **head** and
the last node is called the **tail**. If there is just one node created then it is called both **head** and **tail**.
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/list2.png">
</p>

## Implementation of Linked List in C++
As linked list consists of nodes, we need to declare a structure which defines a single node. 
Our structure should have at least one variable for data section and a pointer for the next node.

In C++, our code would look like this:
  ```cpp
  struct node {
	int data;
	node* next;
};
```
## Creation of Linked List Using C++
  ```cpp
  node *head = nullptr, *tail = nullptr;
  ```
  
  Now, we will write a function for the node creation. The process of creating node is very simple. We need a pointer of a node type (which we defined) and we will insert the value in its data field. The next field of node would be declared as NULL as it would be the last node of linked list.

Now, the function will have a very special case that we want to know what would happen if the linked list is still empty? We will have to check it. Do you remember that the head points to the first node? It means if the head is equal to NULL then we can conclude that the linked list is empty.

I have also told you before that if there is just one node (which we are going to create) in linked lists, then it is called both head and tail.

And if a linked list is created already, then we would insert this node at the end of the linked list. We know that the last node is called a tail. So we are going to create this newly created node next to a tail node.

The creation of a new node at the end of linked list has 2 steps:

    1.Linking the newly created node with tail node. Means passing the address of a new node to the next pointer of a tail node.
    2.The tail pointer should always point to the last node. So we will make our tail pointer equal to a new node.
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/list3.png">
</p>

The C++ code for the creation of new a node would like this:
```cpp
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
```

## Displaying Linked List Using C++

Now we have a working linked list which allows creating nodes. If we want to see that what is placed in our linked list then we will have to make a display function. The logic behind this function is that we make a temporary node and pass the address of the head node to it. Now we want to print all the nodes on the screen. So we need a loop which runs as many times as nodes exist. Every node contains the address of the next node so the temporary node walks through the whole linked list. If the temporary node becomes equal to NULL then the loop would be terminated.
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/list4.png">
</p>

```cpp
void display(node* temp) {
	while (temp != nullptr) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
}
```

The basic framework of a singly-linked list is ready. Now it is the time to perform some other operations on the list. Basically, two operations are performed on linked lists:

	1.Insertion
   	2.Deletion

## Insertion

Inserting a new node in the linked list is called insertion.

A new node is created and inserted in the linked list.

There are three cases considered while inserting a node:

	1.Insertion at the start
	2.Insertion at the end
	3.Insertion at a particular position

## Insertion at the Start

Insertion of a new node is quite simple.
It is just a 2-step algorithm which is performed to insert a node at the start of a singly linked list.

	1.New node should be connected to the first node, which means the head. This can be achieved by putting the address of the head in the next field of the new node.
	2.New node should be considered as a head. It can be achieved by declaring head equals to a new node.

The diagrammatic demonstration of this process is given below:
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/list5.png">
</p>
The code for this process is:

```cpp
void insertAtStart(int data) {
	node* newNode = new node;
	newNode -> data = data;
	newNode -> next = head;
	head = newNode;
}
```

## Insertion at the End

The insertion of a node at the end of a linked list is the same as we have done in node creation function. If you noticed then, we inserted the newly created node at the end of the linked list. So this process is the same.

The diagrammatic demonstration of this process is given below:
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/list5.png">
</p>

```cpp
void insertAtEnd(int data) {
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
```

## Insertion at Particular Position

The insertion of a new node at a particular position is a bit difficult to understand. In this case, we don’t disturb the head and tail nodes. Rather, a new node is inserted between two consecutive nodes. So, these two nodes should be accessible by our code. We call one node as current and the other as previous, and the new node is placed between them. 
The diagrammatic demonstration of this process is given below:
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/list5.png">
</p>
Now the new node can be inserted between the previous and current node by just performing two steps:

   1.Pass the address of the new node in the next field of the previous node.
   2.Pass the address of the current node in the next field of the new node.

We will access these nodes by asking the user at what position he wants to insert the new node. Now, we will start a loop to reach those specific nodes. We initialized our current node by the head and move through the linked list. At the end, we would find two consecutive nodes.

C++ code for insertion of node would be as follows:
```cpp
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
```
##  Deletion:
So, you have become familiar with linked list creation. Now, it’s time to do some manipulation on the linked list created. Linked lists provide us the great feature of deleting a node. The process of deletion is also easy to implement. The basic structure is to declare a temporary pointer which points the node to be deleted. Then a little bit of working on links of nodes.
There are also three cases in which a node can be deleted:

	1.Deletion at the start
	2.Deletion at the end
	3.Deletion at a particular position
   
## Deletion at the Start

In this case, the first node of the linked list is deleted. I know, you remember that the first node is called the head. So, we are going to delete the head node.
The process of deletion includes:

	1.Declare a temp pointer and pass the address of the first node, i.e. head to this pointer.
	2.Declare the second node of the list as head as it will be the first node of linked list after deletion.
	3.Delete the temp node.
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/list7.png">
</p>
The C++ code for this process is given below:

```cpp
void deleteAtFirst() {
	node *temp = head;
    head = head -> next;
    delete temp;
}
```

## Deletion at the End

Deletion of the last node is a bit difficult to understand than the first node. In the case of the first node, you just need access to the head and you can delete it. But in the case of the last node, you also need access to the second to the last node of the linked list as you will delete the last node and make the previous node as the tail of linked list.
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/list8.png">
</p>
Our algorithm should be capable of finding a node that comes before the last node. This can be achieved by traversing the linked list. We would make two temporary pointers and let them move through the whole linked list. At the end, the previous node will point to the second to the last node and the current node will point to the last node, i.e. node to be deleted.
We would delete this node and make the previous node as the tail.

```cpp
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
```

## Deletion at a Particular Position

In linked list, we can delete a specific node. The process of deletion is simple. Here we don’t use the head and tail nodes. We ask the user to input the position of the node to be deleted. After that, we just move two temporary pointers through the linked list until we reach our specific node. Now, we delete our current node and pass the address of the node after it to the previous pointer. This way, the current node is removed from the linked list and the link is established between its previous and next node.
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/list9.png">
</p>
The deletion can be done in C++ by using code given below:

```cpp
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
```

## Size of a Singly Linked List 

The size function give us the size of the Linked List.

The Size Function can be done in C++ by using code given below:
```cpp
int Size(node* temp) {
	int cnt = 0;
	while(temp != nullptr) {
		cnt++;
		temp = temp -> next;
	}
	return cnt;
}
```

## GetHead of a Linked List 

The getHead function all time return head node.
The GetHead Function can be done in C++ by using code given below:
```cpp
node* getHead() {
	return head;
}
```
## Main function of Linked List

We know that every function have a **main()** function.\
Without **main()** function the code could not be run.\
The sample of main funtion can be given below:
```cpp
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
```

## Full Singly Linked List using C++
[Code here](https://github.com/Shamim-Nik/Tutorial/blob/master/singly-linked%20list%20using%20C++.cpp)
The full code can be given below:
```cpp
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
```

## Output For This Code
The output for this code can be given below:
<p align="center">
  <img src="https://github.com/Shamim-Nik/Just-For-Me/blob/master/image/Screenshot%20from%202020-07-25%2020-07-22.png">
</p>

#### Happy Coding😊️😊️
