var input = require('fs').readFileSync('1308.txt', 'utf8');
var lines = input.split('\n');

var linesNumber = lines[0];

for (let i = 1; i <= linesNumber; i++) {
    console.log(linesNumber)
}