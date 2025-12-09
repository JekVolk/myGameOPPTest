#include "xp_book.hpp"

void XPBook::_activate(Cossack &cossack)
{
  cossack.receivingXP(getValue());
}