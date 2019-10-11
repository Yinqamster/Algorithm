/*#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

vector<char> vec;

int main() {
	char src;
	int num = 0;
	while(scanf("%c",&src) == 1) {
		if (src != ' ') {
			vec.push_back(src);
		}
	}
	num = vec.size()-1;
	char *vec2 = new char[num];
	for (int i = 0; i < num; i++) {
		vec2[i] = vec[num-i-1];
	}

	short **arr; 
	arr = new short*[num+1]; 
	for(int i=0;i<=num;i++){
	   arr[i] = new short[num+1]; 
	}

	for (int i = 1; i <= num; i++)
		arr[i][0] = 0;
	for (int j = 0; j <= num; j++)
		arr[0][j] = 0;

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if (vec[i-1] == vec2[j-1])
				arr[i][j] = arr[i-1][j-1] + 1;
			else if (arr[i-1][j] >= arr[i][j-1])
				arr[i][j] = arr[i-1][j];
			else
				arr[i][j] = arr[i][j-1];
		}
	}
*/

/*	for (int i = 0; i <= num; i++) {
		for(int j = 0; j <= num; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}*/

//	cout<<arr[num][num]<<endl;
/*	for (int i = 0; i < num; i++)
		printf("%c ",vec[i]);
	for (int i = 0; i < num; i++)
		printf("%c ",vec2[i]);*/
//}