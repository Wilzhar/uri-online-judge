var input = require('fs').readFileSync('1245.txt', 'utf8');
var lines = input.split('\n');

var line = parseInt(lines[0]);
var start = 1;
var finish = line + 1;

while (line) {
    countPairsBoots(start, finish)
    line = parseInt(lines[finish]);
    start = finish + 1;
    finish = parseInt(start + line);
}

function countPairsBoots(start, finish) {

    var bootsStore = {};

    for (let i = start; i <= finish; i++) {
        if (lines[i]) {

            let boot = lines[i].replace(/\r/g, '').split(" ");

            bootSize = boot[0];

            if (bootsStore[bootSize] == undefined) {
                if (boot[1] == 'E') {
                    bootsStore[bootSize] = { 'E': 1, 'D': 0 };
                }
                else {
                    bootsStore[bootSize] = { 'E': 0, 'D': 1 };
                }
            }
            else {

                if (boot[1] == 'E') {
                    bootsStore[bootSize].E += 1;
                }
                else {
                    bootsStore[bootSize].D += 1;
                }
            }
        }

    }

    let sizes = Object.keys(bootsStore);
    let count = 0;

    for (let i = 0; i < sizes.length; i++) {
        let boot = bootsStore[sizes[i]];
        if (boot.E < boot.D) {
            count += boot.E;
        }
        else {
            count += boot.D;
        }

    }

    console.log(count)
}

