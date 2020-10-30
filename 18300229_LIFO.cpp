// 18300229_LIFO.cpp	P2.2 - PILA
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

template <class T>
class List	//Contains the activities of the list.
{
	class Node //Holds our nodes.
	{
	public:
		T data = NULL; //Holds a generic data value.
		Node* link; //Points to the next element.
		Node()
		{
			link = nullptr;
		}
	};

	Node* beggining;

public:
	List()
	{
		beggining = nullptr;
	}

	void Push(T data) //adds element at the end of the list.
	{
		Node* newNode, * cursor;
		newNode = new Node();
		newNode->data = data;

		if (beggining == nullptr)
			beggining = newNode;
		else
		{
			cursor = beggining;
			while (cursor->link) //while next link is not empty.
				cursor = cursor->link;
			cursor->link = newNode;
		}
	}

	int getPosition(T searchValue) //Returns the position where data was found.
	{
		for (int pos = 0; pos < count(); pos++) //Search.
		{
			if (getValue(pos) == searchValue)
				return pos;
		}
		return -1;
	}

	int count() //Counts the elements in the list.
	{
		int elementCount = 0;
		Node* cursor = beggining;
		while (cursor)
		{
			elementCount++;
			cursor = cursor->link;
		}
		return elementCount;
	}

	void pop() //Deletes a particular element in the list.
	{
		if (count() > 1) //more than a single node
		{
			Node* erase = beggining,
				* prevElement = nullptr;
			while (erase->link)	//moves cursor while link not null
			{
				prevElement = erase;
				erase = erase->link;
			}
			delete erase;	//deletes last element.
			prevElement->link = nullptr;	//points now last element to null;
		}
		else
			beggining = nullptr;	//set beginning to null.
	}

	void deleteAll() //Clears list.
	{
		Node* erase;

		while (beggining) //Deletes from first to last while link not null.
		{
			erase = beggining;
			beggining = beggining->link;
			delete erase;
		}
	}

	bool checkEmpty() //Checks if count is 0.
	{
		if (count() == 0)
		{
			cout << "List is empty." << endl;
			return true;
		}
		return false;
	}
	T getValue(T index)	//
	{
		if (count() > index)
		{
			Node* cursor = beggining;
			for (int i = 0; i < index; i++)
				cursor = cursor->link;
			return cursor->data;
		}
		return beggining->data;
	}
};

int main()
{
	List<int> myCollection;
	int dataValue = 0,
		searchPos = 0;
	do
	{
		char choice = 0;
		system("cls");
		cout << "========FIFO=========" << endl;

		do //Loop until correct input
		{
			cout << endl << "Choose an option" << endl;
			cout << "[1] Push" << endl;
			cout << "[2] Search value in the collection." << endl;
			cout << "[4] Count" << endl;
			cout << "[5] Show all elements in the list." << endl;
			cout << "[7] Pop" << endl;
			cout << "[8] Delete all" << endl;
			cout << "[9] Exit." << endl;
			cout << ">Answer: "; choice = _getch();
			system("cls");
		} while (choice < 49 or choice > 57); //ASCII from 1 to 9.

		switch (choice)
		{
		case '1':	//Pop -- add element
			cout << "Push:" << endl;
			cout << "Item [" << myCollection.count() + 1 << "]: ";
			cin >> dataValue;
			myCollection.Push(dataValue);
			cout << "item added" << endl;
			break;

		case '4': //Count
			if (myCollection.checkEmpty())
				break;
			cout << "\nThe element count is = " << myCollection.count() << " elements.\n";
			break;

		case '5': //Show all items
			if (myCollection.checkEmpty())
				break;
			for (int i = 0; i < myCollection.count(); i++)
				cout << "Item [" << i + 1 << "] = " << myCollection.getValue(i) << endl;
			break;

		case '7':	//Delete particular
			if (myCollection.checkEmpty()) break;
			myCollection.pop();
			break;

		case '8':	//Clear list
			if (myCollection.checkEmpty())
				break;
			myCollection.deleteAll();
			cout << "\n List is now clear, all elements deleted successfully\n";
			break;

		case '9':	//Exit
			cout << endl << "Successfully exited the program.\n";
			return 0;
			break;
		}

		cout << endl;
		system("pause");
	} while (1);	//Never ending loop
}