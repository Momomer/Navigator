#include "../utility/data_structures.h"
#include <assert.h> 
#include <iostream>

namespace test_data_structures{
	//Tests insertion of an element into the list.	
	void test_add(){
		nav::LinkedList_Unrolled<int> list;

		for (int i=0;i<100;i++){
			list.add(i);
		}
		assert(list.getLength()==20 && "The number of nodes after insertion is not correct.");

	}

	//Tests removing elements from a list.
	void test_remove(){
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
	void test_search(){
		nav::LinkedList_Unrolled<int> list;
		for (int i=0;i<5;i++){
			list.add(i);
		}
		list.remove(0);
		assert(list.search(4) && "Error occured during searching the list.");
		assert(!list.search(0) && "Error occured during searching the list.");
	}

	//Runs all tests
	void run(){
		test_add();
		test_remove();
		test_search();
	}


}

