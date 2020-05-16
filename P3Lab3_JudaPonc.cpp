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
void borrarMatriz(int size, char**& matriz);
int menu();
int main(int argc, char** argv) {
int opcion;
	opcion=menu();
	
	switch(opcion){
		case 1: {
			int fila,columna, turnos, option;
			cout<<" Ingrese tama�o x del tablero: "<<endl;
			cin>>fila;
			cout<<" Ingrese tama�o y del tablero: "<<endl;
			cin>>columna;
			cout<< " Ingrese cantidad de turnos: "<<endl;
			cin>>turnos;
			while(fila<=1){
				cout<<" El tama�o de las filas debe ser positivo y mayor que 1"<<endl;
				cout<<" Por favor ingrese un numero nuevo de filas: "<<endl;
				cin>>fila;
			}
			while(columna<=1){
				cout<<" El tama�o de las columnas debe ser positivo y mayor que 1"<<endl;
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
			//imprimirMatrizRandom(fila,columna,matrizRandom);
			option=menu();

			
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
	
		cin.get();

	
}

void llenarMatrizRandom(int fila, int columna, char**& matrix){
	int randomX,RandomY;
	if(matrix != NULL){
		
		for(int i = 0; i < fila ; i++){
			for(int j = 0; j < columna; j++){
				if((i==0) || ( j ==columna-1) ||(i==fila-1) || (j ==0)){
					matrix[i][j]='#';
				}else{
					randomX = rand() % 100;
					if (randomX > 20){
						matrix[i][j] = '*'; 
					} else {
						matrix[i][j] = '0';
					}
				}
			}
		}
 		imprimirMatrizRandom(fila,columna, matrix);
 	
 	}
}

void simulacionRandom (int fila, int columna, char**& matrix, int turno){
	if(matrix!= NULL)
	int controlDeturnos = 0;
	char **matrizTemporal = matrix;
	int contadorVidas = 0;
	for (int k=0; k< turno-1; k++){
		
		for (int x = 1; x < fila-1; x++){
			for (int y = 1; y < columna-1; y++){
				contadorVidas = 0;
				
				if (matrix[x][y+1] == '*'){
					contadorVidas++;
				}
				if (matrix[x][y-1] == '*'){
					contadorVidas++;
				}
				if (matrix[x-1][y] == '*'){
					contadorVidas++;
				}
				if (matrix[x-1][y+1] == '*'){
					contadorVidas++;
				}
				if (matrix[x-1][y-1] == '*'){
					contadorVidas++;
				}
				if (matrix[x+1][y] == '*'){
					contadorVidas++;
				}
				if (matrix[x+1][y+1] == '*'){
					contadorVidas++;
				}
				if (matrix[x+1][y-1] == '*'){
					contadorVidas++;
				}
				if (matrix[x][y] == '*'){
					if (contadorVidas == 2 || contadorVidas == 3){
						matrizTemporal[x][y]= '*';
					} else {
						matrizTemporal[x][y] = '0';
					}					
				} else if (matrix[x][y] == '0') {
					if (contadorVidas == 3){
						matrizTemporal[x][y] = '*';
					}
				}
				//cout << contvivas << endl;
			}
		}		
		
		matrix = matrizTemporal;
		imprimirMatrizRandom(fila,columna,matrix);
		cout << endl;
	}
}

void borrarMatriz(int size, char**& matriz){
	if(matriz != NULL){
	
		for(int i = 0; i < size; i++){
			delete[] matriz[i];
		}
		
		delete[]matriz;
		matriz = NULL;
	}
}

int menu(){
	int opcion;
	cout<<" Bienvenido al juego de la vida de conway!!"<<endl;
	cout<<" 1. Jugar con matriz Random: "<<endl;
	cout<<" 2. Jugar con matriz predefinida: "<<endl;
	cout<<" 3. Salir"<<endl;
	cin>>opcion;
	
	return opcion;
	
}
	
	

