/*
 * @author: Carolina Arcos Prats y Jonathan Eidelman
 * @version: Agosto de 2013
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string>
#include <time.h>

using namespace std;

/* 
 * El vector datos, es un vector global de tipo string en el que se almacenan 
 * los datos que serán organizados
 */
vector <string> datos;

/* 
 * El método lecturaDeDocumento recíbe el archivo que será ordenado y lo pone 
 * en el vector datos
 */
void lecturaDeDocumento (){
FILE *archivo;
    string linea;
    int i=0;
    archivo = fopen("1.txt", "r"); //Se abre el archivo solo para lectura
    ifstream palabra("1.txt"); 
    if (archivo==NULL) { /*Si el archivo no existe o no se pudo abrir, se emite
                          *  el mensaje Error al abrir el archivo */
        cout << ("Error al abrir el archivo") << endl;
    }
    do { /* mientras el archivo no sea nulo, ubica cada línea dde éste en una
          * posición del vector datos */
        palabra >> linea;
        datos.push_back(linea);
        //i++;
    } while (palabra != NULL);    
    
    datos.erase(datos.end()); /*borra la última posición del vector datos para
                               *que no quere repetida*/
}

/*
 * El método comparar, analiza los datos del vector datos; si la posición [j]
 * es mayor que la posición [j+1], los intercambia y continúa el ciclo hasta el
 * encontrar un elemento del cual sea menor. Posterior mente repite el ciclo con
 * el elemento de la posicion i.
 */
vector<string> comparar(vector<string> & datos){
	for(int i = 0; i < datos.size(); i++){
		for(int j = 0; j < datos.size() - 1; j++){
			if (datos[j] > datos [j+1]){ /* si el elemento de la
                                                 *  posición [j] es mayor que el
                                                 *  de la posición [j+1], los 
                                                 * intercambia implementando el 
                                                 * temporal */
				string tempo = datos [j];
				datos[j] = datos [j+1];
				datos[j+1] = tempo;
			}
		}
	}
	return datos;
}

/*
 * El método imprimir se encarga de imprimir cada una de las posiciones del
 *  vector
 */
void imprimir (vector<string> datos){
	for(int i = 0; i < datos.size(); i++){
		cout << datos[i] << endl;
	}
}

/*
 * El método main es el ejecutable del programa
 */
int main(){
	time_t inicio, fin; /*declaración de las variables para medir el tiempo 
                         * de ordenamiento*/
	lecturaDeDocumento(); // se imvoca el método lecturaDeDocumento
	inicio = time(NULL); // se inicia el tiempo de conteo del ordenamiento
	comparar(datos); /*se imvoca el método comparar para analizar y 
                         * organizar los datos*/
        fin = time(NULL); //se termina el tiempo de conteo del ordenamiento
	imprimir(datos); /*se invoca el método imprimir para mostrar los datos 
                         * ordenados*/	
	cout << "El tiempo de ejecucion fue de " << difftime(fin,inicio)
                << endl; /*muestra el tiempo total de ordenamiento restando el 
        tiempo final menos el inicial*/
	cout << datos.capacity()*sizeof(string) << " Bytes" << endl; /*indica la
                                                 * memoria utilizada en el 
                                                 * ordenamiento de los datos en 
                                                 * Bytes*/
	
	return 0;
}
