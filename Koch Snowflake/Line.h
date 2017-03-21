#pragma once
#include "Point.h"
#include <math.h>

using namespace bw;

class Line
{
private:
	

public:
	Point a;
	Point b;

	Line();
	Line(Point a, Point b) : a(a), b(b) { };
	~Line();
	void drawLine();


};

