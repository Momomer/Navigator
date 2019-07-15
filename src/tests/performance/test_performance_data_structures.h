#include "../../utility/data_structures.h"
#include <random>
#include <iostream>
#include<chrono>
#include<thread>
#include<string>

namespace test_performance_data_structures{
	//Measures insertion time of elements into the list.	
	void test_add(long int range_upper,long int n){
		nav::LinkedList_Unrolled<int> list;
		// Record start time
		auto start = std::chrono::high_resolution_clock::now();
		
		for (int i=0;i<n;i++){
			list.add(i);
		}

		// Record end time
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::string out=std::string("test_performance_add took ") +std::to_string(elapsed.count())+std::string(" seconds\n");
		std::cout << out;
	}

	//Measures insertion time of elements into the list.	
	void test_remove(long int n){
		nav::LinkedList_Unrolled<int> list;	
		for (int i=0;i<n;i++){
			list.add(i);
		}

		// Record start time
		auto start = std::chrono::high_resolution_clock::now();
		for (int i=0;i<n;i++){
			list.remove(i);
		}
		// Record end time
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::string out=std::string("test_performance_remove took ") +std::to_string(elapsed.count())+std::string(" seconds\n");
		std::cout << out;
	}


	//Runs all tests
	void run(){
	long int n=200000; //number of elements each test creates
	//std::thread t1(test_add,n,n);
	std::thread t2(test_remove,n);
	//t1.join();
	t2.join();
	}


}