#pragma once

#include "Player.hpp"

namespace pandemic
{
    class FieldDoctor : public Player
    {   
        public:
        FieldDoctor(Board& board, City city);
        ~FieldDoctor();

        std::string role() const override
        {
            return "FieldDoctor";
        }

        protected:
        bool can_treat(City city) override;
    };
}