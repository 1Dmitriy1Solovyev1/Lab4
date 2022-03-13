#include <iostream>

using namespace std;

struct Stack
{
	int info;
	Stack* next;
};

Stack* head;

Stack* AddElement(Stack* head, int elem);
void View(Stack* head);
void Delete_All(Stack** p);
void SwapFirstLast(Stack* p);
void Sort1(Stack** head);
void Sort2(Stack* head);

int main() {
	setlocale(LC_ALL, "Rus");
	while (true) {
		int choice, elem;
		cout << "\t1 - добавить рандомные элементы\t2 - добавить элемент\n\t3 - просмотр стека\t4 - Поменять местами крайние эл-ты\n\t5 - сортировка\t\t6 - очищение стека\n\t7 - выход\n\tВаш выбор : ";
		cin >> choice;
		switch (choice) {
		case 1:
			int n;
			cout << "\t- Сколько элементов вы хотите ?\n\t- ";
			cin >> n;
			for (int i = 1; i <= n; i++) {
				elem = rand() % 41 - 20;
				head = AddElement(head, elem);
			}
			cout << "Элементы созданы" << endl;
			break;
		case 2:
			cout << "\tВведите элемент: ";
			cin >> elem;
			head = AddElement(head, elem);
			cout << "Элемент создан" << endl;
			break;
		case 3:
			View(head);
			break;
		case 4:
			SwapFirstLast(head);
			cout << "поменял" << endl;
			break;
		case 5:
			int sort;
			cout << "\t5.1 - перестановка адресов двух соседних элементов, следующих за элементом с известным указателем\n";
			cout << "\t5.2 - обмен информацией между текущим и следующим элементами\n";
			cout << "\tЯ выбираю ";
			cin >> sort;
			switch (sort) {
			case 1:
				Sort1(&head);
				cout << "Стек отсортирован 1-ым способом (по возрастанию)\n";
				break;
			case 2:
				Sort2(head);
				cout << "Стек отсортирован 2-ым способом (по убыванию)\n";
				break;
			}

			break;
		case 6:
			Delete_All(&head);
			cout << "Стека больше нет\n";
			break;
		case 7:
			Delete_All(&head);
			return 0;
		}
	}

}

Stack* AddElement(Stack* head, int elem) {
	Stack* t = new Stack;
	t->info = elem;
	t->next = head;
	return t;
}

void View(Stack* head) {
	Stack* t = head;
	if (t == NULL) cout << "стeк пустой" << endl;
	else {
		while (t != NULL) {

			cout << " | " << t->info;
			t = t->next;
		}
		cout << " |" << endl;
	}
}

void Delete_All(Stack** p) {
	Stack* t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void SwapFirstLast(Stack* head) {
	int first, last;
	Stack* first_el = head;			
	first = head->info;
	while (!head->next == NULL)
		head = head->next; 		       
	Stack* last_el = head;          
	last = head->info;
	first_el->info = last;
	last_el->info = first;
}

void Sort1(Stack** head) {
	Stack* zero = NULL, * stack2, * forchange;
	if ((*head)->next->next == NULL) return;
	do {
		for (stack2 = *head; stack2->next->next != zero; stack2 = stack2->next)
			if (stack2->next->info > stack2->next->next->info) {
				forchange = stack2->next->next;
				stack2->next->next = forchange->next;
				forchange->next = stack2->next;
				stack2->next = forchange;
			}
		zero = stack2->next;
	} while ((*head)->next->next != zero);
}

void Sort2(Stack* head) {
	Stack* zero = NULL, * stack2;
	int forchange;
	do {
		for (stack2 = head; stack2->next != zero; stack2 = stack2->next)
			if (stack2->info < stack2->next->info) {
				forchange = stack2->info;
				stack2->info = stack2->next->info;
				stack2->next->info = forchange;
			}
		zero = stack2;
	} while (head->next != zero);
}