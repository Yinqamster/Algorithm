#include <iostream>
using namespace std;
//#define N 5000000
//int a[N];
//int temp[N];
/*int main() {
	int k,n;
	cin>>k>>n;
	int *a = new int[n];
	
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
//寻找最大值
	int max = a[0], min = a[0];
	for(int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
//非比较的计数排序
	int *temp = new int[max - min + 1];      //容易内存超限
	
	for(int i = 0; i < max - min + 1; i++)
		temp[i] = 0;
	 for(int i=0;i<n;i++)
        temp[a[i] - min]++;
    int m=0;
    for (int i=0;i<max - min + 1;i++) {
      while(temp[i]-->0)
          a[m++]=i + min; 
    }
	
	if(n%2 == 0) {
		for (int i = n/2 - k - 1; i <n/2 + k - 1; i++)
			cout<<a[i]<<" ";
		cout<<a[n/2 + k - 1]<<endl;
	}
	else {
		for (int i = (n-1)/2 - k; i <(n-1)/2 + k; i++)
			cout<<a[i]<<" ";
		cout<<a[(n-1)/2 + k]<<endl;
	}
	delete[] temp;
	delete[] a;
	return 0;

//	for (int i = 0; i < n; i++)
//		cout<<a[i]<<" ";

}*/
/*#define max 18

int split(int x[], int first, int last) {
	int split_point, pivot;
	pivot = x[first];
	split_point = first;
	for (int i = first + 1; i <= last; i++)
		if (x[i] < pivot) {
			split_point++;
			int t = x[split_point];
			x[split_point] = x[i];
			x[i] = t;
		}
		x[first] = x[split_point];
		x[split_point] = pivot;
		return split_point;
}


void quick_sort(int x[], int first, int last) {
	if(first < last) {
		int split_point;
		split_point = split(x, first, last);
		for (int i = 0; i < max; i++)
			cout<<x[i]<<" ";
		cout<<endl;
		quick_sort(x, first, split_point-1);
		quick_sort(x, split_point+1, last);
	}
}

int main() {
	int n;
//	cin>>n;
	int *a = new int[max];
	for(int i = 0; i < max; i++) {
		cin>>a[i];
	}
	quick_sort(a,0,max-1);
//	for (int i = 0; i < max; i++)
//		cout<<a[i]<<" ";
}*/

/*
int main() {
	int k,n;
	cin>>k>>n;
	int *a = new int[n];
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	quick_sort(a,0,n-1);

//	for (int i = 0; i < n; i++)
//	cout<<a[i]<<" ";

	if(n%2 == 0) {
		for (int i = n/2 - k - 1; i <n/2 + k - 1; i++)
			cout<<a[i]<<" ";
		cout<<a[n/2 + k - 1]<<endl;
	}
	else {
		for (int i = (n-1)/2 - k; i <(n-1)/2 + k; i++)
			cout<<a[i]<<" ";
		cout<<a[(n-1)/2 + k]<<endl;
	}

	delete[] a;
	return 0;
}*/