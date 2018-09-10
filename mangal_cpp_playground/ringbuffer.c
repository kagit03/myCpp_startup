#include<stdio.h>

int circ_buf[5];
static int head=0;
static int tail=0;
int len= 5;

int circ_buf_pus(int val){
	int next;
	next = head +1;
	
	if(next >= len){
		next=0;
	}

	if(next == tail){
		return -1;
	}
	circ_buf[head]=val;
	head = next;
	return 0;
}

int circ_buf_pop(){
	int next;
	next = tail+1;
	if (head == tail){
		return -1;
	}
	if(next >= len){
		next=0;
	}
	tail = next;
	return 	circ_buf[tail-1];
}

int main (){
	int i=0, ret_val=0;
	
	for(i=0; i<=4; i++)
	{
		ret_val = circ_buf_pus((i+1)*5);
		if (ret_val != 0){
			ret_val = circ_buf_pop();
			printf("%d popped out\n", ret_val);
		}
		printf("%d pushed in\n", circ_buf[i]);
	}
	//circ_buf_pop(20);

	return 0;
}

