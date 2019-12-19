
#include <iostream>
#include <android/log.h>
#include "com_xiaowei_ndkcpp_NDKCppSecondInterface.h"
#include "model/Company.h"

using namespace std;
extern "C" {
JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCppSecondInterface_executeCppConstruct(JNIEnv *, jobject){
//    Company company;
//    company.setName("混合开发");
//    __android_log_print(ANDROID_LOG_INFO,"weip","名称:%s",company.getName());
    //构造函数初始化
    //无参数构造
//    Company company;
//    __android_log_print(ANDROID_LOG_INFO,"weip","名称:%s",company.getName());
    //有参数构造第一种写法:
    //构造方法是一个参数,可以使用该方式
//    Company company = "阿里巴巴";
    //两个参数
//    Company company("阿里巴巴",200);  or   Company company = Company("阿里巴巴",200);
//    Company company = Company("阿里巴巴",200);
//    __android_log_print(ANDROID_LOG_INFO,"weip","名称:%s,年龄:%d",company.getName(),company.getAge());

    //指针方式来进行构造
    Company* company = new Company("阿里巴巴",200);
    //(*company).getName() ===>company->getName()
    __android_log_print(ANDROID_LOG_INFO,"weip","名称:%s,年龄:%d",company->getName(),company->getAge());
};
//C++中的析构函数
JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCppSecondInterface_executeCppDestrcut(JNIEnv *env, jobject jobj){
    //什么时候会被调用？
    //company:局部变量
    //析构函数在释放对象之前调用
    //作用：用于善后工作(释放内存)
//    Company company("动脑子了",100);
//    Company company;
    Company* company = new Company("动脑子了",100);
    //new关键字实例化和不用new实例化区别?   new实例化不调用析构函数,需要手动调用析构函数,不使用new实例化,虚拟机自动帮助我们管理
    __android_log_print(ANDROID_LOG_INFO,"weip","名称:%s,年龄:%d",company->getName(),company->getAge());
    //注意:手动调用析构函数
    company->~Company();
};
}

