#include <bits/stdc++.h>
using namespace std;

char jud1[30]={0};				//jud1记录字母对应的密字 
bool jud2[30];					//jud2记录密字的使用情况 
char a[105],b[105],c[105];

int main(){
	//freopen("test.in","r",stdin);
	scanf("%s%s%s",a,b,c);	
	for(int i = 0;i < strlen(a);i ++){
		if((jud2[b[i]-64] == 1 && jud1[a[i]- 64] != b[i]) || (jud1[a[i]- 64] != 0 && jud1[a[i]- 64] != b[i])){
			printf("Failed");
			return 0;	
		}
		jud1[a[i]-64] = b[i];
		jud2[b[i]-64] = 1;
	}
	for(int i = 1;i <= 26;i ++)
		if(jud1[i] == 0){
			printf("Failed");
			return 0;
		}
	for(int i = 0;i < strlen(c);i ++)
		c[i] = jud1[c[i]-64];
	printf("%s",c);
	return 0;
}
