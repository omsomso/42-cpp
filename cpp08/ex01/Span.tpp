template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
	while (begin != end) {
		if (_numbers.size() >= _N)
			throw std::runtime_error("Span is full");
		_numbers.push_back(*begin);
		++begin;
	}
}