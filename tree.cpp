#include <iostream>

//node struct, r = rigth node and l = rigth node 
struct node {
	char info;
	node *  r;
	node * l;
	node(char info, node * lptr, node * rptr);
};

void visit(node * t);
void traverseInorder(node * t);
void traversePreorder(node * t);
void traversePostorder(node * t);

//building a tree to work on
node * z = new node('z', z, z);
node * C = new node('C', z, z);
node * D = new node('D', z, z);
node * F = new node('F', z, z);
node * G = new node('G', z, z);
node * B = new node('B', C, D);
node * E = new node('E', F, G);
node * A = new node('A', B, E);											//root

int main() {

	std::cout << "\nInorder traversal:\n";
	traverseInorder(A);
	std::cout << "\n\nPreorder traversal:\n";
	traversePreorder(A);
	std::cout << "\n\nPostorder traversal:\n";
	traversePostorder(A);
	std::cout << "\n\n";
	
	return 0;
}

//node constructor
node::node(char i, node * lptr, node * rptr) {
	info = i;
	l = lptr;
	r = rptr;
}

//prints the node's info
void visit(node * t) {
	std::cout << t->info << ' ';
}

//inorder traversal of tree, t = root
void traverseInorder(node * t) {
	if (t != z) {
		traverseInorder(t->l);
		visit(t);
		traverseInorder(t->r);
	}
}

//preorder traversal of tree, t = root
void traversePreorder(node * t) {
	if (t != z) {
		visit(t);
		traversePreorder(t->l);
		traversePreorder(t->r);
	}
}

//postorder traversal of tree, t = root
void traversePostorder(node * t) {
	if (t != z) {
		traversePostorder(t->l);
		traversePostorder(t->r);
		visit(t);
	}
}

//next step: traverseLevelorder(node * t); displayTree(node * t);