#include <iostream>

using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
  Node* head;

 public:
  LinkedList() { head = NULL; }

  // Add node at begining
  void prependNode(int data){

	Node* newNode = new Node(data);

	if(head == NULL){
		head = newNode;
		return;
	}

	newNode->next = head;
	head =  newNode;

  }

  void appendNode(int data);             // Add node at end []
  void insertNode(int index, int data);  // Insert at given index []
  void findNode(int data);               // Find by value
  void getNode(int index);               // Get by index
  void deleteNode();                     // Delete last node
  void deleteNodeAt(int index);          // Delete at index
  void print();                          // Print all nodes [X]

  // ===== Extra common methods =====
  int length();                   // Return number of nodes
  bool isEmpty();                 // Check if list is empty
  void clear();                   // Delete all nodes
  void reverse();                 // Reverse the list
  void removeDuplicates();        // Remove duplicate values
  void sort();                    // Sort list in ascending order
  void merge(LinkedList& other);  // Merge with another list
  Node* middleNode();             // Get middle node
  Node* nthFromEnd(int n);        // Get nth node from end
  void swapNodes(int x, int y);   // Swap nodes by values
};

// we can write like this with scope resolution operator (::)
void LinkedList::print(){
	Node* temp = head;

	while(temp != NULL){
		cout << temp->data << " -> ";
		temp = temp -> next;
	}
	cout << endl;
}

// main function
int main() {
  LinkedList list;

  list.prependNode(10);
  list.prependNode(20);
  list.prependNode(30);
  list.prependNode(40);
  list.print();

  return 0;
}