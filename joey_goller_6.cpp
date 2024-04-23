#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class Node {
    public:
        char letter;
        Node* path1;
        Node* path2;
        Node* path3;

        Node(char letter) : letter(letter), path1(nullptr), path2(nullptr), path3(nullptr) {}
};

class Tree {
    Node* A;
    Node* B;
    Node* C;
    Node* D;
    Node* E;
    Node* F;
    Node* G;
    Node* H;
    Node* I;

    // A->path1 = *B; A->path2 = C; A->path3 = D;
    // B->path1 = E;
    // C->path1 = B; C->path2 = G;
    // D->path1 = C; D->path2 = G;
    // E->path1 = C; E->path2 = F;
    // F->path1 = C; F->path2 = H;
    // G->path1 = F; G->path2 = H; G->path3 = I;
    // H->path1 = E; H->path2 = I;
    // I->path1 = F;

        
};

void menu() { // Menu for Program
    cout << "                   M E N U" << endl;
    cout << "Depth-First Search (0), Minimum Path Search (1)" << endl;
    cout << "Exit Program (3)" << endl;
    cout << "                   Choose? ";
}

int main () {
    int userChoice;

    while (true) {
        menu();
        cin >> userChoice;

        switch (userChoice) {
            case 0:
                cout << "DFS" << endl;
                break;
            case 1:
                cout << "MPS" << endl;
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
        }
    }
    return 0;
}