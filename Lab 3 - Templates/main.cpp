#include <type_traits>
#include <iostream>

template <typename T>
class Rectangle {
public:
	static_assert(std::is_arithmetic<T>::value, "Cannot create Rectangle with anything but numbers!");

	Rectangle(T width, T height) {
		setWidth(width);
		setHeight(height);
	}

	inline T getArea() const {
		return getWidth() * getHeight();
	}
	inline T getHeight() const {
		return m_height;
	}
	inline T getWidth() const {
		return m_width;
	}

	inline void setHeight(T value) {
		m_height = value;
	}
	inline void setWidth(T value) {
		m_width = value;
	}

	static friend std::ostream& operator <<(std::ostream& os, Rectangle r) {
		os << "Width: " << r.getWidth() << ", Height: " << r.getHeight();
		return os;
	}

private:
	T m_width, m_height;
};

template <typename T>
T getArea(Rectangle<T> rect) {
	return rect.getWidth() * rect.getHeight();
}

int main()
{
	Rectangle<float> myFloatingRect = Rectangle<float>(2.3f, 7.9f);
	Rectangle<int> myIntegerRect = Rectangle<int>(5, 12);
	Rectangle<double> myDoubleRect = Rectangle<double>(0.00413, 0.1357);

	float floatRectArea = getArea(myFloatingRect);
	int rectIntArea = getArea(myIntegerRect);
	double rectDoubleArea = getArea(myDoubleRect);

	std::cout << "Rectangle A: " << myFloatingRect << ", Area: " << floatRectArea << std::endl;
	std::cout << "Rectangle B: " << myIntegerRect << ", Area: " << rectIntArea << std::endl;
	std::cout << "Rectangle D (get it?): " << myDoubleRect << ", Area: " << rectDoubleArea << std::endl;

	return 0;
};