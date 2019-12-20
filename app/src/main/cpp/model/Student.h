//
// Created by Administrator on 2019/12/20.
//

#ifndef NDKCPP_STUDENT_H
#define NDKCPP_STUDENT_H
#include <android/log.h>
#include "Teacher.h"

//解决方案:初始化
//第一种写法:Teacher提供无参构造方法
//第二种写法: Teacher headerTeacher = "xxx";  Teacher subjectTeacher = "xxx";
//第三种写法:Teacher headerTeacher =  Teacher("xxx"); Teacher subjectTeacher = Teacher("xxx");
//第四种写法:Student::Student(char *name):headerTeacher("dd"),subjectTeacher("ff") {
//    this->name = name;
//}
//第五种写法:
//class Student {
//private:
//    char* name;
//    //班主任
//    Teacher headerTeacher;
//    //任课老师
//    Teacher subjectTeacher;
//public:
//    //有参构造
//    Student::Student(char *name,char* headName,char* subjectName)
//            :headerTeacher(headName),subjectTeacher(subjectName){
//        this->name = name;
//    };
//};
class Student {
private:
    char* name;
    //班主任
    Teacher headerTeacher;
    //任课老师
    Teacher subjectTeacher;
public:
    //有参构造
    Student(char *name,char* headName,char* subjectName)
            :headerTeacher(headName),subjectTeacher(subjectName){
        this->name = name;
        __android_log_print(ANDROID_LOG_INFO,"weip","Student构造函数");
    };
    ~Student(){
        __android_log_print(ANDROID_LOG_INFO,"weip","Student析构函数");
    }
};



#endif //NDKCPP_STUDENT_H
