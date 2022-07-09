

#include <iostream>
#include <cstring>

#include "tipo.h"
#include "liste.h"

using namespace std;

tipo_inf head(lista p){return p->inf;}

elem* search(lista l, tipo_inf v){
	while(l!=NULL)
		if(compare(head(l),v)==0)
			return l;
		else
			l=tail(l);
	return NULL;}


elem* new_elem(tipo_inf inf){
	    elem* p = new elem ;
	    copy(p->inf,inf);
	    p->pun=p->prev=NULL;
		return p;

	}


lista tail(lista p){return p->pun;}
lista prev(lista p){return p->prev;}

lista insert_elem(lista l, elem* e){
	e->pun=l;
	if(l!=NULL)
		l->prev=e;
	e->prev=NULL;
	return e;
}

lista insert_elem_sorted(lista l, elem* e){
	if (l == NULL) {  // inserimento lista vuota
		e->pun = NULL;
		e->prev = NULL;
		return e;
	}

	elem *cur = l;
	elem *prev = NULL;
	while (cur != NULL && compare(cur->inf, e->inf) < 0) {
		prev = cur;
		cur = cur->pun;
	}

	e->pun = cur;
	e->prev = prev;
	if (prev != NULL)
		prev->pun = e;
	else
		l = e;

	if (cur != NULL)
		cur->prev = e;
	return l;
}

lista delete_elem(lista l, elem* e){

		if(l==e)
			l=e->pun; // e è la testa della lista
		else // e non è la testa della lista
			(e->prev)->pun = e->pun;
		if(e->pun!=NULL)
			(e->pun)->prev=e->prev;
		delete e;
		return l;
}
