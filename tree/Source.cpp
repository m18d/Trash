#include<iostream>


using namespace std;

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
	void GoDel(int data, Node* pThis, Node* pLast);
	void GoDel2(int data, Node* pThis, Node* pLast);
	void GoAllDel(Node* pThis);
	Node* _deleteNode(Node* currentNode, int itemValue);
	void LKPNode(Node* cur, int level);
	void KLPNode(Node* cur, int level);
	void LPKNode(Node* cur, int level);
private:
	Node* _findMinElement(Node* node);
};

class Tree
{
private:
	int TreeApex;
	int SIZE;
	Node* Head;

	void DestroyTree(); //Полное удаление дерева
public:
	int GetApex() { return TreeApex; }
	int GetCount() { return SIZE; }
	Tree(int Apex);
	~Tree();
	void deleteItem(int nodeValue);
	void AddElement(int data); //Добавление элемента в узел дерева
	void DelElement(int data);
	void LKP(); //Симетричный проход
	void KLP(); //корень лево право
	void LPK(); //Лево право корень
};

Tree::Tree(int Apex)
{
	this->Head =  nullptr;
	this->TreeApex = Apex;
	this->SIZE = 0;
}

Tree::~Tree()
{
	DestroyTree();
}

void Tree::deleteItem(int nodeValue) {
	// если дерево пустое - ничего не делаем, можно выдать предупреждение
	Node* tmp = this->Head;
	if (tmp != nullptr) { tmp = tmp->_deleteNode(tmp, nodeValue); }
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
		this->SIZE++;
	}
}

void Tree::DelElement(int data)
{
	if (this->Head != nullptr)
	{
		if (data != Head->data)
		{
			Head->GoDel(data, this->Head, nullptr);
		}
		else
		{
			Head->GoDel2(data, this->Head, nullptr);
		}
	}
}

void Tree::DestroyTree()
{
	Node* Temp = this->Head;
	if (Temp != nullptr)
	{
		Temp->GoAllDel(Temp);
	}
	this->SIZE--;
}

void Tree::LKP()
{
	if (this->Head != nullptr)
	{
		cout << "==================================\n";
		this->Head->LKPNode(this->Head, 0);
		cout << "==================================\n";
	}
}

void Tree::KLP()
{
	if (this->Head != nullptr)
	{
		cout << "==================================\n";
		this->Head->KLPNode(this->Head, 0);
		cout << "==================================\n";
	}
}

void Tree::LPK()
{
	if (this->Head != nullptr)
	{
		cout << "==================================\n";
		this->Head->LPKNode(this->Head, 0);
		cout << "==================================\n";
	}
}

int menu()
{
	while (true)
	{
		system("cls");
		cout << "==============Меню бинарного дерева===================" << endl;
		cout << "1. Добавить элемент." << endl;
		cout << "2. Удалить элемент." << endl;
		cout << "3. Вывести дерево на экран." << endl;
		cout << "4. Выход." << endl;
		cout << "Ввод: ";
		int choice;
		cin >> choice;
		if (choice < 5 && choice > 0)
		{
			return choice;
		}
		else
		{
			system("cls");
			cout << "Ошибка (Диапазон выбора от 1 до 4)";
			system("pause");
		}
	}
}
int aprove()
{
	while (true)
	{
		system("cls");
		cout << "Введите количество вершин." << endl;
		cout << "Ввод: ";
		int Aprove;
		cin >> Aprove;
		if (Aprove > 0)
		{
			return Aprove;
		}
	}
}
void add(Tree tr)
{
	if (tr.GetApex() != tr.GetCount())
	{
		system("cls");
		cout << "Введите числовое значени элемента, которое хотите добавить" << endl;
		cout << "Ввод: ";
		int value;
		cin >> value;
		tr.AddElement(value);
	}
	else
	{ 
		cout << "Максимально количетсво элементов. Удалить 1 элемент перед добавлением" << endl; 
		system("pause"); 
	}
}
void del(Tree tr)
{
	if (tr.GetCount() != 0)
	{
		system("cls");
		cout << "Введите числовое значени элемента, которое хотите удалить" << endl;
		cout << "Ввод: ";
		int value;
		cin >> value;
		tr.DelElement(value);
	}
	else
	{
		cout << "Перед удаленим нужно добавить хотя бы 1 элемент" << endl;
		system("pause");
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	Tree tr(aprove());
	while (true)
	{
		switch (menu())
		{
		case 1:
			if (tr.GetApex() != tr.GetCount())
			{
				system("cls");
				cout << "Введите числовое значени элемента, которое хотите добавить" << endl;
				cout << "Ввод: ";
				int value;
				cin >> value;
				tr.AddElement(value);
			}
			else
			{
				cout << "Максимально количетсво элементов. Удалить 1 элемент перед добавлением" << endl;
				system("pause");
			}
			break;
		case 2:
			if (tr.GetCount() != 0)
			{
				system("cls");
				cout << "Введите числовое значени элемента, которое хотите удалить" << endl;
				cout << "Ввод: ";
				int value;
				cin >> value;
				tr.DelElement(value);
			}
			else
			{
				cout << "Перед удаленим нужно добавить хотя бы 1 элемент" << endl;
				system("pause");
			}
			break;
		case 3:
			system("cls");
			tr.LKP();
			system("pause");
			break;
		case 4:
			cout << "Заходи ещё!!!";
			exit(0);
		}
	}
}

void Node::GoAdd(int data, Node* pThis)
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

Node* Node::_findMinElement(Node* node) {
	if (node->pLeft == nullptr) return node;

	return _findMinElement(node->pLeft);
}

Node* Node::_deleteNode(Node* currentNode,int itemValue) {
	// если нашли нужный элемент, начинаем процедуру удаления
	if (currentNode->data == itemValue) {
		// обработка самого простого случая, вместо узла возвращается null
		if (currentNode->pLeft == nullptr && currentNode->pRight== nullptr) {
			return nullptr;
		}

		// обработка двух случаев, с только одним из поддеревьев
		if (currentNode->pLeft == nullptr) {
			return currentNode->pRight;
		}

		if (currentNode->pRight == nullptr) {
			return currentNode->pLeft;
		}

		// если у ноды есть оба потомка
		const Node* minNodeInRightSubtree = _findMinElement(currentNode->pRight);
		// заменили текущий элемент минимальным из правого поддерева
		currentNode->data= minNodeInRightSubtree->data;

		// ищем в правом поддереве минимальный элемент,
		// значение которого уже вставлено на место текущего
		currentNode->pRight = _deleteNode(
			currentNode->pRight,
			minNodeInRightSubtree->data
		);
		return currentNode;
	}

	// попадаем сюда, если элемент не был найден,
	// просто проваливаемся в дерево глубже и глубже

	// производится рекурсивный вызов этой же функции,
	// при этом если элемент не будет найден,
	// то алгоритм просто будет возвращать существующую ссылку на поддерево,
	// которая присвоится в ту же позицию
	if (itemValue < currentNode->data) {
		if (currentNode->pLeft == nullptr) {
			return currentNode;
		}

		// проваливаемся в левое поддерево,
		// после рекурсивной отработки функции _deleteNode
		// будет возвращен текущий элемент,
		// который в предыдущем вызове будет присвоен
		currentNode->pLeft = _deleteNode(currentNode->pLeft, itemValue);

		// присваивание на рекурсивный уровень выше,
		// может быть как в левое поддерево,так и в правое,
		// на текущем уровне мы не знаем какое поддерево обрабатываем
		return currentNode;
	}

	// аналогичная обработка для правого поддерева
	if (itemValue > currentNode->data) {
		if (currentNode->pRight == nullptr) {
			return currentNode;
		}

		currentNode->pRight = _deleteNode(currentNode->pRight, itemValue);
		return currentNode;
	}
}

void Node::GoDel(int data, Node* pThis, Node* pLast)
{
	if (data == pThis->data) {

		if (pThis->pRight == nullptr)
			pLast->pRight = pThis->pLeft;
		else {

			Node* ptr = pThis->pRight;
			if (ptr->pLeft == nullptr) {
				ptr->pLeft = pThis->pLeft;
				if (pLast != nullptr) { pLast->pRight = ptr; }
			}
			else {

				Node* pmin = ptr->pLeft;
				while (pmin->pLeft != nullptr) {
					ptr = pmin;
					pmin = ptr->pLeft;
				}
				ptr->pLeft = pmin->pLeft;
				pmin->pLeft = pThis->pLeft;
				pmin->pRight = pThis->pRight;
				if (pLast != nullptr) { pLast->pLeft = pmin; }
			}
		}
		delete pThis;
	}
	else if (data < pThis->data)
		GoDel(data, pThis->pLeft, pThis);
	else
		GoDel(data, pThis->pRight, pThis);
}

void Node::GoDel2(int data, Node* pThis, Node* pLast)
{
	if (pThis->pRight != nullptr)
	{
		Node* right = pThis->pRight;
		Node* left = pThis->pLeft;
		if (right->pLeft == nullptr)
		{
			right->pLeft = left;
			Node* del = pThis;
			pThis = right;
			delete del;
		}
	}
	else if(pThis->pRight == nullptr)
	{
		Node* left = pThis->pLeft;
		Node* del = pThis;
		pThis = left;
		delete del;
	}
	else
	{
		delete pThis;
	}
}

void Node::GoAllDel(Node* pThis)
{
	if (pThis != nullptr)
	{
		GoAllDel(pThis->pRight);
		GoAllDel(pThis->pLeft);
		delete pThis;
	}
}

void Node::LKPNode(Node* cur, int level)
{
	if (cur != nullptr)
	{
		LKPNode(cur->pLeft, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << cur->data << endl;
		LKPNode(cur->pRight, level + 1);
	}
}

void Node::KLPNode(Node* cur, int level)
{
	if (cur != nullptr)
	{
		for (int i = 0; i < level; i++) cout << "   ";
		cout << cur->data << endl;
		KLPNode(cur->pLeft, level + 1);
		KLPNode(cur->pRight, level + 1);
	}
}

void Node::LPKNode(Node* cur, int level)
{
	if (cur != nullptr)
	{
		KLPNode(cur->pLeft, level + 1);
		KLPNode(cur->pRight, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << cur->data << endl;
	}
}
