var input = require('fs').readFileSync('1168.txt', 'utf8');
var lines = input.split('\n');

var linesNumber = lines[0];

ledsNumber = {
    1: 2,
    2: 5,
    3: 5,
    4: 4,
    5: 5,
    6: 6,
    7: 3,
    8: 7,
    9: 6,
    0: 6
};

for (let i = 1; i <= linesNumber; i++) {
    let desiredValue = 0;

    let line = lines[i];


    for (let j = 0; j < line.length; j++) {
        line = line.replace(/\r/, '');
        desiredValue += ledsNumber[line[j]];
    }

    console.log(desiredValue, "leds");
}