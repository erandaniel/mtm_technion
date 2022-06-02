
#include "HealthPoints.h"

HealthPoints::HealthPoints(const int maxHp) : m_hp(maxHp), m_maxHp(maxHp)
{
    if (m_hp <= 0)
    {
        throw HealthPoints::InvalidArgument();
    }
}

HealthPoints& HealthPoints::operator+=(const int hpToAdd)
{
    this->m_hp += hpToAdd;
    if (this->m_hp > m_maxHp)
    {
        this->m_hp = m_maxHp;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(const int hpToSubtract)
{
    this->m_hp -= hpToSubtract;
    if (this->m_hp < 0)
    {
        this->m_hp = 0;
    }
    return *this;
}

HealthPoints& HealthPoints::operator+(const int hpToAdd)
{
    return *this += hpToAdd;
}

HealthPoints& operator+(const int hpToAdd, HealthPoints &object)
{
    return object += hpToAdd; //using += operator from above
}

HealthPoints &HealthPoints::operator-(const int hpToSubtract)
{
    HealthPoints tempObject = *this;
    return tempObject -= hpToSubtract;
}

bool operator==(const HealthPoints &object1, const HealthPoints &object2)
{
    return object1.m_hp == object2.m_hp;
}

bool operator>(const HealthPoints &object1, const HealthPoints &object2)
{
    return object1.m_hp > object2.m_hp;
}

bool operator!=(const HealthPoints &object1, const HealthPoints &object2)
{
    return !(object1 == object2);
}

bool operator>=(const HealthPoints &object1, const HealthPoints &object2)
{
    return (object1 > object2) || (object1 == object2);
}

bool operator<=(const HealthPoints &object1, const HealthPoints &object2)
{
    return (object2 >= object1);
}

bool operator<(const HealthPoints &object1, const HealthPoints &object2)
{
    return (object2 > object1);
}


std::ostream &operator<<(std::ostream &output, const HealthPoints &hp)
{
    output << hp.m_hp;
    return output;
}
