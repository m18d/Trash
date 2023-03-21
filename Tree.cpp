#include<iostream>
#include<string>
#include<time.h>


using namespace std;


//����� ������.
class Tree
{
public:
	//�������� ������ ������ ������.
	Tree(); //�����������
	~Tree(); //����������
	void AddValue(int const value); //������� ���������� �������� � ������.
	void SearchValue(int const value); //������� ����� �������� � ������ � ����� ���������� ��� ����������.
	void PrintLKP(); //������������ �����.
	void PrintLPK(); //�������� �����.
private:
	//����� ����(���������).
	class Node
	{
	public:
		//�������� ����.
		Node* pRight;
		Node* pLeft;
		int value;
		int count;
		//�����������
		Node(int value)
		{
			this->value= value;
			this->count = 1;
			this->pRight = nullptr;
			this->pLeft = nullptr;
		}
	};
	
	//�������� ������ ������.
	Node* Head;
	int Size;

	//�������� ������ ������ ������.
	void AllDel(Node* pThis);
	void Add(Node* pThis, int const value);
	void Search(Node* pThis, int const value);
	void LKP(Node* pThis, int Tab);
	void LPK(Node* pThis, int Tab);
};

Tree::Tree()
{
	this->Head = nullptr;
	this->Size = 0;
}

Tree::~Tree()
{
	AllDel(this->Head);
}

void Tree::AddValue(int const value)
{
	if (this->Head == nullptr)
	{
		this->Head = new Node(value);
		this->Size++;
	}
	else
	{
		this->Add(this->Head, value);
	}
}

void Tree::SearchValue(int const value)
{
	if (this->Head != nullptr)
	{
		Search(this->Head, value);
	}
}

void Tree::PrintLKP()
{
	if (this->Head != nullptr) { this->LKP(this->Head, 0); }
}

void Tree::PrintLPK()
{
	if (this->Head != nullptr) { this->LPK(this->Head, 0); }
}

void Tree::AllDel(Node* pThis)
{
	if (this->Head != nullptr)
	{
		if (pThis->pLeft != nullptr) { AllDel(pThis->pLeft); }
		else if (pThis->pRight != nullptr) { AllDel(pThis->pRight); }
		else
		{
			this->Size--;
			delete pThis;
		}
	}
}

void Tree::Add(Node* pThis, int const value)
{
	if (pThis->value == value) { pThis->count++; }
	else
	{
		if (pThis->value > value)
		{
			if (pThis->pLeft == nullptr)
			{
				pThis->pLeft = new Node(value);
				this->Size++;
			}
			else { Add(pThis->pLeft, value); }
		}
		else
		{
			if (pThis->pRight == nullptr)
			{
				pThis->pRight = new Node(value);
				this->Size++;
			}
			else { Add(pThis->pRight, value); }
		}
	}
}

void Tree::Search(Node* pThis, int const value)
{
	if (pThis->value == value)
	{
		system("cls");
		cout << "����: " << value << " ������� ���������: " << pThis->count << endl;
		system("pause");
	}
	else
	{
		if (pThis->value > value)
		{
			if (pThis->pLeft != nullptr) { Search(pThis->pLeft, value); }
		}
		if (pThis->value < value)
		{
			if (pThis->pRight != nullptr) { Search(pThis->pRight, value); }
		}
	}
}

void Tree::LKP(Node* pThis, int Tab)
{
	if (pThis != nullptr)
	{
		LKP(pThis->pLeft, Tab + 1);
		for (int i = 0; i < Tab; i++)
		{
			cout << "	";
		}
		cout << pThis->value << endl;
		LKP(pThis->pRight, Tab + 1);
	}
}

void Tree::LPK(Node* pThis, int Tab)
{
	if (pThis != nullptr)
	{
		LPK(pThis->pLeft, Tab + 1);
		LPK(pThis->pRight, Tab + 1);
		for (int i = 0; i < Tab; i++)
		{
			cout << "	";
		}
		cout << pThis->value << endl;
	}
}

int isInt(string txt)
{
	char number[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int Count = 0;
	for (int i = 0; i < txt.length(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (txt[i] == number[j])
			{
				Count++;
				break;
			}
		}
	}
	return Count;
}

int quantityApex()
{
	while (true)
	{
		system("cls");
		cout << "������ ����. ��� ����������� ������ ���������� ����������� '������'." << endl;
		cout << "������� ���������� ������ ������, ��� ��� ��������: ";
		string choice;
		cin >> choice;

		if (choice.length() == isInt(choice)) { return stoi(choice); }
		else
		{
			system("cls");
			cout << "�� ���� ���������� ������ �����!!!" << endl;
			system("pause");
		}
	}
}

int menu()
{
	while (true)
	{
		system("cls");
		cout << "=========================����=========================" << endl;
		cout << "1. �������� ����� ������� � ������." << endl;
		cout << "2. ����� ������� � �������� �����." << endl;
		cout << "3. ������������ ����� ������." << endl;
		cout << "4. �������� ������������ ����� ������." << endl;
		cout << "5. �����." << endl;
		cout << "����: ";
		string choice;
		cin >> choice;

		if (choice.length() == isInt(choice))
		{
			if (stoi(choice) > 0 && stoi(choice) < 6) { return stoi(choice); }
			else
			{
				system("cls");
				cout << "�������� ����� �� 1 �� 5 ������������!!!" << endl;
				system("pause");
			}
		}
		else
		{
			system("cls");
			cout << "�� ���� ���������� ������ �����!!!" << endl;
			system("pause");
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	Tree tree;
	int Apex = quantityApex();
	for (int i = 0; i < Apex; i++)
	{
		tree.AddValue(rand() % 100);
	}

	while (true)
	{
		switch (menu())
		{
		case 1:
		{
			system("cls");
			cout << "������� �������� ��������, �������� ������ ��������: ";
			string value;
			cin >> value;

			if (isInt(value)) { tree.AddValue(stoi(value)); }
			else
			{
				system("cls");
				cout << "�� ���� ���������� ������ �����!!!" << endl;
				system("pause");
			}
			break;
		}
		case 2:
		{
			system("cls");
			cout << "������� �������� ��������, �������� ������ �����: ";
			string value;
			cin >> value;

			if (isInt(value)) { tree.SearchValue(stoi(value)); }
			else
			{
				system("cls");
				cout << "�� ���� ���������� ������ �����!!!" << endl;
				system("pause");
			}
			break;
		}
		case 3:
			system("cls");
			cout << "����� ������ � ������������ ����: " << endl;
			tree.PrintLKP();
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "����� ������ � �������-������������ ����: " << endl;
			tree.PrintLPK();
			system("pause");
			break;
		case 5:
			exit(0);
		}
	}
}