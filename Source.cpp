#include "Node.h"
#include <queue>
#include <limits>
#include <unordered_map>

struct NodeInfo {
    int distance;
    Node* predecessor;
};

vector<pair<int, int>> dijkstraStepByStep(vector<Node*>& graph, Node* source, Node* end) {

    unordered_map<Node*, NodeInfo> nodeInfoMap; 
    for (auto& node : graph) {
        nodeInfoMap[node] = { numeric_limits<int>::max(), nullptr };
    }
    nodeInfoMap[source] = { 0, nullptr }; 

    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    pq.push({ 0, source });

    vector<pair<int, int>> steps;

    while (!pq.empty()) {
        Node* current = pq.top().second;
        pq.pop();

        if (current == end) break;

        if (nodeInfoMap[current].distance == numeric_limits<int>::max()) continue; 

        // Store step-by-step result
        steps.push_back({ nodeInfoMap[current].distance, current->getName()[0] - 'A' });

        for (auto& neighbor : current->getNeighbors()) {
            Node* next = neighbor.first;
            int weight = neighbor.second;
            int newDistance = nodeInfoMap[current].distance + weight; 

            if (newDistance < nodeInfoMap[next].distance) {
                nodeInfoMap[next] = { newDistance, current }; 
                pq.push({ newDistance, next });
            }
        }
    }

    vector<pair<int, int>> path;
    Node* currentNode = end;
    while (currentNode != nullptr) {
        path.push_back({ nodeInfoMap[currentNode].distance, currentNode->getName()[0] - 'A' });
        currentNode = nodeInfoMap[currentNode].predecessor;
    }
    reverse(path.begin(), path.end()); 

    return path;
}

int main() {
    vector<Node*> graph;
    Node A("A");
    Node B("B");
    Node C("C");
    Node D("D");
    Node E("E");
    Node F("F");
    Node G("G");
    Node H("H");
    Node I("I");
    Node J("J");

    A.addNeighbor(&B, 85);
    A.addNeighbor(&C, 217);
    A.addNeighbor(&E, 173);

    B.addNeighbor(&F, 80);

    C.addNeighbor(&G, 186);
    C.addNeighbor(&H, 103);

    D.addNeighbor(&H, 183);

    E.addNeighbor(&J, 502);

    F.addNeighbor(&I, 250);

    H.addNeighbor(&J, 167);

    I.addNeighbor(&J, 84);

    graph.emplace_back(&A);
    graph.emplace_back(&B);
    graph.emplace_back(&C);
    graph.emplace_back(&D);
    graph.emplace_back(&E);
    graph.emplace_back(&F);
    graph.emplace_back(&G);
    graph.emplace_back(&H);
    graph.emplace_back(&I);
    graph.emplace_back(&J);

    
    cout << "Nodes existante:" << endl;
    for (Node* node : graph) {
        cout << node->getName() << endl;
    }
    cout << endl;

    cout << "Selectionner la node de debut: ";
    string startName;
    cin >> startName;
    for (char& c : startName) {
        c = toupper(c);
    }

    Node* start = nullptr;
    for (Node* node : graph) {
        if (node->getName() == startName) {
            start = node;
            break;
        }
    }

    if (!start) {
        cout << "La node de debut n'existe pas" << endl;
        return 1;
    }

    cout << "Selectionner la node de fin: ";
    string endName;
    cin >> endName;
    for (char& c : endName) {
        c = toupper(c);
    }

    Node* end = nullptr;
    for (Node* node : graph) {
        if (node->getName() == endName) {
            end = node;
            break;
        }
    }

    if (!end) {
        cout << "La node de fin n'existe pas" << endl;
        return 1;
    }
vector<pair<int, int>> path = dijkstraStepByStep(graph, start, end);

cout << "Etapes de l'algorithme de Dijkstra :" << endl;
for (const auto& step : path) {
    cout << "Distance jusqu'a la node " << static_cast<char>('A' + step.second) << ": " << step.first << endl;
}

return 0;
}