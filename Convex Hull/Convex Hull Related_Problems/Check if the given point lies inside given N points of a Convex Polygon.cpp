// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Sorting Function to sort points
bool cmp(pair<int, int> &a,
         pair<int, int> &b)
{

    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

// Function To Check Clockwise
// Orientation
int cw(pair<int, int> &a,
       pair<int, int> &b,
       pair<int, int> &c)
{

    int p = a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);

    return p < 0ll;
}

// Function To Check Counter
// Clockwise Orientation
int ccw(pair<int, int> &a,
        pair<int, int> &b,
        pair<int, int> &c)
{

    int p = a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);

    return p > 0ll;
}

// Graham Scan algorithm to find Convex
// Hull from given points
vector<pair<int, int>> convexHull(
    vector<pair<int, int>> &v)
{
    // Sort the points
    sort(v.begin(),
         v.end(), cmp);

    int n = v.size();
    if (n <= 3)
        return v;

    // Set starting and ending points as
    // left bottom and top right
    pair<int, int> p1 = v[0];
    pair<int, int> p2 = v[n - 1];

    // Vector to store points in
    // upper half and lower half
    vector<pair<int, int>> up, down;

    // Insert StartingEnding Points
    up.push_back(p1);
    down.push_back(p1);

    // Iterate over points
    for (int i = 1; i < n; i++)
    {

        if (i == n - 1 || !ccw(p1, v[i], p2))
        {

            while (up.size() > 1 && ccw(up[up.size() - 2],
                                        up[up.size() - 1],
                                        v[i]))
            {

                // Exclude this point
                // if we can form better

                up.pop_back();
            }

            up.push_back(v[i]);
        }

        if (i == n - 1 || !cw(p1, v[i], p2))
        {

            while (down.size() > 1 && cw(down[down.size() - 2],
                                         down[down.size() - 1],
                                         v[i]))
            {

                // Exclude this point
                // if we can form better
                down.pop_back();
            }
            down.push_back(v[i]);
        }
    }

    // Combine upper and  lower half
    for (int i = down.size() - 2;
         i > 0; i--)
        up.push_back(down[i]);

    // Remove duplicate points
    up.resize(unique(up.begin(),
                     up.end()) -
              up.begin());

    // Return the points on Convex Hull
    return up;
}

// Function to find if point lies inside
// a convex polygon
bool isInside(vector<pair<int, int>> points,
              pair<int, int> query)
{
    // Include the query point in the
    // polygon points
    points.push_back(query);

    // Form a convex hull from the points
    points = convexHull(points);

    // Iterate over the points
    // of convex hull
    for (auto x : points)
    {

        // If the query point lies
        // on the convex hull
        // then it wasn't inside
        if (x == query)
            return false;
    }

    // Otherwise it was Inside
    return true;
}

// Driver Code
int main()
{

    // Points of the polygon
    // given in any order
    int n = 7;
    vector<pair<int, int>> points;

    points = {{1, 1}, {2, 1}, {3, 1}, {4, 1}, {4, 2}, {4, 3}, {4, 4}};

    // Query Points
    pair<int, int> query = {3, 2};

    // Check if its inside
    if (isInside(points, query))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}