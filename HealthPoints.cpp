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
        this.m_hp += object.m_hp;
        if(this.m_hp > m_maxHp) 
        {
            this.m_hp = m_maxHp;
        } 
        return *this;
    }

    HealthPoints& HealthPoints::operator-=(const HealthPoints& object)
    {
        this.m_hp -= object.m_hp;
        if(this.m_hp < 0)
        {
            this.m_hp = 0;
        }
        return *this;
    }


    HealthPoints& operator+(const HealthPoints& hp1, const HealthPoints& hp2)
    {
        HealthPoints tempHp = hp1;
        return tempHp += hp2;
    }

    HealthPoints& operator-(const HealthPoints& hp1, const HealthPoints& hp2)
    {
        HealthPoints tempHp = hp1;
        return tempHp -= hp2;
    }


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