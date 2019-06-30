#ifndef HELLOZEE_ERRORS_H
#define HELLOZEE_ERRORS_H

namespace errors {
class error {
private:
    enum class error_type {
        blank, nil, err
    };
    const char *_e_string;
    error_type _type;
    friend error nil();
public:
    error(const char *error_string)
        : _e_string(error_string), _type(error_type::err)
    { }

    error() :
        _e_string(nullptr), _type(error_type::blank)
    { }

    ~error()
    {
        if (_e_string != nullptr)
            delete _e_string;
    }

    inline const char * what() const
    {
        return _e_string == nullptr ? "" : _e_string;
    }

    bool operator == (const error &e) const
    {
        return e._e_string == _e_string && e._type == _type;
    }

    bool operator != (const error &e) const
    {
        return e._type != _type || e._e_string != _e_string;
    }
};

inline error new_error(const char *error_string)
{
    return error(error_string);
}

error nil()
{
    error e;
    e._type = error::error_type::nil;
    return e;
}
}

#endif /* ifndef HELLOZEE_ERRORS_H */
/* vim: set filetype=cpp: */