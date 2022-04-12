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
    ListNode* head=new ListNode();
	ListNode* endp;
    int currentSize;//the size of List;
public:
    MyListNode(){
        currentSize=0;
    }
    MyListNode(vector<T>&contains){
        creatList(contains.begin(),contains.end());
    }
	template <typename T1>
    MyListNode(T1 iter_begin,T1 iter_end){
        creatList(iter_begin,iter_end);
    }
	//iterator
	template <typename T1>
    void creatList(T1 iter_begin,T1 iter_end){
		currentSize=0;
		ListNode* root=head;
        for(auto iter=iter_begin;iter!=iter_end;iter++){
            ListNode* cur=new ListNode(*iter);
            head->next=cur;
			head=head->next;
			endp=cur;
			currentSize++;
        }
        head=root->next;
		delete root;
    } 
    void orderall(){
        ListNode* cur=head;
        while(cur->next!=nullptr){
            cout<<cur->val<<" -> ";
            cur=cur->next;
        }
        cout<<cur->val<<endl;;
		//cout<<" the size of list is "<<currentSize<<endl;
    }
	void back_insert(T& obj){
		insert(currentSize-1,obj);
	}
	void front_insert(T& obj){
		ListNode* p=new ListNode(obj);
		p->next=head;
		head=p;
		currentSize++;
	}
	void insert(int index,T& obj){
		ListNode* p=new ListNode(obj);
		cout<<"insert obj:"<<obj<<" at: "<<index+1<<endl;
		if(index<currentSize){
			ListNode* cur=head;
			while(cur){
				if(!index--){
					ListNode* temp=cur->next;
					cur->next=p;
					p->next=temp;
					currentSize++;
					break;
				}
				cur=cur->next;
			}
		}
		else{
			
			cout<<"insert fail \n";
		}
	}
	void deleteNode(int begin,int end){
		ListNode* cur=head;
		ListNode* start=cur;
		if(end<begin){
			cout<<"index is error!\n";
			return;
		}
		bool deletehead=(begin==0);
		while(cur&&end>=0){		
			if((end--)>=0&&(--begin)<0){
				ListNode* p=cur;

				cur=cur->next; 
				delete p;
				continue;
			}		
			start=cur;
			cur=cur->next;
		}
		start->next=cur;
		head=deletehead?cur:head;
	}
	
	void deleteNode(T& obj){
		ListNode* first=new ListNode(-1,head);
		ListNode* fast=head,*slow=first;
		while(fast){
			while(fast->val==obj){
				ListNode* p=fast;
				fast=fast->next;
				delete p;
			}
			slow->next=fast;
			slow=slow->next;
			fast=fast->next;		
		}
		head=first->next;
		delete first;
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
    vector<int>arr1={4,6,2,3,8,7,5,6,2,4,2,7};
    MyListNode<int> list1(arr1);
    list1.orderall();
	/* int x=-1,y=-3;
	list1.insert(0,x);
	list1.orderall();
	x=10; */
	int x=4;	
	list1.deleteNode(x);
	/* list1.back_insert(y);
	list1.orderall();
	x=1;
	list1.front_insert(x); */
	list1.orderall();
}



int main(){
    test();
    system("pause");
    return 0;
}