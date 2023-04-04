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

// ���ں�������ֵ

// ����һ������
const int func1() {
    int a = 2;
    return a;
}

// ����һ��ָ������ָ�������ʹ�� const int* p = func2();
const int* func2() {
    // ���涨���a��һ���ֲ�����������������󣬾ֲ��������ڵ��ڴ潫�ᱻ�ͷ�
    // �����Ҫ��ò����ͷŵĶ���Ӧ�÷���һ��ָ��static������ָ��
    // ����ͨ���ѷ����ڴ���������̬������new int(222);
    // int a = 3; 
    int* b = new int(3);
    return b;
}

// ����һ��ָ������ĳ�ָ�룬ʹ�� int* const p = func3();
int* const func3() {
    static int c = 4;
    return &c;
}

int main() {
    // ���ڱ���
    char str[] = "string";
    char* p1 = str;
    const char* p2 = str;  // ָ�����
                           // const ���ε��� char����ָ��ָ�������Ϊchar�Ķ���
                           // ָ��Ķ�����ͨ����ָ����иı䣬ָ����Ը���ָ��Ķ���
                           // p2[0] = 'a'; ָ��ָ���������ܶ�ָ��Ķ�����и���
    cout << "const char* p2 = " << p2 << endl;
    p2 = "123";  // �ܹ�����ָ��Ķ���
    cout << "const char* p2 = " << p2 << endl;
    char* const p3 = str;  // ����ָ��
                           // const���ε���p3��p3�������� char*
                           // ���ܶ�ָ����и�ֵ��ֻ�ܹ�ָ��Ψһ���󣬲���ָ�����������ܹ��ı�ָ������ֵ
                           // p3 = "123"; ����
    cout << "char* const p3 = " << p3 << endl;
    p3[0] = 'a';  // ָ���ǳ���������ָ��������ǿ��Ըı��
    cout << "char* const p3 = " << p3 << endl;

    const char* const p4 = str;  // ָ������ָ��
                                 // ��һ��const���ε�char���ڶ���const���ε���p4
                                 // p4Ϊ����ָ�룬ָ��Ķ�����ͨ��ָ����и��ģ�
    cout << "const char* const p4 = " << p4 << endl;

    // ���ڶ�����
    ClassA ca;
    const ClassA cb;         // ��������ֻ�ܵ��ó�����Ա����
    const ClassA* cc = &ca;  // ָ�������ָ��Ķ�����ͨ����ָ��ı�
    const ClassA& cd = ca;   // �����ã����õĶ�����ͨ�������ý��иı�

    auto v1 = func1(); // ���ص��Ƕ���ı�����ֵ
    cout << v1 << endl;
    auto v2 = func2();
    cout << *v2 << endl;
    delete(v2);
    auto v3 = func3();
    cout << *v3 << endl;
    return 0;
}