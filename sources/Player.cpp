#include "Player.hpp"

#include "City.hpp"
#include "Color.hpp"

#include <vector>

using namespace pandemic;
using namespace std;

namespace pandemic
{

    Player::Player(Board& b, City current_city)
    :board(b)
    {
        this->current_city = current_city;
        this->n = cards_num;
    }

    Player::~Player()
    {
    }

    Player& Player::take_card(City city)
    {
        this->owned_cards.insert(city);
        return (*this);
    }

    Player& Player::throw_card(City city)
    {
        if(this->owned_cards.find(city) != this->owned_cards.end())
        {
            owned_cards.erase(city);
        }
        return (*this);
    }

    Player& Player::drive(City city)
    {
        if(!(board.is_cities_connected(city, this->current_city)))
        {
            throw invalid_argument("those cities are not connected");
        }
        this->current_city = city;
        return *this;
    }

    Player& Player::fly_direct(City city)
    {
        if(this->owned_cards.find(city) == this->owned_cards.end())
        {
            throw invalid_argument("you don't have the given card");
        }
        if(city == this->current_city)
        {
            throw invalid_argument("you can't fly to your current city");
        }
        this->throw_card(city);
        this->current_city = city;
        return *this;
    }

    Player& Player::fly_charter(City city)
    {
        if(this->owned_cards.find(this->current_city) == this->owned_cards.end())
        {
            throw invalid_argument("you don't have your current city card");
        }
        if(city == this->current_city)
        {
            throw invalid_argument("you can't fly to your current city");
        }
        this->throw_card(this->current_city);
        this->current_city = city;
        return *this;
    }

    Player& Player::fly_shuttle(City city)
    {
        if(!(board.have_research_station(this->current_city)))
        {
            throw invalid_argument("your current city doesn't have a research station");
        }
        if(!(board.have_research_station(city)))
        {
            throw invalid_argument("the dest city doesn't have a research station");
        }
        if(this->current_city == city)
        {
            throw invalid_argument("you can't fly to your current city");
        }
        this->current_city = city;
        return *this;
    }
    Player& Player::build()
    {
        if(board.have_research_station(this->current_city))
        {
            return *this;
        }
        if(this->owned_cards.find(this->current_city) == this->owned_cards.end())
        {
            throw invalid_argument("you don't have your current city card");
        }
        board.add_research_station(this->current_city);
        this->owned_cards.erase(this->current_city);
        return *this;
    }

    bool Player::discover_cure_throw_cards(Color color)
    {
        vector<City> discover_cure_cards;
        for(City city : this->owned_cards)
        {
            if(board.get_city_color(city) == color)
            {
                discover_cure_cards.push_back(city);
            }
            if(discover_cure_cards.size() == this->n)
            {
                break;
            }
        }
        if(discover_cure_cards.size() < this->n)
        {
            return false;
        }
        for(City city : discover_cure_cards)
        {
            this->throw_card(city);
        }
        return true;
    }

    bool Player::can_discover_cure(Color color)
    {
       if(!board.have_research_station(this->current_city))
       {
           return false;
       }
       return this->discover_cure_throw_cards(color);
    }

    Player& Player::discover_cure(Color color)
    {
            if(board.have_cure(color))
        {
            return *this;
        }
        if(!(this->can_discover_cure(color)))
        {
            throw invalid_argument("you dont have enough cards or your current city dont have a resreach city");
        }
        board.add_cure(color);
        return *this;
    }

    bool Player::can_treat(City city)
    {
        if(city != this->current_city)
        {
            return false;
        }
        if(board[city] <= 0)
        {
            return false;
        }
        return true;
    }

    Player& Player::treat(City city)
    {
        if(!(this->can_treat(city)))
        {
            throw invalid_argument("aint the currect city or treat lvl is 0");
        }
        if(board.have_cure(board.get_city_color(city)))
        {
            board[city] = 0;
        }
        else
        {
            board[city] = board[city] - 1; 
        }
        return *this;
    }
}