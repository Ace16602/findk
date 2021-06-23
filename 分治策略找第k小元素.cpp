#include<stdio.h>

int n,k;

int Select(int a[],int l,int r,int k){
	if (l==r) return a[l];
	int i=l,j=r;
	
	int x = a[i];
	while(i<j){
		while(i<j && a[j]>=x) j--;
		a[i]=a[j];
		while (i<j && a[i]<=x)i++;
		a[j] = a[i];
	}
	
	a[i]=x;
	
	int num =i-l+1;
	
	if(num<k) return Select(a,i+1,r,k-num);
	
	return Select(a,l,i,k);
} 

int main(){
	scanf("%d %d",&n,&k);
	int a[1000];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d",Select(a,1,n,k));
}
