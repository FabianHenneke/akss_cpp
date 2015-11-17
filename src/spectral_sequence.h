#pragma once

#include <map>
#include <vector>
#include "abelian_group.h"

class TrigradedIndex
{
 public:
  TrigradedIndex(const int p, const int q, const int s);

  inline int p() const
  {
    return p_;
  }
  inline int q() const
  {
    return q_;
  }
  inline int s() const
  {
    return s_;
  }

  friend bool operator==(const TrigradedIndex& a, const TrigradedIndex& b);
  friend bool operator<(const TrigradedIndex& a, const TrigradedIndex& b);

 private:
  const int p_;
  const int q_;
  const int s_;
};

bool operator==(const TrigradedIndex& a, const TrigradedIndex& b);
bool operator<(const TrigradedIndex& a, const TrigradedIndex& b);

class GroupSequence {
 public:
	GroupSequence(const std::size_t index_min, const AbelianGroup& grp);
	const AbelianGroup& get_group(const std::size_t index);
	const MatrixQ& get_matrix(const std::size_t index);
	void append(const std::size_t index, const AbelianGroup& grp, const MatrixQ& map);
	void done();

 private:
	bool done_;
	std::map<std::size_t, std::tuple<AbelianGroup,MatrixQ>> entries_;

	//The matrix nr n represents the map between the group nr index_min and the n-th group.
	//if number n is not set explicitly, but smaller than current,
	//its value is given by the next smaller index.
	//if done is set, arbitrarily large indices are allowed,
	//and all higher things are treated as equal to the highest one that has been set explicitly.
};
