#include<iostream>
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
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	insertionbi(a, n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
