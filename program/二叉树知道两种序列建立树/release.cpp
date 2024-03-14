#include <bits/stdc++.h>

using namespace std;

string qx,zx,hx;

typedef struct node{
	char e;
	node *left;
	node *right;
	node():left(NULL),right(NULL){}
}node,*T;

T newnode(){
	return new node();
}

void qxcrtree(T& p,int i,int begin,int len){
	if(!len) return;
	p = newnode();
	p -> e = qx[i];
	int j;
	for(j = begin;j < len;j ++)
		if(qx[i] == zx[j])
			break;
	qxcrtree(p->left,i+1,begin,j-begin);
	qxcrtree(p->right,i+(j-begin)+1,j+1,len-(j-begin)-1);
}

void hxcrtree(T& p,int i,int begin,int len){
	if(!len) return;
	p = newnode();
	p -> e = hx[i];
	int j;
	for(j = begin;j < len;j ++)
		if(hx[i] == zx[j])
			break;
	hxcrtree(p->left , i-(len-(j-begin)-1)-1 , begin , j-begin);
	hxcrtree(p->right , i-1 , j+1 , len-(j-begin+1));
}

void qxout(T p){
	if(p){
		cout << p->e;
		qxout(p->left);
		qxout(p->right);
	}
}

void zxout(T p){
	if(p != NULL){
		zxout(p->left);
		cout << p->e;
		zxout(p->right);
	}
}

void hxout(T p){	
	if(p != NULL){
		hxout(p->left);
		hxout(p->right);
		cout << p->e;
	}
} 

int main(){
	//freopen("in.in","r",stdin);
	//freopen("out.txt","w",stdout);
	T root;
	int c;
	cout << "知道前序和中序输入1\n" << "知道后序和中序输入2" << endl;
	scanf("%d",&c);
	if(c == 1){
		cin >> qx >> zx;
		qxcrtree(root,0,0,qx.size());
		qxout(root);
		cout << endl;
		zxout(root);
		cout << endl;
		hxout(root);
	}
	else{
		cin >> hx >> zx;
		int leng = hx.length();
		hxcrtree(root,leng-1,0,leng);
		qxout(root);
		cout << endl;
		zxout(root);
		cout << endl;
		hxout(root);
	} 
} 
