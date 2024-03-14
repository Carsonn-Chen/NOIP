#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#define max_l 1005
#define ri register int

using namespace std;

class bign{
	public:
		int len,num[max_l];
		bool sign;
		
		bign();
		bign(const char*);
		bign(int);
		
		string ToStr() const;
		
		friend istream& operator>>(istream &,bign &);//重载输入流
		friend ostream& operator<<(ostream &,bign &);//重载输出流
		
		bign operator = (const char*);
		bign operator = (int);
		bign operator = (string);
		
		bign operator + (const bign&) const;
		bign operator - (const bign&) const;
};

bign::bign(){
	memset(num,0,sizeof(num));
	sign = 1;
	len = 0;
}

bign::bign(int num){
	*this = num;
}

bign::bign(const char *a){
	*this = a;
}

istream &operator>>(istream &in,bign &a) {
	string str;
	in >> str;
	a = str;
	return in;
}

ostream &operator<<(ostream &out,bign &a) {
	out << a.ToStr();
	return out;
}

bign bign::operator = (const char *a){
	memset(num,0,sizeof(num));
	char x[max_l];
	if(a[0] == '-')
		for(ri i = 1;i < (int)strlen(a);i ++)
			x[i-1] = num[i];
	else
		strcpy(x,a);
	sign = !(a[0] == '-');
	len = strlen(x);
	for(ri i = 0;i < len;i ++)
		num[i] = a[len- i -1] - '0';
	return *this;
}

bign bign::operator = (int a){
	if (a < 0)
		sign = 0, a = -a;
	else
		sign = 1;
	char temp[max_l];
	sprintf(temp, "%d", num);
	*this = temp;
	return *this;
}

string bign::ToStr() const {
	string res;
	res = "";
	for (int i = 0; i < len; i++)
		res = (char)(num[i] + '0') + res;
	if (res == "")
		res = "0";
	if (!sign&&res != "0")
		res = "-" + res;
	return res;
}

bign bign::operator=(const string num) {
	const char *tmp;
	tmp = num.c_str();
	*this = tmp;
	return *this;
}

bign bign::operator+(const bign &a) const {
	if (sign^a.sign) {
		bign tmp = sign ? a : *this;
		tmp.sign = 1;
		return sign ? *this - tmp : a - tmp;
	}
	bign result;
	result.len = 0;
	int temp = 0;
	for (int i = 0; temp || i < (max(len, a.len)); i++) {
		int t = num[i] + a.num[i] + temp;
		result.num[result.len++] = t % 10;
		temp = t / 10;
	}
	result.sign = sign;
	return result;
}

bign bign::operator-(const bign &a) const {
	bign b = a,c=*this;
	if (!num.sign && !sign) {
		b.sign=1;
		c.sign=1;
		return b-c;
	}
	if (!b.sign) {
		b.sign=1;
		return c+b;
	}
	if (!c.sign) {
		c.sign=1;
		b=bign(0)-(c+b);
		return b;
	}
	if (c<b) {
		bign c=(b-a);
		c.sign=false;
		return c;
	}
	bign result;
	result.len = 0;
	for (int i = 0, g = 0; i < a.len; i++) {
		int x = a.s[i] - g;
		if (i < b.len) x -= b.s[i];
		if (x >= 0) g = 0;
		else {
			g = 1;
			x += 10;
		}
		result.s[result.len++] = x;
	}
	result.clean();
	return result;
}

int main(){
	bign a = "12345678999999999999";
	cout << a << endl;
	cin >> a;
	cout << a << endl;
	return 0;
}
