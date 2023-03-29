#include <iostream>
#include <conio.h>
using namespace std;


class Point {
protected:
	int x;
	int y;
public:
	Point() {
		printf("Point()\n");
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		printf("Point(int x, int y)\n");
		this->x = x;
		this->y = y;
	}
	Point(const Point& p) {
		printf("Point(Point &p)\n");
		x = p.x;
		y = p.y;
	}
	~Point() {
		printf("%d, %d\n", x, y);
		printf("~Point()\n");
	}

	void reset();
	void showCord();
	void moveCoord(int dx, int dy);
};

void Point::reset() {
	x = 0;
	y = 0;
}

void Point::showCord() {
	printf("Point coord: (%d, %d)\n", x, y);
}

void Point::moveCoord(int dx, int dy) {
	x = x + dx;
	y = y + dx;
}

class ColoredPoint : public Point {
protected:
	int color;
public:
	ColoredPoint() : Point() {
		printf("ColoredPoint()\n");
		x = 0;
		y = 0;
		color = 0;
	}
	ColoredPoint(int x, int y, int color) : Point(x, y) {
		printf("ColoredPoint(int x, int y)\n");
		this->x = x;
		this->y = y;
		this->color = color;
	}
	ColoredPoint(const ColoredPoint& p) {
		printf("ColoredPoint(ColoredPoint &p)\n");
		x = p.x;
		y = p.y;
		color = p.color;
	}
	~ColoredPoint() {
		printf("%d, %d color = %d\n", x, y, color);
		printf("~ColoredPoint()\n");
	}
};


class Section {
protected:
	Point* p1;
	Point* p2;
public:
	Section() {
		printf("Section()\n");
		p1 = new Point;
		p2 = new Point;
	}
	Section(int x1, int y1, int x2, int y2) {
		printf("Section(int x1, int y1, int x2, int y2)\n");
		p1 = new Point(x1, y1);
		p2 = new Point(x2, y2);
	}
	Section(const Section& s) {
		printf("Section(Section &p)\n");
		p1 = new Point(*(s.p1));
		p2 = new Point(*(s.p2));
	}
	~Section() {
		delete p1;
		delete p2;
		printf("~Section()\n");
	}
};


class Square {
protected:
	Point firstS;
	Point secondS;
	Point thirdS;
	Point fourthS;
	int radius;
public:
	Square() {
		printf("Square()\n");
	}
	Square(int x1, int y1, int x2, int y2,
		int x3, int y3, int x4, int y4) : firstS(x1, y1), secondS(x2, y2), thirdS(x3, y3), fourthS(x4, y4) {
		printf("Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)\n");
	}
	Square(const Square& s) : firstS(s.firstS), secondS(s.secondS), thirdS(s.thirdS), fourthS(s.fourthS) {
		printf("Square(Square &c)\n");
	}
	~Square() {
		printf("~Square()\n");
	}
};


int main() {
	setlocale(LC_ALL, "rus");

	/* cout << endl << "________Section________" << endl;
	Section* s1 = new Section(2, 4, 6, 8);
	Section* s2 = new Section(*s1);
	delete s1;
	delete s2;
	cout << endl << "________ColoredPoint________" << endl;
	ColoredPoint* cp = new ColoredPoint(1, 2, 255);
	cp->showCord();
	cp->reset();
	cp->showCord();
	delete cp; */


	{
		cout << endl << "________Square________" << endl;
		Square sq1(1, 2, 3, 4, 5, 6, 7, 8);
		Square sq2(sq1);
	}
	
	_getch();
	return 0;
}
