#include <cstring>
#include <iostream>
#include <string>
#include "arduino_string.hpp"

my::String::String()
{
}

my::String::~String()
{
}

my::String::String(const std::string &str)
{
    this->data += str;
}

my::String::String(const my::String &str)
{
    this->data += str.get_data();
}

my::String::String(const char *str)
{
    this->data += std::string(str);
}

my::String::String(const char str)
{
    this->data = std::string(1, str);
}

my::String::String(const char str, CODAGE)
{
    this->data = std::string(1, str);
}

my::String::String(const float nbr, const int i)
{
    std::ostringstream ss;
    ss << nbr;
    this->data = ss.str();
}

my::String::String(const int i)
{
    this->data = std::to_string(i);
}

my::String::String(const int i, CODAGE)
{
    this->data = std::to_string(i);
}

my::String::String(const unsigned int i)
{
    this->data = std::to_string(i);
}

my::String::String(const unsigned int i, CODAGE)
{
    this->data = std::to_string(i);
}

my::String &my::String::operator+(const int &rhs)
{
    this->data += this->to_string(rhs);
    return *this;
}

my::String &my::String::operator+(const unsigned int &rhs)
{
    this->data += this->to_string(rhs);
    return *this;
}

my::String &my::String::operator+(const char &rhs)
{
    this->data += rhs;
    return *this;
}

my::String &my::String::operator+(const std::string &rhs)
{
    this->data += rhs;
    return *this;
}

my::String &my::String::operator+(const char *rhs)
{
    this->data += rhs;
    return *this;
}

my::String &my::String::operator+(const my::String &rhs)
{
    this->data += rhs.get_data();
    return *this;
}

my::String &my::String::operator=(const std::string &rhs)
{
    this->set_data(rhs);
    return *this;
}

my::String &my::String::operator=(const char *rhs)
{
    this->set_data(std::string(rhs));
    return *this;
}

my::String &my::String::operator+=(const unsigned int &rhs)
{
    this->set_data(this->get_data() + std::to_string(rhs));
    return *this;
}

my::String &my::String::operator+=(const std::string &rhs)
{
    this->set_data(this->get_data() + rhs);
    return *this;
}

my::String &my::String::operator+=(const my::String &rhs)
{
    this->set_data(this->get_data() + rhs.get_data());
    return *this;
}

my::String &my::String::operator+=(const char *rhs)
{
    this->set_data(this->get_data() + std::string(rhs));
    return *this;
}

my::String &my::String::operator+=(const int &rhs)
{
    this->set_data(this->get_data() + std::to_string(rhs));
    return *this;
}

my::String my::String::to_string(const int &rhs)
{
    my::String str(std::to_string(rhs));
    return str;
}

my::String my::String::to_string(const unsigned int &rhs)
{
    my::String str(std::to_string(rhs));
    return str;
}

void my::String::concat(const int &i)
{
    this->data += std::to_string(i);
}

void my::String::concat(const unsigned int &i)
{
    this->data += std::to_string(i);
}

std::string my::String::get_data() const
{
    return this->data;
}

void my::String::set_data(const std::string &str)
{
    this->data = str;
}

// https://stackoverflow.com/a/313990/10152334
void my::String::toLowerCase()
{
    std::transform(this->data.begin(), this->data.end(), this->data.begin(), [](unsigned char c) { return std::tolower(c); });
}

// https://stackoverflow.com/a/313990/10152334
void my::String::toUpperCase()
{
    std::transform(this->data.begin(), this->data.end(), this->data.begin(), [](unsigned char c) { return std::toupper(c); });
}

std::ostream &my::String::operator<<(std::ostream &os)
{
    os << this->get_data();
    return os;
}

#warning To do
std::ostream &my::String::operator>>(std::ostream &os)
{
    os << this->get_data();
    return os;
}

bool my::String::equals(const my::String &rhs)
{
    if (this->data.length() == rhs.get_data().length()) {
        if (this->data == rhs.get_data()) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool my::String::equalsIgnoreCase(const my::String &rhs)
{
    return this->data.size() == rhs.get_data().size()
           && std::equal(this->data.begin(), this->data.end(), rhs.get_data().begin(), [](char cA, char cB) { return toupper(cA) == toupper(cB); });
}

int my::String::toInt()
{
    return std::stoi(this->data);
}

int my::String::compareTo(const my::String &rhs)
{
    return this->data.compare(rhs.get_data());
}

bool my::String::operator==(const my::String &rhs)
{
    return this->equals(rhs);
}

bool my::String::operator==(const char *rhs)
{
    if(this->data == rhs)
    {
        return true;
    } else {
        return false;
    }
}

bool my::String::operator!=(const my::String &rhs)
{
    return !this->equals(rhs);
}

bool my::String::operator>=(const my::String &rhs)
{
    if(compareTo(rhs) >= 0) {
        return true;
    } else {
        return false;
    }
}

bool my::String::operator<=(const my::String &rhs)
{
    if(compareTo(rhs) <= 0) {
        return true;
    } else {
        return false;
    }
}

#warning Not
bool my::String::operator>=(const char *rhs)
{
    if (this->data.size() >= std::strlen(rhs)) {
        return true;
    } else {
        return false;
    }
}

bool my::String::operator<=(const char *rhs)
{
    if (this->data.size() <= std::strlen(rhs)) {
        return true;
    } else {
        return false;
    }
}

//#define digitalWrite(pin, value) digitalWrite_standard(pin, value)

/*
template<typename _CharT, typename _Traits, typename _Alloc> void std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::concat(int v)
{

}
*/