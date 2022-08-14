#include <iostream>
#include <stdio.h>
/*
parent[i] = array[i/2]
left child[i] = array[i * 2]
right chilf[i] = arrray[i * 2 + 1]
*/
using namespace std;

class Binary_tree {
public:
	Binary_tree(long long buff_size) {
		buffer_size = buff_size;
		array = (long long*)malloc(buff_size * sizeof(long long));
		size = 0;
		swapping = 0;
		pair_of_swap = (long long*)malloc(buff_size * 8 * sizeof(long long));
	}

	void swap(long long* first, long long* second, long long* array) {
		long long temp = *first;
		*first = *second;
		*second = temp;
		pair_of_swap[swapping * 2] = first - array;
		pair_of_swap[swapping*2 + 1] = second - array;
		swapping++;
		//printf("%d %d\n", first - array, second - array);
	}

	int compare(long long first, long long second) {//1 меньше, то 1
		if(array[first] < array[second]) {
			return 1;
		} 
		return 0;
	}

	void sort_up(long long i) {
		while(i > 0) {
			if(compare(i, (i-1)/2)) {
				swap(array + (i-1)/2, array + i, array);
			}
			i =(i-1)/2;
		}
		//sort_up(i/2);
	}

	void sort_down(long long i) {
		long long left = 2*i + 1;
		long long right = 2*i + 2;
		if(right < size) {
			if(compare(right, i) && compare(left, i)) {
				if(compare(right, left)){
					swap(array + i, array+right, array);
					sort_down(right);
				}
				else {
					swap(array + i, array + left, array);
					sort_down(left);
				}
			} 
			else if(compare(right, i)){
				swap(array + i,array + right, array);
				sort_down(right);
			}
			else if(compare(left, i)) {
				swap(array + i, array + left, array);
				sort_down(left);
			}
		} else if(left < size){
			if(compare(left, i)){
				swap(array + i, array + left, array);
				sort_down(left);
			}
		}
	}

	void push_elem(long long elem) {
		array[size] = elem;
		//sort_up(size);
		size++;
	}

	void change_array() {
		for(int i = (size+1)/2; i >= 0 ; i--) {
			sort_down(i);
		}
		printf("%lld\n", swapping);
		for(long long i = 0; i < swapping; i++) {
			printf("%lld %lld\n", pair_of_swap[i * 2],pair_of_swap[i * 2 + 1]);
		}
	}

	long long get_size() {
		return size;
	}
	long long get_min() {
		return array[0];
	}
	long long hight() {
		long long curr = 1;
		int hight = 0;
		while(curr <= size) {
			curr*=2;
			hight++;
		}
		return hight;
	}
	void print_tree() {
		printf("[");
		for(long long i = 0; i < size; i++) {
			//printf("here ");
			printf("( %lld )", array[i]);
		}
		printf("]\n");
	}

protected:
	long long size;
	long long buffer_size;
	long long* array;
	long long swapping;
	long long* pair_of_swap;
}; 

int main() {
	int n;
	cin>>n;
	Binary_tree bin(n);
	
	for(int i = 0; i < n; i++) {
		long long a;
		cin>>a;		
		bin.push_elem(a);
	}
	bin.change_array();
	return 0;
} 
 
