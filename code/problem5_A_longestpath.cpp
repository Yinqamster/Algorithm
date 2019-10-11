/*#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include<queue>
using namespace std;

queue<int>q;
struct Edge {
	int dest;
	int weight;
//	struct Edge* next;
};
struct Vertex {
	int data;
	int res;
	int indegree;
//	struct Edge* adj;
	vector<Edge> vec;
};

void topo(int num, Vertex table[], int tp[]) {
	q.push(0);
	int base = 0;
	int k = 0;
	while (q.empty() != 1) {
		int temp0 = q.front();
		tp[k] = temp0;
		k++;
		q.pop();
		if (table[temp0].vec.empty() != 1) {
			for (int i = 0; i < table[temp0].vec.size(); i++) {
				table[table[temp0].vec.at(i).dest].indegree--;
				int a = table[table[temp0].vec.at(i).dest].res;
				int b = table[temp0].vec.at(i).weight + table[temp0].res;
				table[table[temp0].vec.at(i).dest].res = a > b ? a : b;
				if(table[table[temp0].vec.at(i).dest].indegree == 0) {
					q.push(table[temp0].vec.at(i).dest);
					a = table[table[temp0].vec.at(i).dest].res;
					b = table[temp0].res + table[temp0].vec.at(i).weight;
					table[table[temp0].vec.at(i).dest].res = a > b ? a : b;
				}
			}
		}
//		for (int i = 0; i < table[temp0].vec.size(); i++) {
//			if (table[temp0].vec.at(i).dest == q.front()) {
//				base = base + table[temp0].vec.at(i).weight;
//				table[table[temp0].vec.at(i).dest].res = base;
//			}
//		}

	}
}

int main() {
	int num;
	scanf("%d",&num);
	Vertex *table = new Vertex[num];
	int *tp = new int[num];
//	tp[0] = 0;
	for (int i = 0; i < num; i++) {
		table[i].data = i;
//		table[i].adj = NULL;
		table[i].res = 0;
		table[i].indegree = 0;
//		table[i].vec = 0;
//		res[i] = 0;
	}
	
	int src,des,wei;
	while(scanf("%d",&src) == 1) {
		scanf("%d%d",&des,&wei);
		Edge p;
		p.dest = des;
		p.weight = wei;
		table[src].vec.push_back(p);
	}
	for (int i = 0; i < num; i++) {
		if(table[i].vec.empty() != 1) {
			for (int j = 0; j < table[i].vec.size(); j++) 
				table[table[i].vec.at(j).dest].indegree++;
		}
	}*/
/*	for (int i = 0; i < num; i ++) {
		printf("%d ",table[i].indegree);
	}*/
//	topo(num,table,tp);
/*	int base = 0;
	for (int j = 0; j < num-1; j++) {
		for (int i = 0; i < table[tp[j]].vec.size(); i++) {
				if (table[tp[j]].vec.at(i).dest == tp[j+1]) {
					base = base + table[tp[j]].vec.at(i).weight;
					table[tp[j+1]].res = base;
				}
			}
	}*/


/*	printf("%d\n",num);
	for (int i = 0; i < num; i ++) {
		printf("%d %d %d %d\n",table[i].data,table[i].indegree,table[i].res,table[i].vec.size());
		if(table[i].vec.empty() != 1) {
			for (int j = 0; j < table[i].vec.size(); j++) 
				printf("%d %d\n",table[i].vec[j].dest,table[i].vec[j].weight);
		}
	}*/
//	for (int i = 0; i < num; i++) {
//		printf("%d\n",table[i].vec.size());
//	}
//	printf("%d %d\n",table[0].vec.at(3).dest,table[0].vec.at(3).weight);
/*	for (int i = 1; i < num; i++) 
		printf("%d ",table[i].res);
	return 0;
}*/