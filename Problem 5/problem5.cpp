//Author: Nagham Wael Mohamed
//ID: 20231189
//Problem info: Problem #5 Statistical Calculation
//Bonus: taking input from a file
//Attached files: test cases in files stat1.txt & stat2.txt


#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

template <typename T>
class StatisticalCalculation {
private:
    T* data;
    int size;

public:
    //constructor
    StatisticalCalculation(int size) : size(size) {
        data = new T[size];
    }

    //destructor
    ~StatisticalCalculation() {
        delete[] data;
    }

    //take elements from user and validate that entered elements are only numeric e.g, -2 , 4.0 , 5 , 2.5
    void inputData() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i + 1 << ": ";
            //the loop works when user enters an invalid element (non-numeric)
            while (!(cin >> data[i])) {
                cout << "Invalid input. Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    //function to sort the data
    void sort() {
        // Insertion Sort algorithm
        for (int i = 1; i < size; i++) {
            T key = data[i];
            int j = i - 1;
            while (j >= 0 && data[j] > key) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = key;
        }
    }

    //find the median of the data
    double findMedian() { //in classroom the TA said to change the return type from T to double
        sort();
        if (size % 2 == 0)
            return (data[size / 2 - 1] + data[size / 2] ) / 2.0;
        else
            return data[size / 2];
    }

    //find the smallest element
    T findMin() {
        sort();
        return data[0];
    }

    //find the biggest element
    T findMax() {
        sort();
        return data[size-1];
    }

    //find the mean of the data
    double findMean() {
        T sum = findSummation();
        return static_cast<double>(sum) / size;
    }

    //find the summation of all elements
    T findSummation() {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += data[i];
        }
        return sum;
    }

    //display sorted array
    void displayArray() {
        cout << endl;
        sort();
        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }

    }

    //the main menu of statistical operations
    void statisticsMenu() {
        string choice;
        do {
            displayArray();
            cout << "\nSelect a statistical calculation:\n";
            cout << "1. Find Median\n";
            cout << "2. Find Minimum\n";
            cout << "3. Find Maximum\n";
            cout << "4. Find Mean\n";
            cout << "5. Find Summation\n";
            cout << "6. Exit\n";
            cout << "Enter your choice (1-6): ";
            cin >> choice;

            if(choice == "1") cout << "Median: " << findMedian() << endl;
            else if(choice == "2") cout << "Minimum: " << findMin() << endl;
            else if(choice == "3") cout << "Maximum: " << findMax() << endl;
            else if(choice == "4") cout << "Mean: " << findMean() << endl;
            else if(choice == "5") cout << "Summation: " << findSummation() << endl;
            else if(choice =="6")  cout << "Exiting program...\n";
            else cout << "Invalid choice! Please enter a valid option.\n";



        } while (choice != "6");
    }

    //take input from a .txt file
    bool inputDataFromFile(const string& filename) {
        ifstream file(filename);

        //file not opened correctly
        if (!file) {
            cout << "Error opening file. Please make sure the file exists.\n";
            return false;
        }

        int fileSize;
        file >> fileSize;

        //the number of elements is a non-numeric value or a negative value or non-integer
        if (file.fail() || fileSize <= 0) {
            cout << "Invalid file format! First line must be a positive integer.\n";
            return false;
        }

        //the number of the elements in the first line isn't correct
        if (fileSize != size) {
            cout << "Mismatch in number of elements. Expected: " << size << ", Found: " << fileSize << endl;
            return false;
        }

        //the file contains a non-numerical value in the elements
        for (int i = 0; i < size; i++) {
            if (!(file >> data[i])) {
                cout << "Invalid data in file. Please ensure all elements are numbers.\n";
                return false;
            }
        }

        file.close();
        return true;
    }
};



int main() {
    string inputChoice;
    //input options menu
    do {
        cout << "Choose input method:\n";
        cout << "1. Enter data manually\n";
        cout << "2. Read data from a file\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> inputChoice;

        if (inputChoice != "1" && inputChoice != "2") {
            cout << "Invalid choice! Please enter 1 or 2.\n";
        }
    } while (inputChoice != "1" && inputChoice != "2");

    int numElements;
    string filename;

    if (inputChoice == "1") {
        cout << "Enter the number of elements: ";
        while (true) {
            cin >> numElements;
            if (cin.fail() || numElements <= 0) {
                cout << "Invalid input. Please enter a positive integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    } else {
        cout << "Note: make sure the file is in the cmake-build-debug folder first\n";
        cout << "Enter the file name (e.g., stat1.txt): ";
        cin >> filename;

        // attempt to open file
        ifstream file(filename);
        while (!file) {
            cout << "File not found! Please enter a valid file name: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> filename;
            file.open(filename);
        }

        // read number of elements from the first line of the file
        file >> numElements;
        // the number of elements isn't valid
        if (file.fail() || numElements <= 0) {
            cout << "Invalid file format! The first line must be a positive integer.\n";
            return 1;
        }

        file.close();
    }

    // create object
    StatisticalCalculation<double> stats(numElements);

    if (inputChoice == "1") {
        stats.inputData();
    } else {
        if (!stats.inputDataFromFile(filename)) {
            return 1;
        }
    }

    stats.statisticsMenu();
    return 0;
}
