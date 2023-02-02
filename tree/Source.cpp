#include<iostream>


using namespace std;


class Tree
{
private:
	class Node
	{
	public:
		int data;
		Node* pRight;
		Node* pLeft;

		Node(int data = int(), Node* pRight = nullptr, Node* pLeft = nullptr)
		{
			this->data = data;
			this->pRight = pRight;
			this->pLeft = pLeft;
		}
		void GoAdd(int data, Node* pThis);
	};
	int TreeApex;
	int SIZE;
	Node* Head;
public:
	Tree(int Apex);
	void AddElement(int data);
	Node** GetHead() { return &Head; }
};

Tree::Tree(int Apex)
{
	this->Head =  nullptr;
	this->TreeApex = Apex;
	this->SIZE = 0;
}

void Tree::AddElement(int data)
{
	if (this->Head == nullptr)
	{
		this->Head = new Node(data);
		this->SIZE++;
	}
	else
	{
		Node* cur = this->Head;
		cur->GoAdd(data, cur);
	}
}

int main()
{
	Tree tr(5);
	tr.AddElement(3);
	tr.AddElement(5);
	tr.AddElement(6);
	tr.AddElement(4);
	tr.AddElement(1);
}

void Tree::Node::GoAdd(int data, Node* pThis)
{
	if (pThis != nullptr)
	{

		if (pThis->data > data)
		{
			if (pThis->pLeft == nullptr)
			{
				pThis->pLeft = new Node(data);
			}
			else
			{
				pThis->GoAdd(data, pThis->pLeft);
			}
		}
		else if (pThis->data < data)
		{
			if (pThis->pRight == nullptr)
			{
				pThis->pRight = new Node(data);
			}
			else
			{
				pThis->GoAdd(data, pThis->pRight);
			}
		}
	}
}
