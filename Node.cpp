#include "Node.h"

Node::Node(string n) : name(n), visited(false), dist(0) {}

Node::Node(string na, const vector<pair<Node*, int>>& n) : name(na), neighbors(n), visited(false), dist(0) {}

string Node::getName() const {
    return name;
}

void Node::setName(const string& n) {
    name = n;
}

vector<pair<Node*, int>> Node::getNeighbors() {
    return neighbors;
}

void Node::addNeighbor(Node* n, int w) {
    neighbors.emplace_back(n, w);
    n->neighbors.emplace_back(this, w);
}

void Node::addNeighbor(vector<pair<Node*, int>> n) {
    for (pair<Node*, int>& p : n) {
        neighbors.emplace_back(p);
        p.first->neighbors.emplace_back(this, p.second);
    }
}

void Node::showNeighbors() {
    cout << getName() << " neighbors : {";
    for (pair<Node*, int>& p : neighbors) {
        cout << "(" << p.first->getName() << ";" << p.second << ")";
    }
    cout << "}" << endl;
}

bool Node::isVisited() const {
    return visited;
}

void Node::setVisited(bool v) {
    visited = v;
}

int Node::getDistance() const {
    return dist;
}

void Node::setDistance(int d) {
    dist = d;
}