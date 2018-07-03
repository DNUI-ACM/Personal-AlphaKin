#include <iostream>
#include <cstdio>
#include "jvector.h"
using namespace std;

int main(){
	//freopen("out", "w", stdout);

	jj::jvector<int> va;

	va.push_back(2);
	va.push_back(3);
	va.push_back(4);
	va.push_back(5);
	va.push_back(1);
	va.push_back(6);
	va.resize(2, 2);//重新分配
	va.push_back(100);


	jj::jvector<int> vb(va);//拷贝构造
	vb.push_back(77);
	vb.resize(10, 5);//重新分配
	vb.push_back(66);
	vb.erase(5);//删除第5个元素

	jj::jvector<int> vc(5, 3);


	cout << "下标遍历va:" << endl;
	for(int i=0; i<va.size(); ++i)
		cout << va[i] << ' ';
	cout << endl << endl;
	cout << "下标遍历vb:" << endl;
	for(int i=0; i<vb.size(); ++i)
		cout << vb[i] << ' ';
	cout << endl << endl;

	cout << "迭代器遍历va:" << endl;
	jj::jvector<int>::iterator p;//迭代器
	cout << "reserve:" << ' ';
	for(p=va.begin(); p!=va.end(); ++p)
		cout << *(p) << ' ';
	cout << endl << "space:   " << va.size() << '/' <<  va.capacity() << endl;

cout << endl;

	cout << "迭代器遍历vb:" << endl;
	jj::jvector<int>::iterator ps;
	cout << "reserve:" << ' ';
	for(ps=vb.begin(); ps!=vb.end(); ++ps)
		cout << *(ps) << ' ';
	cout << endl << "space:   " << vb.size() << '/' <<  vb.capacity() << endl;

	cout << endl << "---调用swap():---" << endl << endl;
	va.swap(vb);

	cout << "迭代'倒'遍历va:" << endl;

	cout << "reserve:" << ' ';
	for(p=va.end()-1; p!=va.begin(); --p)
		cout << *(p) << ' ';
	cout << *(p);
	cout << endl << "space:   " << va.size() << '/' <<  va.capacity() << endl;

cout << endl;

	cout << "迭代器遍历vb:" << endl;
	cout << "reserve:" << ' ';
	for(ps=vb.begin(); ps!=vb.end(); ++ps)
		cout << *(ps) << ' ';
	cout << endl << "space:   " << vb.size() << '/' <<  vb.capacity() << endl;

cout << endl;

	
	jj::jvector<int>::reverse_iterator rp;//反向迭代器
	cout << "反向迭代器遍历va:" << endl;
	cout << "reserve:" << ' ';
	for(rp=va.rbegin(); rp!=va.rend(); ++rp)
		cout << *(rp) << ' ';
	cout << endl << "space:   " << va.size() << '/' <<  va.capacity() << endl;

cout << endl;

	
	cout << "反向迭代器'倒'遍历vb:" << endl;
	cout << "reserve:" << ' ';
	for(rp=va.rend()+1; rp!=va.rbegin(); --rp)
		cout << *(rp) << ' ';
	cout << *(rp);
	cout << endl << "space:   " << va.size() << '/' <<  va.capacity() << endl;

cout << endl;
	
	cout << "迭代器遍历vc:" << endl;
	cout << "reserve:" << ' ';
	for(ps=vc.begin(); ps!=vc.end(); ++ps)
		cout << *(ps) << ' ';
	cout << endl << "space:   " << vb.size() << '/' <<  vb.capacity() << endl;

cout << endl;

	jj::jvector<int>::iterator p1 = va.end();
	jj::jvector<int>::iterator p2 = va.begin() + va.size();
	cout << "令:p1 = va.end();\n   p2 = va.begin + va.size();" << endl;
	puts(p1 == p2 ? "则p1 == p2" : "则p1 != p2");

cout << endl;

	cout << "va[p1-1] = " << *(p1-1) << endl;
}

/*

下标遍历va:
2 3 100 

下标遍历vb:
2 3 100 77 5 5 5 5 5 66 

迭代器遍历va:
reserve: 2 3 100 
space:   3/4

迭代器遍历vb:
reserve: 2 3 100 77 5 5 5 5 5 66 
space:   10/20

---调用swap():---

迭代'倒'遍历va:
reserve: 66 5 5 5 5 5 77 100 3 2
space:   10/20

迭代器遍历vb:
reserve: 2 3 100 
space:   3/4

反向迭代器遍历va:
reserve: 66 5 5 5 5 5 77 100 3 2 
space:   10/20

反向迭代器'倒'遍历vb:
reserve: 2 3 100 77 5 5 5 5 5 66
space:   10/20

迭代器遍历vc:
reserve: 3 3 3 3 3 
space:   3/4

令:p1 = va.end();
   p2 = va.begin + va.size();
则p1 == p2

va[p1-1] = 66

*/
