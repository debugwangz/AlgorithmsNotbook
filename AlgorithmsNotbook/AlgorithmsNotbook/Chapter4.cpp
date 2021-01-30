//
//  Chapter4.cpp
//  AlgorithmsNotbook
//
//  Created by 王哲 on 2021/1/30.
//

#include "Chapter4.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

const string inputFile = "PATRanking.txt";

void getRandomNumber(int *arrary, int length);
void printArrary(int * arrary, int length);
void swapInArrary(int * arrary, int index1,int index2);

void mainInC4(){
    int length = 15;
    int arrary[length];
    getRandomNumber(arrary, length);
    //    printArrary(arrary, length);
    //    selectSort(arrary, length);
    //    insertSort(arrary, length);
    //    printArrary(arrary, length);
    ifstream in(inputFile);
    cin.rdbuf(in.rdbuf());
    string str;
    while (cin>>str) {
        cout<<str<<endl;
    }
}

#pragma mark - 交换数组中两数
void swapInArrary(int * arrary, int index1,int index2){
    int tmp = arrary[index1];
    arrary[index1] = arrary[index2];
    arrary[index2] = tmp;
}

#pragma mark - 打印数组
void printArrary(int * arrary, int length){
    for (int i=0; i<length; i++) {
        cout<<arrary[i]<<" ";
    }
    cout<<endl;
}

#pragma mark - 生成随机数数组
void getRandomNumber(int *arrary, int length)
{
    for(int i = 0;i < length;i++){
        int randNumber;
        srand((unsigned)time(NULL)+i);//time()用系统时间初始化种。为rand()生成不同的随机种子。
        randNumber = rand() % 50 + 1;//生成1~100随机数
        arrary[i] = randNumber;
    }
}

#pragma mark - 选择排序
void selectSort(int *arrary , int length){
    cout<<"选择排序"<<endl;
    for (int i = 0; i<length; i++) {
        int smallestIndex = i;
        for (int j = i+1; j<length; j++) {
            if (arrary[j] < arrary[smallestIndex]) {
                smallestIndex = j;
            }
        }
        if (i != smallestIndex) {
            swapInArrary(arrary, i, smallestIndex);
        }
    }
}

#pragma mark - 插入排序
void insertSort(int * arrary,int length){
    cout<<"插入排序"<<endl;
    for (int i = 0; i<length; i++) {
        int j =i+1;
        int temp = arrary[j];
        while (j>0 && (arrary[j-1] > temp)) {
            arrary[j] = arrary[j-1];
            j--;
        }
        arrary[j] = temp;
    }
}

#pragma mark - PAT排名

