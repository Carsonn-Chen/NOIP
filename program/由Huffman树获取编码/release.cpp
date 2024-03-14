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

struct bm{
	int fh;										//符号 
	char name[15];								//编码 
}n[8];

priority_queue<T,vector<T>,cmp1>q;

T newnode(){
	return new node();	
}

char bianma[20];								//记录编码 
int no=0;

void hqbm(T t,int i){									//获取编码 
	if(t){
		if(t->parent && t == t->parent->left)
			bianma[i] = '0';
	 	if(t->parent && t == t->parent->right)
			bianma[i] = '1';
		if(!t->left && !t->right){
			n[no].fh = t->weight;
			for(int k = 0;k < strlen(bianma);k ++)
				n[no].name[k] = bianma[k];
			no++;
		}
		hqbm(t->left,i+1);
		hqbm(t->right,i+1);
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
	hqbm(t5,0);
	for(int i = 0;i < 8;i ++){
		cout << n[i].fh << ":";
		printf("%s\n",n[i].name);
	}
	return 0;
}
