#include <iostream>
#include<vector>
using namespace std;

struct Node
{
	int value;
	Node* back;
	Node* next;
	int occ;
};
class LinkedList
{

private:
	Node *first, *last;

public:
	LinkedList(); //default constructor
	void insert(int n); //insert node at the end of the list
	void remove(); //remove node from the end of the list
	void insertAfter(int, Node*); //insert node after a specific node
	void print(); //print all the nodes in the list
	int sum(); //sums up all the nodes in the list
	LinkedList& createVector(vector<int>); //extracts values from a vector and creates a list based on these values
	~LinkedList(); //destructor



};

