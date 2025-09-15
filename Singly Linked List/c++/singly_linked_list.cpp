#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList
{
	Node *head;

public:
	LinkedList()
	{
		head = NULL;
	}

	void prependNode(int data)
	{
		Node *newNode = new Node(data);

		if (head == NULL)
		{
			head = newNode;
			return;
		}

		newNode->next = this->head;
		this->head = newNode;
	}

	void appendNode(int data)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		Node *temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}

	void insertNode(int index, int data) {}
	void findNode(int data) {}
	void getNode(int index) {}
	void deleteNode() {}
	void deleteNodeAt(int index) {}

	void print()
	{
		Node *temp = head;

		if (head == NULL)
		{
			cout << "List is Empty" << endl;
			return;
		}

		while (temp != NULL)
		{
			cout << temp->data << " -> ";
			temp = temp->next;
		}
	}
};

int main()
{
	LinkedList list;
	list.prependNode(10);
	list.prependNode(20);
	list.prependNode(30);
	list.print();

	return 0;
}