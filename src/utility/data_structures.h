/*These are various helper function. Also includes Dijkstra's algorithm, that is used
for pathfinding.*/

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
	//Changes the key of an existing node
	void decreasePriority(T key);
	bool isEmpty() {
		return heap.size() == 0;
	}
	void add(T key);
	T extract();
	void repair_up(int index);
	void repair_down(int index);
	const std::vector<T>& getHeap() const{
		return heap;
	}
	friend std::ostream& operator<<(std::ostream& os, Heap_Min<int>& h);
	};
	
	/*These nodes are only used within Dijkstra's algorithm.
	Otherwise*/
	class DijkstraNode {
	public:
		double distance;
		int identifier;
		DijkstraNode() : distance(0), identifier(0) {

		};
		DijkstraNode(int id, double _distance) :identifier(id), distance(_distance) {

		}
		friend bool operator< (const DijkstraNode &c1, const DijkstraNode &c2);
		friend bool operator> (const DijkstraNode &c1, const DijkstraNode &c2);
		friend bool operator== (const DijkstraNode &c1, const DijkstraNode &c2);
		DijkstraNode& operator= (const DijkstraNode &node) {
			(*this).distance = node.distance;
			(*this).identifier = node.identifier;
			return (*this);
		}
	};


	bool operator< (const DijkstraNode &c1, const DijkstraNode &c2) {
		return c1.distance < c2.distance;
	};

	bool operator> (const DijkstraNode &c1, const DijkstraNode &c2) {
		return c1.distance > c2.distance;
	};

	//Two nodes are equal, if they share the same identifier
	bool operator== (const DijkstraNode &c1, const DijkstraNode &c2) {
		if (c1.identifier == c2.identifier) {
			return true;
		}
		else {
			return false;
		}
	}


	/*Abstract Base Class for edges*/
	class Edge {
	public:
		virtual double getWeight(size_t source, size_t end) = 0;
		virtual int getNumNodes() = 0;
	};

	class Edge_Adjacency_Matrix :public Edge {
	private:
		std::vector<double> weights;
		int dimN = 0;
	public:
		Edge_Adjacency_Matrix(std::vector<double> _weights, size_t N) :weights(_weights), dimN(N) {

		}
		virtual double getWeight(size_t source, size_t end) override {
			return weights[end + dimN * source];
		}
		virtual int getNumNodes() override {
			return dimN;
		}

	};



	class Edge_Linked_List :public Edge {
	private:
		std::vector<LinkedList_Unrolled<DijkstraNode>> weights;
	public:

		Edge_Linked_List(std::vector<LinkedList_Unrolled<DijkstraNode>>& _weights) :weights(_weights) {

		}

		virtual double getWeight(size_t source, size_t end) override {

			//Search the node
			auto curr = weights[source].getHead();
			while (curr) {
				for (auto& x : (*curr).elems) {
					if (x.identifier == end) {
						return x.distance;
					}
				}
				curr = curr->next;
			}
		
			return 0.0;
		}
		virtual int getNumNodes() {
			return weights.size();
		}
	};


	//Dijkstra's shortest path algorithm
	std::vector<double> dijkstra(Edge& edges, size_t source);
	
}

#include "data_structures.tpp"