#include <iostream>
#include "tipo.h"

using namespace std;

int compare(tipo_inf a, tipo_inf b){
    if(a.seme == b.seme && a.valore == b.valore){
        return 0;
    }else if(a.seme == b.seme){
        return a.valore - b.valore;
    }else if(a.valore == b.valore){
        return a.seme - b.seme;
    }

    return ((a.seme+a.valore)-(b.seme+b.valore));
}
void copy(tipo_inf& dest, tipo_inf src){
    dest.seme = src.seme;
    dest.valore = src.valore;
}

void print(tipo_inf t){
    cout<<t.valore<<t.seme<<" ";
}