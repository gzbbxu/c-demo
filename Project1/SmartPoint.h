#pragma once
using namespace std;
namespace DTLib {

	//规则
	//智能指针 只能用来指向堆空间的单个对象或者变量 不能是堆数组，也不能够指向一个局部的对象。或者局部的变量
	template<typename T>
	class SmartPoint
	{
	public:

		SmartPoint(T * p = NULL) {
			cout << "一般构造"<<endl;
			m_pointer = p;
		}

		SmartPoint(const SmartPoint<T>& point) {
			cout << "拷贝构造"<<endl;
			//同一片堆空间 只能有一个指针所指向
			m_pointer = point.m_pointer;
			//point.m_pointer = NULL; //因为是const 对象，所以不能直接赋值 需要强制类型转换  
			//去除一个对象的const 属性
			const_cast<SmartPoint<T>&>(point).m_pointer = NULL;
		}

		SmartPoint<T>& operator = (const SmartPoint<T>& point) {
			cout << "赋值构造"<<endl;
			if (this != &point) {
				//判断是否是自己给自己赋值
				delete m_pointer;
				m_pointer = point.m_pointer;
				const_cast<SmartPoint<T>&>(point).m_pointer = NULL;
			}
			return *this; //返回自身支持连续的赋值
		}

		T* operator-> () {
			return m_pointer;
		}

		T& operator*() {
			return *m_pointer;
		}

		bool isNull() {
			return (m_pointer == NULL);
		}

		T * get() {
			return *m_pointer;
		}

		~SmartPoint() {
			delete m_pointer;
		}

	protected:
		T * m_pointer;
	};
}



