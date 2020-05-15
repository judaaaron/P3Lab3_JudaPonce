#include <iostream>
#include<cstdlib>
#include <ctime>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
char** crearMatrizRandom(int);
void imprimirMatrizRandom(int,int, char**);
void llenarMatrizRandom(int, int, char**&);
int main(int argc, char** argv) {
	int opcion;
	cout<<" Bienvenido al juego de la vida de conway!!"<<endl;
	cout<<" 1. Jugar con matriz Random: "<<endl;
	cout<<" 2. Jugar con matriz predefinida: "<<endl;
	cin>>opcion;
	
	switch(opcion){
		case 1: {
			int fila,columna;
			cout<<" Ingrese tamaño x del tablero: "<<endl;
			cin>>fila;
			cout<<" Ingrese tamaño y del tablero: "<<endl;
			cin>>columna;
			char** matrizRandom = NULL;//instancia
			matrizRandom = crearMatrizRandom(fila);
			llenarMatrizRandom(fila,columna,matrizRandom);
			//imprimirMatrizRandom(fila,columna,matrizRandom);
			
			break;
		} 
		case 2: {
			
			
			break;
		}
	}
	
	
	return 0;
}


char** crearMatrizRandom(int size){
	
	char** matriz = NULL;//instancia
	
	matriz = new char*[size];
	
	for(int i = 0; i < size; i++){
		matriz[i] = new char[size];
	}
	
	return matriz;
}

void imprimirMatrizRandom(int fila, int columna, char** matriz){
	if(matriz != NULL){
	
		for(int i = 0; i < fila; i++){
			for(int j = 0; j < columna; j++){
				if(i==0 || j==0 || i==fila-1 || j==columna-1){
				cout << "[" << matriz[i][j] << "]";
				}
				else{
						cout<<" "<< matriz[i][j]<<" ";
				}
			}
			cout << endl;
		}
	}
	
}

void llenarMatrizRandom(int fila, int columna, char**& matrix){
	if(matrix != NULL){
	
		for(int i = 0; i < fila ; i++){
			for(int j = 0; j < columna; j++){
				if(i==0 || j==0 || i==fila-1 || j==columna-1){
						matrix[i][j]='#';
				}else{
					matrix[i][j]='*';
					
				}
			
			}
			cout << endl;
		}
	}
	imprimirMatrizRandom(fila,columna, matrix);
	
}
