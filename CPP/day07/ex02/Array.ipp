/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:05:12 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 13:08:34 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : _size(0) {
	this->arr = new T[0];
}

template<typename T>
Array<T>::Array(int n) : _size(n) {
	this->arr = new T[n];
}

template<typename T>
Array<T>::Array(const Array<T> &other) : _size(other.size), arr(NULL) {
	*this = other;
}

template<typename T>
Array<T>::~Array() {
	if (this->arr)
		delete [] this->arr;
	this->arr = NULL;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &other) {
	if (*this == other)
		return (*this);
	if (this->arr)
		delete [] this->arr;
	this->arr = NULL;
	this->_size = other._size;
	this->arr = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++) {
		this->arr[i] = other.arr[i];
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](int index) {
	if (static_cast<size_t>(index) >= this->_size || index < 0)
		throw Array<T>::NotElementException(index, this->_size);
	return this->arr[index];
}

template<typename T>
size_t	Array<T>::size() const {
	return this->_size;
}

/*==============================================================================*/
/*=====================>  Array::NotElementException  <=========================*/
/*==============================================================================*/

template<typename T>
Array<T>::NotElementException::NotElementException() : error("y") {
}

template<typename T>
Array<T>::NotElementException::NotElementException(int index, size_t size) {
	messageError(index, size);
}

template<typename T>
Array<T>::NotElementException::NotElementException(const NotElementException &except) {
	*this = except;
}

template<typename T>
Array<T>::NotElementException::~NotElementException() throw () {
}

template<typename T>
void	Array<T>::NotElementException::messageError(int index, size_t size) {
	this->error = "index > 0 && index < size, but index = ";
	this->error.append(std::to_string(index));
	this->error.append(", size = ");
	this->error.append(std::to_string(size));
}

template<typename T>
typename Array<T>::NotElementException	&Array<T>::NotElementException::operator=(const Array<T>::NotElementException &except) {
	this->error = except.error;
	return *this;
}

template<typename T>
const char	*Array<T>::NotElementException::what() const throw () {
	return this->error.c_str();
}
