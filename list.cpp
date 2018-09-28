
#include <iostream>

struct node {
	char key;
	node * next;
};

node * head = new node,
*z = new node,
*a = new node,
*b = new node,
*c = new node;

void display();
node * before(node * x);
void remove(node * x);
void place(node * x);

int main() {

	head->key = 'h';
	a->key = 'A';
	b->key = 'B';
	c->key = 'C';
	z->key = 'z';

	head->next = a;
	a->next = b;
	b->next = c;
	c->next = z;
	z->next = z;

	remove(b);
	display();
	node * d = new node;
	d->key = 'D';
	place(d);
	display();

	return 0;
}

node * before(node * x) {

	node * temp = new node;
	temp = head;

	while (temp->next != x) {
		temp = temp->next;
	}
	return temp;
}

void display() {

	node * temp = new node;
	temp = head;

	while (temp != z) {
		std::cout << temp->key << " -> ";
		temp = temp->next;
	}
	std::cout << temp->key << std::endl;
	delete temp;
}

void remove(node * x) {
	node * temp = new node;
	temp = before(x);
	*temp->next = *x->next;
}

void place(node * x) {
	before(z)->next = x;
	x->next = z;
}