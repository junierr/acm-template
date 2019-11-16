#include<bits/stdc++.h>
using namespace std;
 
#define MAX 10      //����Ů�����ΪMAX�� 
 
int main() {
	int man_num, woman_num;    //����Ů���ĸ�������Ҫ���� 
	int ManPref[MAX][MAX], WomanPref[MAX][MAX];     //ϲ�����У���Ҫ���루�����ֱ�ʾ����Ů���� 
	int ManInverse[MAX][MAX], WomanInverse[MAX][MAX]; 
	int wife[MAX], husband[MAX];    //��ʾ������� 
	int count[MAX];    // count[m]��ʾm������Ĵ��� 
	queue<int> FreeMen;   // ��ʾδ����Ե����� 
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
	//��ʼ��ÿ��������Ů����״̬������ÿ������������Ĵ�����ֵ��0 
	for (int i = 0; i < man_num; i++) {
		wife[i] = -1;
		husband[i] = -1;
		count[i] = 0;
	}
	// ��FreeMen�Ķ���Ϊ��ʱ����ѭ�� 
	while(FreeMen.size() != 0) {
		// ȡ�������еĵ�һ��������man�������������� 
		int man = FreeMen.front();
		// ���������Լ���ϲ�����н����Ů��������ֱ����������� 
		for (int i = count[man]; i < woman_num; count[man]++, i++) {
			// ������Ů��δ����� 
			if (wife[ManPref[man][i]] == -1) {
				wife[ManPref[man][i]] = man;
				husband[man] = ManPref[man][i];   //������Ů����� 
				FreeMen.pop();   // ���������Ӷ���ɾ�� 
				break;
			}
			// ���Ů����֮�����������ϲ��������� 
			else if (WomanInverse[ManPref[man][i]][man] 
                        < WomanInverse[ManPref[man][i]][wife[ManPref[man][i]]]) {
				FreeMen.push(wife[ManPref[man][i]]);   //��ԭ�����������δ����������� 
				husband[wife[ManPref[man][i]]] = -1;   //��������״̬���ó�δ��ԣ�Ҳ���Բ������ã� 
				wife[ManPref[man][i]] = man;
				husband[man] = ManPref[man][i];       //������� 
				FreeMen.pop();  // ���������Ӷ���ɾ��  
				break;
			}
			// ����Ů���ܾ���������� 
			else {
			}
		}
	}
	for (int i = 0; i < man_num; i++) {
		cout << "man" << i << " match woman" << husband[i] << endl;
	}
}

