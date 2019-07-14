#include "../utility/data_structures.h"
#include <assert.h> 
#include <iostream>

namespace test_data_structures{
	//Tests insertion of an element into the list.	
	void test_linked_list_add(){
		nav::LinkedList_Unrolled<int> list;

		for (int i=0;i<100;i++){
			list.add(i);
		}
		assert(list.getLength()==20 && "The number of nodes after insertion is not correct.");

	}

	//Tests removing elements from a list.
	void test_linked_list_remove(){
		nav::LinkedList_Unrolled<int> list;
		for (int i=0;i<100;i++){
			list.add(i);
		}
		for (int i=0;i<100;i++){
			list.remove(i);
		}
		assert(list.getLength()==0 && "The number of nodes after deletion is not correct.");
	}


	//Tests searching a list.
	void test_linked_list_search(){
		nav::LinkedList_Unrolled<int> list;
		for (int i=0;i<5;i++){
			list.add(i);
		}
		list.remove(0);
		assert(list.search(4) && "Error occured during searching the list.");
		assert(!list.search(0) && "Error occured during searching the list.");
	}

	//Tests, if heap property is maintained after random insertions and deletions
	void test_heap_correctness(){
		nav::Heap_Min<int> heap;
		for (int i=99;i>=0;i--){
			heap.add(i);
		}
		for (int i=0;i<100;i++){
			heap.extract();
		}
		const std::vector<int>& storage=heap.getHeap();
		for (int i=1;i<storage.size();i++){
			std::cout<<i<< " ";
			assert(storage[i]>storage[0.5*(i-1)] && "The min heap property is not maintained after sequences of insertions and extractions.");
		}
	}


	//Runs all tests
	void run(){
		test_linked_list_add();
		test_linked_list_remove();
		test_linked_list_search();
		test_heap_correctness();
	}


}

