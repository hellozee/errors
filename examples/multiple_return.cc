#include <errors.h>
#include <stdio.h>

auto simple_divide(int a, int b)
{
    if (!b) {
        return errors::container<double>(0,
                               errors::new_error("trying to divide by zero"));
        // can be substituted with {0, errors::new_error("trying to divide by zero")}
        // for c++17
    }
    return errors::container<double>(a / b, errors::nil());
    // similarly {a/b, errors::nil()}
}

int main()
{
    auto result = simple_divide(4, 0);
    if (result.err() != errors::nil()) {
        printf("%s\n", result.err().what());
    }
}
