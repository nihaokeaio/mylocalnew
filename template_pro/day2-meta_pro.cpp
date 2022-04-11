#include<iostream>

using namespace std;
class BB{};
template <typename T>class TypeID{
    public:
        static int const ID=0;
        void foo(){
        }
};
template <>class TypeID<int>{
    public:
        static int const ID=1;
};
template <>class TypeID<float>{
    public:
        static int const ID=2;
};
/*
template <>class TypeID<int>{
    public:
        static int const ID=-1;
};

template <>class TypeID<float>{
    public:
        static int const ID=-2;
};
template <>class TypeID<void*>{
    public:    
        static int const ID=-3;
};

template <>class TypeID<int[4]>{
    public:    
        static int const ID=-4;
};

template <>class TypeID<bool(int[])>{
    public:    
        static int const ID=-5;
};

template <>class TypeID<int*(void*,float[10])>{
    public:    
        static int const ID=-6;
};
*/
template <typename T>
class TypeID<T*>{//对所有类型指针进行特化
    public:
        typedef T SameAst;
        static int const ID=0;
};

template <typename T>
class Removepoint{
    public:
        typedef T result;
        static int const ID=0;
};

template <typename T>
class Removepoint<T*>{
    public:
        //typedef T result;//剥掉一层指针
        typedef typename Removepoint<T>::result result;
        static int const ID=1;
};
template <>
class Removepoint<int*>{
    public:
        //typedef T result;//剥掉一层指针
        static int const ID=2;
       // WTF INSTAN;
};

struct A;
template <typename T> struct B{};
template <typename T> struct X {
    typedef X<T> TA; // 编译器当然知道 X<T> 是一个类型。
    typedef X    TB; // X 等价于 X<T> 的缩写
    typedef T    TC; // T 不是一个类型还玩毛
    
    // ！！！注意我要变形了！！！
    class Y {
        typedef X<T>     TD;          // X 的内部，既然外部高枕无忧，内部更不用说了
        typedef X<T>::Y  TE;          // 嗯，这里也没问题，编译器知道Y就是当前的类型，
                                      // 这里在VS2015上会有错，需要添加 typename，
                                      // Clang 上顺利通过。
        typedef typename X<T*>::Y TF; // 这个居然要加 typename！
                                      // 因为，X<T*>和X<T>不一样哦，
                                      // 它可能会在实例化的时候被别的偏特化给抢过去实现了。
    };
    
    typedef A TG;                   // 嗯，没问题，A在外面声明啦
    typedef B<T> TH;                // B<T>也是一个类型
    typedef typename B<T>::type TI; // 嗯，因为不知道B<T>::type的信息，
                                    // 所以需要typename
    //typedef B<int>::type TJ;        // B<int> 不依赖模板参数，
                                    // 所以编译器直接就实例化（instantiate）了
                                    // 但是这个时候，B并没有被实现，所以就出错了
};



void foo(){   
    //cout<<TypeID< TypeID<float*>::SameAst >::ID<<endl;//去掉了一个指针
    // Removepoint*的指针处理掉以后的结果：float啦。
    std::cout << Removepoint<int*>::ID << std::endl;//对于三个类都能匹配，但模板匹配遵循从最特殊到最一般的模式匹配
}







int main(){
    // cout<<"hello!"<<endl;
    // int x=10;
    // cout<<x<<endl;
    foo();
    // cout<<x+1<<endl;
    system("pause");
    return 0;
}