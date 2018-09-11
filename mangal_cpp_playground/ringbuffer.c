#include<stdio.h>

int circ_buf[5];
static int head=0;
static int tail=0;
int len= 5;

int circ_buf_pus(int val){
	int next;
	next = head +1;
	
	if(next > len){
		next=0;
	}

	/*if(next == tail){
		head = next;
		return -1;
	}*/
	circ_buf[head]=val;
	head = next;
	return 0;
}

int circ_buf_pop(){
	int next;
	next = tail+1;

	if(next > len){
		next=0;
	}

	if (next == head){
		tail = next;
		return -1;
	}

	tail = next;
	return 	circ_buf[tail-1];
}

int main (){
	int i=0,j= 0,k=0, ret_val=0;
	for(i=0; i<=5; i++)
	{
		ret_val = circ_buf_pus(i+5);
		if (ret_val != 0){
			ret_val = circ_buf_pop();
			printf("%d popped out\n", ret_val);
		}else{
			printf("%d pushed in\n", circ_buf[i]);
		}
	}

	printf("\n\n");

	for(k=0; k<=6; k++){
		ret_val = circ_buf_pop();
		if (ret_val < 0){
			printf("Data not read even once\n");
			//break;
		}
	}
	
	printf("\n\n");
	for(j=0; j<len; j++){
		printf("%d\n",circ_buf[j]);
	}
	printf("Head=%d Tail=%d\n",head, tail);

	return 0;
}

