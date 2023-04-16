#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
const int N=2005;
const double PI=acos(-1);
struct Cricle 
{
	double r,x,y;
	void input() {scanf("%lf%lf%lf",&x,&y,&r);}
}a[N];
struct Opt {double l,r;} opt[N];
int n,top,flag;
double ans;
double Dis(Cricle c1,Cricle c2)
{
	return sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
}
double angle(double a,double b,double c)
{
	return acos((a*a+b*b-c*c)/(2*a*b));
}
void add(double a,double b) {opt[++top].l=a; opt[top].r=b;}
void solve(Cricle c1,Cricle c2,double dis)
{
	double t1=atan2(c1.y-c2.y,c1.x-c2.x),t2=angle(c1.r,dis,c2.r);
	double l=t1-t2,r=t1+t2;
	if (l<0) l+=2*PI;
	if (r<0) r+=2*PI;
	if (l>r) add(l,2*PI),add(0,r);
	else add(l,r);
}
int cmp(Opt a,Opt b) {return a.l<b.l;}
double calc()
{
	sort(opt+1,opt+top+1,cmp);
	double l=-100,r=-100,ret=0;
	for (int i=1;i<=top;i++)
	{
		if (opt[i].l>r) {ret+=r-l; l=opt[i].l; r=opt[i].r;}
		else r=max(r,opt[i].r);
	}
	ret+=r-l;
	return 2*PI-ret;
}
int main()
{
    while (~scanf("%d", &n))
    {
        ans = 0;
        for (int i=n;i;i--) a[i].input();
        for (int i=1;i<=n;i++)
        {
            top=0; flag=1;
            for (int j=1;j<i&&flag;j++)
            {
                double dis=Dis(a[i],a[j]);
                if (a[i].r+dis<a[j].r) flag=0;
                if (a[i].r+a[j].r>dis&&fabs(a[j].r-a[i].r)<dis) solve(a[i],a[j],dis);
            }
            if (flag)
            {
                ans+=a[i].r*calc();
            }
        }
        printf("%.9lf\n",ans);
    }
    return 0;
}

