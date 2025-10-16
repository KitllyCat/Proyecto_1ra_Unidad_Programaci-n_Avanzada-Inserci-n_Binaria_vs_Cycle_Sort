#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main(){
	
    srand(time(0));
    const int n=100000;
    vector<int> numeros(n);
    
    for(int i=0;i<n;i++){
        numeros[i]=rand() %100000+1;//rango modificable.
    }

    ofstream archivo("Num-Random-n5.csv"); //Editable, se guardaran con diferentes nombres
    
    if(!archivo){
        cout<<"Error al crear el archivo"<<endl;
        return 1;
    }
    
    for (int i=0;i<n;i++){
        archivo<<numeros[i];
        if (i!=n-1){
        	archivo<<"\n";
		}
    }

    archivo.close();
    
    cout<<"Archivo generado correctamente"<<endl;
    return 0;
}
