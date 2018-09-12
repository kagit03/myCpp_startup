#include<stdio.h>


int main (){

	int arr[5]={250,170,20,523,105};
	int temp,i,j;
	int len = sizeof(arr)/sizeof(int);

	for(i=0;i<len;i++){
		for(j=i;j<len;j++){
			if(arr[i]<arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		printf("%d\t",arr[i]);
	}
	printf("\n");
	
	return 0;
}
