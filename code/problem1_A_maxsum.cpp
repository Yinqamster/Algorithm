/*#include <iostream>
using namespace std;
#define N 100000

int main() {
	int k,n = 0;
	int a[N] = {0};
	while(cin>>k) {
		a[n] = k;
		n++;
	}
	int maxsum = 0;
	int thissum = 0;
	for (int i = 0; i < n - 1; i++) {
		thissum += a[i];
		if(thissum > maxsum)
			maxsum = thissum;
		else if(thissum < 0)
			thissum = 0;
	}
	cout<<maxsum<<endl;
	return 0;
}*/