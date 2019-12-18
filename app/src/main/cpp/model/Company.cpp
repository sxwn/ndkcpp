//
// Created by Administrator on 2019/12/18.
//

#include <iostream>
#include <android/log.h>
#include "Company.h"
using namespace std;

Company::Company() {
    this->name ="格尔";
    this->age = 100;
}
Company::Company(char *name) {
    this->name = name;
}
Company::Company(int age) {
    this->age = age;
}
Company::Company(char *name, int age) {
    this->name = name;
    this->age = age;
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

