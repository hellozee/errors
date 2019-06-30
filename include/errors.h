#ifndef HELLOZEE_ERRORS_H
#define HELLOZEE_ERRORS_H

#include <string>
#include <iostream>

namespace errors {
    class error {
private:
        enum class error_type{
            blank, nil, err
        };
        std::string _e_string;
        error_type _type;
        friend error nil();
public:
        error(std::string error_string)
            : _e_string(error_string), _type(error_type::err)
        { }

        error():
            _e_string(""), _type(error_type::blank)
        { }

        inline std::string what() const { return _e_string; }

        bool operator == (const error &e) const {
            return e._e_string == _e_string && e._type == _type;
        }

        bool operator != (const error &e) const {
            return e._type != _type || e._e_string != _e_string;
        }

    };

    inline error new_error(std::string error_string)
    {
        return error(error_string);
    }

    error nil()
    {
        error e;
        e._type = error::error_type::nil;
        return e;
    }
    
    //this is not what it should look like
    //but for the time, I don't have any idea
    //how to approach so let it be
    void panic(error e)
    {
        if (e != nil()) {
            std::cerr << e.what() << std::endl;
            std::abort();
        }
    }
}

#endif /* ifndef __ERRORS__H */
/* vim: set filetype=cpp: */
