#pragma once

#include "Player.hpp"

namespace pandemic
{
    class Virologist : public Player
    {
        public:
        Virologist(Board& board, City city);
        ~Virologist();

        std::string role() const override
        {
            return "Virologist";
        }

        Player& treat(City) override;

        protected:
        bool can_treat(City) override;
    };
}