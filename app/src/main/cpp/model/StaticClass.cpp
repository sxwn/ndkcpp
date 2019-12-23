//
// Created by Administrator on 2019/12/20.
//

#include "StaticClass.h"
#include <android/log.h>

StaticClass::StaticClass(char *name) {
    this->name = name;
    __android_log_print(ANDROID_LOG_INFO,"weip","调用了构造函数");
}
StaticClass::~StaticClass() {
    __android_log_print(ANDROID_LOG_INFO,"weip","调用了析构函数");
}

