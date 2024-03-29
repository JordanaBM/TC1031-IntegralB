/*
 * main.cpp
 *
 *  Created on: 11 de noviembre de 2021
 *      Author: Jordana Betancourt Menchaca
 * 
 * Integral B. Crea un grafo con varios municipios del Estado de Guanajuato, 
 * permite encontrar el trayecto más corto entre dos ciudades y visualizar
 * todas las conexiones de carreteras entre municipios, incluyendo una opción 
 * donde muestra las distancias entre municipios de mayor a menor y otra 
 * alfabéticamente.
 */

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "grafos.h"

using namespace std;

int main() {

    int opcion,partida, llegada;

    cout<<"\nEncuentra tu trayecto más corto en municipios de Guanajuato"<<endl;
    
    Grafo gto(10); //Creo un grafo de 10 nodos
    gto.creaMunicipios(); //Llamo a la función para inicializar municipios
    gto.creaEdges(); //Creo las conexiones entre municipios
    gto.imprimeMunicipios(); //Imprimo los municipios registrados
    cout<<endl;

    cout<<"------------------------------------------"<<endl;
    cout<<"----------------Ejemplos------------------"<<endl;
    cout<<"------------------------------------------"<<endl;

    //----------Buscar rutas más rápidas----------
    //Guanajuato a San Miguel de Allende
    cout<<gto.BFS(0,9);

    //León a Salamanca
    cout<<gto.BFS(2,7);


    do //Menú de opciones
	{
		cout<<"\n===========Menú=============\n"<<endl;
		cout<<"1. Encuentra el trayecto más rápido\n";
        cout<<"2. Visualiza las trayectorias entre municipios\n";
        cout<<"3. Visualiza las trayectorias ordenadas por menor kilometraje\n";
        cout<<"4. Visualiza las trayectorias ordenadas por ciudades Alfabéticamente\n";
		cout<<"5. Salir\n";
        cout<<"Ingrese la opción que desea: ";
        cin>>opcion;

        switch (opcion)
		{
        //Caso 1: Encuentra trayectoria
			case 1:
            cout<<"\n========================================="<<endl;
			cout<<"=======Trayectorias rápidas============="<<endl;
            cout<<"========================================="<<endl;
            gto.imprimeMunicipios();
            cout<<endl;
			cout<<"Ingresa la ciudad de origen con su índice correspondiente: ";
            cin>>partida;
            cout<<"Ingresa la ciudad de destino con su índice correspondiente: ";
            cin>>llegada;
            cout<<endl;
            cout<<gto.BFS(partida,llegada);
			break;

        //Caso 2: Visualizar los arcos entre ciudades
            case 2:
            cout<<"\n============================================"<<endl;
			cout<<"=======Trayectos entre ciudades============="<<endl;
            cout<<"============================================"<<endl;
            gto.printGrafo();
			break;

        //Caso 3: Visualizar los arcos entre ciudades de menor a mayor distancia
            case 3:
            cout<<"\n===================================================================="<<endl;
			cout<<"=======Trayectos con menor kilometraje entre municipios============="<<endl;
            cout<<"===================================================================="<<endl;
            gto.ciudadesMenosDist();
			break;

        //Caso 4: Visualizar los arcos entre ciudades ordenadas alfabéticamente
            case 4:
            cout<<"\n================================================================"<<endl;
			cout<<"=======Trayectos alfabéticamente de los municipios============="<<endl;
            cout<<"================================================================"<<endl;
            gto.ciudadesAlfabeticamente();
			break;
        
        }

    }while (opcion != 5);

    return 0;
}    
