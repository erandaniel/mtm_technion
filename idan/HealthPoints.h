#include <iostream>
#include <string>

const int DEFAULT_MAX_HP = 100

class HealthPoints
{

public:

    /**
     * C'tor of HealthPoints class
     *
     * @param maxHp - The maximum HP (and the current HP)
     * @return
     *      A new instance of HealthPoints
     */
    explicit HealthPoints(const int maxHp = DEFAULT_MAX_HP);

    /**
     *
     * Addition and assignment operator of HealthPoints class
     *
     * @param hpToAdd - the amount of HP that will be added to HealthPoints
     * @return
     *      A reference to HealthPoints object
     */
    HealthPoints &operator+=(const HealthPoints &hpToAdd);

    /**
     *
     * Subtraction and assignment operator of HealthPoints class
     *
     * @param hpToSubtract - the amount of HP that will be subtracted from HealthPoints
     * @return
     *      A reference to HealthPoints object
     */
    HealthPoints &operator-=(const HealthPoints &hpToSubtract);

    /**
     * 'Equal To' operator of HealthPoints class
     *
     * @param object1 - the object we want to compare to
     * @param object2 - the object we want compared
     * @return
     *      true - if objects are equal, false - if object are different
     */
    friend bool operator==(const HealthPoints &object1, const HealthPoints &object2);

    /**
     * 'Greater-than' operator of HealthPoints class
     *
     * @param object1 - the object we want to compare to
     * @param object2 - the object we want compared
     * @return
     *      true - if object1 is greater than object2
     *      false - if object1 is not greater than object2
     */
    friend bool operator>(const HealthPoints &object1, const HealthPoints &object2);

    /**
     * 'Stream-insertion' operator of HealthPoints class
     * 
     * @param output - stream to send
     * @param hp - hp to send to ostream
     * @return  
     *      A reference to std::ostream after it has been changed
     */
    friend std::ostream &operator<<(std::ostream output, const HealthPoints &hp);
    
    class InvalidArgument{};

private:
    int m_hp;
    int m_maxHp;
};

/**
 * 'Addition' operator of HealthPoints class
 * 
 * @param object1 - first object we want to add
 * @param object2 - second object we want to add
 * @return 
 *      A reference to HealthPoints object(sum of other two)
 */
HealthPoints &operator+(const HealthPoints &object1, const HealthPoints &object2);

/**
 * 'Subtraction' operator of HealthPoints class
 * 
 * @param object1 - object we want to subtract from
 * @param object2 - object we want to subtract from first object
 * @return 
 *      A reference to HealthPoints object(what's left from the subtraction)
 */

HealthPoints &operator-(const HealthPoints &object1, const HealthPoints &object2);

/**
 * 'Not-equal-to' operator of HealthPoints class
 *
 * @param object1 - the object we want to compare to
 * @param object2 - the object we want compared
 * @return
 *      true - if objects are different, false - if object are equal
 */
bool operator!=(const HealthPoints &object1, const HealthPoints &object2);

/**
 * 'Greater-than or Equal-to' operator of HealthPoints class
 *
 * @param object1 - the object we want to compare to
 * @param object2 - the object we want compared
 * @return
 *      true - if object1 is greater than or equal to object2
 *      false - if object1 is not greater than nor is equal object2
 */
bool operator>=(const HealthPoints &object1, const HealthPoints &object2);

/**
 * 'Less-than or Equal-to' operator of HealthPoints class
 *
 * @param object1 - the object we want to compare to
 * @param object2 - the object we want compared
 * @return
 *      true - if object1 is lesser than or equal to object2
 *      false - if object1 is not lesser than nor is equal object2
 */
bool operator<=(const HealthPoints &object1, const HealthPoints &object2);

/**
 * 'Less-than' operator of HealthPoints class
 *
 * @param object1 - the object we want to compare to
 * @param object2 - the object we want compared
 * @return
 *      true - if object1 is lesser than object2
 *      false - if object1 is not lesser than object2
 */
bool operator<(const HealthPoints &object1, const HealthPoints &object2);