//Nicholas Guidice
//CS 375 Program 3 "heapSort"

//Runtime Information
//Computer: Lenovo Yoga 7 Laptop, OS: Windows, CPU: Intel i5-1135G7
//mergeSort Time: 1M: 0m47.913s 10M: 4m29.721s
//heapSort Time: 1M: 0m7.442s 10M: 1m9.526s

//Conclusions: heapSort is significantly faster than mergeSort, It is roughly a constant factor comparing 1M and 10M

//Import Libraries 
#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int num, int i){
    int root = i; //Intialize Largest Value To Make Root
    int leftChild = 2 * i + 1; //Left Child Index
    int rightChild = 2 * i + 2; //Right Child Index

    //Check If Left Child Exists And Is Greater Than Root
    if (leftChild < num && arr[leftChild] > arr[root]){
        root = leftChild;
    }

    //Check If Right Child Exists And Is Greater Than Root
   if (rightChild < num && arr[rightChild] > arr[root]){
        root = rightChild;
    }

    //If Largest Is Not Root, Swap And Continue Heapify
    if(root != i){
        swap(arr[i],arr[root]);
        heapify(arr,num,root);
    }
}

void buildHeap(vector<int>& arr){
    int num = arr.size();
    for(int i = num / 2 - 1; i >= 0; i--){
        heapify(arr,num,i);
    }
}

void heapSort(vector<int>& arr){
    buildHeap(arr); //Build A Max Heap
    int num = arr.size();

    //Extract Elements From Heap One By One
    for (int i = num - 1; i > 0; i--){
        swap(arr[0],arr[i]); //Move Current Root To End
        heapify(arr,i,0); //Call Heapify On The Reduced Heap
    }
}

void print(const vector<int>& arr){
    //Format 
    cout << "Total Numbers: " << arr.size() << endl;
    //Iterate Over The Entire Array And Print
    /*
    cout << "Sorted Array:" << endl;
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " " << endl;
    }
    */
}

int main (int argc, char* argv[]){
    //Declare Variable That Will Hold The Size Of The Vector
    int arrNum;

    // Define A Value Vector To The Correct Size
    cin >> arrNum;
    vector<int> valArr(arrNum);

    // Read In the Pre-Sorted Values Into The Vector 
    for (int i = 0; i < arrNum; i++) {
        cin >> valArr[i];
    }

    //Call heapSort 
    heapSort(valArr);

    //Call Print Function
    print(valArr);

    // End Main
    return 0;
}
