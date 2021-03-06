/**
 * Copyright (c) 2012 Andrew Prock. All rights reserved.
 */
#include <iostream>
#include "rank.h"

namespace nit {

Rank::Rank(const std::string& c) { fromString(c); }

Rank::Rank(uint8_t code) {
  if (code <= RANK_ACE)
    m_rank = code;
  else
    m_rank = rank_code(code);
}

std::string Rank::str() const {
  switch (m_rank) {
    case RANK_TWO:
      return "2";
    case RANK_THREE:
      return "3";
    case RANK_FOUR:
      return "4";
    case RANK_FIVE:
      return "5";
    case RANK_SIX:
      return "6";
    case RANK_SEVEN:
      return "7";
    case RANK_EIGHT:
      return "8";
    case RANK_NINE:
      return "9";
    case RANK_TEN:
      return "T";
    case RANK_JACK:
      return "J";
    case RANK_QUEEN:
      return "Q";
    case RANK_KING:
      return "K";
    case RANK_ACE:
      return "A";
  }
  return "?";
}

void Rank::fromString(const std::string& c) {
  int code = rank_code(c[0]);
  if (code >= 0)
    m_rank = code;
  else
    std::cout << "Wow nice error" << std::endl;
}

int Rank::rank_code(char c) {
  switch (c) {
    case '2':
      return Rank::RANK_TWO;
    case '3':
      return Rank::RANK_THREE;
    case '4':
      return Rank::RANK_FOUR;
    case '5':
      return Rank::RANK_FIVE;
    case '6':
      return Rank::RANK_SIX;
    case '7':
      return Rank::RANK_SEVEN;
    case '8':
      return Rank::RANK_EIGHT;
    case '9':
      return Rank::RANK_NINE;
    case 't':
    case 'T':
      return Rank::RANK_TEN;
    case 'j':
    case 'J':
      return Rank::RANK_JACK;
    case 'q':
    case 'Q':
      return Rank::RANK_QUEEN;
    case 'k':
    case 'K':
      return Rank::RANK_KING;
    case 'a':
    case 'A':
      return Rank::RANK_ACE;
  }
  return -1;
}

bool Rank::isRankChar(char c) {
  if (rank_code(c) >= 0)
    return true;
  return false;
}

}  // namespace nit
