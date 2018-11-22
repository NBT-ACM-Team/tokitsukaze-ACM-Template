/*
ԭ������ 
1.һ����m�����ԭ��������ԭ������Ϊphi[phi[m]]����mΪ����������ԭ������Ϊphi[phi[m]]=phi[m-1]��
2.��ԭ������ֻ��2,4,p^n,2*p^n (pΪ����,nΪ������)
3.һ��������Сԭ���Ĵ�С��O(n^0.25)��
4.���gΪn��ԭ������g^dΪn��ԭ���ĳ�Ҫ������gcd(d,phi[n])=1

ָ�귨��
1. I(a*b)��I(a)+I(b) (mod p-1)
2. I(a^k)��k*I(a) (mod p-1)

*/


int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	mem(prime,0);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
        for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
ll pow2(ll a,ll b,ll p)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int tp[MAX];
int find_root(int x)//������ԭ��
{
	if(x==2) return 1;
    int f,phi=x-1;
    tp[0]=0;
    for(int i=0;phi&&i<tot;i++)
	{
        if(phi%p[i]==0)
		{
            tp[++tp[0]]=p[i];
            while(phi%p[i]==0) phi/=p[i];
        }
    }
    if(phi!=1) tp[++tp[0]]=phi;
    phi=x-1;
    for(int g=2;g<=x-1;g++)
	{
        f=1;
        for(int i=1;i<=tp[0];i++)
		{
            if(pow2(g,phi/tp[i],x)==1)
			{
                f=0;
                break;
            }
        }
        if(f) return g;
    }
    return 0;
}
int I[MAX];
void get_I(int p)//��ָ��� 
{
	int g,now;
	g=find_root(p);
	now=1;
	for(int i=1;i<p;i++)
	{
		now=now*g%p;
		I[now]=i;
	}
}
