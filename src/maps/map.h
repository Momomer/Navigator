#pragma once

#include<vector>
#include <ostream>
namespace nav {
	class MapNode {
	public:
		int id; //ID of the node
		int locationX; //x value of its coordinates
		int locationY; //y value of its coordinates
		MapNode(int _id, int locX, int locY) :id(_id), locationX(locX), locationY(locY) {

		}
		friend std::ostream& operator<<(std::ostream& os, MapNode& m);


	};

	/*Overload that enables us to print the list via std::cout.*/
	std::ostream& operator<<(std::ostream& os, MapNode& m) {

			os << "[id: "<<m.id<<" ,locationX: "<<m.locationX<<"  ,locationY: "<<m.locationY<<"]";
	
		return os;
	}
	class Map {
	private:
		const std::vector<MapNode> map;
	public:
		const std::vector<MapNode> getMap() const {
			return map;
		}
	};


		class Frankfurt:public Map {
		private:
			std::vector<bool> neighbors = {false,true,true,
											true,false,false,
											true,true,false} ;
			std::vector<nav::MapNode> map = { MapNode(0,0,0), MapNode(1,-20,0),MapNode(2,60,0) };
		public:



		public:
			void printmap() {
				for (auto& x : map) {
					std::cout << x << " ";
				}
			}

	};
}


