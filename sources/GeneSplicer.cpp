#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic
{
    GeneSplicer::GeneSplicer(Board& board, City city) : Player(board, city)
    {
    }
    GeneSplicer::~GeneSplicer()
    {
    }

    bool GeneSplicer::discover_cure_throw_cards(Color color)
    {
        if(this->n > owned_cards.size())
        {
            return false;
        }
        auto iter = owned_cards.begin();
        int i = 0;
        while(i < this->n)
        {
            iter = owned_cards.erase(iter);
            i += 1;
        }
        return true;
    }
}