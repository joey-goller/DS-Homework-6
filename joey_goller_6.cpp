/* Joey Goller Data Structures Homework 6 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <deque>

using namespace std;

class givenGraph {
private:
    unordered_map<string, vector<string>> graph;

public:
    givenGraph() { // Instantiating Graph
        graph["A"] = {"B", "C", "D"};
        graph["B"] = {"E"};
        graph["C"] = {"B", "G"};
        graph["D"] = {"C", "G"};
        graph["E"] = {"C", "F"};
        graph["F"] = {"C", "H"};
        graph["G"] = {"F", "H", "I"};
        graph["H"] = {"E", "I"};
        graph["I"] = {"F"};
    }

    void depthFirstSearch(string start) { // Depth-First Search Algorithm
        unordered_set<string> visited;
        stack<string> stack;
        stack.push(start);

        while (!stack.empty()) {
            string node = stack.top();
            stack.pop();
            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                cout << node << " ";

                for (const string &neighbor : graph[node]) {
                    stack.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void breadthFirstSearch(string start, string end) { // Breadth-First Search Algorithm
        unordered_set<string> visited;
        queue<string> queue;
        unordered_map<string, string> previous;
        queue.push(start);
        visited.insert(start);

        while (!queue.empty()) {
            string node = queue.front();
            queue.pop();
            if (node == end) {
                printPath(end, previous);
                return;
            }

            for (const string &neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    previous[neighbor] = node;
                    queue.push(neighbor);
                }
            }
        }
        cout << "No path found from " << start << " to " << end << endl;
    }

private:
    void printPath(string current, unordered_map<string, string> &previous) {
        deque<string> path;
        while (!current.empty()) {
            path.push_front(current);
            current = previous[current];
        }

        while (!path.empty()) {
            cout << path.front() << " ";
            path.pop_front();
        }
        cout << endl;
    }
};

void menu() { // Menu for Program
    cout << "                   M E N U" << endl;
    cout << "Depth-First Search (0), Minimum Path Search (1)" << endl;
    cout << "Exit Program (3)" << endl;
    cout << "                   Choose? ";
}

int main() {
    givenGraph graphSearch;

    while (true) {
        menu();
        int userChoice;
        string dfsStart;
        string bfsStart;
        string bfsEnd;

        cin >> userChoice;

        switch (userChoice) {
            case 0:
                cin >> dfsStart;
                graphSearch.depthFirstSearch(dfsStart);
                break;

            case 1:
                cin >> bfsStart >> bfsEnd;
                graphSearch.breadthFirstSearch(bfsStart, bfsEnd);
                break;

            case 3:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid input" << endl;
                break;
        }
    }

    return 0;
}
