#include <concepts>
#include <iostream>

#if (defined(_LIBCPP_STD_VER) && _LIBCPP_STD_VER > 17) || (_MSC_VER > 1700)
template<typename Number>
    requires std::integral<Number>
#else
/**
 * @brief Fallback for older cpp versions 
 * 
 */
typedef int Number ; 
#endif
class Range
{
    Number cursor;
    Number min, max;
public:
    Range(Number from, Number to): cursor(from), min(from), max(to)
    {}

    Range(Number count): cursor(0), min(0), max(count) 
    {}

    Range begin() const
    {
        return Range(min, max);
    }

    Range end() const
    {
        Range temp(min, max);
        temp.cursor = max;

        return temp;
    }

    bool operator !=(Range& other)
    {
        return this->min != other.min 
            || this->max != other.max 
            || this-> cursor <= other.cursor;
    } 

    void operator ++()
    {
        this->cursor += 1;
    }

    int operator *()
    {
        return this->cursor;
    }

    friend std::ostream& operator<<(std::ostream &stream, Range var);
};