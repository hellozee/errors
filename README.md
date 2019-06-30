# errors

An idiot's attempt to do a `go` like error handling in `c++`

Really simple library and obviously the code is self documenting, take a look at the examples if you want to use.

Unfortunately there is no install rule but can be used as git submodule in a `cmake` project.

### What inspired me?

Along with `c++`, I also use `go` at least for my personal projects. And I really like how `go` handles errors without the use of any exceptions or such. How does it do that? Simple by using multiple returns, one of which is the error and then we check if the error is nil or not. Like this,

```go
f, err := os.Open("filename.ext")
if err != nil {
    //oops error
}
```

I try to imitate the same thing in `c++`, for example I can write the above example using my library as

```c++
#include <errors.h>
..
..
errors::container<type> result = some_function(param);
if(result.err() != errors::nil()){
    //oops error
}
```

The library is a header only library. 

I try to avoid involving `std::exception` in the library, as well  as the resulting code, it is being used in, but I am not sure if I am able to get that, would be happy if someone could point me out an example where exceptions would involved and if possible can suggest a solution. :smile: