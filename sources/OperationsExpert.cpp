#include "OperationsExpert.hpp"

namespace pandemic
{
    OperationsExpert::OperationsExpert(Board& board, City city) : Player(board, city)
    {
    }
    OperationsExpert::~OperationsExpert()
    {
    }

    Player& OperationsExpert::build()
    {
        board.add_research_station(this->current_city);
        return *this;
    }
}