#include "../../utility/data_structures.h"
#include <random>
#include <iostream>
#include<chrono>
#include<thread>
#include<string>

namespace test_performance_data_structures{
	//Measures insertion time of elements into the list.	
	void test_linked_list_add(long int range_upper,long int n){
		nav::LinkedList_Unrolled<int> list;
		// Record start time
		auto start = std::chrono::high_resolution_clock::now();
		
		for (int i=0;i<n;i++){
			list.add(i);
		}

		// Record end time
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::string out=std::string("test_linked_list_performance_add took ") +std::to_string(elapsed.count())+std::string(" seconds\n");
		std::cout << out;
	}

	//Measures insertion time of elements into the list.	
	void test_linked_list_remove(long int n){
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
		std::string out=std::string("test_linked_list_performance_remove took ") +std::to_string(elapsed.count())+std::string(" seconds\n");
		std::cout << out;
	}

	void test_dijkstra_adjacency_matrix(long int n) {
		std::vector<double> w(n*n);
		srand(time(NULL));   // Initialization, should only be called once.
		for (int i = 0; i < n*n; i++) {
			w[i] = (size_t)rand();
		}
		nav::Edge_Adjacency_Matrix edges(w, n);

		// Record start time
		auto start = std::chrono::high_resolution_clock::now();
		auto dist = nav::dijkstra(edges, 0);

		// Record end time
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::string out = std::string("test_dijkstra_adjacency_matrix_performance took ") + std::to_string(elapsed.count()) + std::string(" seconds\n");
		std::cout << out;
	}

	void test_dijkstra_linked_list(long int n) {
		std::vector<nav::LinkedList_Unrolled<nav::DijkstraNode>> w(n);
		srand(time(NULL));   // Initialization, should only be called once.
		for (auto& list:w) {
			size_t depth = rand() % n;
			for (int i = 0; i < depth; i++) {
				list.add(nav::DijkstraNode(i, rand()%30));
			}
		}
		nav::Edge_Linked_List edges(w);

		// Record start time
		auto start = std::chrono::high_resolution_clock::now();
		auto dist = nav::dijkstra(edges, 0);

		// Record end time
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;
		std::string out = std::string("test_dijkstra_linked_list_performance took ") + std::to_string(elapsed.count()) + std::string(" seconds\n");
		std::cout << out;
	}

	//Runs all tests
	void run(){
	long int n=15000; //number of elements each test creates
	std::thread t1(test_linked_list_add,n,n);
	std::thread t2(test_linked_list_remove,n);
	std::thread t3(test_dijkstra_linked_list, n);
	//std::thread t4(test_dijkstra_adjacency_matrix, n);
	//t1.join();
	//t2.join();
	t3.join();
	//t4.join();
	}


}