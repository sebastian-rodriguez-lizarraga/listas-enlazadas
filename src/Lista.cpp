#include "Lista.h"

Lista::Lista(): prim(nullptr), ult(nullptr) {}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    destruirNodos();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Completar
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    if(prim == nullptr){
        prim = nuevo;
        ult = nuevo;
    }
    else{
        nuevo->siguiente = prim;
        nuevo->anterior = nullptr;
        prim = nuevo;
    }


}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    if(prim == nullptr){
        prim = nuevo;
        ult = nuevo;
    }
    else{
        ult->siguiente = nuevo;
        nuevo->anterior = ult;
        nuevo->siguiente = nullptr;
        ult = nuevo;
    }
}

// Pre 0<= i < longitud(l)
 void Lista::eliminar(Nat i) {
    if(i == 0 && longitud() == 1){
        Nodo* aBorrar = prim;
        prim = nullptr;
        ult  = nullptr;
        delete aBorrar;
    }
    else if(i == 0){
        Nodo* aBorrar = prim;
        prim = prim->siguiente;
        prim->anterior = nullptr;
        delete aBorrar;
    }
    else if(i == longitud()-1){
        Nodo* aBorrar = ult;
        ult = ult->anterior;
        ult->siguiente = nullptr;
        delete aBorrar;
    }  //hasta aca testee que anden para los casos en que borro el primero y el ultimo elemento, el tema es en el medio.
    else{
        Nodo* aBorrar = prim;
        Nodo* anterior = prim;
        Nodo* siguiente = prim;
        for (int j = 0; j < i; ++j) {
            anterior = aBorrar;
            aBorrar = aBorrar->siguiente;
            siguiente = aBorrar -> siguiente;
        }
        siguiente->anterior = anterior;
        anterior->siguiente  = siguiente;
        delete aBorrar;
    }

}

int Lista::longitud() const {
    int i = 0;
    if (prim == nullptr){
        return i;
    }
    else{
        Nodo* actual = prim;
        while(actual != nullptr){
            actual = actual->siguiente;
            i++;
        }
     }
     return i;
}
// este es para lo de copia
const int& Lista::iesimo(Nat i) const {
    Nodo* actual = prim;
    for(int j = 0; j<i;j++){
        actual = actual->siguiente;
    }
    return actual->valor;
}

int& Lista::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo* actual = prim;
    for(int j = 0; j<i;j++){
        actual = actual->siguiente;
    }
    return actual->valor;
    //assert(false);
}

void Lista::mostrar(ostream& o) {
    Nodo* actual = prim;
    o << "[";
    while (actual != nullptr){
        if (actual->siguiente != nullptr){
            o << actual->valor << "," ;
        }
    }
    o << "]";
}

//aux


void Lista::destruirNodos(){
    Nodo* actual = prim;
    while(actual != nullptr){
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    prim = nullptr;
}

void Lista::copiarNodos(const Lista &a) {
    Nodo* actual =  a.prim; //preguntar porque va el punto y no va "->"
    for (int i = 0; i < a.longitud() ; ++i) {
        agregarAtras(actual->valor);
        actual = actual->siguiente;
    }
}



