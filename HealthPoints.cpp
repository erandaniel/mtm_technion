#include "HealthPoints.h"

HealthPoints::HealthPoints(const int maxHp) : 
    m_hp(maxHp), m_maxHp(maxHp)
    {
        if(m_hp <= 0)
        {
            throw HealthPoints::InvalidArgument();
        }
    }

    

    HealthPoints& HealthPoints::operator+=(const HealthPoints& object) 
    {
        m_hp += object.m_hp;
        if(m_hp > m_maxHp) 
        {
            m_hp = m_maxHp;
        } 
        return *this;
    }

    HealthPoints& HealthPoints::operator-=(const HealthPoints& object)
    {
        m_hp -= object.m_hp;
        if(m_hp < 0)
        {
            m_hp = 0;
        }
        return *this;
    }
    //binary ops:
    HealthPoints& operator+(const HealthPoints& hp1, const HealthPoints& hp2)
    {
        HealthPoints updatedHp = hp1;
        return updatedHp += hp2; // using += op
    }

    HealthPoints& operator-(const HealthPoints& hp1, const HealthPoints& hp2)
    {
        HealthPoints updatedHp = hp1;
        return updatedHp -= hp2; // using -= op
    }

    //boolean ops:
    bool operator==(const HealthPoints& object1, const HealthPoints& object2)
    {
        return object1.m_hp == object2.m_hp;
    }

    bool operator>(const HealthPoints& object1, const HealthPoints& object2)
    {
        return object1.m_hp > object2.m_hp;
    }

    bool operator!=(const HealthPoints& object1, const HealthPoints& object2)
    {
        return !(object1 == object2);
    }

    bool operator>=(const HealthPoints& object1, const HealthPoints& object2)
    {
        return (object1 > object2) || (object1 == object2);
    }

    bool operator<=(const HealthPoints& object1, const HealthPoints& object2)
    {
        return (object2 >= object1);
    }

    bool operator<(const HealthPoints& object1, const HealthPoints& object2)
    {
        return (object2 > object1);
    }

    std::ostream& operator<<(std::ostream& output, const HealthPoints& hp)
    {
	    output << hp.m_hp;
	    return output;
    }