#ifndef MYSTRING_H
#define MYSTRING_H
#include <cstring>
#include <iostream>
const int INI_MAX = 0x7fffffff;//2^32
const int INI_MIN = 0x80000000;// -2^32
const int npos = 0xffffffff;// npos
using namespace std;

class MyString
{
public:
    // constructor
    MyString();//
    MyString(const MyString &);//
    MyString(const char *);
    MyString(const size_t,const char);

    // destructor
    ~MyString();

    // attributes

    size_t length();// �ַ�������
    bool isEmpty();// �����ַ����Ƿ�Ϊ��
    const char* c_str();// ����c����trr��ָ��

    // friend funs
    // read writer operations
    friend ostream& operator<< (ostream&, const MyString&);
    friend istream& operator>> (istream&, MyString&);
    //add operation
    friend MyString operator+(const MyString&,const MyString&);
    // compare operations
    friend bool operator==(const MyString&,const MyString&);
    friend bool operator!=(const MyString&,const MyString&);
    friend bool operator<(const MyString&,const MyString&);
    friend bool operator<=(const MyString&,const MyString&);
    friend bool operator>(const MyString&,const MyString&);
    friend bool operator>=(const MyString&,const MyString&);

    // ��Ա����ʵ�����������,��ʵһ����Ҫ�����������ģ���Ա������������ػ��һЩ
    // index operation
    char& operator[](const size_t);
    const char& operator[](const size_t)const;
    // =
    MyString& operator=(const MyString&);
    // +=
    MyString& operator+=(const MyString&);
    // +=
    //MyString operator+=(const MyString&); cannot be overloaded
    // ��Ա��������
    // substr
    MyString substr(size_t pos,const size_t n);
    // append
    MyString& append(const MyString&);
    //insert
    MyString& insert(size_t,const MyString&);
    //assign �滻
//    MyString& assign(MyString&,size_t,size_t);
//    // erase ɾ��
//    MyString& erase(size_t,size_t);
//    //find_first_of ����ĳһ���ַ� size_t �ǷǷ�������,����
//    // �������ַ����е�һ����str�е�ĳ���ַ�ƥ����ַ�����������λ�á�
//    //������index��ʼ�����û�ҵ��ͷ���string::npos
//    int find_first_of(const char* str,size_t index=0);
//    int find_first_of(const char ch,size_t index=0);
//    int find_first_of(const MyString &,size_t index=0);
//    // ���ַ����в��ҵ�һ����str�е��ַ�����ƥ����ַ�����������λ�á�������index��ʼ�����û�ҵ��ͷ���string::nops
//    int find_first_not_of(const char* str,size_t index=0);
//    int find_first_not_of(const char ch,size_t index=0);
//    int find_first_not_of(const MyString&,size_t index=0);
//    // swap
//    void swap(MyString& lhs,MyString& rhs);
//    // replace_all
//    MyString& replace_all(const char oldc,const char newc=NULL);
//    MyString& replace(size_t index,size_t num1,size_t num2,const char ch);
//    //find
//    int find(const char* str,size_t index=0);
//    int find(const MyString& str,size_t index=0);
//    int find(const char ch,size_t index=0);


    //private
private:
    char* cdata;
    size_t clength;
};


#endif // MYSTRING_H
