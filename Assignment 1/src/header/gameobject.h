#pragma once

#include <iostream>

class gameObject {
public:
  inline virtual ~gameObject() = default;
  virtual void normalAttack() const = 0;

  inline friend std::ostream &operator<<(std::ostream &os,
                                         const gameObject &g) {
    return g.print(os);
  }

  inline friend bool operator==(const gameObject &a, const gameObject &b) {
    return a.compare(b);
  }

protected:
  virtual std::ostream &print(std::ostream &) const = 0;
  virtual bool compare(const gameObject &) const = 0;
};