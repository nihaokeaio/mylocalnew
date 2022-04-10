//列举散列函数，解决哈希碰撞（书中代码）
#include<string>

//将键值通过哈希函数转换成ASCII码叠加和
//将表设置为素数。当表很大时，无法得到很好的均匀分配
int hash0(const string &key,int tablesize){
	int hashVal=0;
	for(int i=0;i<key.size();i++){
		hashVal+=key[i];
	}
	return hashVal%tablesize;
}

//列举一个比较好的散列函数
int hash(const string &key,int tablesize){
	int hashVal=0;
	for(int i=0;i<key.size();i++){
		hashVal=37*hashVal+key[i];//hashVal=key[0]+37*key[1]+37^2*key[2]+37^3*key[3]....
	}
	//可能会溢出出现负值
	hashVal%=tablesize;
	if(hashVal<0)hashVal+=tablesize;
	
	return hashVal;
}












