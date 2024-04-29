#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Insertion Sort
void insertionSort(vector<int>& array) {
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

// Selection Sort
void selectionSort(vector<int>& array) {
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

// Bubble Sort
void bubbleSort(vector<int>& array) {
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

// Shell Sort
void shellSort(vector<int>& array) {
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

int main() {
    vector<int> myArray = {9, 7, 6, 15, 16, 5, 10, 11};
    vector<int> tempArray;

    cout << "HW#6 Bonus, by Jacob Riley" << endl;
    cout << "Input Data  (0), Insertion Sort (1), Selection Sort (2)" << endl;
    cout << "Bubble Sort (3), Shell Sort     (4), Exit Program   (5)" << endl;
    
    int input = -1;
    string input2;

    while (true) {
        input = -1;
        cout << "Select an option: ";
        cin >> input;

        switch (input) {
            case 0: {
                cout << "Enter the array below: ";
                getline(cin >> ws, input2);
                istringstream iss(input2);
                vector<int> myNumbers;
                int number;
                while (iss >> number) {
                    myNumbers.push_back(number);
                }
                myArray = myNumbers;
                break;
            }
            case 1:
                tempArray = myArray;
                insertionSort(tempArray);
                cout << "Sorted with Insertion Sort: ";
                for (int num : tempArray)
                    cout << num << " ";
                cout << endl;
                break;

            case 2:
                tempArray = myArray;
                selectionSort(tempArray);
                cout << "Sorted with Selection Sort: ";
                for (int num : tempArray)
                    cout << num << " ";
                cout << endl;
                break;

            case 3:
                tempArray = myArray;
                bubbleSort(tempArray);
                cout << "Sorted with Bubble Sort: ";
                for (int num : tempArray)
                    cout << num << " ";
                cout << endl;
                break;

            case 4:
                tempArray = myArray;
                shellSort(tempArray);
                cout << "Sorted with Shell Sort: ";
                for (int num : tempArray)
                    cout << num << " ";
                cout << endl;
                break;

            case 5:
                cout << "Exiting program" << endl;
                return 0;

            default:
                cout << input << " is not a valid option" << endl;
                break;
        }
    }

    return 0;
}
