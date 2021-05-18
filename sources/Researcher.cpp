#include "Researcher.hpp"

namespace pandemic
{
    Researcher::Researcher(Board& board, City city) : Player(board, city)
    {
    }
    Researcher::~Researcher()
    {
    }

    bool Researcher::can_discover_cure(Color color)
    {
        return Player::discover_cure_throw_cards(color);
    }
}