#include <stdarg.h>
#include <string>
#include <tuple>


/**
 * By the LoggerArg templates it is possible to wrap the arguments,
 * so that also C++ types can be passed.
 *
 * The default template covers the default types (int for %d format, char* for %s format, ...)
 */
template <typename T>
T LoggerArg(T value) noexcept
{
  return value;
}

/**
 * The string template allowes to specify also std::string for %s format.
 */
template <typename T>
T const * LoggerArg(std::basic_string<T> const & value) noexcept
{
  return value.c_str();
}

int LOG_ERR = 1;
int LOG_WARNING = 1;
int LOG_INFO = 1;

class Logger
{
public:

    template <typename ... Args>
    static void error(char const * const format, Args const& ... args) noexcept {
        log(LOG_ERR, format, args ...);
    }

    template <typename ... Args>
    static void warning(char const* const format, Args const& ... args) noexcept {
        log(LOG_WARNING, format, args ...);
    }

    template <typename ... Args>
    static void info(char const * const format, Args const& ... args) noexcept {
        log(LOG_INFO, format, args ...);
    }

private:

    template <typename ... Args>
    static void log(int severity, char const * const format, Args const& ... args) noexcept {
        std::tuple<Args...> t(args...);
        int n = std::tuple_size_v<decltype(t)>;

        if (n == 0) {
            printf("%s", format);
        }
        else
        {
            printf(format, LoggerArg(args) ...);
        }
        printf("\n");
    }

    static std::string _ident;
    static bool _toStdout;
};

int main(int argc, char const *argv[])
{
    Logger out;
    std::string name = "abc";
    out.error("hello world");
    out.error("hello world, %d, %d, %s", 1, 11, name);
    return 0;
}
