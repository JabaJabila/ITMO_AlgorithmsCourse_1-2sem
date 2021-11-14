#include <fstream>
using namespace std;

unsigned ** create_array(size_t n) {
    unsigned ** a = new unsigned *[n];
    for (size_t i = 0; i < n; i++) {
        a[i] = new unsigned [n];
        for (size_t j = 0; j < n; j++)
            a[i][j] = 0;
        }
    return a;
}

void free_array(unsigned ** a, size_t n) {
    for (size_t i = 0; i < n; i++)
        delete [] a[i];
    delete [] a;
}

bool check_parallels(unsigned ** v, size_t n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            if ((i == j) and (v[i][j] > 2))
                return true;
            if (v[i][j] > 1)
                return true;
        }
    return false;
}

int main() {
	ifstream fin("input.txt");
    ofstream fout("output.txt");

    size_t n, m;
    fin >> n >> m;
    unsigned ** v_matrix = create_array(n);
    unsigned x, y;

    for (size_t i = 0; i < m; i++) {
        fin >> x >> y;
        v_matrix[x - 1][y - 1]++;
        v_matrix[y - 1][x - 1]++;
    }
    	
    if (check_parallels(v_matrix, n))
        fout << "YES\n";
    else
        fout << "NO\n";

    free_array(v_matrix, n);

	return 0;
}














// #include <iostream>
// #include <vector>
// #include <cmath>

// class Point {
// public:
// 	Point(double x = 0, double y = 0) : x(x),  y(y) {}
// 	double get_x() const {return x;}
// 	double get_y() const {return y;}
// 	bool operator==(Point const &right) const {return (x == right.x && y == right.y);}

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


// class Segment : Line {
// public:
// 	Segment(Point d1 = Point(), Point d2 = Point(1, 1)) : d1(d1), d2(d2) {
// 		if (d1 == d2)
// 			throw "Impossible to create a segment with start point mathes end point!!!";
// 	}

// 	double length() const {
// 		return sqrt(pow((d1.get_x() - d2.get_x()), 2.0) + pow((d1.get_y() - d2.get_y()), 2.0));
// 	};

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


// class Polyline : Line {
// public:
// 	Polyline() = delete;

// 	Polyline(std::vector<Point> ps) : points(ps) {
// 		if (points.size() >= 2)
// 			delete_repeated();
// 		if (points.size() < 2)
// 			throw "Impossible to create a polyline with less than 2 points";
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


// class ClosedPolyline : Polyline {
// public:
// 	ClosedPolyline() = delete;

// 	ClosedPolyline(std::vector<Point> ps) : Polyline(ps) {
// 		check_closed();
// 		if (points.size() < 3)
// 			throw "Impossible to create a  closed polyline with less than 3 points";
// 	}

// 	ClosedPolyline(Point * ps, size_t size) : Polyline(ps, size) {
// 		check_closed();
// 		if (points.size() < 3)
// 			throw "Impossible to create a closed polyline with less than 3 points";
// 	}

// 	double length() const {
// 		double length = 0;
// 		Polyline temp = Polyline(points);
// 		length += temp.length();
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



// 	// std::vector<Point> ps;             // ТЕСТ НА ДИНАМИЧЕСКИЙ ПОЛИМОРФИЗМ ДЛЯ АБСТРАКТНОГО КЛАССА ЛИНИЙ
// 	// ps.push_back(Point());
// 	// ps.push_back(Point(1, 1));
// 	// ps.push_back(Point(0, 1));

// 	// Segment l1 = Segment(Point(), Point(2, 0));
// 	// Polyline l2 = Polyline(ps);
// 	// ClosedPolyline l3 = ClosedPolyline(ps);

// 	// Line * lines[3] = {(Line *)&l1, (Line *)&l2, (Line *)&l3};

// 	// for (size_t i = 0; i < 3; i++) {
// 	// 	std::cout << lines[i]->get_components().size() << ' ';
// 	// 	std::cout << lines[i]->length() << '\n';
// 	// }

// 	return 0;
// }