#include < iostream >
#include < list >
using namespace std;
//Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого равно среднему арифметическому всех его элементов.


void averageList(list <double>& lst)
{
    list < double > ::const_iterator  p = lst.begin();
    double s(0);
    int n=0;
    while (p != lst.end())
    {
        s = s + *p;
        ++n;
        ++p;
    }
    if (n != 0) lst.push_back(s / n); 
}

//Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по диапазону целых чисел в цикле for - range - based.


template<typename T>
class range_iterator sealed
{
public:
    typedef T range_type;
    typedef range_iterator<range_type> self_type;
    typedef typename range_type::value_type value_type;

    range_iterator(const range_type* const range, value_type start_value)
        : m_range(range), m_value(start_value)
    { }

    operator value_type() const
    {
        return m_value;
    }

    value_type& operator*() {
        return m_value;
    }

    self_type& operator++() {
        m_value += m_range->step();
        return *this;
    }

    self_type operator++(int) {
        self_type tmp(*this);
        ++(*this);
        return tmp;
    }

    bool operator==(const self_type& other) const {
        return ((m_range == other.m_range) &&
            (equals<value_type>(m_value, other.m_value, m_range->step())));
    }

    bool operator!=(const self_type& other) const {
        return !((*this) == other);
    }

private:
    template<typename R> static bool equals(R a, R b, R e) {
        return a == b;
    }

    template<> static bool equals(double a, double b, double e) {
        return std::abs(a - b) < std::abs(e);
    }

    template<> static bool equals(float a, float b, float e) {
        return std::abs(a - b) < std::abs(e);
    }

    const range_type* const m_range;
    value_type m_value;
};

int main()
{
     

    return 0;
}