package com.xiaowei.ndkcpp;

public class NDKCpp {
    //C++构造函数
    public native void callCppConstruct();
    //C++new关键字、delete关键字
    public native void callCppNewOrDelete();
    //C++ static关键字
    public native void callCppStatic();
    //C++中对象的大小
    public native void callCppObjectSize();
    //C++中const修饰函数(常量函数)
    public native void callCppConstFunc();
    //C++中友元函数
    public native void callCppFriendFunc();
    //C++中友元类
    public native void callCppFriendClass();
}
