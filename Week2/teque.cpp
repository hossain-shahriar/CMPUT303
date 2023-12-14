/*
  BEGIN-HEADER

  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://stackoverflow.com/questions/57960065/what-makes-the-java-linked-list-implementation-of-a-triple-ended-queue-slow
  Learned from the link above that you can use two list (two deque) is the list gets big

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

void equal(deque<ll> &queue1, deque<ll> &queue2)
{
    ll temp;
    ll d = queue1.size()-queue2.size();
    if (d > 1)
    {
        for (ll i = 0; i < floor((double)d/2); i++)
        {
            temp = queue1.back();
            queue1.pop_back();
            queue2.push_front(temp);
        }
    }
    else if (d < 0)
    {
        for (ll i = 0; i < ceil((double)d/-2); i++)
        {
            temp = queue2.front();
            queue2.pop_front();
            queue1.push_back(temp);
        }
    }
}

int main()
{
    ll n, x;
    deque<ll> queue1;
    deque<ll> queue2;
    char input[13];
    cin >> n;
    for (ll i = 0; i < n; i++){
        scanf("%s %lld", input, &x);
        if (input[0] == 'g'){
            if (queue1.size() > x){
                cout << queue1[x] << endl;
            }
            else{
                cout << queue2[x-queue1.size()] << endl;
            }
        }
        else if (input[5] == 'b'){
            queue2.push_back(x);
            equal(queue1, queue2);
        }
        else if (input[5] == 'f'){
            queue1.push_front(x);
            equal(queue1, queue2);
        }
        else if (input[5] == 'm'){
            queue1.push_back(x);
            equal(queue1, queue2);
        }
    }
    return 0;
}