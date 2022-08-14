#include <iostream>
#include <stdio.h>
/*
parent[i] = array[i/2]
left child[i] = array[i * 2]
right chilf[i] = arrray[i * 2 + 1]
*/
using namespace std;

struct doub
{
	long long time;
	long long number;
};

class Binary_tree {
public:
	Binary_tree(long long buff_size) {
		buffer_size = buff_size;
		array = (struct doub*)malloc(buff_size * sizeof(struct doub));
		size = 0;
	}

	void swap(struct doub* first, struct doub* second) {
		long long temp = first->time;
		long long proc = first->number;
		first->time = second->time;
		first->number = second->number;
		second->time = temp;
		second->number = proc;
	}

	int compare(long long first, long long second) {//1 меньше, то 1
		if(array[first].time < array[second].time) {
			return 1;
		} 
		if(array[first].time == array[second].time && array[first].number < array[second].number) {
			return 1;
		}
		return 0;
	}

	void sort_up(long long i) {
		while(i > 0) {
			if(compare(i, (i-1)/2)) {
				swap(array + i, array + (i-1)/2);
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
					swap(array + right, array+i);
					sort_down(right);
				}
				else {
					swap(array + left, array + i);
					sort_down(left);
				}
			} 
			else if(compare(right, i)){
				swap(array + i,array + right);
				sort_down(right);
			}
			else if(compare(left, i)) {
				swap(array + i, array + left);
				sort_down(left);
			}
		} else if(left < size){
			if(compare(left, i)){
				swap(array + left, array + i);
				sort_down(left);
			}
		}
	}

	void push_elem(long long elem) {
		if(elem == 0) {
			if(size == 0) {
				printf("0 0\n");
			} else if(size < buffer_size) {
				//array[size].number = size;
				printf("%lld %lld\n", size, 0);
			} else if(size == buffer_size) {
				printf("%lld %lld\n", array[0].number, array[0].time);
			}
		} else {
			if(size == 0) {
				array[size].number = size;
				array[size].time = elem;
				printf("%lld %lld\n",0, 0);
				size++;
			} else if(size < buffer_size) {
				array[size].number = size;
				array[size].time = elem;
				sort_up(size);
				size++;
				printf("%lld %lld\n", size - 1, 0);
			} else if(size == buffer_size) {
				printf("%lld %lld\n", array[0].number, array[0].time);
				array[0].time += elem;
				sort_down(0);
			}
		}
	}

	long long get_size() {
		return size;
	}
	int get_min() {
		return array[0].time;
	}
	int hight() {
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
			printf("( %d %d )", array[i].time, array[i].number);
		}
		printf("]\n");
	}

protected:
	long long size;
	long long buffer_size;
	struct doub* array;
}; 

int main() {
	int n,m;
	cin>>n>>m;
	Binary_tree bin(n);
	
	for(int i = 0; i < m; i++) {
		long long a;
		cin>>a;
		if(a >= 0) {
			bin.push_elem(a);
		}
	}

	return 0;
} 
 
