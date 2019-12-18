//
// Created by Administrator on 2019/12/18.
//

#include <iostream>
#include <android/log.h>
#include "Company.h"
using namespace std;

Company::Company() {
//    this->name ="格尔";
//    this->age = 100;
//    __android_log_print(ANDROID_LOG_INFO,"weip","调用了构造函数");
    this->age = 100;
    //开辟一块内存
    this->name = (char*)malloc(sizeof(char)*1000);
    strcpy(this->name,"歌尔农场");
    __android_log_print(ANDROID_LOG_INFO,"weip","调用了构造函数");
}
Company::Company(char *name) {
    __android_log_print(ANDROID_LOG_INFO,"weip","调用了构造函数");
    this->name = name;
}
Company::Company(int age) {
    __android_log_print(ANDROID_LOG_INFO,"weip","调用了构造函数");
    this->age = age;
}
Company::Company(char *name, int age) {
    __android_log_print(ANDROID_LOG_INFO,"weip","调用了构造函数");
    this->name = name;
    this->age = age;
}
//实现析构函数
Company::~Company() {
    //析构函数释放内存(堆内存)
    free(this->name);
    __android_log_print(ANDROID_LOG_INFO,"weip","调用了析构函数");
}

void Company::setAge(int age) {
    this->age = age;
}
int Company::getAge() {
    return this->age;
}

void Company::setName(char *name) {
    this->name = name;
}

char* Company::getName() {
    return this->name;
}

