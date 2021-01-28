//
//  Chapter3.cpp
//  AlgorithmsNotbook
//
//  Created by 王哲 on 2021/1/28.
//

#include "Chapter3.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#pragma mark - 卡拉兹猜想
bool isEvenNumber(int number);
int callatz(int input);

void callatz(){
    int input;
    cout<<"输入一个整数"<<endl;
    cin>>input;
    int output = callatz(input);
    cout<<input<<" 的卡拉兹猜想数为 "<<output<<endl;
}

int callatz(int input){
    int count = 0;
    while (input != 1) {
        if (isEvenNumber(input)) {
            input /= 2;
        }else{
            input = (3*input +1)/2;
        }
        count ++;
    }
    return count;
}

bool isEvenNumber(int number){
    if (number % 2 == 0) {
        return true;
    }
    return false;
}

#pragma mark - 挖掘机技术哪家强

void wajueji(){
    cout<<"挖掘机技术哪家强"<<endl;
    int numberOfParticipants;
    cin>>numberOfParticipants;
    int schools[100010] = {0};
    int schoolID =0;
    int scores =0;
    for (int i=0; i<numberOfParticipants; i++) {
        cin>>schoolID;
        cin>>scores;
        schools[schoolID] +=scores;
    }
    for (int i=0; i<numberOfParticipants; i++) {
        if (schools[i]> scores) {
            schoolID = i;
            scores = schools[i];
        }
    }
    cout<<schoolID<<" "<<scores<<endl;
}
#pragma mark - 找x
void searchX(){
    cout<<"找x"<<endl;
    int n =0;
    cin>>n;
    int arrary[n];
    for (int i=0; i<n; i++) {
        cin>>arrary[i];
    }
    int x = 0;
    cin>>x;
    int result = -1;
    for (int i=0; i<n; i++) {
        if (arrary[i] == x) {
            result = i;
            break;
        }
    }
    cout<<result<<endl;
}
#pragma mark - 画正方形
void drawSquare(){
    cout<<"画正方形"<<endl;
    int lineLength = 0;
    int columnLength = 0;
    char C;
    cin>>columnLength>>C;
    if (isEvenNumber(columnLength)) {
        lineLength = columnLength/2;
    }else{
        lineLength = columnLength/2 +1;
    }
    for (int i =0; i<lineLength; i++) {
        if (i == 0 || i == lineLength-1 ) {
            for (int j = 0; j<columnLength; j++) {
                cout<<C;
            }
            cout<<endl;
            continue;
        }
        cout<<C;
        for (int j = 1; j<columnLength-1; j++) {
            cout<<" ";
        }
        cout<<C<<endl;
    }
}
#pragma mark - 日期处理
bool isLeap(int year){
    return (year % 4== 0 && year % 100 != 0)|| (year % 400 == 0);
}
void dateDifference(){
    cout<<"日期求差"<<endl;
    int month[13][2] = {
        {0,0},{31,31},{28,29},{31,31},{30,30},{31,31},{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},{31,31}
    };
    int firstDate;
    int secondDate;
    int days = 1;
//    while ((cin>>firstDate>>secondDate) != EOF){   //从文件读多组数据
    cin>>firstDate>>secondDate;
    if (firstDate > secondDate) {
        int tmp = firstDate;
        firstDate = secondDate;
        secondDate =tmp;
    }
    int firstYear = firstDate / 10000;
    int firstMonth = firstDate % 10000 /100;
    int firstDay = firstDate % 100;
    int secondYear = secondDate /10000;
    int secondMonth = secondDate %10000 / 100;
    int secondDay = secondDate % 100;
    while(firstYear < secondYear || firstMonth < secondMonth || firstDay <secondDay){
        days++;
        firstDay += 1;
        if (firstDay == month[firstMonth][isLeap(firstYear)] +1) {
            firstMonth++;
            firstDay = 1;
        }
        if (firstMonth == 13) {
            firstYear ++;
            firstMonth = 1;
        }
    }
//    }                                              //从文件读多组数据
    cout<<days<<endl;
}

