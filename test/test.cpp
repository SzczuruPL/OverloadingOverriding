#include <iostream>

class Class
{
private:
    double d;
    bool b;
    int N;
    int* tab;

public:
    Class(double d, bool b, int N, int* tab);
    Class operator + (const Class& other) const;
    Class operator - (const Class& other) const;
    Class operator * (const Class& other) const;
    Class operator / (const Class& other) const;
    Class& operator ++ (); 
    Class operator ++ (int);
    friend std::ostream& operator<<(std::ostream& os, const Class& obj);
    Class operator = (const Class& other);
    Class operator += (const Class& other);
    bool operator && (const Class& other) const;
    bool operator || (const Class& other) const;
    bool operator !() const;
    bool operator > (const Class& other) const;
    bool operator < (const Class& other) const;
    bool operator == (const Class& other) const;
};

Class::Class(double d, bool b, int N, int* tab)
{
    this->d = d;
    this->b = b;
    this->N = N;
    this->tab = new int[N];
    for (int i = 0; i < N; i++)
    {
        this->tab[i] = tab[i];
    }
}

Class Class::operator+(const Class& other) const
{
    double new_d = d + other.d;
    bool new_b = b || other.b;
    int* new_tab = new int[N + other.N];
    for (int i = 0; i < N; i++)
    {
        new_tab[i] = tab[i];
    }
    for (int i = 0; i < other.N; i++)
    {
        new_tab[N + i] = other.tab[i];
    }
    return Class(new_d, new_b, N + other.N, new_tab);
}

Class Class::operator-(const Class& other) const
{
    double new_d = d - other.d;
    bool new_b = b && !other.b;
    int* new_tab = new int[N];
    for (int i = 0; i < N; i++)
    {
        new_tab[i] = tab[i] - other.tab[i];
    }
    return Class(new_d, new_b, N, new_tab);
}

Class Class::operator*(const Class& other) const
{
    double new_d = d * other.d;
    bool new_b = b && other.b;
    int* new_tab = new int[N];
    for (int i = 0; i < N; i++)
    {
        new_tab[i] = tab[i] * other.tab[i];
    }
    return Class(new_d, new_b, N, new_tab);
}

Class Class::operator/(const Class& other) const
{
    double new_d = d / other.d;
    bool new_b = b || !other.b;
    int* new_tab = new int[N];
    for (int i = 0; i < N; i++)
    {
        new_tab[i] = tab[i] / other.tab[i];
    }
    return Class(new_d, new_b, N, new_tab);
}

Class& Class::operator++()
{
    d++;
    b = !b;
    for (int i = 0; i < N; i++)
    {
        tab[i]++;
    }
    return *this;
}

Class Class::operator++(int)
{
    Class temp(*this);
    operator++();
    return temp;
}

Class Class::operator=(const Class& other)
{
    if (this == &other)
    {
        return *this;
    }
    d = other.d;
    b = other.b;
    N = other.N;
    delete[] tab;
    tab = new int[N];
    for (int i = 0; i < N; i++)
    {
        tab[i] = other.tab[i];
    }
    return *this;
}

Class Class::operator+=(const Class& other)
{
    d += other.d;
    b = b || other.b;
    int new_N = N + other.N;
    int* new_tab = new int[new_N];
    for (int i = 0; i < N; i++)
    {
        new_tab[i] = tab[i];
    }
    for (int i = 0; i < other.N; i++)
    {
        new_tab[N + i] = other.tab[i];
    }
    N = new_N;
    delete[] tab;
    tab = new_tab;
    return *this;
}

bool Class::operator&&(const Class& other) const
{
    return b && other.b;
}

bool Class::operator||(const Class& other) const
{
    return b || other.b;
}

bool Class::operator!() const
{
    return !b;
}

bool Class::operator>(const Class& other) const
{
    if (d > other.d)
        return true;
    else if (d < other.d)
        return false;
    else
    {
        if (b > other.b)
            return true;
        else if (b < other.b)
            return false;
        else
        {
            if (N > other.N)
                return true;
            else if (N < other.N)
                return false;
            else
            {
                for (int i = 0; i < N; i++)
                {
                    if (tab[i] > other.tab[i])
                        return true;
                    else if (tab[i] < other.tab[i])
                        return false;
                }
                return false;
            }
        }
    }
}

bool Class::operator<(const Class& other) const
{
    return !operator>(other) && !operator==(other);
}

bool Class::operator==(const Class& other) const
{
    if (d != other.d)
        return false;
    if (b != other.b)
        return false;
    if (N != other.N)
        return false;
    for (int i = 0; i < N; i++)
    {
        if (tab[i] != other.tab[i])
            return false;
    }
    return true;
}

int main()
{

    return 0;
}