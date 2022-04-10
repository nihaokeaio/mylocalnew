//分离链接法解决哈希碰撞
//当发生哈希值相同时，在哈希值相同的地方创建一个链表（尽可能的短），新值放在链表头
#include<string>
#include<list>
#include<vector>
#include<iostream>
using namespace std;
template <typename hashedObj>
class HashTable{
	public:
		explicit HashTable(int size=101):currentSize(size){}
		
		bool contains(const hashedObj &x)const{
			const list<hashedObj>&whichList=theLists[myhash(x)];
			return find(whichList.begin(),whichList.end(),x)!=whichList.end();
		}
		
		void makeempty(){
			for(int i=0;i<theLists.size();i++)
				theLists[i].clear();
		}
		void insert(const hashedObj& x){
			const list<hashedObj>&whichList=theLists[myhash(x)];
			if(find(whichList.begin(),whichList.end(),x)!=whichList.end())return;
			whichList.push_back(x);
			currentSize++;
			if(currentSize>theLists.size())rehash();
		}
		void remove(const hashedObj& x){
			const list<hashedObj>&whichList=theLists[myhash(x)];
			typename list<hashedObj>::iterator iter=find(whichList.begin(),whichList.end(),x);
			if(iter!=whichList.end()){
				whichList.erase(iter);
				currentSize--;
				std::cout<<"delete obj successful! "<<endl;
			}
			else
				std::cout<<"delete obj fail! "<<endl;
		}
		
	private:
		vector<list<hashedObj>> theLists;//数组链表
		int currentSize;
		
		void rehash();
		int myhash(const hashedObj& x)const{
			int hashVal=hash(x);
			hashVal%=theLists.size();
			if(hashVal<0)hashVal+=theLists.size();
			return hashVal;
		}
};

class Employee{
	public:
		const string& getname()const
		{return name;}
		
		bool operator==(const Employee& rhs)const {
			return rhs.getname()==getname();
		}
		bool operator!=(const Employee& rhs)const{
			return !(rhs==*this);
		}
	private:
		string name;
		double salary;
		int seniority;
};
int hash(const string &key);
int hash(int key);






















