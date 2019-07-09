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

	void test_remove(){
		nav::LinkedList_Unrolled<int> list;
		for (int i=0;i<100;i++){
			list.add(i);
		}
		for (int i=0;i<100;i++){
			list.remove(i);
		}
		std::cout<<"LENGTH:"<<list.getLength()<<"\n"<<std::endl;
		std::cout<<list<<"\n";
		assert(list.getLength()==0 && "The number of nodes after deletion is not correct.");

	}

	void run(){
		test_add();
		test_remove();
	}


}

