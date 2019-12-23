//
// Created by weip on 2019/12/20.
//

#ifndef NDKCPP_FRIENDFUNC_H
#define NDKCPP_FRIENDFUNC_H


class FriendFunc {
private:
    char* name;
public:
    FriendFunc();
    //声明一个友元函数(friend关键字)
    friend void update_name(FriendFunc *func,char *name);
    char* getName();
};

#endif //NDKCPP_FRIENDFUNC_H
