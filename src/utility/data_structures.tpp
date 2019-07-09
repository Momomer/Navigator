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
				curr->len++;
			}
			else{
				curr->next=(std::make_shared<Node>(lenNode,nullptr));
				(*curr->next).elems.push_back(key);
				(*curr->next).len++;
				len++;
			}
		}
		else{
			head=(std::make_shared<Node>(lenNode,nullptr));	
			(*head).elems.push_back(key);
			(*head).len++;
			len++;
		}
	}
	
	/*Remove an element from the list. Use operation sparingly. In order to keep the list balanced,*/
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
							if (elems.size()-1<0.5*lenNode){
								std::vector<T>& nelems=(*next).elems;
								if (nelems.size()<0.5*lenNode){
									std::copy(nelems.begin(),nelems.end(),elems.begin()+i);
									(*curr).next=(*next).next;
									len--; //one element has been deleted, so length decreases
								}else{
									int esize=elems.size();
									elems.resize(5);
									std::cout<<*this<<"\n";
									std::copy(nelems.end()-(esize+1),nelems.end(),elems.begin()+i);
								//elems.insert(elems.begin()+i,nelems.end()-(lenNode-i),nelems.end()-;
									nelems.erase(nelems.end()-(esize+1),nelems.end());
									std::cout<<*this<<"\n";
									(*next).len=(*next).len-esize;
									std::cout<<-esize<<"Laenge\n";
									std::cout<<(*next).len<<"nextlen \n";
									std::cin.get();
								}
								
							}else{
								elems.erase(elems.begin()+i);
								(*curr).len--;
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
							(*curr).len--;
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


	



