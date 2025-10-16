#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>
using namespace std;

void cyclesort(int a[], int n){
	int comparations=0;
	long long int swapes=0;
	chrono::steady_clock::time_point begin=chrono::steady_clock::now();
	for(int i=0;i<n-1;i++){
		int val=a[i];
		int pos=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<val){
				pos=pos+1;
			}
			comparations+=1;
		}
		if(pos==i){
			continue;
		}
		while(val==a[pos]){
			pos=pos+1;
			comparations+=1;
		}
		if(pos!=i){
			swap(val,a[pos]);
			swapes+=1;
		}
		while(pos!=i){
			pos=i;
			for(int j=i+1;j<n;j++){
				if(a[j]<val){
					pos=pos+1;
				}
				comparations+=1;
			}
			while(val==a[pos]){
				pos=pos+1;
				comparations+=1;
			}
			swap(val, a[pos]);
			swapes+=1;
		}
	}
	chrono::steady_clock::time_point end=chrono::steady_clock::now();
	
	ofstream archivo("Datos del algoritmo cycle sort.txt");
    archivo<<"Comparaciones: "<<comparations<<"\n";
	archivo<<"Intercambios: "<<swapes<<"\n\n";
	archivo<<"Tiempo de demora:\n";
	archivo<<"Milisegundos	[ms]: "<<chrono::duration_cast<chrono::milliseconds>(end-begin).count()<<"\n";
    archivo<<"Microsegundos	[us]: "<<chrono::duration_cast<chrono::microseconds>(end-begin).count()<<"\n";
    archivo<<"Nanosegundos	[ns]: "<<chrono::duration_cast<chrono::nanoseconds>(end-begin).count()<<"\n";
    archivo.close();
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
	
	cyclesort(a, n);
	
	return 0;
}
