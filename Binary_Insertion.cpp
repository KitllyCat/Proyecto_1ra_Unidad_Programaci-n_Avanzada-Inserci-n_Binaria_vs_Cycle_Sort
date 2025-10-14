#include <iostream>
#include <fstream>
using namespace std;

void insertionbi(int a[],int n){
	int aux, izq=0, der=n-1;
	int m, j;
	for(int i=1;i<n;i++){
		aux=a[i];
		izq=0;
		der=i-1;
		while(izq<=der){
			m=(izq+der)/2;
			if(aux<a[m]){
				der=m-1;
			}else{
				izq=m+1;
			}
		}
		j=i-1;
		while(j>=izq){
			a[j+1]=a[j];
			j=j-1;
		}
		a[izq]=aux;
	}
}

int main(){
	
	string nombreArchivo;
    cout<<"Ingrese el nombre del archivo .csv: ";
    cin>>nombreArchivo;

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){
        cout<<"Error al abrir el archivo. Ingrese bien el nombre"<<endl;
        return 1;
    }

    int cont=0;
    int temp;
    while (archivo >> temp){
    	cont++;
	}
    archivo.close();
    int n=cont;
	int a[100000]; //Importante, modificar esto de acuerdo a la cantidad de numeros de n

    archivo.open(nombreArchivo);
    for (int i = 0; i < cont; i++) {
        archivo >> a[i];
    }
    archivo.close();
	
	insertionbi(a, n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
