#include "Dispatcher.hpp"

using namespace pandemic;
using namespace std;

namespace pandemic
{
    Dispatcher::Dispatcher(Board &board, City city)
    : Player(board, city)
    {
    }
    Dispatcher::~Dispatcher()
    {
    }

    Player& Dispatcher::fly_direct(City dest_city)
    {
        if(board.have_research_station(this->current_city))
        {
            if(this->current_city == dest_city)
            {
                throw invalid_argument("can't ply to your current city");
            }
            this->current_city = dest_city;
        }
        else
        {
            Player::fly_direct(dest_city);
        }
        return *this;
    }
}