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
  int size = 0;

 public:
  LinkedList() { head = NULL; }

  // Add node at begining
  void prependNode(int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
      head = newNode;
      size++;
      return;
    }

    newNode->next = head;
    head = newNode;
    size++;
  }

  // Add node at end
  void appendNode(int data) {
    Node* current = head;
    Node* newNode = new Node(data);

    while (current->next) {
      current = current->next;
    }

    current->next = newNode;
    size++;
  }

  // Insert at given position
  void insertNode(int position, int data) {
    Node* newNode = new Node(data);

    if (position < 1 || position > size) {
      cout << position
           << " is invalid position. enter valid position to insert " << data
           << endl;
      return;
    }

    if (position == 1) {
      prependNode(data);
      return;
    }

    Node* current = head;
    int count = 2;

    while (count < position) {
      current = current->next;
      count++;
    }
    newNode->next = current->next;
    current->next = newNode;
    size++;
  }

  // Delete last node
  void deleteNode() {
    if (!head) {
      cout << "list is empty" << endl;
      return;
    }

    Node* current = head;
    Node* prev = nullptr;
    while (current->next) {
      prev = current;
      current = current->next;
    }
    prev->next = nullptr;
    delete current;
  }

 private:
  void remove(Node* node) {
    if (node) {
      remove(node->next);
      delete node;
    }
  }

 public:
  // Delete all nodes
  void clear() {
    remove(head);
    head = nullptr;
    size = 0;
  }

  // Find by value
  void findNode(int data){
    if(!head){
      return;
    }
    if(head->data == data){
      cout << "data found at 0 th index" << endl;
      return;
    }
    Node* current = head->next;
    int index = 1;
    while(current){
      if(current->data==data){
        cout << "data found at " << index << "th index" << endl;
        return;
      }
      index++;
      current = current->next;
    }
    cout << data << "is not found" << endl;
  }

  void getNode(int index);  // Get by index

  void deleteNodeAt(int index);  // Delete at index
  void print();                  // Print all nodes [X]

  // ===== Extra common methods =====
  int length();                   // Return number of nodes
  bool isEmpty();                 // Check if list is empty
  void reverse();                 // Reverse the list
  void removeDuplicates();        // Remove duplicate values
  void sort();                    // Sort list in ascending order
  void merge(LinkedList& other);  // Merge with another list
  Node* middleNode();             // Get middle node
  Node* nthFromEnd(int n);        // Get nth node from end
  void swapNodes(int x, int y);   // Swap nodes by values
};

// we can write like this with scope resolution operator (::)
void LinkedList::print() {
  Node* temp = head;

  cout << "linked list items : " << endl;
  while (temp != NULL) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }
  cout << endl;
  cout << "size : " << size << endl;
}

// main function
int main() {
  LinkedList list;

  list.prependNode(10);
  list.prependNode(20);
  list.prependNode(30);
  list.prependNode(40);
  list.appendNode(100);
  list.insertNode(3, 510);
  list.print();
  list.deleteNode();
  list.print();
  // list.clear();
  list.print();
  list.findNode(100);

  return 0;
}