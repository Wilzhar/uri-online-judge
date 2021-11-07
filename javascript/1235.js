var input = require('fs').readFileSync('1235.txt', 'utf8');
var lines = input.split('\n');

var casesNumber = parseInt(lines[0]);

for (let i = 1; i <= casesNumber; i++) {

    let processedSentence = "";

    let sentence = lines[i].replace(/[\r\n]/g, "");

    let sentPart1 = sentence.substring(0, sentence.length / 2);

    let sentPart2 = sentence.substring(Math.floor(sentence.length / 2), sentence.length);

    processedSentence += sentPart1.split('').reverse().join('') + sentPart2.split('').reverse().join('');

    console.log(processedSentence);

}

