//Noorain Baig
//Project 1 
//CSCI 2270/Data Structures
//Section 310

#include <iostream>

struct vertex;

struct adjVertex {
	vertex * v; 
	adjVertex * next;
	adjVertex * prev;
	int weight;
};



struct vertex
{
    std::string key;
    int index;
    int districtID;
    //vertex * parent;
    std::string INFECT;
    // bool solved;
    vertex * next;
    bool solved;
    bool visited;
    int distance;
    std::string previous;
    adjVertex * head;

};  
		

class LinkedList {
private:
	 adjVertex * head;


public:
	LinkedList();
	//LinkedList(vertex * new_vertex, vertex * city_name, int weight);
	void ReadAdjVertices(vertex * new_vertex, vertex * city_name, int weight);

};

class Graph {

private:
	vertex * head;
	std::string key;
    int index;
    int districtID;
    std::string INFECT;
    vertex * next;
    bool solved;
    bool visited;
    int distance;
    std::string previous;
    int queueSize;
    int maxQueue;
    vertex * queue;

	
public:
	Graph();
	~Graph();
	Graph(std::string key, int index, int districtID, vertex * next, bool solved, bool visited, int distance, std::string previous);
	vertex * insertVertex(std::string key, int count);
	vertex * FindKeyVertex(std::string city_name);
	vertex * FindVertex(int value);
	void ShortestUnweightedPath(std::string vertice1key, std::string vertice2key);
	string DijkstrasAlgorithm(std::string start, std::string end, int count);
	void print();
	void ClearPrevious();
	void SetDistrictID(int count);
	void addElement(vertex * solved[], vertex * addin);
	bool isSolved(vertex * input_vertex, vertex * solved[], int size);
	void ReadMore(string infect, int count, int p);
	int Infection(int t);
	vertex * gettail();
	int isFull();
	int isEmpty();
	int enqueue(string v);
	string dequeue();
	//printVertices(); //breadth or depth first search 
	//for bool, take in two vertices, and find their weight, 
	// void insertEdge();
};



