var input = require('fs').readFileSync('1259.txt', 'utf8');
var lines = input.split('\n');

let casesNumber = lines[0];
let evenList = [];
let oddList = [];
for (let i = 1; i <= casesNumber; i++) {
    let number = parseInt(lines[i]);
    if (number % 2 == 0) {
        evenList.push(number);
    }
    else {
        oddList.push(number);
    }

}
console.log(evenList.sort((a, b) => { return a - b }).join("\n"))
console.log(oddList.sort((a, b) => { return b - a }).join("\n"))