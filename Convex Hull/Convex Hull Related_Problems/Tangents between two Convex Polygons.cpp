#include <bits/stdc++.h>
using namespace std;

// Determines the quadrant of a point relative to origin
int quad(vector<int> p)
{
    if (p[0] >= 0 && p[1] >= 0)
        return 1;
    if (p[0] <= 0 && p[1] >= 0)
        return 2;
    if (p[0] <= 0 && p[1] <= 0)
        return 3;
    return 4;
}

// Returns the orientation of ordered triplet (a, b, c)
// 0 -> Collinear, 1 -> Clockwise, -1 -> Counterclockwise
int orientation(vector<int> a, vector<int> b, vector<int> c)
{
    int res = (b[1] - a[1]) * (c[0] - b[0]) -
              (c[1] - b[1]) * (b[0] - a[0]);
    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}

// Compare function to sort points counter-clockwise around center
bool compare(vector<int> p1, vector<int> q1, vector<int> mid)
{
    vector<int> p = {p1[0] - mid[0], p1[1] - mid[1]};
    vector<int> q = {q1[0] - mid[0], q1[1] - mid[1]};

    int one = quad(p);
    int two = quad(q);

    if (one != two)
        return (one < two);
    return (p[1] * q[0] < q[1] * p[0]);
}

// Sorts the polygon points counter-clockwise
vector<vector<int>> sortPoints(vector<vector<int>> polygon)
{
    vector<int> mid = {0, 0};
    int n = polygon.size();

    // Calculate center (centroid) of the polygon
    for (int i = 0; i < n; i++)
    {
        mid[0] += polygon[i][0];
        mid[1] += polygon[i][1];
        polygon[i][0] *= n;
        polygon[i][1] *= n;
    }

    // Sort points based on their angle from the center
    sort(polygon.begin(), polygon.end(),
         [mid](vector<int> p1, vector<int> p2)
         {
             return compare(p1, p2, mid);
         });

    // Divide back to original coordinates
    for (int i = 0; i < n; i++)
    {
        polygon[i][0] /= n;
        polygon[i][1] /= n;
    }

    return polygon;
}

// Finds the upper tangent between two convex polygons a and b
// Returns two points forming the upper tangent
vector<vector<int>> findUpperTangent(vector<vector<int>> a,
                                     vector<vector<int>> b)
{

    int n1 = a.size(), n2 = b.size();

    // Find the rightmost point of polygon a and leftmost point of polygon b
    int maxa = INT_MIN;
    for (auto &p : a)
        maxa = max(maxa, p[0]);

    int minb = INT_MAX;
    for (auto &p : b)
        minb = min(minb, p[0]);

    // Sort both polygons counter-clockwise
    a = sortPoints(a);
    b = sortPoints(b);

    // Ensure polygon a is to the left of polygon b
    if (minb < maxa)
        swap(a, b);

    n1 = a.size();
    n2 = b.size();

    // Find the rightmost point in a
    int ia = 0, ib = 0;
    for (int i = 1; i < n1; i++)
        if (a[i][0] > a[ia][0])
            ia = i;

    // Find the leftmost point in b
    for (int i = 1; i < n2; i++)
        if (b[i][0] < b[ib][0])
            ib = i;

    // Initialize starting points
    int inda = ia, indb = ib;
    bool done = false;

    // Find upper tangent using orientation checks
    while (!done)
    {
        done = true;
        // Move to next point in a if necessary
        while (orientation(b[indb], a[inda], a[(inda + 1) % n1]) > 0)
            inda = (inda + 1) % n1;

        // Move to previous point in b if necessary
        while (orientation(a[inda], b[indb],
                           b[(n2 + indb - 1) % n2]) < 0)
        {
            indb = (n2 + indb - 1) % n2;
            done = false;
        }
    }

    // Return the points forming the upper tangent
    return {a[inda], b[indb]};
}

// Main driver code
int main()
{
    vector<vector<int>> a = {{2, 2}, {3, 1}, {3, 3}, {5, 2}, {4, 0}};
    vector<vector<int>> b = {{0, 1}, {1, 0}, {0, -2}, {-1, 0}};

    vector<vector<int>> tangent = findUpperTangent(a, b);
    for (auto it : tangent)
    {
        cout << it[0] << " " << it[1] << "\n";
    }
    return 0;
}