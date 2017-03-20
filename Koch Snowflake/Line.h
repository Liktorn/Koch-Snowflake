#pragma once
class Line
{
private:
	int degree;
	int length;
	int segmentLength;
	int x1;
	int x2;
	int x3;
	int x4;
	int y1;
	int y2;
	int y3;
	int y4;

public:
	Line();
	~Line();
	void drawLine();
	void calcMiddleSegment(int x1, int y1, int x4, int y4);
};

