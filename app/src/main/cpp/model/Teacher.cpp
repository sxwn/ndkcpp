
#include "Teacher.h"

Teacher::Teacher() {
    this->name = "Dream";
    __android_log_print(ANDROID_LOG_INFO,"weip","Teacher构造函数");
}
Teacher::Teacher(char* name){
    this->name = name;
    __android_log_print(ANDROID_LOG_INFO,"weip","Teacher构造函数");
}

Teacher::~Teacher(){
__android_log_print(ANDROID_LOG_INFO,"weip","Teacher析构函数");
}

void Teacher::setName(char *name) {
    this->name = name;
}