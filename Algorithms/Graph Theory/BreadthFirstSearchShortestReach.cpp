#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef struct node {
    int id;
    int visit;
    vector<struct node*> edges;
} Node;

class Graph {
    private:
    map<int, Node*> nodes;

    void cleanVisits() {
        for (pair<int, Node*> item : nodes)
            item.second->visit = 0;
    }

    public:

    Graph() {}

    void addNode(int id) {
        nodes[id] = new Node;
        nodes[id]->id = id;
        nodes[id]->visit = 0;
    }

    void addEdge(int from, int to) {
        nodes[from]->edges.push_back(nodes[to]);
        nodes[to]->edges.push_back(nodes[from]);
    }

    Node * getNodeById(int id){
        return nodes[id];
    }

    int getShortestPath(int from, int to) {
        cleanVisits();
        bool found = false;
        Node* foundNode = 0;
        queue<Node*> q;
        q.push(nodes[from]);
        nodes[from]->visit = from;
        int count = 0;

        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            for (Node* item : temp->edges) {
                if (item->id == to) {
                    found = true;
                    foundNode = item;
                    item->visit = temp->id;
                    break;
                }

                if (item->visit == 0) {
                    q.push(item);
                    item->visit = temp->id;
                }
            }

            if (found) break;
        }

        if (!found) return -1;

        Node * runner = foundNode;

        while (runner->id != from) {
            ++count;
            runner = nodes[runner->visit];
        }

        return count * 6;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        int s;
        cin >> n >> m;
        Graph * g = new Graph();

        for (int i = 1; i <= n; i++) {
            g->addNode(i);
        }

        for (int i = 0; i < m; i++) {
            int f,t;
            cin >> f >> t;
            g->addEdge(f,t);
        }

        cin >> s;

        for (int i = 1; i <= n; i++) {
            if (s == i) continue;
            cout << g->getShortestPath(s, i);
            if (i != n) cout << " ";
        }

        cout << endl;
    }


    return 0;
}
