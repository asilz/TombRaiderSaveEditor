#include <cstddef>
#include <string_view>

template <size_t N> class TemplateString
{
  public:
    char data[N];

    consteval TemplateString(const char (&str)[N])
    {
        for (size_t i = 0; i < N; ++i)
        {
            data[i] = str[i];
        }
    }

    // Explicit buffer construction for concatenation
    consteval TemplateString() = default;

    consteval const char *GetCStr(void) const { return data; }
};

template <std::size_t N> TemplateString(const char (&)[N]) -> TemplateString<N>;

template <size_t N1, size_t N2>
consteval TemplateString<N1 + N2 - 1> operator+(TemplateString<N1> lhs, TemplateString<N1> rhs)
{
    TemplateString<N1 + N2 - 1> result;

    for (size_t i = 0; i < N1 - 1; ++i)
    {
        result[i] = lhs[i];
    }
    for (size_t i = 0; i < N2; ++i)
    {
        result[i + N1 - 1] = rhs[i];
    }

    return result;
}