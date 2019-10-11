/*#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<stack>
#include<queue>
using namespace std;

#define size 20000

struct Edge {
	int dest;
	struct Edge* next;
};
struct Vertex {
	int data;
	int influ;
	int scc;
	int visit;
	int ok;
	struct Edge* adj;
};

int orderNum;        //time of visit
int sccNum;           //the total num of scc
int maxNum;                  //judge the total num, if there is no number at last line
stack<int> Path;
stack<int> Root;
Vertex nodeTable[size];
Vertex sccTable[size];
queue<int>q;
int bfs[size];
int scc[size][2];

void findScc (int v) {
	nodeTable[v].visit = ++orderNum;
	Path.push(v);
	Root.push(v);

	Edge *p = nodeTable[v].adj;
	while(p != NULL) {
		if (nodeTable[p->dest].visit == -1) {
			findScc(p->dest);
		}
		else if (nodeTable[p->dest].scc == -1) {
			while(nodeTable[Root.top()].visit > nodeTable[p->dest].visit)
				Root.pop();
		}
		p = p->next;
	}
	
	if (Root.top() == v) {
		int count = 0;
		Root.pop();
		sccNum++;
		int top;
		do {
			count++;
			top = Path.top();
			nodeTable[top].scc = sccNum;
			Path.pop();
		}while (top != v);
		scc[sccNum][0] = sccNum;
		scc[sccNum][1] = count;
//		for (int i = 0; i <= maxNum; i++) {
//			if (nodeTable[i].scc == sccNum) {
//				nodeTable[i].influ = count;
//				sccTable[sccNum].influ = count - 1;
//				sccTable[sccNum].visit =i;
//			}
//		}
	}
}

int a;
int b = -1;
void BFS(int n)  {
//	q.push(n);
	Edge *p = sccTable[n].adj;
	while(p != NULL) {
//		for (int i = 0; i <= a)
		q.push(p->dest);
		p = p->next;
	}
	while (q.empty() != 1) {
		int t = q.front();
//		cout<<t<<endl;
		q.pop();
		for (int i = 0; i <= a; i++) {
			if (bfs[i] == t) {
				b = 1;
				break;
			}
			else
				b = -1;
		}
		if (b == -1) {
			bfs[++a] = t;
			BFS(t);
		}
	}
}

//int find(int a) {
//	for (int i = 0; i <= maxNum; i++) {
//		if (nodeTable[i].scc == a)
//			return nodeTable[i].influ;
//	}
//}

int main() {
	//initialize nodeTable
	for (int i = 0; i < size; i++) {
		nodeTable[i].adj = NULL;
		nodeTable[i].data = i;
		nodeTable[i].visit = -1;
		nodeTable[i].scc = -1;
		sccTable[i].data = i;
		sccTable[i].adj = NULL;
		sccTable[i].ok = -1;
		bfs[i] = -1;
	}

	orderNum = 0;  
	sccNum = 0;   
	maxNum = 0; 
	a = -1;
	b = -1;


	

	int n = 0;              //hang shu
	char s[10000];

	//input
	while(gets(s)) {
		char *tokenS = strtok(s," ");
		while(tokenS != NULL) {
	//		cout<<tokenS<<endl;
			Edge *p = new Edge;
			p->dest = atoi(tokenS);
			maxNum = p->dest > maxNum ? p->dest : maxNum;
			p->next = NULL;
			p->next = nodeTable[n].adj;
			nodeTable[n].adj = p;
			tokenS = strtok(NULL, " ");
		}
		n++;
	}
	maxNum = n - 1 > maxNum ? n - 1 : maxNum;
	//find scc
	for (int i = 0; i <= maxNum; i++) {
		if (nodeTable[i].visit == -1)
			findScc(i);
	}


	for (int i = 0; i <= maxNum; i++) {
		
//		if (nodeTable[i].scc == scc[nodeTable[i].scc][0]) {
		nodeTable[i].influ = scc[nodeTable[i].scc][1];
		sccTable[nodeTable[i].scc].influ = nodeTable[i].influ - 1;
		sccTable[nodeTable[i].scc].visit =i;
//		}
	}

//	for (int i = 1; i <= sccNum; i++) {
		
//		sccTable[i].influ = find(i) - 1;
//	}

	//output  test
//	cout<<maxNum<<endl;

	for (int i = 0; i <= maxNum; i++) {
		cout<<nodeTable[i].data<<" ";
		Edge *p = nodeTable[i].adj;
		while(p != NULL) {
			cout<<p->dest<<" ";
			p = p->next;
		}
		cout<<endl;
	}

	for (int i = 1; i <= sccNum; i++) {
		cout<<i<<" ";
		for (int j = 0; j < n; j++) {
			if (nodeTable[j].scc == i)
				cout<<nodeTable[j].data<<" ";
		}
		cout<<endl;
	}

//	for (int i = 0; i <= maxNum; i++) {
//		cout<<nodeTable[i].data<<" "<<nodeTable[i].scc<<" "<<nodeTable[i].visit<<" "<<nodeTable[i].influ<<endl;
//	}



	//creat a graph with scc
	
	int flag = -1;
	for (int i = 0; i <= maxNum; i++) {
		Edge *p = nodeTable[i].adj;
		while(p != NULL) {
			if (nodeTable[p->dest].scc != nodeTable[i].scc) {
				Edge *q = new Edge;
				q = sccTable[nodeTable[i].scc].adj;
				while(q != NULL) {
					if (q->dest != nodeTable[p->dest].scc)
						q = q->next;
					else {
						flag = 1;
						q = q->next;
					}
				}
				if (q == NULL && flag != 1) {
					Edge *t = new Edge;
					t->next = NULL;
					t->dest = nodeTable[p->dest].scc;
					t->next = sccTable[nodeTable[i].scc].adj;
					sccTable[nodeTable[i].scc].adj = t;
				}
			}
			p = p->next;
			flag = -1;
		}
	}



	int max = 0;
	int t = -1;
	int sccCount[size];
	for (int i = 0; i < size; i++) {
		sccCount[i] = -1;
	}
	if (sccNum == 1) {
		max = nodeTable[0].influ-1;
		sccCount[++t] = 1;
	}
	else {
		for (int i = 1; i <= sccNum; i++) {
			BFS(i);
			for (int j = 0; j <= a; j++) {
//				if (sccTable[bfs[j]].ok != 1) {
					sccTable[i].influ += nodeTable[sccTable[bfs[j]].visit].influ;
					max = sccTable[i].influ > max ? sccTable[i].influ : max;
//				}
//				sccTable[bfs[j]].ok = 1;
			}

//			for (int j = 1; j <= sccNum; j++) {
//				sccTable[j].ok = -1;
//			}
			
			for (int j = 0; j <= a; j++)
				cout<<bfs[j]<<" ";
			cout<<endl;

			for (int j = 0; j <= a; j++) {
				bfs[j] = -1;
			}
			a = -1;
			b = -1;
			
		}
		for (int i = 1; i <= sccNum; i++) {
		if (sccTable[i].influ == max) {
	//		cout<<sccTable[i].data<<endl;
			sccCount[++t] = sccTable[i].data;
		}
	}
	}
	

	//output test
//	cout<<"scc"<<sccNum<<endl;
	for (int i = 1; i <= sccNum; i++) {
		cout<<sccTable[i].data<<" "<<sccTable[i].influ<<" "<<sccTable[i].visit<<" ";
		Edge *p = sccTable[i].adj;
		while(p != NULL) {
			cout<<p->dest<<" ";
			p = p->next;
		}
		cout<<endl;
	}
	

	cout<<max<<endl;
	for (int i = 0; i <= maxNum; i++) {
		for (int j = 0; sccCount[j] != -1; j++) {
			if (nodeTable[i].scc == sccCount[j])
				cout<<nodeTable[i].data<<" ";
		}
	}	
	return 0;
}*/