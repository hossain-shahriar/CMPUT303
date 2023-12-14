/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://eclass.srv.ualberta.ca/pluginfile.php/10032854/mod_resource/content/5/08-geometry.pdf
  https://www.geeksforgeeks.org/geometry-using-complex-numbers-stdcomplex-in-c/
  https://www.cs.cmu.edu/~15451-f22/lectures/lec21-geometry.pdf

  Solved the problem by calculating the perpendicular distance from cities to the hurricane's path using complex numbers and cross product. The closest city or cities has the highest danger

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
typedef complex<double> point;

double cross(const point& a, const point& b) {
    return imag(conj(a)*b);
}
double distPointLine(const point& a, const point& b, const point& c) {
    return abs(cross(b-a, c-a)) / abs(b-a);
}
int main() {
    int n, m;
    point a, b;
    cin >> n;
    while (n) {
        double ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        a = {ax, ay};
        b = {bx, by};
        cin >> m;
        vector<pair<string, point>> cities(m);
        string name;
        double cx, cy;
        for (int i = 0; i < m; ++i) {
            cin >> name >> cx >> cy;
            cities[i] = {name, point(cx, cy)};
        }
        double minDist = numeric_limits<double>::max();
        vector<string> closest;
        for (const auto& city : cities) {
            double dist = distPointLine(a, b, city.second);
            if (dist < minDist) {
                minDist = dist;
                closest.clear();
                closest.push_back(city.first);
            } else if (dist == minDist) {
                closest.push_back(city.first);
            }
        }
        for (const auto& name : closest) {
            cout << name << " ";
        }
        cout << endl;
        n--;
    }
    return 0;
}
