//
// Created by Administrator on 2019/12/20.
//

#ifndef NDKCPP_TEACHER_H
#define NDKCPP_TEACHER_H
#include <android/log.h>

class Teacher {
private:
    char *name;
public:
    Teacher();
    //有参构造
    Teacher(char *name);
    ~Teacher();
    void setName(char* name);
};


#endif //NDKCPP_TEACHER_H
