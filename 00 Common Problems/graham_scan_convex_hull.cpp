#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void printPoints(vector<pair<int, int>> &points);

int crossProduct(const pair<int, int> &p1, const pair<int, int> &p2, const pair<int, int> &p3)
{
    return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
}

vector<pair<int, int>> convexHull(vector<pair<int, int>> &points)
{
    vector<pair<int, int>> hull;
    for (const auto &p : points)
    {
        while (hull.size() > 1 && crossProduct(hull[hull.size() - 2], hull.back(), p) <= 0)
        {
            hull.pop_back();
        }
        hull.push_back(p);
    }
    return hull;
}

int distSq(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

bool compare(const pair<int, int> &p1, const pair<int, int> &p2, const pair<int, int> &ref)
{
    int dx1 = p1.first - ref.first;
    int dy1 = p1.second - ref.second;
    int dx2 = p2.first - ref.first;
    int dy2 = p2.second - ref.second;
    int cross = dx1 * dy2 - dy1 * dx2;
    if (cross == 0)
        return distSq(ref, p1) < distSq(ref, p2);
    return cross > 0;
}

void sortByAngle(vector<pair<int, int>> &points)
{
    pair<int, int> ref = *min_element(points.begin(), points.end(), [](const pair<int, int> &p1, const pair<int, int> &p2)
                                      { return (p1.second < p2.second) || (p1.second == p2.second && p1.first < p2.first); });
    sort(points.begin(), points.end(), [&](const pair<int, int> &p1, const pair<int, int> &p2)
         { return compare(p1, p2, ref); });
}

pair<int, int> findMinPoint(const vector<pair<int, int>> &points)
{
    pair<int, int> minPoint = {numeric_limits<int>::max(), numeric_limits<int>::max()};
    for (const auto &point : points)
    {
        if (point.second < minPoint.second || (point.second == minPoint.second && point.first < minPoint.first))
        {
            minPoint = point;
        }
    }
    return minPoint;
}

vector<pair<int, int>> generateRandomPoints(int n, int x_min, int x_max, int y_min, int y_max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_x(x_min, x_max);
    uniform_int_distribution<> dis_y(y_min, y_max);
    vector<pair<int, int>> points;
    for (int i = 0; i < n; ++i)
    {
        int x = dis_x(gen);
        int y = dis_y(gen);
        points.emplace_back(x, y);
    }
    return points;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<pair<int, int>> points = generateRandomPoints(n, -10, 10, -10, 10);
    pair<int, int> minP = findMinPoint(points);
    printPoints(points);
    sortByAngle(points);
    cout << "after sorting points are: \n";
    printPoints(points);
    vector<pair<int, int>> hull = convexHull(points);
    cout << "hull: " << endl;
    printPoints(hull);
}
void printPoints(vector<pair<int, int>> &points)
{
    for (const auto &p : points)
        cout << p.first << " " << p.second << endl;
}