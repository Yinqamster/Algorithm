/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int compare(const void *a,const void *b) {
     return *(char *)a - *(char *)b;
}

void inSort(char* x[], int i, char *str1) {
	char str[50];
	int n = strlen(x[i]);
	for (int j = 0; j < n; j++)
		str[j] = x[i][j];
	str[n] = '\0';
	qsort((void *)str,n,sizeof(char),compare);
	strncpy(str1, str,sizeof(str));
}

int split(char* x[], int first, int last) {
	int split_point;
	char* pivot = new char[50];
	char* pivot0 = new char[50];
	strcpy(pivot0, x[first]);
	inSort(x,first,pivot);
	split_point = first;
	for (int i = first + 1; i <= last; i++) {
		char* str1 = new char[50];
		inSort(x,i,str1);
		if (strcmp(str1, pivot)<0) {
			split_point++;
			char* t = new char[50];
			strcpy(t, x[split_point]);
			strcpy(x[split_point], x[i]);
			strcpy(x[i], t);
			delete t;
		}
		delete str1;
	}
		strcpy(x[first], x[split_point]);
		strcpy(x[split_point], pivot0);
		delete pivot;
		delete pivot0;
		return split_point;
}


void quick_sort(char* x[], int first, int last) {
	if(first < last) {
		int split_point;
		split_point = split(x, first, last);
		quick_sort(x, first, split_point-1);
		quick_sort(x, split_point+1, last);
	}
}


int Split(char* x[], int first, int last) {
	int split_point;
	char* pivot = new char[50];
	strcpy(pivot, x[first]);
	split_point = first;
	for (int i = first + 1; i <= last; i++)
		if (strcmp(x[i], pivot)<0) {
			split_point++;
			char* t = new char[50];
			strcpy(t, x[split_point]);
			strcpy(x[split_point], x[i]);
			strcpy(x[i], t);
			delete t;
		}
		strcpy(x[first], x[split_point]);
		strcpy(x[split_point], pivot);
		delete pivot;
		return split_point;
}


void quickSort(char* x[], int first, int last) {
	if(first < last) {
		int split_point;
		split_point = Split(x, first, last);
		quickSort(x, first, split_point-1);
		quickSort(x, split_point+1, last);
	}
}


int main() {
	int num;
	scanf("%d",&num);
	char **wordsBefore = new char*[num];
	char **res = new char*[num];
	for (int i = 0; i < num; i++) {
		wordsBefore[i] = new char[50];
	}
	for (int i = 0; i < num; i++) {
		res[i] = new char[50];
	}

	int i = 0;
	while (i < num) {
		scanf("%s",wordsBefore[i]);
		i++;
	}
	
	quick_sort(wordsBefore, 0, num-1);

	i = 1;
	int count = 0;

	while (i < num) {
//		printf("%d\n",i);
		char *str = new char[50];
		char *str0 = new char[50];
		inSort(wordsBefore,i,str);
		inSort(wordsBefore,i-1,str0);
//		printf("%s %s\n",str0,str);
		if (strcmp(str, str0) == 0) {
			int j = i - 1;	
			while(strcmp(str, str0) == 0 && i < num - 1) {
				i++;
				inSort(wordsBefore,i,str);
				inSort(wordsBefore,i-1,str0);
//				printf("%s %s\n",str0,str);
			}
			if (i == num - 1 && strcmp(str, str0) == 0) {
				quickSort(wordsBefore, j, i);
				i++;
			}
			else
				quickSort(wordsBefore, j, i-1);
			strcpy(res[count],wordsBefore[j]);
//			k++;
//			printf("%s\n",wordsBefore[j]);
			count++;
		}
		else {
			i++;
		}
		delete str;
		delete str0;
	}
//	for (int i = 0; i < count; i++)
//		printf("%s ",res[i]);
	printf("%d\n",count);
	quickSort(res, 0, count-1);
	for (int t = 0; t < count; t++) {
		printf("%s\n",res[t]);
	}
	return 0;
}*/