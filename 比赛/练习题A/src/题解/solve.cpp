/*在单调序列中查找元素，如果序列中有多个相同的元素，
  返回其中一个元素的下标即可。,所以适合无重复元素，
  或者虽然有重复元素，但返回不限定上下界，可任意。 
*/ 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const double PI= acos(-1.0);

int a[1000005],n,k;

int Erfen(){
   int L = 0; // 查找区间的左端点
   int R = n - 1; // 查找区间的右端点
   while( L <= R) { // 如果查找区间不为空就继续查找
      int mid = L+(R-L>>1); // 取查找区间正中元素的下标
      if( k == a[mid] ) return mid;
      if( k > a[mid]) L = mid + 1; // 设置新的查找区间的左端点
        else R = mid - 1; // 设置新的查找区间的右端点
   }
   return -1;
}   // 复杂度O(log(n))

int main(){
	freopen("solve.in","r",stdin);
    freopen("solve.out","w",stdout);    
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i]; 
    cout<<Erfen()<<endl;   
return 0;
}


