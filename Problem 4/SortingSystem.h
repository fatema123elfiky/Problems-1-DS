//
// Created by Fatma on 3/12/2025.
//

#ifndef SORTING_ALGORITHIMS_SORTINGSYSTEM_H
#define SORTING_ALGORITHIMS_SORTINGSYSTEM_H

#include <iostream>
using namespace std;


template<typename  T>
class SortingSystem {

private:

    T* data;
    int size;

    void merge(int left , int mid , int right );//done // Merge Sort helper function
    int partition(int low , int high);//done// Quick Sort helper function


public:
    SortingSystem(int n);// done
    ~SortingSystem();// done

    void insertionSort();//done
    void selectionSort();//done
    void bubbleSort();//done
    void shellSort();//done
    void quickSort(int left , int right);//done
    void mergeSort(int left , int right);//done
    void countSort();//done
    void radixSort();//done
    void bucketSort();


    void displayData();//done
    void measureSortTime(void (SortingSystem<T>::*sortFunc) () );
    void measureSortTime(void (SortingSystem<T>::*sortFunc) (int left , int right) );
    void viewMenu();//done

};


#endif //SORTING_ALGORITHIMS_SORTINGSYSTEM_H
