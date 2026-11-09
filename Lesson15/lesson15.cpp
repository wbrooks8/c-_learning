//
// Created by kyle on 11/5/26.
//

#include "lesson15.h"
#include <iostream>

#include "Random.h"

namespace lesson15 {
    class Monster {
    public:
        enum Type {
            dragon,
            goblin,
            ogre,
            orc,
            skeleton,
            troll,
            vampire,
            zombie,
            maxMonsterTypes,
        };

    private:
        Type m_type{};
        std::string m_name{};
        std::string m_roar{};
        int m_hit_points{};

    public:
        Monster(Type type, const std::string &name, const std::string &roar, int hit_points)
            : m_type{type}, m_name{name}, m_roar{roar}, m_hit_points{hit_points} {
        }

        constexpr std::string_view getTypeString() const {
            switch (m_type) {
                case dragon: return "dragon";
                case goblin: return "goblin";
                case ogre: return "ogre";
                case orc: return "orc";
                case skeleton: return "skeleton";
                case troll: return "troll";
                case vampire: return "vampire";
                case zombie: return "zombie";
                default: return "???";
            }
        }

        void print() const {
            if (m_hit_points > 0) {
                std::cout << m_name << " the " << getTypeString() << " has " << m_hit_points << " hit points and says "
                        << m_roar << "." << std::endl;
            } else {
                std::cout << m_name << " the " << getTypeString() << " is dead." << std::endl;
            }
        }
    };

    namespace MonsterGenerator {

        std::string getName(int i) {
            switch (i) {
                case 0:
                    return "Bonez";
                case 1:
                    return "Phillip";
                case 2:
                    return "Tigre";
                case 3:
                    return "Bob";
                case 4:
                    return "Timmy";
                case 5:
                    return "Van";
                default:
                    return "???";
            }
        }

        std::string getRoar(int i) {
            switch (i) {
                case 0:
                    return "*rattle*";
                case 1:
                    return "*wiggle*";
                case 2:
                    return "*hiss*";
                case 3:
                    return "*bark*";
                case 4:
                    return "*wistle*";
                case 5:
                    return "*wimper*";
                default:
                    return "???";
            }
        }

        Monster generate()
        {
            return Monster{
                static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes-1)),
                getName(Random::get(0,5)),
                getRoar(Random::get(0,5)),
                Random::get(1, 100)
                };
        }

    }

    class Simple {
    private:
        int m_id{};

    public:
        Simple(int id)
            : m_id{id} {
        }

        int getID() const { return m_id; }
        void setID(int id) { m_id = id; }

        void print() const { std::cout << m_id; }
    };


#include <iostream>

    class Date {
    private:
        int m_year{};
        int m_month{};
        int m_day{};

    public:
        Date(int year, int month, int day); // constructor declaration

        void print() const; // print function declaration

        int getYear() const { return m_year; }
        int getMonth() const { return m_month; }
        int getDay() const { return m_day; }
    };

    Date::Date(int year, int month, int day) // constructor definition
        : m_year{year}
          , m_month{month}
          , m_day{day} {
    }

    void Date::print() const // print function definition
    {
        std::cout << "Date(" << m_year << ", " << m_month << ", " << m_day << ")\n";
    };

    int main() {
        const Date d{2015, 10, 14};
        d.print();

        return 0;
    }


    void runLesson() {
        Simple simple{1};
        simple.setID(2);

        simple.print();

        Monster skeleton{Monster::skeleton, "Bones", "*rattle*", 4};
        skeleton.print();

        Monster vampire{Monster::vampire, "Nibblez", "*hiss*", 0};
        vampire.print();

        Monster m{MonsterGenerator::generate()};
        m.print();
    }
} // lesson15
