#include <iostream>
#include <string>

class Person {
   private:
   public:
    std::string name;      // ����
    std::string identity;  // ���
    Person() : name("person"), identity("no-indentity") {}
    Person(std::string _name) : name(_name), identity("no-identity") {}

    // ���Ա����
    // ����ʹ�� ����ָ������� �����������и��ع�(override)����
    // �����ڻ���������
    virtual void ShowName() {
        std::cout << "[" << identity << "] "
                  << "My name is " << name << std::endl;
    }

    virtual ~Person() {
        std::cout << "base destructor" << std::endl;
    }
};

// ����һ�� father ��
class Father : Person {
   private:
    int id;
    static int childCount;

   public:
    // ��д�̳еĻ����е�virtual����������ʹ�û����ָ������õ���
    void ShowName() override {
        std::cout << "[" << identity << "] "
                  << "My name is " << name << std::endl;
    }
    // const �����Զ����غ�����������
    // ����Ա�����������޸������κ����ݳ�Ա����
    std::string getName() const {
        return name;
    }

    ~Father() {
        std::cout << "derived destructor of father" << std::endl;
    }
};

// ����һ�� mother ��
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

    Father fa1;  // ������ֻ�ܵ��ó���Ա����

    return 0;
}