#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;


void insertAfter(vector<int> & n, int firstValue, int secondValue)
{
	int counter = 0;
	for (int i=0; i<n.size(); i++)
	{
		if (n.at(i) == firstValue)
		{
			n.insert(n.begin() + i, secondValue); //inserts new value in vector if first value is found
			counter++;
		}
	}
	if (counter == 0)
		cout << "The value being searched for was not found within this vector" << endl;
}

int main()
{
	vector<int> num;
	int n;
	cout << "Enter numbers to push into vector & enter 99999 when you wish to exit the input loop:"<<endl;
	do
	{
		cin >> n;
		if(n!=99999) //99999 is a sentinel value
		num.push_back(n);
	}
	while (n != 99999);
	
	LinkedList list;
	list.createVector(num);
	list.print();

	
	/*cout << "List after last node is removed:" << endl;

	list.print();*/

	list.~LinkedList();



	return 0;
}