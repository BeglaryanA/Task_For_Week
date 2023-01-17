#include <iostream>

#include "bitvector.h"

BitVector::BitVector() 
: m_arr{nullptr}
, m_size{0}
{}

BitVector::BitVector(const int size)
: m_size{size}
{
    this->m_arr = new int[m_size];
}

BitVector::BitVector(const BitVector& rhs) {
    this->m_arr = new int[rhs.m_size];
    this->m_size = rhs.m_size;
    for (int i = 0; i < this->m_size; ++i) {
        this->m_arr[i] = rhs.m_arr[i];
    }
}

BitVector::BitVector(BitVector&& rhs) {
    this->m_arr = rhs.m_arr;
    this->m_size = rhs.m_size;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
}

BitVector& BitVector::operator=(const BitVector& rhs) {
    if (this == &rhs) {
        return *this;
    }
    this->clear();
    this->m_size = rhs.m_size;
    this->m_arr = new int[this->m_size];
    for (int i = 0; i < this->m_size; ++i) {
        this->m_arr[i] = rhs.m_arr[i];
    }
    return *this;
}

BitVector& BitVector::operator=(BitVector&& rhs) {
    if (this == &rhs) {
        return *this;
    }
    this->clear();
    this->m_arr = rhs.m_arr;
    this->m_size = rhs.m_size;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
    return *this;
}

int& BitVector::operator[](const int index) {
    return this->m_arr[index];
}

const int& BitVector::operator[](const int index) const {
    return this->m_arr[index];
}

BitVector::~BitVector() {
    this->clear();
}

void BitVector::set(const int position, const bool value) {
    if (position >= m_size) {
        this->resize(position + 1);
    }
    this->m_arr[position] |= value;
}

int BitVector::get(const int position) {
    if (position >= m_size) {
        throw std::out_of_range("Invalid argument!");
    }
    return this->m_arr[position];
}

const int BitVector::size() const {
    return this->m_size;
}


void BitVector::resize(const int new_size) {
    int* for_change = new int[new_size];
    for (int i = 0; i < m_size; ++i) {
        for_change[i] = this->m_arr[i];
    }
    this->clear();
    this->m_size = new_size;
    this->m_arr = for_change;
    for_change = nullptr;
}

void BitVector::clear() {
    delete this->m_arr;
    this->m_arr = nullptr;
    this->m_size = 0;
}