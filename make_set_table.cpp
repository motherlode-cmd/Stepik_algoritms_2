#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <string>
using namespace std;

class Min_set {

public:
    Min_set(int isize) {
    	size_ = isize;
       sizes = new int[size_];
       link = new int[size_];
       max_size = 0;
    }
    ~Min_set() {
    }
    void union_(int in, int what) {
    	int i = in-1;
    	int j = what-1;
    	if(i == j && link[j] != j) {
    		int temp_size = sizes[link[j]];
    		sizes[link[j]] = 0;
    		sizes[i] = temp_size;
    		int set = link[j];
    		for(int t = 0; t < size_; t++) {
    			if(link[t] == set) {
    				link[t] = i;
    			}
    		}
    	} else if(link[j] == i ) {

    	} else if(link[i] == link[j]) {
    		int set = link[i];
    		int temp_size = sizes[link[i]];
    		sizes[link[i]] = 0;
    		sizes[i] += temp_size;
    		for(int t = 0; t < size_; t++) {
    			if(link[t] == set) {
    				link[t] = i;
    			}
    		}
    	} else if(link[j] == j && link[i] == i) {
    		for(int t = 0; t < size_; t++) {
    			if(link[t] == j && t != i){
		        	link[t] = i;
		        	sizes[i] += sizes[t];
		        	sizes[t] = 0;
		        }
	        }
        } else if(link[j] != j && link[i] == i) {
        	int set = link[j];
        	for(int t = 0; t < size_; t++) {
        		if(link[t] == set && t != i) {
        			//printf("\nhere\n");
        			link[t] = i;
        			sizes[i] += sizes[t];
        			sizes[t] = 0;
        		}
      		}
        } else if(link[j] == j && link[i] != i) {
        	int set = link[i];
        	for(int t = 0; t < size_; t++) {
        		if(t != i && (link[t] == set || link[t] == j)) {
        			link[t] = i;
        			sizes[i] += sizes[t];
        			sizes[t] = 0;
        		}
        	}
        	link[i] = i;
        } else if(link[j] != j && link[i] != i) {
        	int set = link[j];
        	int set_2 = link[i];
        	for(int t = 0; t < size_; t++) {
        		if(t != i && (link[t] == set || link[t] == set_2)) {
        			link[t] = i;
        			sizes[i] += sizes[t];
        			sizes[t] = 0;
        		}
        	}
        	link[i] = i;
        }
       
        if(sizes[i] > max_size) max_size = sizes[i];
        
        printf("%d\n", max_size);
    }	
    void make_set(int* array) {
    	for(int i = 0; i < size_; i++) {
    		if(max_size < array[i]) {
    			max_size = array[i];
    		}
    		sizes[i] = array[i];
    		link[i] = i;
    	}
    }
    void print_set() {
    	printf("\n");
    	for(int i = 0; i < size_; i++) {
    		printf("{%d -> %d} ", i + 1, link[i] + 1);
    	}
    	printf("\n");
    	for(int i = 0; i < size_; i++) {
    		printf("{%d size } ",sizes[i]);
    	}
    }
	// методы push, pop, size, empty, top + конструкторы, деструктор
private:
	// поля класса, к которым не должно быть доступа извне
protected:  // в этом блоке должен быть указатель на голову
    int* sizes;
    int* link;
    int size_;
    int max_size;
};


int main() {
	int n, m;
	cin>>n>>m;
	Min_set a(n);
	int* b = new int[n];
	for(int i = 0; i < n; i++) {
		cin>>b[i];
	}
	a.make_set(b);
	//a.print_set();
	for(int i = 0; i < m; i++) {
		int in, what;
		cin>>in>>what;
		a.union_(in, what);
		//a.print_set();
	}
	//a.print_set();
	return 0;
}
 
