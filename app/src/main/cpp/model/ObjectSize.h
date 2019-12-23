//
// Created by Administrator on 2019/12/20.
//

#ifndef NDKCPP_OBJECTSIZE_H
#define NDKCPP_OBJECTSIZE_H


class ObjectSizeA {
private:
    int a;
    int b;
};

class ObjectSizeB {
private:
    int a;
    int b;
    int c;
public:
    static int d;
};

class ObjectSizeC {
private:
    int a;
    int b;
    int c;
public:
    void toString();
};



#endif //NDKCPP_OBJECTSIZE_H
