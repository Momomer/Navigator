#pragma once //include guard

#include <vector>
#include <memory>
#include <ostream>

namespace nav{
	template<class T>
	class LinkedList_Unrolled{
		private:
		
		class Node{
			public:
			std::vector<T> elems;
			int len=0;
			std::shared_ptr<Node> next;
			std::shared_ptr<Node> prev;
			Node(int lenNode,std::shared_ptr<Node>  next): next(next){
			elems.reserve(lenNode);
			};		
		};
		int len; //returns the number of nodes in the list
		int lenNode=5; //number of elements in a node //returns the number of elements pernode.
		std::shared_ptr<Node> head;
		
		public:
			LinkedList_Unrolled():len(0), head(nullptr){ //use of class initializer list
		}
		void add(T key);
		bool remove(T key);
		bool search(T key);
		std::shared_ptr<Node> getHead() const{
			return head;
		}
		int getLength(){
			return len;
		}
		
 		friend std::ostream& operator<<(std::ostream& os, LinkedList_Unrolled<int>& m);

	};

	template<class T>
	class Heap_Min{
	private:
	std::vector<T> heap;
	
	public:
	Heap_Min(){
	}
	Heap_Min(const std::vector<T>& input);
	
	void add(T key);
	T extract();
	void repair_up(int index);
	void repair_down(int index);
	const std::vector<T>& getHeap() const{
		return heap;
	}
	friend std::ostream& operator<<(std::ostream& os, Heap_Min<int>& h);
	};


	
}

#include "data_structures.tpp"