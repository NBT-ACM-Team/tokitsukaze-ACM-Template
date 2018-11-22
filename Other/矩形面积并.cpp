//���������
struct node
{
	ll l,r,h;
	int tag;
	friend bool operator <(node a,node b)
	{
		return a.h<b.h;
	}
}seg[MAX<<1];//�߶� 
ll x[MAX<<1];//��������ɢ�� 
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	ll n,ql,qr,qv;
	ll cover[MAX<<3],len[MAX<<3];//ע������Ҫ��8�� 
	void build(ll _n)
	{
		mem(cover,0);
		mem(len,0);
		n=_n;
	}
	void callen(int id,int l,int r)
	{
		if(cover[id]) len[id]=x[r+1]-x[l];//�����θ���
		else if(l==r) len[id]=0;//����һ���߶�
		else len[id]=len[ls]+len[rs];//��һ���߶ε���û�б����θ��� 
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			cover[id]+=qv;//�������
			callen(id,l,r);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		callen(id,l,r);
	}
}tree;
int main()
{
	int n,i,tot,l,r,cnt;
	ll x1,y1,x2,y2,ans;
	while(~scanf("%d",&n)&&n)
	{
		tot=0;
		mem(x,0);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
			//���ε����º��������� 
			x[tot]=x1;
			seg[tot].tag=-1; 
			seg[tot].l=x1;
			seg[tot].r=x2;
			seg[tot++].h=y1;
			//�ϱ߽� 
			x[tot]=x2;
			seg[tot].tag=1;
			seg[tot].l=x1;
			seg[tot].r=x2;
			seg[tot++].h=y2;
			//�±߽� 
		}
		sort(seg,seg+tot);//�߶ΰ����������� 
		sort(x,x+tot);//����������
		cnt=unique(x,x+tot)-x;
		tree.build(cnt-1);
		ans=0;
		for(i=0;i<tot;i++)
		{
			if(i) ans+=(seg[i].h-seg[i-1].h)*tree.len[1];
			tree.ql=lower_bound(x,x+cnt-1,seg[i].l)-x;
			tree.qr=lower_bound(x,x+cnt-1,seg[i].r)-x-1;
			tree.qv=seg[i].tag;
			tree.update(0,cnt-1,1);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
