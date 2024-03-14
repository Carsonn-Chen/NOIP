#include <bits/stdc++.h>

using namespace std;

bool tag[15];
char word[15],sent[1000005];

int main(){
	freopen("in.in","r",stdin);
	scanf("%s",word);
	char temp;
	int k = 0;
	getchar();
	getchar();
	while(scanf("%c",&temp) && temp != '\n'){
		sent[k++] = temp;
	}
	int j = 0;
	int len1 = strlen(word),len2 = strlen(sent);
	for(int i = 0;i < len1;i ++){
		if(word[i] >= 'A' && word[i] <= 'Z')
			word[i] = tolower(word[i]);
	}
	int cnt = 0;
	bool first = 1;
	int place;
	for(int i = 0;i < len2;i ++){
		if(sent[i] >= 'A' && sent[i] <= 'Z')
			sent[i] = tolower(sent[i]);
		if(sent[i] == word[0] && !tag[0]){
			tag[0] = 1;
			j ++;
		}
		else if(sent[i] == word[j] && tag[j-1]){
			tag[j] = 1;
			j ++;
		}
		else if(sent[i] != word[j] && tag[j-1]){
			j = 1;
			memset(tag,0,sizeof(bool));
		}
		if(j == len1){
			if(first){
				place = i+1-len1;
				first = 0;
			}
			cnt += 1;
			j = 1;
			memset(tag,0,sizeof(bool));
		}
		
		
	}
	if(cnt == 0)
		printf("-1");
	else
		printf("%d %d",cnt,place);
	return 0;
}
