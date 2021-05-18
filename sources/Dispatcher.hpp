#pragma once

#include "Player.hpp"

namespace pandemic
{
    class Dispatcher : public Player
    {
        public:
        Dispatcher(Board&, City);
        ~Dispatcher();

        std::string role() const override
        {
            return "Dispatcher";
        }

        Player& fly_direct(City) override;
    };
}