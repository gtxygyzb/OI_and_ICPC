#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
const double eps=1e-10;
const double pi=acos(-1);

int x[10],y[10];

double totheta(int x,int y)
{
	if(x==0) return y>0?90:270;
	if(y==0) return x>0?0:180;
	double ans=atan2(abs(y),abs(x));
	ans=ans*180/pi;
	if(x>0&&y>0) return ans;
	if(x>0&&y<0) return 360-ans;
	if(x<0&&y>0) return 180-ans;
	if(x<0&&y<0) return 180+ans;
} 

void qujian(vector<P> &ans,double lb,double rb)
{
	if(lb<0)
	{
		ans.push_back(P(lb+360,360));
		ans.push_back(P(0,rb));
	}
	else if(rb>=lb) ans.push_back(P(lb,rb));
	else 
	{
		ans.push_back(P(lb,360));
		ans.push_back(P(0,rb));
	}
}

bool ask(vector<P> &a,vector<P> b) // b all in a ?
{
	sort(a.begin(),a.end());
	for(P p1:b)
	{
		for(P p2:a)
		{
			if(p2.second<p1.first) continue;
			if(p2.second==p1.first)
			{
				p1.first+=eps;
				if(p1.first>p1.second) break;
				continue;
			}
			if(p2.first>p1.first) return 0;
			p1.first=p2.second+eps;
			if(p1.first>p1.second) break;
		}
	}	
	return 1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=6;i++)
		{
			scanf("%d%d",x+i,y+i);
		}
		if(x[1]>x[2])
		{
			swap(x[1],x[2]);
			swap(y[1],y[2]);
		}
		vector<P> a,b;
		double du1=totheta(x[3]-x[1],y[3]-y[1]);
		double du2=totheta(x[4]-x[1],y[4]-y[1]);
		double du3=totheta(x[5]-x[1],y[5]-y[1]);
		double du4=totheta(x[6]-x[1],y[6]-y[1]);
		qujian(a,du1,du2);qujian(a,du3,du4);
		//printf("%.6lf %.6lf %.6lf %.6lf\n",du1,du2,du3,du4);
		for(P p:a) printf("%.6lf %.6lf\n",p.first,p.second);
		du1=totheta(x[3]-x[2],y[3]-y[2]);
		du2=totheta(x[4]-x[2],y[4]-y[2]);
		du3=totheta(x[5]-x[2],y[5]-y[2]);
		du4=totheta(x[6]-x[2],y[6]-y[2]);
		qujian(a,du1,du2);qujian(a,du3,du4);
		
		du1=totheta(x[2]-x[1],y[2]-y[1]);
		du2=totheta(x[1]-x[2],y[2]-y[1]);
		vector<P> tp1,tp2;
		tp1.push_back(P(du1,du1));
		tp2.push_back(P(du2,du2));
		if(!ask(a,tp1)&&!ask(b,tp2)) 
		{
			puts("0");
			continue;
		}
		
		tp1.clear();tp2.clear();
		
		qujian(tp1,du1,du1+90);
		qujian(tp2,du2-90,du2);
		if(!ask(a,tp1)&&!ask(b,tp2)) 
		{
			puts("1");
			continue;
		}
		
		tp1.clear();tp2.clear();
		qujian(tp1,du1-90,du1);
		qujian(tp2,du2,du2+90);
		if(!ask(a,tp1)&&!ask(b,tp2)) 
		{
			puts("1");
			continue;
		}
		puts("2");
	}
	return 0;
}

