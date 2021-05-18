#include "Medic.hpp"

using namespace std;

namespace pandemic
{
    Medic::Medic(Board& board, City city) : Player(board, city)
    {
    }
    Medic::~Medic()
    {
    }

    void Medic::update_board(City city)
    {
        if(board.have_cure(board.get_city_color(city)))
        {
            board[city] = 0;
        }
    }

    Player& Medic::drive(City city)
    {
        Player::drive(city);
        this->update_board(city);
        return *this;
    }

    Player& Medic::fly_direct(City city)
    {
        Player::fly_direct(city);
        this->update_board(city);
        return *this;
    }
    Player& Medic::fly_charter(City city)
    {
        Player::fly_charter(city);
        this->update_board(city);
        return *this;
    }
    Player& Medic::fly_shuttle(City city)
    {
        Player::fly_shuttle(city);
        this->update_board(city);
        return *this;
    } 
    Player& Medic::discover_cure(Color color)
    {
        Player::discover_cure(color);
        update_board(this->current_city);
        return *this;
    }
    Player& Medic::treat(City city)
    {
        if(!(Player::can_treat(city)))
        {
            throw invalid_argument("aint the currect city or treat lvl is 0");
        }
        board[city] = 0;
        return *this;
    }
}