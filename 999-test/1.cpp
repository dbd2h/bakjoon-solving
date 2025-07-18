#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 300000
#define LL long long
#define INF 1e9

using namespace std;
string A, T;
deque<char> DQ_Front;
deque<char> DQ_Back;
int Left_Point, Right_Point;
string answer;

int main() {
	FIRST
	cin >> A;
	cin >> T;
	Left_Point = 0;
	Right_Point = (T.size() - 1);
	
	while (Left_Point <= Right_Point) { // 문자열의 앞 포인터가 뒤 포인터를 넘어가면 끝
		while (Left_Point <= Right_Point) {
			DQ_Front.push_back(T[Left_Point++]);
			if (DQ_Front.size() >= A.size()) {
				bool Flag = true;
				int IDX = DQ_Front.size() - 1;
				for (int i = (A.size() - 1); i >= 0; i--) {
					if (A[i] != DQ_Front[IDX]) {
						Flag = false;
						break;
					}
					IDX--;
				}
				if (Flag) {
					for (int i = 0; i < A.size(); i++) {
						DQ_Front.pop_back();
					}
					break;
				}
			}
		};
    cout<<Left_Point<<" "<<Right_Point<<"\n";
		while (Left_Point <= Right_Point) {
			DQ_Back.push_front(T[Right_Point--]);
			if (DQ_Back.size() >= A.size()) {
				bool Flag = true;
				int IDX = 0;
				for (int i = 0; i < A.size(); i++) {
					if (A[i] != DQ_Back[IDX]) {
						Flag = false;
						break;
					}
					IDX++;
				}
				if (Flag) {
					for (int i = 0; i < A.size(); i++) {
						DQ_Back.pop_front();
					}
					break;
				}
			}
		};
    cout<<Left_Point<<" "<<Right_Point<<"\n";
	};
	for (int i = 0; i < DQ_Front.size(); i++) {
		answer.push_back(DQ_Front[i]);
	}
	for (int i = 0; i < DQ_Back.size(); i++) {
		answer.push_back(DQ_Back[i]);
	}
  cout<<answer<<"\n";
	while (answer.find(A) < MAX) {
		answer.erase(answer.find(A), A.size());
	};
	if (!answer.empty()) {
		cout << answer;
	}

	return 0;
}