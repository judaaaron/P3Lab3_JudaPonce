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
void simulacionRandom(int, int, char**&, int );
int main(int argc, char** argv) {
	int opcion;
	cout<<" Bienvenido al juego de la vida de conway!!"<<endl;
	cout<<" 1. Jugar con matriz Random: "<<endl;
	cout<<" 2. Jugar con matriz predefinida: "<<endl;
	cout<<" 3. Salir"<<endl;
	cin>>opcion;
	
	switch(opcion){
		case 1: {
			int fila,columna, turnos;
			cout<<" Ingrese tamaño x del tablero: "<<endl;
			cin>>fila;
			cout<<" Ingrese tamaño y del tablero: "<<endl;
			cin>>columna;
			cout<< " Ingrese cantidad de turnos: "<<endl;
			cin>>turnos;
			while(fila<=1){
				cout<<" El tamaño de las filas debe ser positivo y mayor que 1"<<endl;
				cout<<" Por favor ingrese un numero nuevo de filas: "<<endl;
				cin>>fila;
			}
			while(columna<=1){
				cout<<" El tamaño de las columnas debe ser positivo y mayor que 1"<<endl;
				cout<<" Por favor ingrese un numero nuevo de columnas: "<<endl;
				cin>>columna;
			}
			while(turnos<=1){
				cout<<" La cantidad de turnos debe ser positivo y mayor que 1"<<endl;
				cout<<" Por favor ingrese nueva cantidad de turnos: "<<endl;
				cin>>turnos;
			}
			char** matrizRandom = NULL;//instancia
			matrizRandom = crearMatrizRandom(fila);
			llenarMatrizRandom(fila,columna,matrizRandom);
			cout<<endl;
			simulacionRandom(fila,columna,matrizRandom, turnos);

			
			break;
		} 
		case 2: {
			
			
			break;
		}
		case 3: {
			exit(0);
			break;
		}
		 default:
           		cout<<"Opcion incorrecta";
                break;
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
	int randomX,RandomY;
	if(matrix != NULL){
		
		for(int i = 0; i < fila ; i++){
			for(int j = 0; j < columna; j++){
				if((i==0) || ( j ==columna-1) ||(i==fila-1) || (j ==0)){
					matrix[i][j]='#';
				}else{
				randomX = rand() % columna;
				if(randomX == 1){
					matrix[i][j] = '*';	
				}else{
					matrix[i][j] = ' ';	
				}
			}
			}
		}
 	imprimirMatrizRandom(fila,columna, matrix);
 	
 	}
}

void simulacionRandom(int fila, int columna, char**& matrix, int turno){

	
	int contadorVida=0;
	for(int i = 0; i < fila; i++){
		for(int j = 0; j < columna; j++){
		if(matrix[i][j] == '*'){
		if(matrix[i-1][j-1]=='*'){contadorVida++;}
		if(matrix[i-1][j]=='*'){contadorVida++;}
		if(matrix[i-1][j+1]=='*'){contadorVida++;}
///medio
		if(matrix[i][j-1]=='*'){contadorVida++;}
		if(matrix[i][j+1]=='*'){contadorVida++;}
///abajo
		if(matrix[i+1][j-1]=='*'){contadorVida++;}
		if(matrix[i+1][j]=='*'){contadorVida++;}
		if(matrix[i+1][j+1]=='*'){contadorVida++;}
		
		if(contadorVida<2||contadorVida>3)
			{matrix[i][j]=' ';}
		else if(contadorVida==2||contadorVida==3)
			{matrix[i][j]='*';}	

		}
	
	}
	
	}
	imprimirMatrizRandom(fila,columna, matrix);

	
}
	
	

