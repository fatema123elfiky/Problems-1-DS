//
// Created by Fatma on 3/12/2025.
//

#include "UI.h"
#include <iostream>
#include "SortingSystem.h"
#include <algorithm>
using namespace std;

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




bool UI::start(){

    string text="Enter which data type you want?"
                "\n1.float\n2.int\n3.string\n4.character"
                "\n5.long long\nEnter your choice : ";
    string choices []={"1","2","3","4","5"};
    string choice = check_menu(text,choices,5);


    string Size;
    cout<<"Enter the number of the items : ";
    getline(cin,Size);
    while (!isDigit(Size)) {
        cout<<"Please enter a valid number : ",getline(cin,Size);
    }
    int size= stoi(Size);


    if(choice=="1")
        SortingSystem<float>sort(size);
    else if(choice=="2")
        SortingSystem<int>sort(size);
    else if(choice=="3")
        SortingSystem<string>sort(size);
    else if(choice=="4")
        SortingSystem<char>sort(size);
    else
        SortingSystem<long long>sort(size);



    text="Do you want to sort another data set ? (y/n): ";
    string answers []={"y","n"};
    choice = check_menu(text,answers,2);


    if(choice=="n")
        return false;

    return true;
}