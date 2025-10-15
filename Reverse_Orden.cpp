#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

int main(){
	srand(time(NULL));
	int n=1000;
	vector<int>a(n);
	int p=60;//Recomendación: p debe ser mayor a 50 //A partir de p es que se saca los elementos duplicados
	int val=1;
	
	for(int i=0;i<n;i++){
		a[i]=(rand()%n)+1;
	}
	
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
	
	for(int i=0;i<(n/2);i++){
		int aux=a[n-i-1];
		a[n-i-1]=a[i];
		a[i]=aux;
	}
    
    for(int i=0;i<n;i++){
    	cout<<a[i]<<" ";
	}
	
	return 0;
}
