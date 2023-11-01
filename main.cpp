#include <iostream>
#include <fstream>

using namespace std;

struct competidores
{
    int nro_competidor;
    string nombre;
    int categoria;
    int sub_categoria;
    int tiro_centro;
    int tiro_no_centro;
};

void definir_nro_competidores(int &nro);
void cargar_datos_estructura(competidores competidor[], int &nro);
void mostrar_nombres(competidores competidor[], int &nro);

int main(){
    int nro = 0;
    definir_nro_competidores(nro);

    competidores competidor[nro];
    cargar_datos_estructura(competidor, nro);

    mostrar_nombres(competidor, nro);

    return 0;
}

void definir_nro_competidores(int &nro){
    string test;
    ifstream competidores("competidores.txt");
    
    if(!competidores.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while(!competidores.eof()){
        competidores >> test;
        competidores >> test;
        competidores >> test;
        competidores >> test;
        competidores >> test;
        competidores >> test;
        nro++;
    }
}

void cargar_datos_estructura(competidores competidor[], int &nro){
    ifstream competidores("competidores.txt");
    
    if(!competidores.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    while (!competidores.eof())
    {
        competidores >> competidor[nro].nro_competidor;
        competidores >> competidor[nro].nombre;
        competidores >> competidor[nro].categoria;
        competidores >> competidor[nro].sub_categoria;
        competidores >> competidor[nro].tiro_centro;
        competidores >> competidor[nro].tiro_no_centro;
        nro++;
    }
}

void mostrar_nombres(competidores competidor[], int &nro){
    for (int i = 0; i < nro; i++) {
        cout << competidor[i].nombre << endl;
    }
}
