/*This is the file specification for a map. A map is represented as a connection of nodes. All nodes live
in a two dimensional coordinate system. The X,Y values give the coordinates of a node respective to the grid.
Each node also has a unique ID. This enable the user to create an index, e.g. add labels to some nodes (e.g. node
with id=3 could be restaurant).

Each new map derives from the base class Map.*/

#pragma once

#include<vector>
#include <ostream>
namespace nav {
	class MapNode {
	public:
		int id; //ID of the node
		doublelocationX; //x value of its coordinates
		double locationY; //y value of its coordinates
		MapNode(int _id, double locX, double locY) :id(_id), locationX(locX), locationY(locY) {

		}
		friend std::ostream& operator<<(std::ostream& os, MapNode& m);


	};

	/*Overload that enables us to print the map nodes via std::cout.*/
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

		//This map is unfinished
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


