#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	n = 5;
	int limit = 1000000;
	queue<int> br; queue<int> nr;

	for (int i = 0; i < n; i++) { int br_v; cin >> br_v; br.push(br_v); }
	for (int i = 0; i < n; i++) { int nr_v; cin >> nr_v; nr.push(nr_v); }
	
	int moves = 0;
	while(!br.empty() && !nr.empty() && moves < limit){
		int br_v, nr_v;
		br_v = br.front(); br.pop();
		nr_v = nr.front(); nr.pop();

		bool br_w;

		if (br_v == 0 && nr_v == 9) br_w = true;
		else if (nr_v == 0 && br_v == 9) br_w = false;
		else br_w = (br_v > nr_v);

		if (br_w) { br.push(br_v); br.push(nr_v);
		} else { nr.push(br_v); nr.push(nr_v); }
		

		moves++;
	}

	if (moves>= limit) {
		cout << "blin nichya";
	} else if (nr.empty()) {
		cout << "Boris " << moves;
	} else {
		cout << "Nursik " << moves;
	}
	
}
