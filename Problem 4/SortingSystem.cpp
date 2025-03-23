//
// Created by Fatma on 3/12/2025.
//

#include "SortingSystem.h"
#include <algorithm>


string check_menu(const string& menuText ,const string choices[],int size ){
    string currentAnswer;

    while(true){
        cout << menuText ;
        getline(cin, currentAnswer);
        if(currentAnswer.size() != 1 || find(choices,choices+size, currentAnswer) == choices+size)
            cout << "Try again !!\n\n" ;
        else
            break;
    }
    cin.ignore(0, '\n');

    return currentAnswer;
}

template<typename T>
void SortingSystem<T> :: viewMenu(){


        again:
        string text ="Select a sorting algorithm: \n1. Insertion Sort \n"
                     "2. Selection Sort \n"
                     "3. Bubble Sort \n"
                     "4. Shell Sort \n"
                     "5. Merge Sort \n"
                     "6. Quick Sort \n"
                     "7. Count Sort (Only for integers) \n"
                     "8. Radix Sort (Only for integers) \n"
                     "9. Bucket Sort \n"
                     "Enter your choice : ";
        string choices[9]={"1","2","3","4","5","6","7","8","9"};
        string choice =check_menu(text,choices,9);





        void (SortingSystem<T>::*sortFunc)()= nullptr;
        void (SortingSystem<T>::*sortFunc_2)(int,int)= nullptr;


        if(choice=="1") {

            cout<<"Sorting using insertion ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            insertionSort(), sortFunc = &SortingSystem<T>::insertionSort;

        }
        else if(choice=="2") {

            cout<<"Sorting using selection ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            selectionSort(), sortFunc = &SortingSystem<T>::selectionSort;

        }
        else if(choice=="3") {

            cout<<"Sorting using bubbleSort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            bubbleSort(), sortFunc = &SortingSystem<T>::bubbleSort;

        }
        else if(choice=="4") {

            cout<<"Sorting using shellSort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            shellSort(), sortFunc = &SortingSystem<T>::shellSort;

        }
        else if(choice=="5") {

            cout<<"Sorting using merge sort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            mergeSort(0, size - 1), sortFunc_2 = &SortingSystem<T>::mergeSort;

        }
        else if(choice=="6") {
            cout<<"Sorting using quicksort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            quickSort(0, size - 1), sortFunc_2 = &SortingSystem<T>::quickSort;
        }
        else if(choice=="7"){

            if constexpr (is_integral_v<T>)
                countSort(),sortFunc=&SortingSystem<T>::countSort;

            else {
                cout << "Sorry ,Try again!!\n\n";
                goto again;
            }

        }else if(choice=="8"){

            if constexpr (is_integral_v<T>)
                radixSort(),sortFunc=&SortingSystem<T>::radixSort;

            else {
                cout << "Sorry ,Try again!!\n\n";
                goto again;
            }

        }else
            bucketSort(),sortFunc=&SortingSystem<T>::bucketSort;


        cout<<"\n\n"<<"Sorted data : ";
        displayData();

        if(sortFunc)
            measureSortTime(sortFunc);
        else
            measureSortTime(sortFunc_2);




}

template <typename T>
void SortingSystem<T>::displayData() {

    cout<<"[";
    for (int index = 0; index < size-1; ++index)
        cout<<data[index]<<", ";
    cout<<data[size-1]<<"]\n";

}

template <typename T>
SortingSystem<T>::SortingSystem(int n):size(n) {

    if(n<=0)
        size=1;

    data=new T[size];

    int counter=0;
    while (counter<size) {
        cout << "Enter data " << counter+1 << ": ";
        cin>>data[counter++];
    }

    viewMenu();
}

template <typename T>
SortingSystem<T>::~SortingSystem() {
    delete [] data ;
}

template<typename T>
void SortingSystem<T>::insertionSort() {

    for (int index = 1,sub_index; index < size ; ++index) {

        T key=data[index];

        for ( sub_index = index-1; sub_index >=0 ; --sub_index) {
            if(data[sub_index]>key)
                data[sub_index+1]=data[sub_index];
            else
                break;
        }

        data[sub_index+1]=key;

        cout<<"Iteration "<<index<<" : ";
        displayData();

    }

}

template<typename T>
void SortingSystem<T>::selectionSort() {


    for (int index = 0,least; index < size; ++index) {

        least=index;
        for (int pointer = index+1; pointer < size ; ++pointer) {
            if(data[least]<data[pointer])
                   least=pointer;
        }
        swap(data[least],data[index]);

        cout<<"Iteration "<<index+1<<" : ";
        displayData();

    }


}

template<typename T>
void SortingSystem<T>::bubbleSort() {

    for (int index = 0; index < size-1; ++index) {

        for (int sub_index = 0; sub_index < size-index-1; ++sub_index) {
            if(data[sub_index]>data[sub_index+1])
                swap(data[sub_index],data[sub_index+1]);
        }

        cout<<"Iteration "<<index+1<<" : ";
        displayData();
    }


}

template<typename T>
void SortingSystem<T>::shellSort() {

    for (int gap = size/2; gap > 0; gap/=2) {

        cout<<"After gap of size "<<gap<<" : ";
        for (int index = gap; index < size ; ++index) {

            int gaped_index=index;
            while (gaped_index>=gap&&data[gaped_index]<data[gaped_index - gap ])
                swap(data[gaped_index],data[gaped_index - gap ]),gaped_index-=gap;

        }
        displayData();

    }


}

template<typename T>
void SortingSystem<T>::mergeSort(int left, int right) {

    if(left>=right)
        return;

    int mid=(left+right)/2;

    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,mid,right);

}

template<typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {

    int size_1 = mid-left+1 , size_2 = right-mid;

    T*part_1=new T(size_1);
    T*part_2=new T(size_2);

    for (int index = left; index <= mid; ++index)
        part_1[index]=data[index];
    for (int index = mid+1; index <= right; ++index)
        part_2[index]=data[index];


    int pointer_1=0,pointer_2=0,pointer=left;
    while (pointer_1<size_1 && pointer_2<size_2){
        if(part_1[pointer_1]<=part_2[pointer_2])
            data[pointer++]=part_1[pointer_1++];
        else
            data[pointer++]=part_2[pointer_2++];
    }

    while (pointer_1<size_1)
        data[pointer++]=part_1[pointer_1++];
    while (pointer_2<size_2)
        data[pointer++]=part_2[pointer_2++];

    cout<<"Sorted part of size "<<size_1+size_2<<" : [";
    for (int index = left; index <right ; ++index)
        cout<<data[index]<<',';
    cout<<data[right]<<"]\n";

}

template<typename T>
void SortingSystem<T>::quickSort(int left, int right) {

    if(left>=right)
        return;
    int pivot = partition(left,right);


    cout<<"Pivot: "<<data[pivot]<<" --> [";
    for (int index = left; index < pivot-1 ; ++index)
        cout<<data[index]<<", ";
    cout<<data[pivot-1]<<"] "<<data[pivot]<<" [";
    for (int index = pivot+1; index < right ; ++index)
        cout<<data[index]<<", ";
    cout<<data[right]<<"]\n";


    quickSort(left,pivot-1);
    quickSort(pivot+1,right);
}

template <typename T>
int SortingSystem<T>::partition(int low, int high) {

    int pivot = data[low];
    int pointer_1=low;

    for (int pointer_2 = low+1; pointer_2 <= high ; ++pointer_2)
        if(data[pointer_2]<pivot)
            swap(data[++pointer_1],data[pointer_2]);


    swap(data[pointer_1],data[low]);
    return pointer_1;

}

//Some revision and test !!
template <typename T>
void SortingSystem<T>::countSort() {

    //Zero-Based
    int * sorted_array = new int (size);

    int max = *( max_element(data , data+size) );
    int * freq_array = new int (max+1);


    for (int index = 0; index <= max; ++index)
        freq_array[index]=0;
    for (int index = 0; index < size; ++index)
        freq_array[index]++;
    for (int index = 1; index <=max ; ++index)
        freq_array[index]+=freq_array[index-1];

    for (int index = size-1; index >=0 ; --index) {
        int new_position = --freq_array[ data[index] ];
        sorted_array[new_position]=data[index];
    }

    delete freq_array , delete data;
    data=sorted_array;
}

template<typename T>
void SortingSystem<T>::radixSort() {

    int * sorted_array= new int (size);
    int * freq_array  = new int (10);
    int max = * (max_element(data,data+size));

    for (int divisor = 1; max/divisor > 0 ; divisor*=10) {

        for (int index = 0; index < 10; ++index)
            freq_array[index]=0;
        for (int index = 0; index < size; ++index) {
           int digit= (data[index] / divisor) % 10 ;
           freq_array[digit]++;
        }
        for (int index = 1; index < 10; ++index)
            freq_array[index]+=freq_array[index-1];

        for (int index =size-1; index >=0 ; --index) {
            int digit= (data[index] / divisor) % 10 ;
            int new_position=--freq_array[digit];
            sorted_array[new_position]=data[index] ;
        }
        swap(sorted_array,data);
    }

}