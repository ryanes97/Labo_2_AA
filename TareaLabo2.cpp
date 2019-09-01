#include <iostream>
#include <cstdlib>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
}*inicio;

struct Nodo2{
    int dato;
    Nodo2 *sig;
}*inicio2,*fin;

class Cola{
    public:
        Nodo2* crearNodo(int valor){
            Nodo2 *n = new Nodo2;
            n->dato = valor;
            n->sig = nullptr;
            return n;
        }
        
        void push(int valor){
            Nodo2 *n = crearNodo(valor);
            if(!inicio2){
                inicio2 = n;
                fin = n;
            }else{
                fin->sig = n;
                fin = n;
            }
        }
        
        void pop(){
            Nodo2 *temp = inicio2;
            inicio2 = inicio2->sig;
            free(temp);
        }
        
        void mostrarCola(){
            Nodo2 *temp = inicio2;
            if(!inicio2)
                cout<<"Cola vacia"<<endl;
            else
                while(temp){
                    cout<<temp->dato<<", ";
                    temp = temp->sig;
                }
            cout<<endl;
        }
};

class Pila{
    public:
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig = nullptr;
            return n;
        }
        
        void push(int valor){
            Nodo *n = crearNodo(valor);
            n->sig = inicio;
            inicio = n;
        }
        
        void pop(){
            Nodo *temp = inicio;
            inicio = inicio->sig;
            free(temp);
        }
        
        void mostrarPila(){
            Nodo *temp = inicio;
            if(!inicio)
                cout<<"Pila vacia"<<endl;
            else
                while(temp){
                    cout<<temp->dato<<", ";
                    temp = temp->sig;
                }
        }
};

void invertirCola(Cola n, Pila i){
    Nodo2 *temp = inicio2;
    if(!inicio2)
        cout<<"Cola vacia"<<endl;
    else
        while(temp){
            i.push(temp->dato);
            temp = temp->sig;
        }
    i.mostrarPila();
}

int main(int argc, char** argv) {
    
    Cola l;
    Pila p;
    
    l.push(1);
    l.push(2);
    l.push(3);
    
    l.mostrarCola();
    invertirCola(l,p);
    

    return 0;
}

