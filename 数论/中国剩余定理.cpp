//m�ǳ���  r������  p�ǳ�����LCM(Ҳ���Ǵ𰸵�ѭ����) 
int CRT(int *m,int *r,int n)
{
	int p=m[0],res=r[0],x,y,g;
	for(int i=1;i<n;i++)
	{
		g=exgcd(p,m[i],x,y);
		if((r[i]-res)%g) return -1;//�޽� 
		x=(r[i]-res)/g*x%(m[i]/g);
		res+=x*p;
		p=p/g*m[i];
		res%=p;
    }
    return res>0?res:res+p;
}
