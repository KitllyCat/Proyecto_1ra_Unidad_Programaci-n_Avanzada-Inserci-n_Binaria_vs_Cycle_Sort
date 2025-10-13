#include<iostream>
#include<algorithm>
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
			for(int j=i+1;j<n;){
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
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	cyclesort(a, n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
