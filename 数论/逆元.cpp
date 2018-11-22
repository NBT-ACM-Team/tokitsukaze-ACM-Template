/*
1.����С���� 
����:modΪ���� 
*/
ll inv(ll x,ll p){return pow2(x,p-2);}

/*
2.��չŷ�����
����:gcd(a,mod)==1
���gcd(a,mod)!=1 ����-1 
*/
ll inv(ll a,ll p)
{
	ll g,x,y;
	g=exgcd(a,p,x,y);
	return g==1?(x+p)%p:-1;
}

/*
3.��ʽ
a/b%mod=c
->a%(b*mod)/b=c 
*/

/*
4.��Ԫ���
p��ģ 
pҪ���������� 
*/
ll inv[MAX];
void getinv(int n,ll p)
{
	ll i;
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=(p-p/i)*inv[p%i]%p;
}
