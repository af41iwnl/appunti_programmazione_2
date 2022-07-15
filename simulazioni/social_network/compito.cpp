#include <iostream>
#include <cstring>
#include <fstream>

#include "coda.h"
#include "node.h"
#include "grafi.h"

graph prendiGrafo();
node* prendiNode(int dim);
void stampa(graph g, node* n);
int*  totalLike(graph g , node* n);
void stampaLike(int dim, node* n, int* totLike);
void follow(graph g, node* n, int u);

using namespace std;
int main(){
    
    graph g = prendiGrafo();

    node* n = prendiNode(get_dim(g));

    
    cout<<"Stampa social network:"<<endl;
    stampa(g, n);

    int* totLike = totalLike(g, n);
    cout<<"Utenti con maggior numero di like:"<<endl;
    stampaLike(get_dim(g), n, totLike);

    int f;
    do{
        cout<<"inserire nodo per scoprire le gerarchie di follow:"<<endl;
        cin>>f;
    }while(f <= 0 || f > get_dim(g));
    
    
    follow(g, n, f);
    return 0;
}

graph prendiGrafo(){
    ifstream f;
    f.open("graph");
    int a,b;
    f>>a;
    graph g = new_graph(a);
    while(f>>a){
        f>>b;
        add_arc(g, a, b, 0);
    }
    f.close();
    return g;
}

node* prendiNode(int dim){
    node* n = new node[dim];
    ifstream f;
    f.open("node");
    string s;
    node i;
    int cont = 0;
    while(getline(f, s)){
        strcpy(i.cont, s.c_str());
        getline(f, s);
        i.tipo = s[0];
        n[cont] = i;
        cont++;
    }
    f.close();
    return n;
}

void stampa(graph g, node* n){
    for(int i=1; i<=get_dim(g); i++){
        adj_list l = get_adjlist(g, i);
        while(l != NULL){
            if(n[i-1].tipo == 'U' && n[l->node].tipo == 'U'){
                cout<<" "<<n[i-1].cont<<" \t\t\t FOLLOW "<<n[l->node].cont<<endl;
            }else if(n[i-1].tipo == 'T' && n[l->node].tipo == 'U'){
                cout<<" "<<n[i-1].cont<<" \t\t\t OWNER "<<n[l->node].cont<<endl;
            }else if(n[i-1].tipo == 'U' && n[l->node].tipo == 'T'){
                cout<<" "<<n[i-1].cont<<" \t\t\t LIKE "<<n[l->node].cont<<endl;
            }
            l = l->next;
        }
        cout<<endl;
    }
}

int*  totalLike(graph g , node* n){
    int* tweetLike = new int[get_dim(g)];
    int* totLike = new int[get_dim(g)];
    for(int i=0; i<get_dim(g); i++){
        tweetLike[i] = 0;
        totLike[i] = 0;
    }

    for(int i=1; i<=get_dim(g); i++){
        adj_list l = get_adjlist(g, i);
        while(l != NULL){
            if(n[i-1].tipo == 'U' && n[l->node].tipo == 'T'){
                tweetLike[l->node]++;
            }
            l = l->next;
        }
    }

    for(int i=1; i<=get_dim(g); i++){
        adj_list l = get_adjlist(g, i);
        while(l != NULL){
            if(n[i-1].tipo == 'T' && n[l->node].tipo == 'U'){
                totLike[l->node] += tweetLike[i-1];
            }
            l = l->next;
        }
    }

    return totLike;
}

void stampaLike(int dim, node* n, int* totLike){
    int max = 0;
    for(int i=0; i<dim; i++){
        if(totLike[i] >= max){
            max = totLike[i];
        }
    }

    for(int i=0; i<dim; i++){
        if(totLike[i] == max){
            cout<<n[i].cont<<endl;
            
        }
    }
}

void follow(graph g, node* n, int u){
    coda c = newQueue();
    bool visited[get_dim(g)];
    for(int i=0; i<get_dim(g); i++){
        visited[i] = false;
    }

    visited[u-1] = true;
    c = enqueue(c, u);
    while(!isEmpty(c)){
        int v = dequeue(c);
        adj_list adj = get_adjlist(g,v);
        while(adj != NULL){
            if((visited[adj->node] == false) && (n[adj->node].tipo == 'U')){
                visited[adj->node] = true;
                c = enqueue(c, adj->node+1);  
                cout<<n[adj->node].cont<<endl;
            }
            adj = adj->next;
        }
    }
    cout<<endl;
}