#include <array>
#include <cmath>
#include <exception>
#include <format>
#include <functional>
#include <iostream>
#include <numeric>
#include <print>
#include <ranges>
#include <regex>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>


/************************ START FORMAT *******************************/
// template <typename T>
// struct Point3D {
//     T x;
//     T y;
//     T z;
// };

// template <typename T>
// struct std::formatter<Point3D<T>> : std::formatter<std::string_view> {
//     // VERSION 1 is better in most cases unless you want to inherit parse() behavior for format specifiers (:>5)
//     /**** VALID VERSION 1 ****/
//     // auto format(const Point3D<T>& point, std::format_context& ctx) const {
//     //     return std::format_to(ctx.out(), "x: {}, y: {}, z: {}", point.x, point.y, point.z);
//     // }
//     /**** VALID VERSION 2 ****/
//     // auto format (const Point3D<T>& point, std::format_context& ctx) const {
//     //     return std::formatter<std::string_view>::format(
//     //         std::format("x: {}, y: {}, z: {}", point.x, point.y, point.z), ctx
//     //     );
//     // }
// };


/// If you want to make your own format specifiers, you don't need to inherit from a formatter and you use parse to get the format specifiers
// template <typename T>
// struct std::formatter<Point3D<T>> {

//     bool verbose = false;

//     constexpr auto parse(std::format_parse_context& ctx) {
//         // if (!std::is_constant_evaluated()) {
//         if !consteval {
//             std::string spec{ctx.begin(), ctx.end()};
//             std::println("{}", spec);
//         }

//         auto it = std::begin(ctx);

//         for (; it != std::end(ctx); ++it) {
//             switch (*it) {
//                 case '}':
//                     return it;
//                 case 'v':
//                     verbose = true;
//                     break;
//                 default:
//                     continue;
//             }
//         }

//         return it;
//     }

//     auto format(const Point3D<T>& point, std::format_context& ctx) const {
//         if (verbose) {
//             return std::format_to(ctx.out(), "x: {}, y: {}, z: {}", point.x, point.y, point.z);
//         } else {
//             return std::format_to(ctx.out(), "{}, {}, {}", point.x, point.y, point.z);
//         }
//     }
// };
/************************ END FORMAT *******************************/

/************************ START RANDOM SHIT *******************************/
// Works without this in C++20 but will fail to compile in C++17
// template <typename T>
// Point3D(T x, T y, T z) -> Point3D<T>;

// template <typename T>
// class D2Array {
//     private:
//         T** array;
//         size_t size_x;
//         size_t size_y;

//     public:
//         D2Array(size_t size_x, size_t size_y, T default_data) : size_x(size_x), size_y(size_y) {
//             array = new T* [size_x];
//             if (!array) {
//                 throw std::runtime_error("Fucked up");
//             }

//             for (auto i{0uz}; i < size_x; i++) {
//                 array[i] = new T[size_y];
//                 if (!array[i]) {
//                     throw std::runtime_error("You fucked up again");
//                 }

//                 for (auto j{0uz}; j < size_y; ++j) {
//                     array[i][j] = default_data;
//                 }
//             }
//         }

//         D2Array(size_t size, T default_data) : D2Array(size, size, default_data) { }

//         size_t size() const { return size_x * size_y; }
//         const T* const* const_data() const { return array; }
//         T** data() const { return array; }

//         T* operator[](const size_t x) {
//             std::println("Called non-const operator[x]");
//             if (x >= size_x) {
//                 throw std::runtime_error("x too large for size_x, you're a bitch");
//             }
//             return array[x];
//         }

//         const T* operator[](const size_t x) const {
//             std::println("Called const operator[x]");
//             if (x >= size_x) {
//                 throw std::runtime_error("x too large for size_x, you're a bitch");
//             }
//             return array[x];
//         }

//         T& operator[](const size_t x, const size_t y) {
//             std::println("Called non-const operator [x, y]");
//             if (x >= size_x || y >= size_y) {
//                 throw std::runtime_error("x or y too large for size_x and size_y, you're a bitch 2x");
//             }
//             return array[x][y];
//         }

//         const T& operator[](const size_t x, const size_t y) const {
//             std::println("Called const operator [x, y]");
//             if (x >= size_x || y >= size_y) {
//                 throw std::runtime_error("x or y too large for size_x and size_y, you're a bitch 2x");
//             }
//             return array[x][y];
//         }
// };
/************************ END RANDOM SHIT *******************************/

/************************ START FUNCTIONS *******************************/
// struct IsPositive {
//     template <typename T>
//     bool operator()(const T n) const { return n > 0; }
// };

// template <typename T, std::size_t S>
// std::array<T, S> make_array() {
//     return std::array<T, S>{};
// }
// constexpr std::size_t size = 10;

// template <typename T>
// struct Minimum {
//     constexpr T operator()(T a, T b) {
//         return a <= b ? a : b;
//     }
// };

// template <typename T>
// struct Maxmimum {
//     constexpr T operator()(T a, T b) {
//         return a >= b ? a : b;
//     }
// };

// template <typename T, template <typename> typename M>
// T trimin(T a, T b, T c) {
//     return M<T>{}(a, M<T>{}(b, c));
// }

// template <typename T, template <typename> typename M>
// constexpr T xmin(T a, T b) {
//     if !consteval {
//         std::cout << __PRETTY_FUNCTION__ << std::endl;
//     }
//     return M<T>{}(a, b);
// }

// template <typename T, template <typename> typename M, typename... Args>
// constexpr T xmin(T a, Args&&... args) {
//     if !consteval {
//         std::cout << __PRETTY_FUNCTION__ << std::endl;
//     }
//     return M<T>{}(a, xmin<T, M>(args...));
// }

// template <typename... Args>
// constexpr auto add_pack(Args&&... args) {
//     return (... + args);
//     // return (1 + ... + args);
//     // return (args + ...);
//     // return (args + ... + 1);
//     // return (1 + ... + args + 1);
//     // return (1 + args + ... + 1);
// }

// template <typename... Args>
// void print_types(auto&&... args) {
// // void print_types(Args&&... args) {
//     ((std::println("{}: {}", typeid(args).name(), args)), ...);
// }

template <typename F, typename R>
 R mapf(F&& func, R range) {
    std::transform(
        std::begin(range),
        std::end(range),
        std::begin(range),
        std::forward<F>(func)
    );
    return range;
}

template <typename F, typename R>
void mapfr(F&& func, const R& range) {
    std::transform(
        std::begin(range),
        std::end(range),
        std::begin(range),
        std::forward<F>(func)
    );
}

template <typename F, typename R>
auto fold_left(F&& func, const R& range, const auto init) {
    return std::accumulate(
        std::begin(range),
        std::end(range),
        init);
}

template <typename F, typename G>
auto compose(F&& f, G&& g) {
    return [=](auto x) { return f(g(x)); };
}

template <typename F, typename... R>
auto compose(F&& f, R&&... r) {
    return [=](auto x) { return f(compose(r...)(x)); };
}

// template <typename T = double>
// struct fround {
//     // typename std::enable_if<std::is_floating_point_v<T>, T>::type
//     std::enable_if_t<std::is_floating_point_v<T>, T>
//     operator()(const T& value) const {
//         return std::round(value);
//     }
// };

// template <typename T = double>
// struct fround {
//     // T operator()(const T& value) const
//     //     requires std::floating_point<T> {
//     //         return std::round(value);
//     //     }

//     // T operator()(const T& value) const
//     //     requires std::integral<T> {
//     //         return value;
//     //     }

//     // ORRRRRR

//     // T operator()(const T& value) const {
//     //     if constexpr(std::floating_point<T>) {
//     //         return std::round(value);
//     //     } else {
//     //         return value;
//     //     }
//     // }
// };

// template <typename T>
// T sum(T a) {
//     return a;
// }

// template <typename T, typename... Args>
// T sum(T a, Args... args) {
//     return a + sum(args...);
// }

// constexpr std::size_t fib(const int n) {
//     if (n <= 1) {
//         return n;
//     }

//     auto prev{0uz};
//     auto curr{1uz};

//     for (auto i{2uz}; i <= n; ++i) {
//         auto next{prev + curr};
//         prev = curr;
//         curr = next;
//     }

//     return curr;
// }

// constexpr int fib(const int n) {
//     return n <=2 ? 1 : fib(n - 1) + fib (n - 2);
// }



/************************ END FUNCTIONS *******************************/

int main(int argc, char* argv[]) {
    using namespace std::string_literals;

    /************************ START RANDOM SHIT *******************************/
    // Point3D p{0, 1, 2};
    // D2Array arr{3uz, 12uz};
    // arr[0, 0] = 10;
    // auto d = arr.const_data();
    // d[0][0] = 10uz;
    // auto& val = arr[0, 1];
    // const auto& carr = arr;
    // const auto& cval = carr[0, 1];
    // const auto& carr1 = carr[0];
    // const auto* val1 = arr[0];
    // val = 10;
    // std::println("arr[0, 1] = {}", cval);
    // std::println("arr[0, 0] = {}", arr[0, 0]);
    // std::vector vec2d(2, std::vector(2, 3));
    // std::println("vec2d[0, 0] = {}", vec2d[0, 0]);
    /************************ END RANDOM SHIT *******************************/

    /************************ START REGEX *******************************/
    // std::smatch results{};
    // auto pattern = R"(([A-Z0-9._%+-]+)@([A-Z0-9.-]+)\.([A-Z]{2,}))"s;
    // auto text = "JOHN.DOE@DOMAIN.COM\nJOHN.DOE@DOMAIN.COM"s;
    // auto rx = std::regex {pattern, std::regex_constants::icase};
    // auto found = std::regex_search(text, results, rx);
    // std::print("Found {}:", found);
    // for (const auto& result: results) {
    //     std::print(" {}", result.str());
    // }
    // std::println();
    /************************ END REGEX *******************************/

    /************************ START FORMAT *******************************/
    // Point3D p{0, 1, 2};
    // std::println("{:v}", p);
    // std::println("{}", p);
    /************************ END FORMAT *******************************/

    /************************ START FUNCTIONS *******************************/
    // auto ispositive = [](const auto n) { return n > 0; };
    // const std::vector<int> numbers = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    // auto positives = std::count_if(std::begin(numbers), std::end(numbers), IsPositive{});
    // auto positives = std::count_if(std::begin(numbers), std::end(numbers), ispositive);
    // std::println("{}", positives);

    // auto get_next_number = [count = 0]() mutable { return ++count; };
    // std::println("{} {} {}", get_next_number(), get_next_number(), get_next_number()); // 3 2 1 because fuck ass C++

    // auto lsum = [](const auto s, const auto n) { return s + n; };
    // auto output = lsum("hello", 1);
    // std::println("{}", output);

    // auto lsum = [](const auto s, const decltype(s) n) { std::println("The type of n is {}", typeid(n).name()); return s + n; };
    // auto output = lsum("hello"s, "hello");
    // auto output = lsum(0uz, 10);
    // std::println("{}", output);

    // Default implementation - Try this later with consteval
    // constexpr int fib(const int n) {
    //     return n <=2 ? 1 : fib(n - 1) + fib (n - 2);
    // }
    // C++ 11
    // std::function<int(const int)> lfib = [&lfib](const int n) {
    //     return n <=2 ? 1 : lfib(n - 1) + lfib (n - 2);
    // };
    // std::println("{}", lfib(10));
    // C++14
    // Won't compile without the trailing return type unless you split out the ternary to if/else
    // auto lfib = [](auto f, const int n) -> int {
    //     return  n<=2 ? 1: f(f, n - 1) + f(f, n -2);
    // };
    // std::println("{}", lfib(lfib, 10));
    // C++ 23
    // auto rfib = [](this const auto& self, int n) -> int { // Try to compile without the trailing return type
    //     return n <= 2 ? 1 : self(n - 1) + self(n - 2);
    // };
    // auto lfib = [](this const auto& self, int n) {
    //     if (n <= 2) return 1;
    //     return self(n - 1) + self(n - 2);
    // };
    // std::println("{}", rfib(10));
    // std::println("{}", lfib(10));

    // auto arr = make_array<int, size>();
    // for (const auto& val: arr) {
    //     std::println("{}", val);
    // }

    // auto out = trimin<int, Minimum>(10, 5, 30);
    // std::println("{}", out);

    // std::println("{}", sum(1, 2, 3, 4, 5));
    // constexpr auto value = fib(30);
    // std::println("{}", value);

    // std::println("{}", xmin<int, Maxmimum>(1, 2, 3, 4, 5, 0));
    // auto output = xmin<int, Maxmimum>(1, 2, 3, 4, 5, 0);
    // static_assert(output == 5);
    // std::println("{}", output);
    // std::println("{}", add_pack(1, 2, 3, 4, 5));
    // print_types(1, "hi", "hi"s, 1.f, 1., ((void*)0), nullptr);

    // auto amounts = std::array<double, 5> {10.42, 2.50, 100.0, 23.75, 12.99};
    // auto a = mapf(fround<>(), amounts);
    // auto a = mapf([](const auto& val) { return std::round(val); }, amounts);
    // for (const auto& val: a) {
    //     std::print("{} ", val);
    // }
    // for (const auto [i, val] : std::views::enumerate(a)) {
    //     if (i > 0) {
    //         std::print(" ");
    //     }

    //     std::print("{}", val);
    // }
    // std::println();

    auto functor = compose(
        [](const auto val) { return std::to_string(val); },
        [](const auto val) { return val * val; }
    );
    std::vector<int> v = {1, 2, 3, 4, 5, 6};
    std::for_each(std::begin(v), std::end(v), [&](const auto x){ std::println("{}", functor(x)); });

    auto s = compose(
        [](const auto& v) { std::println("{}", v); return fold_left(std::plus<>(), v, 0); },
        [](const auto& v) { std::println("{}", v); return mapf([](const auto i) { return i + i; }, v); },
        [](const auto& v) { std::println("{}", v); return mapf([](const auto i) { return i * i; }, v); }
    )(v);
    std::println("{}", s);
    /************************ END FUNCTIONS *******************************/

    return 0;
}
