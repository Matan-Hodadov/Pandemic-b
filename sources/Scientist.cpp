#include "Scientist.hpp"

// #include "Player.hpp"

namespace pandemic
{
    Scientist::Scientist(Board& board, City city, int n)
    : Player(board, city)
    {
        this->n = n;
    }

    Scientist::~Scientist()
    {

    }
}