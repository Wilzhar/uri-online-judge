var input = require('fs').readFileSync('1088.txt', 'utf8');
var lines = input.split('\n');

var rest = false;

for (let i = 0; i < lines.length && !rest; i++) {

    lines[i] = lines[i].replace(/(\r\n|\n|\r)/gm, "");
    if (lines[i].trim() === '0') {
        rest = true;
    }

    if (!rest) {
        let bubblesSequence = lines[i].split(" ");
        let turnNumber = 0;

        let restart = false;

        for (let k = 0; k < bubblesSequence.length; k++) {
            if (restart) {
                k = 0;
                restart = false;
            }
            for (let j = 0; j < bubblesSequence.length - 1 && !restart; j++) {
                if (parseInt(bubblesSequence[j]) !== parseInt(bubblesSequence[j + 1])) {
                    if (parseInt(bubblesSequence[j]) > parseInt(bubblesSequence[j + 1])) {
                        let temp = bubblesSequence[j + 1];
                        bubblesSequence[j + 1] = bubblesSequence[j];
                        bubblesSequence[j] = temp;
                        turnNumber++;
                        restart = true;
                    }
                }
            }
        }
        if (turnNumber % 2 == 1) {
            console.log('Marcelo');
        }
        else {
            console.log('Carlos');
        }
    }


}

