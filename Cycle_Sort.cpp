#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

void cyclesort(int a[], int n){
	for(int i=0;i<n-1;i++){
		int val=a[i];
		int pos=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<val){
				pos=pos+1;
			}
		}
		if(pos==i){
			continue;
		}
		while(val==a[pos]){
			pos=pos+1;
		}
		if(pos!=i){
			swap(val,a[pos]);
		}
		while(pos!=i){
			pos=i;
			for(int j=i+1;j<n;j++){
				if(a[j]<val){
					pos=pos+1;
				}
			}
			while(val==a[pos]){
				pos=pos+1;
			}
			swap(val, a[pos]);
		}
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
	
	cyclesort(a, n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
