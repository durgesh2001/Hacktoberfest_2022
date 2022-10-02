#include<stdio.h>
void merge(int arr[], int p, int q, int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1],M[n2],v,w;
	for(w=0;w<n1;w++)
	L[w]=arr[p+w];
	for(v=0;v<n2;v++)
	M[v]= arr[q+1+v];
	int i,j,k;
	i=0;
	j=0;
	k=p;
	while(i<n1&&j<n2)
	{
		if(L[i]<+M[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k]=M[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=M[j];
		j++;
		k++;
	}
}
void mergesort(int arr[], int l, int r){
	if(l<r){
		int m=l+(r-l)/2;
		mergesort(arr, l, m);
		mergesort(arr, m+1, r);
		merge(arr,l,m,r);
	}
}
void printArray(int arr[], int size){
	int i;
	for(i=0;i<size;i++)
	printf(" %d ",arr[i]);
	
	printf("\n");
}
int main(){
int arr[]={17,34,23,12,10,50,30,1};
int size= sizeof(arr)/sizeof(arr[0]);
mergesort(arr,0,size-1);
printf("The sorted array of the element is= \n");
printf("\n");
printArray(arr,size);
printf("\n");
}
