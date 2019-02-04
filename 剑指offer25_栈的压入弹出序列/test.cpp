#include<iostream>
using namespace std;
#include<stack>
#include<vector>



class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int cur_push = 0;
		int cur_pop = 0;
		stack<int> s;
		s.push(pushV[cur_push++]);
		while (cur_push < popV.size() && cur_pop < popV.size()){
			while(!s.empty()&&s.top() != popV[cur_pop] ){
				s.push(pushV[cur_push++]);
			}
			while(!s.empty() && s.top() == popV[cur_pop]){
				s.pop();
				++cur_pop;
			}
		}
		if (!s.empty()){
			return false;
		}
		else{
			return true;
		}
	}
};

void TestFunc(){
	vector<int> array1 = { 1 };
	/*vector<int> array2 = { 4, 5, 3, 2, 1 };*/
	vector<int> array2 = {  1 };
	Solution s;
	cout << s.IsPopOrder(array1, array2) << endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}