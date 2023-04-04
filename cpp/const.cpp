#include <iostream>

using namespace std;
class ClassA {
   private:
    int a;

   public:
    ClassA() : a(0) {}
    int getValue() const {
        return a;
    }
};

// 对于函数返回值

// 返回一个常数
const int func1() {
    int a = 2;
    return a;
}

// 返回一个指向常数的指针变量，使用 const int* p = func2();
const int* func2() {
    // 下面定义的a是一个局部变量，函数体结束后，局部变量所在的内存将会被释放
    // 如果想要获得不被释放的对象，应该返回一个指向static变量的指针
    // 或者通过堆分配内存来创建动态对象，如new int(222);
    // int a = 3; 
    int* b = new int(3);
    return b;
}

// 返回一个指向变量的常指针，使用 int* const p = func3();
int* const func3() {
    static int c = 4;
    return &c;
}

int main() {
    // 对于变量
    char str[] = "string";
    char* p1 = str;
    const char* p2 = str;  // 指针变量
                           // const 修饰的是 char，即指针指向的类型为char的对象
                           // 指向的对象不能通过该指针进行改变，指针可以更改指向的对象
                           // p2[0] = 'a'; 指针指向常量，不能对指向的对象进行更改
    cout << "const char* p2 = " << p2 << endl;
    p2 = "123";  // 能够更改指向的对象
    cout << "const char* p2 = " << p2 << endl;
    char* const p3 = str;  // 常量指针
                           // const修饰的是p3，p3的类型是 char*
                           // 不能对指针进行赋值，只能够指向唯一对象，不能指向其他对象，能够改变指向对象的值
                           // p3 = "123"; 错误
    cout << "char* const p3 = " << p3 << endl;
    p3[0] = 'a';  // 指针是常量，但是指向的内容是可以改变的
    cout << "char* const p3 = " << p3 << endl;

    const char* const p4 = str;  // 指向常量的指针
                                 // 第一个const修饰的char，第二个const修饰的是p4
                                 // p4为常量指针，指向的对象不能通过指针进行更改，
    cout << "const char* const p4 = " << p4 << endl;

    // 对于对象类
    ClassA ca;
    const ClassA cb;         // 常量对象，只能调用常量成员函数
    const ClassA* cc = &ca;  // 指针变量，指向的对象不能通过该指针改变
    const ClassA& cd = ca;   // 常引用，引用的对象不能通过该引用进行改变

    auto v1 = func1(); // 返回的是定义的变量的值
    cout << v1 << endl;
    auto v2 = func2();
    cout << *v2 << endl;
    delete(v2);
    auto v3 = func3();
    cout << *v3 << endl;
    return 0;
}