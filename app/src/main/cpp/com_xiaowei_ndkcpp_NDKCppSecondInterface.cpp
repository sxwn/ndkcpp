
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
    __android_log_print(ANDROID_LOG_INFO,"weip","名称:%s,年龄:%d",company->getName(),company->getAge());
};
}

