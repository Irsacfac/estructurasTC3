#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

typedef struct node* link;

struct node {
	int val;
	link izq, der;
	bool isBlack;

	node(int v) :val{ v }, izq{ nullptr }, der{ nullptr }, isBlack{ false }{}
	void show(int nivel);

	string sColor() {
		if (this->isBlack)
			return "negro";
		else return "rojo";
	}
};

void node::show(int nivel) {
	for (int i = 0; i < 3 * nivel; i++) cout << " ";
	if (this->izq == nullptr && this->der == nullptr) {
		cout << "[" << this->val << " <" << this->sColor() << ">" << "]";
	}

	else {
		cout << "[" << this->val << " <" << this->sColor() << ">" << endl;
		if (this->izq)
			this->izq->show(nivel + 1);
		else {
			for (int i = 0; i < 3 * (nivel + 1); i++)cout << " ";
			cout << "[]";
		}
		cout << "\n";
		if (this->der)
			this->der->show(nivel + 1);
		else {
			for (int i = 0; i < 3 * (nivel + 1); i++)cout << " ";
			cout << "[]";
		}
		cout << "\n";
		for (int i = 0; i < 3 * nivel; i++) cout << " ";
		cout << "j";
	}
}

void rotateR(link &h) {
	link p = h->izq;
	h->izq = p->der;
	p->der = h;
	h = p;
}

void rotateL(link &h) {
	link p = h->der;
	h->der = p->izq;
	p->izq = h;
	h = p;
}

bool esRojo(link x) {
	if (x == nullptr) return false;
	return x->isBlack == false;
}
void RBinsert(link& h, int x) {
	RBinsertR(h, x, 0);
	h->isBlack = true;
}

void RBinsertR(link& h, int x, int sw) {
	if (h == nullptr) { h = new node(x); return; }
	if (esRojo(h->izq) && esRojo(h->der)) {
		h->isBlack == false;
		h->izq->isBlack == true;
		h->der->isBlack == true;
	}
	if (x < h->val) {
		RBinsertR(h->izq, x, 0);
		if (esRojo(h) && esRojo(h->izq) && sw)
			rotateR(h);
		if (esRojo(h->izq) && esRojo(h->izq->izq)) {
			rotateR(h);
			h->isBlack = true;
			h->der->isBlack = false;
		}
	}
	else {
		RBinsertR(h->der, x, 1);
		if (esRojo(h) && esRojo(h->der) && !sw)
			rotateL(h);
		if (esRojo(h) && esRojo(h->der->der)) {
			rotateL(h);
			h->isBlack = true;
			h->izq->isBlack = false;
		}
	}
}
template <class Item>
void intercambie(Item& a, Item& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	return
}

int* permuta(int n) {
	int * pt = new int[n];
	for (int i = 0; i < n; i++)
		pt[i] = i;
	for (int i = 0; i < n; i++)
		intercambie<int>(pt[i], pt[rand() % n]);
}