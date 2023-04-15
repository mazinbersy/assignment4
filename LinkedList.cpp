#include "LinkedList.h"

LinkedList::LinkedList()
{
	first = NULL;
	last = NULL;
}

void LinkedList::insert(int n)
{
	if (first == NULL)
	{
		first = new Node;
		first->value = n;
		first->back = NULL;
		first->next = NULL;
		last = first;
	}
	else
	{
		Node* temp = new Node;
		temp->value = n;
		temp->back = last;
		last->next = temp;
		last = temp;
	
		
	}
}

void LinkedList::remove()
{
	if (last == NULL) // List is empty
	{
		cout << "List is empty." << endl;
		return;
	}

	if (last == first) // Only one node in list
	{
		last = NULL;
		first = NULL;
		return;
	}

	Node* temp = last->back; // Second to last node
	temp->next = NULL;
	last = temp;
}

void LinkedList::insertAfter(int v, Node* curr)
{
	Node* temp = new Node;
	temp->value = v;
	temp->back = curr;
	temp->next = curr->next;
	curr->next = temp;
	if (temp->next != NULL)
		temp->next->back = temp;

}

void LinkedList::print()
{
	Node* temp;
	temp = first;
	cout << "THE LIST IS AS FOLLOWS:" << endl;
	while (temp != NULL)
	{
		cout << temp->value;
		if (temp->occ > 1)
			cout << " -----------> occurs " << temp->occ << " times";
		cout << endl;
		temp = temp->next;
	}

}

int LinkedList::sum()
{
	int sum = 0;
	Node* temp = new Node;
	temp = first;
	while (temp != NULL)
	{
		sum += temp->value;
		temp = temp->next;
	}
	return sum;
}

LinkedList& LinkedList::createVector(vector<int> n)
{
		for (int i = 0; i < n.size(); i++)
		{
			int count = 1;
			for (int j=i+1; j < n.size(); j++)
			{
				if (n[i] == n[j])
				{
					count++;
					n.erase(n.begin() + j);
					j--;
				}

			}
			if (count > 1)
			{
				insert(n[i]);
				last->occ = count;
				
			}
			if (count == 1)
				insert(n[i]);

		}


		return *this;
	}



LinkedList::~LinkedList()
{
	delete first;
	delete last;
}
