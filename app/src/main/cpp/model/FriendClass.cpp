//
// Created by Administrator on 2019/12/23.
//

#include "FriendClass.h"
#include <android/log.h>

FriendA::FriendA() {
    __android_log_print(ANDROID_LOG_INFO,"weip","FriendA构造函数");
}
FriendA::~FriendA() {
    __android_log_print(ANDROID_LOG_INFO,"weip","FriendA析构函数");
}
FriendA::FriendA(const FriendA &friendA) {
    this->name =friendA.name;
    this->age = friendA.age;
    __android_log_print(ANDROID_LOG_INFO,"weip","FriendA拷贝函数");
}
void FriendA::toString() {

}
void FriendA::setName(char *name) {
    this->name = name;
}

char* FriendA::getName() {
    return this->name;
}


/***********************B类*****************************/
FriendB::FriendB() {
    __android_log_print(ANDROID_LOG_INFO,"weip","FriendB构造函数");
}
FriendB::~FriendB() {
    __android_log_print(ANDROID_LOG_INFO,"weip","FriendB析构函数");
}
FriendB::FriendB(const FriendB &friendB) {
    __android_log_print(ANDROID_LOG_INFO,"weip","FriendB拷贝函数");
}
void FriendB::update_friendA(FriendA friendA,char* name){
//    this->friendA = friendA;
//    this->friendA.name = name;
    friendA.name = name;
    __android_log_print(ANDROID_LOG_INFO,"weip","update_friendA");
}
void FriendB::update_friendA_name(FriendA* friendA, char *name) {
    friendA->name = name;
}
void FriendB::update_friendA_p(FriendA *friendA, char *name) {
    friendA->name = name;
}
void FriendB::myprint() {
    __android_log_print(ANDROID_LOG_INFO,"weip","myprint");
}