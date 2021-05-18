#include "Board.hpp"
#include <ostream>
#include <fstream>
#include <algorithm>

#include "City.hpp"
#include "Color.hpp"

using namespace pandemic;
using namespace std;

namespace pandemic
{
    // unordered_map<City, unordered_set<City>> Board::cities_connections;
    // unordered_map<City, Color> Board::cities_colors;

    const unordered_map<string, Color> Board::colors_names = {
        {"Black", Color::Black},
        {"Blue", Color::Blue},
        {"Red", Color::Red},
        {"Yellow", Color::Yellow},
    };
    const unordered_map<string, City> Board::cities_names = {
        {"Algiers", City::Algiers},
        {"Atlanta", City::Atlanta},
        {"Baghdad", City::Baghdad},
        {"Bangkok", City::Bangkok},
        {"Beijing", City::Beijing},
        {"Bogota", City::Bogota},
        {"BuenosAires", City::BuenosAires},
        {"Cairo", City::Cairo},
        {"Chennai", City::Chennai},
        {"Chicago", City::Chicago},
        {"Delhi", City::Delhi},
        {"Essen", City::Essen},
        {"HoChiMinhCity", City::HoChiMinhCity},
        {"HongKong", City::HongKong},
        {"Istanbul", City::Istanbul},
        {"Jakarta", City::Jakarta},
        {"Johannesburg", City::Johannesburg},
        {"Karachi", City::Karachi},
        {"Khartoum", City::Khartoum},
        {"Kinshasa", City::Kinshasa},
        {"Kolkata", City::Kolkata},
        {"Lagos", City::Lagos},
        {"Lima", City::Lima},
        {"London", City::London},
        {"LosAngeles", City::LosAngeles},
        {"Madrid", City::Madrid},
        {"Manila", City::Manila},
        {"MexicoCity", City::MexicoCity},
        {"Miami", City::Miami},
        {"Milan", City::Milan},
        {"Montreal", City::Montreal},
        {"Moscow", City::Moscow},
        {"Mumbai", City::Mumbai},
        {"NewYork", City::NewYork},
        {"Osaka", City::Osaka},
        {"Paris", City::Paris},
        {"Riyadh", City::Riyadh},
        {"SanFrancisco", City::SanFrancisco},
        {"Santiago", City::Santiago},
        {"SaoPaulo", City::SaoPaulo},
        {"Seoul", City::Seoul},
        {"Shanghai", City::Shanghai},
        {"StPetersburg", City::StPetersburg},
        {"Sydney", City::Sydney},
        {"Taipei", City::Taipei},
        {"Tehran", City::Tehran},
        {"Tokyo", City::Tokyo},
        {"Washington", City::Washington},
    };

    Board::Board()
    {
        if (!(this->cities_connections.empty()))  //if this is not the first board
        {
            return;
        }
        ifstream ifs{"cities_map.txt"};

        string city_string;
        string color_string;
        string temp_neighbor_string;

        while (!ifs.eof())
        {
            ifs >> city_string >> color_string;
            City city = string_to_city(city_string);
            this->city_diseaselvl[city] = 0;
            cities_colors[city] = string_to_color(color_string);

            while (ifs.peek() != '\n' && !(ifs.eof()))
            {
                ifs >> temp_neighbor_string;
                this->cities_connections[city].insert(string_to_city(temp_neighbor_string));
            }
        }
        ifs.close();
    }

    int& Board::operator [] (City city)
    {
        return this->city_diseaselvl[city];
    }

    ostream& operator << (ostream& os, Board& board)
    {
        // os << boolalpha << endl;
        os << "Cities details:" << endl;
        for (auto city_diseaselvl_row : board.city_diseaselvl)
        {
            City city = city_diseaselvl_row.first;

            os << Board::city_to_string(city) << endl;
            os << "Infection Level: " << city_diseaselvl_row.second << endl;
            if(board.have_research_station(city))
            {
                os << "Have A research station" << endl;
            }
            else
            {
                os << "Dont have a research station" << endl;
            }
        }
        os << "\nDiscovered Cures:" << endl;
        for (auto color_cure : board.city_medicine)
        {
            os << Board::color_to_string(color_cure) << endl;
        }
        os << endl;
        return os;
    }

    bool Board::have_research_station(City city) const
    {
        // if(this->city_station.find(city) != this->city_station.end())
        // {
        //     return true;
        // }
        // return false;
        return this->city_station.find(city) != this->city_station.end();
    }

    Color Board::get_city_color(City city) const
    {
        return this->cities_colors.at(city);
        // if(this->cities_colors.find(city) != this->cities_colors.end())
        // {
        //     return this->cities_colors.at(city);
        // }
        // return;
    }

    bool Board::is_cities_connected(City city1, City city2) const
    {
        auto connected_cities = this->cities_connections.at(city1);
        // if(connected_cities.find(city2) == connected_cities.end())
        // {
        //     return false;
        // }
        // return true;
        return connected_cities.find(city2) != connected_cities.end();
    }

    void Board::add_research_station(City city)
    {
        this->city_station.insert(city);
    }

    bool Board::have_cure(Color color) const
    {
        // if(this->city_medicine.find(color) == this->city_medicine.end())
        // {
        //     return false;
        // }
        // return true;
        return this->city_medicine.find(color) != this->city_medicine.end();
    }

    void Board::add_cure(Color color)
    {
        this->city_medicine.insert(color);
    }


    City Board::string_to_city(const string& city)
    {
        return cities_names.find(city)->second;
    }
    string Board::city_to_string(City city)
    {
        return find_if(begin(Board::cities_names), end(Board::cities_names), [&](const auto &element) {
                return element.second == city;
            })
            ->first;
    }
    Color Board::string_to_color(const string& color_name)
    {
        return colors_names.find(color_name)->second;
    }
    string Board::color_to_string(Color color)
    {
        return find_if(begin(Board::colors_names), end(Board::colors_names), [&](const auto &element) {
                return element.second == color;
            })
            ->first;
    }

    bool Board::is_clean()
    {
        // for(int i = 0; i < 48;i++)
        // {
        //     if (this->city_diseaselvl[(City)i] > 0)
        //     {
        //         return false;
        //     }
        // }   
        for(auto city_desease_row : this->city_diseaselvl)
        {
            if(city_desease_row.second > 0)
            {
                return false;
            }    
        }
        return true;
    }

    void Board::remove_cures()
    {
        this->city_medicine.clear();
    }
}