/**
 * Copyright (c) 2012 Andrew Prock. All rights reserved.
 */
#ifndef NIT_ENUM_ODOMETER_H_
#define NIT_ENUM_ODOMETER_H_

#include <algorithm>
#include <string>
#include <vector>

namespace nit {

/** This is a simple odomter class.  It runs each index from [0..max] where
 * the max of the ith index is the ith element in the extents vector passed
 * to the init function.  For example if the extent vector is: <2,4,3> the
 * odomoeter will generate these 3-tuples in this oder:
 *
 *  0  0  0
 *  0  0  1
 *  0  0  2
 *  0  1  0
 *  0  1  1
 *  0  1  2
 *  0  2  0
 *  0  2  1
 *  0  2  2
 *  0  3  0
 *  0  3  1
 *  0  3  2
 *  1  0  0
 *  1  0  1
 *  1  0  2
 *  1  1  0
 *  1  1  1
 *  1  1  2
 *  1  2  0
 *  1  2  1
 *  1  2  2
 *  1  3  0
 *  1  3  1
 *  1  3  2
 *
 * To check if more tuples are available, call hasMore() and to get the
 * next one, call getNext ().
 *
 * usage example:
 */
class Odometer {
 public:
  explicit Odometer(const std::vector<size_t>& extents)
      : m_extents(extents.size()), m_odom(extents.size(), 0) {
    for (size_t i = 0; i < extents.size(); i++)
      m_extents[i] = static_cast<int>(extents[i]);
  }

  size_t size() const { return m_odom.size(); }

  std::string str() const {
    std::string ret(size(), '0');
    for (size_t i = 0; i < ret.size(); i++)
      ret[i] += m_odom[i];
    return ret;
  }

  bool next() { return flip(static_cast<int>(m_odom.size() - 1)); }

  unsigned int operator[](size_t i) const { return m_odom[i]; }

 private:
  bool flip(int n) {
    if (n < 0)
      return false;
    m_odom[n]++;
    if (m_odom[n] >= m_extents[n]) {
      m_odom[n] = 0;
      return flip(n - 1);
    }
    return true;
  }

  std::vector<int> m_extents;
  std::vector<int> m_odom;
};

}  // namespace nit

#endif  // NIT_ENUM_ODOMETER_H_
