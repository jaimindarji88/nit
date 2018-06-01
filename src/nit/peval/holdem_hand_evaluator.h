/**
 * Copyright (c) 2012 Andrew Prock. All rights reserved.
 */
#ifndef NIT_PEVAL_HOLDEM_HAND_EVALUATOR_H_
#define NIT_PEVAL_HOLDEM_HAND_EVALUATOR_H_

#include "holdem.h"
#include "poker_hand_evaluator.h"

namespace nit {
/**
 * A specialized hand evaluator for hold'em.  Not as slow.
 */
class HoldemHandEvaluator : public PokerHandEvaluator {
 public:
  virtual PokerHandEvaluation evaluateHand(const CardSet& hand,
                                           const CardSet& board) const {
    // if (hand.size () != NUM_HOLDEM_POCKET)
    // throw std::invalid_argument ("HHE: incorrect number of pocket
    // cards");
    CardSet h = hand;
    h.insert(board);
    return PokerHandEvaluation(h.evaluateHigh());
  }

  virtual PokerEvaluation evaluateRanks(
      const CardSet& hand, const CardSet& board = CardSet(0)) const {
    CardSet h = hand;
    h.insertRanks(board);
    return h.evaluateHighRanks();
  }

  virtual PokerEvaluation evaluateSuits(
      const CardSet& hand, const CardSet& board = CardSet(0)) const {
    CardSet h = hand;
    h.insert(board);
    return h.evaluateHighFlush();
  }

  virtual size_t handSize() const { return NUM_HOLDEM_POCKET; }
  virtual size_t boardSize() const { return BOARD_SIZE; }
  virtual size_t evaluationSize() const { return 1; }
};

}  // namespace nit

#endif  // NIT_PEVAL_HOLDEM_HAND_EVALUATOR_H_
