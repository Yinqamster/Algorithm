/*#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define size 500000

struct Edge {
	int u;        //起点
	int v;        //终点
	int w;       //权值
};

bool cmp(Edge a, Edge b) {
	if (a.w < b.w)
		return true;
	return false;
}

int main() {
	int numV,numE;            //顶点数  边数
	int sn1,sn2;
	int sumW = 0;
	int vset[size];
	scanf("%d",&numV);
	Edge graph[size];
	int sum = 0;
	int i = 0,k = 0;;
	while(scanf("%d",&graph[i].u) == 1) {
		scanf("%d%d",&graph[i].v,&graph[i].w);
		sum += graph[i].w;
		i++;
	}
	numE = i;
	make_heap(&graph[0], &graph[i],cmp);
	sort_heap(&graph[0], &graph[i],cmp);

	for (int j = 0; j < numV; j++) {
		vset[j] = j;
	}
	k = 1;
	i = 0;
	while(k < numV) {
		sn1 = vset[graph[i].u];
		sn2 = vset[graph[i].v];
		if (sn1 != sn2) {
//			printf("%d ---> %d, %d\n",graph[i].u,graph[i].v,graph[i].w); 
			sumW += graph[i].w;
            k++;  
            for (int j=0;j<numV;j++)  
            {  
                if (vset[j]==sn2)  
                {  
                    vset[j]=sn1;  
                }  
            }  
		}
		i++;
	}


//	for (int j = 0; j < numE; j++) {
//		printf("%d%d%d\n",graph[j].u,graph[j].v,graph[j].w);
//	}
//	printf("%d %d\n",sum,numE);
	printf("%d",sumW);
	return 0;
}*/