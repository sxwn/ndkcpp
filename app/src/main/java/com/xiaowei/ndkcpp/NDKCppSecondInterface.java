package com.xiaowei.ndkcpp;

public class NDKCppSecondInterface {
    //C++构造函数
    public native void executeCppConstruct();
    //C++析构函数
    public native void executeCppDestrcut();
    //C++中拷贝函数、赋值运算
    public native void executeCppCopyFunc();
    //C++中拷贝函数调用场景
    public native void executeCppCopyFuncScene();
    //C++中的浅拷贝和深拷贝
    public native void executeCppCopy();
}
