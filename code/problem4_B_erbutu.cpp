/*#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define size 100000

struct graphNode {
	int num;
	int color;
};

int main() {
	graphNode a[size];
	int b[1000];	
	char s[10000];

	for (int i = 0; i < size; i++) {
		a[i].num = i;
		a[i].color = -1;
	}
	a[0].color = 1;
	while(gets(s)) {
		int n = 0;       //读入一行的数字个数
//		cout<<s<<endl;
		char *tokenS = strtok(s," ");
		while(tokenS != NULL) {
	//		cout<<tokenS<<endl;
			b[n] = atoi(tokenS);
			n++;
			tokenS = strtok(NULL, " ");
		}

//		for (int i = 0; i < n; i++)
//			cout<<b[i]<<" ";
		
		//chu li er bu tu
//		if (a[b[0]].num == 0) {
//			a[b[0]].color = 1;         //1 is red
//			for (int i = 1; i < n; i++) {
//				a[b[i]].color = 2;       //2 is blue
//			}
//		}

		if (a[b[0]].color == 1) {
			for (int i = 1; i < n; i++) {
				if (a[b[i]].color == -1)
					a[b[i]].color = 2;       //2 is blue
				else if (a[b[i]].color == 1)
					return 0;
			}
		}
		else if (a[b[0]].color == 2) {
			for (int i = 1; i < n; i++) {
				if (a[b[i]].color == -1)
					a[b[i]].color = 1;       //2 is blue
				else if (a[b[i]].color == 2)
					return 0;
			}
		}
		else if (a[b[0]].color == -1) {
			for (int i = 1; i < n; i++) {
				if(a[b[i]].color == -1);
				else if(a[b[i]].color == 1) {
					a[b[0]].color = 2;
					break;
				}
				else if(a[b[i]].color == 2) {
					a[b[0]].color = 1;
					break;
				}
			}
			if (a[b[0]].color == 1) {
				for (int i = 1; i < n; i++) {
					if (a[b[i]].color == -1)
						a[b[i]].color = 2;       //2 is blue
					else if (a[b[i]].color == 1)
						return 0;
				}
			}
			else if (a[b[0]].color == 2) {
				for (int i = 1; i < n; i++) {
					if (a[b[i]].color == -1)
						a[b[i]].color = 1;       //2 is blue
					else if (a[b[i]].color == 2)
						return 0;
				}
			}
		}
	}

//	for (int i = 0; a[i].color != -1; i++)
//		cout<<a[i].num<<" "<<a[i].color<<endl;
	for (int i = 0; a[i].color != -1; i++) {
		if (a[i].color == 1)
			cout<<a[i].num<<endl;
	}
	return 0;
}

*/