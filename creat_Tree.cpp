//编写几种树的构建，前中、后中，层中、扩展前、扩展后 递归写法
//by:层次遍历
// #include <iostream>
// #include <vector>
// #include<queue>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x):val(x),left(nullptr),right(nullptr){}
		};

struct CreatTree{
	
		struct TreeNode{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x):val(x),left(nullptr),right(nullptr){}
		};
		TreeNode* root;
		int index;
		CreatTree():root(nullptr),index(0){};
		
	//前序和中序构建树	
	TreeNode* creatTree_pre_in(vector<int >&pre_nums,vector<int>&in_nums){
		if(!pre_nums.size())return nullptr;

		int index=findindex(pre_nums[0],in_nums);
		
		vector<int>::const_iterator p_first=pre_nums.begin()+1;
		vector<int>::const_iterator p_last=pre_nums.begin()+index+1;
		vector<int>::const_iterator p_end=pre_nums.end();
		
		vector<int>::const_iterator i_first=in_nums.begin();
		vector<int>::const_iterator i_last=in_nums.begin()+index;
		vector<int>::const_iterator i_end=in_nums.end();
		//切割成两个小数组
		vector<int>pre_nums_left(p_first,p_last);
		vector<int>pre_nums_right(p_last,p_end);
		
		vector<int>in_nums_left(i_first,i_last);
		vector<int>in_nums_right(i_last+1,i_end);
		
		TreeNode* temp=new TreeNode();
		temp->val=pre_nums[0];
		temp->left=creatTree_pre_in(pre_nums_left,in_nums_left);
		temp->right=creatTree_pre_in(pre_nums_right,in_nums_right);
		return temp;
	}
	//后续与中序构建树
	TreeNode* creatTree_post_in(vector<int >&post_nums,vector<int>&in_nums){
		if(!post_nums.size())return nullptr;

		int index=findindex(post_nums[post_nums.size()-1],in_nums);
		
		vector<int>::const_iterator p_first=post_nums.begin();
		vector<int>::const_iterator p_last=post_nums.begin()+index;
		vector<int>::const_iterator p_end=post_nums.end();
		
		vector<int>::const_iterator i_first=in_nums.begin();
		vector<int>::const_iterator i_last=in_nums.begin()+index;
		vector<int>::const_iterator i_end=in_nums.end();
		//切割成两个小数组
		vector<int>post_nums_left(p_first,p_last);
		vector<int>post_nums_right(p_last,p_end-1);
				
		vector<int>in_nums_left(i_first,i_last);
		vector<int>in_nums_right(i_last+1,i_end);
		
		//开始递归构建树
		TreeNode* temp=new TreeNode();
		temp->val=post_nums[post_nums.size()-1];
		temp->left=creatTree_post_in(post_nums_left,in_nums_left);
		temp->right=creatTree_post_in(post_nums_right,in_nums_right);
		return temp;
	}
	//层序和中序构建树
	TreeNode* creatTree_by_in(vector<int >&by_nums,vector<int>&in_nums){
		if(!by_nums.size())return nullptr;

		int index=findindex(by_nums[0],in_nums);
				
		vector<int>::const_iterator i_first=in_nums.begin();
		vector<int>::const_iterator i_last=in_nums.begin()+index;
		vector<int>::const_iterator i_end=in_nums.end();
		//切割成两个小数组			
		vector<int>in_nums_left(i_first,i_last);
		vector<int>in_nums_right(i_last+1,i_end);
		
		vector<int>by_nums_left;
		vector<int>by_nums_right;
		//cout<<in_nums_left.size()<<endl;
		for(int i=0;i<by_nums.size();i++){
			if(findindex(by_nums[i],in_nums_left)!=-1)by_nums_left.push_back(by_nums[i]);
			if(findindex(by_nums[i],in_nums_right)!=-1)by_nums_right.push_back(by_nums[i]);
		}
		
		//开始递归构建树
		TreeNode* temp=new TreeNode();
		temp->val=by_nums[0];
		temp->left=creatTree_by_in(by_nums_left,in_nums_left);
		temp->right=creatTree_by_in(by_nums_right,in_nums_right);
		return temp;
	}
	//扩展节点构建树,-1代表空节点
	TreeNode* creatTree_expand(vector<int >&nums){
		if(nums[index]==-1){
			index++;
			return nullptr;			
		}
		TreeNode* temp=new TreeNode();
		temp->val=nums[index];
		index++;
		temp->left=creatTree_expand(nums);
		temp->right=creatTree_expand(nums);
		return temp;		
	}
	int findindex(int target,vector<int>&nums);
	void getTree(vector<int >&pre_nums,vector<int>&in_nums){
		root=creatTree_pre_in(pre_nums,in_nums);
		postTreeNode(root);
	}
	void preorderTreeNode(TreeNode* root){
		if(!root) return;
		std::cout<<root->val<<"\t";
		preorderTreeNode(root->left);
		preorderTreeNode(root->right);
	}
	
	void inTreeNode(TreeNode* root){
		if(!root) return;		
		inTreeNode(root->left);
		std::cout<<root->val<<"\t";
		inTreeNode(root->right);
	}
	void postTreeNode(TreeNode* root){
		if(!root) return;		
		postTreeNode(root->left);		
		postTreeNode(root->right);
		std::cout<<root->val<<"\t";
	}
	void by_TreeNode(TreeNode* root){
		if(!root)return;
		queue<TreeNode*>qt;
		qt.push(root);
		while(!qt.empty()){
			int n=qt.size();
			for(int i=0;i<n;i++){
				TreeNode* root=qt.front();
				cout<<root->val<<"\t";
				qt.pop();
				if(root->left)qt.push(root->left);
				if(root->right)qt.push(root->right);
			}
		}
		cout<<endl;
	}
	
	~CreatTree(){
		delete root;
	}
};

int CreatTree::findindex(int target,vector<int>&nums){
	for(int i=0;i<nums.size();i++){
		if (nums[i]==target)return i;
	}
	return -1;
}

int main(){
	vector<int>preorder = {1,2,4,7,3,5,6,8};
	vector<int>midorder = {4,7,2,1,5,3,8,6};
	vector<int>postorder = {7,4,2,5,8,6,3,1};
	vector<int>byorder = {1,2,3,4,5,6,7,8};
	vector<int>in_expand = {1, 2, 4, -1, 7, -1, -1, -1, 3, 5, -1, -1, 6, 8, -1, -1, -1};//中序数组
	CreatTree tree;
	tree.root=tree.creatTree_expand(in_expand);
	//tree.pre_inTreeNode();
	tree.by_TreeNode(tree.root);
	//tree.pre_inTreeNode(tree.root);
	//delete root;
	system("pause");
}
