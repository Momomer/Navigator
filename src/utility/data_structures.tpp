#include <ostream>
#include<iostream>
#include "data_structures.h"
#include <algorithm>
#include <cmath>

namespace nav{
	template<class T>
	void LinkedList_Unrolled<T>::add(T key){
		if (head){
			std::shared_ptr<Node> curr=head;
			while (curr->next){
				curr=curr->next;
			}
			if (curr->elems.size()<lenNode){
				curr->elems.push_back(key);
			}
			else{
				curr->next=(std::make_shared<Node>(lenNode,nullptr));
				(*curr->next).elems.push_back(key);
				len++;
			}
		}
		else{
			head=(std::make_shared<Node>(lenNode,nullptr));	
			(*head).elems.push_back(key);
			len++;
		}
	}
	
	/*Remove an element from the list. Use operation sparingly, because in the worst case,
	a lot of elements have to be reallocated.
	If after removal, the current node fills less than half its capacity, 
	an element from the neighbor will be taken. If the neighbor will have less than half
	its capacity after such a theft, then both nodes will be merged.*/
	template<class T>
	bool LinkedList_Unrolled<T>::remove(T key){
		if (head){
			std::shared_ptr<Node> curr=head;
			std::shared_ptr<Node> prev=head;
			int iter=len;
			while (curr){
				std::vector<T>& elems=(*curr).elems;
				for (int i=0; i<lenNode; i++){
					if (key==(*curr).elems[i]){
						std::shared_ptr<Node> next=(*curr).next;
						if (next){
							int halfFloor =0.5*lenNode;
							int halfCeil=halfFloor+1;
							if (elems.size()-1<halfFloor){
								std::vector<T>& nelems=(*next).elems;
								if (nelems.size()<halfCeil){
									int prevSize=elems.size()-1;
									elems.erase(elems.begin()+i);
									elems.resize(elems.size()+nelems.size());
									std::copy(nelems.begin(),nelems.end(),elems.begin()+prevSize);
									(*curr).next=(*next).next;
									len--; //one element has been deleted, so length decreases
								}else{
									elems[i]=nelems.back();
									nelems.pop_back();
								}
								
							}else{
								elems.erase(elems.begin()+i);
							}
						}else{
							elems.erase(elems.begin()+i);
							if (elems.size()<=0){
								if (len>1){
									(*prev).next=nullptr;
								}
								else{
									head=nullptr;
								}
								len--;					
							}
						}
						return true;
					}
				}
				prev=curr;
				curr=curr->next;
			}
			return false;
		}
		else{
			return false;
		}
		
	}
		template<class T>
		bool LinkedList_Unrolled<T>::search(T key){
			auto curr=head;
		
			while(curr){
				for (auto& x:(*curr).elems){
					if(x==key){
					return true;
					}
				}
			curr=curr->next;
			}
		return false;	
		}
		
		/*Overload that enables us to print the list via std::cout.*/
		std::ostream& operator<<(std::ostream& os, LinkedList_Unrolled<int>& m) { 
			auto curr=m.head;
		
			while(curr){
				os<<"[";
				for (auto& x:(*curr).elems){
					os<<x<<",";
				}
				os<<"] -> ";
				curr=curr->next;
			}
	
    			return os;
		}
	
	template<class T>
	Heap_Min<T>::Heap_Min(const std::vector<T>& input):heap(input){
		int depth=std::log2(heap.size()); //depth of tree starting from the root
		int h=1;
		
		
	}

	template<class T>
	void Heap_Min<T>::add(T key){	
		heap.push_back(key);
		repair_up(heap.size()-1);
	}

	template<class T>
	T Heap_Min<T>::extract(){
		size_t n=heap.size()-1;
		T root=heap[0];
		heap[0]=heap[n];
		heap[n]=root;
		heap.pop_back();
		repair_down(0);
		return root;
	}

	template<class T>
	void Heap_Min<T>::repair_up(int index){
		if (index>0){
			bool repair_ongoing=true;
			int current=index;
			while (repair_ongoing){
				size_t parent=0.5*(current-1);
				if (heap[current]<heap[parent]){
					T temp=heap[current];
					heap[current]=heap[parent];
					heap[parent]=temp;
					current=parent;
				}
				else{
					repair_ongoing=false;
				}
			}		
		}

	}

	template<class T>
	void Heap_Min<T>::repair_down(int index){
		bool repair_ongoing=true;
		int current=index;
		size_t n=heap.size();
		
		while (repair_ongoing){
			size_t left_child=2*(current+1)-1;
			size_t right_child=2*(current+1);
			size_t minimum;
			size_t limit= std::log2(n);//up to this depth the tree is a complete binary tree
			if (left_child<n && right_child<n){
				if (heap[left_child]<heap[right_child]){
					minimum=left_child;
				}
				else{
					minimum=right_child;
				}
				
			}
			else if(left_child<n){
				minimum=left_child;
			}
			else if (right_child<n){
				minimum=right_child;
			}
			else{
				minimum=current;
			}
			if (heap[current]>heap[minimum]){
				T temp=heap[current];
				heap[current]=heap[minimum];
				heap[minimum]=temp;
				current=minimum;
				
			}
			else{
				repair_ongoing=false;
			}
		}
		
		
		
	}

	//Changes the key of an existing node
	template<class T>
	void Heap_Min<T>::decreasePriority(T key) {		
		for (size_t i = 0; i < heap.size(); i++) {
			if (heap[i] == key) {
				heap[i] = key;
				int current_index = i;
				int index_parent = 0.5*(current_index - 1);
				if (heap[index_parent] > heap[i]) { //repair upwards
				Heap_Min<T>::repair_up(current_index);
				}
				else { //repair downwards
				Heap_Min<T>::repair_down(current_index);
			}
		}
		}
	}


		/*Overload that enables us to print the heap via std::cout.*/
		std::ostream& operator<<(std::ostream& os, Heap_Min<int>& h) { 

			for (auto&x: h.heap){
				os<<x<<"   ";
			}
    			return os;
		}

	std::vector<double> dijkstra(Edge& edges, size_t source) {
	int numNodes = edges.getNumNodes();
	std::vector<double> dist(numNodes, INFINITY);
	std::vector<size_t> prev(numNodes, 0);

	dist[source] = 0.0;

	std::vector<DijkstraNode> elems;
	elems.resize(numNodes);
	for (size_t i = 0; i < numNodes; i++) {
		elems[i] = DijkstraNode(i,dist[i]);
	}



	Heap_Min<DijkstraNode> Q(elems);
	while (!Q.isEmpty()) {
		auto u = Q.extract();
		for (int j = 0; j < numNodes; j++) {			
			double len=edges.getWeight(u.identifier, j);
			
			if (len != 0) { //check if they are neighbors
				double alt = dist[u.identifier] + len;
				if (alt < dist[j]) {
					dist[j] = alt;
					prev[j] = u.identifier;
					Q.decreasePriority(DijkstraNode(j, dist[j]));
				}
			}
			
		}
		
	}
	return dist;
}

}


	



