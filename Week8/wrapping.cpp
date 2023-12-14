/*
  BEGIN-HEADER
  
  Name: Mohammad Shahriar Hossain
  Student-ID: 1724709

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.geeksforgeeks.org/convex-hull-using-graham-scan/
  https://algorithmist.com/wiki/Monotone_chain_convex_hull
  https://eclass.srv.ualberta.ca/pluginfile.php/10032854/mod_resource/content/5/08-geometry.pdf
  
  Determined the space efficiency of boards in a mould. rotated and translated the corners of each board to construct a convex hull. Then calculated the area of this hull and compared it to the sum of the boards' areas to output the space utilization as a percentage

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

struct Point {
    double x, y;
    bool operator<(const Point& other) const {
        return x < other.x || (abs(x-other.x) < 0.000000001 && y < other.y);
    }
};
double cross(const Point &origin, const Point &pointA, const Point &pointB) {
    return (pointA.x-origin.x)*(pointB.y-origin.y)-(pointA.y-origin.y)*(pointB.x-origin.x);
}
vector<Point> convexH(vector<Point> points) {
    int n = points.size(), k = 0;
    vector<Point> hull(n*2);
    sort(points.begin(), points.end());
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k-2], hull[k-1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }
    for (int i = n-1, t = k+1; i >= 0; --i) {
        while (k >= t && cross(hull[k-2], hull[k-1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }
    hull.resize(k-1);
    return hull;
}
Point rotate(const Point &point, double angle) {
    return {point.x*cos(angle)-point.y*sin(angle), point.x*sin(angle)+point.y*cos(angle)};
}
double polygon(const vector<Point> &vertices) {
    double area = 0.0;
    for (int i = 0; i < vertices.size(); i++) {
        int j = (i + 1) % vertices.size();
        area += vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y;
    }
    return abs(area) / 2.0;
}
int main() {
    int t;
    double x, y, w, h, v;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<Point> cornerAll;
        double areaTotal = 0.0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> w >> h >> v;
            double a = -(v)*3.1416/180.0;
            vector<Point> corner(4);
            corner[0] = rotate({-w/2, h/2}, a);
            corner[1] = rotate({w/2, h/2}, a);
            corner[2] = rotate({w/2, -h/2}, a);
            corner[3] = rotate({-w/2, -h/2}, a);
            for (const Point &cornerP : corner) {
                cornerAll.push_back({cornerP.x+x, cornerP.y+y});
            }
            areaTotal += h*w;
        }
        vector<Point> hull = convexH(cornerAll);
        double hullArea = polygon(hull);
        cout << fixed << setprecision(1) << (areaTotal/hullArea) * 100.0 << " %" << endl;
    }
    return 0;
}