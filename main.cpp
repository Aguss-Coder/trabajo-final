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
void mostrar_competidores(competidores competidor[], int &nro);
void calcular_puntaje(competidores competidor[], competidoresConMasPuntos competidorConPuntos[], int nro);
void cargar_datos_nueva_estructura_ordenada(competidores competidor[], competidoresConMasPuntos competidorNuevo[], int nro);
void ordenar_competidores(competidoresConMasPuntos competidorGanador[], int nro);
void crear_archivo(competidoresConMasPuntos competidor[], int nro);
void mostrar_competidores_con_mas_puntos(competidoresConMasPuntos competidor[], int &nro);
void saber_competidores_por_categoria_y_subcategoria(competidores competidor[],  int nro);
void saber_competidores_arriba_del_umbral(competidoresConMasPuntos competidor[], int nro);

int main() {
    int nro = 0;
    nro = definir_nro_competidores(nro);

    competidores competidor[nro];
    cargar_datos_estructura(competidor, nro);

    competidoresConMasPuntos competidorConMasPuntos[nro];
    calcular_puntaje(competidor, competidorConMasPuntos, nro);
    cargar_datos_nueva_estructura_ordenada(competidor, competidorConMasPuntos, nro);
    ordenar_competidores(competidorConMasPuntos, nro);
    crear_archivo(competidorConMasPuntos, nro);
    
    int opcion;

    while (opcion != 5) {
        cout << "Seleccione una opción: " << endl;
        cout << endl;
        cout << "1. Mostrar competidores" << endl;
        cout << "2. Mostrar competidores con más puntos" << endl;
        cout << "3. Mostrar competidores que superan un umbral" << endl;
        cout << "4. Mostrar competidores por categoría y subcategoría" << endl;
        cout << "5. Salir" << endl;
        cout << endl;

        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
        case 1: {
            cout << "Los competidores son:" << endl;
            mostrar_competidores(competidor, nro);
            cout << endl;
        }break;
        case 2: {
            cout << "Los competidores con más puntos son:" << endl;
            cout << endl;
            mostrar_competidores_con_mas_puntos(competidorConMasPuntos, nro);
            cout << endl;
        }break;
        case 3: {
            saber_competidores_arriba_del_umbral(competidorConMasPuntos, nro);
            cout << endl;
        }break;
        case 4: {
            saber_competidores_por_categoria_y_subcategoria(competidor, nro);
            cout << endl;
        }break;
        case 5:
            cout << "Programa finalizado con exito" << endl;
            break;
        default:
            cout << "Opción inválida" << endl;
            cout << endl;
            break;
        }
    }
    
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

void mostrar_competidores(competidores competidor[], int &nro){
    for (int i = 0; i < nro; i++) {
        cout << competidor[i].nombre << endl;
    }
}

void mostrar_competidores_con_mas_puntos(competidoresConMasPuntos competidor[], int &nro){
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

void ordenar_competidores(competidoresConMasPuntos competidorGanador[], int nro) {
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

void saber_competidores_por_categoria_y_subcategoria(competidores competidor[],  int nro){
    int matriz[3][3] = {0};
    for (int i = 0; i < nro; i++)
    {
        matriz[competidor[i].categoria ][competidor[i].sub_categoria ]++;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Categoria " << i << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Subcategoria " << j << ": " << matriz[i][j] << endl;
        }
    }
    

}

void saber_competidores_arriba_del_umbral(competidoresConMasPuntos competidor[], int nro){
    cout << "Ingrese el umbral de puntos: ";
    int umbral = 0;
    cin >> umbral;
    int contador = 0;
    for (int i = 0; i < nro; i++)
    {
        if (competidor[i].puntaje > umbral)
        {
            contador++;
        }
    }
    cout << "La cantidad de competidores que superan el umbral de puntos es: " << contador << endl;
}
