#include <bits/stdc++.h>

using namespace std;

typedef struct node{
	node* left;
	node* right;
	node* parent;
	int weight;
	node():left(NULL),right(NULL),parent(NULL),weight(0){}
}node,*T;

struct cmp1{  
    bool operator ()(const T &a,const T &b){  
        return a->weight > b->weight;			//最小值优先  
    }  
}; 

priority_queue<T,vector<T>,cmp1>q;

T newnode(){
	return new node();	
}

void qx(T root){
	if(root){
		cout << root -> weight << " ";
		qx(root -> left);
		qx(root -> right);	
	}
}

void zx(T root){
	if(root){
		zx(root -> left);
		cout << root -> weight << " ";
		zx(root -> right);
	}
} 


int main(){
	freopen("in.in","r",stdin);
	float temp;
	T t;
	for(int i = 1;i <= 8;i ++){
		cin >> temp;
		temp = temp * 100;
		t = newnode();
		t -> weight = (int)temp;
		q.push(t);
	}
	T t3,t4,t5;
	while(!q.empty()){
		t3 = q.top();
		q.pop();
		t4 = q.top();
		q.pop();
		t5 = newnode();
		t5 -> left = t3;
		t5 -> right = t4;
		t5 -> weight = t3 -> weight + t4 -> weight;
		t3 -> parent = t4 -> parent = t5;
		if(!q.empty())
			q.push(t5);
	}
	qx(t5);
	cout << endl;
	zx(t5);
	return 0;
}
