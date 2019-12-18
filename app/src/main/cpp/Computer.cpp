//
// Created by weip on 2019/12/18.
//
#include <iostream>
#include "Computer.h"

void Computer::setCPU(char* cpu){
    this->cpu = cpu;
};
char* Computer::getCPU(){
    return this->cpu;
};
void Computer::setDisplay(char* display){
    this->display = display;
}
char* Computer::getDisplay(){
    return this->display;
};
void Computer::setName(char* name){
    this->name = name;
}
char* Computer::getName(){
    return this->name;
};
void Computer::setMemory(int memory){
    this->memory = memory;
}
int Computer::getMemory(){
    return this->memory;
};
void Computer::setAge(int age){
    this->age = age;
}
int Computer::getAge(){
    return this->age;
};

