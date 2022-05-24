#include <iostream>
#include <string>

#define DEFAULT_MAX_HP = 100

class HealthPoints
{

public:
    HealthPoints(const int maxHp = DEFAULT_MAX_HP);

    HealthPoints& operator+=(const HealthPoints& hpToAdd);
    HealthPoints& operator-=(const HealthPoints& hpToSubtract);

    //must be 'friend' to access values inside
    friend bool operator==(const HealthPoints& object1, const HealthPoints& object2);
    friend bool operator>(const HealthPoints& object1, const HealthPoints& object2);
    
    friend std::ostream& operator<<(std::ostream output, const HealthPoints& hp);

private:
    int m_hp;
    int m_maxHp;
};
//no need to be in HealthPoints because uses += and -= operators
HealthPoints& operator+(const HealthPoints& object1, const HealthPoints& object2);
HealthPoints& operator-(const HealthPoints& object1, const HealthPoints& object2);

//no need to be in HealthPoints because uses == and > operators
bool operator!=(const HealthPoints& object1, const HealthPoints& object2);
bool operator>=(const HealthPoints& object1, const HealthPoints& object2);
bool operator<=(const HealthPoints& object1, const HealthPoints& object2);
bool operator<(const HealthPoints& object1, const HealthPoints& object2);