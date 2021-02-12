/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 09:10:32 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/25 13:21:53 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stack>
# include <string>
# include <algorithm>


template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(const MutantStack &);
	~MutantStack();
	MutantStack	&operator=(const MutantStack &);
	class iterator : public std::iterator<std::input_iterator_tag, T> {
	private:
		T	*point;
	public:
		iterator();
		iterator(T *);
		iterator(const iterator &);
		~iterator();
		iterator	&operator=(const iterator &);
		bool		operator==(const iterator &);
		bool		operator>=(const iterator &);
		bool		operator<=(const iterator &);
		bool		operator<(const iterator &);
		bool		operator>(const iterator &);
		bool		operator!=(const iterator &);
		T			operator*();
		iterator	&operator++();
		iterator	&operator--();
		iterator	&operator+=(const size_t);
		iterator	&operator-=(const size_t);
		iterator	operator++(int);
		iterator	operator--(int);
	};
	iterator	begin();
	iterator	end();
};

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>() {
	*this = other;
}

template<typename T>
MutantStack<T>::~MutantStack() {
}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &other) {
	std::stack<T>::operator=(other);
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return iterator(&this->top() - this->size());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return iterator(&this->top());
}

/*=================================================================================================================================*/
/*==================================================>   MutantStack::iterator   <==================================================*/
/*=================================================================================================================================*/

template<typename T>
MutantStack<T>::iterator::iterator() : std::iterator<std::input_iterator_tag, T>(), point(NULL) {}

template<typename T>
MutantStack<T>::iterator::iterator(T *point) : std::iterator<std::input_iterator_tag, T>(), point(point) {}

template<typename T>
MutantStack<T>::iterator::iterator(const iterator &other) : std::iterator<std::input_iterator_tag, T>(), point(other.point) {
	*this = other;
}

template<typename T>
MutantStack<T>::iterator::~iterator() {}


template<typename T>
typename MutantStack<T>::iterator	&MutantStack<T>::iterator::operator=(const iterator &other) {
	this->point = other.point;
	return *this;
}

template<typename T>
bool		MutantStack<T>::iterator::operator==(const iterator &other) {
	return this->point == other.point;
}

template<typename T>
bool		MutantStack<T>::iterator::operator>=(const iterator &other) {
	return this->point >= other.point;
}

template<typename T>
bool		MutantStack<T>::iterator::operator<=(const iterator &other) {
	return this->point <= other.point;
}

template<typename T>
bool		MutantStack<T>::iterator::operator<(const iterator &other) {
	return this->point < other.point;
}

template<typename T>
bool		MutantStack<T>::iterator::operator>(const iterator &other) {
	return this->point > other.point;
}

template<typename T>
bool		MutantStack<T>::iterator::operator!=(const iterator &other) {
	return this->point != other.point;
}

template<typename T>
T			MutantStack<T>::iterator::operator*() {
	return *this->point;
}

template<typename T>
typename MutantStack<T>::iterator	&MutantStack<T>::iterator::operator++() {
	return this->operator+=(1);
}

template<typename T>
typename MutantStack<T>::iterator	&MutantStack<T>::iterator::operator--() {
	return this->operator-=(1);
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator++(int n) {
	typename MutantStack<T>::iterator	prev = *this;

	n = 1;
	this->operator+=(1);
	return prev;
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::iterator::operator--(int n) {
	typename MutantStack<T>::iterator	prev = *this;

	n = 1;
	this->operator-=(1);
	return prev;
}

template<typename T>
typename MutantStack<T>::iterator	&MutantStack<T>::iterator::operator+=(const size_t n) {
	this->point -= n;
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator	&MutantStack<T>::iterator::operator-=(const size_t n) {
	this->point += n;
	return *this;
}
