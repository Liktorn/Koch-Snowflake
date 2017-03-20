#include <SDL.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include "Point.h"

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






int main(int argc, char ** argv)
{
	static int WIDTH = 800;
	static int HEIGHT = 600;
	static int LENGTH = 100;

	Point p1(4, 1);
	Point p2(1, 6);

	Point mP = midpoint(p1, p2);
	Point p3 = midpoint(p1, p3);
	cout << mP.x << "," << mP.y << endl;






	double x1 = 4;
	double y1 = 1;
	double x2 = 1;
	double y2 = 6;



	// Calculate a new point on the middle between x1,y1 and x2,y2
	double xx = (x1 + x2) / 2;
	double yy = (y1 + y2) / 2;
	cout << "midpoint = " << xx << "," << yy << endl;

	
	/*


	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;

		if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) == 0) {
			SDL_bool done = SDL_FALSE;

			while (!done) {
				SDL_Event event;

				

				// Set the color to the Renderer.
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

				int x1 = (WIDTH / 2);
				int x2 = (WIDTH / 2) - (LENGTH / 2);
				int x3 = (WIDTH / 2) + (LENGTH / 2);
				
				int y1 = (HEIGHT / 2) - (LENGTH / 2);
				int y2 = (HEIGHT / 2) + (LENGTH / 2);
				int y3 = (HEIGHT / 2) + (LENGTH / 2);

				int v1[] = { x1, y1 };
				int v2[] = { x2, y2 };
				v1[0] = 4;
				v1[1] = 1;
				v2[0] = 1;
				v2[1] = 6;
				std::cout << "distance between vectors " << x1 << "," << y1 << " and " << x2 << "," << y2 << " is ";
				std::cout << vectorDistance(v1, v1 + 2, v2) << std::endl;


				// drawing the 3 lines
				SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
				SDL_RenderDrawLine(renderer, x2, y2, x3, y3);
				SDL_RenderDrawLine(renderer, x3, y3, x1, y1);
				SDL_RenderPresent(renderer);

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

	*/
	return 0;
}