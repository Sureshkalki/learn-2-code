#include "pch.h"
#include <iostream>

using namespace std;

typedef struct Element
{
	void* data;
	struct Element* next;
} Element;

bool push(Element** top, void* data)
{
	Element* elem = new Element;
	if (!elem) return false;

	elem->data = data;
	elem->next = *top;
	*top = elem;
	return true;
}

bool createStack(Element** top)
{
	*top = NULL;
	return true;
}

bool pop(Element** top, void** data)
{
	Element* elem;
	if (!(elem = *top)) return false;

	*data = elem->data;
	*top = elem->next;
	delete elem;
	return true;
}

bool deleteStack(Element** top)
{
	Element* elem;
	while (*top) {
		elem = (*top)->next;
		delete* top;
		*top = elem;
	}
	return true;

}

void printStack(Element* top)
{
	if (top == NULL) {
		cout << "Empty!" << endl;
	}
	Element* cur = top;
	while (cur) {
		cout << *(static_cast<int*>(cur->data)) << " ";
		cur = cur->next;
	}
	cout << endl << endl;
}

TEST(TestCaseName, testStack)
{
	Element* head;
	createStack(&head);
	int n1 = 10, n2 = 20, n3 = 30, n4 = 40, n5 = 50;
	EXPECT_EQ(true, push(&head , &n1));
	EXPECT_EQ(true, push(&head , &n2));
	EXPECT_EQ(true, push(&head , &n3));
	EXPECT_EQ(true, push(&head , &n4));
	EXPECT_EQ(true, push(&head , &n5));

	printStack(head);

	void* n;
	pop(&head, &n);
	cout << "popped " << *(static_cast<int*>(n)) << endl;
	EXPECT_EQ(50, *(static_cast<int*>(n)));
	pop(&head, &n);
	cout << "popped " << *(static_cast<int*>(n)) << endl;
	EXPECT_EQ(40, *(static_cast<int*>(n)));
	cout << endl;

	printStack(head);

	cout << "deleting stack..." << endl;
	deleteStack(&head);
	EXPECT_EQ(false, pop(&head, &n));
	printStack(head);
}
