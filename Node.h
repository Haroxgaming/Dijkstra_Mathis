#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
    string name;
    vector<pair<Node*, int>> neighbors;


public:
    Node(string n);
    Node(string na, const vector<pair<Node*, int>>& n);
    string getName() const;
    void setName(const string& n);
    vector<pair<Node*, int>> getNeighbors();
    void addNeighbor(Node* n, int w);
    void addNeighbor(vector<pair<Node*, int>> n);
    void showNeighbors();
    bool isVisited() const;
    void setVisited(bool v);
    int getDistance() const;
    void setDistance(int d);
    bool visited;
    int dist;
};