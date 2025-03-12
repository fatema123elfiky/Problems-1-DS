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

bool isDigit(string number){

    for(char digit :number)
        if(!isdigit(digit))
            return false;

    return true;
}


template<typename T>
void SortingSystem<T> :: viewMenu(){

    while (true){

        string Size;
        cout<<"Enter the number of the items : ";
        getline(cin,Size);

        while (!isDigit(Size))
            cout<<"Please enter a valid number : ",getline(cin,Size);

        size= stoi(Size);


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


        if(choice=="1")
            insertionSort();
        else if(choice=="2")
            selectionSort();
        else if(choice=="3")
            bubbleSort();
        else if(choice=="4")
            shellSort();
        else if(choice=="5")
            mergeSort(0,size-1);
        else if(choice=="6")
            quickSort(0,size-1);//~~
        else if(choice=="7"){

            if constexpr (is_integral_v<T>)
              countSort();
            else {
                cout << "Sorry ,Try again!!\n\n";
                goto again;
            }

        } else if(choice=="8"){

            if constexpr (is_integral_v<T>)
                radixSort();
            else {
                cout << "Sorry ,Try again!!\n\n";
                goto again;
            }

        }else
            bubbleSort();


       

        displayData();
        measureSortTime();




    }

}

template <typename T>
void SortingSystem<T>::displayData() {

    cout<<"Sorted Data: [";
    for (int index = 0; index < size-1; ++index)
        cout<<data[index]<<',';
    cout<<data[size-1]<<"]\n";
}
