#pragma once

#include "Player.hpp"

namespace pandemic
{
    class Medic : public Player
    {
        public:
        Medic(Board& board, City city);
        ~Medic();

        std::string role() const override
        {
            return "Medic";
        }

        virtual Player& drive(City) override;
        virtual Player& fly_direct(City) override; 
        virtual Player& fly_charter(City) override;
        virtual Player& fly_shuttle(City) override; 
        virtual Player& discover_cure(Color) override;
        virtual Player& treat(City city) override;

        private:
        void update_board(City);
    };
}