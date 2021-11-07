var input = require('fs').readFileSync('1444.txt', 'utf8');
var lines = input.split('\n');

var i = 0;

let drakesNumber = 0;

while (lines[i] != 0) {

    drakesNumber = parseInt(lines[i]);

    console.log(countRaces(drakesNumber));

    i++;
}


function countRaces(drakes) {
    if (drakes <= 1) {
        return 0;
    }
    else if (drakes <= 3) {
        return 1;
    } else {
        let races = Math.floor(drakes / 3);

        if (drakes % 3 == 0) {
            return races + countRaces(races);
        }
        else {
            return (races + 1) + countRaces(races + 1);
        }

    }
}

