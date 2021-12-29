#ifndef _pattern_h_
#define _pattern_h_

#include<iostream>
#include<algorithm> 
using namespace std;
const int MAX=50;
const int TIMES=6;
class Pattern{
	private:
		int a[MAX][MAX*TIMES];
		int line,first;
		int totalLenth,midLenth;
		static int nTotalNumber;
		static int nTotalArea;
	public:
		Pattern();
		Pattern(int line_,int first_);
		~Pattern();
		void Generate();
		void PrintOut();
};
int Pattern::nTotalNumber=0;
int Pattern::nTotalArea=0; 
Pattern::Pattern()
{
	line=first=totalLenth=midLenth=0;
	fill(a[0],a[0]+MAX*MAX*TIMES,0);
}
Pattern::Pattern(int line_,int first_)
{
	line=line_;
	first=first_;
	totalLenth=3*line_-2;
	midLenth=line_+line_/2-1+line_%2;
	fill(a[0],a[0]+MAX*MAX*TIMES,0);
}
Pattern::~Pattern()
{
}
void Pattern::Generate()
{
	for(int j=0;j<midLenth;++j)
		a[0][j]=(first+j)%10;
	for(int j=0;j<midLenth;++j)
		a[0][totalLenth-1-j]=a[0][j];
	for(int i=1;i<line;++i)
		for(int j=0;j<totalLenth;++j)
			a[i][j]=a[0][j];
}
void Pattern::PrintOut()
{
	for(int i=0;i<line;++i)
		for(int j=0;j<totalLenth-i;++j)
		{	if(i==0&&j==totalLenth-1) cout<<a[0][j]<<endl;
			else if(i==0&&j<totalLenth-1) cout<<a[0][j]<<" ";
			else if(i==line-1&&j==line*2-2) cout<<a[i][j]<<endl;
			else if(i==line-1&&j>line-2&&j<line*2-2) cout<<a[i][j]<<" ";
			else if(i!=0&&i!=line-1&&j==i) cout<<a[i][j]<<" ";
			else if(i!=0&&i!=line-1&&j==totalLenth-i-1) cout<<a[i][j]<<endl;
			else cout<<"  ";
		}
}

#endif
