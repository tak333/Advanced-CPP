#include <vector>
using namespace std;

#include <cmath>

struct Point
{
	Point(double x = 0, double y = 0);
	double x, y;
	bool operator==(const Point& b)const;
	bool operator!=(const Point& b)const;
};

class Line
{
public:
	Line(Point, Point);
	Line(double, double);
	double y(double x) { return k * x + b; }
	double k, b;
	bool operator==(const Line& b)const;
	bool operator!=(const Line& b)const;
};

class Shape
{
public:
	virtual double perimeter() const = 0;
	virtual double area() const = 0;
	virtual bool operator==(const Shape& another) const = 0;

	virtual void rotate(Point center, double angle) = 0;
	virtual void reflex(Point center) = 0;
	virtual void reflex(Line axis) = 0;
	virtual void scale(Point center, double coefficient) = 0;
};

class Polygon : public Shape {
public:
	Polygon(const std::vector<Point>& arr);
	size_t verticesCount();
	std::vector<Point> getVertices();

	double perimeter() const override;
	double area() const override;
	bool operator!=(const Shape& another) const;
	virtual bool operator==(const Shape& another) const override;

	void rotate(Point center, double angle) override;
	void reflex(Point center) override;
	void reflex(Line axis) override;
	void scale(Point center, double coefficient) override;

protected:
	std::vector<Point> arr;
};

class Ellipse : public Shape {
public:
	Ellipse(Point f1, Point f2, double sum);
	std::pair<Point, Point> focuses();
	double eccentricity();
	Point center();

	double perimeter() const override;
	double area() const override;
	bool operator!=(const Shape& another) const;
	bool operator==(const Shape& another) const override;

	void rotate(Point center, double angle) override;
	void reflex(Point center) override;
	void reflex(Line axis) override;
	void scale(Point center, double coefficient)override;
protected:
	Point f1, f2;
	double sum;
};

class Circle :public Ellipse {
public:
	Circle(Point p, double r);
	double radius();
};

class Rectangle : public Polygon {
public:
	//не понимаю, зачем число:
	Rectangle(Point p1, Point p2, int);
	Rectangle(double d);
	Point center();
	std::pair<Line, Line> diagonals();
};

class Square : public Rectangle {
public:
	Square(Point p1, Point p2);
	Circle circumscribedCircle();
	Circle inscribedCircle();
};

class Triangle : public Polygon {
private:
	Point averagePerpendicular();
public:
	Triangle(const Point p1, const Point p2, const  Point p3);
	Circle circumscribedCircle();
	Circle inscribedCircle();
	Point centroid(); //центр масс
	Point orthocenter(); //ортоцентр
	Line EulerLine(); //пр€ма€ Ёйлера
	Circle ninePointsCircle(); //окружность Ёйлера
};