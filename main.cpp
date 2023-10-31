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

void definirNroCompetidores(int &nro);
void cargarDatosEstructura(competidores competidor[], int &nro);

int main(){
    int nro = 0;

    definirNroCompetidores(nro);

    competidores competidor[nro];

    cargarDatosEstructura(competidor, nro);

    return 0;
}

void definirNroCompetidores(int &nro){
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

void cargarDatosEstructura(competidores competidor[], int &nro){
    ifstream competidores("competidores.txt");
    
    if(!competidores.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    for (int i = 0; i < nro; i++)
    {
        while(!competidores.eof()){
        competidores >> competidor[i].nro_competidor;
        nro++;
        competidores >> competidor[i].nombre;
        competidores >> competidor[i].categoria;
        competidores >> competidor[i].sub_categoria;
        competidores >> competidor[i].tiro_centro;
        competidores >> competidor[i].tiro_no_centro;
    }
    }
    
}