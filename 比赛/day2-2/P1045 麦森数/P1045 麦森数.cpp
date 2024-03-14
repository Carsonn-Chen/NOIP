#include <string>
#include <iostream>
#include <iosfwd>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#define ri register int
#define MAX_L 100005//最大长度，可以修改

using namespace std;

class bign {
	public:
		int len;
		int s[MAX_L];//数的长度，记录数组
//构造函数
		bign();
		bign(const char*);
		bign(int);
		bool sign;//符号 1正数 0负数
		friend istream& operator>>(istream &,bign &);//重载输入流
		friend ostream& operator<<(ostream &,bign &);//重载输出流
//重载复制
		string toStr() const;
		bign operator=(const char*);
		bign operator=(int);
		bign operator=(const string);
		bign operator*(const bign &)const;
		bign operator*(const int num)const;
		bign operator*=(const bign&);
		void clean();
};

bign::bign() {
	memset(s, 0, sizeof(s));
	len = 1;
	sign = 1;
}

bign::bign(const char *num) {
	*this = num;
}

bign::bign(int num) {
	*this = num;
}

string bign::toStr() const {
	string res;
	res = "";
	for (int i = 0; i < len; i++)
		res = (char)(s[i] + '0') + res;
	if (res == "")
		res = "0";
	if (!sign&&res != "0")
		res = "-" + res;
	return res;
}

istream &operator>>(istream &in, bign &num) {
	string str;
	in>>str;
	num=str;
	return in;
}

ostream &operator<<(ostream &out, bign &num) {
	out<<num.toStr();
	return out;
}

bign bign::operator=(const char *num) {
	memset(s, 0, sizeof(s));
	char a[MAX_L] = "";
	if (num[0] != '-')
		strcpy(a, num);
	else
		for (int i = 1; i < (int)strlen(num); i++)
			a[i - 1] = num[i];
	sign = !(num[0] == '-');
	len = strlen(a);
	for (int i = 0; i < (int)strlen(a); i++)
		s[i] = a[len - i - 1] - 48;
	return *this;
}

bign bign::operator=(int num) {
	if (num < 0)
		sign = 0, num = -num;
	else
		sign = 1;
	char temp[MAX_L];
	sprintf(temp, "%d", num);
	*this = temp;
	return *this;
}

bign bign::operator=(const string num) {
	const char *tmp;
	tmp = num.c_str();
	*this = tmp;
	return *this;
}

bign bign::operator * (const bign &num)const {
	bign result;
	result.len = len + num.len;

	for (int i = 0; i < len; i++)
		for (int j = 0; j < num.len; j++)
			result.s[i + j] += s[i] * num.s[j];

	for (int i = 0; i < result.len; i++) {
		result.s[i + 1] += result.s[i] / 10;
		result.s[i] %= 10;
	}
	result.clean();
	result.sign = !(sign^num.sign);
	return result;
}

bign bign::operator*(const int num)const {
	bign x = num;
	bign z = *this;
	return x*z;
}
bign bign::operator*=(const bign&num) {
	*this = *this * num;
	return *this;
}

void bign::clean() {
	if (len == 0) len++;
	while (len > 1 && s[len - 1] == '\0')
		len--;
}

bign a = 2;

int main(){
	int p;
	scanf("%d",&p);
	for(ri i = 2;i <= p;i ++)
		a *= 2;
	printf("%d\n",a.len);
	int cnt = 0;
	if(a.len < 500){
		for(ri i = 1;i < 500-a.len;i ++){
			printf("0");
			cnt ++;
			if(cnt == 50)
				printf("\n"),cnt = 0;
		}
		for(ri i = a.len;i > 0;i --){
			printf("%d",a.s[i]);
			cnt ++;
			if(cnt == 50)
				printf("\n"),cnt = 0;
		}
		printf("%d",a.s[0]-1);
	}
	else{
		for(ri i = 499;i > 0;i --){
			printf("%d",a.s[i]);
			cnt ++;
			if(cnt == 50)
				printf("\n"),cnt = 0;
		}
		printf("%d",a.s[0]-1);
	}
	return 0;
}
