#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<algorithm> 
#include<vector> 
using namespace std;
#define max 100      //200000

vector<int>table[max]; 
int visit[2][max]; 

void solve(int num) {
	for (int i = num-1; i >= 0; i--) {
		if (table[i].size() == 0) {
			visit[0][i] = 0;
			visit[1][i] = 1;
		}
		else {
			for (int j = 0; j < table[i].size(); j++) {
				int a = table[i][j];
				visit[0][i] += visit[1][a];
				visit[1][i] += visit[0][a] < visit[1][a] ? visit[0][a] : visit[1][a];
			}
		}
		
	}
}

int main() {
	int num = 0;
	char *s = new char[1000];
	while(gets(s)) {
		char *tokenS = strtok(s," ");
		int data = atoi(tokenS);
		if (tokenS != NULL)
			tokenS = strtok(NULL, " ");
		while(tokenS != NULL) {
			table[data].push_back(atoi(tokenS));
			tokenS = strtok(NULL, " ");
		}
		num++;
	}
	for (int i = 0; i < num; i++)
			visit[0][i] = 0;
	for (int i = 0; i < num; i++)
			visit[1][i] = 1;

	solve(num);

	int res = visit[0][0] < visit[1][0] ? visit[0][0] : visit[1][0];
	cout<<res<<endl;


/*	for (int i = 0; i < 2; i++){
		for (int j = 0; j < num; j++) 
			cout<<visit[i][j]<<" ";
		cout<<endl;
	}*/
/*	for (int i = 0; i < num; i ++) {
		printf("%d %d ",table[i].size(),i);
		if(table[i].empty() != 1) {
			for (int j = 0; j < table[i].size(); j++) 
				printf("%d ",table[i][j]);
		}
		cout<<endl;
	}*/
}