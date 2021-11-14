#include <fstream>
#include <queue>
#include <vector>
using namespace std;

enum Color {
	WHITE,
	GRAY,
	BLACK
};

struct Vertex {
	unsigned component;
	Color color;
	vector<unsigned> adj;
};

void bfs(size_t t, size_t x, Vertex * v) {
	v[x].color = GRAY;
	v[x].component = t;
	queue<size_t> q;
	size_t index;
	q.push(x);

	while (!q.empty()) {
		index = q.front();
		q.pop();
		v[index].color = GRAY;

		for (size_t i = 0; i < v[index].adj.size(); i++)
			if (v[v[index].adj[i] - 1].color == WHITE) {
				v[v[index].adj[i] - 1].color = GRAY;
				q.push(v[index].adj[i] - 1);
			}
		v[index].color = BLACK;
		v[index].component = t;
	}
}

int main() {
	ifstream fin("components.in");
    ofstream fout("components.out");

    size_t n, m, c = 1;
    fin >> n >> m;

    Vertex * v = new Vertex[n];

    for (size_t i = 0; i < n; i++) {
    	v[i].color = WHITE;
    	v[i].component = 0;
    }

    unsigned x, y;

    for (size_t i = 0; i < m; i++) {
        fin >> x >> y;
        if (x == y)
        	continue;
        else { 
        	v[x - 1].adj.push_back(y);
        	v[y - 1].adj.push_back(x);
	    }
    }

    for (size_t i = 0; i < n; i++) {
    	if (v[i].color == WHITE) {
    		bfs(c, i, v);
    		c++;
    	}
    }

    fout << --c << "\n";

    for (size_t i = 0; i < n; i++)
       	fout << v[i].component << " ";

    delete [] v;

	return 0;
}

// #include <iostream>
// #include <vector>
// #include <cmath>

// class Point {
// public:
// 	explicit Point(double x = 0, double y = 0) : x(x),  y(y) {}
// 	Point(Point const & other) : x(other.x), y(other.y) {}
// 	Point & operator=(Point const & other) {
// 		if (this != &other) {
// 			x = other.x;
// 			y = other.y;
// 		}
// 		return *this;
// 	}

// 	double get_x() const {return x;}
// 	double get_y() const {return y;}
// 	bool operator==(Point const & right) const {return (x == right.x && y == right.y);}

// private:
// 	double x;
// 	double y;
// };


// class Line {
// public:
// 	virtual double length() const = 0;
// 	virtual std::vector<Point> get_components() const = 0;
// 	virtual ~Line() {} 
// };


// class Segment : public Line {
// public:
// 	explicit Segment(Point d1 = Point(), Point d2 = Point(1, 1)) : d1(d1), d2(d2) {
// 		if (d1 == d2)
// 			throw "Impossible to create a segment with start point mathes end point!!!";
// 	}

// 	Segment(Segment const & other) : d1(other.d1), d2(other.d2) {}
// 	Segment & operator=(Segment const & other) {
// 		if (this != &other) {
// 			d1 = other.d1;
// 			d2 = other.d2;
// 		}
// 		return *this;
// 	}

// 	double length() const {
// 		return sqrt(pow((d1.get_x() - d2.get_x()), 2.0) + pow((d1.get_y() - d2.get_y()), 2.0));
// 	}

// 	std::vector<Point> get_components() const {
// 		std::vector<Point> temp;
// 		temp.push_back(d1);
// 		temp.push_back(d2);
// 		return temp; 
// 	}

// 	Point start() const {return d1;}
// 	Point end() const {return d2;}

// private:
// 	Point d1;
// 	Point d2;
// };


// class Polyline : public Line {
// public:
// 	Polyline() = delete;

// 	explicit Polyline(std::vector<Point> ps) : points(ps) {
// 		if (points.size() >= 2)
// 			delete_repeated();
// 		if (points.size() < 2)
// 			throw "Impossible to create a polyline with less than 2 points";
// 	}

// 	Polyline(Polyline const & other) : points(other.points) {}
// 	Polyline & operator=(Polyline const & other) {
// 		if (this != &other)
// 			points = other.points;
// 		return *this;
// 	}

// 	Polyline(Point * ps, size_t size) {
// 		if (size >= 2) {
// 			for (size_t i = 0; i < size; i++)
// 				points.push_back(ps[i]);
// 			delete_repeated();
// 		}
// 		if (size < 2 || points.size() < 2)
// 			throw "Impossible to create a polyline with less than 2 points";
// 	}

// 	double length() const {
// 		double length = 0;
// 		Point prev = points[0];
// 		for (size_t i = 1; i < points.size(); i++) {
// 			length += Segment(prev, points[i]).length();
// 			prev = points[i];
// 		}
// 		return length;
// 	}

// 	std::vector<Point> get_components() const {return points;}

// private:
// 	void delete_repeated() {
// 		Point prev = points[0];
// 		for (size_t i = 1; i < points.size(); i++) {
// 			if (prev == points[i])  {
// 				points.erase(points.begin() + i);
// 				i--;
// 			}
// 			else
// 				prev = points[i];
// 		}
// 	}

// protected:
// 	std::vector<Point> points;
// };


// class ClosedPolyline : public Polyline {
// public:
// 	ClosedPolyline() = delete;

// 	explicit ClosedPolyline(std::vector<Point> ps) : Polyline(ps) {
// 		check_closed();
// 		if (points.size() < 3)
// 			throw "Impossible to create a  closed polyline with less than 3 points";
// 	}

// 	ClosedPolyline(Point * ps, size_t size) : Polyline(ps, size) {
// 		check_closed();
// 		if (points.size() < 3)
// 			throw "Impossible to create a closed polyline with less than 3 points";
// 	}

// 	ClosedPolyline(ClosedPolyline const & other) : Polyline(other.points) {}
// 	ClosedPolyline & operator=(ClosedPolyline const & other) {
// 		if (this != &other)
// 			points = other.points;
// 		return *this;
// 	}

// 	double length() const {
// 		double length = Polyline::length();
// 		length += Segment(points[0], points[points.size() - 1]).length();
// 		return length;
// 	}

// 	std::vector<Point> get_components() const {return points;}

// private:
// 	void check_closed() {
// 		if (points[points.size() - 1] == points[0])
// 			points.erase(points.end() - 1);
// 	}
// };



// int main() {

// 	// std::vector<Point> ps;
// 	// ps.push_back(Point());
// 	// ps.push_back(Point(1, 1));
// 	// ps.push_back(Point(2, 2));
// 	// ps.push_back(Point(2, 0));
// 	// ps.push_back(Point(2, 0));
// 	// ps.push_back(Point(-1, 0));

// 	// Point * pd = new Point[4];
// 	// pd[0] = Point(1, 0);
// 	// pd[1] = Point(2, 0);
// 	// pd[2] = Point();
// 	// pd[3] = Point(1, 0);

// 	// Polyline l1 = Polyline(ps);
// 	// ClosedPolyline l2 = ClosedPolyline(pd, 4);

// 	// std::cout << l1.get_components().size() << '\n';
// 	// std::cout << l2.get_components().size() << '\n';
// 	// std::cout << l1.length() << ' ' << l2.length() << '\n';

// 	// delete [] pd;



// 	std::vector<Point> ps;             // ТЕСТ НА ДИНАМИЧЕСКИЙ ПОЛИМОРФИЗМ ДЛЯ АБСТРАКТНОГО КЛАССА ЛИНИЙ
// 	ps.push_back(Point());
// 	ps.push_back(Point(1, 1)); 
// 	ps.push_back(Point(1));

// 	Segment l1 = Segment(Point(-3), Point(2));
// 	Polyline l2(ps);
// 	ClosedPolyline l3(ps);
// 	Polyline l4 = l2;
// 	Segment l5;
// 	l5 = l1;
// 	ClosedPolyline l6 = l3;

// 	Line * lines[] = {(Line *)&l1, (Line *)&l2, (Line *)&l3, (Line *)&l4, (Line *)&l5, (Line *)&l6};

// 	for (size_t i = 0; i < 6; i++) {
// 		std::cout << lines[i]->get_components().size() << ' ';
// 		std::cout << lines[i]->length() << '\n';
// 	}

// 	std::cout << '\n' << l5.start().get_x() << ' ' << l1.start().get_x() << '\n';
// 	std::cout << l4.get_components()[0].get_x() << ' ' << l2.get_components()[0].get_x() << '\n';
// 	std::cout << l6.get_components()[1].get_x() << ' ' << l3.get_components()[1].get_x() << '\n';

// 	return 0;
// }