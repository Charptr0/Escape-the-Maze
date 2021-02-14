#pragma once

enum axis
{
    x = 0, y = 1
};

class Entity
{
    protected:
    int coordinate[2];

    public:
    int x() const;
    int y() const;


    void setX(const int &x);
    void setY(const int&y);
    void setPosition(const int coord[2]);
    void setSymbol(char &symbol);

};