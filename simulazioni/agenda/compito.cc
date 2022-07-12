#include <iostream>
#include <fstream>
#include <cstring>

#include "tipo.h"
#include "liste.h"


using namespace std;

void agenda(lista&  agenda, appuntamento  a);
void stampa(lista agenda);
void quanti(lista agenda, appuntamento a);
lista  estrai(lista& agenda, appuntamento d);

int main(){
  ifstream f;
  f.open("agenda.txt");

  
  lista l = NULL;

  appuntamento a;
  while(f>>a.data){
    string s;
    f>>a.ora_i>>a.ora_f;
    getline(f>>ws, s);
    s.pop_back();
    strcpy(a.descr, s.c_str());
    agenda(l, a);
  }

  f.close();

  cout<<"AGENDA:"<<endl;
  stampa(l);

  appuntamento c;
  cout<<"inserire data, ora inizio, ora fine, descrizione, dell'appuntamento da controllare"<<endl;
  cin>>c.data>>c.ora_i>>c.ora_f>>c.descr;
  quanti(l, c);

  appuntamento desc;
  string ap;
  cout<<"inserire descrizione da estrarre"<<endl;
  getline(cin>>ws, ap);
  strcpy(desc.descr, ap.c_str());

  cout<<"GLI APPUNTAMENTI IN AGENDA CON LA DESCRIZIONE "<<desc.descr<<" SONO:"<<endl;
  lista l1 = estrai(l , desc);
  stampa(l1);


  cout<<"AGENDA SENZA "<<desc.descr<<":"<<endl;
  stampa(l);

  return 0;
}


void agenda(lista&  agenda, appuntamento  a){
    lista tmp = agenda;
    bool trovato = false;

    while(tmp != NULL && !trovato){
      if(compare(head(tmp), a) == true){
        trovato = true;
      }

      tmp = tail(tmp);
    }

    if(!trovato){
      elem* app = new_elem(a);
      agenda = insert_elem_sorted(agenda,app);
    }else{
      cout<<"Errore,l'appuntamento ";
      print(a);
      cout<<" è già stato prenotato"<<endl;
    }
    
}

void stampa(lista agenda){
  while(agenda != NULL){
    print(head(agenda));
    agenda = tail(agenda);
  }
}

void quanti(lista agenda, appuntamento a){
  int contPrima = 0;
  int contDopo = 0;



  while(agenda != NULL){
      if((strcmp(head(agenda).data, a.data) == 0) && compare(head(agenda), a) == false){
        if(strcmp(head(agenda).ora_f, a.ora_i) < 0){
          contPrima++;
        }else if(strcmp(head(agenda).ora_i, a.ora_f) > 0){
          contDopo++;
        }
      }
      agenda = tail(agenda); 
  }

  cout<<contPrima<<" appuntamenti prima e "<<contDopo<<" appuntamenti dopo"<<endl;
}


lista  estrai(lista& agenda, appuntamento d){
  lista l1 = NULL;
  lista tmp = agenda;
    
    while(tmp != NULL){
      if(strcmp(head(tmp).descr, d.descr) == 0){
        elem* e = tmp;
        if(prev(tmp) != NULL){
          (e->prev)->pun = e->pun;
        }
        if(tail(tmp)!=NULL){
          (e->pun)->prev=e->prev;
        }
        tmp = tail(tmp);
        l1 = insert_elem_sorted(l1, e);
      }else{
        tmp = tail(tmp);
      }
    }

    return l1;
}