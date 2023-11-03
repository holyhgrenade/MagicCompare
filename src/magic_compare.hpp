#ifndef MAGIC_COMPARE_HPP
#define MAGIC_COMPARE_HPP

template <class T>
class MagicCompare {
private:
  T left;     // numerical value left
  T right;    // numerical value right
  bool comp;  // comparison result
  
  MagicCompare(T theLeft, T theRight, bool theComp = true) :
  left(theLeft), right(theRight), comp(theComp) {}
public:
  MagicCompare(T theNum)
  {
    this->left = theNum;
    this->right = theNum;
    this->comp = true;
  }

  T getLeft() const
  {
    return left;
  }
  T getRight() const
  {
    return right;
  }
  bool getComp() const
  {
    return comp;
  }
  operator bool() const
  {
    return comp;
  }
  operator T() const {
    return left;
  }

  // comparison with other MagicCompare
  MagicCompare operator<(const MagicCompare& rhs) const {
    MagicCompare result(
      this->left,
      rhs.right,
      (this->comp) && (rhs.comp) && (this->right < rhs.left)
    );
    return result;
  }
  MagicCompare operator>(const MagicCompare& rhs) const {
    MagicCompare result(
      this->left,
      rhs.right,
      (this->comp) && (rhs.comp) && this->right > rhs.left
    );
    return result;
  }
  MagicCompare operator<=(const MagicCompare& rhs) const {
    MagicCompare result(
      this->left,
      rhs.right,
      (this->comp) && (rhs.comp) && this->right <= rhs.left
    );
    return result;
  }
  MagicCompare operator>=(const MagicCompare& rhs) const {
    MagicCompare result(
      this->left,
      rhs.right,
      (this->comp) && (rhs.comp) && this->right >= rhs.left
    );
    return result;
  }
  MagicCompare operator==(const MagicCompare& rhs) const {
    MagicCompare result(
      this->left,
      rhs.right,
      (this->comp) && (rhs.comp) && this->right == rhs.left
    );
    return result;
  }
  MagicCompare operator!=(const MagicCompare& rhs) const {
    MagicCompare result(
      this->left,
      rhs.right,
      (this->comp) && (rhs.comp) && this->right != rhs.left
    );
    return result;
  }

  // comparison with numbers
  MagicCompare operator<(const T rhs) const {
    MagicCompare result(
      this->left,
      rhs,
      (this->comp) && (this->right < rhs)
    );
    return result;
  }
  MagicCompare operator>(const T rhs) const {
    MagicCompare result(
      this->left,
      rhs,
      (this->comp) && (this->right > rhs)
    );
    return result;
  }
  MagicCompare operator<=(const T rhs) const {
    MagicCompare result(
      this->left,
      rhs,
      (this->comp) && (this->right <= rhs)
    );
    return result;
  }
  MagicCompare operator>=(const T rhs) const {
    MagicCompare result(
      this->left,
      rhs,
      (this->comp) && (this->right >= rhs)
    );
    return result;
  }
  MagicCompare operator==(const T rhs) const {
    MagicCompare result(
      this->left,
      rhs,
      (this->comp) && (this->right == rhs)
    );
    return result;
  }
  MagicCompare operator!=(const T rhs) const {
    MagicCompare result(
      this->left,
      rhs,
      (this->comp) && (this->right != rhs)
    );
    return result;
  }
  
  // comparison of numbers with MagicCompare
  friend MagicCompare operator <(const T lhs, const MagicCompare& rhs)
  {
    MagicCompare result(
      lhs,
      rhs.right,
      (rhs.comp) && (lhs < rhs.left)
    );
    return result;
  }
  friend MagicCompare operator >(const T lhs, const MagicCompare& rhs)
  {
    MagicCompare result(
      lhs,
      rhs.right,
      (rhs.comp) && (lhs > rhs.left)
    );
    return result;
  }
  friend MagicCompare operator <=(const T lhs, const MagicCompare& rhs)
  {
    MagicCompare result(
      lhs,
      rhs.right,
      (rhs.comp) && (lhs <= rhs.left)
    );
    return result;
  }
  friend MagicCompare operator >=(const T lhs, const MagicCompare& rhs)
  {
    MagicCompare result(
      lhs,
      rhs.right,
      (rhs.comp) && (lhs >= rhs.left)
    );
    return result;
  }
  friend MagicCompare operator ==(const T lhs, const MagicCompare& rhs)
  {
    MagicCompare result(
      lhs,
      rhs.right,
      (rhs.comp) && (lhs == rhs.left)
    );
    return result;
  }
  friend MagicCompare operator !=(const T lhs, const MagicCompare& rhs)
  {
    MagicCompare result(
      lhs,
      rhs.right,
      (rhs.comp) && (lhs != rhs.left)
    );
    return result;
  }
  
  // increment and decrement ops
  MagicCompare& operator++()
  {
    ++left;
    ++right;
    return *this;
  }
  MagicCompare& operator--()
  {
    --left;
    --right;
    return *this;
  }
  MagicCompare operator++(int)
  {
    MagicCompare tmp(*this);
    ++(*this);
    return tmp;
  }
  MagicCompare operator--(int)
  {
    MagicCompare tmp(*this);
    --(*this);
    return tmp;
  }
  
  // + and +=
  MagicCompare& operator+=(const MagicCompare& rhs)
  {
    left += rhs.left;
    right += rhs.right;
    comp = comp && rhs.comp;
    return *this;
  }
  MagicCompare& operator+=(const T rhs)
  {
    left += rhs;
    right += rhs;
    return *this;
  }
  
  MagicCompare operator+(const MagicCompare& rhs)
  {
    MagicCompare result(*this);
    result += rhs;
    return result;
  }
  
  MagicCompare operator+(const T rhs)
  {
    MagicCompare result(*this);
    result += rhs;
    return result;
  }

  // - and -=
  MagicCompare& operator-=(const MagicCompare& rhs)
  {
    left -= rhs.left;
    right -= rhs.right;
    comp = comp && rhs.comp;
    return *this;
  }
  MagicCompare& operator-=(const T rhs)
  {
    left -= rhs;
    right -= rhs;
    return *this;
  }
  
  MagicCompare operator-(const MagicCompare& rhs)
  {
    MagicCompare result(*this);
    result -= rhs;
    return result;
  }
  
  MagicCompare operator-(const T rhs)
  {
    MagicCompare result(*this);
    result -= rhs;
    return result;
  }
  
  // * and *=
  MagicCompare& operator*=(const MagicCompare& rhs)
  {
    left *= rhs.left;
    right *= rhs.right;
    comp = comp && rhs.comp;
    return *this;
  }
  MagicCompare& operator*=(const T rhs)
  {
    left *= rhs;
    right *= rhs;
    return *this;
  }
  
  MagicCompare operator*(const MagicCompare& rhs)
  {
    MagicCompare result(*this);
    result *= rhs;
    return result;
  }
  
  MagicCompare operator*(const T rhs)
  {
    MagicCompare result(*this);
    result *= rhs;
    return result;
  }
  
  friend MagicCompare operator*(const T lhs, const MagicCompare& rhs)
  {
    MagicCompare result(
      lhs * rhs.left,
      lhs * rhs.right,
      rhs.comp
    );
    return result;
  }

  // / and /=
  MagicCompare& operator/=(const MagicCompare& rhs)
  {
    left /= rhs.left;
    right /= rhs.right;
    comp = comp && rhs.comp;
    return *this;
  }
  MagicCompare& operator/=(const T rhs)
  {
    left /= rhs;
    right /= rhs;
    return *this;
  }
  
  MagicCompare operator/(const MagicCompare& rhs)
  {
    MagicCompare result(*this);
    result /= rhs;
    return result;
  }
  
  MagicCompare operator/(const T rhs)
  {
    MagicCompare result(*this);
    result /= rhs;
    return result;
  }
};

#endif // MAGIC_COMPARE_H
