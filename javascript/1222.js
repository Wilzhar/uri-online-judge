var input = require('fs').readFileSync('1222.txt', 'utf8');
var lines = input.split('\n');

let caseNumber = 0;

while (lines[caseNumber]) {

    let caseInfo = lines[caseNumber].trim().replace(/[\r\n]/g, "").split(" ");

    if (caseInfo.length != 3) {
        break;
    }

    let wordsNumber = parseInt(caseInfo[0]);
    let linesPerPage = parseInt(caseInfo[1]);
    let charactersPerLine = parseInt(caseInfo[2]);

    let currentPages = 0;
    let currentLines = 0;
    let currentCharacters = 0;

    let words = lines[caseNumber + 1].trim().replace(/[\r\n]/g, "").split(" ");

    console.log(words)
    console.log("wordsNumber", wordsNumber);
    console.log("LinesPerPage", linesPerPage);
    console.log("charactersPerLine", charactersPerLine);

    for (let i = 0; i < wordsNumber; i++) {

    }
}

