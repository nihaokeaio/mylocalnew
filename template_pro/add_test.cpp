#include<iostream>
using namespace std;
template <typename T>T add(T a,T b){
    return a+b;
}

float arr[1024]={0.4,1.1,2.5};
template <typename T>T getvalue(int i){
    return static_cast<T>(arr[i]);
}

template <typename DstT,typename SrcT >DstT c_style_cast(SrcT v){
    return static_cast<DstT>(v);
}

template <typename T,int Size>struct Array
{
    /* data */
    T  data[Size];
    //Array<int,16>arr;int 替换T，16替换Size,整型往往作为常量使用
};
/*
template <int i>class A{};
void foo(){
    int x=3;
    A<5>a;//true;
    //A<x>b;//error,编译阶段无法确定x，无法作为模板参数（编译阶段确定）出现。
}
*/
/*-----------------------------------------------------*/
//下面内容稍微复杂些
template <int i>class A
{//整型模板类参数
    public:
        void foo(int){}
};

//uint8_t,bool，指针函数都可以算是整型，因此都可作为模板参数
template <uint8_t a,typename b,void *c>class B {};
template <bool,void (*a)()>class C {};//整了一个指针函数作为模板参数
template <void (A<3>::*a)(int)> class D{};//整吐了，这个成员函数的指针

template <int i>int Add(int x){
    return i+x;
}

void foo(){
    A<5> a;
    B<6,A<3>,nullptr>b;
    C<false,&foo>c;
    D<&A<3>::foo>d;
    int x=Add<3>(6);
}

//template <float i>class E{};//哒咩


























int main(){
    float a=1.2;
    char b='c';
    
    float c=getvalue<float>(0);
    int d=getvalue<int>(1);//返回值不能作为推导依据
    //cout<<c<<"\t"<<d<<endl;

    float v=0.2;
    int i=c_style_cast<int>(v);//（匹配顺序）匹配时优先考虑指定的类型，然后自动推导，DstT吃掉了int，SrcT由v自动推导，反之则不行
    cout<<i<<"\t"<<v<<endl;
    system("pause");
}