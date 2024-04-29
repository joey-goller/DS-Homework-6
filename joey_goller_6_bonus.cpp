/* Joey Goller Homework 6 Bonus */
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void insertionSort(vector<int>& array) { // Insertion Sort
    int n = array.size();
    for (int j = 1; j < n; j++) {
        int key = array[j];
        int i = j - 1;
        while ((i > -1) && (array[i] > key)) {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
}

void selectionSort(vector<int>& array) { // Selection Sort
    for (int i = 0; i < array.size() - 1; i++) {
        int index = i;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[index]) {
                index = j;
            }
        }
        int smallerNumber = array[index];
        array[index] = array[i];
        array[i] = smallerNumber;
    }
}

void bubbleSort(vector<int>& array) { // Bubble Sort
    int n = array.size();
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < (n - i); j++) {
            if (array[j - 1] > array[j]) {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void shellSort(vector<int>& array) { // Shell Sort
    int n = array.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void menu() { // Menu for Program
    cout << "                   M E N U" << endl;
    cout << "Input Data  (0), Insertion Sort (1), Selection Sort (2)" << endl;
    cout << "Bubble Sort (3), Shell Sort (4), Exit Program (5)" << endl;
    cout << "                   Choose? ";
}

int main() {
    vector<int> storedArray;
    vector<int> tempArray;
    string userData;
    int userChoice;

    while (true) {
        menu();
        cin >> userChoice;

        switch (userChoice) {
            case 0: { // Input Data
                getline(cin >> ws, userData);
                istringstream iss(userData);
                vector<int> myNumbers;
                int number;
                while (iss >> number) {
                    myNumbers.push_back(number);
                }
                storedArray = myNumbers;
                break;
            }
            case 1: // Insertion Sort
                tempArray = storedArray;
                insertionSort(tempArray);
                for (int num : tempArray)
                    cout << num << " ";
                cout << endl;
                break;

            case 2: // Selection Sort
                tempArray = storedArray;
                selectionSort(tempArray);
                for (int num : tempArray)
                    cout << num << " ";
                cout << endl;
                break;

            case 3: // Bubble Sort
                tempArray = storedArray;
                bubbleSort(tempArray);
                for (int num : tempArray)
                    cout << num << " ";
                cout << endl;
                break;

            case 4: // Shell Sort
                tempArray = storedArray;
                shellSort(tempArray);
                for (int num : tempArray)
                    cout << num << " ";
                cout << endl;
                break;

            case 5: // Exit Program
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid option" << endl;
                break;
        }
    }

    return 0;
}
