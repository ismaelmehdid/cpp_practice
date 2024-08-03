#pragma once

#include "AForm.hpp"

#include <string>

class Intern
{
    public:
        Intern();
        ~Intern();
        AForm *makeForm(const std::string &form, const std::string &target);
};
