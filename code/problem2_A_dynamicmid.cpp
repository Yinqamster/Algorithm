/*#include <stdio.h>
#include <algorithm>
//#include <stdlib.h>
using namespace std;
#define size 600000

bool inc_cmp(int a,int b){ return a > b; }

int main() {
	int num;
	int counts = 0;
	int countb = 0;
	int s[size];
	int b[size];
	int root1,root2;
	scanf("%d", &root1);
	printf("%d ", root1);
	s[0] = root1;	
	if (scanf("%d",&root2) == 1) {
		b[0] = root1 > root2 ? root1 : root2;
		s[0] = root1 < root2 ? root1 : root2;
		make_heap(&b[0],&b[countb+1],inc_cmp);
	}
	else
		return 0;
	make_heap(&s[0],&s[counts+1]);
	
	printf("%d ", s[0]);

	while (scanf("%d",&num) == 1) {
		if (num < s[0]) {
			if (counts <= countb) {
				s[++counts] = num;
				push_heap(&s[0],&s[counts+1]);
			}
			else if (counts == countb + 1) {
				pop_heap(&s[0],&s[counts+1]);
				b[++countb] = s[counts];
				push_heap(&b[0],&b[countb+1],inc_cmp);
				s[counts] = num;
				push_heap(&s[0],&s[counts+1]);
			}
		}


		else if (num <= b[0] && num >= s[0]) {
			if (counts <= countb) {
				s[++counts] = num;
				push_heap(&s[0],&s[counts+1]);
			}
			else if (counts == countb + 1) {
				b[++countb] = num;
				push_heap(&b[0],&b[countb+1],inc_cmp);
			}
		}
		else if (num > b[0]) {
			if (countb <= counts) {
				b[++countb] = num;
				push_heap(&b[0],&b[countb+1],inc_cmp);
			}
			else if (countb == counts + 1) {
				pop_heap(&b[0],&b[countb+1],inc_cmp);
				s[++counts] = b[countb];
				push_heap(&s[0],&s[counts+1]);
				b[countb] = num;
				push_heap(&b[0],&b[countb+1],inc_cmp);
			}
		}
		if (counts == countb)
			printf("%d ",s[0]);
		else
			printf("%d ",counts > countb ? s[0] : b[0]);

	}
	return 0;
}*/