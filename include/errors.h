#ifndef HELLOZEE_ERRORS_H
#define HELLOZEE_ERRORS_H

#include <utility>

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

template <typename type>
class container {
private:
    error _e;
    type _object;
public:
    container(const type& object, error e) :
        _e(e), _object(object)
    { }

    container(type&& object, error e) :
        _e(e), _object(std::move(object))
    { }

    inline const error& err() const { return _e; }
    inline const type& object() const { return _object; }
};
}

#endif /* ifndef HELLOZEE_ERRORS_H */
/* vim: set filetype=cpp: */
