#include <ostream>
#include<iostream>
#include "data_structures.h"

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
	
}


	



