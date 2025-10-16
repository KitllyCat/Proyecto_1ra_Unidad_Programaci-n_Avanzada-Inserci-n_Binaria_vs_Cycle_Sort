#include<iostream>
#include<fstream>
#include<chrono>
#include<cstdlib>
#include<ctime>
using namespace std;

void insertionbi(int a[],int n){
	int comparations=0;
	long long int swapes=0;
	int aux, izq=0, der=n-1;
	int m, j;
	chrono::steady_clock::time_point begin=chrono::steady_clock::now();	
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
			comparations+=1;
		}
		j=i-1;
		while(j>=izq){
			a[j+1]=a[j];
			j=j-1;
			swapes+=1;
		}
		a[izq]=aux;
	}
	cout<<"Comparaciones = "<<comparations<<"\nIntercambios = "<<swapes;
	cout<<endl;
	chrono::steady_clock::time_point end=chrono::steady_clock::now();
	cout<<"Time difference = ";
	cout<<chrono::duration_cast<chrono::milliseconds>(end-begin).count()<<" [ms]"<<endl;
	cout<<"Time difference = ";
	cout<<chrono::duration_cast<chrono::microseconds>(end-begin).count()<<" [us]"<<endl;
	cout<<"Time difference = ";
	cout<<chrono::duration_cast<chrono::nanoseconds>(end-begin).count()<<" [ns]"<<endl;
	
	ofstream archivo("Conteo de comparaciones e intercambios.txt");
    archivo<<"Comp. "<<comparations<<"\n";
	archivo<<"Inter. "<<swapes;
    archivo.close();
    
    ofstream archivo1("Tiempo de demora del algoritmo.txt");
    archivo1<<"[ms] "<<chrono::duration_cast<chrono::milliseconds>(end-begin).count()<<"\n";
    archivo1<<"[us] "<<chrono::duration_cast<chrono::microseconds>(end-begin).count()<<"\n";
    archivo1<<"[ns] "<<chrono::duration_cast<chrono::nanoseconds>(end-begin).count();
    archivo1.close();
}

int main(){
	srand(time(NULL));
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		//cin>>a[i];
		a[i]=(rand()%n)+1;
	}
	insertionbi(a, n);
	
	return 0;
}
