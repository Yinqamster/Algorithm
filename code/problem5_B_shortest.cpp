/*#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define size 500

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

int find(int x, int father[]){
	if(father[x]!=x)
		father[x]=find(father[x],father);
	return father[x];
}

int main() {
	int numV,numE;            //顶点数  边数
	int s,t;
	int sn1,sn2;
//	int max = 0;
	scanf("%d%d%d",&numV,&s,&t);
	int *vset = new int[numV];
	Edge graph[size];
	int i = 0,k = 0;
	while(scanf("%d",&graph[i].w) == 1) {
		scanf("%d%d",&graph[i].u,&graph[i].v);
		i++;
	}
	numE = i;
	make_heap(&graph[0], &graph[i],cmp);
	sort_heap(&graph[0], &graph[i],cmp);

	for (int j = 0; j < numV; j++) {
		vset[j] = j;
	}
//	k = 1;
	i = 0;
	while(i < numE) {
//		sn1 = vset[graph[i].u];
//		sn2 = vset[graph[i].v];
		sn1 = find(graph[i].u, vset);
		sn2 = find(graph[i].v, vset);
//		printf("%d %d\n",sn1,sn2);
		if (sn1 != sn2) {
			vset[sn1] = sn2;

	//		printf("%d ---> %d, %d\n",graph[i].u,graph[i].v,graph[i].w); 
 //           k++;  
   //         for (int j=0;j<numV;j++)  {  
     //           if (vset[j]==sn2) {  
       //             vset[j]=sn1;  
         //       }
				if (find(s,vset) == find(t,vset)) {
					printf("%d",graph[i].w);
					return 0;
//				}
            }  
		}	
		i++;
	}

//	printf("%d\n",k);
//	for (int j = 0; j < numE; j++) {
//		printf("%d %d %d\n",graph[j].u,graph[j].v,graph[j].w);
//	}
//	printf("%d %d\n",numV,numE);
//	printf("%d",max);
	return 0;
}
*/