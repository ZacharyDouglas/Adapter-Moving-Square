//Zach Douglas
//Lab 9
//Moving Square
//04/06/16

#include <iostream>

using std::cout; using std::endl;

// base interface
class Figure {
public:
	virtual void draw() = 0;
	virtual ~Figure() {}
};

// adaptee/implementer
class LegacyRectangle {
public:
	LegacyRectangle(int x1, int y1, int x3, int y3) :
		x1_(x1), y1_(y1), x3_(x3), y3_(y3) {}
	void oldDraw() {
		for (int i = 0; i < y3_; ++i) {
			for (int j = 0; j < x3_; ++j)
				if (y1_ <= i && x1_ <= j)
					cout << '*';
				else
					cout << ' ';
			cout << endl;
		}
	}

	void move(int x1, int y1, int x3, int y3) {
		x1_ = x1;
		y1_ = y1;
		x3_ = x3;
		y3_ = y3;
	}

	int getX1() {
		return x1_;
	}

	int getY1() {
		return y1_;
	}

	int getX3() {
		return x3_;
	}

	int getY3() {
		return y3_;
	}
private: // defining top/left and bottom/right coordinates 
	int x1_;
	int y1_;
	int x3_;
	int y3_;
};

// adapter uses multiple inheritance to inherit
// interface and implementation
class SquareAdapter : public Figure,
	private LegacyRectangle {
public:
	SquareAdapter(int size) :
		LegacyRectangle(0, 0, size, size) {};
	void draw() {
		oldDraw();
	}

	int size() {
		int ySize = getY3() - getY1();
		return ySize;
	}

	void resize(int newSize) {
		move(0, 0, newSize, newSize);
	}
};

