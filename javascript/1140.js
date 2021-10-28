var input = require('fs').readFileSync('1140.txt', 'utf8');
var lines = input.split('\n');

var rest = false;

for (let i = 0; i < lines.length && !rest; i++) {

    if (lines[i].trim() === '*') {
        rest = true;
    }

    if (!rest) {
        let sentence = lines[i];

        let isTautogram = true;

        let words = sentence.split(' ');

        let tautogramLetter = words[0][0].toLowerCase();
        for (let j = 1; j < words.length && isTautogram; j++) {
            if (words[j][0].toLocaleLowerCase() !== tautogramLetter) {
                isTautogram = false;
            }
        }

        if (isTautogram) {
            console.log('Y');
        }
        else {
            console.log('N');
        }
    }
}