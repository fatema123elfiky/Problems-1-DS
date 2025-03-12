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



template <typename T>
bool UI::start(){

    string Size;
    cout<<"Enter the number of the items : ";
    getline(cin,Size);
    while (!isDigit(Size))
        cout<<"Please enter a valid number : ",getline(cin,Size);
    int size= stoi(Size);

    SortingSystem<T> sort (size);



    string text="Do you want to sort another data set ? (y/n): ";
    string answers []={"y","n"};
    string choice = check_menu(text,answers,2);

    if(choice=="n")
        return false;

    return true;
}