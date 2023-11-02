#include <iostream>
#include <fstream>

using namespace std;

struct competidoresConMasPuntos
{
    int nro_competidor;
    string nombre;
    int categoria;
    int sub_categoria;
    int tiro_centro;
    int tiro_no_centro;
    int puntaje;
};


struct competidores
{
    int nro_competidor;
    string nombre;
    int categoria;
    int sub_categoria;
    int tiro_centro;
    int tiro_no_centro;
};

int definir_nro_competidores(int nro);
void cargar_datos_estructura(competidores competidor[], int nro);
void mostrar_nombres(competidores competidor[], int &nro);
void calcular_puntaje(competidores competidor[], int nro, int &puntaje);
void ordenar_puntaje(competidores competidor[], int nro);
void cargar_datos_nueva_estructura(competidores competidor[], competidoresConMasPuntos competidorGanador[], int nro, int puntaje);
void crear_archivo(competidoresConMasPuntos competidorGanador[], int nro);

int main(){
    int nro = 0;
    nro = definir_nro_competidores(nro);

    competidores competidor[nro];
    cargar_datos_estructura(competidor, nro);

    cout << "Los competidores son: " << endl;

    mostrar_nombres(competidor, nro);

    int puntaje = 0;

    calcular_puntaje(competidor, nro, puntaje);
    ordenar_puntaje(competidor, nro);
    
    competidoresConMasPuntos competidorGanador[nro];
    cargar_datos_nueva_estructura(competidor, competidorGanador, nro, puntaje);

    crear_archivo(competidorGanador, nro);

    return 0;
}

int definir_nro_competidores(int nro){
    string test;
    ifstream competidores("competidores.txt");
    
    if(!competidores.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
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
    
    return nro;
}

void cargar_datos_estructura(competidores competidor[], int nro){
    ifstream competidores("competidores.txt");
    
    if(!competidores.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    nro = 0;

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

void calcular_puntaje(competidores competidor[], int nro, int &puntaje){
    // code
}

void ordenar_puntaje(competidores competidor[], int nro){
    // code
}

void cargar_datos_nueva_estructura(competidores competidor[], competidoresConMasPuntos competidorNuevo[], int nro, int puntaje){
    for(int i = 0; i < nro; i++){
        competidorNuevo[i].nro_competidor = competidor[i].nro_competidor;
        competidorNuevo[i].nombre = competidor[i].nombre;
        competidorNuevo[i].categoria = competidor[i].categoria;
        competidorNuevo[i].sub_categoria = competidor[i].sub_categoria;
        competidorNuevo[i].tiro_centro = competidor[i].tiro_centro;
        competidorNuevo[i].tiro_no_centro = competidor[i].tiro_no_centro;
        competidorNuevo[i].puntaje = puntaje;
    }
}

void crear_archivo(competidoresConMasPuntos competidor[], int nro){
    ofstream jugadoresConMasPuntos("resultados.txt");

    if(!jugadoresConMasPuntos.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    for (int i = 0; i < nro; i++) {
        jugadoresConMasPuntos << competidor[i].nro_competidor << " ";
        jugadoresConMasPuntos << competidor[i].nombre << " ";
        jugadoresConMasPuntos << competidor[i].categoria << " ";
        jugadoresConMasPuntos << competidor[i].sub_categoria << " ";
        jugadoresConMasPuntos << competidor[i].tiro_centro << " ";
        jugadoresConMasPuntos << competidor[i].tiro_no_centro << " ";
        jugadoresConMasPuntos << competidor[i].puntaje << endl;
    }
}
