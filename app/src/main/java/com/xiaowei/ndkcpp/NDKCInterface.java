package com.xiaowei.ndkcpp;

/**
 * 生成头文件:
 * 1、build项目，生成class文件
 * 2、进入到javac/debug/classes文件夹中
 * 3、javah -jni com.xiaowei.ndkcpp.NDKCInterface
 */
public class NDKCInterface {

    //常量
    public native void executeCConst();
}
