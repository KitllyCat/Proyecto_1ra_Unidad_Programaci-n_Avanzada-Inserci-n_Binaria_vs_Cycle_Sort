#include<iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>
using namespace std;

void insertionbi(int a[],int n){
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
		}
		j=i-1;
		while(j>=izq){
			a[j+1]=a[j];
			j=j-1;
		}
		a[izq]=aux;	
	}
	chrono::steady_clock::time_point end=chrono::steady_clock::now();
	cout<<"Time difference = ";
	cout<<chrono::duration_cast<chrono::milliseconds>(end-begin).count()<<"[ms]"<<endl;
	cout<<"Time difference = ";
	cout<<chrono::duration_cast<chrono::microseconds>(end-begin).count()<<"[us]"<<endl;
	cout<<"Time difference = ";
	cout<<chrono::duration_cast<chrono::nanoseconds>(end-begin).count()<<"[ns]"<<endl;
}

int main(){
	srand(time(NULL));
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=(rand()%n)+1;
	}
	
	insertionbi(a, n);

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	
	return 0;
}
