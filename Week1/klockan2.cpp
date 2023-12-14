/*
  BEGIN-HEADER

  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  Emailed my TA (Akif Chowdhury) and he clarified the problem for me.

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

int main()
{
    double angle, mins, hours;
    cin >> angle;
    int i;
    for (i = 0; i <= 720; i++)
    {
        if (fmod(i*6-i*0.5,360) == double(angle)/10)
        {
            break;
        }
    }
    mins = fmod(i, 60);
    hours = i/60;
    cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << mins << endl;
    return 0;
}