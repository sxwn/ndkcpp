
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <android/log.h>
#include "com_xiaowei_ndkcpp_NDKCInterface.h"

//C语言中常量是否可以修改
//C语言中也不能修改
//注意：当前我们用的是Mac环境下的Android Studio开发工具
//思考：现在我要换成Windows下的Visual Studio 2013开发环境试试
//总结：常量的值在C语言中是可以修改的，但是与编译的环境有关系
//例如：在android studio中不可以，在Visual Studio 2013就可以修改
//然而C++语言不管在任何的编译环境中都是不允许修改
JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCInterface_executeCConst
  (JNIEnv *env, jobject jobj){
    const int a = 100;
    int *p = (int*)&a;
    *p = 200;
    __android_log_print(ANDROID_LOG_INFO,"main","C语言：%d",a);
};

