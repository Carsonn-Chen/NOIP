#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("out.out","w",stdout);
	int k;
	char num[230];
	scanf("%d",&k);
	scanf("%s",num);
	int len= strlen(num);
	for(int i = 0;i < len;i ++){											//顶部横着的 
		if((num[i]-48) == 1 || (num[i]-48) == 4)
			for(int j = 1;j <= (k+2);j ++)
				printf(" ");
		else{
			printf(" ");
			for(int j = 1;j <= k;j ++)
				printf("-");
			printf(" ");
		}
		if(i != len)
			printf(" ");
	}
	printf("\n");
	for(int n = 1;n <= k;n ++){												//上面竖着的 
		for(int i = 0;i < len;i ++){
			if((num[i]-48) == 1 || (num[i]-48) == 2 || (num[i]-48) == 3 || (num[i]-48) == 7){
				for(int j = 1;j <= (k+1);j ++)
					printf(" ");
				printf("|");
			}
			else if((num[i]-48) == 4 || (num[i]-48) == 8 || (num[i]-48) == 9 || (num[i]-48) == 0){
				printf("|");
				for(int j = 1;j <= k;j ++)
					printf(" ");
				printf("|");
			}
			else if((num[i]-48) == 5 || (num[i]-48) == 6){
				printf("|");
				for(int j = 1;j <= (k+1);j ++)
					printf(" ");
			}
			if(i != len)
				printf(" ");
		}
		printf("\n");
	}
	for(int i = 0;i < len;i ++){											//中部横着的 
		if((num[i]-48) == 1 || (num[i]-48) == 7 || (num[i]-48) == 0)
			for(int j = 1;j <= (k+2);j ++)
				printf(" ");
		else{
			printf(" ");
				for(int j = 1;j <= k;j ++)
					printf("-");
			printf(" ");
		}
		if(i != len)
			printf(" ");
	}
	printf("\n");
	for(int n = 1;n <= k;n ++){												//下面竖着的 
		for(int i = 0;i < len;i ++){
			if((num[i]-48) == 1 || (num[i]-48) == 3 || (num[i]-48) == 4 || (num[i]-48) == 5 || (num[i]-48) == 7 || (num[i]-48) == 9){
				for(int j = 1;j <= (k+1);j ++)
					printf(" ");
				printf("|");
			}
			else if((num[i]-48) == 6 || (num[i]-48) == 8 || (num[i]-48) == 0){
				printf("|");
				for(int j = 1;j <= k;j ++)
					printf(" ");
				printf("|");
			}
			else if((num[i]-48) == 2){
				printf("|");
				for(int j = 1;j <= (k+1);j ++)
					printf(" ");
			}
			if(i != len)
				printf(" ");
		}
		printf("\n");
	}
	for(int i = 0;i < len;i ++){											//下面横着的 
		if((num[i]-48) == 1 || (num[i]-48) == 7 || (num[i]-48) == 4)
			for(int j = 1;j <= (k+2);j ++)
				printf(" ");
		else{
			printf(" ");
				for(int j = 1;j <= k;j ++)
					printf("-");
			printf(" ");
		}
		if(i != len)
			printf(" ");
	}
	return 0;
}
