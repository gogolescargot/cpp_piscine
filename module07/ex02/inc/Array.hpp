/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:08:52 by ggalon            #+#    #+#             */
/*   Updated: 2024/05/13 17:25:53 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <class T>
class Array {
		
	private:
		T* _array;
		unsigned int _size;

	public:
		Array()
		{
			_array = new (T);
			_size = 0;
		}

		Array(unsigned int size)
		{
			_array = new T[size];
			_size = size;
		}

		Array(const Array<T>& src)
		{
			_array = new T[src._size];
			_size = src._size;
			std::copy(src._array, src._array + _size, _array);
		}

		Array<T>& operator=(const Array<T>& src)
		{
			delete[] _array;
			_array = new T[src._size];
			_size = src._size;
			std::copy(src._array, src._array + _size, _array);
			return (*this);
		}

		~Array()
		{
			delete[] _array;
		}

		T& operator[](unsigned int i)
		{
			if (i >= _size)
				throw (Array::IndexOutOfRange());
			return (_array[i]);
		}

	class IndexOutOfRange : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Index out of range");
		}
	};
};

#endif