#pragma once
using namespace std;
namespace DTLib {

	//����
	//����ָ�� ֻ������ָ��ѿռ�ĵ���������߱��� �����Ƕ����飬Ҳ���ܹ�ָ��һ���ֲ��Ķ��󡣻��߾ֲ��ı���
	template<typename T>
	class SmartPoint
	{
	public:

		SmartPoint(T * p = NULL) {
			cout << "һ�㹹��"<<endl;
			m_pointer = p;
		}

		SmartPoint(const SmartPoint<T>& point) {
			cout << "��������"<<endl;
			//ͬһƬ�ѿռ� ֻ����һ��ָ����ָ��
			m_pointer = point.m_pointer;
			//point.m_pointer = NULL; //��Ϊ��const �������Բ���ֱ�Ӹ�ֵ ��Ҫǿ������ת��  
			//ȥ��һ�������const ����
			const_cast<SmartPoint<T>&>(point).m_pointer = NULL;
		}

		SmartPoint<T>& operator = (const SmartPoint<T>& point) {
			cout << "��ֵ����"<<endl;
			if (this != &point) {
				//�ж��Ƿ����Լ����Լ���ֵ
				delete m_pointer;
				m_pointer = point.m_pointer;
				const_cast<SmartPoint<T>&>(point).m_pointer = NULL;
			}
			return *this; //��������֧�������ĸ�ֵ
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



