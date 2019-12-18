//
// Created by Administrator on 2019/12/18.
//

#ifndef NDKCPP_COMPANY_H
#define NDKCPP_COMPANY_H
class Company{
private:
    int age;
    char* name;
public:
    //无参构造
    Company();
    Company(char* name);
    Company(int age);
    Company(char* name,int age);
    void setAge(int age);
    int getAge();
    void setName(char* name);
    char* getName();
};

#endif //NDKCPP_COMPANY_H
