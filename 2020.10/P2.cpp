/*
* Author:		bloodnighttw
* URL:				https://zerojudge.tw/ShowProblem?problemid=f313
* ID:				f313
* Statue:		AC | 4 ms | 64 KB
* Note:			APCS 2020.10.17 P2
*/

#include <bits/stdc++.h>

using namespace std;

#define BOUND -1

int v[53][53];
int give[53][53];
int count_[53][53];

int main(){
		
	int min_ = 100000000,max_ = 0;
	int r,c,k,m;
	cin >> r >> c >> k >> m;
	//cout << "// 0" << endl;
	// set up bound
	for(int i = 0 ; i <= c+1 ; i++ ){
		v[0][i] = BOUND; // v is vector<vector<int>>
		v[r+1][i] = BOUND;
		give[0][i] = 0; // give is vector<vector<int>>
		give[r+1][i] = 0;
	}
	//cout << "// 1" << endl;
	for(int i = 0 ; i <= r+1 ; i++ ){
		v[i][0] = BOUND;
		v[i][c+1] = BOUND;

		give[i][0] = 0;
		give[i][c+1] = 0;
	}

	// count to 0	
	for(int i = 0 ; i <= r ; i++ ){
		for(int j = 0 ; j <= c ; j++ ){
			count_[i][j] = 0;	
		}
	}
	

	// set up bound done
	
	// input
	
	for(int i = 1 ; i <= r ; i++ ){
		for(int j = 1 ; j <= c ; j++ ){
			int temp;
			cin >> temp;
			if(temp == -1)
				give[i][j] = 0;
			else
				give[i][j] = temp / k;
			v[i][j] = temp;
				
		}
	}

	
	for(int i = 0 ; i < m  ; i++ ){

		
		for(int j = 1 ; j <= r ; j++ ){
			
			for(int l = 1 ; l <= c ; l++ ){
				
				if(v[j][l] == BOUND)
					continue;

				if(v[j-1][l] != BOUND){
					v[j][l] += give[j-1][l];
					count_[j-1][l]++;
				}

				if(v[j+1][l] != BOUND){
					v[j][l] += give[j+1][l];
					count_[j+1][l]++;
				}

				if(v[j][l-1] != BOUND){
					v[j][l] += give[j][l-1];
					count_[j][l-1]++;
				}


				if(v[j][l+1] != BOUND){
					v[j][l] += give[j][l+1];
					count_[j][l+1]++;
				}
			
			}
			
		}


		
		min_ = 100000000,max_ = 0;

		for(int j = 1 ; j <= r ; j++ ){
		
			for(int l = 1 ; l <= c ; l++ ){
				int temp = v[j][l] - count_[j][l]*give[j][l];
				v[j][l] = temp;
				count_[j][l] = 0;
				give[j][l] = temp/k;
			
				if(temp != -1 && temp < min_){
					min_ = temp;
				}

				if(max_ < temp){
					max_ = temp;
				}

			}
		
		}
		/*
		cout << "[o]count print" << endl; 
		show(r,c,count_);
		cout << "[o]give" << endl;
		show(r,c,give);
		*/
		
		//show(r,c,v);

	}

	cout << min_ << endl << max_ << endl;

	return 0 ;
}
