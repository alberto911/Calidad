#include <stack>
using namespace std;

template <class T>
class Pila {
public:
	void push(T value) {
		st.push(value);
	}
	void pop() {
		st.pop();
	}
	unsigned int size() {
		return st.size();
	}
protected:
	stack<T> st;
};
