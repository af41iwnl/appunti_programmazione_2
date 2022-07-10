#include <iostream>
using namespace std;

lista insert_elem_sorted(lista l, elem* e){ 
    if (l == NULL){
		l =  insert_elem(l, e);
	}
    else if (strcmp(head(l).data, e->inf.data) >= 0) {
        e->pun = l;
        e->pun->prev = e;
        l = e;
    }else{
        lista tmp = l;
        while ((tail(tmp) != NULL) && (strcmp(tail(tmp)->inf.data, e->inf.data)<0)){
			tmp = tail(tmp);
		}
        e->pun = tail(tmp);
        if (tail(tmp) != NULL)
            e->pun->prev = e;
  
        tmp->pun = e;
        e->prev = tmp;
    }
	return l;
}