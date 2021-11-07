var input = require('fs').readFileSync('1162.txt', 'utf8');
var lines = input.split('\n');

var casesNumber = parseInt(lines[0]);

var lineNumber = 1;

for (let i = 0; i < casesNumber; i++) {

    let trainLength = parseInt(lines[lineNumber]);
    let carriages = lines[lineNumber + 1].trim().split(" ");

    lineNumber += 2;

    let swapCount = 0;

    for (let carriageNumber = 1; carriageNumber <= trainLength; carriageNumber++) {

        let currentPos = carriages.indexOf(`${carriageNumber}`)

        if (currentPos != carriageNumber - 1) {

            swapCount += currentPos - (carriageNumber - 1);
            carriages.splice(currentPos, 1);
            carriages.splice(carriageNumber - 1, 0, `${carriageNumber}`);

            found = true;
        }
    }


    console.log(`Optimal train swapping takes ${swapCount} swaps.`);
}



