#include <cstddef>

class Canvas
{
public:
    Canvas(const std::size_t row, const std::size_t col);
    ~Canvas();
    void Resize(const std::size_t row, const std::size_t col);
    bool DrawPixel(const int x, const int y, const char brush);
    void Print() const;
    void Clear();
private:
    std::size_t row, col;
    char **canvas;
};

class Shape 
{
public:
    Shape();
    Shape(int x, int y, char b);
    double GetArea() {};
    int GetPerimeter() {};
    void Draw(int canvas_width, int canvas_height);
protected:
    // Define common properties for all shape types
    int topleft_x, topleft_y;
    char brush;
};

class Square: public Shape
{
    std::size_t side;
public:
    Square(int x, int y, std::size_t z1, char b);
    double GetArea();
    int GetPerimeter();
    void Draw(int canvas_width, int canvas_height, Canvas* c);
};

class Rectangle: public Shape
{
    std::size_t width, height;
public:
    Rectangle(int x, int y, std::size_t z1, std::size_t z2, char b);
    double GetArea();
    int GetPerimeter();
    void Draw(int canvas_width, int canvas_height, Canvas* c);
};