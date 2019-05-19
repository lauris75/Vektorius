#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <chrono>
#include <fstream>

const int defaultSize = 2;

	template <typename T>
	class Vector
	{
		typedef T value_type;
	private:
		T* array_;
		int size_;
		int reserved_size_;
		inline void make_new()
		{
			reserved_size_ = size_ * 2 + 2;
			T* temp = new T[reserved_size_];
			memcpy(temp, array_, size_ * sizeof(T));
			delete[] array_;
			array_ = temp;
		}
	public:
		Vector()
		{
			size_ = 0;
			reserved_size_ = 0;
			array_ = new T[0];
		}

		Vector(int s)
		{
			size_ = s;
			reserved_size_ = s;
			array_ = new T[size_];
		}

		~Vector()
		{
			delete[] array_;
		}

		void assign(int n, T value);
		void push_back(const T& t);
		void pop_back();
		void insert(int it, T value);
		void insert(int it, int n, T value);
		void erase(int it);
		void erase(int it1, int it2);
		void clear();

		T* data() { return array_; }

		void resize(int n, T val = 0);
		int size() { return size_; }
		int capacity() { return reserved_size_; }
		bool empty() { if (size_ > 0) return false; else return true; };
		void shrink_to_fit();
		void reserve(int n);

		T& at(int it) {
			if (it < 0 || size_ < it) throw std::out_of_range{ "Vector::reference_at" };
			return array_[it];
		}
		T& back() { return array_[size_ - 1]; }
		T& front() { return array_[0]; }

		typedef T* iterator;
		iterator begin() { return array_; }
		iterator end() { return array_ + size_; }

		T& operator[](int i) {
			if (i < size_ && i >= 0) { return array_[i]; }
			else throw std::out_of_range{ "Vector::operator[]" };
		}

		T& operator=(const Vector & other) {
			if (&other == this) return *this;
			T * pointer = new T[other.size_];
			for (int i = 0; i != other.size_; ++i) pointer[i] = other.array_[i];
			delete[] array_;
			array_ = pointer;
			size_ = other.size_;
			reserved_size_ = size_;
			return *this;
		}
	};
	template <typename T>
	void Vector<T>::reserve(int n)
	{
		if (n > reserved_size_) {
			T* array_2 = new T[n];
			for (int i = 0; i < size_; i++)
			{
				array_2[i] = array_[i];
			}
			delete[] array_;
			T* array_ = new T[n];
			array_ = array_2;
			delete[] array_2;
			reserved_size_ = n;
		}
	}

	template <typename T>
	void Vector<T>::shrink_to_fit()
	{
		if (size_ < reserved_size_) {
			T* array_2 = new T[size];
			for (int i = 0; i < size_; i++)
			{
				array_2[i] = array_[i];
			}
			delete[] array_;
			array_ = array_2;
			delete[] array_2;
			reserved_size_ = size_;
		}
	}

	template <typename T>
	void Vector<T>::push_back(const T & t)
	{
		if (size_ == reserved_size_) make_new() ;
		array_[size_] = t;
		size_++;
	}

	template <typename T>
	void Vector<T>::resize(int n, T val)
	{
		if (n > 0) {
			T* array_2 = new T[n];
			int k;
			if (size_ > n) k = n; else k = size_;
			for (int i = 0; i < k; i++) {
				array_2[i] = array_[i];
			}
			for (int i = k; i < n; i++) {
				array_2[i] = val;
			}
			delete[] array_;
			array_ = array_2;
			delete[] array_2;
			if (n > reserved_size_) reserved_size_ = n;
			size_ = n;
		}
	}

	template <typename T>
	void Vector<T>::pop_back()
	{
		if (size_ > 0) {
			delete& array_[size_];
			size_--;
		}
	}

	template <typename T>
	void Vector<T>::assign(int n, T value) {
		if (n < 0) throw std::out_of_range{ "Vector::assign" };
		delete[] array_;
		size_ = n;
		reserved_size_ = size_;
		array_ = new T[size_];
		std::fill_n(array_, size_, value);
	}

	template <typename T>
	void Vector<T>::insert(int it, T value) {
		if (it < 1 || it > size_) throw std::out_of_range{ "Vector::insert" };
		T* array_2 = new T[size_ + 1];
		for (int i = 0; i < it; i++) {
			array_2[i] = array_[i];
		}
		array_2[it] = value;
		for (int i = it; i < size_ + 1; i++) {
			array_2[i + 1] = array_[i];
		}
		delete[] array_;
		array_ = array_2;
		delete[] array_2;
		size_++;
		if (reserved_size_ < size_) reserved_size_ = size_;
	}

	template <typename T>
	void Vector<T>::insert(int it, int n, T value) {
		if (n < 1 || it < 1 || it > size_) throw std::out_of_range{ "Vector::insert" };
		T* array_2 = new T[size_ + n];
		for (int i = 0; i < it; i++) {
			array_2[i] = array_[i];
		}
		for (int i = it; i < it + n; i++) {
			array_2[i] = value;
		}
		for (int i = it; i < size_; i++) {
			array_2[i + n] = array_[i];
		}
		delete[] array_;
		array_ = array_2;
		delete[] array_2;
		size_ = size_ + n;
		if (reserved_size_ < size_) reserved_size_ = size_;
	}

	template <typename T>
	void Vector<T>::clear() {
		if (size_ > 0)
		{
			size_ = 0;
		}
	}

	template <typename T>
	void Vector<T>::erase(int it) {
		if (it < 1 || it > size_) throw std::out_of_range{ "Vector::erase" };
		T* array_2 = new T[size-1];
		for (int i = 0; i < it; i++) {
			array_2[i] = array_[i];
		}
		for (int i = it; i < size_ - 1; i++) {
			array_2[i] = array_[i + 1];
		}
		delete[] array_;
		array_ = array_2;
		delete[] array_2;
		size_--;
	}

	template <typename T>
	void Vector<T>::erase(int it1, int it2) {
		if (it1 - it2 > 0 || it2 > size_) throw std::out_of_range{ "Vector::erase" };
		T* array_2 = new T[size - (it2 - it1)];
		for (int i = 0; i < it1; i++)
		{
			array_2 = array_[i];
		}
		for (int i = it1; i < size_ - (it2 - it1); i++)
		{
			array_2 = array_[i + (it2 - it1)];
		}
		delete[] array_;
		array_ = array_2;
		delete[] array_2;
		size_ = size_ - (it2 - it1);
	}