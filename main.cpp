#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
struct checkpoint
{
    int x;
    int y;
    int dx;
};

vector<checkpoint> checkpointList;
int maxDistance = 0;
bool bBoost = false;

int GetDistFromCheckpointList(int x, int y)
{
    for (int idx = 0; idx < checkpointList.size(); idx++)
    {
        if ((checkpointList[idx].x == x) && (checkpointList[idx].y == y))
        {
            return checkpointList[idx].dx;
        }
    }

    return 0;
}

int AddCheckpointToList(int x, int y)
{
    for (int idx = 0; idx < checkpointList.size(); idx++)
    {
        if ((checkpointList[idx].x == x) && (checkpointList[idx].y == y))
        {
            return idx;
        }
    }

    checkpoint cp;
    cp.x = x;
    cp.y = y;

    if (checkpointList.size() > 0)
    {
        int jdx = checkpointList.size() - 1;
        //no need for sqrt
        cp.dx = (checkpointList[jdx].x - x)*(checkpointList[jdx].x - x) + (checkpointList[jdx].y - y)*(checkpointList[jdx].y - y);

        if (maxDistance < cp.dx)
        {
            maxDistance = cp.dx;
        }
    }

    checkpointList.push_back(cp);

    return -1;
}



int main()
{
    // game loop
    while (1) {
        int x;
        int y;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; cin.ignore();
        int opponentX;
        int opponentY;
        cin >> opponentX >> opponentY; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        

        // You have to output the target position
        // followed by the power (0 <= thrust <= 100)
        // i.e.: "x y thrust"
        int thrust;
        int dist = 0;

        int index = AddCheckpointToList(nextCheckpointX, nextCheckpointY);
        if (index >= 0)
        {
            bBoost = true;
            dist = checkpointList[index].dx;
        }

        cerr << "checkpoint: " << x << " " << y << " " << nextCheckpointX << " " << nextCheckpointY << " angle: " << nextCheckpointAngle << " maxdist: " << maxDistance << " nextDist: " << dist << endl;
        cerr << "next checkpoint dist: " << nextCheckpointDist << endl;

        if ((nextCheckpointAngle > 90) || (nextCheckpointAngle < -90))
            thrust = 0;
        else
        {
            if (nextCheckpointDist < 1500)
                thrust = 70;
            else if (nextCheckpointDist < 1000)
                thrust = 50;
            else if (nextCheckpointDist < 700)
                thrust = 30;
            else thrust = 100;
        }

        cerr << "bBoost: " << bBoost << " | angle: " << nextCheckpointAngle << " | dist: " << dist << nextCheckpointDist << endl;
        if  ((bBoost) && (nextCheckpointAngle == 0) && (dist == maxDistance))
        {
            bBoost = false;
            cout << nextCheckpointX << " " << nextCheckpointY << " BOOST" << endl;
        }
        else
            cout << nextCheckpointX << " " << nextCheckpointY << " " << thrust << endl;
    }
}