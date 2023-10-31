#include <iostream>
#include <fstream>

using namespace std;

void mostrarCompetidores(string &nombre);

int main(){
    string nombre;

    mostrarCompetidores(nombre);

    return 0;
}

void mostrarCompetidores(string &nombre){
    ifstream competidores("nombres.txt");
    if(!competidores.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    // mostrar los nombres de los competidores con un vector
    while(getline(competidores, nombre)){
        cout << nombre << endl;
    }
    competidores.close();
}