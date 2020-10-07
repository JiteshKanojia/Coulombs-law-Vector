// Calculates the force exerted by Q2(point 1) on Q1(point 2)
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#define pi M_PI
#define E0 8.854e-12 // epsilon 0 defines permittivity in free space
using namespace std;
struct Vector // Vector for storing x,y,z
{
    float x; // x co-ordinate
    float y; // y co-ordinate
    float z; // z co-ordinate
};

int main()
{
    float Q1;      // charge at point 1
    float Q2;      // charge at point 2
    Vector Answer; // stores the answer vector
    Vector pos1;   // stores position 1 of charge
    Vector pos2;   // stores position 2 of charge
    Vector r12;    //stores the distance between the charges

    cout << "Enter Q1 (charge at point 1) and Q2 (Charge at point 2)" << endl;
    cin >> Q1 >> Q2;

    cout << "Enter the values of Co-ordinate (x,y,z) at first point." << endl;
    cin >> pos1.x >> pos1.y >> pos1.z;

    cout << "Enter the values of Co-ordinate (x,y,z) at second point." << endl;
    cin >> pos2.x >> pos2.y >> pos2.z;

    r12.x = pos2.x - pos1.x; // calculates x co-ordinate of distance
    r12.y = pos2.y - pos1.y; // calculates y co-ordinate of distance
    r12.z = pos2.z - pos1.z; // calculates z co-ordinate of distance

    int r12_mod = sqrt((r12.x * r12.x) + (r12.y * r12.y) + (r12.z * r12.z)); //identifies as |R12|

    r12.x = r12.x / r12_mod; //
    r12.y = r12.y / r12_mod; //calculates a12
    r12.z = r12.z / r12_mod; //

    //store the multiple which is then multiplied with each vector co-ordinate
    float multiple = ((Q1 * Q2) / (4 * pi * E0 * r12_mod * r12_mod));

    Answer.x = multiple * r12.x; // multiply the multiple with x co-ordinate of distance vector
    Answer.y = multiple * r12.y; // multiply the multiple with y co-ordinate of distance vector
    Answer.z = multiple * r12.z; // multiply the multiple with z co-ordinate of distance vector

    cout << "   Force of Q2 on Q1 is:>  "
         << " (" << Answer.x << ")x +"
         << " (" << Answer.y << ")y +"
         << " (" << Answer.z << ")z" << endl;

    cout << "   multiple: " << multiple << endl;

    cout << "  |R12|: " << r12_mod << endl;

    cout << "   R12:   ["
         << "x:  " << r12.x * r12_mod << " y:  " << r12.y * r12_mod << "  z: " << r12.z * r12_mod << "]" << endl;

    cout << "   A12:   ["
         << "x:  " << r12.x << " y:  " << r12.y << "  z: " << r12.z << "]" << endl; // ( R12 / |R12| ) gives A12
    return 0;
}
