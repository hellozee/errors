#ifndef HELLOZEE_ERRORS_H
#define HELLOZEE_ERRORS_H

#include <utility>
#include <iostream>

namespace errors {

enum class error_type {
    blank, nil, err
};

inline std::ostream& operator<<(std::ostream & out, error_type ge) {
  switch (ge) {
   case error_type::nil: return out << "nil";
   case error_type::err: return out << "err";
   case error_type::blank: return out << "blank";
    default: return out << (int) ge;
  }
}

// for easier comparison
const error_type nil = error_type::nil;
const error_type err = error_type::err;

class error {
private:
    const char *_e_string;
    error_type _type;
public:
    error(const char *error_string)
        : _e_string(error_string), _type(error_type::err)
    { }

    error() :
        _e_string(nullptr), _type(error_type::nil)
    { }

    inline const char * what() const
    {
        return _e_string == nullptr ? "" : _e_string;
    }

    // comparisons
    bool operator == (const error &e) const
    {
        return e._e_string == _e_string && e._type == _type;
    }

    bool operator != (const error &e) const
    {
        return e._type != _type || e._e_string != _e_string;
    }

   	bool operator==(const error_type& inp) const {
   		return _type == inp;
   	}

   	bool operator!=(const error_type& inp) const {
   		return _type != inp;
   	}

    // printing
    friend std::ostream& operator<<(std::ostream& out, const error& e);
};

std::ostream& operator<<(std::ostream& out, const error& e) {
 out << e._type << " " << e._e_string;
 return out;
}

inline error new_error(const char *error_string)
{
    return error(error_string);
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

    // comparisons
   	bool operator==(const error& inp) const {
   		return _e == inp;
   	}

   	bool operator!=(const error& inp) const {
   		return _e != inp;
   	}

    bool operator==(const error_type& inp) const {
      return _e._type == inp;
    }

    bool operator!=(const error_type& inp) const {
      return _e._type != inp;
    }

    // printing
    template<typename R>
    friend std::ostream& operator<<(std::ostream& out, const container<R>& r);


};

template<typename R>
std::ostream& operator<<(std::ostream& out, const container<R>& r) {
  out << r._e << "\t";
  out << r._object;
  return out;
}


}

#endif /* ifndef HELLOZEE_ERRORS_H */
/* vim: set filetype=cpp: */
