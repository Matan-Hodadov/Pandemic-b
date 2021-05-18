#pragma once

#include <string>
#include <unordered_set>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"


namespace pandemic
{
    class Player
    {
        protected:
        Board& board;
        City current_city;
        int n;
        static const int cards_num = 5;
        std::unordered_set<City> owned_cards;

        virtual bool can_treat(City);  //field doctor and virologist are diffrent
        virtual bool can_discover_cure(Color);  //reasercher is diffrent
        virtual bool discover_cure_throw_cards(Color color);  //gene splicer is diffrent

        public:
        Player(Board& b, City city);
        ~Player();
        virtual Player& drive(City city);  //medic is diffrent 
        virtual Player& fly_direct(City city);  //medic and dispatcher are diffrent 
        virtual Player& fly_charter(City city);  //medic is diffrent 
        virtual Player& fly_shuttle(City city);  //medic is diffrent 
        virtual Player& build();  //operation expart is diffrent 
        virtual Player& discover_cure(Color color);  //medic is diffrent 
        virtual Player& treat(City city);  //medic and virologist are diffrent 

        virtual std::string role() const = 0;
        Player& take_card(City city);
        Player& throw_card(City city);

    };
}