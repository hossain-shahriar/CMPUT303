/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  1. learned (n*(n-1))/2 gives you the number of pairs that can be formed from n. source: https://math.stackexchange.com/questions/2214839/exactly-how-does-the-equation-nn-1-2-determine-the-number-of-pairs-of-a-given
  2. Googled how to implement dictionary in C++ and learned how map works in C++

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  I did not discuss this exercise with anyone.

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 303/403.

  END-HEADER
*/


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ll n, d, a, temp, count=0;
	cin >> n >> d;
	map<ll, ll> li;
	for(ll i = 0; i < n; i++) {
		cin >> a;
        temp = a/d;
		li[temp] += 1;
	}
	for(auto i : li) {
		count = count + ((i.second * (i.second-1))/2);
	}
	cout << count << endl;
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int n, d, m, count=0;
//     vector<int> li;
//     cin >> n >> d;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> m;
//         li.push_back(m/d);
//     }
//     for (int i = 0; i < n-1; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if (li[i] == li[j])
//             {
//                 count += 1;
//             }
            
//         }
//     }
//     cout << count << endl;
//     return 0;
// }