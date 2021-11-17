/*
*  autor: Jordana Betancourt Menchaca A01707434
*  fecha: 11 de noviembre de 2021
*
*  Grafos para rutas en municipios de Guanajuato
*/

#ifndef Grafo_H_
#define Grafo_H_

#include <bits/stdc++.h>
#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

class Grafo{
    private:
    int edgesList;
	int edgesMat;
	int nodes;
    vector<string> municipios;
    vector <pair<int, float> > *adjList;

    public:
	
    Grafo(int);
    void addEdge(int u,int v, float distancia);
    void printGrafo();
    void creaMunicipios();
	void creaEdges();
    void imprimeMunicipios();
    //BFS
	string BFS(int, int);
	void bfsHelper(int, int, queue<int>&, list<int>&, vector<vector<int>>&,std::stringstream &aux,float suma);
	//Print
	string print_path(vector<vector<int>>&,int ,int);
    bool contains(list<int>, int);

 
};

/*
 * Grafo
 *
 * @param int n
 * @return Grafo
 * 
*/
Grafo:: Grafo(int n) {
	nodes = n;
	adjList = new vector<pair<int,float> >[n];
	edgesList = edgesMat = 0;
}

/*
 * creaMunicipios
 *
 * @param 
 * @return void
 * 
*/
void Grafo :: creaMunicipios(){
    municipios.push_back("Guanajuato");
    municipios.push_back("San Felipe");
    municipios.push_back("León");
    municipios.push_back("Silao");
    municipios.push_back("Romita");
    municipios.push_back("Irapuato");
    municipios.push_back("Abasolo");
    municipios.push_back("Salamanca");
    municipios.push_back("Dolores Hidalgo");
    municipios.push_back("San Miguel de Allende");
}


/*
 * creaEdges
 *
 * @param 
 * @return void
 * 
*/
void Grafo :: creaEdges(){
	//Guanajuato-San Felipe
    addEdge(0, 1,83.7);

    //Guanajuato-León
    addEdge(0, 2, 75);

    //Guanajuato-Silao
    addEdge(0, 3, 41.4);
    
    //Guanajuato-Irapuato
    addEdge(0, 5, 68.3);

    //Guanajuato-Salamanca
    addEdge(0, 7, 68.6);

    //Guanajuato-Dolores Hidalgo
    addEdge(0, 8, 60.2);

    //San Felipe-León
    addEdge(1, 2, 95.3);

    //Léon-Silao
    addEdge(2, 3, 43.9);

    //Silao-Romita
    addEdge(3, 4, 13.8);

    //Silao-Irapuato
    addEdge(3, 5, 40);

    //Irapuato-Abasolo
    addEdge(5, 6, 33.1);

    //Irapuato-Salamanca
    addEdge(5, 7, 22.4);

    //Dolores Hidalgo-San Miguel de Allende
    addEdge(8, 9, 40.5);
}

/*
 * imprimeMunicipios
 *
 * @param 
 * @return void
 * 
*/
void Grafo :: imprimeMunicipios(){
    cout<<"\nLISTA DE MUNICIPIOS REGISTADOS\n";

    int tam = municipios.size();
    for(int i=0 ; i <  tam; i++){
        cout<<i<<". "<<municipios[i]<<endl;
    }
}


/*
 * addEdge
 *
 * @param int,int,float 
 * @return void
 * 
*/
void Grafo :: addEdge(int u,int v, float distancia)
{
    adjList[u].push_back(make_pair(v, distancia));
    adjList[v].push_back(make_pair(u,distancia));
}
 
// Imprime una lista de adyacencia de un grafo
/*
 * printGrafo
 *
 * @param 
 * @return void
 * 
*/
void Grafo :: printGrafo()
{
    int v;
    float km;
    for (int u = 0; u < nodes; u++)
    {
        cout << "Municipio: " << municipios[u] << " tiene un arco con \n";
        for (auto it = adjList[u].begin(); it!=adjList[u].end(); it++)
        {
            v = it->first;
            km = it->second;
            cout << "\tMunicipio " << municipios[v] << " con distancia de = "
                 << km << "km\n";
        }
        cout << "\n";
    }
}


/*
 * BFS
 *
 * @param int,int
 * @return string
 * 
*/
string Grafo::BFS(int start, int goal){
	std::stringstream aux;
	queue <int> qu;
	list <int> visited;
    vector <vector<int>> paths(nodes, vector<int>(0));
    float suma = 0;
	qu.push(start);
 	bfsHelper(start, goal, qu, visited, paths,aux,suma);
	aux << " ";
	aux << print_path(paths, start, goal)<<endl;
	return aux.str();
}

/*
 * bfsHelper
 *
 * @param int,int,vector,vector,vector<vector>,stringstream
 * @return 
 * 
*/
void Grafo::bfsHelper(int current,
	int goal,
	queue<int> &qu,
	list<int> &visited,
	vector<vector<int>> &paths,
	std::stringstream &aux,
    float suma){
    
		//Si el actual es al que quiero llegar imprimo todos los nodos visitados
		if(current == goal){
            return;
			//aux << print_visited(visited);
		//Si está vacío no hay nodos
		} else if(qu.empty()){
			aux << "Nodo no encontrado";
		//De otra forma
		}	else {
			//.front() Devuelve la referencia del siguiente nodo de la lista
			current = qu.front();
			// .pop() elimina el elemento siguiente de la lista
			qu.pop();
			//Se agrega el siguiente elemento como ya visitado
			visited.push_back(current);
			//Recorremos toda la lista de nodos hasta el current size
			for(int  i = 0; i < adjList[current].size(); i++)
			//Si no está en visitado lo agregamos al queue
				if(!contains(visited, adjList[current][i].first)){
					qu.push(adjList[current][i].first);
				//Agrego al path como llegué a ese número
					paths[adjList[current][i].first].push_back(current);
				}
			bfsHelper(current, goal, qu, visited, paths,aux,suma);
		}

    }


/*
 * print_path
 *
 * @param vector<vector>,int,int,stringstream
 * @return string
 * 
*/
string Grafo::print_path(vector<vector <int>> &path, int start, int goal){
	//Declaramos algunas variables
	std::stringstream aux;
	float suma;
	int actual;
	int siguiente;
	int node =  path[goal][0];
	stack<int> reverse;
	//Metemos al stack el municipio al que se quiere llegar
	reverse.push(goal);
	aux << "Ruta más rápida de "<<municipios[start]<< " a "<<municipios[goal];
    aux<<": "<<endl;

	//Mientras el nodo sea distinto al municipio de origen se añaden al stack
	while (node != start) {
		reverse.push(node);
    node = path[node][0];
 	}

	//Se añade al stack el minicipio de inicio
	reverse.push(start);

	//Mientras el tamaño del stack sea mayor a 1
	while (reverse.size() > 1) {
        
		//Imprimos el que se encuentra en el top del stack
		aux << " " << reverse.top()<<". ";
        aux << municipios[reverse.top()]<<endl;

		//Lo guardamos como el actual
		actual = reverse.top();
		//Lo eliminamos del stack
		reverse.pop();
		//Se toma como siguiente el nuevo top
		siguiente = reverse.top();

    	for (int u = 0; u < nodes; u++)
		{			
			for (auto it = adjList[u].begin(); it!=adjList[u].end(); it++)
			{
				/*Si u es en la lista de adyacencia es igual al la lista de
				adyacencia con nodo actual y el iterador en primero es igual
				al siguiente nodo en el stack*/
				if(adjList[u] == adjList[actual] && it->first == siguiente)
					//Se suma la distancia de ese iterador
					suma = suma + it->second;
				
			}
			
		}
		
  	}
//Se agrega al aux el municipio destino y la suma de la distancia del recorrido
  aux << " " << siguiente <<". ";
  aux << municipios[goal]<<endl;
  aux<<" Con un recorrido total de: "<<suma<<" kilometros"<<endl;

  return aux.str();
}

/*
 * contains
 *
 * @param list,int
 * @return bool
 * 
*/
bool Grafo::contains(list<int> ls, int node){
		list<int>::iterator it;
		it = find(ls.begin(), ls.end(), node);
		if(it != ls.end())
			return true;
		else
			return false;
}

#endif /* Grafo_H_ */