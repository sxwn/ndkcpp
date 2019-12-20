
#include <iostream>
#include <android/log.h>
#include "com_xiaowei_ndkcpp_NDKCppInterface.h"

//在C++中命名空间(类似于Java的包)
//std:代表标准命名空间
using namespace std;
extern "C" {
//C++中常量
//C++中常量的值不能够修改（不管你是间接修改还是直接修改，都不是不允许）
JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCppInterface_executeCppConst
        (JNIEnv *env, jobject jobj) {
    const int a = 100;
    //常量不能修改
//    a  = 200;
    //间接修改
    int *p = (int *) &a;
    *p = 200;
    __android_log_print(ANDROID_LOG_INFO, "main", "修改值：%d", a);
} ;
//c++中的引用
struct User{
    char *name;
    int age;
};
//二级指针
//void update_user(User** u){
//    User *user = (User*)malloc(sizeof(User));
//    user->name = "Dream";
//    user->age = 100;
//    *u = user;
//};
//指针的引用
//&u:代表User的地址(相当于引用)
void update_user(User* &u){
    u = (User*)malloc(sizeof(User));
    u->name = "crish";
    u->age = 88;
}
JNIEXPORT void JNICALL
Java_com_xiaowei_ndkcpp_NDKCppInterface_executeCppPointer(JNIEnv *env, jobject jobj) {
    User *user = NULL;
    //二级指针的使用
//    int a = 100;
//    int *p = &a;
//    int **p2 = &p;
//    update_user(&user);
    //指针的引用
    int a = 100;
//    (int*) p = &a;
    //编译器自动将user转成&user
    update_user(user);
    __android_log_print(ANDROID_LOG_INFO, "main", "result：%s",user->name);
} ;
//c++中的常引用(初始化)
void const_init(){
    int a = 100;
    int b = 200;
    //第一种写法:变量赋值
    //常引用的写法：const int &c = a;
    //引用:&c
    //编译器: int* c = &a;
    const int &c = a;
    __android_log_print(ANDROID_LOG_INFO, "main", "常引用变量赋值：%d",c);
    //第一种写法:字变量
    const int &d = 200;
    __android_log_print(ANDROID_LOG_INFO, "main", "字变量：%d\n",d);
}
//常引用作为函数的参数来使用
struct Company{
    char *name;
    char *address;
    int age;
};
//类似于java中的final,只读
void const_func_param(const Company &cp){
    //不能修改(只读)
//    cp.age = 100;
    __android_log_print(ANDROID_LOG_INFO, "main", "公司地址：%s",cp.address);
}
void const_printf(){
    Company company;
    company.address = "望京国际大厦";
    company.name = "阿里";
    company.age = 10;
    const_func_param(company);
}
JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCppInterface_executeCppConstRef(JNIEnv *env, jobject jobj){
//    const_init();
    const_printf();
};
//内联函数
//在程序编译的时候,编译器会将函数调用处的代码替换成函数体
//内联函数:编译的时候调用
//宏定义:预编译
//例如:买书 买书之前准备钱(预编译)  找书店的过程(编译)   找到书店,买书(运行)
//在使用上面内联函数和普通函数没什么区别,但执行的效率比一般的函数要高
inline void printf_inline(){
    char *address = "环普产业园";
    __android_log_print(ANDROID_LOG_INFO, "main", "内容：%s",address);
};
//宏定义和内联函数的区别
//需求:求一个数的积
//总结:这两种情况一般都不要这么写(自增自减)
#define GET_RESULT(A) A*A
inline int get_result(int a ){
    return a*a;
}
void printf_result(){
    int a = 2;
    //宏函数预编译替换
    //12  分析:int b = (++a) * (++a)
    //第一次：a = 3  * ++a
    //第二次: a = 4
    //结果: 3 * 4
//    int b = GET_RESULT(++a);
//内联函数,和普通方法一样
//结果 a * a 然而a=3  结果是9
    int b =get_result(++a);
    __android_log_print(ANDROID_LOG_INFO, "main", "结果：%d",b);
}
JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCppInterface_executeCppInlineFunc(JNIEnv *env, jobject jobj){
    //编译的时候,就是进行拷贝
//    {
//        char *address = "环普产业园";
//        __android_log_print(ANDROID_LOG_INFO, "main", "内容：%s",address);
//     }
//    printf_inline();
    printf_result();
};

//c++中函数参数
//函数参数的默认值
//void func_param(int a = 100){
//    __android_log_print(ANDROID_LOG_INFO, "main", "result：%d",a);
//}
//函数重载(在java中方法重载,参数的个人,类型不同,与返回值无关)
//函数重载需要注意不能够函数"歧义"
//void func_param(int a){
//    __android_log_print(ANDROID_LOG_INFO, "main", "result：%d",a);
//}
//void func_param(int a,int b=10){
//    __android_log_print(ANDROID_LOG_INFO, "main", "result：a=%d,b=%d",a,b);
//}
//b有默认值,后面参数都得有默认值,所以c必须有默认值
//void func_param(int a,int b=10,int c){
//    __android_log_print(ANDROID_LOG_INFO, "main", "result：a=%d,b=%d",a,b);
//}

//c++可变参数
//API都会提示用户传参数的类型
void func_param(int a,...){
    __android_log_print(ANDROID_LOG_INFO, "main", "result：%d",a);
    //获取可变参数
    //定义可变参数指针
    va_list  args_p;
    //首先要指定可变参数开始位置
    va_start(args_p,a);
    //一个个获取(按照顺序来)
    //第一个参数是int类型
    int arg_int = va_arg(args_p, int);
    __android_log_print(ANDROID_LOG_INFO, "main", "第一个参数：%d",arg_int);
    //第二个参数是char类型
    char arg_char = va_arg(args_p, char);
    __android_log_print(ANDROID_LOG_INFO, "main", "第二个参数：%c",arg_char);
    //第三个参数是double类型
    double arg_double= va_arg(args_p, double);
    __android_log_print(ANDROID_LOG_INFO, "main", "第三个参数：%f",arg_double);
    //结束
    va_end(args_p);
}
//循环读取(一般情况下都是指定类型)
//注意:必须要指定可变参数的开始位置
void func_param_int(int a,int len,...){
    //定义可变参数指针
    va_list  args_p;
    //首先要指定可变参数开始位置
    va_start(args_p,len);
    int i = 0;
    int result =0;
    for(i;i<len;i++){
        result = va_arg(args_p,int);
        __android_log_print(ANDROID_LOG_INFO, "main", "参数：%d",result);
    }
//    while (true){
//        i = va_arg(args_p,int);
//        __android_log_print(ANDROID_LOG_INFO, "main", "参数：%d",i);
//        if(i == 60){
//            //告诉程序读取完毕
//            break;
//        }
//    }
    //结束
    va_end(args_p);
}

//函数的预留参数(提高了程序的扩展性)
//void func_param(int a,int){
//    __android_log_print(ANDROID_LOG_INFO, "main", "参数：%d",a);
//}

JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCppInterface_executeCppFuncParam(JNIEnv *env, jobject jobj){
//    func_param();
//    func_param(10);
//    func_param(10,20);
    //歧义?
//    func_param(10);
//    func_param(10,40,'A',45.5);
    func_param_int(10,5,20,30,40,50,60);
//    func_param(10,20);
};
//函数指针
int get_min(int a ,int b,int c,int d){
    return a<b?a:b;
}
//函数指针别名
typedef int (*GET_MIN_P)(int,int,int,int);
JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCppInterface_executeCppFuncPointer(JNIEnv *env, jobject jobj){
//    int (*get_min_p)(int,int) = get_min;
//    int c = get_min_p(10,20);
//    __android_log_print(ANDROID_LOG_INFO, "main", "最小值：%d",c);
    GET_MIN_P p = get_min;
    int result = p(10,20,30,40);
    __android_log_print(ANDROID_LOG_INFO, "main", "最小值：%d",result);
};

//C++中定义个类
//class Computer{
//private:
//    char *cpu;
//    char *display;
//    char *name;
//    int memory;
//    int age;
//public:
//    void setCPU(char* cpu){
//        this->cpu = cpu;
//    };
//    char* getCPU(){
//        return this->cpu;
//    };
//    void setDisplay(char* display){
//        this->display = display;
//    }
//    char* getDisplay(){
//        return this->display;
//    };
//    void setName(char* name){
//        this->name = name;
//    }
//    char* getName(){
//        return this->name;
//    };
//    void setMemory(int memory){
//        this->memory = memory;
//    }
//    int getMemory(){
//        return this->memory;
//    };
//    void setAge(int age){
//        this->age = age;
//    }
//    int getAge(){
//        return this->age;
//    };
//};
#include "Computer.h"
JNIEXPORT void JNICALL Java_com_xiaowei_ndkcpp_NDKCppInterface_executeCppClass(JNIEnv *env, jobject jobj){
//    Computer computer;
//    computer.setCPU("Intel");
//    computer.setDisplay("Gerfoce");
//    computer.setName("MacBook Pro 2019款");
//    computer.setAge(6);
//    computer.setMemory(2);
    //也可以new
    Computer* computer = new Computer();
    computer->setCPU("Intel");
    computer->setDisplay("Gerfoce");
    computer->setName("MacBook Pro 2019款");
    computer->setAge(6);
    computer->setMemory(2);
    __android_log_print(ANDROID_LOG_INFO, "main", "computer display：%s",computer->getDisplay());
};
}