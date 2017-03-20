#pragma once

namespace bw{

class Point
{
public:
	double x;
	double y;

public:
	Point();
	Point(int x, int y) :  x(x), y(y) { };
	~Point();
};

}//namespace