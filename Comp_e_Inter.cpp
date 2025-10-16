#include<iostream>
#include <fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

void insertionbi(int a[],int n){
	long long int comparations=0, sorts=0;
	int aux, izq=0, der=n-1;
	int m, j;
	for(int i=1;i<n;i++){
		aux=a[i];
		izq=0;
		der=i-1;
		while(izq<=der){
			comparations+=1;
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
			sorts+=1;
		}
		a[izq]=aux;
		sorts+=1;
	}
	cout<<"comparaciones = "<<comparations<<endl;
	cout<<"intercambios = "<<sorts;
	
    ofstream archivo("Comparaciones e Intercambios.txt");
    archivo<<"Comparaciones = "<<comparations<<"\nIntercambios = "<<sorts;
    archivo.close();
}

int main(){
	srand(time(NULL));
	int n;//Se puede igualar n por: 1000, 10000 o 100000
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=(rand()%n)+1;
	}
	insertionbi(a, n);
	
	return 0;
}
