var input = require('fs').readFileSync('3154.txt', 'utf8');
var lines = input.split('\n');

let daysAndpeople = lines[0].trim().split(" ");

let days = parseInt(daysAndpeople[0]);
let people = parseInt(daysAndpeople[1]);

let birthDayLikelihood = 1 / days;

let totalLikelihood = birthDayLikelihood;

for (let i = 2; i < people - 1; i++) {
    totalLikelihood += (birthDayLikelihood * i);
}

console.log(totalLikelihood * 100);

console.log((1 - ((342 / 365) * (342 / 365))) * 100);