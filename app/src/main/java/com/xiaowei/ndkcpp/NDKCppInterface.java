package com.xiaowei.ndkcpp;

/**
 * javah -jni com.xiaowei.ndkcpp.NDKCppInterface
 */
public class NDKCppInterface {
    //c++中的常量
    public native void executeCppConst();
    //C++中的指针的引用
    public native void executeCppPointer();
    //C++中的常引用
    public native void executeCppConstRef();
    //C++中的内联函数
    public native void executeCppInlineFunc();
    //C++中的函数参数
    public native void executeCppFuncParam();
    //C++中的函数指针
    public native void executeCppFuncPointer();
    //C++中的AOP 类的定义
    public native void executeCppClass();
}
