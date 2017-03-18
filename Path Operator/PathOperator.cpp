/*
 * PathOperator.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Sam
 */

#include <iostream>

using namespace std;

#include "path.h"

Path::Path(int n)
{
    xy = new int [2 * n];
    length = n;
}

int Path::getX(int i)
{
   if (0 <= i && i < length)
      return xy[2 * i];
   else
      return 0;
}

int Path::getY(int i)
{
   if (0 <= i && i < length)
      return xy[2 * i + 1];
   else
      return 0;
}

void Path::set(int i, int x, int y)
{
   if (0 <= i && i < length)
   {
      xy[2 * i] = x;
      xy[2 * i + 1] = y;
   }
}

int Path::getLength()
{
   return length;
}

Path& Path::operator=(const Path& rhs)
{
	//xy = new int [rhs.length];

    for(int i = 0; i < 2 * rhs.length; i++)
    {
    	xy[i] = rhs.xy[i];
    }

    length = rhs.length;
}

void Path::printXY()
{
    for(int i = 0; i < length; i++)
    {
    	 cout << xy[i] << " ";
    }
    cout << "\n";
}

int main()
{
   Path p(4);
   p.set(0, 3, 1);
   p.set(1, 4, 1);
   p.set(2, 5, 9);
   p.set(3, 2, 6);
   p.printXY();
   cout << p.getX(2) << " " << p.getY(2) << endl;
   cout << "Expected: 5 9" << endl;
   Path q(1);
   q = p;
   cout << q.getX(0) << " " << q.getY(0) << endl;
   cout << "Expected: 3 1" << endl;
   p.set(2, 9, 7);
   cout << p.getX(2) << " " << p.getY(2) << endl;
   cout << "Expected: 9 7" << endl;
   cout << q.getX(2) << " " << q.getY(2) << endl;
   cout << "Expected: 5 9" << endl;

   q.printXY();
   p.printXY();

   return 0;
}



