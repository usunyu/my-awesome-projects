Feature: code-breaker submits guess

  The code-breaker submits a guess of four numbers.  The game marks the guess
  with + and - signs.

  For each number in the guess that matches the number and position of a number
  in the secret code, the mark includes one + sign. For each number in the guess
  that matches the number but not the position of a number in the secret code,
  the mark includes one - sign.

  Each position in the secret code can only be matched once.  For example, a
  guess of 1134 against a secret code of 1234 would get three plus signs: one
  each for the exact matches in the first, third and fourth positions.  The
  number match in the second position would be ignored.

  Scenario Outline: submit guess
    Given the secret code is "<code>"
    When I guess "<guess>"
    Then the mark should be "<mark>"

    Scenarios: no matches
      | code | guess | mark |
      | 1234 | 5555  |      |

    Scenarios: 1 number correct
      | code | guess | mark |
      | 1234 | 1555  | +    |
      | 1234 | 2555  | -    |

    Scenarios: 2 numbers correct
      | code | guess | mark |
      | 1234 | 5254  | ++   |
      | 1234 | 5154  | +-   |
      | 1234 | 2545  | --   |

    Scenarios: 3 numbers correct
      | code | guess | mark |
      | 1234 | 5234  | +++  |
      | 1234 | 5134  | ++-  |
      | 1234 | 5124  | +--  |
      | 1234 | 5123  | ---  |

    Scenarios: all numbers correct
      | code | guess | mark |
      | 1234 | 1234  | ++++ |
      | 1234 | 1243  | ++-- |
      | 1234 | 1423  | +--- |
      | 1234 | 4321  | ---- |

    Scenarios: matches with duplicates
      | code | guess | mark |
      | 1234 | 1155  | +    |
      | 1234 | 5115  | -    |
      | 1134 | 1155  | ++   |
      | 1134 | 5115  | +-   |
      | 1134 | 5511  | --   |
      | 1134 | 1115  | ++   |
      | 1134 | 5111  | +-   |
