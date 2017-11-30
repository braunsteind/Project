#ifndef EX2_POINT_H
#define EX2_POINT_H

class Point {
public:
    /**
     * Default constructor.
     * Set the point to (-1,-1).
     */
    Point();

    /**
     * Constructor.
     * @param row The row of the point.
     * @param column The column of the point.
     */
    Point(int row, int column);

    /**
     * Get the point row.
     * @return The point row.
     */
    int getRow() const;

    /**
     * Get the point column.
     * @return The point column.
     */
    int getColumn() const;

    /**
     * Set the point row.
     * @param r The row.
     */
    void setRow(int r);

    /**
     * Set the point column.
     * @param c The column.
     */
    void setColumn(int c);

    /**
     * Set point.
     * @param r The row.
     * @param c The column.
     */
    void setPoint(int r, int c);

    /**
     * Copy point.
     * @param p The point to copy from.
     */
    void copyPoint(const Point p);

    /**
     * Equals override.
     * @param point The other point.
     * @return True if equals, false if not.
     */
    bool operator==(const Point &point) const;

private:
    int row;
    int column;
};

#endif //EX2_POINT_H