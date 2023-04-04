#include <iostream>
#include <string>

class Person {
   private:
   public:
    std::string name;      // 名字
    std::string identity;  // 身份
    Person() : name("person"), identity("no-indentity") {}
    Person(std::string _name) : name(_name), identity("no-identity") {}

    // 虚成员函数
    // 允许使用 基类指针或引用 调用派生类中该重构(override)函数
    // 必须在基类中声明
    virtual void ShowName() {
        std::cout << "[" << identity << "] "
                  << "My name is " << name << std::endl;
    }

    virtual ~Person() {
        std::cout << "base destructor" << std::endl;
    }
};

// 定义一个 father 类
class Father : Person {
   private:
    int id;
    static int childCount;

   public:
    // 重写继承的基类中的virtual函数，可以使用基类的指针或引用调用
    void ShowName() override {
        std::cout << "[" << identity << "] "
                  << "My name is " << name << std::endl;
    }
    // const 还可以对重载函数进行区分
    // 常成员函数，不得修改类中任何数据成员变量
    std::string getName() const {
        return name;
    }

    ~Father() {
        std::cout << "derived destructor of father" << std::endl;
    }
};

// 定义一个 mother 类
class Mohter : Person {
   private:
    int id;
    static int childCount;

   public:
    void ShowName() override {
        std::cout << "[" << identity << "] "
                  << "My name is " << name << std::endl;
    }
};

int main() {
    std::cout << "this is a show class file." << std::endl;

    Father fa1;  // 常对象，只能调用常成员函数

    return 0;
}