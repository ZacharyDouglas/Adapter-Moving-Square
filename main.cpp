//Zach Douglas
//Lab 9
//Moving Square
//04/06/16

#include <iostream>
#include "AdapterClass.cpp"

int main() {
	Figure *square = new SquareAdapter(10);
	SquareAdapter *ptr = new SquareAdapter(10);

	int squareSize;
	int squareResize;

	std::cout << "Please enter a square size!" << std::endl;
	std::cin >> squareSize;
	ptr->resize(squareSize);
	ptr->draw();
	std::cout << "Please enter a new size for the square!" << std::endl;
	std::cin >> squareResize;
	ptr->resize(squareResize);
	ptr->draw();
	std::cout << "Wait!";
}