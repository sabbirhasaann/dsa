#include <bits/stdc++.h>
using namespace std;

// Structure to represent a point
struct Point
{
    double x, y;

    // Operator to check equality of two points
    bool operator==(const Point &t) const
    {
        return x == t.x && y == t.y;
    }
};

// Function to find orientation of the triplet (a, b, c)
// Returns -1 if clockwise, 1 if counter-clockwise, 0 if collinear
int orientation(Point a, Point b, Point c)
{
    double v = a.x * (b.y - c.y) +
               b.x * (c.y - a.y) +
               c.x * (a.y - b.y);
    if (v < 0)
        return -1;
    if (v > 0)
        return +1;
    return 0;
}

// Function to calculate the squared distance between two points
double distSq(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) +
           (a.y - b.y) * (a.y - b.y);
}

// Function to find the convex hull of a set of 2D points
vector<vector<int>> findConvexHull(vector<vector<int>> points)
{

    // Store number of points points
    int n = points.size();

    // Convex hull is not possible if there are fewer than 3 points
    if (n < 3)
        return {{-1}};

    // Convert points 2D vector into vector of Point structures
    vector<Point> a;
    for (auto &p : points)
    {
        a.push_back({(double)p[0], (double)p[1]});
    }

    // Find the point with the lowest y-coordinate (and leftmost in case of tie)
    Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b)
                            { return make_pair(a.y, a.x) < make_pair(b.y, b.x); });

    // Sort points based on polar angle with respect to the reference point p0
    sort(a.begin(), a.end(), [&p0](const Point &a, const Point &b)
         {
        int o = orientation(p0, a, b);

        // If points are collinear, keep the farthest one last
        if (o == 0) {
            return distSq(p0, a) < distSq(p0, b);
        }

        // Otherwise, sort by counter-clockwise order
        return o < 0; });

    // Vector to store the points on the convex hull
    vector<Point> st;

    // Process each point to build the hull
    for (int i = 0; i < (int)a.size(); ++i)
    {

        // While last two points and current point make a non-left turn, remove the middle one
        while (st.size() > 1 && orientation(st[st.size() - 2], st.back(), a[i]) >= 0)
            st.pop_back();

        // Add the current point to the hull
        st.push_back(a[i]);
    }

    // If fewer than 3 points in the final hull, return {-1}
    if (st.size() < 3)
        return {{-1}};

    // Convert the final hull into a vector of vectors of integers
    vector<vector<int>> result;
    for (auto &p : st)
    {
        result.push_back({(int)p.x, (int)p.y});
    }

    return result;
}

int main()
{

    // Define the points set of 2D points
    vector<vector<int>> points = {
        {0, 0}, {1, -4}, {-1, -5}, {-5, -3}, {-3, -1}, {-1, -3}, {-2, -2}, {-1, -1}, {-2, -1}, {-1, 1}};

    // Call the function to compute the convex hull
    vector<vector<int>> hull = findConvexHull(points);

    // If hull contains only {-1}, print the error result
    if (hull.size() == 1 && hull[0].size() == 1)
    {
        cout << hull[0][0] << " ";
    }
    else
    {

        // Print each point on the convex hull
        for (auto &point : hull)
        {
            cout << point[0] << ", " << point[1] << "\n";
        }
    }

    return 0;
}