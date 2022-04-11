//链表创建，后向插入，前向插入，删除节点，翻转，排序
#include <iostream>
#include<vector>
using namespace std;
//创建一个单向链表


template<typename T>
class MyListNode
{
private:
    struct ListNode
    {
        T val;
        ListNode * next;
        ListNode():val(0),next(nullptr){}
        ListNode(T x):val(x),next(nullptr){}
        ListNode(T x,ListNode* p):val(x),next(p){}
    };
    ListNode* head;
    int currentSize;//the size of List;
public:
    MyListNode(){
        currentSize=0;
    }
    MyListNode(vector<T>&contains){
        creatList(contains,contains.begin(),contains.end());
    }
    MyListNode(vector<T>&contains,auto iter_begin,auto iter_end){
        creatList(contains,contains.begin(),contains.end());
    }
    void creatList(vector<T>&contains,auto iter_begin,auto iter_end){
        ListNode* cur=head;
        for(auto iter=iter_begin;iter!=iter_end;iter++){
            head=new ListNode(*iter);
            head=head->next;
        }
        head=cur;
    } 
    void orderall(){
        ListNode* cur=head;
        cout<<head<<endl;
        while(cur->next!=nullptr){
            cout<<cur->val<<" -> ";
            cur=cur->next;
        }
        cout<<cur->val<<endl;
    }
    ~MyListNode(){
        while(head){
            ListNode *p=head;
            head=head->next;
            delete p;
        }
    }
};





void test(){
    vector<int>arr1={4,6,2,3,8};
    MyListNode<int> list1(arr1);
    list1.orderall();
}



int main(){
    test();
    system("pause");
    return 0;
}
