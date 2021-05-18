#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    Virologist::Virologist(Board& board, City city) : Player(board, city)
    {
    }
    Virologist::~Virologist()
    {
    }

    bool Virologist::can_treat(City city)
    {
        return board[city] > 0;
    }

    Player& Virologist::treat(City city)
    {
        if (city != this->current_city)
        {
            if (owned_cards.find(city) == owned_cards.end())
            {
                throw invalid_argument("You Don't have the required card");
            }
            owned_cards.erase(city);
        }
        Player::treat(city);
        return *this;
    }   
}