#include<bits/stdc++.h>
using namespace std;
 
#define MAX 10      //男生女生最多为MAX个 
 
int main() {
	int man_num, woman_num;    //男生女生的个数，需要输入 
	int ManPref[MAX][MAX], WomanPref[MAX][MAX];     //喜欢序列，需要输入（用数字表示男生女生） 
	int ManInverse[MAX][MAX], WomanInverse[MAX][MAX]; 
	int wife[MAX], husband[MAX];    //表示各个配对 
	int count[MAX];    // count[m]表示m提出求婚的次数 
	queue<int> FreeMen;   // 表示未被配对的男生 
	cout << "Please input the number of men or women:" << endl;
	cin >> man_num;
	woman_num = man_num;
	for (int i = 0; i < man_num; i++) {
		cout << "Please input the man" << i << "'s prefer list in order" << endl;
		FreeMen.push(i);
		for (int j = 0; j < woman_num; j++) {
			cin >> ManPref[i][j];
		}
	}
	for (int i = 0; i < woman_num; i++) {
		cout << "Please input the woman" << i << "'s prefer list in order" << endl;
		for (int j = 0; j < man_num; j++) {
			cin >> WomanPref[i][j];
		}
	}
	for (int i = 0; i < man_num; i++) {
		for (int j = 0; j < woman_num; j++) {
			ManInverse[i][ManPref[i][j]] = j;
		}
	}
	for (int i = 0; i < woman_num; i++) {
		for (int j = 0; j < man_num; j++) {
			WomanInverse[i][WomanPref[i][j]] = j;
		}
	}
	//初始化每个男生和女生的状态，并将每个男生提出求婚的次数赋值成0 
	for (int i = 0; i < man_num; i++) {
		wife[i] = -1;
		husband[i] = -1;
		count[i] = 0;
	}
	// 当FreeMen的队列为空时结束循环 
	while(FreeMen.size() != 0) {
		// 取出队列中的第一个男生，man代表该男生的序号 
		int man = FreeMen.front();
		// 男生按照自己的喜欢序列降序对女生提出求婚直到男生被配对 
		for (int i = count[man]; i < woman_num; count[man]++, i++) {
			// 如果这个女生未被配对 
			if (wife[ManPref[man][i]] == -1) {
				wife[ManPref[man][i]] = man;
				husband[man] = ManPref[man][i];   //将男生女生配对 
				FreeMen.pop();   // 将该男生从队列删除 
				break;
			}
			// 如果女生较之已配对男生更喜欢这个男生 
			else if (WomanInverse[ManPref[man][i]][man] 
                        < WomanInverse[ManPref[man][i]][wife[ManPref[man][i]]]) {
				FreeMen.push(wife[ManPref[man][i]]);   //将原配对男生加入未配对男生队列 
				husband[wife[ManPref[man][i]]] = -1;   //将男生的状态设置成未配对（也可以不用设置） 
				wife[ManPref[man][i]] = man;
				husband[man] = ManPref[man][i];       //重新配对 
				FreeMen.pop();  // 将该男生从队列删除  
				break;
			}
			// 否则女生拒绝男生的求婚 
			else {
			}
		}
	}
	for (int i = 0; i < man_num; i++) {
		cout << "man" << i << " match woman" << husband[i] << endl;
	}
}

