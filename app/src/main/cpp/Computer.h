//
// Created by Administrator on 2019/12/18.
//
//这个判断就是为了避免重复include
#ifndef NDKCPP_COMPUTER_H
#define NDKCPP_COMPUTER_H
//声明该类
class Computer{
private:
    char *cpu;
    char *display;
    char *name;
    int memory;
    int age;
public:
    void setCPU(char* cpu);
    char* getCPU();
    void setDisplay(char* display);
    char* getDisplay();
    void setName(char* name);
    char* getName();
    void setMemory(int memory);
    int getMemory();
    void setAge(int age);
    int getAge();
};
#endif //NDKCPP_COMPUTER_H
