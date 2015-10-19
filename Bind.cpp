#include<iostream>
#include<boost/bind.hpp>
#include<boost/shared_ptr.hpp>
#include<boost/function.hpp>

using namespace std;

class A{
public:
	void m_fun(int a, int b){
		cout<<a<<","<<b<<endl;
	}
};
void fun(int a, int b){
	cout<<a<<" and "<<b<<endl;
}

int echo(int a){
	return a;
}

int main(){
	boost::bind(&fun,3,4)();
	boost::bind(fun,3,_1)(4);
	boost::bind(fun,_1,4)(3);
	boost::bind(fun,_1,_2)(3,4);
	boost::bind(fun,_2,_1)(3,4);

	int i = 20;
	boost::function<int (void)> fh = boost::bind(&echo,i);
	cout<< fh() << endl;

	A a;
	A* pa = new A;
	boost::shared_ptr<A> spa(new A);
	boost::bind(&A::m_fun,a,5,6)();
	boost::bind(&A::m_fun,pa,5,_1)(6);
	boost::function<void (void)> mf = boost::bind(&A::m_fun,_3,_2,_1);
	mf(5,6,spa);
	return 0;
}
