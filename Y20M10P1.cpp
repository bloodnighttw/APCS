/*
* Author:		bloodnighttw
* URL:				https://zerojudge.tw/ShowProblem?problemid=f312
* ID:				f312
* Statue:		AC | 2 ms | 328 KB
* Note:			APCS 2020.10.17 P1 and fuck u 師大 垃圾測資3（是錯的） 害我沒有4 幹
*/
#include <bits/stdc++.h>

using namespace std;

class CaluBuilder{
	
	long a,b,c;
	public:
	CaluBuilder(long a1,long b1,long c1){
			a = a1;
			b = b1;
			c = c1;
	}

	long build(long x){
		return (a*(x*x)+b*(x)+c);
	}

};

int main(){
	long a,b,c,n;
	cin >> a >> b >> c;
	CaluBuilder n1(a,b,c);
	
	cin >> a >> b >> c;
	CaluBuilder n2(a,b,c);
	
	cin >> n;
	long max_ = -1000000000000000; // o.301 * 64 ==19. ..... 10^15 won't overflow in long
	for(long i = 0 ; i <= n ; i++){
		long sum = n1.build(i) + n2.build(n-i);
		if(max_ < sum){
			max_ = sum;
		}
	}

	cout << max_ << endl;

	return 0 ;
}
