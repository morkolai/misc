
#include <iostream>

struct node {
	char info;
	node *  r;
	node * l;
	node(char info, node * lptr, node * rptr);
};

void tree();

int main() {

	tree();

	return 0;
}

node::node(char i, node * lptr, node * rptr) {
	info = i;
	l = lptr;
	r = rptr;
}

void tree() {
	node * z = new node('z', z, z);
	node * C = new node('C', z, z);
	node * D = new node('D', z, z);
	node * F = new node('F', z, z);
	node * G = new node('G', z, z);
	node * B = new node('B', C, D);
	node * E = new node('E', F, G);
	node * A = new node('A', B, E);
}

