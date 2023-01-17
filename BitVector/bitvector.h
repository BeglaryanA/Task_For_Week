#ifndef BITVECTOR_H
#define BITVECTOR_H

#include <execution>

class BitVector {
public:
    BitVector();
    BitVector(const int);
    BitVector(const BitVector&);
    BitVector(BitVector&&);
    ~BitVector();

public:
    BitVector& operator=(const BitVector&);
    BitVector& operator=(BitVector&&);

public:
    void set(const int, const bool);
    int get(const int);
    const int size() const;
    void clear();

public:
    int& operator[](const int);
    const int& operator[](const int) const;
    friend std::ostream& operator<<(std::ostream& os, const BitVector& rhs) {
        for (int i = rhs.size() - 1; i >= 0; --i) {
            os << rhs[i];
        }
        return os;
    }


private:
    void resize(const int);

private:
    int* m_arr;
    int m_size;
};

#endif // BITVECTOR_H