#pragma once

#include "Player.hpp"

namespace pandemic
{
    class GeneSplicer : public Player
    {
        public:
        GeneSplicer(Board& board, City city);
        ~GeneSplicer();

        std::string role() const override
        {
            return "GeneSplicer";
        }

        protected:
        bool discover_cure_throw_cards(Color) override;
    };
}