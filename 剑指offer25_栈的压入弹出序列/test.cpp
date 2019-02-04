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
		while (cur_pop < popV.size()){
			if (!s.empty()&&s.top() != popV[cur_pop] && pushV[cur_push]!= popV[cur_pop]){
				s.push(pushV[cur_push++]);
			}
			else if (!s.empty() && s.top() != popV[cur_pop] && pushV[cur_push] == popV[cur_pop]){
				++cur_pop;
				++cur_push;
			}
			else if (!s.empty() && s.top() == popV[cur_pop]){
				s.pop();
				++cur_pop;
			}
			else{
				return false;
			}
			return true;
		}
	}
};

void TestFunc(){
	vector<int> array1 = { 1, 2, 3, 4, 5 };
	/*vector<int> array2 = { 4, 5, 3, 2, 1 };*/
	vector<int> array2 = { 4, 3, 5, 1, 2 };
	Solution s;
	cout << s.IsPopOrder(array1, array2) << endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}