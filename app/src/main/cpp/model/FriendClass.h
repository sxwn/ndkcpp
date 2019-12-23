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
};

class FriendB{
private:
    FriendA friendA;
public:
    FriendB();
    void myprint(){
        friendA.name
    };
};



#endif //NDKCPP_FRIENDCLASS_H
