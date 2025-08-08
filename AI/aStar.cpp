#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Heuristic values for each node
unordered_map<string, int> heuristic = {
    {"S", 10}, {"A", 8}, {"B", 5}, {"C", 5},
    {"D", 4}, {"E", 2}, {"G", 0}
};

// Graph representation using unordered_map and vector of pairs
unordered_map<string, vector<pair<string, int>>> graph = {
    {"S", {{"A", 1}, {"B", 2}, {"C", 3}}},
    {"A", {{"G", 6}}},
    {"B", {{"D", 2}, {"E", 3}}},
    {"C", {{"G", 1}, {"D", 2}}},
    {"D", {{"G", 1}}},
    {"E", {{"G", 1}}},
    {"G", {}}
};

// Helper function to reconstruct the path from start to goal
void reconstructPath(unordered_map<string, string>& parent, const string& goal) {
    vector<string> path;
    string node = goal;
    while (!node.empty()) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (const string& n : path)
        cout << n << " ";
    cout << endl;
}

// Greedy Best First Search
void greedyBestFirstSearch(const string& start, const string& goal) {
    cout << "\n--- Greedy Best First Search ---" << endl;

    // Priority queue sorted by heuristic value
    auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

    unordered_set<string> visited;
    unordered_map<string, string> parent;

    pq.push({heuristic[start], start});
    parent[start] = "";

    while (!pq.empty()) {
        auto [h, node] = pq.top();
        pq.pop();

        if (visited.count(node)) continue;
        visited.insert(node);

        if (node == goal) {
            reconstructPath(parent, goal);
            return;
        }

        for (auto& [neighbor, cost] : graph[node]) {
            if (!visited.count(neighbor)) {
                pq.push({heuristic[neighbor], neighbor});
                parent[neighbor] = node;
            }
        }
    }

    cout << "Goal not reachable." << endl;
}

// A* Search Algorithm
void aStarSearch(const string& start, const string& goal) {
    cout << "\n--- A* Search ---" << endl;

    // Priority queue sorted by f(n) = g(n) + h(n)
    auto cmp = [](pair<int, pair<int, string>>& a, pair<int, pair<int, string>>& b) {
        return a.first > b.first;
    };
    priority_queue<pair<int, pair<int, string>>, vector<pair<int, pair<int, string>>>, decltype(cmp)> pq(cmp);

    unordered_map<string, int> gCost;
    unordered_map<string, string> parent;

    gCost[start] = 0;
    pq.push({heuristic[start], {0, start}});
    parent[start] = "";

    unordered_set<string> visited;

    while (!pq.empty()) {
        auto [f, gc_node] = pq.top();
        auto [g, node] = gc_node;
        pq.pop();

        if (visited.count(node)) continue;
        visited.insert(node);

        if (node == goal) {
            reconstructPath(parent, goal);
            return;
        }

        for (auto& [neighbor, cost] : graph[node]) {
            int newG = g + cost;

            // If not visited or found a better path
            if (!gCost.count(neighbor) || newG < gCost[neighbor]) {
                gCost[neighbor] = newG;
                int fCost = newG + heuristic[neighbor];
                pq.push({fCost, {newG, neighbor}});
                parent[neighbor] = node;
            }
        }
    }

    cout << "Goal not reachable." << endl;
}

int main() {
    string start = "S", goal = "G";

    greedyBestFirstSearch(start, goal);
    aStarSearch(start, goal);

    return 0;
}
