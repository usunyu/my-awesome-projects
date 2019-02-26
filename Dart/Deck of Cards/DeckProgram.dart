void main() {
  var deck = new Deck();
//   deck.shuffle();
  print(deck);
//   print(deck.deal(5));
//   print(deck);
  deck.removeCard('Diamonds', 'Ace');
  print(deck);
}

class Deck {
  List<Card> cards = new List<Card>();
  
  Deck() {
    var ranks = ['Ace', 'Two', 'Three', 'Four', 'Five'];
    var suits = ['Diamonds', 'Hearts', 'Clubs', 'Spades'];
    
    for (var suit in suits) {
      for (var rank in ranks) {
        var card = new Card(
          suit: suit,
          rank: rank
        );
        cards.add(card);
      }
    }
  }
  
  void shuffle() {
    cards.shuffle();
  }
  
  cardsWithSuit(String suit) {
//     return cards.where((card) {
//       return card.suit == suit;
//     });
    return cards.where((card) => card.suit == suit);
  }
  
  List<Card> deal(int handSize) {
    var hand = cards.sublist(0, handSize);
    cards = cards.sublist(handSize);
    
    return hand;
  }
  
  void removeCard(String suit, String rank) {
    cards.removeWhere((card) {
      return card.suit == suit && card.rank == rank;
    });
  }
  
  String toString() {
    return cards.toString();
  }
}

class Card {
  String suit;
  String rank;
  
  Card({this.rank, this.suit});
  
  String toString() {
    return '$rank of $suit';
  }
}