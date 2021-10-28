var input = require('fs').readFileSync('1110.txt', 'utf8');
var lines = input.split('\n');



var i = 0;
while (lines[i] != 0) {

    let cardsNumber = lines[i];

    if (cardsNumber != 0) {
        let discardedCards = [];
        let remainingCards = 0;
        i++;

        let cards = [];
        if (cardsNumber > 1) {

            for (let j = 0; j < cardsNumber; j++) {
                if ((j + 1) % 2 == 1) {
                    discardedCards.push(j + 1)
                }
                else {
                    if (j + 1 != 2) {
                        cards.push(j + 1);
                    }
                }

            }

            if (cardsNumber % 2 == 0) {
                cards.unshift(2);
            }
            else {
                cards.push(2);
            }

            while (cards.length >= 2) {
                discardedCards.push(cards[0]);
                cards.splice(0, 1);

                let top = cards[0];
                cards.splice(0, 1);
                cards.push(top)
            }
        }
        else {
            cards.push(1)
        }

        console.log("Discarded cards:", discardedCards.join(", "));
        console.log("Remaining card:", cards[0]);
    }

}