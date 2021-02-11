#ifndef __COMPOSE
#define __COMPOSE

#include <utility>
#include <tuple>

template<int index, typename Callback, typename... Args>
struct iterate_tuple
{
	static void next(std::tuple<Args...>& t, Callback& callback)
	{
		// Decrementing position and recursive calling same method
		iterate_tuple<index - 1, Callback, Args...>::next(t, callback);

		// Call handler (position, function)
		callback(index, std::get<index>(t));

	}
};

// Partial specialization for the index 0 (end of the recursion)
template<typename Callback, typename... Args>
struct iterate_tuple<0, Callback, Args...>
{
	static void next(std::tuple<Args...>& t, Callback& callback)
	{
		callback(0, std::get<0>(t));
	}
};

template<typename T>
struct callback {
	callback(T value) :value(value) {};

	template <typename F>
	void operator()(int index, F& f) {
		value = (f(value));
	}

	T value;
};

template<typename Callback, typename... Args>
void for_each(std::tuple<Args...>& t, Callback& callback)
{
	int const t_size = std::tuple_size<std::tuple<Args...>>::value;

	iterate_tuple<t_size - 1, Callback, Args...>::next(t, callback);
}


template <class... Args>
class composition {
public:
	composition(Args&... args) : comp(std::forward<Args>(args)...) { }

	template<typename T>
	T operator()(const T& value) {
		callback<T> cb(value);

		for_each(comp, cb);
		return cb.value;
	}

private:
	std::tuple<Args...> comp;
};

template <class... Args>
composition<Args...> compose(Args... args)
{
	composition<Args...> c(args...);

	return c;
}

#endif