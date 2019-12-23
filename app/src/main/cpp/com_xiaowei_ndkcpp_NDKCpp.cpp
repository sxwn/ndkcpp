//
// Created by Administrator on 2019/12/20.
//
#include "com_xiaowei_ndkcpp_NDKCpp.h"
#include <iostream>
using namespace std;

#include "model/Student.h"
#include "model/StaticClass.h"
#include "model/FriendFunc.h"
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
//C++ static关键字
//static修饰属性 修饰函数
#include "model/StaticClass.h"
//静态属性,需要在函数的外部进行初始化
int StaticClass::age = 100;

JNIEXPORT void JNICALL
Java_com_xiaowei_ndkcpp_NDKCpp_callCppStatic(JNIEnv *env, jobject jobj){
//    StaticClass staticClass = StaticClass("Dream");
//    staticClass.age = 100;
//    __android_log_print(ANDROID_LOG_INFO,"weip","age:%d",StaticClass::age);
    //访问静态方法
    StaticClass::toString();
};

//C++对象大小
//回想:结构体大小
//结果:objectSizeA大小:8  objectSizeB大小:12  objectSizeC大小;12
//内存分配
//C++类对象的属性和成员函数内存分开存储的
//普通属性:存储在对象中,与结构体存储规则一样
//静态属性:存在静态数据区(内存区:栈、堆、静态区、全局区、代码区)
//成员函数:存储在代码区

//问题:既然成员函数都是放置在代码区,共享,那么函数怎么知道当前访问的是哪一个对象?
//解决方案:this区分
#include "model/ObjectSize.h"
JNIEXPORT void JNICALL
Java_com_xiaowei_ndkcpp_NDKCpp_callCppObjectSize(JNIEnv *env, jobject thiz){
    __android_log_print(ANDROID_LOG_INFO,"weip","objectSizeA大小: %d", sizeof(ObjectSizeA));
    __android_log_print(ANDROID_LOG_INFO,"weip","objectSizeB大小: %d", sizeof(ObjectSizeB));
    __android_log_print(ANDROID_LOG_INFO,"weip","objectSizeC大小: %d", sizeof(ObjectSizeC));
    //C++中类的底层实现相当于一个结构体
    ObjectSizeC c1;
    ObjectSizeC c2;
    ObjectSizeC c3;
    c1.toString();
    c2.toString();
    c3.toString();
};
//C++中const修饰函数(常量函数)
//const修饰什么?
//属性不能修改
//总结:const修饰的this指针所指向的内存区域不能够修改
JNIEXPORT void JNICALL
Java_com_xiaowei_ndkcpp_NDKCpp_callCppConstFunc(JNIEnv *env, jobject jobj){

};
//C++中友元函数
//需求:我要访问私有属性
//友元函数实现
//void update_name(FriendFunc *func,char *name){
//    func->name = name;
//}

JNIEXPORT void JNICALL
Java_com_xiaowei_ndkcpp_NDKCpp_callCppFriendFunc(JNIEnv *env, jobject jobj){
    FriendFunc* friendFunc = new FriendFunc();
//    //硬是要访问?  解决访问:友元函数
//这块调取友元函数报错,目前未找到解决方案
//    update_name(friendFunc,"Hello");
    __android_log_print(ANDROID_LOG_INFO,"weip","值: %s",friendFunc->getName());
};
//c++中友元类
//A类需要访问B类中的私有属性或者函数？
//解决方案:友元类(java反射机制的底层实现)
//注意:A类需要声明B类是我d的友元类,之后B类可以访问A类的任何属性和方法
#include "model/FriendClass.h"
JNIEXPORT void JNICALL
Java_com_xiaowei_ndkcpp_NDKCpp_callCppFriendClass(JNIEnv *env, jobject thiz){
    __android_log_print(ANDROID_LOG_INFO,"weip","友元类");
    //为什么不能够修改?
    //打印结构:A创建了2次,拷贝了1次,析构了3次  b创建了1次,析构了1次
//    FriendA friendA;
//    friendA.setName("Dream");
//    __android_log_print(ANDROID_LOG_INFO,"weip","修改之前的值: %s",friendA.getName());
    //A第二次创建,是因为FriendB有一个FriendA的属性调用构造函数(因为对象属性需要初始化)
//    FriendB friendB;
    //拷贝对象:实参初始化形参,这个时候也会进行对象拷贝
    //第一次析构(析构形参):因为形参在update_friendA方法中使用完毕,会立马进行析构形参对象
//    friendB.update_friendA(friendA,"jack");
//    __android_log_print(ANDROID_LOG_INFO,"weip","修改之后的值: %s",friendA.getName());
    //第二次析构:析构friendA
    //第三次析构:析构friendB中friendA属性
    //那么怎么样才能够实现修改?
    //解决方案:传递指针引用
//    FriendA* friendA = new  FriendA();
//    friendA->setName("Dream");
//    __android_log_print(ANDROID_LOG_INFO,"weip","修改之前的值: %s",friendA->getName());
//    FriendB friendB;
//    friendB.update_friendA_name(friendA,"jack");
//    __android_log_print(ANDROID_LOG_INFO,"weip","修改之后的值: %s",friendA->getName());
    FriendA friendA =  FriendA();
    friendA.setName("Dream");
    __android_log_print(ANDROID_LOG_INFO,"weip","修改之前的值: %s",friendA.getName());
    FriendB friendB;
    friendB.update_friendA_name(&friendA,"jack");
    __android_log_print(ANDROID_LOG_INFO,"weip","修改之后的值: %s",friendA.getName());

};


}
