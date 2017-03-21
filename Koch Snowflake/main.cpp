#include <SDL.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include "Point.h"
#include "Line.h"

#define radian2degree(a) (a * 57.295779513082)
#define degree2radian(a) (a * 0.017453292519)




using namespace std;
using namespace bw;

template<class Iter_T, class Iter2_T>
double vectorDistance(Iter_T first, Iter_T last, Iter2_T first2) {
	double ret = 0.0;
	while (first != last) {
		double dist = (*first++) - (*first2++);
		ret += dist * dist;
	}
	return ret > 0.0 ? sqrt(ret) : 0.0;
}



// Calculate a new point on the middle between point a and b
Point midpoint(Point& a, Point& b) {
	Point ret;
	ret.x = (a.x + b.x) / 2;
	ret.y = (a.y + b.y) / 2;
	return ret;
}
// Return the distance between p1 and p2
float pointDist(Point &p1, Point &p2) {
	//First you calculate the vector from x1y1 to x2y2 :
	float vx = (float)p2.x - (float)p1.x;
	float vy = (float)p2.y - (float)p1.y;

	//Then calculate the length (magnitude) :
	float mag = sqrt(vx*vx + vy*vy);
	return mag;
}
// Make a new point between p1 and p2 at distance dist
Point newPoint(Point &p1, Point &p2, int dist) {

	Point ret;

	//First you calculate the vector from x1y1 to x2y2 :
	float vx = (float)p2.x - (float)p1.x;
	float vy = (float)p2.y - (float)p1.y;

	//Then calculate the length (magnitude) :
	float mag = sqrt(vx*vx + vy*vy);

	//Normalize the vector to unit length :
	vx /= mag;
	vy /= mag;

	//Finally calculate the new vector, which is x1y1 + vxvy * (distance).
	ret.x = (int)((float)p1.x + vx * ((double)dist));
	ret.y = (int)((float)p1.y + vy * ((double)dist));

	return ret;
}
// Return a point len distance and d degrees from a point
Point degreeToPoint(Point &p, int len, int d) {

	Point ret;
	ret.x = p.x + len * cos(degree2radian(d));
	ret.y = p.y + len * sin(degree2radian(d));
	return ret;
}
Line makeMiddleSegment(Line &A, int len) {

	Point p1;
	Point p2;

	//First you calculate the vector from x1y1 to x2y2 :
	float vx = (float)A.b.x - (float)A.a.x;
	float vy = (float)A.b.y - (float)A.a.y;

	//Then calculate the length (magnitude) :
	float mag = sqrt(vx*vx + vy*vy);

	//Normalize the vector to unit length :
	vx /= mag;
	vy /= mag;

	//Finally calculate the new vector, which is x1y1 + vxvy * (distance).
	p1.x = (int)((float)A.a.x + vx * ((double)len));
	p1.y = (int)((float)A.a.y + vy * ((double)len));
	p2.x = (int)((float)A.a.x + vx * ((double)len * 2));
	p2.y = (int)((float)A.a.y + vy * ((double)len * 2));

	Line ret(p1, p2);
	return ret;

}
// Draw the line using the SDL funktion
void drawLine(SDL_Renderer *renderer, Line line) {
	SDL_RenderDrawLine(renderer, line.a.x, line.a.y, line.b.x, line.b.y);
}
// Rotate line degrees
Line rotateLine(Line line, int angle) {

	Line ret;
	Point p1(line.a);
	Point p2(line.b);

	float s = sin(angle);
	float c = cos(angle);


	// rotate point
	float xnew = p.x * c - p.y * s;
	float ynew = p.x * s + p.y * c;

	//	If you rotate point(px, py) around point(ox, oy) by angle theta you'll get:
	//	p'x = cos(theta) * (px-ox) - sin(theta) * (py-oy) + ox
	//	p'y = sin(theta) * (px-ox) + cos(theta) * (py-oy) + oy
	//	this is an easy way to rotate a point in 2D.

	//First you calculate the vector from x1y1 to x2y2 :
	float vx = (float)p2.x - (float)p1.x;
	float vy = (float)p2.y - (float)p1.y;

	//Then calculate the length (magnitude) :
	float mag = sqrt(vx*vx + vy*vy);

	return ret;
}

int main(int argc, char ** argv)
{
	static int WIDTH = 800;
	static int HEIGHT = 600;
	static int LENGTH = 111;


	
	// Starting point in the middle of the screen
	Point startingPoint((WIDTH / 2), (HEIGHT / 2));
	// Making the 3 points of the triangle
	// Top point
	Point p1(degreeToPoint(startingPoint, LENGTH,270));
	// Bottom left
	Point p2(degreeToPoint(startingPoint, LENGTH, 150));
	// Bottom right
	Point p3(degreeToPoint(startingPoint, LENGTH, 30));

	// Calculate the length between points and divide it by 3
	double dist = pointDist(p1, p2) / 3;



	// The segmets
	Line lineA(p1, p2);
	Line lineB(p2, p3);
	Line lineC(p3, p1);

	Line segA(makeMiddleSegment(lineA, dist));
	Line segB(makeMiddleSegment(lineB, dist));
	Line segC(makeMiddleSegment(lineC, dist));


	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;

		if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;

			while (!done) {
				SDL_Event event;

				
				// Set the color to the Renderer.
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

				
				// drawing the 3 middle segments
				drawLine(renderer, segA);
				drawLine(renderer, segB);
				drawLine(renderer, segC);

				//SDL_RenderDrawLine(renderer, segA.a.x, segA.a.y, segA.b.x, segA.b.y);
				//SDL_RenderDrawLine(renderer, segB.a.x, segB.a.y, segB.b.x, segB.b.y);
				//SDL_RenderDrawLine(renderer, segC.a.x, segC.a.y, segC.b.x, segC.b.y);
				SDL_RenderPresent(renderer);

			/*	SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
				SDL_RenderDrawLine(renderer, p2.x, p2.y, p3.x, p3.y);
				SDL_RenderDrawLine(renderer, p3.x, p3.y, p1.x, p1.y);
				SDL_RenderPresent(renderer);*/

				// Checking the event list.
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT) {
						done = SDL_TRUE;
					}
				}
			}
		}

		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}
		if (window) {
			SDL_DestroyWindow(window);
		}
	}
	SDL_Quit();

	//Pause the console so that the window does not exit imediatly
	std::cout << "like this" << std::endl;
	system("PAUSE"); // <-- this will stop the console from closing.

	
	return 0;
}