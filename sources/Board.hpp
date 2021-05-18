#pragma once

#include <ostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Board
    {
        private:
        std::unordered_map<City, int> city_diseaselvl;
        std::unordered_set<City> city_station;
        std::unordered_set<Color> city_medicine;
        std::unordered_map<City, std::unordered_set<City>> cities_connections;
        std::unordered_map<City, Color> cities_colors;
        // static std::unordered_map<City, std::unordered_set<City>> connections;
        // static std::unordered_map<City, Color> cities_colors;

        //for constractor
        const static std::unordered_map<std::string, Color> colors_names;
        const static std::unordered_map<std::string, City> cities_names;

        public:
        Board();
        int& operator [] (City city);
        friend std::ostream& operator << (std::ostream& os, Board& board);
        // friend std::ostream& operator << (std::ostream& os, use 'this' instead);
        bool have_research_station(City city) const;
        Color get_city_color(City city) const;
        bool is_cities_connected(City, City) const;
        void add_research_station(City);
        bool have_cure(Color) const;
        void add_cure(Color);

        static City string_to_city(const std::string&);
        static std::string city_to_string(City);
        static Color string_to_color(const std::string&);
        static std::string color_to_string(Color);

        bool is_clean();
        void remove_cures();
    };
}
