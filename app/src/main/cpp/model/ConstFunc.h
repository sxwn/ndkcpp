//
// Created by Administrator on 2019/12/20.
//

#ifndef NDKCPP_CONSTFUNC_H
#define NDKCPP_CONSTFUNC_H


class ConstFunc {
private:
    int age;
public:
    void toString() const {
        //不允许修改属性
//        age = 100;
//        this = (ConstFunc*)0x1233112;
    };
};


#endif //NDKCPP_CONSTFUNC_H
