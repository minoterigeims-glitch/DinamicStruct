

#include <iostream>
#include<windows.h>

using namespace std;


class LinkedList
{
private:
	struct Node
	{
		int date;
		Node* next;
		Node(int value) : date(value), next(nullptr) {}
	};

	Node* head;

public:
	LinkedList() : head(nullptr) {}
	~LinkedList() {
		Node* carren = head;
		while (carren != nullptr)
		{
			Node* nextNode = carren->next;
			delete carren;
			carren = nextNode;
		}
		cout << "Видалено всі елементи списку" << endl;
	}
	bool isEmpty() const {
		return head == nullptr;
	}

	void push_frond(int value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;

	}
	void push_back(int value) {
		Node* newNode = new Node(value);

		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* current = head;

			while (current->next != nullptr) {
				current = current->next;
			}

			current->next = newNode;
		}
	}

	int size() const {
		int count = 0;
		Node* current = head;
		while (current != nullptr) {
			count++;
			current = current->next;
		}
		return count;
	}

	void print() const {
		if (isEmpty()) {
			cout << "Список порожній" << endl;
			return;
		}

		Node* current = head;
		while (current != nullptr) {
			cout << current->date << " ";
			current = current->next;
		}
		

		cout << "nullptr" << endl;
	}


};

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	LinkedList list;
	int choice, value;

	do {
		cout << "================== МЕНЮ ==================" << endl;
		cout << "1. Додати елемент на початок" << endl;
		cout << "2. Додати елемент у кінець" << endl;
		cout << "3. Перевірити, чи список порожній" << endl;
		cout << "4. Кількість елементів" << endl;
		cout << "5. Вивести список" << endl;
		cout << "0. Вихід" << endl;
		cout << "Ваш вибір: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Введіть число: ";
			cin >> value;
			list.push_frond(value);
			break;

		case 2:
			cout << "Введіть число: ";
			cin >> value;
			list.push_back(value);
			break;

		case 3:
			if (list.isEmpty()) {
				cout << "Список порожній" << endl;
			}
			else {
				cout << "Список не порожній" << endl;
			}
			break;

		case 4:
			cout << "Кількість елементів: "
				<< list.size() << endl;
			break;

		case 5:
			list.print();
			break;

		case 0:
			cout << "Завершення програми" << endl;
			break;

		default:
			cout << "Невірний вибір!" << endl;
			break;
		}

	} while (choice != 0);

}

