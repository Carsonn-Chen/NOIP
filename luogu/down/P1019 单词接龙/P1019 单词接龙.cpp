#include<bits/stdc++.h>

using namespace std;

int n,dic[21][21],vis[21],ans;
string words[21];
char s;

void f(string a,string b,int x,int y)
{
    int a1 = a.size()-1,b1 = b.size()-1; 
    for(int i = 0;i <= b1;i ++)  //�ӵ�һ����ʼö�� 
    {
        if(a[0] == b[i])  //���a������ĸ��b�м����ĸ��ͬ �����ж������ܲ��ܽ���һ�� 
        {
            int pos = 0,tot = 0;  //pos�ǵ�ǰa�ĵڼ�����ĸ��tot��a��b���غϲ��ֳ��� 
            for(int j = i;j <= b1;j ++)
            {
                if(a[pos] == b[j])
                {
                    tot ++;
                    pos ++;
                    if(j == b1 && tot != min(a1,b1)+1) //���ö�ٵ�����󣬲���a��bû�а�����ϵ��˵��������ô�� 
                      dic[x][y] = tot;  //��¼��С�ص����ֵĳ��� 
                                      //֮���Բ�break������Ϊ������ܻ���ö�ٵ���С�Ľӷ� 
                                      //���� chsese �� sesettt ��Ȼ chsesesettt Ҫ��chsesettt���� 
                }
                else break;
            }
        }
    }
}
void dfs(int pos,int sum)
{
    ans = max(ans,sum);  //ʵʱ����ans 
    for(int i = 1;i <= n;i ++)
    {
        if(dic[i][pos] && vis[i])
        {
            vis[i] --;
            int suml = sum+words[i].size()-dic[i][pos]; //�����µ���"��"�ĳ���Ϊ=�ɵĳ���+�µ��ʳ���-�ظ����ֳ��� 
            dfs(i,suml);  //�����µ��ʼ������� 
            vis[i] ++;
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i ++)
    {
        cin >> words[i];
        vis[i] = 2; //��ʼ��vis���飬ÿ�������������� 
    }   
    cin >> s;
    for(int i = 1;i <= n;i ++)
      for(int j = 1;j <= n;j ++)
        f(words[i],words[j],i,j); //Ԥ����dic���� 

    for(int i = 1;i <= n;i ++)
    {
        if(words[i][0] == s)  //�ҵ���ʼ���� 
        {
            vis[i] --;
            dfs(i,words[i].size()); //���� 
            vis[i] ++;
        }  
    }
    cout << ans;
    return 0;
}
