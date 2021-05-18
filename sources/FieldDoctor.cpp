#include "FieldDoctor.hpp"


namespace pandemic
{
    FieldDoctor::FieldDoctor(Board& board, City city) : Player(board, city)
    {
    }
    FieldDoctor::~FieldDoctor()
    {
    }

    bool FieldDoctor::can_treat(City city)
    {    
        if(city != this->current_city && !board.is_cities_connected(this->current_city, city))
        {
            return false;
        }
        if(board[city] <= 0)
        {
            return false;
        }
        return true;
    }   
}