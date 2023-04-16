#include <bits/stdc++.h>
using namespace std;
struct ele{
		int pos,num;
		ele(int aaa=1e8,int bbb=0){num=bbb;pos=aaa;}
		inline bool operator >(const ele &b)const{
			return (num==b.num)?pos<b.pos:num>b.num;
		}
		friend inline ele max(ele a,ele b){return (a>b)?a:b;}
	}a, b;
int main()
{
    a = ele(1, 1); b = ele(1, 2);
    cout<< (b > a) <<endl;
}