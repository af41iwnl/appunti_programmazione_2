#include <iostream>
#include "tipo.h"
#include "liste.h"

using namespace std;

void pesca(lista& l);
void stampa(lista l);
carta*  scala(lista carte, int&  lunghezza);
void stampaScala(lista carte, int lunghezza);
int cala(lista& carte);

int main(){
    /*
        12Q 2P 10Q 3P 11Q 4P
        1F 6F 3F 5F 1C 4F
    */
    lista g1 = NULL;
    lista g2 = NULL;

    int n;
    do{
        cout<<"Inserire carte da assegnare a ciascun giocatore"<<endl;
        cin>>n;
    }while(n <= 0);

    for(int i=0; i<n; i++){
        cout<<"Scegli valore e seme per giocatore 1"<<endl;
        pesca(g1);
        cout<<"Scegli valore e seme per giocatore 2"<<endl;
        pesca(g2);
    }
    
    cout<<"Carte di giocatore 1:"<<endl;
    stampa(g1);
    cout<<endl;
    cout<<"Carte di giocatore 2:"<<endl;
    stampa(g2);
    cout<<endl;

        int l;
        carta* s1 = scala(g1, l);
        elem *scala1 = search(g1, *s1);
        cout<<"Prima scala giocatore 1:"<<endl;
        stampaScala(scala1, l);
        cout<<endl;

        carta* s2 = scala(g2, l);
        elem *scala2 = search(g2, *s2);
        cout<<"Prima scala giocatore 2:"<<endl;
        stampaScala(scala2, l);
        cout<<endl;

    int turni = 2;
    for(int i=1; i<=turni; i++){
        cout<<"TURNO "<<i<<":"<<endl;

        cout<<"Scegli valore e seme per giocatore 1"<<endl;
        pesca(g1);
        cout<<"Scegli valore e seme per giocatore 2"<<endl;
        pesca(g2);
        


        

        cout<<"Punteggio giocatore 1: ";
        int tot1 = cala(g1);
        cout<<tot1<<endl;
        cout<<"Punteggio giocatore 2: ";
        int tot2 = cala(g2);
        cout<<tot2<<endl;
    }
    

    return 0;
}


void pesca(lista& l){
    carta c;
    cin>>c.valore>>c.seme;

    elem* e = new_elem(c);
    l = ord_insert_elem(l, e);
}

void stampa(lista l){
    while(l != NULL){
        print(head(l));
        l = tail(l);
    }
}

carta* scala(lista carte, int&  lunghezza){
    lunghezza = 0;
    char s;
    carta* inizioScala = new carta;
    inizioScala = NULL;
    while(carte != NULL){
        if(lunghezza == 0){
            s = head(carte).seme;
            inizioScala = &(carte->inf);
            lunghezza++;
        }else{
            if(head(carte).seme == s){
                lunghezza++;
                if(lunghezza >= 3 && tail(carte) != NULL){
                    if(tail(carte)->inf.seme != s){
                        return inizioScala;
                    }
                }
                if(lunghezza < 3 && tail(carte) == NULL){
                    return NULL;
                }
            }else{
                lunghezza = 0;
            }
        }
        carte = tail(carte);
    }


    return inizioScala;
}

void stampaScala(lista carte, int lunghezza){
    while(carte!= NULL && lunghezza != 0){
        print(head(carte));
        carte = tail(carte);
        lunghezza--;
    }
}

int cala(lista& carte){
    int l = 0;
    int lunghezza;
    carta* primaScala = scala(carte, lunghezza);
    lista l1 = search(carte, *primaScala);
            while(l1 != NULL && lunghezza != 0){
                l += head(l1).valore;
                carte = delete_elem(carte, l1);
                l1 = tail(l1);
                lunghezza--;
            }

    return l;
}