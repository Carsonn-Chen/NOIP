#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n;
	scanf("%d%d",&t,&n);
	int a1,a2,a3,a4;
	int b;
	while(t--){
		/*memset(pai,0,sizeof(pai));
		for(int i = 1;i <= n;i ++){
			cin >> a >> b;
			if(a.length() != 2)
				pai[a[0]-'0'] ++;
			else{
				if(a[0] == '0'){
					if(a[1] == '1')
						pai[14] ++;
					else
						pai[15] ++;
				}
				else{
					if(a[1] == '0')
						pai[10] ++;
					else if(a[1] == '1')
						pai[11] ++;
					else if(a[1] == '2')
						pai[12] ++;
					else if(a[1] == '3')
						pai[13]++;
				}
			}
		}*/
		if(n == 2){
			cin >> a1 >> b >> a2 >> b;
			if((a1 == a2) || (a1 == 0 && a2 == 0))
				printf("1\n");
			else
				printf("2\n");
		}
		else if(n == 3){
			cin >> a1 >> b >> a2 >> b >> a3 >>b;
			if(a1 == a2 && a1 == a3)
				printf("1\n");
			else if((a1 == a2) || (a1 == a3) || (a2 == a3))
				printf("2\n");
			else
				printf("3\n");
		}
		else if(n == 4){
			cin >> a1 >> b >> a2 >> b >> a3 >>b >> a4 >> b;
			if((a1 == a2 && a1 == a3) || (a1 == a3 && a1 == a4) || (a2 == a3 && a2 == a4))
				printf("1\n");
			else if((a1 == a2 && a3 == a4) || (a1 == a3 && a2 == a4) || (a1 == a4 && a2 == a3))
				printf("2\n");
			else if(a1 != a2 && a1 != a3 && a1 != a4 && a2 != a3 && a2 != a4 && a3 != a4)
				printf("4\n");
			else
				printf("3\n");
		}
	}
	return 0;
}
