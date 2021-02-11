#pragma once
template <typename UnusedType>
class function;

template <typename ReturnType, typename ... ArgumentTypes>
class function <ReturnType(ArgumentTypes ...)> {
public:
	function() : mInvoker() {}
	template <typename FunctionT>
	function(FunctionT f) : mInvoker(new free_function_holder<FunctionT>(f)) {}

	ReturnType operator ()(ArgumentTypes ... args) {
		return mInvoker->invoke(args ...);
	}
private:
	class function_holder_base {
	public:
		function_holder_base() {}
		virtual ~function_holder_base() {}
		virtual ReturnType invoke(ArgumentTypes ... args) = 0;
	};
	typedef std::auto_ptr<function_holder_base> invoker_t;

	template <typename FunctionT>
	class free_function_holder : public function_holder_base {
	public:
		free_function_holder(FunctionT func) : function_holder_base(), mFunction(func) {}

		virtual ReturnType invoke(ArgumentTypes ... args) {
			return mFunction(args ...);
		}
	private:
		FunctionT mFunction;
	};
	invoker_t mInvoker;
};