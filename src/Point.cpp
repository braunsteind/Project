#include "Point.h"

Point::Point() : row(-1), column(-1) {}

Point::Point(int row, int column) : row(row), column(column) {}

int Point::getRow() const {
    return row;
}

int Point::getColumn() const {
    return column;
}

void Point::setRow(int r) {
    row = r;
}

void Point::setColumn(int c) {
    column = c;
}

void Point::setPoint(int r, int c) {
    row = r;
    column = c;
}

void Point::copyPoint(const Point p) {
    row = p.row;
    column = p.column;
}

bool Point::operator==(const Point &point) const {
    //if same point return true.
    if (row == point.getRow() && column == point.getColumn()) {
        return true;
    }
    //if not return false.
    return false;
}