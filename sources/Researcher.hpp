#pragma once

#include "Player.hpp"

namespace pandemic
{
    class Researcher : public Player
    {
        public:
        Researcher(Board& board, City city);
        ~Researcher();

        std::string role() const override
        {
            return "Researcher";
        }

        protected:
        bool can_discover_cure(Color) override;
    };
}