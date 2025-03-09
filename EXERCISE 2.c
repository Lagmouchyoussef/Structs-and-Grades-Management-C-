#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

Point create_point(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

void display_point(Point pt) {
    printf("( x , y ) = ( %.2f , %.2f )\n", pt.x, pt.y);
}

double distance(Point pt1, Point pt2) {
    return sqrt(pow(pt2.x - pt1.x, 2) + pow(pt2.y - pt1.y, 2));
}

typedef struct {
    Point points[100];
    int num_points;
} Polygon;

Polygon create_polygon() {
    Polygon poly;
    poly.num_points = 100;
    for (int i = 0; i < 100; i++) {
        poly.points[i] = create_point(i, i);
    }
    return poly;
}

double calculate_perimeter(Polygon poly) {
    double perimeter = 0.0;
    for (int i = 0; i < poly.num_points; i++) {
        Point pt1 = poly.points[i];
        Point pt2 = poly.points[(i + 1) % poly.num_points];
        perimeter += distance(pt1, pt2);
    }
    return perimeter;
}

int main() {
    Point pt1 = create_point(10.5, -3.5);
    Point pt2 = create_point(15.0, 7.0);
    display_point(pt1);
    display_point(pt2);
    printf("Distance between points: %.2f\n", distance(pt1, pt2));

    Polygon poly = create_polygon();
    printf("Perimeter of the polygon: %.2f\n", calculate_perimeter(poly));

    return 0;
}