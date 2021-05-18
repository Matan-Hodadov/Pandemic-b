#pragma once
    
#include "Player.hpp"

namespace pandemic
{
    class OperationsExpert : public Player
    {
        public:
        OperationsExpert(Board& board, City city);
        ~OperationsExpert();

        std::string role() const override
        {
            return "OperationsExpert";
        }

        Player& build() override;
    };
}