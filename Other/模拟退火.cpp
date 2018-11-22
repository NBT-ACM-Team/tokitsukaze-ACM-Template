//ģ���˻�

//1.�򵥰� ->ģ���˻�������

//2.���Ӱ� 
//�����������һ�㵽�������֮�����
//ʱ�临�Ӷ� cnt*c1*c2*n 
int sgn(double x)
{  
	if(fabs(x)<eps) return 0;
	else return x>0?1:-1;  
}
struct Point
{  
	double x,y;
	Point(){}
	Point(double a,double b)
	{
		x=a;
		y=b;
	}
	void input()
	{
		scanf("%lf%lf",&x,&y);
	}
};
typedef Point Vector;
Vector operator -(Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double dist(Point a,Point b){return sqrt(dot(a-b,a-b));}
double lx,ly;//��������(0,0)-(lx,ly) 
int check(double x,double y)
{
	if(sgn(x)<0||sgn(y)<0||sgn(x-lx)>0||sgn(y-ly)>0) return 1;
	return 0;
}
double Rand(double r,double l)
{  
	return(rand()%((int)(l-r)*1000))/(1000.0+r);  
}
double getres(Point t,Point *p,int n)//�����֮�� 
{
	double res=0;
	for(int i=0;i<n;i++)
	{  
		res+=dist(t,p[i]);
	}
	return res;
}
pair<Point,double> SA(Point *p,int n)//ģ���˻� 
{
	srand(time(0));//����������� 
	const double k=0.85;//�˻��� 
	const int c1=30;//���ȡ��ĸ��� 
	const int c2=50;//�˻���� 
	Point q[c1+10];//���ȡ�� 
	double dis[c1+10];//ÿ����ļ����� 
	int i,j;
	for(i=1;i<=c1;i++)
	{  
		q[i]=Point(Rand(0,lx),Rand(0,ly));
		dis[i]=getres(q[i],p,n);
	}
	double tmax=max(lx,ly);
	double tmin=1e-3;
//	int cnt=0;//�������ѭ������ 
	while(tmax>tmin)  
	{
		for(i=1;i<=c1;i++)
		{
			for(j=1;j<=c2;j++)
			{
				double ang=Rand(0,2*PI);  
				Point z;
				z.x=q[i].x+cos(ang)*tmax;
				z.y=q[i].y+sin(ang)*tmax;
				if(check(z.x,z.y)) continue;
				double temp=getres(z,p,n);
				if(temp<dis[i])
				{
					dis[i]=temp;
					q[i]=z;
				}
			}
		}
//		cnt++;
		tmax*=k;
	}
//	cout<<cnt*c1*c2*n<<endl;//ʱ�临�Ӷ� 
	int pos=1;
	for(i=2;i<=c1;i++)
	{
		if(dis[i]<dis[pos])
		{
			pos=i;
		}
	}
	pair<Point,double> res;
	res=make_pair(q[pos],dis[pos]);
	return res;
}
