//O(1)���ٳ� 
ll mul2(ll x,ll y,ll p)
{
	ll res=(x*y-ll((long double)x/p*y+1.0e-8)*p);
	return res<0?res+p:res;
}

