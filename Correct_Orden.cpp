#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
    const int n=100000;
    vector<int> numeros(n);

    for(int i=0;i<n;i++){
        numeros[i]=rand() %1000+1;
    }
    sort(numeros.begin(),numeros.end());

    ofstream archivo("Num-Random-Ordenados30.csv");

    if(!archivo){
        cout<<"Error al crear el archivo"<<endl;
        return 1;
    }

    for(int i=0;i<n;i++){
        archivo<<numeros[i];
        if(i != n-1){
            archivo<<"\n";
        }
    }

    archivo.close();

    cout<<"Archivo generado y ordenado correctamente"<<endl;
    return 0;
}