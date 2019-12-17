package com.xiaowei.ndkcpp;

/**
 * javah -jni com.xiaowei.ndkcpp.NDKCppInterface
 */
public class NDKCppInterface {
    //c++中的常量
    public native void executeCppConst();
    //指针的引用
    public native void executeCppPointer();
    //常引用
    public native void executeCppConstRef();
    //内联函数
    public native void executeCppInlineFunc();
}
