#include "Board.hpp"

Board::Board(int width, int height):
    width(width),
    height(height)
{
    // 1st dimension
    this->board.resize(this->width);

    // 2nd dimension
    for (int i = 0; i < (this->board.size()); i++)
        this->board[i].resize(this->height);

    for (int i = 0; i < (this->width); i++)
        for (int j = 0; j < (this->height); j++)
            this->board[i][j] = new Tile();
}
Board::~Board()
{
    for (int i = 0; i < (this->width); i++)
        for (int j = 0; j < (this->height); j++)
            if (this->board[i][j]) delete this->board[i][j];
}
Tile* Board::at(int x, int y)
{
    return (this->board[x][y]);
}
void Board::render(int x, int y)
{
    for (int i = 0; i < (this->width); i++)
        for (int j = 0; j < (this->height); j++)
            this->board[i][j]->render(x + i, y + j);
}
int Board::getWidth()
{
    return (this->width);
}
int Board::getHeight()
{
    return (this->height);
}

