#include<stdio.h>
#include<stdlib.h>
#define N 100

int n;
int limitw,totv,maxv;
int cop[N],option[N];

struct bag{
	int weight;
	int value;
}a[N];

void find(int k,int w,int v){
	int i;
	if(w+a[k].weight<limitw){
		cop[k]=1;               //第k件物品包含在内
		if(k<n-1)
			find(k+1,w+a[k].weight,v);
		else{
				for(i=0;i<n;i++)
					option[i]=cop[i];

				maxv=v;
		}
		cop[k]=0;               //第k件物品不包含
	}

	if(v-a[k].value>maxv){
		if(k<n-1)
			find(k+1,w,v-a[k].value);
		else{
				for(i=0;i<n;i++)
					option[i]=cop[i];

				maxv=v-a[k].value;
			}
	}
}

int main(){
	int w,v,i;

	printf("请输入物品的种类：");
	scanf("%d",&n);

	for(totv=0,i=0;i<n;i++){
		printf("请输入第%d件物品的重量和价值:",i+1);
		scanf("%d %d",&w,&v);
		a[i].weight=w;
		a[i].value=v;
		totv+=v;
	}

	printf("请输入背包的总重量：");
	scanf("%d",&limitw);

	maxv=0;
	find(0,0,totv);

	printf("最佳方案：\n");
	for(i=0;i<n;i++){
		if(option[i])
			printf("第%d件物品\n",i+1);
	}

	return 0;
}
