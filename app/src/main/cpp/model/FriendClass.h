//
// Created by Administrator on 2019/12/23.
//

#ifndef NDKCPP_FRIENDCLASS_H
#define NDKCPP_FRIENDCLASS_H


class FriendA{
private:
    int age;
    char* name;
    void toString();
    //声明FriendB是FriendA的朋友
    friend class FriendB;

public:
    FriendA();
    //析构函数
    ~FriendA();
    //拷贝函数
    FriendA(const FriendA &friendA);
    void setName(char *name);

    char* getName();
};

class FriendB{
private:
    FriendA friendA;
public:
    FriendB();
    ~FriendB();
    //拷贝函数
    FriendB(const FriendB &friendB);
    void myprint();
    void update_friendA(FriendA friendA,char* name);
};



#endif //NDKCPP_FRIENDCLASS_H
