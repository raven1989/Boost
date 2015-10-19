#include<iostream>
#include<boost/algorithm/string/regex.hpp>
#include<vector>

using namespace std;
using namespace boost;

int main(){
	vector<string> res;
	char c = ':';
	char * sp = &c;
	split_regex(res, "1:2:3:4.5", regex(sp));
	for(vector<string>::const_iterator it=res.begin(); it!=res.end(); ++it)
		cout<<*it<<endl;
	return 0;
}
