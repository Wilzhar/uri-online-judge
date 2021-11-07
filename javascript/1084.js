var input = require('fs').readFileSync('1084.txt', 'utf8');
var lines = input.split('\n');

var flag = true;

var lineNumber = 0;

while (flag) {
    let caseInput = lines[lineNumber].split(" ");
    let digitsNumber = parseInt(caseInput[0]);
    let digitsToErase = parseInt(caseInput[1]);

    console.log("digitsNumber", lines[lineNumber + 1])
    if (!(digitsNumber == 0 && digitsToErase == 0)) {

        let remainigNumbers = digitsToErase;

        let start = 0;
        let end = start + remainigNumbers;

        let newNumber = [];

        let number = lines[lineNumber + 1].trim().replace(/(?:\\[rn])+/g, "").split("");
        console.log("number", number);

        let a = 0;

        while (a < 100) {
            console.log("start", start, "end", end)
            let maxNumber = Math.max(number.slice(start, end));
            console.log("max", maxNumber)
            let pos = number.indexOf(maxNumber);
            newNumber.push(maxNumber);
            remainigNumbers -= pos;
            start += pos + 1;
            end = start + remainigNumbers;
            a++;
        }

        console.log("newNumber", newNumber.join(""));
    }
    else {
        flag = false;
    }

    lineNumber += 2;
}

