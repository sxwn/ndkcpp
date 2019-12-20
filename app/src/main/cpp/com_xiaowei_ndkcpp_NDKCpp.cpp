//
// Created by Administrator on 2019/12/20.
//
#include "com_xiaowei_ndkcpp_NDKCpp.h"
#include <iostream>
using namespace std;

#include "model/Student.h"
#include <android/log.h>

extern "C" {
    //C++构造函数
    //需求:Teacher类中没有提供无参数的构造函数,在Student类中定义一个Teacher属性变量
    //需要初始化
    //什么时候析构函数调用?
JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCpp_callCppConstruct
        (JNIEnv *env, jobject jobj){
    //创建两个Teacher对象,创建一个Student对象
    Student student = Student("印度阿三","lisi","wangwu");
    //释放
    //首先释放析构Student,再释放析构Teacher
    //注意:顺序类似于栈的数据结构(先进后出,后进先出)
};
//new delete关键字
JNIEXPORT void JNICALL
Java_com_xiaowei_ndkcpp_NDKCpp_callCppNewOrDelete(JNIEnv *env, jobject jobj){
    //基本数据类型
    //在堆内存中开辟一块内存空间
//    int *p = (int*)(malloc(sizeof(int)));
//    *p = 100;
//    //释放内存
//    free(p);
//    p=NULL;
    //C++中提供了非常简便的方式(采取new、delete关键字)
    //new int 相当于(int*)(malloc(sizeof(int)))
//    int *p = new int;
//    *p = 100;
    //释放内存
//    delete p;
//    free(p);
//    p =NULL;

    //数组类型
    //在C语言中(动态内存分配)
    //返回的p就是数组的首地址,通过指针位移的方式一个个读取
//    int *p = (int *)malloc(sizeof(int)*10);
//    p[0] = 100;
//    free(p);
    //C++中
//    int *p = new int[10];
//    p[0] = 19;
//    //注意:释放数组
//    delete[] p;

    //分配对象
    //C++中支持C的混编
//    Teacher* teacher =  (Teacher*)malloc(sizeof(Teacher)) ;
//    teacher->setName("detam");
//    //释放内存
//    free(teacher);
    //直接C++语法
    //这个开辟内存是栈内存(自动管理)
//    Teacher teacher = Teacher();
    //开辟的是堆内存
    Teacher* teacher = new Teacher();
    teacher->setName("detam");
    delete teacher;
};
}
