#include <errors.h>
#include <tuple>
#include <iostream>

auto simple_divide(int a, int b)
{
    if (!b) {
        return std::make_tuple(0,
                               errors::new_error("trying to divide by zero"));
        // can be substituted with {0, errors::new_error("trying to divide by zero")}
        // for c++17
    }
    return std::make_tuple(a / b, errors::nil());
    // similarly {a/b, errors::nil()}
}

int main()
{
    auto result = simple_divide(4, 0);
    auto e      = std::get<1>(result);
    if (e != errors::nil()) {
        std::cout << e.what() << std::endl;
    }
}
