//
// Created by Fatma on 3/12/2025.
//


#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
using namespace std;


void* Array;
string choice_sorting;
bool isFile= false;

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
    void measureSortTime(void (SortingSystem<T>::*sortFunc) () );//done
    void measureSortTime(void (SortingSystem<T>::*sortFunc) (int left , int right) , int left ,int right );//done
    void viewMenu();//done

};

string check_menu(const string& menuText ,const string choices[],int size ){
    string currentAnswer;

    while(true){
        cout << menuText ;
        if(isFile)
            return nullptr;
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
        if(isFile)
            choice=choice_sorting;







        if(choice=="1") {

            cout<<"Sorting using insertion ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            measureSortTime(&SortingSystem<T>::insertionSort);

        }
        else if(choice=="2") {

            cout<<"Sorting using selection ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            measureSortTime(&SortingSystem<T>::selectionSort);

        }
        else if(choice=="3") {

            cout<<"Sorting using bubbleSort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            measureSortTime(&SortingSystem<T>::bubbleSort);

        }
        else if(choice=="4") {

            cout<<"Sorting using shellSort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            measureSortTime(&SortingSystem<T>::shellSort);

        }
        else if(choice=="5") {

            cout<<"Sorting using merge sort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            measureSortTime(&SortingSystem<T>::mergeSort,0,size-1);

        }
        else if(choice=="6") {
            cout<<"Sorting using quicksort ... \n";
            cout<<"Initial data : ";
            displayData();
            cout<<'\n';
            measureSortTime(&SortingSystem<T>::quickSort,0,size-1);
        }
        else if(choice=="7"){

            if constexpr (is_integral_v<T>)
                measureSortTime(&SortingSystem<T>::countSort);

            else {
                cout << "Sorry ,Try again!!\n\n";
                goto again;
            }

        }else if(choice=="8"){

            if constexpr (is_integral_v<T>)
                measureSortTime(&SortingSystem<T>::radixSort);

            else {
                cout << "Sorry ,Try again!!\n\n";
                goto again;
            }

        }else
            measureSortTime(&SortingSystem<T>::bucketSort);




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

    if(!isFile) {
        data = new T[size];
        int counter=0;
        while (counter<size) {
            cout << "Enter data " << counter+1 << ": ";
            cin>>data[counter++];
        }
    }
    else
        data=static_cast<T*>(Array);

    viewMenu();
}

template <typename T>
SortingSystem<T>::~SortingSystem() {
    delete [] data ;
}

template <typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem<T>::*sortFunc)()) {

    auto start= chrono::high_resolution_clock ::now();
    (this->*sortFunc)();
    auto end=chrono::high_resolution_clock ::now();
    cout<<"\n\n"<<"Sorted data : ";
    displayData();
    chrono:: duration<double> Duration = end-start;
    cout<<"Sorting Time: "<<Duration.count()<<" seconds ";

}

template<typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem<T>::*sortFunc)(int, int), int left, int right) {
    auto start= chrono::high_resolution_clock ::now();
    (this->*sortFunc)(left,right);
    auto end=chrono::high_resolution_clock ::now();
    cout<<"\n\n"<<"Sorted data : ";
    displayData();
    chrono:: duration<double> Duration = end-start;
    cout<<"Sorting Time: "<<Duration.count()<<" seconds ";
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

    T*part_1=new T[size_1];
    T*part_2=new T[size_2];

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

    T pivot = data[low];
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
    T * sorted_array = new T [size];

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

    T * sorted_array= new T[size];
    int * freq_array  = new int [10];
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

int main(){

    string Text="you want to take input from file or user ?\n1.file\n2.user\nEnter your choice : ";
    string options[] = {"1", "2"};
    string Choice = check_menu(Text, options, 2);


    ifstream File("input.txt");

    if(Choice=="1")
        isFile= true;

    while (true){

        string Size,type,isBreak;

        if(isFile){
            File>>type>>Size;
            int size=stoi(Size);

            if(type=="1") {
                Array = new float[size];
            }
            else if (type == "2") {
                Array = new int[size];
            }
            else if (type == "3") {
                Array = new string[size];
            }
            else if (type == "4") {
                Array = new char[size];
            }
            else {
                Array = new long long[size];
            }

            int counter=0;
            while (counter<size){
                ostringstream value;

                if(type=="1") {
                    string val;
                    File>>val;
                    value<<val;
                    float * ConvertArray=static_cast<float*>(Array);
                    ConvertArray[counter] = stof(value.str());
                }else if (type == "2"){
                    string val;
                    File>>val;
                    value<<val;
                    int * ConvertArray=static_cast<int*>(Array);
                    ConvertArray[counter] = stoi(value.str());
                }else if(type=="3"){
                    string val;
                    File>>val;
                    value<<val;
                    string * ConvertArray=static_cast<string*>(Array);
                    ConvertArray[counter] = value.str();
                }else if(type == "4") {
                    char val;
                    File>>val;
                    char * ConvertArray=static_cast<char*>(Array);
                    ConvertArray[counter] = val;
                }
                else {
                    string val;
                    File>>val;
                    value<<val;
                    long long * ConvertArray=static_cast<long long*>(Array);
                    ConvertArray[counter] = stoll(value.str());
                }
                counter++;
            }

            File>>choice_sorting;
            File>>isBreak;

        }

        string text = "Enter which data type you want?"
                      "\n1.float\n2.int\n3.string\n4.character"
                      "\n5.long long\nEnter your choice : ";
        string choices[] = {"1", "2", "3", "4", "5"};
        string choice = check_menu(text, choices, 5);

        if(isFile)
            choice=type;

        int size ;
        if(!isFile){
            string volume;
            cout << "Enter the number of the items : ";
            getline(cin, volume);
            while (!isDigit(volume))
                cout << "Please enter a valid number : ", getline(cin, volume);
            size=stoi(volume);
        }else
            size= stoi(Size);



        if (choice == "1")
            SortingSystem<float> SortedArray(size);
        else if (choice == "2")
            SortingSystem<int> SortedArray(size);
        else if (choice == "3")
            SortingSystem<string> SortedArray(size);
        else if (choice == "4")
            SortingSystem<char> SortedArray(size);
        else
            SortingSystem<long long> SortedArray(size);


        text = "Do you want to sort another data set ? (y/n): ";
        string answers[] = {"y", "n"};
        choice = check_menu(text, answers, 2);
        if(isFile)
            choice=isBreak;

        if (choice == "n")
            break;

    }
}