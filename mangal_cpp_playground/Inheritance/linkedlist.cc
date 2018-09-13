#include<iostream>
using namespace std;

class linkedlist{
	protected:
	struct node{
		int num;
		node *link;
	}*p;
	public:
		linkedlist(){
			p=NULL;
		}
		~linkedlist(){
			node *m;
			while (p != NULL){
				m = p;
				p= p->link;
				delete m;
			}
		}
		void add(int num);
		void display();
};

void linkedlist::add(int num){
	node *q,*t;
	
	if(p==NULL){
		p=new node;
		p->num=num;
		p->link=NULL;
	}else{
		q=p;
		while(q!=NULL){
			q=q->link;
		}
		t = new node;
		t->num=num;
		t->link=NULL;
		q->link=t;
	}	
}

void linkedlist::display(){
	while(p!=NULL){
		cout<<p->num<<endl;
		p=p->link;
	}
}
int main(){
	linkedlist a;
	a.add(10);
	a.add(15);
	a.add(25);
	a.display();
	return 0;
}
