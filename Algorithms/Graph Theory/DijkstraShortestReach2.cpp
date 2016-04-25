#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <climits>
#include <list>
#include <functional>

using namespace std;

typedef long long llint;
typedef unsigned long long ullint;

class GraphNode {

private:
	ullint  _id;
	llint _value;
	bool _visit;
	bool _hasParentId;
	ullint _parentId;

public:
	GraphNode(ullint id, llint value) {
		setId(id);
		setValue(value);
		setVisit(false);
		setHasParentId(false);
		setParentId(0);
	}

	~GraphNode() {
	}


	//----- Getters and Setters

	//----- Id
	ullint getId() const { return _id; }
	void setId(ullint id) { _id = id; }

	//----- Value
	llint getValue() const { return _value; }
	void setValue(llint value) { _value = value; }

	//----- Visit
	bool getVisit() { return _visit; }
	void setVisit(bool visit) { _visit = visit; }

	//----- Has Parent Id
	bool getHasParentId() { return _hasParentId; }
	void setHasParentId(bool hasParentId) { _hasParentId = hasParentId; }

	//----- Parent Id
	ullint getParentId() { return _parentId; }
	void setParentId(ullint parentId) { _parentId = parentId; }
};

class GraphEdge {
private:
	const GraphNode* _source;
	const GraphNode* _destination;
	double _weight;

public:
	GraphEdge(const GraphNode* source, const GraphNode* destination,
		double weight) {
		_source = source;
		_destination = destination;
		_weight = weight;
	}

	~GraphEdge() {
	}


	//----- Getters and Setters
	//----- Source
	const GraphNode* getSource() const { return _source; }

	//----- Destination
	const GraphNode* getDestination() const { return _destination; }

	//----- Weight
	double getWeight() { return _weight; }
	void setWeight(double weight) { _weight = weight; }
};

class Graph {

protected:
	//----- Attributes
	map<int, GraphNode*> _nodes;
	map<ullint, list<GraphEdge*>> _edgesBySource;
	map<ullint, list<GraphEdge*>> _edgesByDestination;

	bool _isDirected;
	ullint _id;

public:
	Graph(bool isDirected = false) {
		setIsDirected(isDirected);
		_id = 0;
	}

	~Graph() {
		clear();
	}


	//----- Getters and Setters
	//----- Is Directed
	bool getIsDirected() { return _isDirected; }
	void setIsDirected(bool isDirected) { _isDirected = isDirected; }


	//----- Methods
	void clear() {
		/*// Clear Edges
		for (auto pairEdgeSource : _edgesBySource)
			for (auto edgePtr : pairEdgeSource.second)
				delete edgePtr;

		for (auto pairEdgeDestination : _edgesByDestination)
			for (auto edgePtr : pairEdgeDestination.second)
				delete edgePtr;

		_edgesBySource.clear();
		_edgesByDestination.clear();

		// Clear Nodes
		for (auto pairNode : _nodes)
			delete pairNode.second;

		_nodes.clear();*/
	}

	bool isEmpty() {
		return _nodes.empty();
	}

	ullint getNumberOfNodes() {
		return _nodes.size();
	}

	ullint getNumberOfEdges() {
		return _edgesBySource.size();
	}

	void addNode(llint value) {
		_id++;
		GraphNode* node = new GraphNode(_id, value);
		_nodes[_id] = node;
	}

	void removeNodeById(ullint nodeId) {
		for (auto currentEdge : _edgesBySource[nodeId])
			delete currentEdge;

		for (auto currentEdge : _edgesByDestination[nodeId])
			delete currentEdge;

		_edgesBySource.clear();
		_edgesByDestination.clear();
		_edgesBySource.erase(nodeId);
		_edgesByDestination.erase(nodeId);

		// Remove nodes with the given id
		delete _nodes[nodeId];
		_nodes.erase(nodeId);
	}

	bool removeNodeByValue(llint nodeValue) {
		auto node = searchNodeByValue(nodeValue);
		if (node != NULL) {
			removeNodeById(node->getId());
			return true;
		}

		return false;
	}

	bool removeNodesByValue(llint nodeValue) {
		auto isSuccess = false;

		// Not the best solution, but I will rarely use this
		while (removeNodeByValue(nodeValue))
			isSuccess = true;

		return isSuccess;
	}

	llint getNodesLeastValue() {
		llint leastValue = LLONG_MAX;

		for (auto currentNode : _nodes)
			if (currentNode.second->getValue() < leastValue)
				leastValue = currentNode.second->getValue();

		return leastValue;
	}

	void removeNodeLeastValue() {
		if (isEmpty()) return;
		removeNodeByValue(getNodesLeastValue());
	}

	llint getNodesMaxValue() {
		llint maxValue = LLONG_MIN;

		for (auto currentNode : _nodes)
			if (currentNode.second->getValue() > maxValue)
				maxValue = currentNode.second->getValue();

		return maxValue;
	}

	void removeNodeMaxValue() {
		if (isEmpty()) return;
		removeNodeByValue(getNodesMaxValue());
	}

	GraphNode* searchNodeByValue(llint nodeValue) {
		GraphNode* nodeOutput = NULL;

		for (auto pairNode : _nodes) {
			if (pairNode.second->getValue() == nodeValue) {
				nodeOutput = pairNode.second;
				break;
			}
		}

		return nodeOutput;
	}

	GraphNode* searchNodeById(ullint nodeId) {
		GraphNode* nodeOutput = NULL;

		for (auto pairNode : _nodes) {
			if (pairNode.second->getId() == nodeId) {
				nodeOutput = pairNode.second;
			}
		}

		return nodeOutput;
	}

	bool hasNodeWithValue(llint nodeValue) {
		return searchNodeByValue(nodeValue) != NULL;
	}

	bool hasNodeWithId(ullint nodeId) {
		return searchNodeById(nodeId) != NULL;
	}

	void addEdge(ullint sourceId, ullint destinationId, double weight) {
		auto sourceNode = _nodes[sourceId];
		auto destinationNode = _nodes[destinationId];

		auto newEdge = new GraphEdge(sourceNode, destinationNode, weight);
		_edgesBySource[sourceId].push_back(newEdge);
		_edgesByDestination[destinationId].push_back(newEdge);
	}

	GraphEdge* searchEdgeByWeight(double weight) {
		for (auto currentEdgePair : _edgesBySource)
			for (auto currentEdge : currentEdgePair.second)
				if (currentEdge->getWeight() == weight)
					return currentEdge;

		return NULL;
	}

	GraphEdge* searchEdgeByNodePath(ullint sourceId, ullint destinationId) {
		for (auto currentEdge : _edgesBySource[sourceId])
			if (currentEdge->getDestination()->getId() == destinationId)
				return currentEdge;

		return NULL;
	}

	list<GraphEdge*>& getEdgesWhereNodeIsSource(ullint nodeId) {
		return _edgesBySource[nodeId];
	}

	list<GraphEdge*>& getEdgesWhereNodeIsDestination(ullint nodeId) {
		return _edgesByDestination[nodeId];
	}

	typedef pair<int, int> pp;
	map<ullint, llint> dijkstra(int source) {
		priority_queue<pp, vector<pp>, greater<pp>> costs;
		map<ullint, llint> distances;

		for (auto currNode : _nodes) {
			distances[currNode.second->getId()] = INT_MAX;
		}

		distances[source] = 0;
		costs.push(make_pair(0, source));

		while (!costs.empty()) {
			int dis = costs.top().first;
			int nodeId = costs.top().second;
			costs.pop();

			if (dis > distances[nodeId]) continue;

			auto nodeEdges = getEdgesWhereNodeIsSource(nodeId);
			for (auto currentEdge : nodeEdges) {
				auto newWeight = dis + currentEdge->getWeight();
				auto destinationId = currentEdge->getDestination()->getId();
				auto oldWeight = distances[destinationId];

				if (newWeight < oldWeight) {
					distances[destinationId] = newWeight;
					costs.push(make_pair(newWeight, destinationId));
				}
			}
		}

		return distances;
	}
};

pair<int,int> createPair(int i, int j) {
    if (i < j) return make_pair(i, j);
    return make_pair(j, i);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		Graph g;
		int n, m;
		cin >> n >> m;
        map<pair<int,int>, int> edges;

		for (int i = 1; i <= n; i++) g.addNode(i);

        for (int i = 0; i < m; i++) {
			int x, y, r;
			cin >> x >> y >> r;

			auto auxPair = createPair(x,y);
            if (edges.find(auxPair) == edges.end() || edges[auxPair] > r) {
                edges[auxPair] = r;
            }
		}

        for (auto temp : edges) {
            g.addEdge(temp.first.first, temp.first.second, temp.second);
            g.addEdge(temp.first.second, temp.first.first, temp.second);
        }

		int s;
		cin >> s;

		auto distances = g.dijkstra(s);

		for (int i = 1; i <= distances.size(); i++) {
			if (i == s) continue;
			if (distances[i] == INT_MAX)
				cout << -1;
			else
				cout << distances[i];
			if (i < distances.size()) cout << " ";
		}
		cout << endl;
	}

	return 0;
}
