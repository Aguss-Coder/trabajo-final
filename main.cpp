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
void calcular_puntaje(competidores competidor[], competidoresConMasPuntos competidoresConPuntos[], int nro);
void cargar_datos_nueva_estructura_ordenada(competidores competidor[], competidoresConMasPuntos competidorGanador[], int nro);
void sort_competitors(competidoresConMasPuntos competidorGanador[], int nro);
void crear_archivo(competidoresConMasPuntos competidorGanador[], int nro);
void cantidad_de_competidores_por_categoria(competidores competidor[], int nro);
void cantidad_de_competidores_que_superan_un_umbral_de_puntos(competidoresConMasPuntos competidor[], int nro);

int main(){
    int nro = 0;
    nro = definir_nro_competidores(nro);

    competidores competidor[nro];
    cargar_datos_estructura(competidor, nro);

    cout << "Los competidores son: " << endl;

    mostrar_nombres(competidor, nro);

    competidoresConMasPuntos competidorGanador[nro];
    
    calcular_puntaje(competidor, competidorGanador, nro);
    cargar_datos_nueva_estructura_ordenada(competidor, competidorGanador, nro);
    sort_competitors(competidorGanador, nro);

    crear_archivo(competidorGanador, nro);
    cantidad_de_competidores_que_superan_un_umbral_de_puntos(competidorGanador, nro);

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

void calcular_puntaje(competidores competidor[], competidoresConMasPuntos competidorConPuntos[], int nro){
    int puntaje = 0;
    for (int i = 0; i < nro; i++)
    {
        puntaje = (competidor[i].tiro_centro * 10) + (competidor[i].tiro_no_centro * 5); 
        competidorConPuntos[i].puntaje = puntaje;
    }
    
}

void cargar_datos_nueva_estructura_ordenada(competidores competidor[], competidoresConMasPuntos competidorNuevo[], int nro){
    for(int i = 0; i < nro; i++){
        competidorNuevo[i].nro_competidor = competidor[i].nro_competidor;
        competidorNuevo[i].nombre = competidor[i].nombre;
        competidorNuevo[i].categoria = competidor[i].categoria;
        competidorNuevo[i].sub_categoria = competidor[i].sub_categoria;
        competidorNuevo[i].tiro_centro = competidor[i].tiro_centro;
        competidorNuevo[i].tiro_no_centro = competidor[i].tiro_no_centro;
    }
}

void sort_competitors(competidoresConMasPuntos competidorGanador[], int nro) {
    for(int i = 0; i < nro - 1; i++) {
        for(int j = 0; j < nro - i - 1; j++) {
            if(competidorGanador[j].puntaje < competidorGanador[j + 1].puntaje) {
                competidoresConMasPuntos temp = competidorGanador[j];
                competidorGanador[j] = competidorGanador[j + 1];
                competidorGanador[j + 1] = temp;
            }
        }
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

void cantidad_de_competidores_por_categoria_y_subcategoria(competidores competidor[], int nro){

}
void cantidad_de_competidores_que_superan_un_umbral_de_puntos(competidoresConMasPuntos competidor[], int nro){
    cout << "Ingrese el umbral de puntos: ";
    int umbral = 0;
    cin >> umbral;
    int contador = 0;
    for (int i = 0; i < nro; i++)
    {
        if (competidor[i].puntaje >= umbral)
        {
            contador++;
        }
    }
    cout << "La cantidad de competidores que superan el umbral de puntos es: " << contador << endl;
}
