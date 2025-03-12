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

        if(choice=="1")
            insertionSort(),sortFunc=&SortingSystem<T>::insertionSort;

        else if(choice=="2")
            selectionSort(),sortFunc=&SortingSystem<T>::selectionSort;

        else if(choice=="3")
            bubbleSort(),sortFunc=&SortingSystem<T>::bubbleSort;

        else if(choice=="4")
            shellSort(),sortFunc=&SortingSystem<T>::shellSort;

        else if(choice=="5")
            mergeSort(0, size - 1),sortFunc_2=&SortingSystem<T>::mergeSort;

        else if(choice=="6")
            quickSort(0, size - 1),sortFunc_2=&SortingSystem<T>::quickSort;//~~

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




        cout<<"\n\n";
        displayData();

        if(sortFunc)
            measureSortTime(sortFunc);
        else
            measureSortTime(sortFunc_2);




}

template <typename T>
void SortingSystem<T>::displayData() {

    cout<<"Sorted Data: [";
    for (int index = 0; index < size-1; ++index)
        cout<<data[index]<<',';
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