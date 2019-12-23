//
// Created by Administrator on 2019/12/20.
//

#ifndef NDKCPP_STATICCLASS_H
#define NDKCPP_STATICCLASS_H
#include <android/log.h>

class StaticClass {

private:
    char* name;
public:
    static int age;
    StaticClass(char* name);
    ~StaticClass();
    static void toString(){
        __android_log_print(ANDROID_LOG_INFO,"weip","age:%d",age);
    };
};


#endif //NDKCPP_STATICCLASS_H
