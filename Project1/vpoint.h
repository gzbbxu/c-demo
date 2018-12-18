#pragma once
namespace PTRLib {
	template<typename T>
	class SuperPointer {
	public:
		SuperPointer(T * t = NULL) {
			mpointer = t;
		}

		~SuperPointer()
		{
			delete mpointer;
		}

		SuperPointer(const SuperPointer<T>& other) {
			//const_cast<SuperPointer<T>&>(other).mpointer = NULL;
			mpointer = other.mpointer;
			const_cast<SuperPointer<T>&>(other).mpointer = NULL;
		}

	private:
	protected:
		T * mpointer;
	};
}
