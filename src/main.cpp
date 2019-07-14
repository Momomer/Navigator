#include <iostream>
#include<vector>
#include "utility/data_structures.h"

/*Creates an unrolled linked list.*/
int main(){
	auto list=nav::LinkedList_Unrolled<int>();
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	list.add(7);
	list.add(8);
	list.add(9);
	list.add(10);
	list.add(11);
	//std::cout<<"Content of the list:\n";
	//std::cout<<list<<"\n";
	
	std::vector<int> v={9,2,4,6,1,3};
	auto heap=nav::Heap_Min<int>();
	heap.add(9);
	heap.add(2);
	heap.add(4);
	heap.add(6);
	heap.add(1);
	heap.add(3);
	heap.extract();
	std::cout<<heap;
}
