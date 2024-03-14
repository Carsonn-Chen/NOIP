#include <bits/stdc++.h>

using namespace std;

typedef struct node{
	bool pd;
	string e;
	node* left;
	node* right;
	node():left(NULL),right(NULL),pd(1){}
}node,*T;

bool ju = 1;

T newnode(){
	return new node();
}

void jud(T tr){
	if(tr){
		if(tr -> pd == 1){
			ju = 0;
			return;
		}
		jud(tr -> left);
		jud(tr -> right);
	}
}

void tout(T tr){
	if(tr){
		cout << (tr -> e) << " ";
		tout(tr -> left);
		tout(tr -> right);
	}
}

int main(){
	freopen("in.in","r",stdin);
	T root,p;
	string s,temp;
	root = newnode();
	while(cin >> s){
		if(s == "()")
			break;
		p = root;
		int i = 1;
		while(s[i] != ','){
			temp[i-1] = s[i];
			i ++;
		}
		i += 1;
		while(s[i] != ')'){
			if(s[i] == 'L'){
				p = p -> left;
				if(!p)
					p = newnode();
			}
			else if(s[i] == 'R'){
				p = p -> right;
				if(!p)
					p= newnode();
			}
			i ++;
		}
		if(p -> pd){
			p -> e = temp;
			p -> pd = 0;
		}
		else 
			printf("not complete");
	}
	jud(root);
	if(ju)
		tout(root);
	else
		printf("not complete");
	return 0; 
}
