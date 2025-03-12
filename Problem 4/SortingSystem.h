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

    void merge(int left , int mid , int right );// Merge Sort helper function
    int partition(int low , int high);// Quick Sort helper function


public:
    SortingSystem(int n);// done
    ~SortingSystem();// done

    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort(int left , int right);
    void quickSort(int left , int right);
    void countSort();
    void radixSort();
    void bucketSort();


    void displayData();//done
    void measureSortTime(void (SortingSystem<T>::*sortFunc) () );
    void measureSortTime(void (SortingSystem<T>::*sortFunc) (int left , int right) );
    void viewMenu();//done

};


#endif //SORTING_ALGORITHIMS_SORTINGSYSTEM_H
