var input = require('fs').readFileSync('1215.txt', 'utf8');
var lines = input.split('\n');

var i = 0;

var line;

var words = [];

do {

    if (lines[i]) {
        if (lines[i].trim() != "") {
            line = lines[i].replace(/[^a-zA-Z]+/g, " ").trim().split(" ");
            for (let j = 0; j < line.length; j++) {
                let tempWord = line[j].toLowerCase();
                if (!words.find(word => word == tempWord)) {
                    if (tempWord.trim() != "") {
                        words.push(tempWord);
                    }
                }
            }
        }
    }
    else {
        break;
    }

    i++;
} while (line);

console.log(words.sort().join("\n"));